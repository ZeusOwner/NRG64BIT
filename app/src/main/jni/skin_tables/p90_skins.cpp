#include "p90_skins.h"

namespace skin_tables {

const std::array<int, P90_VARIANT_COUNT> P90Primary = {
    102105,
    1102105012,
    1102105018,
    1102105028,
};

static_assert(P90Primary.size() == P90_VARIANT_COUNT, "P90Primary size mismatch");

}  // namespace skin_tables
