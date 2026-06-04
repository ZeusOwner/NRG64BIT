#pragma once

#include <array>

namespace skin_tables {

constexpr std::size_t AKM_VARIANT_COUNT = 17;

extern const std::array<int, AKM_VARIANT_COUNT> AKMPrimary;
extern const std::array<int, AKM_VARIANT_COUNT> AKMMag;

extern const std::array<int, AKM_VARIANT_COUNT> AKMFlash;
extern const std::array<int, AKM_VARIANT_COUNT> AKMCompensator;
extern const std::array<int, AKM_VARIANT_COUNT> AKMSuppressor;

extern const std::array<int, AKM_VARIANT_COUNT> AKMReddot;
extern const std::array<int, AKM_VARIANT_COUNT> AKMHolo;
extern const std::array<int, AKM_VARIANT_COUNT> AKMx2;
extern const std::array<int, AKM_VARIANT_COUNT> AKMx3;
extern const std::array<int, AKM_VARIANT_COUNT> AKMx4;
extern const std::array<int, AKM_VARIANT_COUNT> AKMx6;

extern const std::array<int, AKM_VARIANT_COUNT> AKMQuickMag;
extern const std::array<int, AKM_VARIANT_COUNT> AKMExtendedMag;
extern const std::array<int, AKM_VARIANT_COUNT> AKMQuickExtendedMag;

extern const std::array<int, AKM_VARIANT_COUNT> AKMStock;
extern const std::array<int, AKM_VARIANT_COUNT> AKMVertical;
extern const std::array<int, AKM_VARIANT_COUNT> AKMAngle;
extern const std::array<int, AKM_VARIANT_COUNT> AKMLightgrip;
extern const std::array<int, AKM_VARIANT_COUNT> AKMPink;
extern const std::array<int, AKM_VARIANT_COUNT> AKMLazer;
extern const std::array<int, AKM_VARIANT_COUNT> AKMThumb;

}  // namespace skin_tables
