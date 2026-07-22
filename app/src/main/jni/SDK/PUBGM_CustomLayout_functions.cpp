// PUBG MOBILE (4.5.0 -- 64bit Beta) SDK Generate By @ByDwoz
// Telegram Channel:- @XelahotOfficial
// Generate on Wed Jul  8 13:37:46 2026
 
#include "../SDK.hpp"

namespace SDK
{
//---------------------❣︎➪ 𝗕𝗬𝗗𝗪𝗢𝗭 𝗗𝗘𝗩𝗘𝗟𝗢𝗣𝗘𝗥༆✈︎🇪🇬---------------------------
//Functions
//---------------------❣︎➪𝗕𝗬𝗗𝗪𝗢𝗭 𝗗𝗘𝗩𝗘𝗟𝗢𝗣𝗘𝗥༆✈︎🇪🇬---------------------------

// Function CustomLayout.CustomizePanel.SetScale
// (Native, Public, BlueprintCallable)
// Parameters:
// float                          Scale                          (Parm, ZeroConstructor, IsPlainOldData)

void UCustomizePanel::SetScale(float Scale)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomizePanel.SetScale");

	UCustomizePanel_SetScale_Params params;
	params.Scale = Scale;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


// Function CustomLayout.CustomizePanel.SetPosition
// (Final, Native, Public, HasOutParms, HasDefaults, BlueprintCallable)
// Parameters:
// struct FVector2D               Position                       (ConstParm, Parm, OutParm, ReferenceParm, IsPlainOldData)

void UCustomizePanel::SetPosition(const struct FVector2D& Position)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomizePanel.SetPosition");

	UCustomizePanel_SetPosition_Params params;
	params.Position = Position;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


// Function CustomLayout.CustomizePanel.SetOpacityWithClamp
// (Final, Native, Public, BlueprintCallable)
// Parameters:
// float                          InOpacity                      (Parm, ZeroConstructor, IsPlainOldData)
// float                          MinOpacity                     (Parm, ZeroConstructor, IsPlainOldData)
// float                          MaxOpacity                     (Parm, ZeroConstructor, IsPlainOldData)

void UCustomizePanel::SetOpacityWithClamp(float InOpacity, float MinOpacity, float MaxOpacity)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomizePanel.SetOpacityWithClamp");

	UCustomizePanel_SetOpacityWithClamp_Params params;
	params.InOpacity = InOpacity;
	params.MinOpacity = MinOpacity;
	params.MaxOpacity = MaxOpacity;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


// Function CustomLayout.CustomizePanel.SetOpacity
// (Native, Public, BlueprintCallable)
// Parameters:
// float                          InOpacity                      (Parm, ZeroConstructor, IsPlainOldData)

void UCustomizePanel::SetOpacity(float InOpacity)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomizePanel.SetOpacity");

	UCustomizePanel_SetOpacity_Params params;
	params.InOpacity = InOpacity;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


// Function CustomLayout.CustomizePanel.SetMovable
// (Final, Native, Public, BlueprintCallable)
// Parameters:
// bool                           bInMovable                     (Parm, ZeroConstructor, IsPlainOldData)

void UCustomizePanel::SetMovable(bool bInMovable)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomizePanel.SetMovable");

	UCustomizePanel_SetMovable_Params params;
	params.bInMovable = bInMovable;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


// Function CustomLayout.CustomizePanel.SetMaxScale
// (Final, Native, Public, BlueprintCallable, Const)
// Parameters:
// float                          Scale                          (Parm, ZeroConstructor, IsPlainOldData)

void UCustomizePanel::SetMaxScale(float Scale)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomizePanel.SetMaxScale");

	UCustomizePanel_SetMaxScale_Params params;
	params.Scale = Scale;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


// Function CustomLayout.CustomizePanel.SetInvalid
// (Native, Public, BlueprintCallable)
// Parameters:
// bool                           Invalid                        (ConstParm, Parm, ZeroConstructor, IsPlainOldData)

void UCustomizePanel::SetInvalid(bool Invalid)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomizePanel.SetInvalid");

	UCustomizePanel_SetInvalid_Params params;
	params.Invalid = Invalid;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


// Function CustomLayout.CustomizePanel.SetInterceptChildInput
// (Final, Native, Public, BlueprintCallable)
// Parameters:
// bool                           bInIntercept                   (Parm, ZeroConstructor, IsPlainOldData)

void UCustomizePanel::SetInterceptChildInput(bool bInIntercept)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomizePanel.SetInterceptChildInput");

	UCustomizePanel_SetInterceptChildInput_Params params;
	params.bInIntercept = bInIntercept;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


// Function CustomLayout.CustomizePanel.SetDrawMargin
// (Final, Native, Public, BlueprintCallable)
// Parameters:
// bool                           bDraw                          (ConstParm, Parm, ZeroConstructor, IsPlainOldData)

void UCustomizePanel::SetDrawMargin(bool bDraw)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomizePanel.SetDrawMargin");

	UCustomizePanel_SetDrawMargin_Params params;
	params.bDraw = bDraw;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


// Function CustomLayout.CustomizePanel.SetDetectMargin
// (Final, Native, Public, HasOutParms, BlueprintCallable)
// Parameters:
// struct FMargin                 InMargin                       (ConstParm, Parm, OutParm, ReferenceParm, IsPlainOldData)

void UCustomizePanel::SetDetectMargin(const struct FMargin& InMargin)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomizePanel.SetDetectMargin");

	UCustomizePanel_SetDetectMargin_Params params;
	params.InMargin = InMargin;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


// Function CustomLayout.CustomizePanel.SetDesireScale
// (Final, Native, Public, BlueprintCallable)
// Parameters:
// float                          Scale                          (Parm, ZeroConstructor, IsPlainOldData)

void UCustomizePanel::SetDesireScale(float Scale)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomizePanel.SetDesireScale");

