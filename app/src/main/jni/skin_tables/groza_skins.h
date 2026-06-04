#pragma once

#include <array>

namespace skin_tables {

constexpr std::size_t GROZA_VARIANT_COUNT = 9;

extern const std::array<int, GROZA_VARIANT_COUNT> GrozaPrimary;
extern const std::array<int, GROZA_VARIANT_COUNT> GrozaMag;
extern const std::array<int, GROZA_VARIANT_COUNT> GrozaSuppressor;
extern const std::array<int, GROZA_VARIANT_COUNT> GrozaReddot;
extern const std::array<int, GROZA_VARIANT_COUNT> GrozaHolo;
extern const std::array<int, GROZA_VARIANT_COUNT> Grozax2;
extern const std::array<int, GROZA_VARIANT_COUNT> Grozax3;
extern const std::array<int, GROZA_VARIANT_COUNT> Grozax4;
extern const std::array<int, GROZA_VARIANT_COUNT> Grozax6;
extern const std::array<int, GROZA_VARIANT_COUNT> GrozaQuickMag;
extern const std::array<int, GROZA_VARIANT_COUNT> GrozaExtendedMag;
extern const std::array<int, GROZA_VARIANT_COUNT> GrozaQuickExtended;

}  // namespace skin_tables
