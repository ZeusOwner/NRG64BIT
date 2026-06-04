#include "boat_skins.h"

namespace skin_tables {

const std::array<int, BOAT_VARIANT_COUNT> BoatSkins = {
    1911001, 1911013, 1911003, 1911004, 1911005, 1911006, 1911007, 1911008,
    1911009, 1911010, 1911011, 1911012};

static_assert(BoatSkins.size() == BOAT_VARIANT_COUNT, "BoatSkins size mismatch");

}  // namespace skin_tables