	UCustomizePanel_SetDesireScale_Params params;
	params.Scale = Scale;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


// Function CustomLayout.CustomizePanel.SetDesirePosition
// (Final, Native, Public, HasOutParms, HasDefaults, BlueprintCallable)
// Parameters:
// struct FVector2D               Position                       (ConstParm, Parm, OutParm, ReferenceParm, IsPlainOldData)

void UCustomizePanel::SetDesirePosition(const struct FVector2D& Position)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomizePanel.SetDesirePosition");

	UCustomizePanel_SetDesirePosition_Params params;
	params.Position = Position;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


// Function CustomLayout.CustomizePanel.SetDefaultLayoutCode
// (Final, Native, Public, HasOutParms, BlueprintCallable)
// Parameters:
// struct FCustomLayoutBlueprintCode InCode                         (ConstParm, Parm, OutParm, ReferenceParm)

void UCustomizePanel::SetDefaultLayoutCode(const struct FCustomLayoutBlueprintCode& InCode)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomizePanel.SetDefaultLayoutCode");

	UCustomizePanel_SetDefaultLayoutCode_Params params;
	params.InCode = InCode;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


// Function CustomLayout.CustomizePanel.SetCustomType
// (Native, Public, BlueprintCallable)
// Parameters:
// int                            NewType                        (Parm, ZeroConstructor, IsPlainOldData)

void UCustomizePanel::SetCustomType(int NewType)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomizePanel.SetCustomType");

	UCustomizePanel_SetCustomType_Params params;
	params.NewType = NewType;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


// Function CustomLayout.CustomizePanel.RestoreInBound
// (Final, Native, Public, BlueprintCallable, Const)

void UCustomizePanel::RestoreInBound()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomizePanel.RestoreInBound");

	UCustomizePanel_RestoreInBound_Params params;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


// Function CustomLayout.CustomizePanel.ResetMaxScale
// (Final, Native, Public, BlueprintCallable, Const)

void UCustomizePanel::ResetMaxScale()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomizePanel.ResetMaxScale");

	UCustomizePanel_ResetMaxScale_Params params;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


// Function CustomLayout.CustomizePanel.IsOutOfBound
// (Final, Native, Public, BlueprintCallable, BlueprintPure, Const)
// Parameters:
// float                          InvisibleCheckOffset           (Parm, ZeroConstructor, IsPlainOldData)
// bool                           ReturnValue                    (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)

bool UCustomizePanel::IsOutOfBound(float InvisibleCheckOffset)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomizePanel.IsOutOfBound");

	UCustomizePanel_IsOutOfBound_Params params;
	params.InvisibleCheckOffset = InvisibleCheckOffset;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


// Function CustomLayout.CustomizePanel.InitDefaultLayoutData
// (Final, Native, Public, BlueprintCallable)

void UCustomizePanel::InitDefaultLayoutData()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomizePanel.InitDefaultLayoutData");

	UCustomizePanel_InitDefaultLayoutData_Params params;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


// Function CustomLayout.CustomizePanel.GetScale
// (Final, Native, Public, BlueprintCallable, BlueprintPure, Const)
// Parameters:
// float                          ReturnValue                    (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)

float UCustomizePanel::GetScale()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomizePanel.GetScale");

	UCustomizePanel_GetScale_Params params;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


// Function CustomLayout.CustomizePanel.GetPosition
// (Final, Native, Public, HasDefaults, BlueprintCallable, BlueprintPure, Const)
// Parameters:
// struct FVector2D               ReturnValue                    (Parm, OutParm, ReturnParm, IsPlainOldData)

struct FVector2D UCustomizePanel::GetPosition()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomizePanel.GetPosition");

	UCustomizePanel_GetPosition_Params params;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


// Function CustomLayout.CustomizePanel.GetOpacity
// (Native, Public, BlueprintCallable, BlueprintPure, Const)
// Parameters:
// float                          ReturnValue                    (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)

float UCustomizePanel::GetOpacity()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomizePanel.GetOpacity");

	UCustomizePanel_GetOpacity_Params params;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


// Function CustomLayout.CustomizePanel.GetMovable
// (Final, Native, Public, BlueprintCallable, BlueprintPure, Const)
// Parameters:
// bool                           ReturnValue                    (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)

bool UCustomizePanel::GetMovable()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomizePanel.GetMovable");

	UCustomizePanel_GetMovable_Params params;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


// Function CustomLayout.CustomizePanel.GetMaxScale
// (Final, Native, Public, BlueprintCallable, BlueprintPure, Const)
// Parameters:
// float                          ReturnValue                    (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)

float UCustomizePanel::GetMaxScale()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomizePanel.GetMaxScale");

	UCustomizePanel_GetMaxScale_Params params;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


// Function CustomLayout.CustomizePanel.GetLayoutData
// (Final, Native, Public, BlueprintCallable, BlueprintPure, Const)
// Parameters:
// struct FUIElemLayoutDetail     ReturnValue                    (Parm, OutParm, ReturnParm)

struct FUIElemLayoutDetail UCustomizePanel::GetLayoutData()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomizePanel.GetLayoutData");

	UCustomizePanel_GetLayoutData_Params params;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


// Function CustomLayout.CustomizePanel.GetLayoutCode
// (Final, Native, Public, BlueprintCallable, BlueprintPure, Const)
// Parameters:
// struct FCustomLayoutBlueprintCode ReturnValue                    (Parm, OutParm, ReturnParm)

struct FCustomLayoutBlueprintCode UCustomizePanel::GetLayoutCode()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomizePanel.GetLayoutCode");

	UCustomizePanel_GetLayoutCode_Params params;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


// Function CustomLayout.CustomizePanel.GetInvalid
// (Native, Public, BlueprintCallable, BlueprintPure, Const)
// Parameters:
// bool                           ReturnValue                    (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)

bool UCustomizePanel::GetInvalid()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomizePanel.GetInvalid");

