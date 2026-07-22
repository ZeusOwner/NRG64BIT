// PUBG MOBILE (4.5.0 -- 64bit Beta) SDK Generate By @ByDwoz
// Telegram Channel:- @XelahotOfficial
// Generate on Wed Jul  8 13:37:46 2026
 
#include "../SDK.hpp"

namespace SDK
{
//---------------------❣︎➪ 𝗕𝗬𝗗𝗪𝗢𝗭 𝗗𝗘𝗩𝗘𝗟𝗢𝗣𝗘𝗥༆✈︎🇪🇬---------------------------
//Functions
//---------------------❣︎➪𝗕𝗬𝗗𝗪𝗢𝗭 𝗗𝗘𝗩𝗘𝗟𝗢𝗣𝗘𝗥༆✈︎🇪🇬---------------------------

// Function ClusterReplication.ClusterReplicationSubsystem.SetAutoClearCache
// (Final, Native, Public, BlueprintCallable)
// Parameters:
// bool                           Val                            (Parm, ZeroConstructor, IsPlainOldData)

void UClusterReplicationSubsystem::SetAutoClearCache(bool Val)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function ClusterReplication.ClusterReplicationSubsystem.SetAutoClearCache");

	UClusterReplicationSubsystem_SetAutoClearCache_Params params;
	params.Val = Val;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


// Function ClusterReplication.ClusterReplicationSubsystem.SetAutoCache
// (Final, Native, Public, BlueprintCallable)
// Parameters:
// bool                           Val                            (Parm, ZeroConstructor, IsPlainOldData)

void UClusterReplicationSubsystem::SetAutoCache(bool Val)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function ClusterReplication.ClusterReplicationSubsystem.SetAutoCache");

	UClusterReplicationSubsystem_SetAutoCache_Params params;
	params.Val = Val;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


// Function ClusterReplication.ClusterReplicationSubsystem.RemoveAllCachedObjectData
// (Final, Native, Public, BlueprintCallable)

void UClusterReplicationSubsystem::RemoveAllCachedObjectData()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function ClusterReplication.ClusterReplicationSubsystem.RemoveAllCachedObjectData");

	UClusterReplicationSubsystem_RemoveAllCachedObjectData_Params params;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


}

