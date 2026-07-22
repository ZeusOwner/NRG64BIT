// PUBG MOBILE (4.5.0 -- 64bit Beta) SDK Generate By @ByDwoz
// Telegram Channel:- @XelahotOfficial
// Generate on Wed Jul  8 13:37:47 2026
 
#include "../SDK.hpp"

namespace SDK
{
//---------------------❣︎➪ 𝗕𝗬𝗗𝗪𝗢𝗭 𝗗𝗘𝗩𝗘𝗟𝗢𝗣𝗘𝗥༆✈︎🇪🇬---------------------------
//Functions
//---------------------❣︎➪𝗕𝗬𝗗𝗪𝗢𝗭 𝗗𝗘𝗩𝗘𝗟𝗢𝗣𝗘𝗥༆✈︎🇪🇬---------------------------

// Function iTOP.FBHelper.DelayToSetAutoInitFacebookLog
// (Final, Native, Static, Public, BlueprintCallable)
// Parameters:
// bool                           IsAutoInit                     (Parm, ZeroConstructor, IsPlainOldData)

void UFBHelper::DelayToSetAutoInitFacebookLog(bool IsAutoInit)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function iTOP.FBHelper.DelayToSetAutoInitFacebookLog");

	UFBHelper_DelayToSetAutoInitFacebookLog_Params params;
	params.IsAutoInit = IsAutoInit;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	static auto defaultObj = StaticClass()->GetDefaultObject();
	defaultObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


// Function iTOP.FBHelper.DelayToInitFacebookSDK
// (Final, Native, Static, Public, BlueprintCallable)
// Parameters:
// bool                           IsAutoInit                     (Parm, ZeroConstructor, IsPlainOldData)
// bool                           WithLaunchOption               (Parm, ZeroConstructor, IsPlainOldData)

void UFBHelper::DelayToInitFacebookSDK(bool IsAutoInit, bool WithLaunchOption)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function iTOP.FBHelper.DelayToInitFacebookSDK");

	UFBHelper_DelayToInitFacebookSDK_Params params;
	params.IsAutoInit = IsAutoInit;
	params.WithLaunchOption = WithLaunchOption;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	static auto defaultObj = StaticClass()->GetDefaultObject();
	defaultObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


}