	UCustomizePanel_GetInvalid_Params params;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


// Function CustomLayout.CustomizePanel.GetDefaultLayoutData
// (Final, Native, Public, BlueprintCallable, BlueprintPure, Const)
// Parameters:
// struct FUIElemLayoutDetail     ReturnValue                    (Parm, OutParm, ReturnParm)

struct FUIElemLayoutDetail UCustomizePanel::GetDefaultLayoutData()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomizePanel.GetDefaultLayoutData");

	UCustomizePanel_GetDefaultLayoutData_Params params;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


// Function CustomLayout.CustomizePanel.GetCustomType
// (Final, Native, Public, BlueprintCallable, BlueprintPure, Const)
// Parameters:
// int                            ReturnValue                    (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)

int UCustomizePanel::GetCustomType()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomizePanel.GetCustomType");

	UCustomizePanel_GetCustomType_Params params;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


// Function CustomLayout.CustomizePanel.ClampPosition
// (Final, Native, Public, HasOutParms, HasDefaults, BlueprintCallable, BlueprintPure, Const)
// Parameters:
// struct FVector2D               DesiredPos                     (ConstParm, Parm, OutParm, ReferenceParm, IsPlainOldData)
// struct FVector2D               ReturnValue                    (Parm, OutParm, ReturnParm, IsPlainOldData)

struct FVector2D UCustomizePanel::ClampPosition(const struct FVector2D& DesiredPos)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomizePanel.ClampPosition");

	UCustomizePanel_ClampPosition_Params params;
	params.DesiredPos = DesiredPos;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


// Function CustomLayout.CustomizePanel.ApplyLayoutData
// (Final, Native, Public, HasOutParms, BlueprintCallable)
// Parameters:
// struct FUIElemLayoutDetail     LayoutDetail                   (ConstParm, Parm, OutParm, ReferenceParm)

void UCustomizePanel::ApplyLayoutData(const struct FUIElemLayoutDetail& LayoutDetail)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomizePanel.ApplyLayoutData");

	UCustomizePanel_ApplyLayoutData_Params params;
	params.LayoutDetail = LayoutDetail;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


// Function CustomLayout.CustomizePanel.ApplyLayoutCode
// (Final, Native, Public, HasOutParms, BlueprintCallable)
// Parameters:
// struct FCustomLayoutBlueprintCode InCode                         (ConstParm, Parm, OutParm, ReferenceParm)

void UCustomizePanel::ApplyLayoutCode(const struct FCustomLayoutBlueprintCode& InCode)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomizePanel.ApplyLayoutCode");

	UCustomizePanel_ApplyLayoutCode_Params params;
	params.InCode = InCode;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


// Function CustomLayout.CustomizePanel.ApplyDefaultLayout
// (Final, Native, Public, BlueprintCallable)

void UCustomizePanel::ApplyDefaultLayout()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomizePanel.ApplyDefaultLayout");

	UCustomizePanel_ApplyDefaultLayout_Params params;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


// Function CustomLayout.CustomLayoutBlueprintLibrary.MakeLayoutDetail
// (Final, Native, Static, Public, HasDefaults, BlueprintCallable, BlueprintPure)
// Parameters:
// int                            Type                           (Parm, ZeroConstructor, IsPlainOldData)
// EAnchorsType                   AnchorType                     (Parm, ZeroConstructor, IsPlainOldData)
// struct FVector2D               Offset                         (Parm, IsPlainOldData)
// struct FUIElemLayoutDetail     ReturnValue                    (Parm, OutParm, ReturnParm)

struct FUIElemLayoutDetail UCustomLayoutBlueprintLibrary::MakeLayoutDetail(int Type, EAnchorsType AnchorType, const struct FVector2D& Offset)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomLayoutBlueprintLibrary.MakeLayoutDetail");

	UCustomLayoutBlueprintLibrary_MakeLayoutDetail_Params params;
	params.Type = Type;
	params.AnchorType = AnchorType;
	params.Offset = Offset;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	static auto defaultObj = StaticClass()->GetDefaultObject();
	defaultObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


// Function CustomLayout.CustomLayoutBlueprintLibrary.Conv_TypeToAnchors
// (Final, Native, Static, Public, BlueprintCallable, BlueprintPure)
// Parameters:
// EAnchorsType                   InType                         (Parm, ZeroConstructor, IsPlainOldData)
// struct FAnchors                ReturnValue                    (Parm, OutParm, ReturnParm)

struct FAnchors UCustomLayoutBlueprintLibrary::Conv_TypeToAnchors(EAnchorsType InType)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomLayoutBlueprintLibrary.Conv_TypeToAnchors");

	UCustomLayoutBlueprintLibrary_Conv_TypeToAnchors_Params params;
	params.InType = InType;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	static auto defaultObj = StaticClass()->GetDefaultObject();
	defaultObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


// Function CustomLayout.CustomLayoutBlueprintLibrary.Conv_LayoutDetailToCode
// (Final, Native, Static, Public, HasOutParms, BlueprintCallable, BlueprintPure)
// Parameters:
// struct FUIElemLayoutDetail     InDetail                       (ConstParm, Parm, OutParm, ReferenceParm)
// struct FCustomLayoutBlueprintCode ReturnValue                    (Parm, OutParm, ReturnParm)

struct FCustomLayoutBlueprintCode UCustomLayoutBlueprintLibrary::Conv_LayoutDetailToCode(const struct FUIElemLayoutDetail& InDetail)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomLayoutBlueprintLibrary.Conv_LayoutDetailToCode");

	UCustomLayoutBlueprintLibrary_Conv_LayoutDetailToCode_Params params;
	params.InDetail = InDetail;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	static auto defaultObj = StaticClass()->GetDefaultObject();
	defaultObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


// Function CustomLayout.CustomLayoutBlueprintLibrary.Conv_CodeToLayoutDetail
// (Final, Native, Static, Public, HasOutParms, BlueprintCallable, BlueprintPure)
// Parameters:
// struct FCustomLayoutBlueprintCode InCode                         (ConstParm, Parm, OutParm, ReferenceParm)
// int                            Type                           (Parm, ZeroConstructor, IsPlainOldData)
// struct FUIElemLayoutDetail     ReturnValue                    (Parm, OutParm, ReturnParm)

struct FUIElemLayoutDetail UCustomLayoutBlueprintLibrary::Conv_CodeToLayoutDetail(const struct FCustomLayoutBlueprintCode& InCode, int Type)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomLayoutBlueprintLibrary.Conv_CodeToLayoutDetail");

