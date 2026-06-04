# /risk-check — Memory & Leak Risk Assessment Skill

## Trigger
User runs: `/risk-check [FileName or area]`
Example: `/risk-check Floating.java handlers` or `/risk-check ESP.h jni`

## Steps

### Step 1 — Load risk table from CLAUDE.md
Cross-reference existing known risks before scanning.

### Step 2 — Scan target area only
Focus scan on specified area. Patterns to detect:
- Static fields holding Context / View / WindowManager
- Handler declared as non-static inner class
- Thread with no stop/interrupt in onDestroy
- JNI: GetMethodID/FindClass without null check
- JNI: CallMethod without ExceptionCheck
- JNI: LocalRef not Deleted after use
- BufferedReader/Stream not in try-with-resources or finally
- open() / fopen() without matching close()
- Recursive method that could shadow native declaration

### Step 3 — Output

```
## RISK CHECK: [Target]

### New Risks Found (not in CLAUDE.md)
| Location | Risk Type | Severity |
[If none: "No new risks found"]

### Known Risks Confirmed Present
| Location | Risk Type | Status |
[From CLAUDE.md — mark STILL PRESENT / FIXED / NOT FOUND IN SCAN]

### Priority Fix Order
1. [Highest severity — file:line — 1-sentence description]
2. [Next...]
(max 5 items)

### Recommended First Fix
[Single safest fix to do next — name only, no code yet]
```

## Constraints
- Assessment only — no code changes
- Do not load unrelated files
- Flag any onSendConfig recursion immediately as CRITICAL
