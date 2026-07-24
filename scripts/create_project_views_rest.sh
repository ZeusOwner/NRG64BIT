#!/usr/bin/env bash
set -Eeuo pipefail

OWNER="${OWNER:-ZeusOwner}"
REPO="${REPO:-NRG64BIT}"
PROJECT_TITLE="${PROJECT_TITLE:-NRG64BIT Development Board}"
API_VERSION="${API_VERSION:-2026-03-10}"

log() {
  printf '[project-views] %s\n' "$*"
}

fail() {
  printf '[project-views] ERROR: %s\n' "$*" >&2
  exit 1
}

require_command() {
  command -v "$1" >/dev/null 2>&1 || fail "Missing required command: $1"
}

require_command gh
require_command jq

# Do not print or persist the authenticated token.
gh auth status -h github.com >/dev/null 2>&1 || \
  fail 'GitHub CLI is not authenticated. Run: gh auth login --scopes project'

api() {
  gh api \
    -H 'Accept: application/vnd.github+json' \
    -H "X-GitHub-Api-Version: ${API_VERSION}" \
    "$@"
}

USER_JSON="$(api "users/${OWNER}")"
USER_ID="$(jq -r '.id // empty' <<<"${USER_JSON}")"
USER_NODE_ID="$(jq -r '.node_id // empty' <<<"${USER_JSON}")"

[[ -n "${USER_ID}" ]] || fail "Could not resolve numeric GitHub user ID for ${OWNER}"
[[ -n "${USER_NODE_ID}" ]] || fail "Could not resolve GitHub user node ID for ${OWNER}"

PROJECTS_JSON="$(api --paginate "users/${OWNER}/projectsV2?per_page=100")"