	UCustomLayoutBlueprintLibrary_Conv_CodeToLayoutDetail_Params params;
	params.InCode = InCode;
	params.Type = Type;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	static auto defaultObj = StaticClass()->GetDefaultObject();
	defaultObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


// Function CustomLayout.CustomLayoutBlueprintLibrary.Conv_AnchorsToType
// (Final, Native, Static, Public, HasOutParms, BlueprintCallable, BlueprintPure)
// Parameters:
// struct FAnchors                InAnchors                      (ConstParm, Parm, OutParm, ReferenceParm)
// EAnchorsType                   ReturnValue                    (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)

EAnchorsType UCustomLayoutBlueprintLibrary::Conv_AnchorsToType(const struct FAnchors& InAnchors)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomLayoutBlueprintLibrary.Conv_AnchorsToType");

	UCustomLayoutBlueprintLibrary_Conv_AnchorsToType_Params params;
	params.InAnchors = InAnchors;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	static auto defaultObj = StaticClass()->GetDefaultObject();
	defaultObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


// Function CustomLayout.CustomLayoutSubsystem.UnregisterCustomPanel
// (Final, Native, Public, BlueprintCallable)
// Parameters:
// class UCustomPanel*            InCustomizePanel               (Parm, ZeroConstructor, InstancedReference, IsPlainOldData)

void UCustomLayoutSubsystem::UnregisterCustomPanel(class UCustomPanel* InCustomizePanel)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomLayoutSubsystem.UnregisterCustomPanel");

	UCustomLayoutSubsystem_UnregisterCustomPanel_Params params;
	params.InCustomizePanel = InCustomizePanel;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


// Function CustomLayout.CustomLayoutSubsystem.SetScreenPadding
// (Final, Native, Static, Public, HasOutParms, BlueprintCallable)
// Parameters:
// struct FMargin                 InOffset                       (ConstParm, Parm, OutParm, ReferenceParm, IsPlainOldData)

void UCustomLayoutSubsystem::SetScreenPadding(const struct FMargin& InOffset)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomLayoutSubsystem.SetScreenPadding");

	UCustomLayoutSubsystem_SetScreenPadding_Params params;
	params.InOffset = InOffset;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	static auto defaultObj = StaticClass()->GetDefaultObject();
	defaultObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


// Function CustomLayout.CustomLayoutSubsystem.SetEditMode
// (Final, Native, Public, BlueprintCallable)
// Parameters:
// bool                           bEnable                        (Parm, ZeroConstructor, IsPlainOldData)

void UCustomLayoutSubsystem::SetEditMode(bool bEnable)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomLayoutSubsystem.SetEditMode");

	UCustomLayoutSubsystem_SetEditMode_Params params;
	params.bEnable = bEnable;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


// Function CustomLayout.CustomLayoutSubsystem.RemoveUserSettingSlot
// (Final, Native, Public, BlueprintCallable)
// Parameters:
// class UCustomLayoutUserSetting* InUserSetting                  (Parm, ZeroConstructor, IsPlainOldData)

void UCustomLayoutSubsystem::RemoveUserSettingSlot(class UCustomLayoutUserSetting* InUserSetting)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomLayoutSubsystem.RemoveUserSettingSlot");

	UCustomLayoutSubsystem_RemoveUserSettingSlot_Params params;
	params.InUserSetting = InUserSetting;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


// Function CustomLayout.CustomLayoutSubsystem.RegisterCustomPanel
// (Final, Native, Public, BlueprintCallable)
// Parameters:
// class UCustomPanel*            InCustomizePanel               (Parm, ZeroConstructor, InstancedReference, IsPlainOldData)

void UCustomLayoutSubsystem::RegisterCustomPanel(class UCustomPanel* InCustomizePanel)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomLayoutSubsystem.RegisterCustomPanel");

	UCustomLayoutSubsystem_RegisterCustomPanel_Params params;
	params.InCustomizePanel = InCustomizePanel;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


// Function CustomLayout.CustomLayoutSubsystem.InsertUserSettingSlot
// (Final, Native, Public, BlueprintCallable)
// Parameters:
// class UCustomLayoutUserSetting* InUserSetting                  (Parm, ZeroConstructor, IsPlainOldData)
// int                            Index                          (Parm, ZeroConstructor, IsPlainOldData)

void UCustomLayoutSubsystem::InsertUserSettingSlot(class UCustomLayoutUserSetting* InUserSetting, int Index)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomLayoutSubsystem.InsertUserSettingSlot");

	UCustomLayoutSubsystem_InsertUserSettingSlot_Params params;
	params.InUserSetting = InUserSetting;
	params.Index = Index;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


// Function CustomLayout.CustomLayoutSubsystem.HandleTouchStatEvent
// (Final, Native, Public, HasOutParms)
// Parameters:
// struct FTouchStatInfo          TouchStatInfo                  (ConstParm, Parm, OutParm, ReferenceParm)

void UCustomLayoutSubsystem::HandleTouchStatEvent(const struct FTouchStatInfo& TouchStatInfo)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomLayoutSubsystem.HandleTouchStatEvent");

	UCustomLayoutSubsystem_HandleTouchStatEvent_Params params;
	params.TouchStatInfo = TouchStatInfo;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


// Function CustomLayout.CustomLayoutSubsystem.GetUserSettingInSlot
// (Final, Native, Public, BlueprintCallable)
// Parameters:
// struct FString                 Name                           (Parm, ZeroConstructor)
// class UCustomLayoutUserSetting* ReturnValue                    (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)

class UCustomLayoutUserSetting* UCustomLayoutSubsystem::GetUserSettingInSlot(const struct FString& Name)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomLayoutSubsystem.GetUserSettingInSlot");

