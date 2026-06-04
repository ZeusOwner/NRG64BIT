#!/usr/bin/env python3
import argparse
import re
import sys
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
JNI = ROOT / "app" / "src" / "main" / "jni"
TABLES = JNI / "skin_tables"
FLOATING = ROOT / "app" / "src" / "main" / "java" / "com" / "bearmod" / "Floating.java"
UPDATE = JNI / "UpdateSkinManager.cpp"
ANDROID_MK = JNI / "Android.mk"


JAVA_LIMITS = {
    "SKIN_XSUIT": 13,
    "SKIN_BACKPACK": 24,
    "SKIN_HELMET": 15,
    "SKIN_VEHICLE_DACIA": 24,
    "SKIN_VEHICLE_UAZ": 14,
    "SKIN_VEHICLE_BUGGY": 33,
    "SKIN_VEHICLE_MOTO": 10,
    "SKIN_VEHICLE_MINIBUS": 12,
    "SKIN_VEHICLE_COUPERB": 30,
    "SKIN_VEHICLE_BOAT": 11,
    "SKIN_M416": 12,
    "SKIN_AKM": 16,
    "SKIN_SCARL": 13,
    "SKIN_M762": 15,
    "SKIN_M16A4": 10,
    "SKIN_GROZAR": 8,
    "SKIN_AUG": 6,
    "SKIN_QBZ": 2,
    "SKIN_HONEY": 1,
    "SKIN_ACE32": 6,
    "SKIN_M249": 6,
    "SKIN_DP28": 8,
    "SKIN_MG3": 3,
    "SKIN_PAN": 4,
    "SKIN_UZI": 10,
    "SKIN_UMP45": 12,
    "SKIN_VECTOR": 9,
    "SKIN_THOMPSON": 2,
    "SKIN_BIZON": 1,
    "SKIN_P90": 3,
    "SKIN_M24": 12,
    "SKIN_KAR98K": 12,
    "SKIN_AWM": 9,
    "SKIN_AMR": 7,
    "SKIN_MK14": 11,
    "SKIN_MINI14": 4,
    "SKIN_S12K": 4,
    "SKIN_DBS": 6,
    "SKIN_XM1014": 1,
}


TABLE_CONFIGS = {
    "SKIN_M416",
    "SKIN_AKM",
    "SKIN_SCARL",
    "SKIN_M762",
    "SKIN_M16A4",
    "SKIN_GROZAR",
    "SKIN_AUG",
    "SKIN_QBZ",
    "SKIN_HONEY",
    "SKIN_ACE32",
    "SKIN_M249",
    "SKIN_DP28",
    "SKIN_MG3",
    "SKIN_PAN",
    "SKIN_UZI",
    "SKIN_UMP45",
    "SKIN_VECTOR",
    "SKIN_THOMPSON",
    "SKIN_BIZON",
    "SKIN_P90",
    "SKIN_M24",
    "SKIN_KAR98K",
    "SKIN_AWM",
    "SKIN_AMR",
    "SKIN_MK14",
    "SKIN_MINI14",
    "SKIN_S12K",
    "SKIN_DBS",
    "SKIN_XM1014",
    "SKIN_BACKPACK",
    "SKIN_HELMET",
    "SKIN_XSUIT",
    "SKIN_VEHICLE_DACIA",
    "SKIN_VEHICLE_UAZ",
    "SKIN_VEHICLE_BUGGY",
    "SKIN_VEHICLE_MOTO",
    "SKIN_VEHICLE_MINIBUS",
    "SKIN_VEHICLE_COUPERB",
    "SKIN_VEHICLE_BOAT",
}


DEAD_SYMBOLS = [
    "ApplyM416DefaultSkin",
    "ApplyM416LuaSkin",
    "ApplyLuaVipSkinRefresh",
    "ApplyVehicleSkinRefresh",
    "ApplySimpleSkin",
    "ApplyMagSkin",
    "ApplyEquipmentSkin",
    "SkinChoice",
    "EquipmentChoice",
]


def strip_comments(text: str) -> str:
    text = re.sub(r"/\*.*?\*/", "", text, flags=re.S)
    text = re.sub(r"//.*", "", text)
    return text


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


def count_array_entries(clean_cpp: str, name: str) -> int:
    match = re.search(r"\b" + re.escape(name) + r"\s*=\s*\{", clean_cpp)
    if not match:
        raise ValueError(f"missing array definition for {name}")
    start = clean_cpp.index("{", match.start())
    end = find_matching_brace(clean_cpp, start)
    body = clean_cpp[start + 1:end].strip()
    if not body:
        return 0
    if "XSuitLoadoutEntry" in body:
        return len(re.findall(r"XSuitLoadoutEntry\s*\{", body))
    return len(re.findall(r"-?\d+", body))


