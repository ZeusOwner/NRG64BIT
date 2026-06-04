//
// Created by Administrator on 3/4/2024.
//

#ifndef MRTHANG_SKIN_DATA_H
#define MRTHANG_SKIN_DATA_H
#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <codecvt>
#include <locale>
bool language = false;
struct ItemData {
 int itemId;
 std::wstring itemName;
};
static std::unordered_map<int, ItemData> itemDatabase;
static std::unordered_set<int> loggedIDs;
static bool showKeyboard1 = false;
static std::string clipboardText = "";

std::string WStringToString(const std::wstring& wstr) {
 std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
 return converter.to_bytes(wstr);
}

void DumpSkin() {
 auto backpack = (UBackpackUtils*)UBackpackUtils::StaticClass();
 if (backpack) {
  auto items = backpack->GetItemIDs();
  for (int i = 0; i < items.Num(); ++i) {
int itemId = items[i];
if (loggedIDs.find(itemId) == loggedIDs.end()) {
 auto itemRecord = backpack->GetItemRecord(itemId);
 ItemData data;
 data.itemId = itemId;
 data.itemName = itemRecord.ItemName.ToWString();
 itemDatabase[itemId] = data;
 loggedIDs.insert(itemId);
}
  }
 }
}

typedef unsigned long DWORD;
class CModBase
{
};

class CWeapAttack : public CModBase
{
public:
 DWORD Default;
};

class CGunSkinSetting : public CModBase
{
public:
    DWORD AKM = 1101001213;
    DWORD M16A4 = 1101002081;
    DWORD SCARL = 1101003188;
    DWORD M416 = 1101004046;
    DWORD GROZA = 1101005052;
    DWORD AUG = 1101006062;
    DWORD QBZ = 1101007046;
    DWORD M762 = 1101008081;
    DWORD HONEY = 0;
    DWORD ACE32 = 1101102017;
    // smg
    DWORD UZI = 1102001024;
    DWORD UMP45 = 1102002136;
    DWORD VECTOR = 1102003080;
    DWORD TOMMY = 1102004018;
    // snip
    DWORD KAR98 = 1103001179;
    DWORD M24 = 1103002087;
    DWORD AWM = 1103003062;
    DWORD MINI14 = 1103006030;
    DWORD MK14 = 1103007020;
    DWORD AMR = 1103012010;
    // light-machine
    DWORD M249 = 1105001048;
    DWORD DP28 = 1105002063;
    DWORD MG3 = 1101102017;
    // SHOTGUN
    DWORD DBS = 1104101001;
    DWORD S12K = 1104003027;
    DWORD XM1014 = 1104101001;
    // other
    DWORD PAN = 1108004356;
    DWORD P90 = 1102105012;
    DWORD S1897,S686,MK12,QBU,SLR,WIN94,VSS,SKS,MP5K,PP19,FAMAS,ACVAL,G36C,MK47 = 0;
};

class CModSkinSetting
{
public:
 DWORD dwPassword = 0xBEEF;
 bool bEnable = true;
 bool bGunSkin = true;
 bool bClothSkin = true;
 bool bVehicleSkin = true;
 bool bKillMsg = true;
 bool bDeadbox = true;
 bool bMetro = false;
 bool bEmote = false;
 bool bBackPack = true;
 //
 CGunSkinSetting *gun;
 CModSkinSetting()
 {
  gun = new CGunSkinSetting();
 }
};

static CModSkinSetting skin;

struct FSkinItem
{
 std::string name2;
 DWORD value;
 std::string ToStructString()
 {
  // return "{ \"" + name + " \", " + std::to_string(value) + " },";
  return std::to_string(value);
 }
};

extern std::vector<FSkinItem> skinItems, filteredItems;
class CSkinsInfo
{
public:
 DWORD *out;
 bool bFirstInit = false;
 int current_index = 0;
 std::vector<FSkinItem> items;
 CSkinsInfo()
 {
  items = {};
 }
 void Init(std::vector<FSkinItem> _items, DWORD *_out)
 {
  out = _out;
  items = _items;
  if (out && items.size() > 0)
  {
*out = items[0].value;
  }
 }
 void Init(std::vector<FSkinItem> _items)
 {
  items = _items;
 }
 DWORD At(int index)
 {
  if (index > items.size())
return 0;
  return items[index].value;
 }
 DWORD Get()
 {
  return At(current_index);
 }
};