	UCustomLayoutSubsystem_GetUserSettingInSlot_Params params;
	params.Name = Name;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


// Function CustomLayout.CustomLayoutSubsystem.GetRegisteredPanel
// (Final, Native, Public, BlueprintCallable)
// Parameters:
// int                            InCustomType                   (Parm, ZeroConstructor, IsPlainOldData)
// class UCustomPanel*            ReturnValue                    (ExportObject, Parm, OutParm, ZeroConstructor, ReturnParm, InstancedReference, IsPlainOldData)

class UCustomPanel* UCustomLayoutSubsystem::GetRegisteredPanel(int InCustomType)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomLayoutSubsystem.GetRegisteredPanel");

	UCustomLayoutSubsystem_GetRegisteredPanel_Params params;
	params.InCustomType = InCustomType;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


// Function CustomLayout.CustomLayoutSubsystem.FlushRegisteredPanelMap
// (Final, Native, Public, BlueprintCallable)

void UCustomLayoutSubsystem::FlushRegisteredPanelMap()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomLayoutSubsystem.FlushRegisteredPanelMap");

	UCustomLayoutSubsystem_FlushRegisteredPanelMap_Params params;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


// Function CustomLayout.CustomLayoutSubsystem.FindLayoutDetail
// (Final, Native, Public, HasOutParms, BlueprintCallable, BlueprintPure, Const)
// Parameters:
// int                            InCustomType                   (Parm, ZeroConstructor, IsPlainOldData)
// struct FUIElemLayoutDetail     OutDetail                      (Parm, OutParm)
// bool                           ReturnValue                    (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)

bool UCustomLayoutSubsystem::FindLayoutDetail(int InCustomType, struct FUIElemLayoutDetail* OutDetail)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomLayoutSubsystem.FindLayoutDetail");

	UCustomLayoutSubsystem_FindLayoutDetail_Params params;
	params.InCustomType = InCustomType;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	if (OutDetail != nullptr)
		*OutDetail = params.OutDetail;

	return params.ReturnValue;
}


// Function CustomLayout.CustomLayoutSubsystem.ClearUserSettingSlots
// (Final, Native, Public, BlueprintCallable)

void UCustomLayoutSubsystem::ClearUserSettingSlots()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomLayoutSubsystem.ClearUserSettingSlots");

	UCustomLayoutSubsystem_ClearUserSettingSlots_Params params;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


// Function CustomLayout.CustomLayoutSubsystem.ClearTouchStatArray
// (Final, Native, Public, BlueprintCallable)

void UCustomLayoutSubsystem::ClearTouchStatArray()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomLayoutSubsystem.ClearTouchStatArray");

	UCustomLayoutSubsystem_ClearTouchStatArray_Params params;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


// Function CustomLayout.CustomLayoutSubsystem.ClearRegisteredPanelMap
// (Final, Native, Public, BlueprintCallable)

void UCustomLayoutSubsystem::ClearRegisteredPanelMap()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomLayoutSubsystem.ClearRegisteredPanelMap");

	UCustomLayoutSubsystem_ClearRegisteredPanelMap_Params params;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


// Function CustomLayout.CustomLayoutSubsystem.BroadcastCustomLayoutChange
// (Final, Native, Public, HasOutParms, BlueprintCallable)
// Parameters:
// TArray<int>                    InCustomTypeList               (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm)

void UCustomLayoutSubsystem::BroadcastCustomLayoutChange(TArray<int> InCustomTypeList)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomLayoutSubsystem.BroadcastCustomLayoutChange");

	UCustomLayoutSubsystem_BroadcastCustomLayoutChange_Params params;
	params.InCustomTypeList = InCustomTypeList;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


// Function CustomLayout.CustomLayoutSubsystem.AddUserSettingSlot
// (Final, Native, Public, BlueprintCallable)
// Parameters:
// class UCustomLayoutUserSetting* InUserSetting                  (Parm, ZeroConstructor, IsPlainOldData)

void UCustomLayoutSubsystem::AddUserSettingSlot(class UCustomLayoutUserSetting* InUserSetting)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomLayoutSubsystem.AddUserSettingSlot");

	UCustomLayoutSubsystem_AddUserSettingSlot_Params params;
	params.InUserSetting = InUserSetting;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


// Function CustomLayout.CustomLayoutUserSetting.UpdateTimeTag
// (Final, Native, Public, BlueprintCallable)

void UCustomLayoutUserSetting::UpdateTimeTag()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomLayoutUserSetting.UpdateTimeTag");

	UCustomLayoutUserSetting_UpdateTimeTag_Params params;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


// Function CustomLayout.CustomLayoutUserSetting.SetTimeTagFromUnixTimestamp
// (Final, Native, Public)
// Parameters:
// int64_t                        InUnixTimestamp                (ConstParm, Parm, ZeroConstructor, IsPlainOldData)

void UCustomLayoutUserSetting::SetTimeTagFromUnixTimestamp(int64_t InUnixTimestamp)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomLayoutUserSetting.SetTimeTagFromUnixTimestamp");

	UCustomLayoutUserSetting_SetTimeTagFromUnixTimestamp_Params params;
	params.InUnixTimestamp = InUnixTimestamp;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


// Function CustomLayout.CustomLayoutUserSetting.SetDataByLayoutDetail
// (Final, Native, Public, HasOutParms, BlueprintCallable)
// Parameters:
// int                            InCustomType                   (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
// struct FUIElemLayoutDetail     InData                         (ConstParm, Parm, OutParm, ReferenceParm)

void UCustomLayoutUserSetting::SetDataByLayoutDetail(int InCustomType, const struct FUIElemLayoutDetail& InData)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomLayoutUserSetting.SetDataByLayoutDetail");

	UCustomLayoutUserSetting_SetDataByLayoutDetail_Params params;
	params.InCustomType = InCustomType;
	params.InData = InData;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


