#include "groza_skins.h"

namespace skin_tables {

const std::array<int, GROZA_VARIANT_COUNT> GrozaPrimary = {101005, 1101005019, 1101005025, 1101005038, 1101005043, 1101005052, 1101005082, 1101005090, 1101005098};
const std::array<int, GROZA_VARIANT_COUNT> GrozaMag = {291005, 1010050191, 1010050251, 1010050381, 1010050431, 1010050521, 1010050821, 1010050981, 1010050981};
const std::array<int, GROZA_VARIANT_COUNT> GrozaSuppressor = {201011, 1010050467, 201011, 201011, 201011, 1010050327, 201011, 201011, 201011};
const std::array<int, GROZA_VARIANT_COUNT> GrozaReddot = {203001, 1010050466, 203001, 203001, 203001, 1010050326, 203001, 203001, 203001};
const std::array<int, GROZA_VARIANT_COUNT> GrozaHolo = {203002, 1010050465, 203002, 203002, 203002, 1010050325, 203002, 203002, 203002};
const std::array<int, GROZA_VARIANT_COUNT> Grozax2 = {203003, 1010050464, 203003, 203003, 203003, 1010050324, 203003, 203003, 203003};
const std::array<int, GROZA_VARIANT_COUNT> Grozax3 = {203014, 1010050463, 203014, 203014, 203014, 1010050323, 203014, 203014, 203014};
const std::array<int, GROZA_VARIANT_COUNT> Grozax4 = {203004, 1010050462, 203004, 203004, 203004, 1010050322, 203004, 203004, 203004};
const std::array<int, GROZA_VARIANT_COUNT> Grozax6 = {203015, 203015, 203015, 203015, 203015, 203015, 203015, 203015, 203015};
const std::array<int, GROZA_VARIANT_COUNT> GrozaQuickMag = {204012, 1010050468, 204012, 204012, 204012, 1010050328, 204012, 204012, 204012};
const std::array<int, GROZA_VARIANT_COUNT> GrozaExtendedMag = {204011, 1010050469, 204011, 204011, 204011, 1010050329, 204011, 204011, 204011};
const std::array<int, GROZA_VARIANT_COUNT> GrozaQuickExtended = {204013, 1010050470, 204013, 204013, 204013, 1010050330, 204013, 204013, 204013};

static_assert(GrozaPrimary.size() == GROZA_VARIANT_COUNT, "GrozaPrimary size mismatch");
static_assert(GrozaMag.size() == GROZA_VARIANT_COUNT, "GrozaMag size mismatch");
static_assert(GrozaSuppressor.size() == GROZA_VARIANT_COUNT, "GrozaSuppressor size mismatch");
static_assert(GrozaReddot.size() == GROZA_VARIANT_COUNT, "GrozaReddot size mismatch");
static_assert(GrozaHolo.size() == GROZA_VARIANT_COUNT, "GrozaHolo size mismatch");
static_assert(Grozax2.size() == GROZA_VARIANT_COUNT, "Grozax2 size mismatch");
static_assert(Grozax3.size() == GROZA_VARIANT_COUNT, "Grozax3 size mismatch");
static_assert(Grozax4.size() == GROZA_VARIANT_COUNT, "Grozax4 size mismatch");
static_assert(Grozax6.size() == GROZA_VARIANT_COUNT, "Grozax6 size mismatch");
static_assert(GrozaQuickMag.size() == GROZA_VARIANT_COUNT, "GrozaQuickMag size mismatch");
static_assert(GrozaExtendedMag.size() == GROZA_VARIANT_COUNT, "GrozaExtendedMag size mismatch");
static_assert(GrozaQuickExtended.size() == GROZA_VARIANT_COUNT, "GrozaQuickExtended size mismatch");

}  // namespace skin_tables
