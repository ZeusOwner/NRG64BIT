#include "uaz_skins.h"

namespace skin_tables {

const std::array<int, UAZ_VARIANT_COUNT> UAZSkins = {
    1908001, 1908070, 1908077, 1908078, 1908076, 1908075, 1908067, 1908075,
    1908094, 1908095, 1957001, 1908086, 1908066, 1908189, 1908001};

static_assert(UAZSkins.size() == UAZ_VARIANT_COUNT, "UAZSkins size mismatch");

}  // namespace skin_tables
