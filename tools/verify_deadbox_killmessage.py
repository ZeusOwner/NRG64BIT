#!/usr/bin/env python3
import re
import sys
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
NRG = ROOT / "app" / "src" / "main" / "jni" / "NRG.h"


def strip_comments(text: str) -> str:
    text = re.sub(r"/\*.*?\*/", "", text, flags=re.S)
    return re.sub(r"//.*", "", text)


def find_matching_brace(text: str, open_index: int) -> int:
    depth = 0
    for i in range(open_index, len(text)):
        if text[i] == "{":
            depth += 1
        elif text[i] == "}":
            depth -= 1
            if depth == 0:
                return i
    raise ValueError("missing closing brace")


def read_function(clean_text: str, name: str) -> str:
    match = re.search(r"\b" + re.escape(name) + r"\s*\([^;{}]*\)\s*\{", clean_text)
    if not match:
        raise ValueError(f"missing function {name}")
    start = clean_text.index("{", match.start())
    end = find_matching_brace(clean_text, start)
    return clean_text[start + 1:end]


def require(errors: list[str], condition: bool, message: str) -> None:
    if not condition:
        errors.append(message)


def contains_ordered(body: str, *patterns: str) -> bool:
    position = -1
    for pattern in patterns:
        match = re.search(pattern, body[position + 1:], re.S)
        if not match:
            return False
        position += match.end()
    return True


def check_globals(clean: str, errors: list[str]) -> None:
    require(
        errors,
        re.search(r"static\s+int\s+LastGunUsedToKillSkin\s*=\s*0\s*;", clean) is not None,
        "LastGunUsedToKillSkin must be a static int initialized to 0",
    )
    require(
        errors,
        re.search(r"static\s+std::set\s*<\s*uint64_t\s*>\s+ChangedDeadBoxTargets\s*;", clean) is not None,
        "ChangedDeadBoxTargets must use uint64_t target+skin keys",
    )
    require(
        errors,
        re.search(r"static\s+constexpr\s+int\s+kKillMessageVTableIndex\s*=\s*\d+\s*;", clean) is not None,
        "kill message vtable index constant is missing",
    )


def check_weapon_tracking(clean: str, errors: list[str]) -> None:
    body = read_function(clean, "ApplyFullWeaponSkin")
    require(errors, "if (!weapon) return;" in body, "ApplyFullWeaponSkin must guard null weapon")
    require(
        errors,
        contains_ordered(
            body,
            r"LastGunUsedToKillSkin\s*=\s*0\s*;",
            r"int\s+weaponSkin\s*=\s*GetWeap",
            r"if\s*\(\s*weaponSkin\s*<=\s*0\s*\)\s*return\s*;",
            r"LastGunUsedToKillSkin\s*=\s*weaponSkin\s*;",
        ),
        "ApplyFullWeaponSkin must reset stale kill skin before resolving current weapon",
    )
    require(errors, "weapon->synData" in body, "ApplyFullWeaponSkin must still update weapon sync data")


def check_kill_message(clean: str, errors: list[str]) -> None:
    body = read_function(clean, "kill_message_event")
    require(errors, 'Config["SKIN_ENABLE"]' in body, "kill_message_event must be gated by SKIN_ENABLE")
    require(errors, "PC && FDP" in body, "kill_message_event must null-check PC and FDP")
    require(errors, "PC->PlayerKey == FDP->CauserKey" in body, "kill_message_event must only alter local causer events")
    require(errors, "LastGunUsedToKillSkin > 0" in body, "kill_message_event must require a resolved weapon skin")
    require(
        errors,
        re.search(r"FDP->CauserWeaponAvatarID\s*=\s*LastGunUsedToKillSkin\s*;", body) is not None,
        "kill_message_event must write CauserWeaponAvatarID from LastGunUsedToKillSkin",
    )
    require(errors, "orig_kill_message_event" in body, "kill_message_event must call the original handler")

    hook = read_function(clean, "ApplyFatalDamageSkin")
    require(errors, "localPlayerController->VTable" in hook, "ApplyFatalDamageSkin must use controller vtable")
    require(errors, "kKillMessageVTableIndex" in hook, "ApplyFatalDamageSkin must use the named vtable index")
    require(errors, "== reinterpret_cast<void*>(kill_message_event)" in hook, "ApplyFatalDamageSkin must avoid duplicate hooks")
    require(errors, "ProtectVTableSlot" in hook, "ApplyFatalDamageSkin must protect/unprotect the vtable slot")
    require(errors, "orig_kill_message_event" in hook, "ApplyFatalDamageSkin must save the original handler")


