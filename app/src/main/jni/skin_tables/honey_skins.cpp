#include "honey_skins.h"

namespace skin_tables {

const std::array<int, HONEY_VARIANT_COUNT> HoneyPrimary = {
    101012,
    1101012009,
};

static_assert(HoneyPrimary.size() == HONEY_VARIANT_COUNT, "HoneyPrimary size mismatch");

}  // namespace skin_tables