PROJECT_NUMBER="$(jq -r --arg title "${PROJECT_TITLE}" '
  if type == "array" then . else (.value // .projects // []) end
  | map(select(.title == $title and (.state // "open") == "open"))
  | first
  | .number // empty
' <<<"${PROJECTS_JSON}")"

[[ -n "${PROJECT_NUMBER}" ]] || \
  fail "Project '${PROJECT_TITLE}' was not found under ${OWNER}. Create it first, then rerun this script."

PROJECT_URL="https://github.com/users/${OWNER}/projects/${PROJECT_NUMBER}"
log "Using project #${PROJECT_NUMBER}: ${PROJECT_URL}"

PROJECT_JSON="$(api "users/${OWNER}/projectsV2/${PROJECT_NUMBER}")" || \
  fail "The project exists but the authenticated session cannot read it. Run: gh auth refresh -h github.com -s project,read:project"

PROJECT_NODE_ID="$(jq -r '.node_id // empty' <<<"${PROJECT_JSON}")"
[[ -n "${PROJECT_NODE_ID}" ]] || fail 'The REST project response did not include node_id.'

# Fields use the username-based user-owned Project endpoint.
FIELDS_JSON='[]'
if REST_FIELDS="$(api --paginate "users/${OWNER}/projectsV2/${PROJECT_NUMBER}/fields?per_page=100" 2>/dev/null)"; then
  FIELDS_JSON="${REST_FIELDS}"
  log 'REST Project fields endpoint is available; custom columns will be included.'
else
  log 'REST Project fields endpoint returned unavailable/404; continuing with GitHub default view columns.'
  log 'This does not block view creation. Columns can be selected later in the Project UI.'
fi

field_id() {
  local name="$1"
  jq -r --arg name "${name}" '
    if type == "array" then . else (.value // .fields // []) end
    | map(select(.name == $name))
    | first
    | .id // empty
  ' <<<"${FIELDS_JSON}"
}

VISIBLE_FIELD_NAMES=(
  "Title"
  "Status"
  "Priority"
  "Area"
  "Agent suitability"
  "Validation"
  "Linked pull requests"
  "Dependency"
)

VISIBLE_FIELDS=()
for name in "${VISIBLE_FIELD_NAMES[@]}"; do
  id="$(field_id "${name}")"
  if [[ -n "${id}" ]]; then
    VISIBLE_FIELDS+=("${id}")
  fi
done

# There is currently no REST list-views endpoint. Read existing view names through GraphQL
# so rerunning the script remains idempotent.
VIEWS_JSON="$(gh api graphql \
  -F projectId="${PROJECT_NODE_ID}" \
  -f query='
    query($projectId: ID!) {
      node(id: $projectId) {
        ... on ProjectV2 {
          views(first: 100) {
            nodes {
              name
              number
            }
          }
        }
      }
    }
  ' \
  --jq '.data.node.views.nodes')"

view_exists() {
  local name="$1"
  jq -e --arg name "${name}" 'any(.name == $name)' <<<"${VIEWS_JSON}" >/dev/null
}

# The REST documentation calls this path parameter `user_id` rather than `username`.
# Try the global REST/GraphQL node ID first, then numeric database ID and login as
# compatibility fallbacks. Once one form succeeds, reuse it for later views.
VIEW_OWNER_KEY=''

post_view() {
  local payload="$1"
  local response=''
  local error_file
  error_file="$(mktemp)"
  trap 'rm -f "${error_file}"' RETURN

  local candidates=()
  if [[ -n "${VIEW_OWNER_KEY}" ]]; then
    candidates=("${VIEW_OWNER_KEY}")
  else
    candidates=("${USER_NODE_ID}" "${USER_ID}" "${OWNER}")
  fi

  local candidate encoded status
  for candidate in "${candidates[@]}"; do
    encoded="$(jq -rn --arg value "${candidate}" '$value | @uri')"

    set +e
    response="$(api \
      --method POST \
      "users/${encoded}/projectsV2/${PROJECT_NUMBER}/views" \
      --input - <<<"${payload}" 2>"${error_file}")"
    status=$?
    set -e

    if [[ ${status} -eq 0 ]]; then
      VIEW_OWNER_KEY="${candidate}"
      printf '%s' "${response}"
      return 0
    fi

    if grep -q 'HTTP 404' "${error_file}" || \
       jq -e '(.message // "") == "Not Found"' <<<"${response}" >/dev/null 2>&1; then
      : >"${error_file}"
      continue
    fi

    [[ -n "${response}" ]] && printf '%s\n' "${response}" >&2
    cat "${error_file}" >&2
    return "${status}"
  done

  [[ -n "${response}" ]] && printf '%s\n' "${response}" >&2
  fail "View creation returned 404 for user node ID, numeric ID, and login. Confirm the gh token is an OAuth/classic token with project scope; fine-grained PATs and GitHub App tokens are not supported by this user-owned Project Views endpoint."
}

create_view() {
  local name="$1"
  local layout="$2"
  local filter="$3"

  if view_exists "${name}"; then
    log "View already exists; skipping: ${name}"
    return 0
  fi

  local payload response
  if [[ "${layout}" == "roadmap" || ${#VISIBLE_FIELDS[@]} -eq 0 ]]; then
    payload="$(jq -n \
      --arg name "${name}" \
      --arg layout "${layout}" \
      --arg filter "${filter}" \
      '{name: $name, layout: $layout, filter: $filter}')"
  else
    payload="$(printf '%s\n' "${VISIBLE_FIELDS[@]}" | jq -s \
      --arg name "${name}" \
      --arg layout "${layout}" \
      --arg filter "${filter}" \
      '{name: $name, layout: $layout, filter: $filter, visible_fields: map(tonumber)}')"
  fi

  response="$(post_view "${payload}")"
  jq -r '(.value // .) | "created: \(.name) -> \(.html_url)"' <<<"${response}"

  # Keep the local idempotency snapshot current during this run.
  VIEWS_JSON="$(jq --arg name "${name}" '. + [{name: $name}]' <<<"${VIEWS_JSON}")"
}

REPO_FILTER="repo:${OWNER}/${REPO}"

create_view "All Work" "table" "${REPO_FILTER}"
create_view "Active Board" "board" "${REPO_FILTER} -status:Done"
create_view "Agent Queue" "table" "${REPO_FILTER} agent-suitability:\"Agent Ready\" -status:Done"
create_view "AndroidIDE Tests" "table" "${REPO_FILTER} status:\"Needs AndroidIDE Test\""
create_view "Device Validation" "table" "${REPO_FILTER} status:\"Needs Device Test\""
create_view "Blocked" "table" "${REPO_FILTER} status:Blocked"
create_view "Completed" "table" "${REPO_FILTER} status:Done"

log "Project views are configured: ${PROJECT_URL}"
log "REST view creation resolved user_id as: ${VIEW_OWNER_KEY}"
log 'Open Active Board in GitHub and set Group by -> Status once if it is not already grouped.'