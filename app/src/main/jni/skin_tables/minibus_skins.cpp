#include "minibus_skins.h"

namespace skin_tables {

const std::array<int, MINIBUS_VARIANT_COUNT> MiniBusSkins = {
    1904001, 1904005, 1904006, 1904007, 1904008, 1904009, 1904010, 1904011,
    1904012, 1904013, 1904014, 1904015, 1904004};

static_assert(MiniBusSkins.size() == MINIBUS_VARIANT_COUNT, "MiniBusSkins size mismatch");

}  // namespace skin_tables
