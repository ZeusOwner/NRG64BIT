#include "dp28_skins.h"

namespace skin_tables {

const std::array<int, DP28_VARIANT_COUNT> DP28Primary = {0, 1105002018, 1105002035, 1105002058, 1105002063, 1105002071, 1105002076, 1105002083, 1105002091};

static_assert(DP28Primary.size() == DP28_VARIANT_COUNT, "DP28Primary size mismatch");

}  // namespace skin_tables
