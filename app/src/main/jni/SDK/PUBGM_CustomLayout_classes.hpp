#pragma once

// PUBG MOBILE (4.5.0 -- 64bit Beta) SDK Generate By @ByDwoz
// Telegram Channel:- @XelahotOfficial
// Generate on Wed Jul  8 13:37:46 2026
 
namespace SDK
{
//---------------------❣︎➪ 𝗕𝗬𝗗𝗪𝗢𝗭 𝗗𝗘𝗩𝗘𝗟𝗢𝗣𝗘𝗥༆✈︎🇪🇬---------------------------
//Classes
//---------------------❣︎➪𝗕𝗬𝗗𝗪𝗢𝗭 𝗗𝗘𝗩𝗘𝗟𝗢𝗣𝗘𝗥༆✈︎🇪🇬---------------------------

// Class CustomLayout.CustomizePanel
// 0x0038 (0x0168 - 0x0130)
class UCustomizePanel : public UCanvasPanel
{
public:
	struct FScriptMulticastDelegate                    OnCustomLayoutChangeEvent;                                // 0x0130(0x0010) (Edit, ZeroConstructor, DisableEditOnTemplate, InstancedReference)
	struct FMargin                                     DetectMargin;                                             // 0x0140(0x0010) (Edit, BlueprintVisible, DisableEditOnTemplate, IsPlainOldData)
	struct FCustomLayoutBlueprintCode                  DefaultLayoutCode;                                        // 0x0150(0x0008) (Transient)
	int                                                CustomType;                                               // 0x0158(0x0004) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, IsPlainOldData)
	float                                              Opacity;                                                  // 0x015C(0x0004) (ZeroConstructor, Transient, IsPlainOldData)
	bool                                               bInvalid;                                                 // 0x0160(0x0001) (BlueprintVisible, ZeroConstructor, Transient, IsPlainOldData)
	bool                                               bInterceptChildInput;                                     // 0x0161(0x0001) (ZeroConstructor, Transient, IsPlainOldData)
	bool                                               bMovable;                                                 // 0x0162(0x0001) (ZeroConstructor, Transient, IsPlainOldData)
	unsigned char                                      UnknownData00[0x5];                                       // 0x0163(0x0005) MISSED OFFSET

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class CustomLayout.CustomizePanel");
		return pStaticClass;
	}


	void SetScale(float Scale);
	void SetPosition(const struct FVector2D& Position);
	void SetOpacityWithClamp(float InOpacity, float MinOpacity, float MaxOpacity);
	void SetOpacity(float InOpacity);
	void SetMovable(bool bInMovable);
	void SetMaxScale(float Scale);
	void SetInvalid(bool Invalid);
	void SetInterceptChildInput(bool bInIntercept);
	void SetDrawMargin(bool bDraw);
	void SetDetectMargin(const struct FMargin& InMargin);
	void SetDesireScale(float Scale);
	void SetDesirePosition(const struct FVector2D& Position);
	void SetDefaultLayoutCode(const struct FCustomLayoutBlueprintCode& InCode);
	void SetCustomType(int NewType);
	void RestoreInBound();
	void ResetMaxScale();
	bool IsOutOfBound(float InvisibleCheckOffset);
	void InitDefaultLayoutData();
	float GetScale();
	struct FVector2D GetPosition();
	float GetOpacity();
	bool GetMovable();
	float GetMaxScale();
	struct FUIElemLayoutDetail GetLayoutData();
	struct FCustomLayoutBlueprintCode GetLayoutCode();
	bool GetInvalid();
	struct FUIElemLayoutDetail GetDefaultLayoutData();
	int GetCustomType();
	struct FVector2D ClampPosition(const struct FVector2D& DesiredPos);
	void ApplyLayoutData(const struct FUIElemLayoutDetail& LayoutDetail);
	void ApplyLayoutCode(const struct FCustomLayoutBlueprintCode& InCode);
	void ApplyDefaultLayout();
};


