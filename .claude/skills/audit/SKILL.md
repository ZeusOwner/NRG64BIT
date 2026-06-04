# /audit — Module Architecture Audit Skill

## Trigger
User runs: `/audit [FileName or ModuleName]`
Example: `/audit Floating.java` or `/audit ESP module`

## Steps (follow in order)

### Step 1 — Load CLAUDE.md context
Read CLAUDE.md module overview and risk table for the target module only.

### Step 2 — Scan target file
- Read first 80 lines (structure/imports/fields)
- Read last 50 lines (cleanup/destroy methods)
- Scan for: static fields, Handler declarations, Thread spawns, native declarations
- If file > 500 lines: scan in 200-line chunks, stop when enough context gathered
- Mark unread sections as [PARTIAL SCAN]

### Step 3 — Output (keep under 300 words total)

```
## AUDIT: [FileName]

### Class Role
[1 sentence]

### Key Fields
[Static fields, Handlers, Singletons — names only]

### Key Methods
[Method names + 5-word description each]

### JNI Connections
[Inbound native declarations + outbound CallMethod refs]

### Risks Found
| Location | Type | Severity |
[From CLAUDE.md risk table — flag if new risks found]

### Dependencies
[Other classes this file touches]

### Recommended Next Step
[One concrete action only]
```

## Constraints
- Do NOT suggest fixes in audit mode
- Do NOT read unrelated files
- Do NOT rewrite or refactor
- Keep total output under 300 words
- If unsure: mark NEEDS VERIFICATION
