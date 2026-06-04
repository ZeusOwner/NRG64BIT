#!/usr/bin/env python3
import argparse
import re
import sys
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
TABLES = ROOT / "app" / "src" / "main" / "jni" / "skin_tables"


CATEGORIES = {
    "M416": {
        "file": "m416_skins.cpp",
        "count": "M416_VARIANT_COUNT",
        "arrays": {
            "M416_1": "M4161",
            "M416_2": "M4162",
            "M416_3": "M4163",
            "M416_4": "M4164",
            "M416_flash": "M416flash",
            "M416_compe": "M416compe",
            "M416_silent": "M416silent",
            "M416_reddot": "M416reddot",
            "M416_holo": "M416holo",
            "M416_x2": "M416x2",
            "M416_x3": "M416x3",
            "M416_x4": "M416x4",
            "M416_x6": "M416x6",
            "M416_quickMag": "M416quickMag",
            "M416_extendedMag": "M416extendedMag",
            "M416_quickNextended": "M416quickNextended",
            "M416_stock": "M416stock",
            "M416_verical": "M416verical",
            "M416_angle": "M416angle",
            "M416_lightgrip": "M416lightgrip",
            "M416_pink": "M416pink",
            "M416_lazer": "M416lazer",
            "M416_thumb": "M416thumb",
        },
    },
    "AKM": {
        "file": "akm_skins.cpp",
        "count": "AKM_VARIANT_COUNT",
        "arrays": {
            "AKM": "AKMPrimary",
            "AKM_Mag": "AKMMag",
            "AKM_flash": "AKMFlash",
            "AKM_compe": "AKMCompensator",
            "AKM_silent": "AKMSuppressor",
            "AKM_reddot": "AKMReddot",
            "AKM_holo": "AKMHolo",
            "AKM_x2": "AKMx2",
            "AKM_x3": "AKMx3",
            "AKM_x4": "AKMx4",
            "AKM_x6": "AKMx6",
            "AKM_quickMag": "AKMQuickMag",
            "AKM_extendedMag": "AKMExtendedMag",
            "AKM_quickNextended": "AKMQuickExtendedMag",
            "AKM_stock": "AKMStock",
            "AKM_verical": "AKMVertical",
            "AKM_angle": "AKMAngle",
            "AKM_lightgrip": "AKMLightgrip",
            "AKM_pink": "AKMPink",
            "AKM_lazer": "AKMLazer",
            "AKM_thumb": "AKMThumb",
        },
    },
    "BACKPACK": {
        "file": "backpack_skins.cpp",
        "count": "BACKPACK_VARIANT_COUNT",
        "arrays": {
            "baglv1": "BackpackLv1",
            "baglv2": "BackpackLv2",
            "baglv3": "BackpackLv3",
        },
    },
    "BIZON": {
        "file": "bizon_skins.cpp",
        "count": "BIZON_VARIANT_COUNT",
        "arrays": {
            "Bizon": "BizonPrimary",
        },
    },
    "HELMET": {
        "file": "helmet_skins.cpp",
        "count": "HELMET_VARIANT_COUNT",
        "arrays": {
            "helmetlv1": "HelmetLv1",
            "helmetlv2": "HelmetLv2",
            "helmetlv3": "HelmetLv3",
        },
    },
    "DACIA": {
        "file": "dacia_skins.cpp",
        "count": "DACIA_VARIANT_COUNT",
        "arrays": {
            "Dacia": "DaciaSkins",
        },
    },
    "HONEY": {
        "file": "honey_skins.cpp",
        "count": "HONEY_VARIANT_COUNT",
        "arrays": {
            "Honey": "HoneyPrimary",
        },
    },
    "SCARL": {
        "file": "scarl_skins.cpp",
        "count": "SCARL_VARIANT_COUNT",
        "arrays": {
            "Scar": "SCARPrimary",
            "Scar_Mag": "SCARMag",
            "Scar_3": "SCARSide",
            "Scar_flash": "SCARFlash",
            "Scar_compe": "SCARCompe",
            "Scar_silent": "SCARSilent",
            "Scar_reddot": "SCARReddot",
            "Scar_holo": "SCARHolo",
            "Scar_x2": "SCARx2",
            "Scar_x3": "SCARx3",
            "Scar_x4": "SCARx4",
            "Scar_x6": "SCARx6",
            "Scar_quickMag": "SCARQuickMag",
            "Scar_extendedMag": "SCARExtendedMag",
            "Scar_quickNextended": "SCARQuickExtended",
            "Scar_verical": "SCARVertical",
            "Scar_angle": "SCARAngle",
            "Scar_lightgrip": "SCARLightgrip",
            "Scar_pink": "SCARPink",
            "Scar_lazer": "SCARLazer",
            "Scar_thumb": "SCARThumb",
        },
    },
    "M762": {
        "file": "m762_skins.cpp",
        "count": "M762_VARIANT_COUNT",
        "arrays": {
            "M762": "M762Primary",
            "M762_Mag": "M762Mag",
            "M762_reddot": "M762Reddot",
            "M762_holo": "M762Holo",
            "M762_x2": "M762x2",
            "M762_x3": "M762x3",
            "M762_x4": "M762x4",
            "M762_x6": "M762x6",
            "M762_lazer": "M762Lazer",
            "M762_flash": "M762Flash",
        },
    },
    "UMP45": {
        "file": "ump45_skins.cpp",
        "count": "UMP_VARIANT_COUNT",
        "arrays": {
            "UMP": "UMPPrimary",
        },
    },
    "VECTOR": {
        "file": "vector_skins.cpp",
        "count": "VECTOR_VARIANT_COUNT",
        "arrays": {
            "Vector": "VectorPrimary",
        },
    },
    "KAR98K": {
        "file": "kar98_skins.cpp",
        "count": "KAR98_VARIANT_COUNT",
        "arrays": {
            "K98": "Kar98Primary",
        },
    },
    "M24": {
        "file": "m24_skins.cpp",
        "count": "M24_VARIANT_COUNT",
        "arrays": {
            "M24": "M24Primary",
        },
    },
    "AWM": {
        "file": "awm_skins.cpp",
        "count": "AWM_VARIANT_COUNT",
        "arrays": {
            "AWM": "AWMPrimary",
        },
    },
    "AMR": {
        "file": "amr_skins.cpp",
        "count": "AMR_VARIANT_COUNT",
        "arrays": {
            "AMR": "AMRPrimary",
        },
    },
    "P90": {
        "file": "p90_skins.cpp",
        "count": "P90_VARIANT_COUNT",
        "arrays": {
            "P90": "P90Primary",
        },
    },
    "PAN": {
        "file": "pan_skins.cpp",
        "count": "PAN_VARIANT_COUNT",
        "arrays": {
            "Pan": "PanPrimary",
        },
    },
    "QBZ": {
        "file": "qbz_skins.cpp",
        "count": "QBZ_VARIANT_COUNT",
        "arrays": {
            "QBZ": "QBZPrimary",
        },
    },
    "XM1014": {
        "file": "xm1014_skins.cpp",
        "count": "XM1014_VARIANT_COUNT",
        "arrays": {
            "XM1014": "XM1014Primary",
        },
    },
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


def read_count(header_text: str, count_name: str) -> int:
    match = re.search(r"\b" + re.escape(count_name) + r"\s*=\s*(\d+)", header_text)
    if not match:
        raise ValueError(f"missing {count_name}")
    return int(match.group(1))


def read_array(cpp_text: str, name: str) -> list[int]:
    match = re.search(r"\b" + re.escape(name) + r"\s*=\s*\{", cpp_text)
    if not match:
        raise ValueError(f"missing array {name}")
    start = cpp_text.index("{", match.start())
    end = find_matching_brace(cpp_text, start)
    body = cpp_text[start + 1:end]
    return [int(value) for value in re.findall(r"-?\d+", body)]


def load_category(name: str) -> tuple[int, dict[str, list[int]]]:
    spec = CATEGORIES[name]
    cpp_path = TABLES / spec["file"]
    header_path = cpp_path.with_suffix(".h")
    header_text = header_path.read_text(encoding="utf-8")
    cpp_text = strip_comments(cpp_path.read_text(encoding="utf-8"))
    count = read_count(header_text, spec["count"])
    arrays = {field: read_array(cpp_text, array_name) for field, array_name in spec["arrays"].items()}
    return count, arrays


def simulate(name: str, index: int) -> list[str]:
    count, arrays = load_category(name)
    lines = [f"{name} index {index} / max {count - 1}"]
    if index < 0 or index >= count:
        lines.append("  OUT_OF_RANGE: native table path ignores this index; previous legacy/default value remains")
        return lines

    for field, values in arrays.items():
        if index >= len(values):
            lines.append(f"  {field}: KEEP_EXISTING (array has no explicit slot)")
            continue
        value = values[index]
        if value == 0:
            lines.append(f"  {field}: KEEP_EXISTING (table value is 0)")
        else:
            lines.append(f"  {field}: {value}")
    return lines


def default_indices(count: int) -> list[int]:
    indices = [0, count // 2, count - 1]
    return list(dict.fromkeys(indices))


def main() -> int:
    parser = argparse.ArgumentParser(description="Offline simulator for skin table selections.")
    parser.add_argument("category", nargs="?", help=f"One of: {', '.join(sorted(CATEGORIES))}")
    parser.add_argument("index", nargs="?", type=int, help="Slider/config index to simulate")
    parser.add_argument("--list", action="store_true", help="List supported simulator categories")
    args = parser.parse_args()

    if args.list:
        for category in sorted(CATEGORIES):
            count, _ = load_category(category)
            print(f"{category}: 0..{count - 1}")
        return 0

    if args.category:
        category = args.category.upper()
        if category not in CATEGORIES:
            print(f"Unknown category: {args.category}", file=sys.stderr)
            return 2
        if args.index is None:
            count, _ = load_category(category)
            indices = default_indices(count)
        else:
            indices = [args.index]
        for i, index in enumerate(indices):
            if i:
                print()
            print("\n".join(simulate(category, index)))
        return 0

    for category in ("M416", "AKM", "BACKPACK", "HELMET", "DACIA"):
        count, _ = load_category(category)
        for index in default_indices(count):
            print("\n".join(simulate(category, index)))
            print()
    return 0


if __name__ == "__main__":
    sys.exit(main())
