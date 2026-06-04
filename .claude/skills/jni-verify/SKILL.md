# /jni-verify — JNI Bridge Safety Check Skill

## Trigger
User runs: `/jni-verify [method name or class]`
Example: `/jni-verify onSendConfig` or `/jni-verify Floating`

## Steps

### Step 1 — Load JNI Bridge Reference from CLAUDE.md
Do NOT read Main.cpp fully. Use bridge map from CLAUDE.md only unless discrepancy found.

### Step 2 — Check target method
For the specified method, verify:
- [ ] Java declaration matches C++ export name exactly
- [ ] Parameter types match JNI signature
- [ ] Return type matches
- [ ] Not renamed since last audit
- [ ] GetMethodID result checked for null (outbound calls)
- [ ] LocalRef cleanup present after outbound calls

### Step 3 — Output

```
## JNI VERIFY: [method]

### Java Side
Class: [class]
Declaration: [signature]
Type: [static native / registered dynamic]

### C++ Side
Function: [export name]
File: [file:line]
Registration: [JNI_OnLoad static / RegisterNatives dynamic]

### Safety Checks
- Null check on return: [YES / NO / N/A]
- LocalRef cleanup: [YES / NO / N/A]
- Signature match: [PASS / FAIL / NEEDS VERIFICATION]

### Verdict
[SAFE / UNSAFE / NEEDS VERIFICATION]

### If UNSAFE
Describe issue in 1-2 sentences. Do NOT fix yet — wait for approval.
```

## Constraints
- Never rename any JNI method
- Never suggest signature change without explicit approval
- Read only the specific method range in C++ file (not full file)
