# /refactor-plan — Safe Incremental Refactor Proposal Skill

## Trigger
User runs: `/refactor-plan [issue or class]`
Example: `/refactor-plan Handler leak Floating` or `/refactor-plan static context`

## Steps

### Step 1 — Understand before proposing
- Read only the specific method/field being refactored
- Do NOT read entire file unless essential
- Cross-check CLAUDE.md risk table and JNI bridge map

### Step 2 — Produce plan (NO code yet)

```
## REFACTOR PLAN: [Issue]

### Current Behavior
[2-3 sentences max — what it does now]

### Why Change Is Needed
[1-2 sentences — specific risk or bug]

### Risk Level
[LOW / MEDIUM / HIGH] — reason in 1 sentence

### JNI Impact
[NONE / POSSIBLE / HIGH — explain if not NONE]

### Smallest Safe Change
[Step-by-step plain English — no code]
1. [Step 1]
2. [Step 2]
...

### What NOT to Touch
[Explicit list of methods/fields to leave unchanged]

### Estimated Lines Changed
~[N] lines in [file]

### Verification Step
[How to confirm fix worked — logcat tag / test action]
```

### Step 3 — Wait for approval
**Do NOT write any code until user replies "approved" or "proceed".**
After approval: make smallest change first, show diff, wait again if > 20 lines.

## Constraints
- Never propose renaming JNI bridge methods
- Never propose structural changes to ESP draw loop without explicit request
- Prefer WeakReference fix over architectural overhaul
- One issue per plan
