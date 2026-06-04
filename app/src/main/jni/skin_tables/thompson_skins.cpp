#include "thompson_skins.h"

namespace skin_tables {

const std::array<int, THOMPSON_VARIANT_COUNT> ThompsonPrimary = {
    102004,       // Default
    1102004018,   // Candy Cane
    1102004034    // Steampunk
};

static_assert(ThompsonPrimary.size() == THOMPSON_VARIANT_COUNT, "ThompsonPrimary size mismatch");

}  // namespace skin_tables
