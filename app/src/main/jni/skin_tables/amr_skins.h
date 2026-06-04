#pragma once

#include <array>

namespace skin_tables {

constexpr std::size_t AMR_VARIANT_COUNT = 8;

extern const std::array<int, AMR_VARIANT_COUNT> AMRPrimary;
extern const std::array<int, AMR_VARIANT_COUNT> AMRReddot;
extern const std::array<int, AMR_VARIANT_COUNT> AMRHolo;
extern const std::array<int, AMR_VARIANT_COUNT> AMRx2;
extern const std::array<int, AMR_VARIANT_COUNT> AMRx3;
extern const std::array<int, AMR_VARIANT_COUNT> AMRx4;
extern const std::array<int, AMR_VARIANT_COUNT> AMRx6;
extern const std::array<int, AMR_VARIANT_COUNT> AMRx8;

}  // namespace skin_tables
