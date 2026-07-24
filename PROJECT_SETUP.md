NRG64BIT Development Board — Project setup and manual run instructions

အခြေအနေ
- GitHub Actions အသုံးမရ (billing/blocked) ဖြစ်နေသောကြောင့် repository-level automation မရနိုင်ပါ။
- ဒီအတွက် Project v2 ကို server-side automation ဖြင့် စီမံမရသေးပါက လက်နက်အဖြစ် manual / local GraphQL steps နဲ့ ပြုလုပ်နိုင်ရန် templates နှင့် README ကိုပေးထားပါတယ်။

ဒီဖိုင်တွေကို repository root မှာ commit လုပ်ပြီး Issue #11 အလိုက် Project ကိုလက်တိုက်ဖန်တီးဖို့ အသုံးပြုပါ။

ဖိုင်များ
- project-config.json — Project name, fields, views, initial snapshot
- PROJECT_SETUP.md — Manual setup steps and GraphQL templates (see below)

Manual web UI steps (fastest, GUI)
1. Open https://github.com/ZeusOwner/NRG64BIT
2. Top-right -> Projects -> New project (choose "Board" or "Table"). Name it: "NRG64BIT Development Board" and add description.
3. In Project settings, add custom fields matching project-config.json:
   - Status (single select) with options: Inbox, Ready, In Progress, Agent Working, Needs AndroidIDE Test, Needs Device Test, Review, Blocked, Done
   - Priority (single select): P0..., P1..., P2..., P3...
   - Area (single select): Java UI, Config/Persistence, JNI Bridge, C++ Native, Overlay Lifecycle, ESP Items, SDK/Offsets, Build/Gradle, Testing, Documentation
   - Agent suitability (single select): Agent Ready, Needs Investigation, Human/Device Required, Do Not Start
   - Validation (single select): Not Started, Static Check Passed, AndroidIDE Build Passed, Device Test Passed, Failed
   - Dependency (text)
   - Linked PR (text)
4. Create views:
   - All Work: Table view with columns Status, Priority, Area, Agent suitability, Validation, Linked PR, Dependency
   - Active Board: Board grouped by Status
   - Agent Queue: Table filtered where Agent suitability == Agent Ready
   - AndroidIDE Tests: Table filtered where Status == Needs AndroidIDE Test
   - Device Validation: Table filtered where Status == Needs Device Test
   - Blocked: Table filtered where Status == Blocked
   - Completed: Table filtered where Status == Done (include closed items)
5. Seed items into the project (manual):
   - Add existing issues/PRs using "Add existing issue/PR" in the project UI and set field values per project-config.json initial_snapshot.

Manual GraphQL (alternative — use GraphQL Explorer or curl + PAT)
- Get repo and issue node IDs (GraphQL):
  query {
    repository(owner: "ZeusOwner", name: "NRG64BIT") { id }
  }

- Create Project (example - open graphql explorer at https://docs.github.com/en/graphql/overview/explorer):
  mutation CreateProject($input: CreateProjectV2Input!) {
    createProjectV2(input: $input) {
      projectV2 { id }
    }
  }

  Variables example:
  {
    "input": {
      "repositoryId": "REPLACE_WITH_REPO_NODE_ID",
      "title": "NRG64BIT Development Board",
      "shortDescription": "Operational board seeded per Issue #11"
    }
  }

- After you create the project, use the GraphQL Explorer to inspect the available mutations for adding fields (addProjectV2Field), creating views, and adding items. Field mutation shapes can change; use Explorer to confirm input shapes. Example to add an existing issue to a project:

  1) Get the issue node id:
     query { repository(owner:"ZeusOwner", name:"NRG64BIT") { issue(number: 2) { id } } }

  2) Add it to project (example mutation name: addProjectV2ItemById):
     mutation AddItem($input: AddProjectV2ItemByIdInput!) {
       addProjectV2ItemById(input: $input) { item { id } }
     }

     Variables:
     {
       "input": {
         "projectId": "REPLACE_WITH_PROJECT_NODE_ID",
         "contentId": "REPLACE_WITH_ISSUE_NODE_ID"
       }
     }

- Note: Setting field values programmatically requires you to query for the project's field IDs first, then call the appropriate mutation (updateProjectV2ItemFieldValue or similar). Because GraphQL field shapes evolve, I recommend using the Explorer to build the final mutations.

curl example (generic):
  TOKEN=YOUR_PERSONAL_ACCESS_TOKEN
  curl -H "Authorization: bearer $TOKEN" -X POST -d '{"query":"query { repository(owner:\"ZeusOwner\", name:\"NRG64BIT\") { id } }"}' https://api.github.com/graphql

Permissions
- Use a PAT with appropriate scopes: repo and projects (projects:write or project scope if available). If your org requires different scopes, follow those rules.

If you want, I can now:
- Provide exact GraphQL mutation payloads for each addProjectV2Field and view creation based on the schema (I will include templates and explain how to adapt them in the Explorer), OR
- Walk you through the GraphQL Explorer live (step-by-step mutations) if you share when you will run them.

