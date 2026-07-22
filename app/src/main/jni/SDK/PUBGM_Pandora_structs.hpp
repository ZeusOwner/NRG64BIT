#pragma once

// PUBG MOBILE (4.5.0 -- 64bit Beta) SDK Generate By @ByDwoz
// Telegram Channel:- @XelahotOfficial
// Generate on Wed Jul  8 13:37:47 2026
 
namespace SDK
{
//---------------------❣︎➪ 𝗕𝗬𝗗𝗪𝗢𝗭 𝗗𝗘𝗩𝗘𝗟𝗢𝗣𝗘𝗥༆✈︎🇪🇬---------------------------
//Enums
//---------------------❣︎➪𝗕𝗬𝗗𝗪𝗢𝗭 𝗗𝗘𝗩𝗘𝗟𝗢𝗣𝗘𝗥༆✈︎🇪🇬---------------------------

// Enum Pandora.EPandoraPanelType
enum class EPandoraPanelType : uint8_t
{
	PDRPT_Pandora                  = 0,
	PDRPT_Gamelet                  = 1,
	PDRPT_MAX                      = 2
};


// Enum Pandora.EPandoraCMDType
enum class EPandoraCMDType : uint8_t
{
	PDRCT_Pandora                  = 0,
	PDRCT_Gamelet                  = 1,
	PDRCT_Undefined                = 2,
	PDRCT_MAX                      = 3
};


// Enum Pandora.EPandoraEnv
enum class EPandoraEnv : uint8_t
{
	PDR_Test                       = 0,
	PDR_Prod                       = 1,
	PDR_SingaporeTest              = 2,
	PDR_SingaporeProd              = 3,
	PDR_NorthAmericaTest           = 4,
	PDR_NorthAmericaProd           = 5,
	PDR_EnvMax                     = 6,
	PDR_MAX                        = 7
};



//---------------------❣︎➪ 𝗕𝗬𝗗𝗪𝗢𝗭 𝗗𝗘𝗩𝗘𝗟𝗢𝗣𝗘𝗥༆✈︎🇪🇬---------------------------
//Script Structs
//---------------------❣︎➪𝗕𝗬𝗗𝗪𝗢𝗭 𝗗𝗘𝗩𝗘𝗟𝗢𝗣𝗘𝗥༆✈︎🇪🇬---------------------------

// ScriptStruct Pandora.PLuaBPVar
// 0x0020
struct FPLuaBPVar
{
	unsigned char                                      UnknownData00[0x20];                                      // 0x0000(0x0020) MISSED OFFSET
};

}

