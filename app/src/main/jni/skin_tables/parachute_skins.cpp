#include "parachute_skins.h"

namespace skin_tables {

const std::array<int, PARACHUTE_VARIANT_COUNT> ParachuteSkins = {
    703001, 1401619, 1401625, 1401624, 1401836, 1401833, 1401287, 1401282,
    1401385, 1401549, 1401336, 1401335, 1401629, 1401628, 1401615, 1401613};

static_assert(ParachuteSkins.size() == PARACHUTE_VARIANT_COUNT, "ParachuteSkins size mismatch");

}  // namespace skin_tables
