#pragma once

#include <array>

namespace skin_tables {

constexpr std::size_t KAR98_VARIANT_COUNT = 13;

extern const std::array<int, KAR98_VARIANT_COUNT> Kar98Primary;
extern const std::array<int, KAR98_VARIANT_COUNT> Kar98Compensator;
extern const std::array<int, KAR98_VARIANT_COUNT> Kar98Flash;
extern const std::array<int, KAR98_VARIANT_COUNT> Kar98Suppressor;
extern const std::array<int, KAR98_VARIANT_COUNT> Kar98Muzzle;
extern const std::array<int, KAR98_VARIANT_COUNT> Kar98Barrel;
extern const std::array<int, KAR98_VARIANT_COUNT> Kar98Reddot;
extern const std::array<int, KAR98_VARIANT_COUNT> Kar98Holo;
extern const std::array<int, KAR98_VARIANT_COUNT> Kar98x2;
extern const std::array<int, KAR98_VARIANT_COUNT> Kar98x3;
extern const std::array<int, KAR98_VARIANT_COUNT> Kar98x4;
extern const std::array<int, KAR98_VARIANT_COUNT> Kar98x6;
extern const std::array<int, KAR98_VARIANT_COUNT> Kar98x8;

}  // namespace skin_tables
