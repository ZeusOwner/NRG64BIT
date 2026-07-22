#pragma once

// PUBG MOBILE (4.5.0 -- 64bit Beta) SDK Generate By @ByDwoz
// Telegram Channel:- @XelahotOfficial
// Generate on Wed Jul  8 13:37:47 2026
 
#include "../SDK.hpp"

namespace SDK
{
//---------------------❣︎➪ 𝗕𝗬𝗗𝗪𝗢𝗭 𝗗𝗘𝗩𝗘𝗟𝗢𝗣𝗘𝗥༆✈︎🇪🇬---------------------------
//Parameters
//---------------------❣︎➪𝗕𝗬𝗗𝗪𝗢𝗭 𝗗𝗘𝗩𝗘𝗟𝗢𝗣𝗘𝗥༆✈︎🇪🇬---------------------------

// Function AndroidPermission.AndroidPermissionFunctionLibrary.CheckPermission
struct UAndroidPermissionFunctionLibrary_CheckPermission_Params
{
	struct FString                                     permission;                                               // (Parm, ZeroConstructor)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function AndroidPermission.AndroidPermissionFunctionLibrary.AcquirePermissions
struct UAndroidPermissionFunctionLibrary_AcquirePermissions_Params
{
	TArray<struct FString>                             Permissions;                                              // (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm)
	class UAndroidPermissionCallbackProxy*             ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

}