def check_table_counts(errors: list[str]) -> None:
    for header in sorted(TABLES.glob("*_skins.h")):
        cpp = header.with_suffix(".cpp")
        if not cpp.exists():
            errors.append(f"missing cpp for {header.name}")
            continue

        h_text = header.read_text(encoding="utf-8")
        c_text = strip_comments(cpp.read_text(encoding="utf-8"))
        count_match = re.search(r"constexpr\s+std::size_t\s+(\w+)_VARIANT_COUNT\s*=\s*(\d+)", h_text)
        if not count_match:
            errors.append(f"missing VARIANT_COUNT in {header.name}")
            continue
        expected = int(count_match.group(2))

        arrays = re.findall(r"extern\s+const\s+std::array<[^,>]+,\s*\w+_VARIANT_COUNT>\s+(\w+)", h_text)
        if not arrays:
            errors.append(f"missing extern arrays in {header.name}")
            continue
        for array_name in arrays:
            try:
                actual = count_array_entries(c_text, array_name)
            except ValueError as exc:
                errors.append(f"{cpp.name}: {exc}")
                continue
            if actual != expected:
                errors.append(f"{cpp.name}:{array_name} count {actual}, expected {expected}")


def check_android_mk(errors: list[str]) -> None:
    mk = ANDROID_MK.read_text(encoding="utf-8")
    for cpp in sorted(TABLES.glob("*_skins.cpp")):
        rel = f"skin_tables/{cpp.name}"
        if rel not in mk:
            errors.append(f"Android.mk missing {rel}")


def check_java_limits(errors: list[str]) -> None:
    text = FLOATING.read_text(encoding="utf-8")
    for key, expected in sorted(JAVA_LIMITS.items()):
        pattern = r"addSeekRow\([^;]*,\s*0,\s*" + str(expected) + r"\s*,\s*GetInteger\(\"" + re.escape(key) + r"\"\)"
        if not re.search(pattern, text):
            errors.append(f"Floating.java slider max mismatch for {key}: expected {expected}")


def check_update_manager(errors: list[str]) -> None:
    text = UPDATE.read_text(encoding="utf-8")
    clean = strip_comments(text)
    for symbol in DEAD_SYMBOLS:
        if re.search(r"\b" + re.escape(symbol) + r"\b", clean):
            errors.append(f"dead symbol still present: {symbol}")

    apply_pos = clean.find("void ApplySkinTablesRefresh()")
    update_pos = clean.find("void updateSkin()")
    final_call = clean.rfind("ApplySkinTablesRefresh();")
    if apply_pos == -1:
        errors.append("missing ApplySkinTablesRefresh definition")
    if update_pos == -1:
        errors.append("missing updateSkin definition")
    if final_call == -1 or (update_pos != -1 and final_call < update_pos):
        errors.append("ApplySkinTablesRefresh is not called at the end of updateSkin flow")

    if "selected < static_cast<u_long>(N)" not in clean:
        errors.append("missing table bounds check helper")

    for key in sorted(TABLE_CONFIGS):
        if f'"{key}"' not in clean:
            errors.append(f"table-backed config key not referenced in UpdateSkinManager.cpp: {key}")


def zero_report() -> int:
    rows: list[tuple[str, str, int, int]] = []
    for cpp in sorted(TABLES.glob("*_skins.cpp")):
        clean = strip_comments(cpp.read_text(encoding="utf-8"))
        for match in re.finditer(r"const\s+std::array<[^>]+>\s+(\w+)\s*=\s*\{", clean):
            name = match.group(1)
            start = clean.index("{", match.start())
            end = find_matching_brace(clean, start)
            values = [int(value) for value in re.findall(r"-?\d+", clean[start + 1:end])]
            zeros = sum(1 for value in values if value == 0)
            if zeros:
                rows.append((cpp.name, name, len(values), zeros))

    if not rows:
        print("No zero fallback markers found in skin tables")
        return 0

    print("Zero fallback marker report")
    print("0 means ApplyTableValue keeps the existing/default new_Skin field.")
    for file_name, array_name, slots, zeros in rows:
        print(f" - {file_name}:{array_name} slots={slots} zeros={zeros}")
    print(f"Total arrays with zero fallback markers: {len(rows)}")
    return 0


def main() -> int:
    parser = argparse.ArgumentParser(description="Verify offline skin table/config wiring.")
    parser.add_argument("--zero-report", action="store_true", help="Print arrays containing 0 fallback markers")
    args = parser.parse_args()

    if args.zero_report:
        return zero_report()

    errors: list[str] = []
    for path in (TABLES, FLOATING, UPDATE, ANDROID_MK):
        if not path.exists():
            errors.append(f"missing required path: {path}")

    if not errors:
        check_table_counts(errors)
        check_android_mk(errors)
        check_java_limits(errors)
        check_update_manager(errors)

    if errors:
        print("Skin logic verification FAILED")
        for error in errors:
            print(f" - {error}")
        return 1

    print("Skin logic verification PASSED")
    print(" - skin_tables array counts match VARIANT_COUNT")
    print(" - Android.mk includes every skin table cpp")
    print(" - Java slider limits match table-backed max values")
    print(" - UpdateSkinManager uses final table apply path with bounds checks")
    print(" - legacy updateSkin blocks have been removed from the active apply path")
    return 0


if __name__ == "__main__":
    sys.exit(main())
