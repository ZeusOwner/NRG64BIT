#include "xm1014_skins.h"

namespace skin_tables {

const std::array<int, XM1014_VARIANT_COUNT> XM1014Primary = {
    104101,
    1104101001,
};

static_assert(XM1014Primary.size() == XM1014_VARIANT_COUNT, "XM1014Primary size mismatch");

}  // namespace skin_tables