// Function CustomLayout.CustomLayoutUserSetting.RemoveData
// (Final, Native, Public, BlueprintCallable)
// Parameters:
// int                            InCustomType                   (ConstParm, Parm, ZeroConstructor, IsPlainOldData)

void UCustomLayoutUserSetting::RemoveData(int InCustomType)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomLayoutUserSetting.RemoveData");

	UCustomLayoutUserSetting_RemoveData_Params params;
	params.InCustomType = InCustomType;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


// Function CustomLayout.CustomLayoutUserSetting.GetTimeTagAsUnixTimestamp
// (Final, Native, Public, Const)
// Parameters:
// int64_t                        ReturnValue                    (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)

int64_t UCustomLayoutUserSetting::GetTimeTagAsUnixTimestamp()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomLayoutUserSetting.GetTimeTagAsUnixTimestamp");

	UCustomLayoutUserSetting_GetTimeTagAsUnixTimestamp_Params params;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


// Function CustomLayout.CustomLayoutUserSetting.GetLayoutCodeCheckSum
// (Final, Native, Public, Const)
// Parameters:
// uint64_t                       ReturnValue                    (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)

uint64_t UCustomLayoutUserSetting::GetLayoutCodeCheckSum()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomLayoutUserSetting.GetLayoutCodeCheckSum");

	UCustomLayoutUserSetting_GetLayoutCodeCheckSum_Params params;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


// Function CustomLayout.CustomLayoutUserSetting.GetDataAsLayoutDetail
// (Final, Native, Public, BlueprintCallable, BlueprintPure, Const)
// Parameters:
// int                            InCustomType                   (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
// struct FUIElemLayoutDetail     ReturnValue                    (Parm, OutParm, ReturnParm)

struct FUIElemLayoutDetail UCustomLayoutUserSetting::GetDataAsLayoutDetail(int InCustomType)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomLayoutUserSetting.GetDataAsLayoutDetail");

	UCustomLayoutUserSetting_GetDataAsLayoutDetail_Params params;
	params.InCustomType = InCustomType;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


// Function CustomLayout.CustomLayoutUserSetting.GetCustomTypeList
// (Final, Native, Public, HasOutParms, BlueprintCallable, BlueprintPure, Const)
// Parameters:
// TArray<int>                    OutKeys                        (Parm, OutParm, ZeroConstructor)

void UCustomLayoutUserSetting::GetCustomTypeList(TArray<int>* OutKeys)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomLayoutUserSetting.GetCustomTypeList");

	UCustomLayoutUserSetting_GetCustomTypeList_Params params;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	if (OutKeys != nullptr)
		*OutKeys = params.OutKeys;
}


// Function CustomLayout.CustomLayoutUserSetting.Contains
// (Final, Native, Public, BlueprintCallable, BlueprintPure, Const)
// Parameters:
// int                            InCustomType                   (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
// bool                           ReturnValue                    (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)

bool UCustomLayoutUserSetting::Contains(int InCustomType)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomLayoutUserSetting.Contains");

	UCustomLayoutUserSetting_Contains_Params params;
	params.InCustomType = InCustomType;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


// Function CustomLayout.CustomPanel.UpdateCustomLayout
// (Final, Native, Public, BlueprintCallable)

void UCustomPanel::UpdateCustomLayout()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomPanel.UpdateCustomLayout");

	UCustomPanel_UpdateCustomLayout_Params params;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


// Function CustomLayout.CustomPanel.SetEditable
// (Final, Native, Public, BlueprintCallable)
// Parameters:
// bool                           bEditable                      (Parm, ZeroConstructor, IsPlainOldData)

void UCustomPanel::SetEditable(bool bEditable)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.CustomPanel.SetEditable");

	UCustomPanel_SetEditable_Params params;
	params.bEditable = bEditable;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


// Function CustomLayout.DynamicCustomIndexer.GetIndexer
// (Final, Native, Static, Public, BlueprintCallable)
// Parameters:
// struct FString                 Path                           (Parm, ZeroConstructor)
// class UDynamicCustomIndexer*   ReturnValue                    (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)

class UDynamicCustomIndexer* UDynamicCustomIndexer::GetIndexer(const struct FString& Path)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.DynamicCustomIndexer.GetIndexer");

	UDynamicCustomIndexer_GetIndexer_Params params;
	params.Path = Path;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	static auto defaultObj = StaticClass()->GetDefaultObject();
	defaultObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


// Function CustomLayout.DynamicCustomIndexer.GetDefaultLayoutCode
// (Final, Native, Public, BlueprintCallable, BlueprintPure, Const)
// Parameters:
// int                            CustomType                     (Parm, ZeroConstructor, IsPlainOldData)
// struct FCustomLayoutBlueprintCode ReturnValue                    (Parm, OutParm, ReturnParm)

struct FCustomLayoutBlueprintCode UDynamicCustomIndexer::GetDefaultLayoutCode(int CustomType)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.DynamicCustomIndexer.GetDefaultLayoutCode");

	UDynamicCustomIndexer_GetDefaultLayoutCode_Params params;
	params.CustomType = CustomType;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


// Function CustomLayout.DynamicCustomIndexer.CreateDynamicCustomWidgets
// (Final, Native, Public, HasOutParms)
// Parameters:
// TArray<int>                    InCustomTypeList               (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm)
// TMap<int, class UCustomizePanel*> CustomPanelMap                 (Parm, OutParm, ZeroConstructor)
// class UCanvasPanel*            Container                      (Parm, ZeroConstructor, InstancedReference, IsPlainOldData)
// bool                           bIgnoreDPIScale                (Parm, ZeroConstructor, IsPlainOldData)
// TMap<int, class UCustomizePanel*> ReturnValue                    (ExportObject, Parm, OutParm, ZeroConstructor, ReturnParm)

