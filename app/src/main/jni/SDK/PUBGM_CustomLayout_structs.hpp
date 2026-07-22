#pragma once

// PUBG MOBILE (4.5.0 -- 64bit Beta) SDK Generate By @ByDwoz
// Telegram Channel:- @XelahotOfficial
// Generate on Wed Jul  8 13:37:46 2026
 
namespace SDK
{
//---------------------❣︎➪ 𝗕𝗬𝗗𝗪𝗢𝗭 𝗗𝗘𝗩𝗘𝗟𝗢𝗣𝗘𝗥༆✈︎🇪🇬---------------------------
//Enums
//---------------------❣︎➪𝗕𝗬𝗗𝗪𝗢𝗭 𝗗𝗘𝗩𝗘𝗟𝗢𝗣𝗘𝗥༆✈︎🇪🇬---------------------------

// Enum CustomLayout.EAnchorsType
enum class EAnchorsType : uint8_t
{
	EAnchorsType__TopLeft          = 0,
	EAnchorsType__TopCenter        = 1,
	EAnchorsType__TopRight         = 2,
	EAnchorsType__MidLeft          = 3,
	EAnchorsType__MidCenter        = 4,
	EAnchorsType__MidRight         = 5,
	EAnchorsType__BottomLeft       = 6,
	EAnchorsType__BottomCenter     = 7,
	EAnchorsType__BottomRight      = 8,
	EAnchorsType__Other            = 9,
	EAnchorsType__EAnchorsType_MAX = 10
};


// Enum CustomLayout.ESCPDisplayState
enum class ESCPDisplayState : uint8_t
{
	ESCPDisplayState__Foreground   = 0,
	ESCPDisplayState__Background   = 1,
	ESCPDisplayState__Hidden       = 2,
	ESCPDisplayState__ESCPDisplayState_MAX = 3
};


// Enum CustomLayout.ETouchEventType
enum class ETouchEventType : uint8_t
{
	ETouchEventType__Undefined     = 0,
	ETouchEventType__TouchStart    = 1,
	ETouchEventType__TouchEnd      = 2,
	ETouchEventType__TouchMove     = 3,
	ETouchEventType__ETouchEventType_MAX = 4
};



//---------------------❣︎➪ 𝗕𝗬𝗗𝗪𝗢𝗭 𝗗𝗘𝗩𝗘𝗟𝗢𝗣𝗘𝗥༆✈︎🇪🇬---------------------------
//Script Structs
//---------------------❣︎➪𝗕𝗬𝗗𝗪𝗢𝗭 𝗗𝗘𝗩𝗘𝗟𝗢𝗣𝗘𝗥༆✈︎🇪🇬---------------------------

// ScriptStruct CustomLayout.CustomLayoutBlueprintCode
// 0x0008
struct FCustomLayoutBlueprintCode
{
	unsigned char                                      UnknownData00[0x8];                                       // 0x0000(0x0008) MISSED OFFSET
};

// ScriptStruct CustomLayout.UIElemLayoutDetail
// 0x0028
struct FUIElemLayoutDetail
{
	int                                                Type;                                                     // 0x0000(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              Opacity;                                                  // 0x0004(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              Scale;                                                    // 0x0008(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	struct FAnchors                                    AnchorType;                                               // 0x000C(0x0010) (Edit, BlueprintVisible)
	struct FVector2D                                   RelativePos;                                              // 0x001C(0x0008) (Edit, BlueprintVisible, IsPlainOldData)
	bool                                               Invalid;                                                  // 0x0024(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0025(0x0003) MISSED OFFSET
};

// ScriptStruct CustomLayout.TouchStatInfo
// 0x0008
struct FTouchStatInfo
{
	uint16_t                                           CustomTypeShort;                                          // 0x0000(0x0002) (ZeroConstructor, IsPlainOldData)
	ETouchEventType                                    EventType;                                                // 0x0002(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x1];                                       // 0x0003(0x0001) MISSED OFFSET
	uint16_t                                           ScreenSpaceX;                                             // 0x0004(0x0002) (ZeroConstructor, IsPlainOldData)
	uint16_t                                           ScreenSpaceY;                                             // 0x0006(0x0002) (ZeroConstructor, IsPlainOldData)
};

// ScriptStruct CustomLayout.DynamicCustomInfo
// 0x0018
struct FDynamicCustomInfo
{
	class UClass*                                      DynamicCustomAsset;                                       // 0x0000(0x0008) (Edit, ZeroConstructor, IsPlainOldData)
	TArray<int>                                        CustomTypes;                                              // 0x0008(0x0010) (Edit, ZeroConstructor)
};

// ScriptStruct CustomLayout.DynamicCustomConfig
// 0x0002
struct FDynamicCustomConfig
{
	bool                                               bIsShowInLobby;                                           // 0x0000(0x0001) (Edit, ZeroConstructor, DisableEditOnTemplate, IsPlainOldData)
	bool                                               bIgnoreDPIScale;                                          // 0x0001(0x0001) (Edit, ZeroConstructor, DisableEditOnTemplate, IsPlainOldData)
};

}

