#pragma once

#include <array>

namespace skin_tables {

constexpr std::size_t M16A4_VARIANT_COUNT = 11;

extern const std::array<int, M16A4_VARIANT_COUNT> M16A4Primary;
extern const std::array<int, M16A4_VARIANT_COUNT> M16A4Stock;
extern const std::array<int, M16A4_VARIANT_COUNT> M16A4Mag;

}  // namespace skin_tables
