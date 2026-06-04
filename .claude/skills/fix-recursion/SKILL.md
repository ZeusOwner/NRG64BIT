# /fix-recursion — Fix onSendConfig Infinite Recursion Skill

## Trigger
User runs: `/fix-recursion`
This is a HIGH priority known bug — Floating.java ~line 354

## Background (from audit)
`Floating.java` declares a Java method `onSendConfig(String, String)` that:
- Shadows the `native` declaration of the same name
- Calls itself recursively → stack overflow risk
- This is the #1 critical bug in the project

## Steps

### Step 1 — Verify bug location
Read only lines 340–370 of Floating.java.
Confirm: Java method `onSendConfig` exists AND calls itself.

### Step 2 — Show current code
Display the offending method only (not surrounding code).

### Step 3 — Explain fix

```
## FIX: onSendConfig Infinite Recursion

### Root Cause
Java method `onSendConfig(String key, String value)` in Floating.java
shadows the `native` declaration. The Java method body calls
`onSendConfig(...)` again → infinite recursion → StackOverflowError.

### Fix Strategy
Option A (Recommended — minimal change):
- Remove the Java wrapper method entirely
- Declare `onSendConfig` as `native` directly (already registered 
  dynamically in Main.cpp:13 as `native_onSendConfig`)
- All existing call sites remain unchanged

Option B (If Java pre-processing is needed):
- Rename Java wrapper to `sendConfigToNative(String, String)`
- Rename native declaration to match
- Update all call sites
- ⚠️ Requires /jni-verify first — impacts Main.cpp registration

### Recommended: Option A
Risk Level: LOW (only removes redundant Java wrapper)
JNI Impact: NONE (native_onSendConfig registration unchanged)
Lines changed: ~5-8 lines removed
```

### Step 4 — Wait for approval before any edit

### Step 5 — After approval
1. Show exact diff (before/after) — no other changes
2. Confirm call sites in Floating.java still compile
3. Update CLAUDE.md: move this risk from "Known Risks" to "Completed Tasks"

## Constraints
- Do NOT touch Main.cpp during this fix
- Do NOT rename native_onSendConfig
- Do NOT refactor surrounding methods
