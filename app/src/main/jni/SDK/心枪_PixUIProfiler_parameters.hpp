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
// Function PixUIProfiler.PxProfilerMgr.StartProfiler
struct UPxProfilerMgr_StartProfiler_Params
{
};

// Function PixUIProfiler.PxProfilerMgr.PxProfilerCapabilitySwitch
struct UPxProfilerMgr_PxProfilerCapabilitySwitch_Params
{
	EPxProfilerCapability                              EPxProfilerCapability;                                    // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
	bool                                               bOpen;                                                    // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
};

// Function PixUIProfiler.PxProfilerMgr.Print
struct UPxProfilerMgr_Print_Params
{
};

// Function PixUIProfiler.PxProfilerMgr.GetPxProfilerCapability
struct UPxProfilerMgr_GetPxProfilerCapability_Params
{
	EPxProfilerCapability                              EPxProfilerCapability;                                    // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function PixUIProfiler.PxProfilerMgr.EndProfiler
struct UPxProfilerMgr_EndProfiler_Params
{
};

// Function PixUIProfiler.PxProfilerMgr.Check
struct UPxProfilerMgr_Check_Params
{
};

}

