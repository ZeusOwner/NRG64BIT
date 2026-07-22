// PUBG MOBILE (4.5.0 -- 64bit Beta) SDK Generate By @ByDwoz
// Telegram Channel:- @XelahotOfficial
// Generate on Wed Jul  8 13:37:47 2026
 
#include "../SDK.hpp"

namespace SDK
{
//---------------------❣︎➪ 𝗕𝗬𝗗𝗪𝗢𝗭 𝗗𝗘𝗩𝗘𝗟𝗢𝗣𝗘𝗥༆✈︎🇪🇬---------------------------
//Functions
//---------------------❣︎➪𝗕𝗬𝗗𝗪𝗢𝗭 𝗗𝗘𝗩𝗘𝗟𝗢𝗣𝗘𝗥༆✈︎🇪🇬---------------------------

// Function UITweens.TweenManager.TweenScale
// (Final, Native, Public, HasDefaults)
// Parameters:
// class UWidget*                 Widget                         (Parm, ZeroConstructor, InstancedReference, IsPlainOldData)
// struct FVector2D               From                           (Parm, IsPlainOldData)
// struct FVector2D               To                             (Parm, IsPlainOldData)
// float                          Timespan                       (Parm, ZeroConstructor, IsPlainOldData)
// int                            Type                           (Parm, ZeroConstructor, IsPlainOldData)

void UTweenManager::TweenScale(class UWidget* Widget, const struct FVector2D& From, const struct FVector2D& To, float Timespan, int Type)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function UITweens.TweenManager.TweenScale");

	UTweenManager_TweenScale_Params params;
	params.Widget = Widget;
	params.From = From;
	params.To = To;
	params.Timespan = Timespan;
	params.Type = Type;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


// Function UITweens.TweenManager.TweenPosition
// (Final, Native, Public, HasDefaults)
// Parameters:
// class UWidget*                 Widget                         (Parm, ZeroConstructor, InstancedReference, IsPlainOldData)
// struct FVector2D               From                           (Parm, IsPlainOldData)
// struct FVector2D               To                             (Parm, IsPlainOldData)
// float                          Timespan                       (Parm, ZeroConstructor, IsPlainOldData)
// int                            Type                           (Parm, ZeroConstructor, IsPlainOldData)

void UTweenManager::TweenPosition(class UWidget* Widget, const struct FVector2D& From, const struct FVector2D& To, float Timespan, int Type)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function UITweens.TweenManager.TweenPosition");

	UTweenManager_TweenPosition_Params params;
	params.Widget = Widget;
	params.From = From;
	params.To = To;
	params.Timespan = Timespan;
	params.Type = Type;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


// Function UITweens.TweenManager.TweenAlpha
// (Final, Native, Public)
// Parameters:
// class UWidget*                 Widget                         (Parm, ZeroConstructor, InstancedReference, IsPlainOldData)
// float                          From                           (Parm, ZeroConstructor, IsPlainOldData)
// float                          To                             (Parm, ZeroConstructor, IsPlainOldData)
// float                          Timespan                       (Parm, ZeroConstructor, IsPlainOldData)
// int                            Type                           (Parm, ZeroConstructor, IsPlainOldData)

void UTweenManager::TweenAlpha(class UWidget* Widget, float From, float To, float Timespan, int Type)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function UITweens.TweenManager.TweenAlpha");

	UTweenManager_TweenAlpha_Params params;
	params.Widget = Widget;
	params.From = From;
	params.To = To;
	params.Timespan = Timespan;
	params.Type = Type;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


// Function UITweens.TweenManager.Tick
// (Final, Native, Public)
// Parameters:
// float                          DeltaTime                      (Parm, ZeroConstructor, IsPlainOldData)

void UTweenManager::Tick(float DeltaTime)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function UITweens.TweenManager.Tick");

	UTweenManager_Tick_Params params;
	params.DeltaTime = DeltaTime;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


}

