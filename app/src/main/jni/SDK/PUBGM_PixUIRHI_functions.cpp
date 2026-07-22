// PUBG MOBILE (4.5.0 -- 64bit Beta) SDK Generate By @ByDwoz
// Telegram Channel:- @XelahotOfficial
// Generate on Wed Jul  8 13:37:47 2026
 
#include "../SDK.hpp"

namespace SDK
{
//---------------------❣︎➪ 𝗕𝗬𝗗𝗪𝗢𝗭 𝗗𝗘𝗩𝗘𝗟𝗢𝗣𝗘𝗥༆✈︎🇪🇬---------------------------
//Functions
//---------------------❣︎➪𝗕𝗬𝗗𝗪𝗢𝗭 𝗗𝗘𝗩𝗘𝗟𝗢𝗣𝗘𝗥༆✈︎🇪🇬---------------------------

// Function PixUIRHI.PxRHIImage.GetHandleObject
// (Final, Native, Public, BlueprintCallable)
// Parameters:
// class UObject*                 ReturnValue                    (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)

class UObject* UPxRHIImage::GetHandleObject()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function PixUIRHI.PxRHIImage.GetHandleObject");

	UPxRHIImage_GetHandleObject_Params params;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


// Function PixUIRHI.PxRHIMgr.RHIImageUpdate
// (Final, Native, Static, Public, BlueprintCallable)
// Parameters:
// class UPxRHIMgr*               pPxRHIImage                    (Parm, ZeroConstructor, IsPlainOldData)
// bool                           ReturnValue                    (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)

bool UPxRHIMgr::RHIImageUpdate(class UPxRHIMgr* pPxRHIImage)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function PixUIRHI.PxRHIMgr.RHIImageUpdate");

	UPxRHIMgr_RHIImageUpdate_Params params;
	params.pPxRHIImage = pPxRHIImage;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	static auto defaultObj = StaticClass()->GetDefaultObject();
	defaultObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


// Function PixUIRHI.PxRHIMgr.RHIImageFindByObject
// (Final, Native, Static, Public, BlueprintCallable)
// Parameters:
// class UObject*                 pCoreObject                    (Parm, ZeroConstructor, IsPlainOldData)
// class UPxRHIMgr*               ReturnValue                    (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)

class UPxRHIMgr* UPxRHIMgr::RHIImageFindByObject(class UObject* pCoreObject)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function PixUIRHI.PxRHIMgr.RHIImageFindByObject");

	UPxRHIMgr_RHIImageFindByObject_Params params;
	params.pCoreObject = pCoreObject;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	static auto defaultObj = StaticClass()->GetDefaultObject();
	defaultObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


// Function PixUIRHI.PxRHIMgr.RHIImageDestroy
// (Final, Native, Static, Public, BlueprintCallable)
// Parameters:
// class UPxRHIMgr*               pPxRHIImage                    (Parm, ZeroConstructor, IsPlainOldData)
// bool                           ReturnValue                    (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)

bool UPxRHIMgr::RHIImageDestroy(class UPxRHIMgr* pPxRHIImage)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function PixUIRHI.PxRHIMgr.RHIImageDestroy");

	UPxRHIMgr_RHIImageDestroy_Params params;
	params.pPxRHIImage = pPxRHIImage;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	static auto defaultObj = StaticClass()->GetDefaultObject();
	defaultObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


// Function PixUIRHI.PxRHIMgr.RHIImageCreate
// (Final, Native, Static, Public, BlueprintCallable)
// Parameters:
// class UPxRHIImage*             ReturnValue                    (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)

class UPxRHIImage* UPxRHIMgr::RHIImageCreate()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function PixUIRHI.PxRHIMgr.RHIImageCreate");

	UPxRHIMgr_RHIImageCreate_Params params;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	static auto defaultObj = StaticClass()->GetDefaultObject();
	defaultObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


// Function PixUIRHI.PxRHIMgr.Get
// (Final, Native, Static, Public, BlueprintCallable)
// Parameters:
// class UPxRHIMgr*               ReturnValue                    (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)

class UPxRHIMgr* UPxRHIMgr::Get()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function PixUIRHI.PxRHIMgr.Get");

	UPxRHIMgr_Get_Params params;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	static auto defaultObj = StaticClass()->GetDefaultObject();
	defaultObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


}

