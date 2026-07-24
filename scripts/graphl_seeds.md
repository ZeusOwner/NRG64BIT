# GraphQL seeds — examples

This file contains conservative, ready-to-adapt GraphQL snippets for creating the project and seeding items. Run these in the GitHub GraphQL Explorer (https://docs.github.com/en/graphql/overview/explorer) or via curl + PAT.

1) Query repository node id

query RepoId {
  repository(owner: "ZeusOwner", name: "NRG64BIT") { id }
}

2) Create project v2 (sample)

mutation CreateProject($input: CreateProjectV2Input!) {
  createProjectV2(input: $input) {
    projectV2 { id }
  }
}

# Variables:
# {
#   "input": {
#     "repositoryId": "REPLACE_WITH_REPO_NODE_ID",
#     "title": "NRG64BIT Development Board",
#     "shortDescription": "Operational board seeded per Issue #11"
#   }
# }

3) Get issue / PR node id

query IssueId {
  repository(owner: "ZeusOwner", name: "NRG64BIT") {
    issue(number: 2) { id }
    pullRequest(number: 3) { id }
  }
}

4) Add an issue or PR to the project (example mutation name; confirm in Explorer)

mutation AddItem($input: AddProjectV2ItemByIdInput!) {
  addProjectV2ItemById(input: $input) {
    item { id }
  }
}

# Variables:
# {
#   "input": {
#     "projectId": "REPLACE_WITH_PROJECT_NODE_ID",
#     "contentId": "REPLACE_WITH_ISSUE_OR_PR_NODE_ID"
#   }
# }

5) Helpful tips
- After creating the project, run a query to list project fields and their node IDs so you can programmatically set values. Use Explorer to discover the exact mutation names and input shapes for updating field values.
- If GraphQL mutations differ, copy the input type from the Explorer and adapt the JSON variables accordingly.

