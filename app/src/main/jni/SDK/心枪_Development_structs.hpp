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
// ScriptStruct Development.PropertyItemData
// 0x0028
struct FPropertyItemData
{
	struct FString                                     PropertyName;                                             // 0x0000(0x0010) (ZeroConstructor)
	class UEditableTextBox*                            EditableTextBox;                                          // 0x0010(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UWidget*                                     ContainerWidget;                                          // 0x0018(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UButton*                                     NameButton;                                               // 0x0020(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
};

}

