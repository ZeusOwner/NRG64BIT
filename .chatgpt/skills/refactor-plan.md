# SKILL: /risk-check
# Usage: paste this + "Risk check: [filename or area]" into chat

## Your task
Scan specified area for memory/leak/crash risks only. No fixes yet.

## Patterns to detect
- Static fields holding Context / View / WindowManager
- Non-static Handler (implicit class ref leak)
- Thread with no stop() in onDestroy
- JNI: GetMethodID/FindClass without null check
- JNI: CallMethod without ExceptionCheck after
- JNI: LocalRef not deleted
- Stream/Reader not in try-with-resources or finally block
- open()/fopen() without matching close()
- Recursive method that shadows native declaration

## Output format (max 200 words)

### RISK CHECK: [Target]

**New Risks Found:**
| Location | Risk Type | Severity |
| --- | --- | --- |
[If none: "No new risks found beyond copilot-instructions.md list"]

**Known Risks Status:**
| Risk | Status |
| onSendConfig recursion | STILL PRESENT / FIXED |
| Static WindowManager | STILL PRESENT / FIXED |
| Handler leak Floating | STILL PRESENT / FIXED |

**Priority Fix Order:**
1. [file:line — 1 sentence]
2. ...
(max 5)

**Recommended First Fix:** [name only — no code]

## Hard rules
- Assessment only
- No code changes
- Flag onSendConfig recursion as CRITICAL immediately if found

---

# SKILL: /refactor-plan
# Usage: paste this + "Refactor plan: [issue]" into chat

## Your task
Propose a safe incremental fix plan. NO code yet — plan only.

## Output format

### REFACTOR PLAN: [Issue]

**Current Behavior:** [2-3 sentences]

**Why Change Needed:** [1-2 sentences — specific risk]

**Risk Level:** LOW / MEDIUM / HIGH — [1-sentence reason]

**JNI Impact:** NONE / POSSIBLE / HIGH — [explain if not NONE]

**Smallest Safe Change:**
1. [Step 1 in plain English]
2. [Step 2]
...

**Do NOT touch:**
- [explicit list of methods/fields to leave unchanged]

**Estimated lines changed:** ~N lines in [file]

**Verification:** [how to confirm fix worked]

## Hard rules
- No code until user says "approved" or "proceed"
- Never propose renaming JNI bridge methods
- One issue per plan only
- If > 20 lines will change: show diff first, wait again