def check_deadbox(clean: str, errors: list[str]) -> None:
    key_body = read_function(clean, "MakeDeadBoxChangeKey")
    require(errors, "static_cast<uint64_t>(targetKey) << 32" in key_body, "MakeDeadBoxChangeKey must include targetKey high bits")
    require(errors, "static_cast<uint32_t>(skinID)" in key_body, "MakeDeadBoxChangeKey must include skinID low bits")

    current_body = read_function(clean, "GetCurrentWeaponSkin")
    require(errors, "CurrentWeaponReplicated" in current_body, "GetCurrentWeaponSkin must read CurrentWeaponReplicated")
    require(errors, "GetWeap" in current_body, "GetCurrentWeaponSkin must map weapon id through GetWeap")

    body = read_function(clean, "ApplyDeadBoxSkin")
    require(errors, "if (!localPlayer) return;" in body, "ApplyDeadBoxSkin must guard null localPlayer")
    require(errors, "ChangedDeadBoxTargets.size() > 512" in body, "ApplyDeadBoxSkin must cap the changed target cache")
    require(errors, "int SkinID = GetCurrentWeaponSkin(localPlayer);" in body, "ApplyDeadBoxSkin must use current weapon skin helper")
    require(errors, "if (SkinID <= 0) return;" in body, "ApplyDeadBoxSkin must skip unsupported/default skin ids")
    require(errors, "GetAllActors(TombBoxes)" in body, "ApplyDeadBoxSkin must enumerate tomb boxes")
    require(errors, "isObjectInvalid(box)" in body, "ApplyDeadBoxSkin must skip invalid tomb boxes")
    require(errors, "box->DamageCauser" in body and "box->TargetPlayer" in body, "ApplyDeadBoxSkin must validate tomb box players")
    require(errors, "box->DamageCauser->PlayerKey != localPlayer->PlayerKey" in body, "ApplyDeadBoxSkin must only touch local-player kills")
    require(errors, "MakeDeadBoxChangeKey(targetKey, SkinID)" in body, "ApplyDeadBoxSkin must cache by target+skin")
    require(errors, "ChangedDeadBoxTargets.count(changeKey)" in body, "ApplyDeadBoxSkin must check target+skin cache key")
    require(
        errors,
        "GetComponentByClass(UDeadBoxAvatarComponent::StaticClass())" in body,
        "ApplyDeadBoxSkin must use typed component lookup instead of hardcoded offsets",
    )
    require(errors, "PreChangeItemAvatar(SkinID)" in body, "ApplyDeadBoxSkin must call PreChangeItemAvatar")
    require(errors, "AsyncChangeItemAvatar(SkinID)" in body, "ApplyDeadBoxSkin must call AsyncChangeItemAvatar")
    require(errors, "ChangedDeadBoxTargets.insert(changeKey)" in body, "ApplyDeadBoxSkin must insert the target+skin cache key")
    require(errors, "0x510" not in body, "ApplyDeadBoxSkin must not use the old hardcoded 0x510 offset")
    require(errors, "ChangeItemAVc" not in body, "ApplyDeadBoxSkin must not use the old vtable ChangeItemAVc path")


def check_call_sites(clean: str, errors: list[str]) -> None:
    require(errors, "ApplyFatalDamageSkin(localPlayerController)" in clean, "ApplyFatalDamageSkin call site is missing")
    require(errors, "ApplyDeadBoxSkin(localPlayer)" in clean, "ApplyDeadBoxSkin call site is missing")
    require(errors, "ApplyWeaponSkinFromProcessEvent" in clean, "ProcessEvent weapon skin path is missing")
    require(errors, 'Config["SKIN_ENABLE"]' in clean, "SKIN_ENABLE gating is missing from runtime skin flow")


def main() -> int:
    if not NRG.exists():
        print(f"Missing {NRG}", file=sys.stderr)
        return 2

    clean = strip_comments(NRG.read_text(encoding="utf-8", errors="ignore"))
    errors: list[str] = []

    try:
        check_globals(clean, errors)
        check_weapon_tracking(clean, errors)
        check_kill_message(clean, errors)
        check_deadbox(clean, errors)
        check_call_sites(clean, errors)
    except ValueError as exc:
        errors.append(str(exc))

    if errors:
        print("Deadbox/killmessage verification FAILED")
        for error in errors:
            print(f" - {error}")
        return 1

    print("Deadbox/killmessage verification PASSED")
    print(" - killmessage hook is guarded, idempotent, and clears stale weapon skin state")
    print(" - deadbox apply uses typed component lookup and target+skin cache keys")
    print(" - runtime call sites remain wired behind SKIN_ENABLE")
    return 0


if __name__ == "__main__":
    sys.exit(main())
