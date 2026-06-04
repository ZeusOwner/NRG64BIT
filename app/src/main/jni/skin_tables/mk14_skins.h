#pragma once

#include <array>

namespace skin_tables {

// Expanded to cover the commonly referenced MK14 upgrade skins instead of a single entry.
constexpr std::size_t MK14_VARIANT_COUNT = 12;

extern const std::array<int, MK14_VARIANT_COUNT> MK14Primary;
extern const std::array<int, MK14_VARIANT_COUNT> MK14Mag;
extern const std::array<int, MK14_VARIANT_COUNT> MK14Flash;
extern const std::array<int, MK14_VARIANT_COUNT> MK14Compensator;
extern const std::array<int, MK14_VARIANT_COUNT> MK14Suppressor;
extern const std::array<int, MK14_VARIANT_COUNT> MK14Muzzle;
extern const std::array<int, MK14_VARIANT_COUNT> MK14Barrel;
extern const std::array<int, MK14_VARIANT_COUNT> MK14Reddot;
extern const std::array<int, MK14_VARIANT_COUNT> MK14Holo;
extern const std::array<int, MK14_VARIANT_COUNT> MK14x2;
extern const std::array<int, MK14_VARIANT_COUNT> MK14x3;
extern const std::array<int, MK14_VARIANT_COUNT> MK14x4;
extern const std::array<int, MK14_VARIANT_COUNT> MK14x6;
extern const std::array<int, MK14_VARIANT_COUNT> MK14x8;
extern const std::array<int, MK14_VARIANT_COUNT> MK14Lazer;

}  // namespace skin_tables
