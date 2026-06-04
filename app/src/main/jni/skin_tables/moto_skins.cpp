#include "moto_skins.h"

namespace skin_tables {

const std::array<int, MOTO_VARIANT_COUNT> MotoSkins = {
    1901001, 1901073, 1901074, 1901075, 1901047, 1901085,
    1901076, 1901027, 1901018, 1901085, 1901070};

static_assert(MotoSkins.size() == MOTO_VARIANT_COUNT, "MotoSkins size mismatch");

}  // namespace skin_tables
