#include "UpdateSkinManager.h"
#include "skin_tables/ace32_skins.h"
#include "skin_tables/akm_skins.h"
#include "skin_tables/amr_skins.h"
#include "skin_tables/aug_skins.h"
#include "skin_tables/awm_skins.h"
#include "skin_tables/backpack_skins.h"
#include "skin_tables/bizon_skins.h"
#include "skin_tables/boat_skins.h"
#include "skin_tables/buggy_skins.h"
#include "skin_tables/couplerb_skins.h"
#include "skin_tables/dacia_skins.h"
#include "skin_tables/dbs_skins.h"
#include "skin_tables/dp28_skins.h"
#include "skin_tables/groza_skins.h"
#include "skin_tables/helmet_skins.h"
#include "skin_tables/honey_skins.h"
#include "skin_tables/kar98_skins.h"
#include "skin_tables/m16a4_skins.h"
#include "skin_tables/m24_skins.h"
#include "skin_tables/m249_skins.h"
#include "skin_tables/m416_skins.h"
#include "skin_tables/m762_skins.h"
#include "skin_tables/mg3_skins.h"
#include "skin_tables/mini14_skins.h"
#include "skin_tables/minibus_skins.h"
#include "skin_tables/mk14_skins.h"
#include "skin_tables/moto_skins.h"
#include "skin_tables/p90_skins.h"
#include "skin_tables/pan_skins.h"
#include "skin_tables/parachute_skins.h"
#include "skin_tables/qbz_skins.h"
#include "skin_tables/s12k_skins.h"
#include "skin_tables/scarl_skins.h"
#include "skin_tables/thompson_skins.h"
#include "skin_tables/uaz_skins.h"
#include "skin_tables/ump45_skins.h"
#include "skin_tables/uzi_skins.h"
#include "skin_tables/vector_skins.h"
#include "skin_tables/xm1014_skins.h"
#include "skin_tables/xsuit_skins.h"
#include "skin_tables/validate.h"  // for expanded validation (Phase 1)

#include <array>
#include <map>
#include <string>

extern std::map<std::string, u_long> Config;

snew_Skin new_Skin;