// Class CustomLayout.CustomLayoutBlueprintLibrary
// 0x0000 (0x0028 - 0x0028)
class UCustomLayoutBlueprintLibrary : public UBlueprintFunctionLibrary
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class CustomLayout.CustomLayoutBlueprintLibrary");
		return pStaticClass;
	}


	static struct FUIElemLayoutDetail MakeLayoutDetail(int Type, EAnchorsType AnchorType, const struct FVector2D& Offset);
	static struct FAnchors Conv_TypeToAnchors(EAnchorsType InType);
	static struct FCustomLayoutBlueprintCode Conv_LayoutDetailToCode(const struct FUIElemLayoutDetail& InDetail);
	static struct FUIElemLayoutDetail Conv_CodeToLayoutDetail(const struct FCustomLayoutBlueprintCode& InCode, int Type);
	static EAnchorsType Conv_AnchorsToType(const struct FAnchors& InAnchors);
};


// Class CustomLayout.CustomLayoutSubsystem
// 0x0088 (0x00B8 - 0x0030)
class UCustomLayoutSubsystem : public UGameInstanceSubsystem
{
public:
	TArray<struct FTouchStatInfo>                      TouchStatArray;                                           // 0x0030(0x0010) (ZeroConstructor, Transient)
	TArray<class UCustomLayoutUserSetting*>            UserSettingSlots;                                         // 0x0040(0x0010) (BlueprintVisible, ZeroConstructor, Transient)
	struct FScriptMulticastDelegate                    OnPanelTouchPreview;                                      // 0x0050(0x0010) (BlueprintVisible, ZeroConstructor, InstancedReference)
	unsigned char                                      UnknownData00[0x58];                                      // 0x0060(0x0058) MISSED OFFSET

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class CustomLayout.CustomLayoutSubsystem");
		return pStaticClass;
	}


	void UnregisterCustomPanel(class UCustomPanel* InCustomizePanel);
	static void SetScreenPadding(const struct FMargin& InOffset);
	void SetEditMode(bool bEnable);
	void RemoveUserSettingSlot(class UCustomLayoutUserSetting* InUserSetting);
	void RegisterCustomPanel(class UCustomPanel* InCustomizePanel);
	void InsertUserSettingSlot(class UCustomLayoutUserSetting* InUserSetting, int Index);
	void HandleTouchStatEvent(const struct FTouchStatInfo& TouchStatInfo);
	class UCustomLayoutUserSetting* GetUserSettingInSlot(const struct FString& Name);
	class UCustomPanel* GetRegisteredPanel(int InCustomType);
	void FlushRegisteredPanelMap();
	bool FindLayoutDetail(int InCustomType, struct FUIElemLayoutDetail* OutDetail);
	void ClearUserSettingSlots();
	void ClearTouchStatArray();
	void ClearRegisteredPanelMap();
	void BroadcastCustomLayoutChange(TArray<int> InCustomTypeList);
	void AddUserSettingSlot(class UCustomLayoutUserSetting* InUserSetting);
};


// Class CustomLayout.CustomLayoutUserSetting
// 0x0078 (0x00A0 - 0x0028)
class UCustomLayoutUserSetting : public USaveGame
{
public:
	int                                                CodecVersion;                                             // 0x0028(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	int                                                ViewportWidth;                                            // 0x002C(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	int                                                ViewportHeight;                                           // 0x0030(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              ViewportScale;                                            // 0x0034(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	struct FDateTime                                   TimeTag;                                                  // 0x0038(0x0008) (BlueprintVisible)
	struct FString                                     SaveSlotName;                                             // 0x0040(0x0010) (BlueprintVisible, ZeroConstructor)
	TMap<int, uint64_t>                                LayoutCodeMap;                                            // 0x0050(0x0050) (ZeroConstructor)

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class CustomLayout.CustomLayoutUserSetting");
		return pStaticClass;
	}


	void UpdateTimeTag();
	void SetTimeTagFromUnixTimestamp(int64_t InUnixTimestamp);
	void SetDataByLayoutDetail(int InCustomType, const struct FUIElemLayoutDetail& InData);
	void RemoveData(int InCustomType);
	int64_t GetTimeTagAsUnixTimestamp();
	uint64_t GetLayoutCodeCheckSum();
	struct FUIElemLayoutDetail GetDataAsLayoutDetail(int InCustomType);
	void GetCustomTypeList(TArray<int>* OutKeys);
	bool Contains(int InCustomType);
};


