#pragma once

// PUBG MOBILE (4.5.0 -- 64bit Beta) SDK Generate By @ByDwoz
// Telegram Channel:- @XelahotOfficial
// Generate on Wed Jul  8 13:37:46 2026
 
#include "../SDK.hpp"

namespace SDK
{
//---------------------❣︎➪ 𝗕𝗬𝗗𝗪𝗢𝗭 𝗗𝗘𝗩𝗘𝗟𝗢𝗣𝗘𝗥༆✈︎🇪🇬---------------------------
//Parameters
//---------------------❣︎➪𝗕𝗬𝗗𝗪𝗢𝗭 𝗗𝗘𝗩𝗘𝗟𝗢𝗣𝗘𝗥༆✈︎🇪🇬---------------------------

// Function EZUMG.EnhancedButton.GetCurrentHeldDuration
struct UEnhancedButton_GetCurrentHeldDuration_Params
{
	float                                              ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function EZUMG.EnhancedButton.ForceCancel
struct UEnhancedButton_ForceCancel_Params
{
};

// Function EZUMG.EnhancedButton.ApplyConfig
struct UEnhancedButton_ApplyConfig_Params
{
};

// Function EZUMG.EnhancedSlider.SetUnfilledBarColor
struct UEnhancedSlider_SetUnfilledBarColor_Params
{
	struct FLinearColor                                InValue;                                                  // (Parm, IsPlainOldData)
};

// Function EZUMG.EnhancedSlider.SetOnlyRespondToThumb
struct UEnhancedSlider_SetOnlyRespondToThumb_Params
{
	bool                                               InValue;                                                  // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function EZUMG.EnhancedSlider.SetFilledBarColor
struct UEnhancedSlider_SetFilledBarColor_Params
{
	struct FLinearColor                                InValue;                                                  // (Parm, IsPlainOldData)
};

// Function EZUMG.EnhancedSlider.SetEnableSteppedSliding
struct UEnhancedSlider_SetEnableSteppedSliding_Params
{
	bool                                               InValue;                                                  // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function EZUMG.EnhancedSlider.GetUnfilledBarColor
struct UEnhancedSlider_GetUnfilledBarColor_Params
{
	struct FLinearColor                                ReturnValue;                                              // (Parm, OutParm, ReturnParm, IsPlainOldData)
};

// Function EZUMG.EnhancedSlider.GetOnlyRespondToThumb
struct UEnhancedSlider_GetOnlyRespondToThumb_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function EZUMG.EnhancedSlider.GetFilledBarColor
struct UEnhancedSlider_GetFilledBarColor_Params
{
	struct FLinearColor                                ReturnValue;                                              // (Parm, OutParm, ReturnParm, IsPlainOldData)
};

// Function EZUMG.EnhancedSlider.GetEnableSteppedSliding
struct UEnhancedSlider_GetEnableSteppedSliding_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function EZUMG.EzFactory.SetNum
struct UEzFactory_SetNum_Params
{
	int                                                NumItems;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function EZUMG.EzFactory.RemoveLastItem
struct UEzFactory_RemoveLastItem_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function EZUMG.EzFactory.GetFactoryItemCount
struct UEzFactory_GetFactoryItemCount_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function EZUMG.EzFactory.AddItem
struct UEzFactory_AddItem_Params
{
	class UWidget*                                     ReturnValue;                                              // (ExportObject, Parm, OutParm, ZeroConstructor, ReturnParm, InstancedReference, IsPlainOldData)
};

// Function EZUMG.EzSelectable.OnStateRefresh
struct UEzSelectable_OnStateRefresh_Params
{
	EEzItemState                                       NewState;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function EZUMG.EzSelector.SetSelectedIndex
struct UEzSelector_SetSelectedIndex_Params
{
	int                                                NewIndex;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function EZUMG.EzSelector.SetItemState
struct UEzSelector_SetItemState_Params
{
	int                                                ItemIndex;                                                // (Parm, ZeroConstructor, IsPlainOldData)
	EEzItemState                                       NewState;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function EZUMG.EzSelector.SetItemEnabled
struct UEzSelector_SetItemEnabled_Params
{
	int                                                ItemIndex;                                                // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               bEnabled;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function EZUMG.EzSelector.IsItemEnabled
struct UEzSelector_IsItemEnabled_Params
{
	int                                                ItemIndex;                                                // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function EZUMG.EzSelector.GetSelectedIndex
struct UEzSelector_GetSelectedIndex_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function EZUMG.EzSelector.GetItemState
struct UEzSelector_GetItemState_Params
{
	int                                                ItemIndex;                                                // (Parm, ZeroConstructor, IsPlainOldData)
	EEzItemState                                       ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function EZUMG.EzSelector.GetHoveredIndex
struct UEzSelector_GetHoveredIndex_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function EZUMG.EzSelector.GetFocusedIndex
struct UEzSelector_GetFocusedIndex_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function EZUMG.HorizontalSelector.GetChildIndexAtPosition
struct UHorizontalSelector_GetChildIndexAtPosition_Params
{
	struct FVector2D                                   LocalPosition;                                            // (ConstParm, Parm, OutParm, ReferenceParm, IsPlainOldData)
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function EZUMG.RadialPanel.SetStartAngleOffset
struct URadialPanel_SetStartAngleOffset_Params
{
	float                                              InStartAngleOffset;                                       // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function EZUMG.RadialPanel.SetSectorPadding
struct URadialPanel_SetSectorPadding_Params
{
	float                                              InSectorPadding;                                          // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function EZUMG.RadialPanel.SetArrangement
struct URadialPanel_SetArrangement_Params
{
	ERadialArrangement                                 InArrangement;                                            // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function EZUMG.RadialPanel.GetAngleAtPosition
struct URadialPanel_GetAngleAtPosition_Params
{
	struct FVector2D                                   LocalPosition;                                            // (Parm, IsPlainOldData)
	float                                              ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function EZUMG.RadialSlot.SlotAsRadialSlot
struct URadialSlot_SlotAsRadialSlot_Params
{
	class UWidget*                                     Widget;                                                   // (Parm, ZeroConstructor, InstancedReference, IsPlainOldData)
	class URadialSlot*                                 ReturnValue;                                              // (ExportObject, Parm, OutParm, ZeroConstructor, ReturnParm, InstancedReference, IsPlainOldData)
};

// Function EZUMG.RadialSlot.SetSectorSizeValue
struct URadialSlot_SetSectorSizeValue_Params
{
	float                                              Value;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function EZUMG.RadialSlot.SetSectorSizeRule
struct URadialSlot_SetSectorSizeRule_Params
{
	TEnumAsByte<ESectorSizeRule>                       InRule;                                                   // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function EZUMG.RadialSlot.SetSectorColorAndOpacity
struct URadialSlot_SetSectorColorAndOpacity_Params
{
	struct FLinearColor                                InTint;                                                   // (ConstParm, Parm, OutParm, ReferenceParm, IsPlainOldData)
};

// Function EZUMG.RadialSlot.SetSectorBrush
struct URadialSlot_SetSectorBrush_Params
{
	struct FSlateBrush                                 InBrush;                                                  // (ConstParm, Parm, OutParm, ReferenceParm)
};

// Function EZUMG.RadialSlot.SetOuterRadiusRatio
struct URadialSlot_SetOuterRadiusRatio_Params
{
	float                                              InOuterRadiusRatio;                                       // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function EZUMG.RadialSlot.SetInnerRadiusRatio
struct URadialSlot_SetInnerRadiusRatio_Params
{
	float                                              InInnerRadiusRatio;                                       // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function EZUMG.RadialSlot.SetAutoSize
struct URadialSlot_SetAutoSize_Params
{
	bool                                               bInAutoSize;                                              // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function EZUMG.RadialSlot.GetCenterRadiusRatio
struct URadialSlot_GetCenterRadiusRatio_Params
{
	float                                              ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function EZUMG.RadialSlot.GetCenterAngle
struct URadialSlot_GetCenterAngle_Params
{
	float                                              ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function EZUMG.RadialSlot.GetArcSize
struct URadialSlot_GetArcSize_Params
{
	float                                              ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function EZUMG.RadialSelector.GetChildIndexByVector
struct URadialSelector_GetChildIndexByVector_Params
{
	struct FVector2D                                   CenterOffset;                                             // (ConstParm, Parm, OutParm, ReferenceParm, IsPlainOldData)
	float                                              DeadzoneLength;                                           // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function EZUMG.RadialSelector.GetChildIndexByAngle
struct URadialSelector_GetChildIndexByAngle_Params
{
	float                                              Angle;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function EZUMG.RadialSelector.GetChildIndexAtPosition
struct URadialSelector_GetChildIndexAtPosition_Params
{
	struct FVector2D                                   LocalPosition;                                            // (ConstParm, Parm, OutParm, ReferenceParm, IsPlainOldData)
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function EZUMG.VerticalSelector.GetChildIndexAtPosition
struct UVerticalSelector_GetChildIndexAtPosition_Params
{
	struct FVector2D                                   LocalPosition;                                            // (ConstParm, Parm, OutParm, ReferenceParm, IsPlainOldData)
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

}