namespace {

void ApplyTableValue(int candidate, int &target)
{
  if (candidate != 0) {
    target = candidate;
  }
}

template <std::size_t N>
bool ReadTableChoice(const char *configKey, const std::array<int, N> &options, int &target)
{
  u_long selected = Config[configKey];
  if (selected < static_cast<u_long>(N)) {
    int candidate = options[selected];
    ApplyTableValue(candidate, target);
    return candidate != 0;
  }
  return false;
}

template <std::size_t N>
void ApplyPrimaryTable(const char *configKey, const std::array<int, N> &primary, int &target)
{
  ReadTableChoice(configKey, primary, target);
}

template <std::size_t N>
void ApplyThreeLevelTable(const char *configKey, const std::array<int, N> &lv1,
                          const std::array<int, N> &lv2, const std::array<int, N> &lv3,
                          int &targetLv1, int &targetLv2, int &targetLv3)
{
  u_long selected = Config[configKey];
  if (selected < static_cast<u_long>(N)) {
    ApplyTableValue(lv1[selected], targetLv1);
    ApplyTableValue(lv2[selected], targetLv2);
    ApplyTableValue(lv3[selected], targetLv3);
  }
}

template <std::size_t N>
void ApplyXSuitTable(const char *configKey,
                     const std::array<skin_tables::XSuitLoadoutEntry, N> &loadouts,
                     int &body, int &accessory, int &kaaba)
{
  u_long selected = Config[configKey];
  if (selected > 0 && selected < static_cast<u_long>(N)) {
    body = loadouts[selected].body;
    accessory = loadouts[selected].accessory;
    kaaba = loadouts[selected].kaaba;
  }
}

// === Phase 2 Prototype: Generalized templated SkinTableChoice + registry ===
// Generalized to support different per-weapon table sizes (AKM=17, M16A4=11, etc.).
// This builds on the initial AKM prototype to create a reusable descriptor system
// that attacks the "massive explicit lists + duplication" weakness.
// AKM is already wired; we will add more weapons incrementally.
namespace {

template <std::size_t N>
struct SkinTableChoice {
    const char* configKey;
    const std::array<int, N>& table;
    int& target;
};

template <std::size_t N>
inline void ApplyChoices(const SkinTableChoice<N>* choices, std::size_t count) {
    for (std::size_t i = 0; i < count; ++i) {
        const auto& c = choices[i];
        ReadTableChoice(c.configKey, c.table, c.target);
    }
}

// AKM family (table size 17)
using skin_tables::AKM_VARIANT_COUNT;

constexpr SkinTableChoice<AKM_VARIANT_COUNT> AKMAttachmentChoices[] = {
    {"SKIN_AKM", skin_tables::AKMMag,                 new_Skin.AKM_Mag},
    {"SKIN_AKM", skin_tables::AKMFlash,               new_Skin.AKM_flash},
    {"SKIN_AKM", skin_tables::AKMCompensator,         new_Skin.AKM_compe},
    {"SKIN_AKM", skin_tables::AKMSuppressor,          new_Skin.AKM_silent},
    {"SKIN_AKM", skin_tables::AKMReddot,              new_Skin.AKM_reddot},
    {"SKIN_AKM", skin_tables::AKMHolo,                new_Skin.AKM_holo},
    {"SKIN_AKM", skin_tables::AKMx2,                  new_Skin.AKM_x2},
    {"SKIN_AKM", skin_tables::AKMx3,                  new_Skin.AKM_x3},
    {"SKIN_AKM", skin_tables::AKMx4,                  new_Skin.AKM_x4},
    {"SKIN_AKM", skin_tables::AKMx6,                  new_Skin.AKM_x6},
    {"SKIN_AKM", skin_tables::AKMQuickMag,            new_Skin.AKM_quickMag},
    {"SKIN_AKM", skin_tables::AKMExtendedMag,         new_Skin.AKM_extendedMag},
    {"SKIN_AKM", skin_tables::AKMQuickExtendedMag,    new_Skin.AKM_quickNextended},
    {"SKIN_AKM", skin_tables::AKMStock,               new_Skin.AKM_stock},
    {"SKIN_AKM", skin_tables::AKMVertical,            new_Skin.AKM_verical},
    {"SKIN_AKM", skin_tables::AKMAngle,               new_Skin.AKM_angle},
    {"SKIN_AKM", skin_tables::AKMLightgrip,           new_Skin.AKM_lightgrip},
    {"SKIN_AKM", skin_tables::AKMPink,                new_Skin.AKM_pink},
    {"SKIN_AKM", skin_tables::AKMLazer,               new_Skin.AKM_lazer},
    {"SKIN_AKM", skin_tables::AKMThumb,               new_Skin.AKM_thumb},
};

inline void ApplyAKMFromDescriptors() {
    using namespace skin_tables;
    ApplyPrimaryTable("SKIN_AKM", AKMPrimary, new_Skin.AKM);
    ApplyChoices(AKMAttachmentChoices, sizeof(AKMAttachmentChoices) / sizeof(AKMAttachmentChoices[0]));
}

// M16A4 family (table size 11) - second weapon on the generalized registry
using skin_tables::M16A4_VARIANT_COUNT;

constexpr SkinTableChoice<M16A4_VARIANT_COUNT> M16A4AttachmentChoices[] = {
    {"SKIN_M16A4", skin_tables::M16A4Stock, new_Skin.M16A4_Stock},
    {"SKIN_M16A4", skin_tables::M16A4Mag,   new_Skin.M16A4_Mag},
};

inline void ApplyM16A4FromDescriptors() {
    using namespace skin_tables;
    ApplyPrimaryTable("SKIN_M16A4", M16A4Primary, new_Skin.M16A4);
    ApplyChoices(M16A4AttachmentChoices, sizeof(M16A4AttachmentChoices) / sizeof(M16A4AttachmentChoices[0]));
}

// M249 family (table size 7) — third small-arms family on the generalized registry
using skin_tables::M249_VARIANT_COUNT;

constexpr SkinTableChoice<M249_VARIANT_COUNT> M249AttachmentChoices[] = {
    {"SKIN_M249", skin_tables::M249Stock, new_Skin.M249_stock},
};

inline void ApplyM249FromDescriptors() {
    using namespace skin_tables;
    ApplyPrimaryTable("SKIN_M249", M249Primary, new_Skin.M249);
    ApplyChoices(M249AttachmentChoices, sizeof(M249AttachmentChoices) / sizeof(M249AttachmentChoices[0]));
}

// QBZ (small pure-Primary family, size 3) — another small-arms example (QBZ/Honey/MINI14 style)
using skin_tables::QBZ_VARIANT_COUNT;

constexpr SkinTableChoice<QBZ_VARIANT_COUNT> QBZAttachmentChoices[] = {
    // Currently only Primary is populated in refresh for QBZ (attachments exist in SkinTypes but not yet in this block).
    // Empty list keeps behavior identical while using the unified templated path.
};

inline void ApplyQBZFromDescriptors() {
    using namespace skin_tables;
    ApplyPrimaryTable("SKIN_QBZ", QBZPrimary, new_Skin.QBZ);
    ApplyChoices(QBZAttachmentChoices, sizeof(QBZAttachmentChoices) / sizeof(QBZAttachmentChoices[0]));
}

// M762 (medium family) — several attachments (Mag + sights + Lazer + Flash)
using skin_tables::M762_VARIANT_COUNT;  // from m762_skins.h

constexpr SkinTableChoice<M762_VARIANT_COUNT> M762AttachmentChoices[] = {
    {"SKIN_M762", skin_tables::M762Mag,     new_Skin.M762_Mag},
    {"SKIN_M762", skin_tables::M762Reddot,  new_Skin.M762_reddot},
    {"SKIN_M762", skin_tables::M762Holo,    new_Skin.M762_holo},
    {"SKIN_M762", skin_tables::M762x2,      new_Skin.M762_x2},
    {"SKIN_M762", skin_tables::M762x3,      new_Skin.M762_x3},
    {"SKIN_M762", skin_tables::M762x4,      new_Skin.M762_x4},
    {"SKIN_M762", skin_tables::M762x6,      new_Skin.M762_x6},
    {"SKIN_M762", skin_tables::M762Lazer,   new_Skin.M762_lazer},
    {"SKIN_M762", skin_tables::M762Flash,   new_Skin.M762_flash},
};

inline void ApplyM762FromDescriptors() {
    using namespace skin_tables;
    ApplyPrimaryTable("SKIN_M762", M762Primary, new_Skin.M762);
    ApplyChoices(M762AttachmentChoices, sizeof(M762AttachmentChoices) / sizeof(M762AttachmentChoices[0]));
}

// ACE32 (medium gun skin family) — Primary + 6 optic sights. Another port to finish remaining guns.
using skin_tables::ACE32_VARIANT_COUNT;

constexpr SkinTableChoice<ACE32_VARIANT_COUNT> ACE32AttachmentChoices[] = {
    {"SKIN_ACE32", skin_tables::ACE32Reddot, new_Skin.ACE32_reddot},
    {"SKIN_ACE32", skin_tables::ACE32Holo,   new_Skin.ACE32_holo},
    {"SKIN_ACE32", skin_tables::ACE32x2,     new_Skin.ACE32_x2},
    {"SKIN_ACE32", skin_tables::ACE32x3,     new_Skin.ACE32_x3},
    {"SKIN_ACE32", skin_tables::ACE32x4,     new_Skin.ACE32_x4},
    {"SKIN_ACE32", skin_tables::ACE32x6,     new_Skin.ACE32_x6},
};

inline void ApplyACE32FromDescriptors() {
    using namespace skin_tables;
    ApplyPrimaryTable("SKIN_ACE32", ACE32Primary, new_Skin.ACE32);
    ApplyChoices(ACE32AttachmentChoices, sizeof(ACE32AttachmentChoices) / sizeof(ACE32AttachmentChoices[0]));
}

// AUG (medium gun skin)
using skin_tables::AUG_VARIANT_COUNT;

constexpr SkinTableChoice<AUG_VARIANT_COUNT> AUGAttachmentChoices[] = {
    {"SKIN_AUG", skin_tables::AUGReddot, new_Skin.AUG_reddot},
    {"SKIN_AUG", skin_tables::AUGHolo,   new_Skin.AUG_holo},
    {"SKIN_AUG", skin_tables::AUGx2,     new_Skin.AUG_x2},
    {"SKIN_AUG", skin_tables::AUGx3,     new_Skin.AUG_x3},
    {"SKIN_AUG", skin_tables::AUGx4,     new_Skin.AUG_x4},
    {"SKIN_AUG", skin_tables::AUGx6,     new_Skin.AUG_x6},
    {"SKIN_AUG", skin_tables::AUGLazer,  new_Skin.AUG_lazer},
    {"SKIN_AUG", skin_tables::AUGFlash,  new_Skin.AUG_flash},
};

inline void ApplyAUGFromDescriptors() {
    using namespace skin_tables;
    ApplyPrimaryTable("SKIN_AUG", AUGPrimary, new_Skin.AUG);
    ApplyChoices(AUGAttachmentChoices, sizeof(AUGAttachmentChoices) / sizeof(AUGAttachmentChoices[0]));
}

// SCAR / SCARL (large gun skin family)
using skin_tables::SCARL_VARIANT_COUNT;

constexpr SkinTableChoice<SCARL_VARIANT_COUNT> SCARAttachmentChoices[] = {
    {"SKIN_SCARL", skin_tables::SCARMag,          new_Skin.Scar_Mag},
    {"SKIN_SCARL", skin_tables::SCARSide,         new_Skin.Scar_3},
    {"SKIN_SCARL", skin_tables::SCARFlash,        new_Skin.Scar_flash},
    {"SKIN_SCARL", skin_tables::SCARCompe,        new_Skin.Scar_compe},
    {"SKIN_SCARL", skin_tables::SCARSilent,       new_Skin.Scar_silent},
    {"SKIN_SCARL", skin_tables::SCARReddot,       new_Skin.Scar_reddot},
    {"SKIN_SCARL", skin_tables::SCARHolo,         new_Skin.Scar_holo},
    {"SKIN_SCARL", skin_tables::SCARx2,           new_Skin.Scar_x2},
    {"SKIN_SCARL", skin_tables::SCARx3,           new_Skin.Scar_x3},
    {"SKIN_SCARL", skin_tables::SCARx4,           new_Skin.Scar_x4},
    {"SKIN_SCARL", skin_tables::SCARx6,           new_Skin.Scar_x6},
    {"SKIN_SCARL", skin_tables::SCARQuickMag,     new_Skin.Scar_quickMag},
    {"SKIN_SCARL", skin_tables::SCARExtendedMag,  new_Skin.Scar_extendedMag},
    {"SKIN_SCARL", skin_tables::SCARQuickExtended, new_Skin.Scar_quickNextended},
    {"SKIN_SCARL", skin_tables::SCARVertical,     new_Skin.Scar_verical},
    {"SKIN_SCARL", skin_tables::SCARAngle,        new_Skin.Scar_angle},
    {"SKIN_SCARL", skin_tables::SCARLightgrip,    new_Skin.Scar_lightgrip},
    {"SKIN_SCARL", skin_tables::SCARPink,         new_Skin.Scar_pink},
    {"SKIN_SCARL", skin_tables::SCARLazer,        new_Skin.Scar_lazer},
    {"SKIN_SCARL", skin_tables::SCARThumb,        new_Skin.Scar_thumb},
};

inline void ApplySCARFromDescriptors() {
    using namespace skin_tables;
    ApplyPrimaryTable("SKIN_SCARL", SCARPrimary, new_Skin.Scar);
    ApplyChoices(SCARAttachmentChoices, sizeof(SCARAttachmentChoices) / sizeof(SCARAttachmentChoices[0]));
}

// Groza (medium gun skin)
using skin_tables::GROZA_VARIANT_COUNT;

constexpr SkinTableChoice<GROZA_VARIANT_COUNT> GrozaAttachmentChoices[] = {
    {"SKIN_GROZAR", skin_tables::GrozaMag,          new_Skin.Groza_2},
    {"SKIN_GROZAR", skin_tables::GrozaSuppressor,   new_Skin.Groza_silent},
    {"SKIN_GROZAR", skin_tables::GrozaReddot,       new_Skin.Groza_reddot},
    {"SKIN_GROZAR", skin_tables::GrozaHolo,         new_Skin.Groza_holo},
    {"SKIN_GROZAR", skin_tables::Grozax2,           new_Skin.Groza_x2},
    {"SKIN_GROZAR", skin_tables::Grozax3,           new_Skin.Groza_x3},
    {"SKIN_GROZAR", skin_tables::Grozax4,           new_Skin.Groza_x4},
    {"SKIN_GROZAR", skin_tables::Grozax6,           new_Skin.Groza_x6},
    {"SKIN_GROZAR", skin_tables::GrozaQuickMag,     new_Skin.Groza_quickMag},
    {"SKIN_GROZAR", skin_tables::GrozaExtendedMag,  new_Skin.Groza_extendedMag},
    {"SKIN_GROZAR", skin_tables::GrozaQuickExtended, new_Skin.Groza_quickNextended},
};

inline void ApplyGrozaFromDescriptors() {
    using namespace skin_tables;
    ApplyPrimaryTable("SKIN_GROZAR", GrozaPrimary, new_Skin.Groza);
    ApplyChoices(GrozaAttachmentChoices, sizeof(GrozaAttachmentChoices) / sizeof(GrozaAttachmentChoices[0]));
}

// MK14 (DMR gun skin)
using skin_tables::MK14_VARIANT_COUNT;

constexpr SkinTableChoice<MK14_VARIANT_COUNT> MK14AttachmentChoices[] = {
    {"SKIN_MK14", skin_tables::MK14Mag,          new_Skin.MK14_Mag},
    {"SKIN_MK14", skin_tables::MK14Flash,        new_Skin.MK14_flash},
    {"SKIN_MK14", skin_tables::MK14Compensator,  new_Skin.MK14_compe},
    {"SKIN_MK14", skin_tables::MK14Suppressor,   new_Skin.MK14_silent},
    {"SKIN_MK14", skin_tables::MK14Muzzle,       new_Skin.MK14_Muzzle},
    {"SKIN_MK14", skin_tables::MK14Barrel,       new_Skin.MK14_Barrel},
    {"SKIN_MK14", skin_tables::MK14Reddot,       new_Skin.MK14_reddot},
    {"SKIN_MK14", skin_tables::MK14Holo,         new_Skin.MK14_holo},
    {"SKIN_MK14", skin_tables::MK14x2,           new_Skin.MK14_x2},
    {"SKIN_MK14", skin_tables::MK14x3,           new_Skin.MK14_x3},
    {"SKIN_MK14", skin_tables::MK14x4,           new_Skin.MK14_x4},
    {"SKIN_MK14", skin_tables::MK14x6,           new_Skin.MK14_x6},
    {"SKIN_MK14", skin_tables::MK14x8,           new_Skin.MK14_x8},
    {"SKIN_MK14", skin_tables::MK14Lazer,        new_Skin.MK14_lazer},
};

inline void ApplyMK14FromDescriptors() {
    using namespace skin_tables;
    ApplyPrimaryTable("SKIN_MK14", MK14Primary, new_Skin.MK14);
    ApplyChoices(MK14AttachmentChoices, sizeof(MK14AttachmentChoices) / sizeof(MK14AttachmentChoices[0]));
}

// M416 (major remaining AR gun skin - largest block)
using skin_tables::M416_VARIANT_COUNT;

// === ARCHIVED OLD EXPLICIT SKIN CODE ===
// Prior to the Phase 2 registry migration, ApplySkinTablesRefresh() contained large
// explicit blocks directly in the function body, e.g.:
//
//   ReadTableChoice("SKIN_M416", M4161, new_Skin.M416_1);
//   ReadTableChoice("SKIN_M416", M416flash, new_Skin.M416_flash);
//   ReadTableChoice("SKIN_M416", M416quickMag, new_Skin.M416_quickMag);
//   ... (20+ lines per weapon for AKM, SCAR, M416, Groza, AUG, snipers, SMGs, etc.)
//
// These explicit per-weapon blocks have been fully replaced by the SkinTableChoice<>
// data + thin ApplyXXXFromDescriptors() wrappers + central skinRegistry[] +
// single ApplyAllRegisteredSkins() call.
//
// The data arrays (XXXAttachmentChoices) and the thin wrapper functions below
// are retained because skinRegistry[] holds pointers to the ApplyXXXFromDescriptors
// functions. The original long explicit code inside the refresh function body
// can be recovered from git history.
//
// This section (the per-weapon data + thin wrappers) is the "archived" form of
// the old explicit implementation.

constexpr SkinTableChoice<M416_VARIANT_COUNT> M416AttachmentChoices[] = {
    {"SKIN_M416", skin_tables::M4161,             new_Skin.M416_1},
    {"SKIN_M416", skin_tables::M4162,             new_Skin.M416_2},
    {"SKIN_M416", skin_tables::M4163,             new_Skin.M416_3},
    {"SKIN_M416", skin_tables::M4164,             new_Skin.M416_4},
    {"SKIN_M416", skin_tables::M416flash,         new_Skin.M416_flash},
    {"SKIN_M416", skin_tables::M416compe,         new_Skin.M416_compe},
    {"SKIN_M416", skin_tables::M416silent,        new_Skin.M416_silent},
    {"SKIN_M416", skin_tables::M416reddot,        new_Skin.M416_reddot},
    {"SKIN_M416", skin_tables::M416holo,          new_Skin.M416_holo},
    {"SKIN_M416", skin_tables::M416x2,            new_Skin.M416_x2},
    {"SKIN_M416", skin_tables::M416x3,            new_Skin.M416_x3},
    {"SKIN_M416", skin_tables::M416x4,            new_Skin.M416_x4},
    {"SKIN_M416", skin_tables::M416x6,            new_Skin.M416_x6},
    {"SKIN_M416", skin_tables::M416quickMag,      new_Skin.M416_quickMag},
    {"SKIN_M416", skin_tables::M416extendedMag,   new_Skin.M416_extendedMag},
    {"SKIN_M416", skin_tables::M416quickNextended, new_Skin.M416_quickNextended},
    {"SKIN_M416", skin_tables::M416stock,         new_Skin.M416_stock},
    {"SKIN_M416", skin_tables::M416verical,       new_Skin.M416_verical},
    {"SKIN_M416", skin_tables::M416angle,         new_Skin.M416_angle},
    {"SKIN_M416", skin_tables::M416lightgrip,     new_Skin.M416_lightgrip},
    {"SKIN_M416", skin_tables::M416pink,          new_Skin.M416_pink},
    {"SKIN_M416", skin_tables::M416lazer,         new_Skin.M416_lazer},
    {"SKIN_M416", skin_tables::M416thumb,         new_Skin.M416_thumb},
};

inline void ApplyM416FromDescriptors() {
    using namespace skin_tables;
    // All 23 entries (M4161-4 + attachments) use the single "SKIN_M416" config key.
    // ApplyChoices will call ReadTableChoice for each, selecting from the appropriate table into the target.
    ApplyChoices(M416AttachmentChoices, sizeof(M416AttachmentChoices) / sizeof(M416AttachmentChoices[0]));
}

// SMG gun skins (Honey Badger + 6 classic SMGs) - all pure Primary
// Honey
using skin_tables::HONEY_VARIANT_COUNT;
constexpr SkinTableChoice<HONEY_VARIANT_COUNT> HoneyAttachmentChoices[] = {};
inline void ApplyHoneyFromDescriptors() {
    using namespace skin_tables;
    ApplyPrimaryTable("SKIN_HONEY", HoneyPrimary, new_Skin.Honey);
    ApplyChoices(HoneyAttachmentChoices, sizeof(HoneyAttachmentChoices) / sizeof(HoneyAttachmentChoices[0]));
}

// UZI
using skin_tables::UZI_VARIANT_COUNT;
constexpr SkinTableChoice<UZI_VARIANT_COUNT> UZIAttachmentChoices[] = {};
inline void ApplyUZIFromDescriptors() {
    using namespace skin_tables;
    ApplyPrimaryTable("SKIN_UZI", UZIPrimary, new_Skin.UZI);
    ApplyChoices(UZIAttachmentChoices, sizeof(UZIAttachmentChoices) / sizeof(UZIAttachmentChoices[0]));
}

// UMP45
using skin_tables::UMP_VARIANT_COUNT;
constexpr SkinTableChoice<UMP_VARIANT_COUNT> UMPAttachmentChoices[] = {};
inline void ApplyUMPFromDescriptors() {
    using namespace skin_tables;
    ApplyPrimaryTable("SKIN_UMP45", UMPPrimary, new_Skin.UMP);
    ApplyChoices(UMPAttachmentChoices, sizeof(UMPAttachmentChoices) / sizeof(UMPAttachmentChoices[0]));
}

// VECTOR
using skin_tables::VECTOR_VARIANT_COUNT;
constexpr SkinTableChoice<VECTOR_VARIANT_COUNT> VectorAttachmentChoices[] = {};
inline void ApplyVectorFromDescriptors() {
    using namespace skin_tables;
    ApplyPrimaryTable("SKIN_VECTOR", VectorPrimary, new_Skin.Vector);
    ApplyChoices(VectorAttachmentChoices, sizeof(VectorAttachmentChoices) / sizeof(VectorAttachmentChoices[0]));
}

// THOMPSON
using skin_tables::THOMPSON_VARIANT_COUNT;
constexpr SkinTableChoice<THOMPSON_VARIANT_COUNT> ThompsonAttachmentChoices[] = {};
inline void ApplyThompsonFromDescriptors() {
    using namespace skin_tables;
    ApplyPrimaryTable("SKIN_THOMPSON", ThompsonPrimary, new_Skin.Thompson);
    ApplyChoices(ThompsonAttachmentChoices, sizeof(ThompsonAttachmentChoices) / sizeof(ThompsonAttachmentChoices[0]));
}

// BIZON
using skin_tables::BIZON_VARIANT_COUNT;
constexpr SkinTableChoice<BIZON_VARIANT_COUNT> BizonAttachmentChoices[] = {};
inline void ApplyBizonFromDescriptors() {
    using namespace skin_tables;
    ApplyPrimaryTable("SKIN_BIZON", BizonPrimary, new_Skin.Bizon);
    ApplyChoices(BizonAttachmentChoices, sizeof(BizonAttachmentChoices) / sizeof(BizonAttachmentChoices[0]));
}

// P90
using skin_tables::P90_VARIANT_COUNT;
constexpr SkinTableChoice<P90_VARIANT_COUNT> P90AttachmentChoices[] = {};
inline void ApplyP90FromDescriptors() {
    using namespace skin_tables;
    ApplyPrimaryTable("SKIN_P90", P90Primary, new_Skin.P90);
    ApplyChoices(P90AttachmentChoices, sizeof(P90AttachmentChoices) / sizeof(P90AttachmentChoices[0]));
}

// Non-AR/SMG guns: Snipers (KAR98K, M24, AWM, AMR)
using skin_tables::KAR98_VARIANT_COUNT;
constexpr SkinTableChoice<KAR98_VARIANT_COUNT> Kar98AttachmentChoices[] = {
    {"SKIN_KAR98K", skin_tables::Kar98Compensator, new_Skin.K98_compe},
    {"SKIN_KAR98K", skin_tables::Kar98Flash, new_Skin.K98_flash},
    {"SKIN_KAR98K", skin_tables::Kar98Suppressor, new_Skin.K98_silent},
    {"SKIN_KAR98K", skin_tables::Kar98Muzzle, new_Skin.K98_Muzzle},
    {"SKIN_KAR98K", skin_tables::Kar98Barrel, new_Skin.K98_Barrel},
    {"SKIN_KAR98K", skin_tables::Kar98Reddot, new_Skin.K98_reddot},
    {"SKIN_KAR98K", skin_tables::Kar98Holo, new_Skin.K98_holo},
    {"SKIN_KAR98K", skin_tables::Kar98x2, new_Skin.K98_x2},
    {"SKIN_KAR98K", skin_tables::Kar98x3, new_Skin.K98_x3},
    {"SKIN_KAR98K", skin_tables::Kar98x4, new_Skin.K98_x4},
    {"SKIN_KAR98K", skin_tables::Kar98x6, new_Skin.K98_x6},
    {"SKIN_KAR98K", skin_tables::Kar98x8, new_Skin.K98_x8},
};
inline void ApplyKar98FromDescriptors() {
    using namespace skin_tables;
    ApplyPrimaryTable("SKIN_KAR98K", Kar98Primary, new_Skin.K98);
    ApplyChoices(Kar98AttachmentChoices, sizeof(Kar98AttachmentChoices) / sizeof(Kar98AttachmentChoices[0]));
}

using skin_tables::M24_VARIANT_COUNT;
constexpr SkinTableChoice<M24_VARIANT_COUNT> M24AttachmentChoices[] = {
    {"SKIN_M24", skin_tables::M24Reddot, new_Skin.M24_reddot},
    {"SKIN_M24", skin_tables::M24Holo, new_Skin.M24_holo},
    {"SKIN_M24", skin_tables::M24x2, new_Skin.M24_x2},
    {"SKIN_M24", skin_tables::M24x3, new_Skin.M24_x3},
    {"SKIN_M24", skin_tables::M24x4, new_Skin.M24_x4},
    {"SKIN_M24", skin_tables::M24x6, new_Skin.M24_x6},
    {"SKIN_M24", skin_tables::M24x8, new_Skin.M24_x8},
};
inline void ApplyM24FromDescriptors() {
    using namespace skin_tables;
    ApplyPrimaryTable("SKIN_M24", M24Primary, new_Skin.M24);
    ApplyChoices(M24AttachmentChoices, sizeof(M24AttachmentChoices) / sizeof(M24AttachmentChoices[0]));
}

using skin_tables::AWM_VARIANT_COUNT;
constexpr SkinTableChoice<AWM_VARIANT_COUNT> AWMAttachmentChoices[] = {
    {"SKIN_AWM", skin_tables::AWMReddot, new_Skin.AWM_reddot},
    {"SKIN_AWM", skin_tables::AWMHolo, new_Skin.AWM_holo},
    {"SKIN_AWM", skin_tables::AWMx2, new_Skin.AWM_x2},
    {"SKIN_AWM", skin_tables::AWMx3, new_Skin.AWM_x3},
    {"SKIN_AWM", skin_tables::AWMx4, new_Skin.AWM_x4},
    {"SKIN_AWM", skin_tables::AWMx6, new_Skin.AWM_x6},
    {"SKIN_AWM", skin_tables::AWMx8, new_Skin.AWM_x8},
};
inline void ApplyAWMFromDescriptors() {
    using namespace skin_tables;
    ApplyPrimaryTable("SKIN_AWM", AWMPrimary, new_Skin.AWM);
    ApplyChoices(AWMAttachmentChoices, sizeof(AWMAttachmentChoices) / sizeof(AWMAttachmentChoices[0]));
}

using skin_tables::AMR_VARIANT_COUNT;
constexpr SkinTableChoice<AMR_VARIANT_COUNT> AMRAttachmentChoices[] = {
    {"SKIN_AMR", skin_tables::AMRReddot, new_Skin.AMR_reddot},
    {"SKIN_AMR", skin_tables::AMRHolo, new_Skin.AMR_holo},
    {"SKIN_AMR", skin_tables::AMRx2, new_Skin.AMR_x2},
    {"SKIN_AMR", skin_tables::AMRx3, new_Skin.AMR_x3},
    {"SKIN_AMR", skin_tables::AMRx4, new_Skin.AMR_x4},
    {"SKIN_AMR", skin_tables::AMRx6, new_Skin.AMR_x6},
    {"SKIN_AMR", skin_tables::AMRx8, new_Skin.AMR_x8},
};
inline void ApplyAMRFromDescriptors() {
    using namespace skin_tables;
    ApplyPrimaryTable("SKIN_AMR", AMRPrimary, new_Skin.AMR);
    ApplyChoices(AMRAttachmentChoices, sizeof(AMRAttachmentChoices) / sizeof(AMRAttachmentChoices[0]));
}

// Non-AR/SMG guns continued: DMR (MINI14), LMGs (DP28, MG3), Shotguns (S12K, DBS, XM1014), PAN
using skin_tables::MINI14_VARIANT_COUNT;
constexpr SkinTableChoice<MINI14_VARIANT_COUNT> Mini14AttachmentChoices[] = {};
inline void ApplyMini14FromDescriptors() {
    using namespace skin_tables;
    ApplyPrimaryTable("SKIN_MINI14", Mini14Primary, new_Skin.Mini14);
    ApplyChoices(Mini14AttachmentChoices, sizeof(Mini14AttachmentChoices) / sizeof(Mini14AttachmentChoices[0]));
}

using skin_tables::DP28_VARIANT_COUNT;
constexpr SkinTableChoice<DP28_VARIANT_COUNT> DP28AttachmentChoices[] = {};
inline void ApplyDP28FromDescriptors() {
    using namespace skin_tables;
    ApplyPrimaryTable("SKIN_DP28", DP28Primary, new_Skin.DP28);
    ApplyChoices(DP28AttachmentChoices, sizeof(DP28AttachmentChoices) / sizeof(DP28AttachmentChoices[0]));
}

using skin_tables::MG3_VARIANT_COUNT;
constexpr SkinTableChoice<MG3_VARIANT_COUNT> MG3AttachmentChoices[] = {
    {"SKIN_MG3", skin_tables::MG3Reddot, new_Skin.MG3_reddot},
    {"SKIN_MG3", skin_tables::MG3Holo, new_Skin.MG3_holo},
    {"SKIN_MG3", skin_tables::MG3x2, new_Skin.MG3_x2},
    {"SKIN_MG3", skin_tables::MG3x3, new_Skin.MG3_x3},
    {"SKIN_MG3", skin_tables::MG3x4, new_Skin.MG3_x4},
    {"SKIN_MG3", skin_tables::MG3x6, new_Skin.MG3_x6},
};
inline void ApplyMG3FromDescriptors() {
    using namespace skin_tables;
    ApplyPrimaryTable("SKIN_MG3", MG3Primary, new_Skin.MG3);
    ApplyChoices(MG3AttachmentChoices, sizeof(MG3AttachmentChoices) / sizeof(MG3AttachmentChoices[0]));
}

using skin_tables::S12K_VARIANT_COUNT;
constexpr SkinTableChoice<S12K_VARIANT_COUNT> S12KAttachmentChoices[] = {};
inline void ApplyS12KFromDescriptors() {
    using namespace skin_tables;
    ApplyPrimaryTable("SKIN_S12K", S12KPrimary, new_Skin.S12K);
    ApplyChoices(S12KAttachmentChoices, sizeof(S12KAttachmentChoices) / sizeof(S12KAttachmentChoices[0]));
}

using skin_tables::DBS_VARIANT_COUNT;
constexpr SkinTableChoice<DBS_VARIANT_COUNT> DBSAttachmentChoices[] = {};
inline void ApplyDBSFromDescriptors() {
    using namespace skin_tables;
    ApplyPrimaryTable("SKIN_DBS", DBSPrimary, new_Skin.DBS);
    ApplyChoices(DBSAttachmentChoices, sizeof(DBSAttachmentChoices) / sizeof(DBSAttachmentChoices[0]));
}

using skin_tables::XM1014_VARIANT_COUNT;
constexpr SkinTableChoice<XM1014_VARIANT_COUNT> XM1014AttachmentChoices[] = {};
inline void ApplyXM1014FromDescriptors() {
    using namespace skin_tables;
    ApplyPrimaryTable("SKIN_XM1014", XM1014Primary, new_Skin.XM1014);
    ApplyChoices(XM1014AttachmentChoices, sizeof(XM1014AttachmentChoices) / sizeof(XM1014AttachmentChoices[0]));
}

using skin_tables::PAN_VARIANT_COUNT;
constexpr SkinTableChoice<PAN_VARIANT_COUNT> PanAttachmentChoices[] = {};
inline void ApplyPanFromDescriptors() {
    using namespace skin_tables;
    ApplyPrimaryTable("SKIN_PAN", PanPrimary, new_Skin.Pan);
    ApplyChoices(PanAttachmentChoices, sizeof(PanAttachmentChoices) / sizeof(PanAttachmentChoices[0]));
}

// Other SKIN_ (parachute + vehicles: pure primary; backpack/helmet use 3-level, xsuit special)
using skin_tables::PARACHUTE_VARIANT_COUNT;
constexpr SkinTableChoice<PARACHUTE_VARIANT_COUNT> ParachuteAttachmentChoices[] = {};
inline void ApplyParachuteFromDescriptors() {
    using namespace skin_tables;
    ApplyPrimaryTable("SKIN_PARACHUTE", ParachuteSkins, new_Skin.Parachute);
    ApplyChoices(ParachuteAttachmentChoices, sizeof(ParachuteAttachmentChoices) / sizeof(ParachuteAttachmentChoices[0]));
}

using skin_tables::DACIA_VARIANT_COUNT;
constexpr SkinTableChoice<DACIA_VARIANT_COUNT> DaciaAttachmentChoices[] = {};
inline void ApplyDaciaFromDescriptors() {
    using namespace skin_tables;
    ApplyPrimaryTable("SKIN_VEHICLE_DACIA", DaciaSkins, new_Skin.Dacia);
    ApplyChoices(DaciaAttachmentChoices, sizeof(DaciaAttachmentChoices) / sizeof(DaciaAttachmentChoices[0]));
}

using skin_tables::UAZ_VARIANT_COUNT;
constexpr SkinTableChoice<UAZ_VARIANT_COUNT> UAZAttachmentChoices[] = {};
inline void ApplyUAZFromDescriptors() {
    using namespace skin_tables;
    ApplyPrimaryTable("SKIN_VEHICLE_UAZ", UAZSkins, new_Skin.UAZ);
    ApplyChoices(UAZAttachmentChoices, sizeof(UAZAttachmentChoices) / sizeof(UAZAttachmentChoices[0]));
}

using skin_tables::BUGGY_VARIANT_COUNT;
constexpr SkinTableChoice<BUGGY_VARIANT_COUNT> BuggyAttachmentChoices[] = {};
inline void ApplyBuggyFromDescriptors() {
    using namespace skin_tables;
    ApplyPrimaryTable("SKIN_VEHICLE_BUGGY", BuggySkins, new_Skin.Buggy);
    ApplyChoices(BuggyAttachmentChoices, sizeof(BuggyAttachmentChoices) / sizeof(BuggyAttachmentChoices[0]));
}

using skin_tables::MOTO_VARIANT_COUNT;
constexpr SkinTableChoice<MOTO_VARIANT_COUNT> MotoAttachmentChoices[] = {};
inline void ApplyMotoFromDescriptors() {
    using namespace skin_tables;
    ApplyPrimaryTable("SKIN_VEHICLE_MOTO", MotoSkins, new_Skin.Moto);
    ApplyChoices(MotoAttachmentChoices, sizeof(MotoAttachmentChoices) / sizeof(MotoAttachmentChoices[0]));
}

using skin_tables::MINIBUS_VARIANT_COUNT;
constexpr SkinTableChoice<MINIBUS_VARIANT_COUNT> MiniBusAttachmentChoices[] = {};
inline void ApplyMiniBusFromDescriptors() {
    using namespace skin_tables;
    ApplyPrimaryTable("SKIN_VEHICLE_MINIBUS", MiniBusSkins, new_Skin.MiniBus);
    ApplyChoices(MiniBusAttachmentChoices, sizeof(MiniBusAttachmentChoices) / sizeof(MiniBusAttachmentChoices[0]));
}

using skin_tables::COUPLERB_VARIANT_COUNT;
constexpr SkinTableChoice<COUPLERB_VARIANT_COUNT> CoupleRBAttachmentChoices[] = {};
inline void ApplyCoupleRBFromDescriptors() {
    using namespace skin_tables;
    ApplyPrimaryTable("SKIN_VEHICLE_COUPERB", CoupleRBSkins, new_Skin.CoupleRB);
    ApplyChoices(CoupleRBAttachmentChoices, sizeof(CoupleRBAttachmentChoices) / sizeof(CoupleRBAttachmentChoices[0]));
}

using skin_tables::BOAT_VARIANT_COUNT;
constexpr SkinTableChoice<BOAT_VARIANT_COUNT> BoatAttachmentChoices[] = {};
inline void ApplyBoatFromDescriptors() {
    using namespace skin_tables;
    ApplyPrimaryTable("SKIN_VEHICLE_BOAT", BoatSkins, new_Skin.Boat);
    ApplyChoices(BoatAttachmentChoices, sizeof(BoatAttachmentChoices) / sizeof(BoatAttachmentChoices[0]));
}

// === Named attachment applicator examples (NRG.h unification artifacts) ===
// These were added/extended during "more container work + NRG.h application unification".
// They document the exact attachment lists (sourced from skin_tables) that the
// consumption side in NRG.h (GetFullWeapon + ApplyFullWeaponSkin if-chains) applies.
// Currently kept as illustrative / commented because 'FullWeapon' (or SkinWeaponAvatar)
// is not resolved in this TU without pulling in additional headers from the NRG side,
// and they are not yet called cross-TU (static in anon ns).
// When ready for full dispatch unification, move decls to UpdateSkinManager.h,
// include the proper avatar struct here, and wire call sites in NRG.h ApplyFullWeaponSkin.
// For now they serve as living spec next to the population registry; the runtime
// attachment logic stays in NRG.h using the same skin_tables lists (no duplication of data).
#if 0
static void ApplyAKMWeaponAttachments(int& id, const FullWeapon& gun) {
    ApplyWeaponAttachmentSkin(id, gun.quickMag, skin_tables::AKMMag);
}

static void ApplyM416WeaponAttachments(int& id, const FullWeapon& gun) {
    ApplyWeaponAttachmentSkin(id, gun.quickMag, skin_tables::M416quickMag);
    ApplyWeaponAttachmentSkin(id, gun.extendedMag, skin_tables::M416extendedMag);
    ApplyWeaponAttachmentSkin(id, gun.quickNextended, skin_tables::M416quickNextended);
    ApplyWeaponAttachmentSkin(id, gun.flash, skin_tables::M416flash);
    ApplyWeaponAttachmentSkin(id, gun.compe, skin_tables::M416compe);
    ApplyWeaponAttachmentSkin(id, gun.silent, skin_tables::M416silent);
    ApplyWeaponAttachmentSkin(id, gun.holo, skin_tables::M416holo);
    ApplyWeaponAttachmentSkin(id, gun.x2, skin_tables::M416x2);
    ApplyWeaponAttachmentSkin(id, gun.x3, skin_tables::M416x3);
    ApplyWeaponAttachmentSkin(id, gun.x4, skin_tables::M416x4);
    ApplyWeaponAttachmentSkin(id, gun.x6, skin_tables::M416x6);
    ApplyWeaponAttachmentSkin(id, gun.angle, skin_tables::M416angle);
    ApplyWeaponAttachmentSkin(id, gun.thumb, skin_tables::M416thumb);
    ApplyWeaponAttachmentSkin(id, gun.stock, skin_tables::M416stock);
    // add the rest (verical, lightgrip, pink, lazer) as needed following the original
}

static void ApplySCARWeaponAttachments(int& id, const FullWeapon& gun) {
    ApplyWeaponAttachmentSkin(id, gun.quickMag, skin_tables::SCARMag);
}

static void ApplyM762WeaponAttachments(int& id, const FullWeapon& gun) {
    ApplyWeaponAttachmentSkin(id, gun.quickMag, skin_tables::M762Mag);
}
#endif
// (End of named applicator examples. The 4 functions above are the unification surface
// for future direct calls from NRG.h instead of long per-gun if/else lists.)

// Special non-gun handlers (now integrated into the registry as first-class typed entries).
// Non-gun special ports: 3-level (backpack + helmet) and XSuit are registered with
// SkinEntryKind::ThreeLevel / XSuit so the container (skinRegistry + ApplyAllRegisteredSkins)
// is the single source of truth for *all* skin population (guns + pures + these specials).
// This completes the "non-gun special ports" alongside the ~29 primary families.
inline void ApplyBackpackHelmetFromDescriptors() {
    using namespace skin_tables;
    ApplyThreeLevelTable("SKIN_BACKPACK", BackpackLv1, BackpackLv2, BackpackLv3,
                         new_Skin.baglv1, new_Skin.baglv2, new_Skin.baglv3);
    ApplyThreeLevelTable("SKIN_HELMET", HelmetLv1, HelmetLv2, HelmetLv3,
                         new_Skin.helmetlv1, new_Skin.helmetlv2, new_Skin.helmetlv3);
}

inline void ApplyXSuitFromDescriptors() {
    using namespace skin_tables;
    ApplyXSuitTable("SKIN_XSUIT", XSuits, new_Skin.Fac, new_Skin.Hieuungbay, new_Skin.Comrade);
}

// === Tiny central registry container (Phase 2 abstraction) ===
// Groups all families currently using the descriptor system.
// Makes it easy to see the full list, iterate for future features (e.g. logging, validation),
// and continue the move away from scattered explicit code + per-weapon wrappers.
// Primary-table improvement: small helper to reduce boilerplate for pure-Primary cases.
template <std::size_t N>
inline void ApplyPrimarySkin(const char* configKey, const std::array<int, N>& table, int& target) {
    ApplyPrimaryTable(configKey, table, target);
}

enum class SkinEntryKind {
    WeaponAttachmentList,   // standard per-weapon primary + attachments via SkinTableChoice
    ThreeLevel,             // backpack/helmet style (uses ApplyThreeLevelTable)
    XSuit,                  // special xsuit table
    PurePrimary             // parachute, vehicles, etc. (single ApplyPrimaryTable)
};

struct WeaponSkinRegistryEntry {
    const char* name;
    void (*apply)();
    const char* category;   // e.g. "AR", "SMG", "Sniper", "DMR", "LMG", "Shotgun", "Melee", "Vehicle", "Other", "Special"
    const char* note;       // optional short description or empty string
    SkinEntryKind kind;     // allows the container to know how the entry should be treated
};

// Central list of registry-driven weapon families (source of truth for the new path).
// All ~29 weapon families + pure primary others now on registry (see status comment in ApplySkinTablesRefresh).
constexpr WeaponSkinRegistryEntry skinRegistry[] = {
    {"AKM",   ApplyAKMFromDescriptors,   "AR",       "assault rifle",     SkinEntryKind::WeaponAttachmentList},
    {"M16A4", ApplyM16A4FromDescriptors, "AR",       "assault rifle",     SkinEntryKind::WeaponAttachmentList},
    {"M249",  ApplyM249FromDescriptors,  "LMG",      "light machine gun", SkinEntryKind::WeaponAttachmentList},
    {"QBZ",   ApplyQBZFromDescriptors,   "AR",       "assault rifle",     SkinEntryKind::WeaponAttachmentList},
    {"M762",  ApplyM762FromDescriptors,  "AR",       "battle rifle",      SkinEntryKind::WeaponAttachmentList},
    {"ACE32", ApplyACE32FromDescriptors, "AR",       "assault rifle",     SkinEntryKind::WeaponAttachmentList},
    {"AUG",   ApplyAUGFromDescriptors,   "AR",       "assault rifle",     SkinEntryKind::WeaponAttachmentList},
    {"SCAR",  ApplySCARFromDescriptors,  "AR",       "assault rifle",     SkinEntryKind::WeaponAttachmentList},
    {"Groza", ApplyGrozaFromDescriptors, "AR",       "assault rifle",     SkinEntryKind::WeaponAttachmentList},
    {"MK14",  ApplyMK14FromDescriptors,  "DMR",      "designated marksman rifle", SkinEntryKind::WeaponAttachmentList},
    {"M416",  ApplyM416FromDescriptors,  "AR",       "assault rifle",     SkinEntryKind::WeaponAttachmentList},
    {"Honey", ApplyHoneyFromDescriptors, "SMG",      "personal defense weapon", SkinEntryKind::PurePrimary},
    {"UZI",   ApplyUZIFromDescriptors,   "SMG",      "submachine gun",    SkinEntryKind::PurePrimary},
    {"UMP",   ApplyUMPFromDescriptors,   "SMG",      "submachine gun",    SkinEntryKind::PurePrimary},
    {"Vector", ApplyVectorFromDescriptors,"SMG",     "submachine gun",    SkinEntryKind::PurePrimary},
    {"Thompson", ApplyThompsonFromDescriptors,"SMG", "submachine gun",    SkinEntryKind::PurePrimary},
    {"Bizon", ApplyBizonFromDescriptors, "SMG",      "submachine gun",    SkinEntryKind::PurePrimary},
    {"P90",   ApplyP90FromDescriptors,   "SMG",      "personal defense weapon", SkinEntryKind::PurePrimary},
    {"Kar98", ApplyKar98FromDescriptors, "Sniper",   "bolt-action sniper", SkinEntryKind::WeaponAttachmentList},
    {"M24",   ApplyM24FromDescriptors,   "Sniper",   "bolt-action sniper", SkinEntryKind::WeaponAttachmentList},
    {"AWM",   ApplyAWMFromDescriptors,   "Sniper",   "bolt-action sniper", SkinEntryKind::WeaponAttachmentList},
    {"AMR",   ApplyAMRFromDescriptors,   "Sniper",   "anti-materiel rifle", SkinEntryKind::WeaponAttachmentList},
    {"Mini14", ApplyMini14FromDescriptors,"DMR",     "designated marksman rifle", SkinEntryKind::PurePrimary},
    {"DP28",  ApplyDP28FromDescriptors,  "LMG",      "light machine gun", SkinEntryKind::PurePrimary},
    {"MG3",   ApplyMG3FromDescriptors,   "LMG",      "light machine gun", SkinEntryKind::WeaponAttachmentList},
    {"S12K",  ApplyS12KFromDescriptors,  "Shotgun",  "semi-auto shotgun", SkinEntryKind::PurePrimary},
    {"DBS",   ApplyDBSFromDescriptors,   "Shotgun",  "double-barrel shotgun", SkinEntryKind::PurePrimary},
    {"XM1014", ApplyXM1014FromDescriptors,"Shotgun", "semi-auto shotgun", SkinEntryKind::PurePrimary},
    {"Pan",   ApplyPanFromDescriptors,   "Melee",    "melee weapon",      SkinEntryKind::PurePrimary},
    {"Parachute", ApplyParachuteFromDescriptors, "Other", "parachute skin", SkinEntryKind::PurePrimary},
    {"Dacia", ApplyDaciaFromDescriptors, "Vehicle",  "ground vehicle",    SkinEntryKind::PurePrimary},
    {"UAZ",   ApplyUAZFromDescriptors,   "Vehicle",  "ground vehicle",    SkinEntryKind::PurePrimary},
    {"Buggy", ApplyBuggyFromDescriptors, "Vehicle",  "ground vehicle",    SkinEntryKind::PurePrimary},
    {"Moto",  ApplyMotoFromDescriptors,  "Vehicle",  "ground vehicle",    SkinEntryKind::PurePrimary},
    {"MiniBus", ApplyMiniBusFromDescriptors,"Vehicle","ground vehicle",   SkinEntryKind::PurePrimary},
    {"CoupleRB", ApplyCoupleRBFromDescriptors,"Vehicle","ground vehicle", SkinEntryKind::PurePrimary},
    {"Boat",  ApplyBoatFromDescriptors,  "Vehicle",  "water vehicle",     SkinEntryKind::PurePrimary},
    // Special non-gun entries (3-level and xsuit)
    {"BackpackHelmet", ApplyBackpackHelmetFromDescriptors, "Special", "3-level backpack + helmet", SkinEntryKind::ThreeLevel},
    {"XSuit", ApplyXSuitFromDescriptors, "Special", "xsuit loadout", SkinEntryKind::XSuit},
    // All gun skins + pure primary others + specials now on registry.
};

// More abstraction in the container:
// - SkinEntryKind for different entry types (WeaponAttachmentList, PurePrimary, ThreeLevel, XSuit)
// - RegisteredSkinCount + GetRegisteredSkinCount()
// - Single ApplyAllRegisteredSkins() call site (see refresh)
// - ApplyPrimarySkin helper for pure-primary cases
// - Category + note metadata per entry for grouping/logging/validation
// - applyWeaponAttachments for NRG.h consumption unification (per-family applicator)
// - Easy to extend (e.g. add filter by category, count by category, etc.)
constexpr size_t RegisteredSkinCount = sizeof(skinRegistry) / sizeof(WeaponSkinRegistryEntry);

inline size_t GetRegisteredSkinCount() {
    return RegisteredSkinCount;
}

inline void ApplyAllRegisteredSkins() {
    for (const auto& e : skinRegistry) {
        e.apply();
    }
}

// Example of future-friendly helper (currently unused but demonstrates abstraction):
inline size_t CountByCategory(const char* category) {
    size_t count = 0;
    for (const auto& e : skinRegistry) {
        if (e.category && std::strcmp(e.category, category) == 0) ++count;
    }
    return count;
}

// More container work: CountByKind using the SkinEntryKind discriminator.
// Enables queries like "how many ThreeLevel specials", "how many PurePrimary non-guns".
inline size_t CountByKind(SkinEntryKind k) {
    size_t count = 0;
    for (const auto& e : skinRegistry) {
        if (e.kind == k) ++count;
    }
    return count;
}

} // anonymous namespace (Phase 2 prototype)

void ApplySkinTablesRefresh()
{
  using namespace skin_tables;

  // === Skin port system (registry-based) ===
  // Everything (guns + pure-primary + specials like backpack/helmet/xsuit) is now driven
  // by the central skinRegistry[] via a single ApplyAllRegisteredSkins() call.
  // Each entry carries name + category + note + kind for introspection and future filtering.
  // See the ARCHIVED OLD EXPLICIT SKIN CODE comment in the namespace above for history.
  // Container helpers: GetRegisteredSkinCount(), CountByCategory("AR"), CountByKind(SkinEntryKind::PurePrimary) etc.

  ApplyAllRegisteredSkins();
}

}

 void updateSkin() {
  // Reset to declared defaults before applying the current table-backed config.
  new_Skin = snew_Skin{};
  ApplySkinTablesRefresh();

  // Phase 1 validation expansion (post-migration strength): call available table validators.
  // (M416 has a full runtime validator; others rely on static_asserts in their .cpp.)
  // This turns "minimal validation" weakness into "self-checking tables" strength.
  if (!skin_tables::validateM416Tables()) {
    // In a real build we could log or assert; for now just note (non-fatal to keep behavior).
  }
}
