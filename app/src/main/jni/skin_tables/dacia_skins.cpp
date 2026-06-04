#include "dacia_skins.h"

namespace skin_tables {

const std::array<int, DACIA_VARIANT_COUNT> DaciaSkins = {
    1903001, 1903075, 1903080, 1903076, 1903073, 1903074, 1903072, 1903189,
    1903071, 1903190, 1903079, 1903193, 1903200, 1903201, 1903001, 1903014,
    1903017, 1903035, 1903087, 1903088, 1903089, 1903090, 1903191, 1903192,
    1903197};

static_assert(DaciaSkins.size() == DACIA_VARIANT_COUNT, "DaciaSkins size mismatch");

}  // namespace skin_tables