class SkinData
{
public:
    CSkinsInfo
        m416,
        m16,
        akm,
        scarl,
        aug,
        m762,
        groza,
        ace32,
        honey,
        qbz;
    CSkinsInfo
        ump45,
        vector,
        tommy,
        uzi;
    CSkinsInfo
        kar98,
        m24,
        awm,
        amr,
        mk14,
        mini14,
        m249,
        dp28,
        mg3,
        pan,        
    s1897,
    s686,
    mk12,
    qbu,
    slr,
    win94,
    vss,
    sks,
    mp5k,
    pp19,
    famas,
    acval,
    g36c,
    mk47,
    p90,
    s12k,
    xm1014,
    dbs;
SkinData()
{
    #pragma region Rifle
    m16.Init(std::vector<FSkinItem>{
        {"Skeletal Core", 1101002081},
    },&skin.gun->M16A4);
    m416.Init(std::vector<FSkinItem>{
      {"Glacier - M416", 1101004046},
      {"Sealed Nether - M416", 1101004226},
      {"The Fool - M416", 1101004062},
      {"Lizard Roar - M416", 1101004086},
      {"Imperial Splendor - M416", 1101004163},
      {"Silver Guru - M416", 1101004201},
      {"Tidal Embrace - M416", 1101004209},
      {"Shinobi Kami - M416", 1101004218},
      {"Crimson Skyblade", 1101004246},
      },&skin.gun->M416);
     akm.Init(std::vector<FSkinItem>{
     {"Starsea Admiral - AKM", 1101001213},
     {"Hellfire - AKM", 1101001231},
     {"Decisive Day - AKM", 1101001231},
     {"Lightshift Temple (Gold Feather) - AKM", 1101001256},
     {"Lightshift Temple (Divine Moon) - AKM", 1101001249},    
     },&skin.gun->AKM);
    scarl.Init(std::vector<FSkinItem>{
    {"Bloodstained Nemesis - SCAR-L (Lv. 8)", 1101003167},
    {"Folly's Clasp - SCAR-L (Lv. 7)", 1101003181},
    {"Serene Lumina - SCAR-L (Lv. 7)", 1101003195},
    },
    &skin.gun->SCARL);
    aug.Init(std::vector<FSkinItem>{
     {"Forsaken Glace - AUG", 1101006062},
     {"Abyssal Howl - AUG", 1101006075},
     },
     &skin.gun->AUG);
    m762.Init(std::vector<FSkinItem>{
      {"Stray Rebellion - M762", 1101008081},
      {"Luminous Muse - M762", 1101008136},
      {"Skeletal Carver - M762", 1101008146},
      {"Platinum Skeleton - M762", 1101008154},
      },
      &skin.gun->M762);
    groza.Init(std::vector<FSkinItem>{
    {"River Styx - Groza", 1101005052},
    {"Primordial Remnants - Groza", 1101005090},
    },
    &skin.gun->GROZA);
    honey.Init(std::vector<FSkinItem>{
    {"Vivid Glare - Honey Badger", 1101012009},
    },
    &skin.gun->HONEY);
    ace32.Init(std::vector<FSkinItem>{
    {"Kamekameha - ACE32", 1101102007},
    {"Icicle Spike - ACE32", 1101102017},
    {"Mystic Kraken - ACE32", 1101102025},
    },
    &skin.gun->ACE32);
    qbz.Init(std::vector<FSkinItem>{
     {"Nether Phantom - QBZ", 1101007046},
     {"Hoa Kiếm Chí Mạng - QBZ", 1101007062}},
     &skin.gun->QBZ);
    #pragma endregion
    #pragma region SMG
    ump45.Init(std::vector<FSkinItem>{
    {"Cryofrost Shard - UMP45", 1102002136},
    },
    &skin.gun->UMP45);
    uzi.Init(std::vector<FSkinItem>{
     {"Citrus Bliss - UZI", 1102001103},
     {"Spirit Sentry - UZI", 1102001112},
     {"Savagery - UZI (Lv. 5)", 1102001998},
     {"Juicer - UZI (Lv. 5)", 1102001102},
     },
     &skin.gun->UZI);
    vector.Init(std::vector<FSkinItem>{
    {"Mecha Drake", 1102003080},
    },
    &skin.gun->VECTOR);
    tommy.Init(std::vector<FSkinItem>{
    {"Candy cane", 1102004018},
    },
    &skin.gun->TOMMY);
    #pragma endregion
    #pragma region Sniper
    kar98.Init(std::vector<FSkinItem>{
    {"Violet Volt - Kar98K", 1103001179},
    {"Thornmaker - Kar98K", 1103001191},
    },
    &skin.gun->KAR98);
    m24.Init(std::vector<FSkinItem>{
     {"Cadence Maestro - M24", 1103002087},
     {"Industry Edge - M24 (Lv. 5)", 1103002094},
     },
     &skin.gun->M24);
    awm.Init(std::vector<FSkinItem>{
     {"Serpengleam - AWM", 1103003087},
     },
     &skin.gun->AWM);
    amr.Init(std::vector<FSkinItem>{
     {"Crimson Ephialtes - AMR", 1103012010},
     {"Hỏa Thần - AMR", 1103012019},
     },
     &skin.gun->AMR);
    mk14.Init(std::vector<FSkinItem>{
      {"Drakreign - Mk14", 1103007028},
      },
      &skin.gun->MK14);
    mini14.Init(std::vector<FSkinItem>{
    {"Icicle - Mini14", 1103006030},
    },
    &skin.gun->MINI14);
    #pragma endregion
    #pragma region LMG
    m249.Init(std::vector<FSkinItem>{
      {"Moondrop Eterna - M249", 1105001048},
      {"Graffiti Street - M249", 1105001062},
      },
      &skin.gun->M249);
    dp28.Init(std::vector<FSkinItem>{
      {"Shenron - DP-28", 1105002063},
      {"Mech Hero - DP-28 (Lv. 5)", 1105002071},
      {"Data Kitten - DP-28 (Lv. 5)", 1105002076},
      },
      &skin.gun->DP28);
    mg3.Init(std::vector<FSkinItem>{
     {"Soaring Dragon - MG3", 1105010008},
     {"Sky Huntress - MG3", 1105010019},
     },
     &skin.gun->MG3);
    pan.Init(std::vector<FSkinItem>{
     {"Chicken Hot - Pan", 1108004356},
     {"Ryan - Pan", 1108004060},
     {"Apeach - Pan", 1108004061},
     {"BAPE X PUBG MOBILE CAMO Pan", 1108004062},
    
     },
     &skin.gun->PAN);
    #pragma endregion
    
    #pragma region Shotgun
    s12k.Init(std::vector<FSkinItem>{
      {"Golden Eagle - S12K", 1104003027},
      {"Atomic Trigger - S12K", 1104003037},
      },
      &skin.gun->S12K);
    dbs.Init(std::vector<FSkinItem>{
     {"Panthera Prime - DBS", 1104004024},
     {"Cosmic Beast - DBS", 1104004035},
     },
     &skin.gun->DBS);
     xm1014.Init(std::vector<FSkinItem>{
    {"Deadly Carnival - M1014", 1104101001},
    },
    &skin.gun->XM1014);
    s1897.Init(std::vector<FSkinItem>{
    {"CUSTOM SKIN", 0},
    },
    &skin.gun->S1897);
    s686.Init(std::vector<FSkinItem>{
    {"CUSTOM SKIN", 0},
    },
    &skin.gun->S686);
    mk12.Init(std::vector<FSkinItem>{
    {"CUSTOM SKIN", 0},
    },
    &skin.gun->MK12);
    qbu.Init(std::vector<FSkinItem>{
    {"CUSTOM SKIN", 0},
    },
    &skin.gun->QBU);
    slr.Init(std::vector<FSkinItem>{
    {"CUSTOM SKIN", 0},
    },
    &skin.gun->SLR);
    win94.Init(std::vector<FSkinItem>{
    {"CUSTOM SKIN", 0},
    },
    &skin.gun->WIN94);
    sks.Init(std::vector<FSkinItem>{
    {"CUSTOM SKIN", 0},
    },
    &skin.gun->SKS);
    mp5k.Init(std::vector<FSkinItem>{
    {"CUSTOM SKIN", 0},
    },
    &skin.gun->MP5K);
    pp19.Init(std::vector<FSkinItem>{
    {"CUSTOM SKIN", 0},
    },
    &skin.gun->PP19);
    famas.Init(std::vector<FSkinItem>{
    {"CUSTOM SKIN", 0},
    },
    &skin.gun->XM1014);
    acval.Init(std::vector<FSkinItem>{
    {"CUSTOM SKIN", 0},
    },
    &skin.gun->ACVAL);
    g36c.Init(std::vector<FSkinItem>{
    {"CUSTOM SKIN", 0},
    },
    &skin.gun->G36C);
    p90.Init(std::vector<FSkinItem> {
    {"The Cunning Cyberkitty - P90",1102105012},
    {"Golden Claw - P90",1102105018},
    {"Golden Pegasus - P90",1102105028},
    },&skin.gun->P90);
    }
};
static SkinData skindata;
#endif // MRTHANG_SKIN_DATA_H
