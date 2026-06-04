#!/usr/bin/env python3
import re
import sys
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
UPDATE = ROOT / "app" / "src" / "main" / "jni" / "UpdateSkinManager.cpp"
TABLES = ROOT / "app" / "src" / "main" / "jni" / "skin_tables"


CATEGORIES = {
    "AKM": ("SKIN_AKM", "AKM", "akm_skins.cpp", "AKMPrimary"),
    "M416": ("SKIN_M416", "M416_1", "m416_skins.cpp", "M4161"),
    "SCARL": ("SKIN_SCARL", "Scar", "scarl_skins.cpp", "SCARPrimary"),
    "M762": ("SKIN_M762", "M762", "m762_skins.cpp", "M762Primary"),
    "M16A4": ("SKIN_M16A4", "M16A4", "m16a4_skins.cpp", "M16A4Primary"),
    "GROZA": ("SKIN_GROZAR", "Groza", "groza_skins.cpp", "GrozaPrimary"),
    "AUG": ("SKIN_AUG", "AUG", "aug_skins.cpp", "AUGPrimary"),
    "QBZ": ("SKIN_QBZ", "QBZ", "qbz_skins.cpp", "QBZPrimary"),
    "HONEY": ("SKIN_HONEY", "Honey", "honey_skins.cpp", "HoneyPrimary"),
    "ACE32": ("SKIN_ACE32", "ACE32", "ace32_skins.cpp", "ACE32Primary"),
    "UZI": ("SKIN_UZI", "UZI", "uzi_skins.cpp", "UZIPrimary"),
    "UMP45": ("SKIN_UMP45", "UMP", "ump45_skins.cpp", "UMPPrimary"),
    "VECTOR": ("SKIN_VECTOR", "Vector", "vector_skins.cpp", "VectorPrimary"),
    "THOMPSON": ("SKIN_THOMPSON", "Thompson", "thompson_skins.cpp", "ThompsonPrimary"),
    "BIZON": ("SKIN_BIZON", "Bizon", "bizon_skins.cpp", "BizonPrimary"),
    "P90": ("SKIN_P90", "P90", "p90_skins.cpp", "P90Primary"),
    "PAN": ("SKIN_PAN", "Pan", "pan_skins.cpp", "PanPrimary"),
    "KAR98K": ("SKIN_KAR98K", "K98", "kar98_skins.cpp", "Kar98Primary"),
    "M24": ("SKIN_M24", "M24", "m24_skins.cpp", "M24Primary"),
    "AWM": ("SKIN_AWM", "AWM", "awm_skins.cpp", "AWMPrimary"),
    "AMR": ("SKIN_AMR", "AMR", "amr_skins.cpp", "AMRPrimary"),
    "MK14": ("SKIN_MK14", "MK14", "mk14_skins.cpp", "MK14Primary"),
    "MINI14": ("SKIN_MINI14", "Mini14", "mini14_skins.cpp", "Mini14Primary"),
    "M249": ("SKIN_M249", "M249", "m249_skins.cpp", "M249Primary"),
    "DP28": ("SKIN_DP28", "DP28", "dp28_skins.cpp", "DP28Primary"),
    "MG3": ("SKIN_MG3", "MG3", "mg3_skins.cpp", "MG3Primary"),
    "S12K": ("SKIN_S12K", "S12K", "s12k_skins.cpp", "S12KPrimary"),
    "DBS": ("SKIN_DBS", "DBS", "dbs_skins.cpp", "DBSPrimary"),
    "XM1014": ("SKIN_XM1014", "XM1014", "xm1014_skins.cpp", "XM1014Primary"),
}


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


def read_array(cpp_text: str, name: str) -> list[int]:
    match = re.search(r"\b" + re.escape(name) + r"\s*=\s*\{", cpp_text)
    if not match:
        raise ValueError(f"missing array {name}")
    start = cpp_text.index("{", match.start())
    end = find_matching_brace(cpp_text, start)
    return [int(value) for value in re.findall(r"-?\d+", cpp_text[start + 1:end])]


def read_legacy(update_text: str, key: str, field: str) -> dict[int, int]:
    result: dict[int, int] = {}
    pattern = re.compile(
        r'if\s*\(\s*Config\["'
        + re.escape(key)
        + r'"\]\s*==\s*(\d+)\s*\)\s*(?:\{\s*)?\n\s*new_Skin\.'
        + re.escape(field)
        + r"\s*=\s*(\d+)",
        re.M,
    )
    for match in pattern.finditer(update_text):
        result[int(match.group(1))] = int(match.group(2))
    return result


def main() -> int:
    update_text = UPDATE.read_text(encoding="utf-8")
    mismatches = 0
    missing = 0
    checked = 0

    for name, (key, field, cpp_name, array_name) in CATEGORIES.items():
        legacy = read_legacy(update_text, key, field)
        if not legacy:
            continue
        checked += len(legacy)
        table = read_array(strip_comments((TABLES / cpp_name).read_text(encoding="utf-8")), array_name)
        rows = []
        for index in sorted(legacy):
            table_value = table[index] if index < len(table) else None
            legacy_value = legacy[index]
            if table_value != legacy_value:
                rows.append((index, legacy_value, table_value))
                mismatches += 1
                if legacy_value not in table:
                    missing += 1
        if rows:
            print(f"{name}: {len(rows)} mismatch(es)")
            for index, legacy_value, table_value in rows:
                table_text = "MISSING_INDEX" if table_value is None else str(table_value)
                present = "present-in-table" if legacy_value in table else "legacy-id-not-in-table"
                print(f"  index {index}: legacy={legacy_value} table={table_text} {present}")

    if mismatches:
        print(f"Total mismatches: {mismatches}")
        print(f"Legacy IDs missing from current tables: {missing}")
        return 1

    if checked == 0:
        print("No legacy updateSkin primary blocks found; active skin logic is table-backed only")
        return 0

    print("Legacy primary IDs match skin_tables primary IDs for checked categories")
    return 0


if __name__ == "__main__":
    sys.exit(main())
