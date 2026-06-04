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
// Function iTOP.FBHelper.DelayToSetAutoInitFacebookLog
struct UFBHelper_DelayToSetAutoInitFacebookLog_Params
{
	bool                                               IsAutoInit;                                               // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function iTOP.FBHelper.DelayToInitFacebookSDK
struct UFBHelper_DelayToInitFacebookSDK_Params
{
	bool                                               IsAutoInit;                                               // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               WithLaunchOption;                                         // (Parm, ZeroConstructor, IsPlainOldData)
};

}

