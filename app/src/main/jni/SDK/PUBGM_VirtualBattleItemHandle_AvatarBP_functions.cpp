// PUBG MOBILE (4.5.0 -- 64bit Beta) SDK Generate By @ByDwoz
// Telegram Channel:- @XelahotOfficial
// Generate on Wed Jul  8 13:37:59 2026
 
#include "../SDK.hpp"

namespace SDK
{
//---------------------❣︎➪ 𝗕𝗬𝗗𝗪𝗢𝗭 𝗗𝗘𝗩𝗘𝗟𝗢𝗣𝗘𝗥༆✈︎🇪🇬---------------------------
//Functions
//---------------------❣︎➪𝗕𝗬𝗗𝗪𝗢𝗭 𝗗𝗘𝗩𝗘𝗟𝗢𝗣𝗘𝗥༆✈︎🇪🇬---------------------------

// Function VirtualBattleItemHandle_AvatarBP.VirtualBattleItemHandle_AvatarBP_C.GetWrapperClass
// (Public, HasOutParms, HasDefaults, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// class UClass*                  WrapperClass                   (Parm, OutParm, ZeroConstructor, IsPlainOldData)

void UVirtualBattleItemHandle_AvatarBP_C::GetWrapperClass(class UClass** WrapperClass)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function VirtualBattleItemHandle_AvatarBP.VirtualBattleItemHandle_AvatarBP_C.GetWrapperClass");

	UVirtualBattleItemHandle_AvatarBP_C_GetWrapperClass_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	if (WrapperClass != nullptr)
		*WrapperClass = params.WrapperClass;
}


// Function VirtualBattleItemHandle_AvatarBP.VirtualBattleItemHandle_AvatarBP_C.Constuct
// (Event, Public, HasOutParms, BlueprintCallable, BlueprintEvent)
// Parameters:
// struct FItemDefineID*          InDefineID                     (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)

void UVirtualBattleItemHandle_AvatarBP_C::Constuct(struct FItemDefineID* InDefineID)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function VirtualBattleItemHandle_AvatarBP.VirtualBattleItemHandle_AvatarBP_C.Constuct");

	UVirtualBattleItemHandle_AvatarBP_C_Constuct_Params params;
	params.InDefineID = InDefineID;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


// Function VirtualBattleItemHandle_AvatarBP.VirtualBattleItemHandle_AvatarBP_C.ExecuteUbergraph_VirtualBattleItemHandle_AvatarBP
// (HasDefaults)
// Parameters:
// int                            EntryPoint                     (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)

void UVirtualBattleItemHandle_AvatarBP_C::ExecuteUbergraph_VirtualBattleItemHandle_AvatarBP(int EntryPoint)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function VirtualBattleItemHandle_AvatarBP.VirtualBattleItemHandle_AvatarBP_C.ExecuteUbergraph_VirtualBattleItemHandle_AvatarBP");

	UVirtualBattleItemHandle_AvatarBP_C_ExecuteUbergraph_VirtualBattleItemHandle_AvatarBP_Params params;
	params.EntryPoint = EntryPoint;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


}

