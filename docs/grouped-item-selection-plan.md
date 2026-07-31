# Grouped item selection implementation plan

Tracking issue: #4

## Status

This branch is a draft implementation workspace. The first commit defines the contract and test boundaries; it does not change runtime behavior.

## Scope

1. Introduce a versioned grouped item schema in the Android assets.
2. Parse and validate stable group IDs and item IDs in Java.
3. Build group controls with checked, unchecked, and mixed states.
4. Keep optional per-item expansion and selection.
5. Replace native toggle semantics with explicit enabled/disabled state.
6. Persist individual selections and replay them only after the native bridge is ready.
7. Verify Java UI state and native `itemConfig` state remain identical after restart.

## Data contract

The v2 schema uses stable machine IDs for groups and numeric game item IDs for entries.

```json
{
  "schemaVersion": 2,
  "groups": [
    {
      "id": "weapon_ar",
      "name": "AR Rifles",
      "items": [
        { "id": 101001, "name": "AKM" },
        { "id": 101004, "name": "M416" }
      ]
    }
  ]
}
```

Validation requirements:

- `schemaVersion` must be supported.
- Group IDs must be non-empty and unique.
- Numeric item IDs must be unique across groups unless aliasing is explicitly supported.
- Empty groups, malformed entries, and duplicate IDs must not silently alter native state.
- The current flat asset must have an explicit migration or fallback path.

## Native contract

The current command toggles state and is not safe to replay:

```cpp
itemConfig[itemId] = !itemConfig[itemId];
```

The replacement must set an explicit state:

```text
setItemEnabled(itemId, enabled)
setItemGroupEnabled(itemIds, enabled)
```

Both operations must be idempotent. Sending `enabled=true` twice must leave the item enabled.

`CMD_PARSE_ITEMS` remains a special asset payload. Item selections must not be treated as generic numeric configuration entries.

## Persistence and startup order

1. Load and validate item metadata.
2. Load saved selected item IDs into Java state.
3. Wait until the native library and registered bridge are ready.
4. Replay explicit `itemId → enabled` values.
5. Report/log native bridge failures instead of silently presenting a successful UI state.

The restore implementation must not call the old toggle command.

## UI behavior

- One switch/checkbox per group.
- Expand/collapse reveals individual items.
- All children enabled → group checked.
- No children enabled → group unchecked.
- Some children enabled → group mixed/indeterminate.
- Group actions update every child.
- Individual actions recalculate the parent state.
- Search is optional and does not own selection state.
- Global actions may enable all weapon groups or disable every item.

## Validation checklist

- [ ] Parser accepts valid v2 data.
- [ ] Parser rejects or safely reports malformed/duplicate data.
- [ ] Legacy/current asset compatibility is documented and tested.
- [ ] Group enable and disable are deterministic.
- [ ] Repeated identical native commands are idempotent.
- [ ] Individual changes produce correct mixed state.
- [ ] Restart restores identical Java and native states.
- [ ] Native bridge failures are visible in logs and do not silently desynchronize UI.
- [ ] AndroidIDE clean build passes.
- [ ] Device tests cover group, item, mixed state, and restart behavior.

## Out of scope

- Floating menu drag changes from #2 / PR #3.
- General non-item configuration replay.
- SDK, offsets, skins, and unrelated ESP logic.

## Integration note

This branch starts from `master`, independently of draft PR #3. Rebase after PR #3 merges if both changes touch `Floating.java`; keep drag and grouped-item commits logically separate.
