#pragma once

// PUBG MOBILE (4.5.0 -- 64bit Beta) SDK Generate By @ByDwoz
// Telegram Channel:- @XelahotOfficial
// Generate on Wed Jul  8 13:37:55 2026
 
#include "../SDK.hpp"

namespace SDK
{
//---------------------❣︎➪ 𝗕𝗬𝗗𝗪𝗢𝗭 𝗗𝗘𝗩𝗘𝗟𝗢𝗣𝗘𝗥༆✈︎🇪🇬---------------------------
//Parameters
//---------------------❣︎➪𝗕𝗬𝗗𝗪𝗢𝗭 𝗗𝗘𝗩𝗘𝗟𝗢𝗣𝗘𝗥༆✈︎🇪🇬---------------------------

// Function VirtualBackpackEmoteHandleBase_BP.VirtualBackpackEmoteHandleBase_BP_C.ExtractItemData
struct UVirtualBackpackEmoteHandleBase_BP_C_ExtractItemData_Params
{
	struct FBattleItemData                             ReturnValue;                                              // (Parm, OutParm, ReturnParm)
};

// Function VirtualBackpackEmoteHandleBase_BP.VirtualBackpackEmoteHandleBase_BP_C.HandleDisuse
struct UVirtualBackpackEmoteHandleBase_BP_C_HandleDisuse_Params
{
	EBattleItemDisuseReason*                           Reason;                                                   // (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function VirtualBackpackEmoteHandleBase_BP.VirtualBackpackEmoteHandleBase_BP_C.HandleUse
struct UVirtualBackpackEmoteHandleBase_BP_C_HandleUse_Params
{
	struct FBattleItemUseTarget*                       Target;                                                   // (BlueprintVisible, BlueprintReadOnly, Parm)
	EBattleItemUseReason*                              Reason;                                                   // (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function VirtualBackpackEmoteHandleBase_BP.VirtualBackpackEmoteHandleBase_BP_C.HandlePickup
struct UVirtualBackpackEmoteHandleBase_BP_C_HandlePickup_Params
{
	TScriptInterface<class UItemContainerInterface>    ItemContainer;                                            // (BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ZeroConstructor, ReferenceParm, IsPlainOldData)
	struct FBattleItemPickupInfo*                      PickupInfo;                                               // (BlueprintVisible, BlueprintReadOnly, Parm)
	EBattleItemPickupReason*                           Reason;                                                   // (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

}

