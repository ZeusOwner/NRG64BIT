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
// Function CreativeLua.CreativeBridgeLuaVM.UGCLuaError
struct UCreativeBridgeLuaVM_UGCLuaError_Params
{
	int                                                ErrCode;                                                  // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function CreativeLua.CreativeBridgeLuaVM.SetUGCSuspendStateFix
struct UCreativeBridgeLuaVM_SetUGCSuspendStateFix_Params
{
	bool                                               bEnable;                                                  // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function CreativeLua.CreativeBridgeLuaVM.RegisterSluaCallUgcluaEventHandler
struct UCreativeBridgeLuaVM_RegisterSluaCallUgcluaEventHandler_Params
{
};

// Function CreativeLua.CreativeBridgeLuaVM.PostInit
struct UCreativeBridgeLuaVM_PostInit_Params
{
};

// Function CreativeLua.CreativeBridgeLuaVM.GetUGCSuspendStateFix
struct UCreativeBridgeLuaVM_GetUGCSuspendStateFix_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function CreativeLua.CreativeEnvLuaVMFactory.CreateCreativeEnvLuaVM
struct UCreativeEnvLuaVMFactory_CreateCreativeEnvLuaVM_Params
{
	struct FString                                     InLuaFilePath;                                            // (Parm, ZeroConstructor)
	class UObject*                                     WorldContextObject;                                       // (Parm, ZeroConstructor, IsPlainOldData)
	class UCreativeEnvLuaVM*                           ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

}

