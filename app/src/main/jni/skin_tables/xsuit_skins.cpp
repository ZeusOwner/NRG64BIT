#include "xsuit_skins.h"

namespace skin_tables {

// Index 0 is fallback; remaining entries mirror the legacy single-star mappings with paired accessories.
const std::array<XSuitLoadoutEntry, XSUIT_VARIANT_COUNT> XSuits = {
    XSuitLoadoutEntry{403003, 40604002, 0},          // fallback/default slot-preserving placeholder
    XSuitLoadoutEntry{1405628, 1402578, 0},          // Golden Pharaoh (6★) + Pharaoh mask
    XSuitLoadoutEntry{1405870, 1403257, 0},          // Blood Raven (6★) + mask
    XSuitLoadoutEntry{1407140, 1402874, 0},          // Poseidon X-Suit (7-Star)
    XSuitLoadoutEntry{1407141, 1403393, 0},          // Avalanche X-Suit (7-Star)
    XSuitLoadoutEntry{1406311, 1410011, 0},          // Silvanus-style body + mask
    XSuitLoadoutEntry{1406475, 1410131, 0},          // Iridescence-style body + mask
    XSuitLoadoutEntry{1406638, 1410242, 0},          // Arcane Jester-style body + accessory
    XSuitLoadoutEntry{1406872, 1403577, 0},         // Stygian-style body + accessory
    XSuitLoadoutEntry{1406971, 402147,   0},         // Marmoris-style body + accessory
    XSuitLoadoutEntry{1407103, 40604002, 0},         // Fiore 7★ body + generic accessory
    XSuitLoadoutEntry{1407391, 40604002, 0},          // Spare mapping (kept for backward compatibility)
    XSuitLoadoutEntry{1405623, 0, 0},                // Yellow Mummy
    XSuitLoadoutEntry{1400687, 0, 0}                  // White Mummy
};

static_assert(XSuits.size() == XSUIT_VARIANT_COUNT, "XSuit loadout size mismatch");

}  // namespace skin_tables
