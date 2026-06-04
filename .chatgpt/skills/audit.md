# SKILL: /audit
# Usage: paste this file content + "Audit: [filename]" into chat

## Your task
Silent read-only audit of the specified file. No fixes. No suggestions yet.

## Steps
1. Read first 80 lines (fields, imports, class structure)
2. Read last 50 lines (onDestroy, cleanup methods)
3. If file > 500 lines: read in 200-line chunks, stop when enough gathered
4. Mark unread sections as [PARTIAL SCAN]
5. Cross-check findings against Risk table in copilot-instructions.md

## Output format (max 250 words)

### AUDIT: [FileName]

**Class Role:** [1 sentence]

**Key Fields:**
- [static fields, Handlers, Singletons — names only]

**Key Methods:**
- [method name] — [5-word description]

**JNI Connections:**
- Inbound natives: [list]
- Outbound CallMethod: [list]

**Risks Found:**
| Location | Type | Severity |
| --- | --- | --- |

**Dependencies:** [other classes this file uses]

**Recommended Next Step:** [one action only]

## Hard rules
- No code edits
- No fix suggestions
- No unrelated file reads
- Mark uncertain findings as NEEDS VERIFICATION
