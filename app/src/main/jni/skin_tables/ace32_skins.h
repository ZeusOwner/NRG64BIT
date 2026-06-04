#pragma once

#include <array>

namespace skin_tables {

constexpr std::size_t ACE32_VARIANT_COUNT = 7;

extern const std::array<int, ACE32_VARIANT_COUNT> ACE32Primary;
extern const std::array<int, ACE32_VARIANT_COUNT> ACE32Reddot;
extern const std::array<int, ACE32_VARIANT_COUNT> ACE32Holo;
extern const std::array<int, ACE32_VARIANT_COUNT> ACE32x2;
extern const std::array<int, ACE32_VARIANT_COUNT> ACE32x3;
extern const std::array<int, ACE32_VARIANT_COUNT> ACE32x4;
extern const std::array<int, ACE32_VARIANT_COUNT> ACE32x6;

}  // namespace skin_tables
