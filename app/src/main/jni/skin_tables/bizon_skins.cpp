#include "bizon_skins.h"

namespace skin_tables {

const std::array<int, BIZON_VARIANT_COUNT> BizonPrimary = {
    102005,
    1102005057,
};

static_assert(BizonPrimary.size() == BIZON_VARIANT_COUNT, "BizonPrimary size mismatch");

}  // namespace skin_tables
