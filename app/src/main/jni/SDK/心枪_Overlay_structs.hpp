#pragma once

/*
// ------------------------------------------------
DUMP SDK BY @Sanji1_Owner V4.4.0

TELEGRAM CHANNEL @NIKA_SOURCE_MODS

All rights reserved by the NIKA TEAM AND INCLUDED TEAM

@INCLUDED_SO
// ------------------------------------------------
*/

namespace SDK
{
//-------------------------------------------------
//Script Structs
//-------------------------------------------------
// ScriptStruct Overlay.OverlayItem
// 0x0028
struct FOverlayItem
{
	struct FTimespan                                   StartTime;                                                // 0x0000(0x0008) (Edit, BlueprintVisible)
	struct FTimespan                                   EndTime;                                                  // 0x0008(0x0008) (Edit, BlueprintVisible)
	struct FString                                     Text;                                                     // 0x0010(0x0010) (Edit, BlueprintVisible, ZeroConstructor)
	struct FVector2D                                   Position;                                                 // 0x0020(0x0008) (Edit, BlueprintVisible, IsPlainOldData)
};

}

