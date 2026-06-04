#pragma once

#include <array>

namespace skin_tables {

constexpr std::size_t M24_VARIANT_COUNT = 13;

extern const std::array<int, M24_VARIANT_COUNT> M24Primary;
extern const std::array<int, M24_VARIANT_COUNT> M24Reddot;
extern const std::array<int, M24_VARIANT_COUNT> M24Holo;
extern const std::array<int, M24_VARIANT_COUNT> M24x2;
extern const std::array<int, M24_VARIANT_COUNT> M24x3;
extern const std::array<int, M24_VARIANT_COUNT> M24x4;
extern const std::array<int, M24_VARIANT_COUNT> M24x6;
extern const std::array<int, M24_VARIANT_COUNT> M24x8;

}  // namespace skin_tables
