#pragma once

#include <array>

namespace skin_tables {

constexpr std::size_t M762_VARIANT_COUNT = 16;

extern const std::array<int, M762_VARIANT_COUNT> M762Primary;
extern const std::array<int, M762_VARIANT_COUNT> M762Mag;
extern const std::array<int, M762_VARIANT_COUNT> M762Reddot;
extern const std::array<int, M762_VARIANT_COUNT> M762Holo;
extern const std::array<int, M762_VARIANT_COUNT> M762x2;
extern const std::array<int, M762_VARIANT_COUNT> M762x3;
extern const std::array<int, M762_VARIANT_COUNT> M762x4;
extern const std::array<int, M762_VARIANT_COUNT> M762x6;
extern const std::array<int, M762_VARIANT_COUNT> M762Lazer;
extern const std::array<int, M762_VARIANT_COUNT> M762Flash;

}  // namespace skin_tables
