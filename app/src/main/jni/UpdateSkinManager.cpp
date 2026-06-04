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

void ApplySkinTablesRefresh()
{
  using namespace skin_tables;

  ReadTableChoice("SKIN_M416", M4161, new_Skin.M416_1);
  ReadTableChoice("SKIN_M416", M4162, new_Skin.M416_2);
  ReadTableChoice("SKIN_M416", M4163, new_Skin.M416_3);
  ReadTableChoice("SKIN_M416", M4164, new_Skin.M416_4);
  ReadTableChoice("SKIN_M416", M416flash, new_Skin.M416_flash);
  ReadTableChoice("SKIN_M416", M416compe, new_Skin.M416_compe);
  ReadTableChoice("SKIN_M416", M416silent, new_Skin.M416_silent);
  ReadTableChoice("SKIN_M416", M416reddot, new_Skin.M416_reddot);
  ReadTableChoice("SKIN_M416", M416holo, new_Skin.M416_holo);
  ReadTableChoice("SKIN_M416", M416x2, new_Skin.M416_x2);
  ReadTableChoice("SKIN_M416", M416x3, new_Skin.M416_x3);
  ReadTableChoice("SKIN_M416", M416x4, new_Skin.M416_x4);
  ReadTableChoice("SKIN_M416", M416x6, new_Skin.M416_x6);
  ReadTableChoice("SKIN_M416", M416quickMag, new_Skin.M416_quickMag);
  ReadTableChoice("SKIN_M416", M416extendedMag, new_Skin.M416_extendedMag);
  ReadTableChoice("SKIN_M416", M416quickNextended, new_Skin.M416_quickNextended);
  ReadTableChoice("SKIN_M416", M416stock, new_Skin.M416_stock);
  ReadTableChoice("SKIN_M416", M416verical, new_Skin.M416_verical);
  ReadTableChoice("SKIN_M416", M416angle, new_Skin.M416_angle);
  ReadTableChoice("SKIN_M416", M416lightgrip, new_Skin.M416_lightgrip);
  ReadTableChoice("SKIN_M416", M416pink, new_Skin.M416_pink);
  ReadTableChoice("SKIN_M416", M416lazer, new_Skin.M416_lazer);
  ReadTableChoice("SKIN_M416", M416thumb, new_Skin.M416_thumb);

  ApplyPrimaryTable("SKIN_AKM", AKMPrimary, new_Skin.AKM);
  ReadTableChoice("SKIN_AKM", AKMMag, new_Skin.AKM_Mag);
  ReadTableChoice("SKIN_AKM", AKMFlash, new_Skin.AKM_flash);
  ReadTableChoice("SKIN_AKM", AKMCompensator, new_Skin.AKM_compe);
  ReadTableChoice("SKIN_AKM", AKMSuppressor, new_Skin.AKM_silent);
  ReadTableChoice("SKIN_AKM", AKMReddot, new_Skin.AKM_reddot);
  ReadTableChoice("SKIN_AKM", AKMHolo, new_Skin.AKM_holo);
  ReadTableChoice("SKIN_AKM", AKMx2, new_Skin.AKM_x2);
  ReadTableChoice("SKIN_AKM", AKMx3, new_Skin.AKM_x3);
  ReadTableChoice("SKIN_AKM", AKMx4, new_Skin.AKM_x4);
  ReadTableChoice("SKIN_AKM", AKMx6, new_Skin.AKM_x6);
  ReadTableChoice("SKIN_AKM", AKMQuickMag, new_Skin.AKM_quickMag);
  ReadTableChoice("SKIN_AKM", AKMExtendedMag, new_Skin.AKM_extendedMag);
  ReadTableChoice("SKIN_AKM", AKMQuickExtendedMag, new_Skin.AKM_quickNextended);
  ReadTableChoice("SKIN_AKM", AKMStock, new_Skin.AKM_stock);
  ReadTableChoice("SKIN_AKM", AKMVertical, new_Skin.AKM_verical);
  ReadTableChoice("SKIN_AKM", AKMAngle, new_Skin.AKM_angle);
  ReadTableChoice("SKIN_AKM", AKMLightgrip, new_Skin.AKM_lightgrip);
  ReadTableChoice("SKIN_AKM", AKMPink, new_Skin.AKM_pink);
  ReadTableChoice("SKIN_AKM", AKMLazer, new_Skin.AKM_lazer);
  ReadTableChoice("SKIN_AKM", AKMThumb, new_Skin.AKM_thumb);

  ApplyPrimaryTable("SKIN_SCARL", SCARPrimary, new_Skin.Scar);
  ReadTableChoice("SKIN_SCARL", SCARMag, new_Skin.Scar_Mag);
  ReadTableChoice("SKIN_SCARL", SCARSide, new_Skin.Scar_3);
  ReadTableChoice("SKIN_SCARL", SCARFlash, new_Skin.Scar_flash);
  ReadTableChoice("SKIN_SCARL", SCARCompe, new_Skin.Scar_compe);
  ReadTableChoice("SKIN_SCARL", SCARSilent, new_Skin.Scar_silent);
  ReadTableChoice("SKIN_SCARL", SCARReddot, new_Skin.Scar_reddot);
  ReadTableChoice("SKIN_SCARL", SCARHolo, new_Skin.Scar_holo);
  ReadTableChoice("SKIN_SCARL", SCARx2, new_Skin.Scar_x2);
  ReadTableChoice("SKIN_SCARL", SCARx3, new_Skin.Scar_x3);
  ReadTableChoice("SKIN_SCARL", SCARx4, new_Skin.Scar_x4);
  ReadTableChoice("SKIN_SCARL", SCARx6, new_Skin.Scar_x6);
  ReadTableChoice("SKIN_SCARL", SCARQuickMag, new_Skin.Scar_quickMag);
  ReadTableChoice("SKIN_SCARL", SCARExtendedMag, new_Skin.Scar_extendedMag);
  ReadTableChoice("SKIN_SCARL", SCARQuickExtended, new_Skin.Scar_quickNextended);
  ReadTableChoice("SKIN_SCARL", SCARVertical, new_Skin.Scar_verical);
  ReadTableChoice("SKIN_SCARL", SCARAngle, new_Skin.Scar_angle);
  ReadTableChoice("SKIN_SCARL", SCARLightgrip, new_Skin.Scar_lightgrip);
  ReadTableChoice("SKIN_SCARL", SCARPink, new_Skin.Scar_pink);
  ReadTableChoice("SKIN_SCARL", SCARLazer, new_Skin.Scar_lazer);
  ReadTableChoice("SKIN_SCARL", SCARThumb, new_Skin.Scar_thumb);

  ApplyPrimaryTable("SKIN_M762", M762Primary, new_Skin.M762);
  ReadTableChoice("SKIN_M762", M762Mag, new_Skin.M762_Mag);
  ReadTableChoice("SKIN_M762", M762Reddot, new_Skin.M762_reddot);
  ReadTableChoice("SKIN_M762", M762Holo, new_Skin.M762_holo);
  ReadTableChoice("SKIN_M762", M762x2, new_Skin.M762_x2);
  ReadTableChoice("SKIN_M762", M762x3, new_Skin.M762_x3);
  ReadTableChoice("SKIN_M762", M762x4, new_Skin.M762_x4);
  ReadTableChoice("SKIN_M762", M762x6, new_Skin.M762_x6);
  ReadTableChoice("SKIN_M762", M762Lazer, new_Skin.M762_lazer);
  ReadTableChoice("SKIN_M762", M762Flash, new_Skin.M762_flash);

  ApplyPrimaryTable("SKIN_M16A4", M16A4Primary, new_Skin.M16A4);
  ReadTableChoice("SKIN_M16A4", M16A4Stock, new_Skin.M16A4_Stock);
  ReadTableChoice("SKIN_M16A4", M16A4Mag, new_Skin.M16A4_Mag);

  ApplyPrimaryTable("SKIN_GROZAR", GrozaPrimary, new_Skin.Groza);
  ReadTableChoice("SKIN_GROZAR", GrozaMag, new_Skin.Groza_2);
  ReadTableChoice("SKIN_GROZAR", GrozaSuppressor, new_Skin.Groza_silent);
  ReadTableChoice("SKIN_GROZAR", GrozaReddot, new_Skin.Groza_reddot);
  ReadTableChoice("SKIN_GROZAR", GrozaHolo, new_Skin.Groza_holo);
  ReadTableChoice("SKIN_GROZAR", Grozax2, new_Skin.Groza_x2);
  ReadTableChoice("SKIN_GROZAR", Grozax3, new_Skin.Groza_x3);
  ReadTableChoice("SKIN_GROZAR", Grozax4, new_Skin.Groza_x4);
  ReadTableChoice("SKIN_GROZAR", Grozax6, new_Skin.Groza_x6);
  ReadTableChoice("SKIN_GROZAR", GrozaQuickMag, new_Skin.Groza_quickMag);
  ReadTableChoice("SKIN_GROZAR", GrozaExtendedMag, new_Skin.Groza_extendedMag);
  ReadTableChoice("SKIN_GROZAR", GrozaQuickExtended, new_Skin.Groza_quickNextended);

  ApplyPrimaryTable("SKIN_AUG", AUGPrimary, new_Skin.AUG);
  ReadTableChoice("SKIN_AUG", AUGReddot, new_Skin.AUG_reddot);
  ReadTableChoice("SKIN_AUG", AUGHolo, new_Skin.AUG_holo);
  ReadTableChoice("SKIN_AUG", AUGx2, new_Skin.AUG_x2);
  ReadTableChoice("SKIN_AUG", AUGx3, new_Skin.AUG_x3);
  ReadTableChoice("SKIN_AUG", AUGx4, new_Skin.AUG_x4);
  ReadTableChoice("SKIN_AUG", AUGx6, new_Skin.AUG_x6);
  ReadTableChoice("SKIN_AUG", AUGLazer, new_Skin.AUG_lazer);
  ReadTableChoice("SKIN_AUG", AUGFlash, new_Skin.AUG_flash);

  ApplyPrimaryTable("SKIN_ACE32", ACE32Primary, new_Skin.ACE32);
  ReadTableChoice("SKIN_ACE32", ACE32Reddot, new_Skin.ACE32_reddot);
  ReadTableChoice("SKIN_ACE32", ACE32Holo, new_Skin.ACE32_holo);
  ReadTableChoice("SKIN_ACE32", ACE32x2, new_Skin.ACE32_x2);
  ReadTableChoice("SKIN_ACE32", ACE32x3, new_Skin.ACE32_x3);
  ReadTableChoice("SKIN_ACE32", ACE32x4, new_Skin.ACE32_x4);
  ReadTableChoice("SKIN_ACE32", ACE32x6, new_Skin.ACE32_x6);
  ApplyPrimaryTable("SKIN_QBZ", QBZPrimary, new_Skin.QBZ);
  ApplyPrimaryTable("SKIN_HONEY", HoneyPrimary, new_Skin.Honey);

  ApplyPrimaryTable("SKIN_MK14", MK14Primary, new_Skin.MK14);
  ReadTableChoice("SKIN_MK14", MK14Mag, new_Skin.MK14_Mag);
  ReadTableChoice("SKIN_MK14", MK14Flash, new_Skin.MK14_flash);
  ReadTableChoice("SKIN_MK14", MK14Compensator, new_Skin.MK14_compe);
  ReadTableChoice("SKIN_MK14", MK14Suppressor, new_Skin.MK14_silent);
  ReadTableChoice("SKIN_MK14", MK14Muzzle, new_Skin.MK14_Muzzle);
  ReadTableChoice("SKIN_MK14", MK14Barrel, new_Skin.MK14_Barrel);
  ReadTableChoice("SKIN_MK14", MK14Reddot, new_Skin.MK14_reddot);
  ReadTableChoice("SKIN_MK14", MK14Holo, new_Skin.MK14_holo);
  ReadTableChoice("SKIN_MK14", MK14x2, new_Skin.MK14_x2);
  ReadTableChoice("SKIN_MK14", MK14x3, new_Skin.MK14_x3);
  ReadTableChoice("SKIN_MK14", MK14x4, new_Skin.MK14_x4);
  ReadTableChoice("SKIN_MK14", MK14x6, new_Skin.MK14_x6);
  ReadTableChoice("SKIN_MK14", MK14x8, new_Skin.MK14_x8);
  ReadTableChoice("SKIN_MK14", MK14Lazer, new_Skin.MK14_lazer);

  ApplyPrimaryTable("SKIN_KAR98K", Kar98Primary, new_Skin.K98);
  ReadTableChoice("SKIN_KAR98K", Kar98Compensator, new_Skin.K98_compe);
  ReadTableChoice("SKIN_KAR98K", Kar98Flash, new_Skin.K98_flash);
  ReadTableChoice("SKIN_KAR98K", Kar98Suppressor, new_Skin.K98_silent);
  ReadTableChoice("SKIN_KAR98K", Kar98Muzzle, new_Skin.K98_Muzzle);
  ReadTableChoice("SKIN_KAR98K", Kar98Barrel, new_Skin.K98_Barrel);
  ReadTableChoice("SKIN_KAR98K", Kar98Reddot, new_Skin.K98_reddot);
  ReadTableChoice("SKIN_KAR98K", Kar98Holo, new_Skin.K98_holo);
  ReadTableChoice("SKIN_KAR98K", Kar98x2, new_Skin.K98_x2);
  ReadTableChoice("SKIN_KAR98K", Kar98x3, new_Skin.K98_x3);
  ReadTableChoice("SKIN_KAR98K", Kar98x4, new_Skin.K98_x4);
  ReadTableChoice("SKIN_KAR98K", Kar98x6, new_Skin.K98_x6);
  ReadTableChoice("SKIN_KAR98K", Kar98x8, new_Skin.K98_x8);

  ApplyPrimaryTable("SKIN_M24", M24Primary, new_Skin.M24);
  ReadTableChoice("SKIN_M24", M24Reddot, new_Skin.M24_reddot);
  ReadTableChoice("SKIN_M24", M24Holo, new_Skin.M24_holo);
  ReadTableChoice("SKIN_M24", M24x2, new_Skin.M24_x2);
  ReadTableChoice("SKIN_M24", M24x3, new_Skin.M24_x3);
  ReadTableChoice("SKIN_M24", M24x4, new_Skin.M24_x4);
  ReadTableChoice("SKIN_M24", M24x6, new_Skin.M24_x6);
  ReadTableChoice("SKIN_M24", M24x8, new_Skin.M24_x8);

  ApplyPrimaryTable("SKIN_AWM", AWMPrimary, new_Skin.AWM);
  ReadTableChoice("SKIN_AWM", AWMReddot, new_Skin.AWM_reddot);
  ReadTableChoice("SKIN_AWM", AWMHolo, new_Skin.AWM_holo);
  ReadTableChoice("SKIN_AWM", AWMx2, new_Skin.AWM_x2);
  ReadTableChoice("SKIN_AWM", AWMx3, new_Skin.AWM_x3);
  ReadTableChoice("SKIN_AWM", AWMx4, new_Skin.AWM_x4);
  ReadTableChoice("SKIN_AWM", AWMx6, new_Skin.AWM_x6);
  ReadTableChoice("SKIN_AWM", AWMx8, new_Skin.AWM_x8);

  ApplyPrimaryTable("SKIN_AMR", AMRPrimary, new_Skin.AMR);
  ReadTableChoice("SKIN_AMR", AMRReddot, new_Skin.AMR_reddot);
  ReadTableChoice("SKIN_AMR", AMRHolo, new_Skin.AMR_holo);
  ReadTableChoice("SKIN_AMR", AMRx2, new_Skin.AMR_x2);
  ReadTableChoice("SKIN_AMR", AMRx3, new_Skin.AMR_x3);
  ReadTableChoice("SKIN_AMR", AMRx4, new_Skin.AMR_x4);
  ReadTableChoice("SKIN_AMR", AMRx6, new_Skin.AMR_x6);
  ReadTableChoice("SKIN_AMR", AMRx8, new_Skin.AMR_x8);

  ApplyPrimaryTable("SKIN_M249", M249Primary, new_Skin.M249);
  ReadTableChoice("SKIN_M249", M249Stock, new_Skin.M249_stock);
  ApplyPrimaryTable("SKIN_DP28", DP28Primary, new_Skin.DP28);
  ApplyPrimaryTable("SKIN_MINI14", Mini14Primary, new_Skin.Mini14);
  ApplyPrimaryTable("SKIN_UZI", UZIPrimary, new_Skin.UZI);
  ApplyPrimaryTable("SKIN_UMP45", UMPPrimary, new_Skin.UMP);
  ApplyPrimaryTable("SKIN_VECTOR", VectorPrimary, new_Skin.Vector);
  ApplyPrimaryTable("SKIN_THOMPSON", ThompsonPrimary, new_Skin.Thompson);
  ApplyPrimaryTable("SKIN_BIZON", BizonPrimary, new_Skin.Bizon);
  ApplyPrimaryTable("SKIN_P90", P90Primary, new_Skin.P90);
  ApplyPrimaryTable("SKIN_PAN", PanPrimary, new_Skin.Pan);
  ApplyPrimaryTable("SKIN_S12K", S12KPrimary, new_Skin.S12K);
  ApplyPrimaryTable("SKIN_DBS", DBSPrimary, new_Skin.DBS);
  ApplyPrimaryTable("SKIN_XM1014", XM1014Primary, new_Skin.XM1014);

  ApplyPrimaryTable("SKIN_MG3", MG3Primary, new_Skin.MG3);
  ReadTableChoice("SKIN_MG3", MG3Reddot, new_Skin.MG3_reddot);
  ReadTableChoice("SKIN_MG3", MG3Holo, new_Skin.MG3_holo);
  ReadTableChoice("SKIN_MG3", MG3x2, new_Skin.MG3_x2);
  ReadTableChoice("SKIN_MG3", MG3x3, new_Skin.MG3_x3);
  ReadTableChoice("SKIN_MG3", MG3x4, new_Skin.MG3_x4);
  ReadTableChoice("SKIN_MG3", MG3x6, new_Skin.MG3_x6);

  ApplyThreeLevelTable("SKIN_BACKPACK", BackpackLv1, BackpackLv2, BackpackLv3,
                       new_Skin.baglv1, new_Skin.baglv2, new_Skin.baglv3);
  ApplyThreeLevelTable("SKIN_HELMET", HelmetLv1, HelmetLv2, HelmetLv3,
                       new_Skin.helmetlv1, new_Skin.helmetlv2, new_Skin.helmetlv3);
  ApplyPrimaryTable("SKIN_PARACHUTE", ParachuteSkins, new_Skin.Parachute);

  ApplyXSuitTable("SKIN_XSUIT", XSuits, new_Skin.Fac, new_Skin.Hieuungbay, new_Skin.Comrade);

  ApplyPrimaryTable("SKIN_VEHICLE_DACIA", DaciaSkins, new_Skin.Dacia);
  ApplyPrimaryTable("SKIN_VEHICLE_UAZ", UAZSkins, new_Skin.UAZ);
  ApplyPrimaryTable("SKIN_VEHICLE_BUGGY", BuggySkins, new_Skin.Buggy);
  ApplyPrimaryTable("SKIN_VEHICLE_MOTO", MotoSkins, new_Skin.Moto);
  ApplyPrimaryTable("SKIN_VEHICLE_MINIBUS", MiniBusSkins, new_Skin.MiniBus);
  ApplyPrimaryTable("SKIN_VEHICLE_COUPERB", CoupleRBSkins, new_Skin.CoupleRB);
  ApplyPrimaryTable("SKIN_VEHICLE_BOAT", BoatSkins, new_Skin.Boat);
}

}

 void updateSkin() {
  // Reset to declared defaults before applying the current table-backed config.
  new_Skin = snew_Skin{};
  ApplySkinTablesRefresh();
}
