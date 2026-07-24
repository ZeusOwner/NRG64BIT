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

USER_ID="$(gh api -H "X-GitHub-Api-Version: ${API_VERSION}" "users/${OWNER}" --jq '.id')"
[[ -n "${USER_ID}" && "${USER_ID}" != "null" ]] || fail "Could not resolve numeric GitHub user ID for ${OWNER}"

PROJECTS_JSON="$(gh api \
  -H 'Accept: application/vnd.github+json' \
  -H "X-GitHub-Api-Version: ${API_VERSION}" \
  --paginate \
  "users/${OWNER}/projectsV2?per_page=100")"

PROJECT_NUMBER="$(jq -r --arg title "${PROJECT_TITLE}" '
  if type == "array" then . else (.value // .projects // []) end
  | map(select(.title == $title and (.state // "open") == "open"))
  | first
  | .number // empty
' <<<"${PROJECTS_JSON}")"

[[ -n "${PROJECT_NUMBER}" ]] || fail "Project '${PROJECT_TITLE}' was not found under ${OWNER}. Create it first, then rerun this script."

PROJECT_URL="https://github.com/users/${OWNER}/projects/${PROJECT_NUMBER}"
log "Using project #${PROJECT_NUMBER}: ${PROJECT_URL}"

FIELDS_JSON="$(gh api \
  -H 'Accept: application/vnd.github+json' \
  -H "X-GitHub-Api-Version: ${API_VERSION}" \
  --paginate \
  "users/${OWNER}/projectsV2/${PROJECT_NUMBER}/fields?per_page=100")"

field_id() {
  local name="$1"
  jq -r --arg name "${name}" '
    if type == "array" then . else (.value // .fields // []) end
    | map(select(.name == $name))
    | first
    | .id // empty
  ' <<<"${FIELDS_JSON}"
}

# Field names expected by Issue #11. Missing optional fields are omitted from visible_fields.
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
  else
    log "Field not found; omitting from visible_fields: ${name}"
  fi
done

# These fields are required by saved filters. Stop instead of creating broken views.
for required in "Status" "Agent suitability"; do
  [[ -n "$(field_id "${required}")" ]] || \
    fail "Required field '${required}' is missing. Create the Project fields from Issue #11 before creating filtered views."
done

VIEWS_JSON="$(gh api \
  -H 'Accept: application/vnd.github+json' \
  -H "X-GitHub-Api-Version: ${API_VERSION}" \
  --paginate \
  "users/${USER_ID}/projectsV2/${PROJECT_NUMBER}/views?per_page=100")"

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

  gh api \
    --method POST \
    -H 'Accept: application/vnd.github+json' \
    -H "X-GitHub-Api-Version: ${API_VERSION}" \
    "users/${USER_ID}/projectsV2/${PROJECT_NUMBER}/views" \
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
log 'Note: the REST create-view endpoint does not expose board group_by/sort_by configuration. Confirm Active Board is grouped by Status in the GitHub UI.'
