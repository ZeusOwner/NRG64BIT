#include "pan_skins.h"

namespace skin_tables {

const std::array<int, PAN_VARIANT_COUNT> PanPrimary = {
    108004,
    1108004356,
    1108004060,
    1108004061,
    1108004062,
};

static_assert(PanPrimary.size() == PAN_VARIANT_COUNT, "PanPrimary size mismatch");

}  // namespace skin_tables
