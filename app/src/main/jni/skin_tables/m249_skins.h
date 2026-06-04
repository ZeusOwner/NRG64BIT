#pragma once

#include <array>

namespace skin_tables {

constexpr std::size_t M249_VARIANT_COUNT = 7;

extern const std::array<int, M249_VARIANT_COUNT> M249Primary;
extern const std::array<int, M249_VARIANT_COUNT> M249Stock;

}  // namespace skin_tables
