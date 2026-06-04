#include "mk14_skins.h"

namespace skin_tables {

const std::array<int, MK14_VARIANT_COUNT> MK14Primary = {
    103007,       // Default Mk14
    1103007020,   // Gilded Galaxy (Lv. 5)
    1103007028,   // Drakreign (Lv. 8)
    1103007038,   // Cuddly Nailoong (Lv. 5)
    1103007043,   // Gift Parcel (Lv. 5)
    1103007029,   // Phoenix Song
    1103007030,   // Vital Source
    1103007032,   // NeoViolet Fighter
    1103007033,   // Brasswork Sparks
    1103007015,   // C2S4 season skin
    1103007010,   // Season 11
    1103007011    // Metal Medley
};

// MK14 shares universal attachments; use consistent defaults until themed IDs are confirmed.
const std::array<int, MK14_VARIANT_COUNT> MK14Mag = {293007, 293007, 293007, 293007, 293007, 293007, 293007, 293007, 293007, 293007, 293007, 293007};
const std::array<int, MK14_VARIANT_COUNT> MK14Flash = {201005, 201005, 201005, 201005, 201005, 201005, 201005, 201005, 201005, 201005, 201005, 201005};
const std::array<int, MK14_VARIANT_COUNT> MK14Compensator = {201003, 201003, 201003, 201003, 201003, 201003, 201003, 201003, 201003, 201003, 201003, 201003};
const std::array<int, MK14_VARIANT_COUNT> MK14Suppressor = {201007, 201007, 201007, 201007, 201007, 201007, 201007, 201007, 201007, 201007, 201007, 201007};
const std::array<int, MK14_VARIANT_COUNT> MK14Muzzle = {201052, 201052, 201052, 201052, 201052, 201052, 201052, 201052, 201052, 201052, 201052, 201052};
const std::array<int, MK14_VARIANT_COUNT> MK14Barrel = {201055, 201055, 201055, 201055, 201055, 201055, 201055, 201055, 201055, 201055, 201055, 201055};
const std::array<int, MK14_VARIANT_COUNT> MK14Reddot = {203001, 203001, 203001, 203001, 203001, 203001, 203001, 203001, 203001, 203001, 203001, 203001};
const std::array<int, MK14_VARIANT_COUNT> MK14Holo = {203002, 203002, 203002, 203002, 203002, 203002, 203002, 203002, 203002, 203002, 203002, 203002};
const std::array<int, MK14_VARIANT_COUNT> MK14x2 = {203003, 203003, 203003, 203003, 203003, 203003, 203003, 203003, 203003, 203003, 203003, 203003};
const std::array<int, MK14_VARIANT_COUNT> MK14x3 = {203014, 203014, 203014, 203014, 203014, 203014, 203014, 203014, 203014, 203014, 203014, 203014};
const std::array<int, MK14_VARIANT_COUNT> MK14x4 = {203004, 203004, 203004, 203004, 203004, 203004, 203004, 203004, 203004, 203004, 203004, 203004};
const std::array<int, MK14_VARIANT_COUNT> MK14x6 = {203015, 203015, 203015, 203015, 203015, 203015, 203015, 203015, 203015, 203015, 203015, 203015};
const std::array<int, MK14_VARIANT_COUNT> MK14x8 = {203005, 203005, 203005, 203005, 203005, 203005, 203005, 203005, 203005, 203005, 203005, 203005};
const std::array<int, MK14_VARIANT_COUNT> MK14Lazer = {202007, 202007, 202007, 202007, 202007, 202007, 202007, 202007, 202007, 202007, 202007, 202007};

static_assert(MK14Primary.size() == MK14_VARIANT_COUNT, "MK14Primary size mismatch");
static_assert(MK14Mag.size() == MK14_VARIANT_COUNT, "MK14Mag size mismatch");
static_assert(MK14Flash.size() == MK14_VARIANT_COUNT, "MK14Flash size mismatch");
static_assert(MK14Compensator.size() == MK14_VARIANT_COUNT, "MK14Compensator size mismatch");
static_assert(MK14Suppressor.size() == MK14_VARIANT_COUNT, "MK14Suppressor size mismatch");
static_assert(MK14Muzzle.size() == MK14_VARIANT_COUNT, "MK14Muzzle size mismatch");
static_assert(MK14Barrel.size() == MK14_VARIANT_COUNT, "MK14Barrel size mismatch");
static_assert(MK14Reddot.size() == MK14_VARIANT_COUNT, "MK14Reddot size mismatch");
static_assert(MK14Holo.size() == MK14_VARIANT_COUNT, "MK14Holo size mismatch");
static_assert(MK14x2.size() == MK14_VARIANT_COUNT, "MK14x2 size mismatch");
static_assert(MK14x3.size() == MK14_VARIANT_COUNT, "MK14x3 size mismatch");
static_assert(MK14x4.size() == MK14_VARIANT_COUNT, "MK14x4 size mismatch");
static_assert(MK14x6.size() == MK14_VARIANT_COUNT, "MK14x6 size mismatch");
static_assert(MK14x8.size() == MK14_VARIANT_COUNT, "MK14x8 size mismatch");
static_assert(MK14Lazer.size() == MK14_VARIANT_COUNT, "MK14Lazer size mismatch");

}  // namespace skin_tables
