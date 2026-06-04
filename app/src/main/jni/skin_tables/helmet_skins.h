#pragma once

#include <array>

namespace skin_tables {

constexpr std::size_t HELMET_VARIANT_COUNT = 16;

extern const std::array<int, HELMET_VARIANT_COUNT> HelmetLv1;
extern const std::array<int, HELMET_VARIANT_COUNT> HelmetLv2;
extern const std::array<int, HELMET_VARIANT_COUNT> HelmetLv3;

}  // namespace skin_tables
