#pragma once

#include <array>

namespace skin_tables {

struct XSuitLoadoutEntry {
	int body;
	int accessory;
	int kaaba;
};

constexpr std::size_t XSUIT_VARIANT_COUNT = 14;

extern const std::array<XSuitLoadoutEntry, XSUIT_VARIANT_COUNT> XSuits;

}  // namespace skin_tables
