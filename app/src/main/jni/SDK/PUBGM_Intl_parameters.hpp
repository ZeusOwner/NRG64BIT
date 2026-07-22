#pragma once

// PUBG MOBILE (4.5.0 -- 64bit Beta) SDK Generate By @ByDwoz
// Telegram Channel:- @XelahotOfficial
// Generate on Wed Jul  8 13:37:45 2026
 
#include "../SDK.hpp"

namespace SDK
{
//---------------------❣︎➪ 𝗕𝗬𝗗𝗪𝗢𝗭 𝗗𝗘𝗩𝗘𝗟𝗢𝗣𝗘𝗥༆✈︎🇪🇬---------------------------
//Parameters
//---------------------❣︎➪𝗕𝗬𝗗𝗪𝗢𝗭 𝗗𝗘𝗩𝗘𝗟𝗢𝗣𝗘𝗥༆✈︎🇪🇬---------------------------

// Function Intl.StatManager.ReportUAStatsEvent
struct UStatManager_ReportUAStatsEvent_Params
{
	TArray<struct FString>                             InReportChannels;                                         // (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm)
	struct FString                                     InEventName;                                              // (Parm, ZeroConstructor)
	TMap<struct FString, struct FString>               InParams;                                                 // (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm)
	bool                                               InIsRealTime;                                             // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Intl.StatManager.ReportRevenue
struct UStatManager_ReportRevenue_Params
{
	int                                                InPurchaseEventType;                                      // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     InCurrencyCode;                                           // (Parm, ZeroConstructor)
	struct FString                                     InExpense;                                                // (Parm, ZeroConstructor)
	TMap<struct FString, struct FString>               InParams;                                                 // (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm)
	struct FString                                     InExtraJson;                                              // (Parm, ZeroConstructor)
};

// Function Intl.StatManager.ReportPurchase
struct UStatManager_ReportPurchase_Params
{
	int                                                InPurchaseEventType;                                      // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     InCurrencyCode;                                           // (Parm, ZeroConstructor)
	struct FString                                     InExpense;                                                // (Parm, ZeroConstructor)
	bool                                               isRealTime;                                               // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Intl.StatManager.ReportEventWithString
struct UStatManager_ReportEventWithString_Params
{
	int                                                EventType;                                                // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     _eventBody;                                               // (Parm, ZeroConstructor)
	bool                                               isRealTime;                                               // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Intl.StatManager.ReportEventWithParam
struct UStatManager_ReportEventWithParam_Params
{
	int                                                EventType;                                                // (Parm, ZeroConstructor, IsPlainOldData)
	TMap<struct FString, struct FString>               _params;                                                  // (Parm, ZeroConstructor)
	bool                                               isRealTime;                                               // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Intl.StatManager.ReportEventWithNoParam
struct UStatManager_ReportEventWithNoParam_Params
{
	int                                                EventType;                                                // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               isRealTime;                                               // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Intl.StatManager.GetInstance
struct UStatManager_GetInstance_Params
{
	class UStatManager*                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

}