TMap<int, class UCustomizePanel*> UDynamicCustomIndexer::CreateDynamicCustomWidgets(TArray<int> InCustomTypeList, class UCanvasPanel* Container, bool bIgnoreDPIScale, TMap<int, class UCustomizePanel*>* CustomPanelMap)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.DynamicCustomIndexer.CreateDynamicCustomWidgets");

	UDynamicCustomIndexer_CreateDynamicCustomWidgets_Params params;
	params.InCustomTypeList = InCustomTypeList;
	params.Container = Container;
	params.bIgnoreDPIScale = bIgnoreDPIScale;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	if (CustomPanelMap != nullptr)
		*CustomPanelMap = params.CustomPanelMap;

	return params.ReturnValue;
}


// Function CustomLayout.PinchDragWidget.SetPinchEnabled
// (Final, Native, Public, BlueprintCallable)
// Parameters:
// bool                           bEnabled                       (Parm, ZeroConstructor, IsPlainOldData)

void UPinchDragWidget::SetPinchEnabled(bool bEnabled)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.PinchDragWidget.SetPinchEnabled");

	UPinchDragWidget_SetPinchEnabled_Params params;
	params.bEnabled = bEnabled;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


// Function CustomLayout.PinchDragWidget.SetDragEnabled
// (Final, Native, Public, BlueprintCallable)
// Parameters:
// bool                           bEnabled                       (Parm, ZeroConstructor, IsPlainOldData)

void UPinchDragWidget::SetDragEnabled(bool bEnabled)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.PinchDragWidget.SetDragEnabled");

	UPinchDragWidget_SetDragEnabled_Params params;
	params.bEnabled = bEnabled;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


// Function CustomLayout.PinchDragWidget.ScreenDeltaToParentLocal
// (Final, Native, Static, Public, HasOutParms, HasDefaults, BlueprintCallable, BlueprintPure)
// Parameters:
// class UWidget*                 Widget                         (ConstParm, Parm, ZeroConstructor, InstancedReference, IsPlainOldData)
// struct FVector2D               ScreenDelta                    (ConstParm, Parm, OutParm, ReferenceParm, IsPlainOldData)
// struct FVector2D               ReturnValue                    (Parm, OutParm, ReturnParm, IsPlainOldData)

struct FVector2D UPinchDragWidget::ScreenDeltaToParentLocal(class UWidget* Widget, const struct FVector2D& ScreenDelta)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.PinchDragWidget.ScreenDeltaToParentLocal");

	UPinchDragWidget_ScreenDeltaToParentLocal_Params params;
	params.Widget = Widget;
	params.ScreenDelta = ScreenDelta;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	static auto defaultObj = StaticClass()->GetDefaultObject();
	defaultObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


// Function CustomLayout.PinchDragWidget.IsPinchEnabled
// (Final, Native, Public, BlueprintCallable, BlueprintPure, Const)
// Parameters:
// bool                           ReturnValue                    (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)

bool UPinchDragWidget::IsPinchEnabled()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.PinchDragWidget.IsPinchEnabled");

	UPinchDragWidget_IsPinchEnabled_Params params;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


// Function CustomLayout.PinchDragWidget.IsFirstPointIndex
// (Final, Native, Public, HasOutParms, BlueprintCallable, BlueprintPure, Const)
// Parameters:
// struct FPointerEvent           InPointerEvent                 (ConstParm, Parm, OutParm, ReferenceParm)
// bool                           ReturnValue                    (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)

bool UPinchDragWidget::IsFirstPointIndex(const struct FPointerEvent& InPointerEvent)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.PinchDragWidget.IsFirstPointIndex");

	UPinchDragWidget_IsFirstPointIndex_Params params;
	params.InPointerEvent = InPointerEvent;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


// Function CustomLayout.PinchDragWidget.IsDragEnabled
// (Final, Native, Public, BlueprintCallable, BlueprintPure, Const)
// Parameters:
// bool                           ReturnValue                    (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)

bool UPinchDragWidget::IsDragEnabled()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.PinchDragWidget.IsDragEnabled");

	UPinchDragWidget_IsDragEnabled_Params params;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


// Function CustomLayout.SettingCustomPanel.SetSelectedImageOriginEffect
// (Final, Native, Public, BlueprintCallable)

void USettingCustomPanel::SetSelectedImageOriginEffect()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.SettingCustomPanel.SetSelectedImageOriginEffect");

	USettingCustomPanel_SetSelectedImageOriginEffect_Params params;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


// Function CustomLayout.SettingCustomPanel.SetSelectedImageFlashEffect
// (Final, Native, Public, BlueprintCallable)

void USettingCustomPanel::SetSelectedImageFlashEffect()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.SettingCustomPanel.SetSelectedImageFlashEffect");

	USettingCustomPanel_SetSelectedImageFlashEffect_Params params;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


// Function CustomLayout.SettingCustomPanel.SetDisplayState
// (Final, Native, Public, BlueprintCallable)
// Parameters:
// ESCPDisplayState               State                          (ConstParm, Parm, ZeroConstructor, IsPlainOldData)

void USettingCustomPanel::SetDisplayState(ESCPDisplayState State)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.SettingCustomPanel.SetDisplayState");

	USettingCustomPanel_SetDisplayState_Params params;
	params.State = State;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


// Function CustomLayout.SettingCustomPanel.OnTouchPreview
// (Event, Protected, BlueprintEvent)

void USettingCustomPanel::OnTouchPreview()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.SettingCustomPanel.OnTouchPreview");

	USettingCustomPanel_OnTouchPreview_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


// Function CustomLayout.SettingCustomPanel.IsSquareFlashEffectAssetName
// (Event, Public, BlueprintEvent)
// Parameters:
// struct FString                 InAssetName                    (Parm, ZeroConstructor)
// bool                           ReturnValue                    (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)

