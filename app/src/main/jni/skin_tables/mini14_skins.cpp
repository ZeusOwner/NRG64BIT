#include "mini14_skins.h"

namespace skin_tables {

const std::array<int, MINI14_VARIANT_COUNT> Mini14Primary = {0, 1103006030, 1103006046, 1103006058, 1103006063};

static_assert(Mini14Primary.size() == MINI14_VARIANT_COUNT, "Mini14Primary size mismatch");

}  // namespace skin_tables