// Class CustomLayout.CustomPanel
// 0x0008 (0x0170 - 0x0168)
class UCustomPanel : public UCustomizePanel
{
public:
	unsigned char                                      UnknownData00[0x8];                                       // 0x0168(0x0008) MISSED OFFSET

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class CustomLayout.CustomPanel");
		return pStaticClass;
	}


	void UpdateCustomLayout();
	void SetEditable(bool bEditable);
};


// Class CustomLayout.DynamicCustomIndexer
// 0x00A0 (0x00D0 - 0x0030)
class UDynamicCustomIndexer : public UDataAsset
{
public:
	TMap<struct FString, struct FDynamicCustomInfo>    InfoMap;                                                  // 0x0030(0x0050) (Edit, ZeroConstructor)
	TMap<int, struct FAnchorData>                      DefaultLayoutData;                                        // 0x0080(0x0050) (Edit, ZeroConstructor)

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class CustomLayout.DynamicCustomIndexer");
		return pStaticClass;
	}


	static class UDynamicCustomIndexer* GetIndexer(const struct FString& Path);
	struct FCustomLayoutBlueprintCode GetDefaultLayoutCode(int CustomType);
	TMap<int, class UCustomizePanel*> CreateDynamicCustomWidgets(TArray<int> InCustomTypeList, class UCanvasPanel* Container, bool bIgnoreDPIScale, TMap<int, class UCustomizePanel*>* CustomPanelMap);
};


// Class CustomLayout.PinchDragWidget
// 0x0048 (0x02A8 - 0x0260)
class UPinchDragWidget : public UUserWidget
{
public:
	struct FScriptDelegate                             OnDrag;                                                   // 0x0260(0x0010) (BlueprintVisible, ZeroConstructor, InstancedReference)
	struct FScriptDelegate                             OnPinch;                                                  // 0x0270(0x0010) (BlueprintVisible, ZeroConstructor, InstancedReference)
	struct FScriptDelegate                             OnRelease;                                                // 0x0280(0x0010) (BlueprintVisible, ZeroConstructor, InstancedReference)
	unsigned char                                      UnknownData00[0x18];                                      // 0x0290(0x0018) MISSED OFFSET

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class CustomLayout.PinchDragWidget");
		return pStaticClass;
	}


	void SetPinchEnabled(bool bEnabled);
	void SetDragEnabled(bool bEnabled);
	static struct FVector2D ScreenDeltaToParentLocal(class UWidget* Widget, const struct FVector2D& ScreenDelta);
	bool IsPinchEnabled();
	bool IsFirstPointIndex(const struct FPointerEvent& InPointerEvent);
	bool IsDragEnabled();
};


// Class CustomLayout.SettingCustomPanel
// 0x0078 (0x01E0 - 0x0168)
class USettingCustomPanel : public UCustomizePanel
{
public:
	ESCPDisplayState                                   DisplayState;                                             // 0x0168(0x0001) (ZeroConstructor, Transient, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0169(0x0007) MISSED OFFSET
	class UMaterialInterface*                          SelectedImageCircularFlashEffectMaterial;                 // 0x0170(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UMaterialInterface*                          SelectedImageSquareFlashEffectMaterial;                   // 0x0178(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData01[0x10];                                      // 0x0180(0x0010) MISSED OFFSET
	TMap<struct FString, TWeakObjectPtr<class UWidget>> WidgetPtrMap;                                             // 0x0190(0x0050) (ExportObject, ZeroConstructor, Transient)

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class CustomLayout.SettingCustomPanel");
		return pStaticClass;
	}


	void SetSelectedImageOriginEffect();
	void SetSelectedImageFlashEffect();
	void SetDisplayState(ESCPDisplayState State);
	void OnTouchPreview();
	bool IsSquareFlashEffectAssetName(const struct FString& InAssetName);
	bool IsCircleFlashEffectAssetName(const struct FString& InAssetName);
	class UWidget* GetWidgetByType(class UWidget* RootWidget, class UClass* WidgetType);
	class UImage* GetSelectedImage();
	class UWidget* GetParentWidget();
	class UWidget* GetNamedWidgetFromOwner(const struct FString& Prefix);
	class UImage* GetInvalidImage();
	struct FVector2D GetCenterPositionInScreenSpace(class UWidget* FullScreenWidget);
	void FlashHighlight(float Seconds);
	struct FVector2D ConvertCenterPositionFromScreenSpace(class UWidget* FullScreenWidget, const struct FVector2D& SSPosition);
};


}

