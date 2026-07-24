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

gh auth status -h github.com >/dev/null 2>&1 || \
  fail 'GitHub CLI is not authenticated. Run: gh auth login --scopes project'

api() {
  gh api \
    -H 'Accept: application/vnd.github+json' \
    -H "X-GitHub-Api-Version: ${API_VERSION}" \
    "$@"
}

USER_ID="$(api "users/${OWNER}" --jq '.id')"
[[ -n "${USER_ID}" && "${USER_ID}" != "null" ]] || \
  fail "Could not resolve numeric GitHub user ID for ${OWNER}"

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

# Verify that the authenticated session can read this exact project.
api "users/${OWNER}/projectsV2/${PROJECT_NUMBER}" >/dev/null || \
  fail "The project exists but the authenticated session cannot read it. Run: gh auth refresh -h github.com -s project,read:project"

# The REST field-list endpoint is still rolling out across token/account combinations.
# View creation does not require visible_fields, so a 404 here is non-fatal.
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

# User-owned Project view endpoints use a numeric user ID in the documented path.
# Some deployments also accept the login, so try both and retain whichever works.
VIEW_OWNER_KEY=''
VIEWS_JSON=''
for candidate in "${USER_ID}" "${OWNER}"; do
  if candidate_json="$(api --paginate "users/${candidate}/projectsV2/${PROJECT_NUMBER}/views?per_page=100" 2>/dev/null)"; then
    VIEW_OWNER_KEY="${candidate}"
    VIEWS_JSON="${candidate_json}"
    break
  fi
done

if [[ -z "${VIEW_OWNER_KEY}" ]]; then
  fail "The Project Views endpoint returned 404 for both numeric user ID and login. Refresh OAuth scopes with: gh auth refresh -h github.com -s project,read:project"
fi

log "Project Views endpoint resolved with user key: ${VIEW_OWNER_KEY}"

view_exists() {
  local name="$1"
  jq -e --arg name "${name}" '
    if type == "array" then . else (.value // .views // []) end
    | any(.name == $name)
  ' <<<"${VIEWS_JSON}" >/dev/null
}

create_view() {
  local name="$1"
  local layout="$2"
  local filter="$3"

  if view_exists "${name}"; then
    log "View already exists; skipping: ${name}"
    return 0
  fi

  local payload
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

  api \
    --method POST \
    "users/${VIEW_OWNER_KEY}/projectsV2/${PROJECT_NUMBER}/views" \
    --input - <<<"${payload}" \
    --jq '(.value // .) | "created: \(.name) -> \(.html_url)"'
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
log 'The REST create-view endpoint does not expose board group_by/sort_by configuration.'
log 'Open Active Board in GitHub and set Group by -> Status once.'
