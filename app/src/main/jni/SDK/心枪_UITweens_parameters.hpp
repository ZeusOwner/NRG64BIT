#pragma once

/*
// ------------------------------------------------
DUMP SDK BY @Sanji1_Owner V4.4.0

TELEGRAM CHANNEL @NIKA_SOURCE_MODS

All rights reserved by the NIKA TEAM AND INCLUDED TEAM

@INCLUDED_SO
// ------------------------------------------------
*/

#include "../SDK.hpp"

namespace SDK
{
//-------------------------------------------------
//Parameters
//-------------------------------------------------
// Function UITweens.TweenManager.TweenScale
struct UTweenManager_TweenScale_Params
{
	class UWidget*                                     Widget;                                                   // (Parm, ZeroConstructor, InstancedReference, IsPlainOldData)
	struct FVector2D                                   From;                                                     // (Parm, IsPlainOldData)
	struct FVector2D                                   To;                                                       // (Parm, IsPlainOldData)
	float                                              Timespan;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                Type;                                                     // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function UITweens.TweenManager.TweenPosition
struct UTweenManager_TweenPosition_Params
{
	class UWidget*                                     Widget;                                                   // (Parm, ZeroConstructor, InstancedReference, IsPlainOldData)
	struct FVector2D                                   From;                                                     // (Parm, IsPlainOldData)
	struct FVector2D                                   To;                                                       // (Parm, IsPlainOldData)
	float                                              Timespan;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                Type;                                                     // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function UITweens.TweenManager.TweenAlpha
struct UTweenManager_TweenAlpha_Params
{
	class UWidget*                                     Widget;                                                   // (Parm, ZeroConstructor, InstancedReference, IsPlainOldData)
	float                                              From;                                                     // (Parm, ZeroConstructor, IsPlainOldData)
	float                                              To;                                                       // (Parm, ZeroConstructor, IsPlainOldData)
	float                                              Timespan;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                Type;                                                     // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function UITweens.TweenManager.Tick
struct UTweenManager_Tick_Params
{
	float                                              DeltaTime;                                                // (Parm, ZeroConstructor, IsPlainOldData)
};

}