bool USettingCustomPanel::IsSquareFlashEffectAssetName(const struct FString& InAssetName)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.SettingCustomPanel.IsSquareFlashEffectAssetName");

	USettingCustomPanel_IsSquareFlashEffectAssetName_Params params;
	params.InAssetName = InAssetName;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


// Function CustomLayout.SettingCustomPanel.IsCircleFlashEffectAssetName
// (Event, Public, BlueprintEvent)
// Parameters:
// struct FString                 InAssetName                    (Parm, ZeroConstructor)
// bool                           ReturnValue                    (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)

bool USettingCustomPanel::IsCircleFlashEffectAssetName(const struct FString& InAssetName)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.SettingCustomPanel.IsCircleFlashEffectAssetName");

	USettingCustomPanel_IsCircleFlashEffectAssetName_Params params;
	params.InAssetName = InAssetName;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


// Function CustomLayout.SettingCustomPanel.GetWidgetByType
// (Final, Native, Public, BlueprintCallable)
// Parameters:
// class UWidget*                 RootWidget                     (Parm, ZeroConstructor, InstancedReference, IsPlainOldData)
// class UClass*                  WidgetType                     (Parm, ZeroConstructor, IsPlainOldData)
// class UWidget*                 ReturnValue                    (ExportObject, Parm, OutParm, ZeroConstructor, ReturnParm, InstancedReference, IsPlainOldData)

class UWidget* USettingCustomPanel::GetWidgetByType(class UWidget* RootWidget, class UClass* WidgetType)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.SettingCustomPanel.GetWidgetByType");

	USettingCustomPanel_GetWidgetByType_Params params;
	params.RootWidget = RootWidget;
	params.WidgetType = WidgetType;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


// Function CustomLayout.SettingCustomPanel.GetSelectedImage
// (Final, Native, Public, BlueprintCallable)
// Parameters:
// class UImage*                  ReturnValue                    (ExportObject, Parm, OutParm, ZeroConstructor, ReturnParm, InstancedReference, IsPlainOldData)

class UImage* USettingCustomPanel::GetSelectedImage()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.SettingCustomPanel.GetSelectedImage");

	USettingCustomPanel_GetSelectedImage_Params params;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


// Function CustomLayout.SettingCustomPanel.GetParentWidget
// (Final, Native, Public, BlueprintCallable, BlueprintPure, Const)
// Parameters:
// class UWidget*                 ReturnValue                    (ExportObject, Parm, OutParm, ZeroConstructor, ReturnParm, InstancedReference, IsPlainOldData)

class UWidget* USettingCustomPanel::GetParentWidget()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.SettingCustomPanel.GetParentWidget");

	USettingCustomPanel_GetParentWidget_Params params;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


// Function CustomLayout.SettingCustomPanel.GetNamedWidgetFromOwner
// (Final, Native, Public, BlueprintCallable)
// Parameters:
// struct FString                 Prefix                         (Parm, ZeroConstructor)
// class UWidget*                 ReturnValue                    (ExportObject, Parm, OutParm, ZeroConstructor, ReturnParm, InstancedReference, IsPlainOldData)

class UWidget* USettingCustomPanel::GetNamedWidgetFromOwner(const struct FString& Prefix)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.SettingCustomPanel.GetNamedWidgetFromOwner");

	USettingCustomPanel_GetNamedWidgetFromOwner_Params params;
	params.Prefix = Prefix;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


// Function CustomLayout.SettingCustomPanel.GetInvalidImage
// (Final, Native, Public, BlueprintCallable)
// Parameters:
// class UImage*                  ReturnValue                    (ExportObject, Parm, OutParm, ZeroConstructor, ReturnParm, InstancedReference, IsPlainOldData)

class UImage* USettingCustomPanel::GetInvalidImage()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.SettingCustomPanel.GetInvalidImage");

	USettingCustomPanel_GetInvalidImage_Params params;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


// Function CustomLayout.SettingCustomPanel.GetCenterPositionInScreenSpace
// (Final, Native, Public, HasDefaults, BlueprintCallable)
// Parameters:
// class UWidget*                 FullScreenWidget               (Parm, ZeroConstructor, InstancedReference, IsPlainOldData)
// struct FVector2D               ReturnValue                    (Parm, OutParm, ReturnParm, IsPlainOldData)

struct FVector2D USettingCustomPanel::GetCenterPositionInScreenSpace(class UWidget* FullScreenWidget)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.SettingCustomPanel.GetCenterPositionInScreenSpace");

	USettingCustomPanel_GetCenterPositionInScreenSpace_Params params;
	params.FullScreenWidget = FullScreenWidget;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


// Function CustomLayout.SettingCustomPanel.FlashHighlight
// (Final, Native, Public, BlueprintCallable)
// Parameters:
// float                          Seconds                        (ConstParm, Parm, ZeroConstructor, IsPlainOldData)

void USettingCustomPanel::FlashHighlight(float Seconds)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.SettingCustomPanel.FlashHighlight");

	USettingCustomPanel_FlashHighlight_Params params;
	params.Seconds = Seconds;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


// Function CustomLayout.SettingCustomPanel.ConvertCenterPositionFromScreenSpace
// (Final, Native, Public, HasOutParms, HasDefaults, BlueprintCallable)
// Parameters:
// class UWidget*                 FullScreenWidget               (Parm, ZeroConstructor, InstancedReference, IsPlainOldData)
// struct FVector2D               SSPosition                     (ConstParm, Parm, OutParm, ReferenceParm, IsPlainOldData)
// struct FVector2D               ReturnValue                    (Parm, OutParm, ReturnParm, IsPlainOldData)

struct FVector2D USettingCustomPanel::ConvertCenterPositionFromScreenSpace(class UWidget* FullScreenWidget, const struct FVector2D& SSPosition)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CustomLayout.SettingCustomPanel.ConvertCenterPositionFromScreenSpace");

	USettingCustomPanel_ConvertCenterPositionFromScreenSpace_Params params;
	params.FullScreenWidget = FullScreenWidget;
	params.SSPosition = SSPosition;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


}

