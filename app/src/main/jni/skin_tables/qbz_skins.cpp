#include "qbz_skins.h"

namespace skin_tables {

const std::array<int, QBZ_VARIANT_COUNT> QBZPrimary = {
    101007,
    1101007046,
    1101007062,
};

static_assert(QBZPrimary.size() == QBZ_VARIANT_COUNT, "QBZPrimary size mismatch");

}  // namespace skin_tables
