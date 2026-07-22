#pragma once

// PUBG MOBILE (4.5.0 -- 64bit Beta) SDK Generate By @ByDwoz
// Telegram Channel:- @XelahotOfficial
// Generate on Wed Jul  8 13:37:46 2026
 
namespace SDK
{
//---------------------❣︎➪ 𝗕𝗬𝗗𝗪𝗢𝗭 𝗗𝗘𝗩𝗘𝗟𝗢𝗣𝗘𝗥༆✈︎🇪🇬---------------------------
//Enums
//---------------------❣︎➪𝗕𝗬𝗗𝗪𝗢𝗭 𝗗𝗘𝗩𝗘𝗟𝗢𝗣𝗘𝗥༆✈︎🇪🇬---------------------------

// Enum Gamelet.EGameletEnvironment
enum class EGameletEnvironment : uint8_t
{
	Gamelet_Test                   = 0,
	Gamelet_Product                = 1,
	Gamelet_Tyf_Test               = 2,
	Gamelet_Tyf_Product            = 3,
	Gamelet_MAX                    = 4
};


// Enum Gamelet.ECmd
enum class ECmd : uint8_t
{
	ECmdGSendMessageToApp          = 0,
	ECmdS2ESDKInitialized          = 1,
	ECmdS2EOnCgiProcessComplete    = 2,
	ECmdS2EStartPuertsVM           = 3,
	ECmdS2EPrepareGcrpRes          = 4,
	ECmdS2PMin                     = 5,
	ECmdS2PMax                     = 6,
	ECmd_MAX                       = 7
};



}

