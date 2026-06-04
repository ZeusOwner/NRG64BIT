#pragma once

#include <array>

namespace skin_tables {

constexpr std::size_t AWM_VARIANT_COUNT = 10;

extern const std::array<int, AWM_VARIANT_COUNT> AWMPrimary;
extern const std::array<int, AWM_VARIANT_COUNT> AWMReddot;
extern const std::array<int, AWM_VARIANT_COUNT> AWMHolo;
extern const std::array<int, AWM_VARIANT_COUNT> AWMx2;
extern const std::array<int, AWM_VARIANT_COUNT> AWMx3;
extern const std::array<int, AWM_VARIANT_COUNT> AWMx4;
extern const std::array<int, AWM_VARIANT_COUNT> AWMx6;
extern const std::array<int, AWM_VARIANT_COUNT> AWMx8;

}  // namespace skin_tables
