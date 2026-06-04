#include "ace32_skins.h"

namespace skin_tables {

const std::array<int, ACE32_VARIANT_COUNT> ACE32Primary = {101102, 1101102007, 1101102017, 1101102025, 1101102032, 1101102041, 1101102049};
const std::array<int, ACE32_VARIANT_COUNT> ACE32Reddot = {0, 1010081396, 1010081396, 1010081396, 0, 0, 0};
const std::array<int, ACE32_VARIANT_COUNT> ACE32Holo = {0, 1010081395, 1010081395, 1010081395, 0, 0, 0};
const std::array<int, ACE32_VARIANT_COUNT> ACE32x2 = {0, 1010081394, 1010081394, 1010081394, 0, 0, 0};
const std::array<int, ACE32_VARIANT_COUNT> ACE32x3 = {0, 1010081393, 1010081393, 1010081393, 0, 0, 0};
const std::array<int, ACE32_VARIANT_COUNT> ACE32x4 = {0, 1010081392, 1010081392, 1010081392, 0, 0, 0};
const std::array<int, ACE32_VARIANT_COUNT> ACE32x6 = {0, 1010081391, 1010081391, 1010081391, 0, 0, 0};

static_assert(ACE32Primary.size() == ACE32_VARIANT_COUNT, "ACE32Primary size mismatch");
static_assert(ACE32Reddot.size() == ACE32_VARIANT_COUNT, "ACE32Reddot size mismatch");
static_assert(ACE32Holo.size() == ACE32_VARIANT_COUNT, "ACE32Holo size mismatch");
static_assert(ACE32x2.size() == ACE32_VARIANT_COUNT, "ACE32x2 size mismatch");
static_assert(ACE32x3.size() == ACE32_VARIANT_COUNT, "ACE32x3 size mismatch");
static_assert(ACE32x4.size() == ACE32_VARIANT_COUNT, "ACE32x4 size mismatch");
static_assert(ACE32x6.size() == ACE32_VARIANT_COUNT, "ACE32x6 size mismatch");

}  // namespace skin_tables
