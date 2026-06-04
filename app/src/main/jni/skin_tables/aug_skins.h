#pragma once

#include <array>

namespace skin_tables {

constexpr std::size_t AUG_VARIANT_COUNT = 7;

extern const std::array<int, AUG_VARIANT_COUNT> AUGPrimary;
extern const std::array<int, AUG_VARIANT_COUNT> AUGReddot;
extern const std::array<int, AUG_VARIANT_COUNT> AUGHolo;
extern const std::array<int, AUG_VARIANT_COUNT> AUGx2;
extern const std::array<int, AUG_VARIANT_COUNT> AUGx3;
extern const std::array<int, AUG_VARIANT_COUNT> AUGx4;
extern const std::array<int, AUG_VARIANT_COUNT> AUGx6;
extern const std::array<int, AUG_VARIANT_COUNT> AUGLazer;
extern const std::array<int, AUG_VARIANT_COUNT> AUGFlash;

}  // namespace skin_tables
