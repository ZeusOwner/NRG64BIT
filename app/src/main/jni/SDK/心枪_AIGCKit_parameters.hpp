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
// Function AIGCKit.AIGCAnimInstance.GetCurrentFrameIndex
struct UAIGCAnimInstance_GetCurrentFrameIndex_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function AIGCKit.AIGCKitFunctionLibrary.GetAnimData
struct UAIGCKitFunctionLibrary_GetAnimData_Params
{
	TArray<unsigned char>                              CompressData;                                             // (Parm, OutParm, ZeroConstructor)
	int                                                FrameRate;                                                // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                FrameNum;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
	struct FSkeletonNodeInfo                           SkeletonNodeInfo;                                         // (ConstParm, Parm, OutParm, ReferenceParm)
	class UAIGCAnimData*                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function AIGCKit.AIGCKitFunctionLibrary.DecompressBone
struct UAIGCKitFunctionLibrary_DecompressBone_Params
{
	int                                                TrackIndex;                                               // (Parm, ZeroConstructor, IsPlainOldData)
	struct FTransform                                  OutAtom;                                                  // (Parm, OutParm, IsPlainOldData)
	TArray<unsigned char>                              RawAnimData;                                              // (Parm, OutParm, ZeroConstructor)
	float                                              Time;                                                     // (Parm, ZeroConstructor, IsPlainOldData)
	float                                              RelativePos;                                              // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function AIGCKit.AIGCKitFunctionLibrary.DecompressAnimData
struct UAIGCKitFunctionLibrary_DecompressAnimData_Params
{
	class UAIGCAnimData*                               OutAnimData;                                              // (Parm, ZeroConstructor, IsPlainOldData)
	TArray<unsigned char>                              RawAnimData;                                              // (Parm, OutParm, ZeroConstructor)
	int                                                FrameNum;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
	float                                              TargetFramerate;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	struct FSkeletonNodeInfo                           SkeletonNodeInfo;                                         // (ConstParm, Parm, OutParm, ReferenceParm)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

}

