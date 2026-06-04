# SKILL: /jni-verify
# Usage: paste this file content + "JNI verify: [method name]" into chat

## Your task
Verify JNI bridge safety for the specified method. Read only the relevant
method range — do NOT read full files.

## Checks
- [ ] Java declaration matches C++ export name exactly
- [ ] Parameter types match JNI signature
- [ ] Return type matches
- [ ] GetMethodID result null-checked (outbound calls)
- [ ] LocalRef cleanup present after outbound calls
- [ ] Not been renamed since last audit

## Output format

### JNI VERIFY: [method]

**Java Side:**
- Class: [class]
- Declaration: [full signature]
- Type: [static native / registered dynamic]

**C++ Side:**
- Function: [export name]
- File: [file:line]
- Registration: [JNI_OnLoad static / RegisterNatives dynamic]

**Safety Checks:**
- Null check: YES / NO / N/A
- LocalRef cleanup: YES / NO / N/A
- Signature match: PASS / FAIL / NEEDS VERIFICATION

**Verdict:** SAFE / UNSAFE / NEEDS VERIFICATION

**If UNSAFE:** [1-2 sentence description — no fix yet]

## Hard rules
- NEVER rename any JNI method
- NEVER suggest signature change without approval
- Read only target method range, not full file
