#include "mg3_skins.h"

namespace skin_tables {

const std::array<int, MG3_VARIANT_COUNT> MG3Primary = {0, 1105010008, 1105010019, 1105010026};
const std::array<int, MG3_VARIANT_COUNT> MG3Reddot = {0, 0, 0, 0};
const std::array<int, MG3_VARIANT_COUNT> MG3Holo = {0, 0, 0, 0};
const std::array<int, MG3_VARIANT_COUNT> MG3x2 = {0, 0, 0, 0};
const std::array<int, MG3_VARIANT_COUNT> MG3x3 = {0, 0, 0, 0};
const std::array<int, MG3_VARIANT_COUNT> MG3x4 = {0, 0, 0, 0};
const std::array<int, MG3_VARIANT_COUNT> MG3x6 = {0, 0, 0, 0};

static_assert(MG3Primary.size() == MG3_VARIANT_COUNT, "MG3Primary size mismatch");
static_assert(MG3Reddot.size() == MG3_VARIANT_COUNT, "MG3Reddot size mismatch");
static_assert(MG3Holo.size() == MG3_VARIANT_COUNT, "MG3Holo size mismatch");
static_assert(MG3x2.size() == MG3_VARIANT_COUNT, "MG3x2 size mismatch");
static_assert(MG3x3.size() == MG3_VARIANT_COUNT, "MG3x3 size mismatch");
static_assert(MG3x4.size() == MG3_VARIANT_COUNT, "MG3x4 size mismatch");
static_assert(MG3x6.size() == MG3_VARIANT_COUNT, "MG3x6 size mismatch");

}  // namespace skin_tables
