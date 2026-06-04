#include "m249_skins.h"

namespace skin_tables {

const std::array<int, M249_VARIANT_COUNT> M249Primary = {0, 1105001034, 1105001048, 1105001054, 1105001062, 1105001069, 1105001075};
const std::array<int, M249_VARIANT_COUNT> M249Stock = {0, 1050010351, 1050010342, 1050010482, 1050010542, 1050010692, 1050010752};

static_assert(M249Primary.size() == M249_VARIANT_COUNT, "M249Primary size mismatch");
static_assert(M249Stock.size() == M249_VARIANT_COUNT, "M249Stock size mismatch");

}  // namespace skin_tables
