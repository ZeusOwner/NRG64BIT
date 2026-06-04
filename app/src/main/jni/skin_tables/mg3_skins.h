#pragma once

#include <array>

namespace skin_tables {

constexpr std::size_t MG3_VARIANT_COUNT = 4;

extern const std::array<int, MG3_VARIANT_COUNT> MG3Primary;
extern const std::array<int, MG3_VARIANT_COUNT> MG3Reddot;
extern const std::array<int, MG3_VARIANT_COUNT> MG3Holo;
extern const std::array<int, MG3_VARIANT_COUNT> MG3x2;
extern const std::array<int, MG3_VARIANT_COUNT> MG3x3;
extern const std::array<int, MG3_VARIANT_COUNT> MG3x4;
extern const std::array<int, MG3_VARIANT_COUNT> MG3x6;

}  // namespace skin_tables
