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

// Function CustomLayout.CustomizePanel.SetScale
struct UCustomizePanel_SetScale_Params
{
	float                                              Scale;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function CustomLayout.CustomizePanel.SetPosition
struct UCustomizePanel_SetPosition_Params
{
	struct FVector2D                                   Position;                                                 // (ConstParm, Parm, OutParm, ReferenceParm, IsPlainOldData)
};

// Function CustomLayout.CustomizePanel.SetOpacityWithClamp
struct UCustomizePanel_SetOpacityWithClamp_Params
{
	float                                              InOpacity;                                                // (Parm, ZeroConstructor, IsPlainOldData)
	float                                              MinOpacity;                                               // (Parm, ZeroConstructor, IsPlainOldData)
	float                                              MaxOpacity;                                               // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function CustomLayout.CustomizePanel.SetOpacity
struct UCustomizePanel_SetOpacity_Params
{
	float                                              InOpacity;                                                // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function CustomLayout.CustomizePanel.SetMovable
struct UCustomizePanel_SetMovable_Params
{
	bool                                               bInMovable;                                               // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function CustomLayout.CustomizePanel.SetMaxScale
struct UCustomizePanel_SetMaxScale_Params
{
	float                                              Scale;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function CustomLayout.CustomizePanel.SetInvalid
struct UCustomizePanel_SetInvalid_Params
{
	bool                                               Invalid;                                                  // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
};

// Function CustomLayout.CustomizePanel.SetInterceptChildInput
struct UCustomizePanel_SetInterceptChildInput_Params
{
	bool                                               bInIntercept;                                             // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function CustomLayout.CustomizePanel.SetDrawMargin
struct UCustomizePanel_SetDrawMargin_Params
{
	bool                                               bDraw;                                                    // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
};

// Function CustomLayout.CustomizePanel.SetDetectMargin
struct UCustomizePanel_SetDetectMargin_Params
{
	struct FMargin                                     InMargin;                                                 // (ConstParm, Parm, OutParm, ReferenceParm, IsPlainOldData)
};

// Function CustomLayout.CustomizePanel.SetDesireScale
struct UCustomizePanel_SetDesireScale_Params
{
	float                                              Scale;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function CustomLayout.CustomizePanel.SetDesirePosition
struct UCustomizePanel_SetDesirePosition_Params
{
	struct FVector2D                                   Position;                                                 // (ConstParm, Parm, OutParm, ReferenceParm, IsPlainOldData)
};

// Function CustomLayout.CustomizePanel.SetDefaultLayoutCode
struct UCustomizePanel_SetDefaultLayoutCode_Params
{
	struct FCustomLayoutBlueprintCode                  InCode;                                                   // (ConstParm, Parm, OutParm, ReferenceParm)
};

// Function CustomLayout.CustomizePanel.SetCustomType
struct UCustomizePanel_SetCustomType_Params
{
	int                                                NewType;                                                  // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function CustomLayout.CustomizePanel.RestoreInBound
struct UCustomizePanel_RestoreInBound_Params
{
};

// Function CustomLayout.CustomizePanel.ResetMaxScale
struct UCustomizePanel_ResetMaxScale_Params
{
};

// Function CustomLayout.CustomizePanel.IsOutOfBound
struct UCustomizePanel_IsOutOfBound_Params
{
	float                                              InvisibleCheckOffset;                                     // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function CustomLayout.CustomizePanel.InitDefaultLayoutData
struct UCustomizePanel_InitDefaultLayoutData_Params
{
};

// Function CustomLayout.CustomizePanel.GetScale
struct UCustomizePanel_GetScale_Params
{
	float                                              ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function CustomLayout.CustomizePanel.GetPosition
struct UCustomizePanel_GetPosition_Params
{
	struct FVector2D                                   ReturnValue;                                              // (Parm, OutParm, ReturnParm, IsPlainOldData)
};

// Function CustomLayout.CustomizePanel.GetOpacity
struct UCustomizePanel_GetOpacity_Params
{
	float                                              ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function CustomLayout.CustomizePanel.GetMovable
struct UCustomizePanel_GetMovable_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function CustomLayout.CustomizePanel.GetMaxScale
struct UCustomizePanel_GetMaxScale_Params
{
	float                                              ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function CustomLayout.CustomizePanel.GetLayoutData
struct UCustomizePanel_GetLayoutData_Params
{
	struct FUIElemLayoutDetail                         ReturnValue;                                              // (Parm, OutParm, ReturnParm)
};

// Function CustomLayout.CustomizePanel.GetLayoutCode
struct UCustomizePanel_GetLayoutCode_Params
{
	struct FCustomLayoutBlueprintCode                  ReturnValue;                                              // (Parm, OutParm, ReturnParm)
};

// Function CustomLayout.CustomizePanel.GetInvalid
struct UCustomizePanel_GetInvalid_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function CustomLayout.CustomizePanel.GetDefaultLayoutData
struct UCustomizePanel_GetDefaultLayoutData_Params
{
	struct FUIElemLayoutDetail                         ReturnValue;                                              // (Parm, OutParm, ReturnParm)
};

// Function CustomLayout.CustomizePanel.GetCustomType
struct UCustomizePanel_GetCustomType_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function CustomLayout.CustomizePanel.ClampPosition
struct UCustomizePanel_ClampPosition_Params
{
	struct FVector2D                                   DesiredPos;                                               // (ConstParm, Parm, OutParm, ReferenceParm, IsPlainOldData)
	struct FVector2D                                   ReturnValue;                                              // (Parm, OutParm, ReturnParm, IsPlainOldData)
};

// Function CustomLayout.CustomizePanel.ApplyLayoutData
struct UCustomizePanel_ApplyLayoutData_Params
{
	struct FUIElemLayoutDetail                         LayoutDetail;                                             // (ConstParm, Parm, OutParm, ReferenceParm)
};

// Function CustomLayout.CustomizePanel.ApplyLayoutCode
struct UCustomizePanel_ApplyLayoutCode_Params
{
	struct FCustomLayoutBlueprintCode                  InCode;                                                   // (ConstParm, Parm, OutParm, ReferenceParm)
};

// Function CustomLayout.CustomizePanel.ApplyDefaultLayout
struct UCustomizePanel_ApplyDefaultLayout_Params
{
};

// Function CustomLayout.CustomLayoutBlueprintLibrary.MakeLayoutDetail
struct UCustomLayoutBlueprintLibrary_MakeLayoutDetail_Params
{
	int                                                Type;                                                     // (Parm, ZeroConstructor, IsPlainOldData)
	EAnchorsType                                       AnchorType;                                               // (Parm, ZeroConstructor, IsPlainOldData)
	struct FVector2D                                   Offset;                                                   // (Parm, IsPlainOldData)
	struct FUIElemLayoutDetail                         ReturnValue;                                              // (Parm, OutParm, ReturnParm)
};

// Function CustomLayout.CustomLayoutBlueprintLibrary.Conv_TypeToAnchors
struct UCustomLayoutBlueprintLibrary_Conv_TypeToAnchors_Params
{
	EAnchorsType                                       InType;                                                   // (Parm, ZeroConstructor, IsPlainOldData)
	struct FAnchors                                    ReturnValue;                                              // (Parm, OutParm, ReturnParm)
};

// Function CustomLayout.CustomLayoutBlueprintLibrary.Conv_LayoutDetailToCode
struct UCustomLayoutBlueprintLibrary_Conv_LayoutDetailToCode_Params
{
	struct FUIElemLayoutDetail                         InDetail;                                                 // (ConstParm, Parm, OutParm, ReferenceParm)
	struct FCustomLayoutBlueprintCode                  ReturnValue;                                              // (Parm, OutParm, ReturnParm)
};

// Function CustomLayout.CustomLayoutBlueprintLibrary.Conv_CodeToLayoutDetail
struct UCustomLayoutBlueprintLibrary_Conv_CodeToLayoutDetail_Params
{
	struct FCustomLayoutBlueprintCode                  InCode;                                                   // (ConstParm, Parm, OutParm, ReferenceParm)
	int                                                Type;                                                     // (Parm, ZeroConstructor, IsPlainOldData)
	struct FUIElemLayoutDetail                         ReturnValue;                                              // (Parm, OutParm, ReturnParm)
};

// Function CustomLayout.CustomLayoutBlueprintLibrary.Conv_AnchorsToType
struct UCustomLayoutBlueprintLibrary_Conv_AnchorsToType_Params
{
	struct FAnchors                                    InAnchors;                                                // (ConstParm, Parm, OutParm, ReferenceParm)
	EAnchorsType                                       ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function CustomLayout.CustomLayoutSubsystem.UnregisterCustomPanel
struct UCustomLayoutSubsystem_UnregisterCustomPanel_Params
{
	class UCustomPanel*                                InCustomizePanel;                                         // (Parm, ZeroConstructor, InstancedReference, IsPlainOldData)
};

// Function CustomLayout.CustomLayoutSubsystem.SetScreenPadding
struct UCustomLayoutSubsystem_SetScreenPadding_Params
{
	struct FMargin                                     InOffset;                                                 // (ConstParm, Parm, OutParm, ReferenceParm, IsPlainOldData)
};

// Function CustomLayout.CustomLayoutSubsystem.SetEditMode
struct UCustomLayoutSubsystem_SetEditMode_Params
{
	bool                                               bEnable;                                                  // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function CustomLayout.CustomLayoutSubsystem.RemoveUserSettingSlot
struct UCustomLayoutSubsystem_RemoveUserSettingSlot_Params
{
	class UCustomLayoutUserSetting*                    InUserSetting;                                            // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function CustomLayout.CustomLayoutSubsystem.RegisterCustomPanel
struct UCustomLayoutSubsystem_RegisterCustomPanel_Params
{
	class UCustomPanel*                                InCustomizePanel;                                         // (Parm, ZeroConstructor, InstancedReference, IsPlainOldData)
};

// Function CustomLayout.CustomLayoutSubsystem.InsertUserSettingSlot
struct UCustomLayoutSubsystem_InsertUserSettingSlot_Params
{
	class UCustomLayoutUserSetting*                    InUserSetting;                                            // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                Index;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function CustomLayout.CustomLayoutSubsystem.HandleTouchStatEvent
struct UCustomLayoutSubsystem_HandleTouchStatEvent_Params
{
	struct FTouchStatInfo                              TouchStatInfo;                                            // (ConstParm, Parm, OutParm, ReferenceParm)
};

// Function CustomLayout.CustomLayoutSubsystem.GetUserSettingInSlot
struct UCustomLayoutSubsystem_GetUserSettingInSlot_Params
{
	struct FString                                     Name;                                                     // (Parm, ZeroConstructor)
	class UCustomLayoutUserSetting*                    ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function CustomLayout.CustomLayoutSubsystem.GetRegisteredPanel
struct UCustomLayoutSubsystem_GetRegisteredPanel_Params
{
	int                                                InCustomType;                                             // (Parm, ZeroConstructor, IsPlainOldData)
	class UCustomPanel*                                ReturnValue;                                              // (ExportObject, Parm, OutParm, ZeroConstructor, ReturnParm, InstancedReference, IsPlainOldData)
};

// Function CustomLayout.CustomLayoutSubsystem.FlushRegisteredPanelMap
struct UCustomLayoutSubsystem_FlushRegisteredPanelMap_Params
{
};

// Function CustomLayout.CustomLayoutSubsystem.FindLayoutDetail
struct UCustomLayoutSubsystem_FindLayoutDetail_Params
{
	int                                                InCustomType;                                             // (Parm, ZeroConstructor, IsPlainOldData)
	struct FUIElemLayoutDetail                         OutDetail;                                                // (Parm, OutParm)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function CustomLayout.CustomLayoutSubsystem.ClearUserSettingSlots
struct UCustomLayoutSubsystem_ClearUserSettingSlots_Params
{
};

// Function CustomLayout.CustomLayoutSubsystem.ClearTouchStatArray
struct UCustomLayoutSubsystem_ClearTouchStatArray_Params
{
};

// Function CustomLayout.CustomLayoutSubsystem.ClearRegisteredPanelMap
struct UCustomLayoutSubsystem_ClearRegisteredPanelMap_Params
{
};

// Function CustomLayout.CustomLayoutSubsystem.BroadcastCustomLayoutChange
struct UCustomLayoutSubsystem_BroadcastCustomLayoutChange_Params
{
	TArray<int>                                        InCustomTypeList;                                         // (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm)
};

// Function CustomLayout.CustomLayoutSubsystem.AddUserSettingSlot
struct UCustomLayoutSubsystem_AddUserSettingSlot_Params
{
	class UCustomLayoutUserSetting*                    InUserSetting;                                            // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function CustomLayout.CustomLayoutUserSetting.UpdateTimeTag
struct UCustomLayoutUserSetting_UpdateTimeTag_Params
{
};

// Function CustomLayout.CustomLayoutUserSetting.SetTimeTagFromUnixTimestamp
struct UCustomLayoutUserSetting_SetTimeTagFromUnixTimestamp_Params
{
	int64_t                                            InUnixTimestamp;                                          // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
};

// Function CustomLayout.CustomLayoutUserSetting.SetDataByLayoutDetail
struct UCustomLayoutUserSetting_SetDataByLayoutDetail_Params
{
	int                                                InCustomType;                                             // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
	struct FUIElemLayoutDetail                         InData;                                                   // (ConstParm, Parm, OutParm, ReferenceParm)
};

// Function CustomLayout.CustomLayoutUserSetting.RemoveData
struct UCustomLayoutUserSetting_RemoveData_Params
{
	int                                                InCustomType;                                             // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
};

// Function CustomLayout.CustomLayoutUserSetting.GetTimeTagAsUnixTimestamp
struct UCustomLayoutUserSetting_GetTimeTagAsUnixTimestamp_Params
{
	int64_t                                            ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function CustomLayout.CustomLayoutUserSetting.GetLayoutCodeCheckSum
struct UCustomLayoutUserSetting_GetLayoutCodeCheckSum_Params
{
	uint64_t                                           ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function CustomLayout.CustomLayoutUserSetting.GetDataAsLayoutDetail
struct UCustomLayoutUserSetting_GetDataAsLayoutDetail_Params
{
	int                                                InCustomType;                                             // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
	struct FUIElemLayoutDetail                         ReturnValue;                                              // (Parm, OutParm, ReturnParm)
};

// Function CustomLayout.CustomLayoutUserSetting.GetCustomTypeList
struct UCustomLayoutUserSetting_GetCustomTypeList_Params
{
	TArray<int>                                        OutKeys;                                                  // (Parm, OutParm, ZeroConstructor)
};

// Function CustomLayout.CustomLayoutUserSetting.Contains
struct UCustomLayoutUserSetting_Contains_Params
{
	int                                                InCustomType;                                             // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function CustomLayout.CustomPanel.UpdateCustomLayout
struct UCustomPanel_UpdateCustomLayout_Params
{
};

// Function CustomLayout.CustomPanel.SetEditable
struct UCustomPanel_SetEditable_Params
{
	bool                                               bEditable;                                                // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function CustomLayout.DynamicCustomIndexer.GetIndexer
struct UDynamicCustomIndexer_GetIndexer_Params
{
	struct FString                                     Path;                                                     // (Parm, ZeroConstructor)
	class UDynamicCustomIndexer*                       ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function CustomLayout.DynamicCustomIndexer.GetDefaultLayoutCode
struct UDynamicCustomIndexer_GetDefaultLayoutCode_Params
{
	int                                                CustomType;                                               // (Parm, ZeroConstructor, IsPlainOldData)
	struct FCustomLayoutBlueprintCode                  ReturnValue;                                              // (Parm, OutParm, ReturnParm)
};

// Function CustomLayout.DynamicCustomIndexer.CreateDynamicCustomWidgets
struct UDynamicCustomIndexer_CreateDynamicCustomWidgets_Params
{
	TArray<int>                                        InCustomTypeList;                                         // (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm)
	TMap<int, class UCustomizePanel*>                  CustomPanelMap;                                           // (Parm, OutParm, ZeroConstructor)
	class UCanvasPanel*                                Container;                                                // (Parm, ZeroConstructor, InstancedReference, IsPlainOldData)
	bool                                               bIgnoreDPIScale;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	TMap<int, class UCustomizePanel*>                  ReturnValue;                                              // (ExportObject, Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function CustomLayout.PinchDragWidget.SetPinchEnabled
struct UPinchDragWidget_SetPinchEnabled_Params
{
	bool                                               bEnabled;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function CustomLayout.PinchDragWidget.SetDragEnabled
struct UPinchDragWidget_SetDragEnabled_Params
{
	bool                                               bEnabled;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function CustomLayout.PinchDragWidget.ScreenDeltaToParentLocal
struct UPinchDragWidget_ScreenDeltaToParentLocal_Params
{
	class UWidget*                                     Widget;                                                   // (ConstParm, Parm, ZeroConstructor, InstancedReference, IsPlainOldData)
	struct FVector2D                                   ScreenDelta;                                              // (ConstParm, Parm, OutParm, ReferenceParm, IsPlainOldData)
	struct FVector2D                                   ReturnValue;                                              // (Parm, OutParm, ReturnParm, IsPlainOldData)
};

// Function CustomLayout.PinchDragWidget.IsPinchEnabled
struct UPinchDragWidget_IsPinchEnabled_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function CustomLayout.PinchDragWidget.IsFirstPointIndex
struct UPinchDragWidget_IsFirstPointIndex_Params
{
	struct FPointerEvent                               InPointerEvent;                                           // (ConstParm, Parm, OutParm, ReferenceParm)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function CustomLayout.PinchDragWidget.IsDragEnabled
struct UPinchDragWidget_IsDragEnabled_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function CustomLayout.SettingCustomPanel.SetSelectedImageOriginEffect
struct USettingCustomPanel_SetSelectedImageOriginEffect_Params
{
};

// Function CustomLayout.SettingCustomPanel.SetSelectedImageFlashEffect
struct USettingCustomPanel_SetSelectedImageFlashEffect_Params
{
};

// Function CustomLayout.SettingCustomPanel.SetDisplayState
struct USettingCustomPanel_SetDisplayState_Params
{
	ESCPDisplayState                                   State;                                                    // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
};

// Function CustomLayout.SettingCustomPanel.OnTouchPreview
struct USettingCustomPanel_OnTouchPreview_Params
{
};

// Function CustomLayout.SettingCustomPanel.IsSquareFlashEffectAssetName
struct USettingCustomPanel_IsSquareFlashEffectAssetName_Params
{
	struct FString                                     InAssetName;                                              // (Parm, ZeroConstructor)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function CustomLayout.SettingCustomPanel.IsCircleFlashEffectAssetName
struct USettingCustomPanel_IsCircleFlashEffectAssetName_Params
{
	struct FString                                     InAssetName;                                              // (Parm, ZeroConstructor)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function CustomLayout.SettingCustomPanel.GetWidgetByType
struct USettingCustomPanel_GetWidgetByType_Params
{
	class UWidget*                                     RootWidget;                                               // (Parm, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UClass*                                      WidgetType;                                               // (Parm, ZeroConstructor, IsPlainOldData)
	class UWidget*                                     ReturnValue;                                              // (ExportObject, Parm, OutParm, ZeroConstructor, ReturnParm, InstancedReference, IsPlainOldData)
};

// Function CustomLayout.SettingCustomPanel.GetSelectedImage
struct USettingCustomPanel_GetSelectedImage_Params
{
	class UImage*                                      ReturnValue;                                              // (ExportObject, Parm, OutParm, ZeroConstructor, ReturnParm, InstancedReference, IsPlainOldData)
};

// Function CustomLayout.SettingCustomPanel.GetParentWidget
struct USettingCustomPanel_GetParentWidget_Params
{
	class UWidget*                                     ReturnValue;                                              // (ExportObject, Parm, OutParm, ZeroConstructor, ReturnParm, InstancedReference, IsPlainOldData)
};

// Function CustomLayout.SettingCustomPanel.GetNamedWidgetFromOwner
struct USettingCustomPanel_GetNamedWidgetFromOwner_Params
{
	struct FString                                     Prefix;                                                   // (Parm, ZeroConstructor)
	class UWidget*                                     ReturnValue;                                              // (ExportObject, Parm, OutParm, ZeroConstructor, ReturnParm, InstancedReference, IsPlainOldData)
};

// Function CustomLayout.SettingCustomPanel.GetInvalidImage
struct USettingCustomPanel_GetInvalidImage_Params
{
	class UImage*                                      ReturnValue;                                              // (ExportObject, Parm, OutParm, ZeroConstructor, ReturnParm, InstancedReference, IsPlainOldData)
};

// Function CustomLayout.SettingCustomPanel.GetCenterPositionInScreenSpace
struct USettingCustomPanel_GetCenterPositionInScreenSpace_Params
{
	class UWidget*                                     FullScreenWidget;                                         // (Parm, ZeroConstructor, InstancedReference, IsPlainOldData)
	struct FVector2D                                   ReturnValue;                                              // (Parm, OutParm, ReturnParm, IsPlainOldData)
};

// Function CustomLayout.SettingCustomPanel.FlashHighlight
struct USettingCustomPanel_FlashHighlight_Params
{
	float                                              Seconds;                                                  // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
};

// Function CustomLayout.SettingCustomPanel.ConvertCenterPositionFromScreenSpace
struct USettingCustomPanel_ConvertCenterPositionFromScreenSpace_Params
{
	class UWidget*                                     FullScreenWidget;                                         // (Parm, ZeroConstructor, InstancedReference, IsPlainOldData)
	struct FVector2D                                   SSPosition;                                               // (ConstParm, Parm, OutParm, ReferenceParm, IsPlainOldData)
	struct FVector2D                                   ReturnValue;                                              // (Parm, OutParm, ReturnParm, IsPlainOldData)
};

}

