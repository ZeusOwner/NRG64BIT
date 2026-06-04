#pragma once

#include <array>

namespace skin_tables {

constexpr std::size_t BACKPACK_VARIANT_COUNT = 25;

extern const std::array<int, BACKPACK_VARIANT_COUNT> BackpackLv1;
extern const std::array<int, BACKPACK_VARIANT_COUNT> BackpackLv2;
extern const std::array<int, BACKPACK_VARIANT_COUNT> BackpackLv3;

}  // namespace skin_tables
