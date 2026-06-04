#include "aug_skins.h"

namespace skin_tables {

const std::array<int, AUG_VARIANT_COUNT> AUGPrimary = {101006, 1101006033, 1101006044, 1101006062, 1101006067, 1101006075, 1101006085};
const std::array<int, AUG_VARIANT_COUNT> AUGReddot = {203001, 1010060562, 203001, 203001, 1010060696, 203001, 203001};
const std::array<int, AUG_VARIANT_COUNT> AUGHolo = {203002, 1010060561, 203002, 203002, 1010060695, 203002, 203002};
const std::array<int, AUG_VARIANT_COUNT> AUGx2 = {203003, 1010060554, 203003, 203003, 1010060694, 203003, 203003};
const std::array<int, AUG_VARIANT_COUNT> AUGx3 = {203014, 1010060553, 203014, 203014, 1010060693, 203014, 203014};
const std::array<int, AUG_VARIANT_COUNT> AUGx4 = {203004, 1010060552, 203004, 203004, 1010060692, 203004, 203004};
const std::array<int, AUG_VARIANT_COUNT> AUGx6 = {203015, 1010060551, 203015, 203015, 1010060691, 203015, 203015};
const std::array<int, AUG_VARIANT_COUNT> AUGLazer = {0, 1010060574, 0, 202007, 1010060707, 202007, 202007};
const std::array<int, AUG_VARIANT_COUNT> AUGFlash = {0, 1010060571, 0, 201010, 1010060699, 201010, 201010};

static_assert(AUGPrimary.size() == AUG_VARIANT_COUNT, "AUGPrimary size mismatch");
static_assert(AUGReddot.size() == AUG_VARIANT_COUNT, "AUGReddot size mismatch");
static_assert(AUGHolo.size() == AUG_VARIANT_COUNT, "AUGHolo size mismatch");
static_assert(AUGx2.size() == AUG_VARIANT_COUNT, "AUGx2 size mismatch");
static_assert(AUGx3.size() == AUG_VARIANT_COUNT, "AUGx3 size mismatch");
static_assert(AUGx4.size() == AUG_VARIANT_COUNT, "AUGx4 size mismatch");
static_assert(AUGx6.size() == AUG_VARIANT_COUNT, "AUGx6 size mismatch");
static_assert(AUGLazer.size() == AUG_VARIANT_COUNT, "AUGLazer size mismatch");
static_assert(AUGFlash.size() == AUG_VARIANT_COUNT, "AUGFlash size mismatch");

}  // namespace skin_tables
