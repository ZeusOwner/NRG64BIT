#pragma once

// PUBG MOBILE (4.5.0 -- 64bit Beta) SDK Generate By @ByDwoz
// Telegram Channel:- @XelahotOfficial
// Generate on Wed Jul  8 13:37:47 2026
 
#include "../SDK.hpp"

namespace SDK
{
//---------------------❣︎➪ 𝗕𝗬𝗗𝗪𝗢𝗭 𝗗𝗘𝗩𝗘𝗟𝗢𝗣𝗘𝗥༆✈︎🇪🇬---------------------------
//Parameters
//---------------------❣︎➪𝗕𝗬𝗗𝗪𝗢𝗭 𝗗𝗘𝗩𝗘𝗟𝗢𝗣𝗘𝗥༆✈︎🇪🇬---------------------------

// Function WebCameraFeed.WebCameraWidget.UnLockScreenOrientation
struct UWebCameraWidget_UnLockScreenOrientation_Params
{
};

// Function WebCameraFeed.WebCameraWidget.SwitchFrontAndBackCamera
struct UWebCameraWidget_SwitchFrontAndBackCamera_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function WebCameraFeed.WebCameraWidget.SetDeviceId
struct UWebCameraWidget_SetDeviceId_Params
{
	int                                                ID;                                                       // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function WebCameraFeed.WebCameraWidget.SetColorAndOpacity
struct UWebCameraWidget_SetColorAndOpacity_Params
{
	struct FLinearColor                                InColorAndOpacity;                                        // (Parm, IsPlainOldData)
};

// Function WebCameraFeed.WebCameraWidget.SaveAsImage
struct UWebCameraWidget_SaveAsImage_Params
{
	struct FString                                     Filename;                                                 // (Parm, ZeroConstructor)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function WebCameraFeed.WebCameraWidget.ReleaseVideoGrabber
struct UWebCameraWidget_ReleaseVideoGrabber_Params
{
};

// Function WebCameraFeed.WebCameraWidget.LockScreenOrientation
struct UWebCameraWidget_LockScreenOrientation_Params
{
};

// Function WebCameraFeed.WebCameraWidget.InitVideoGrabber
struct UWebCameraWidget_InitVideoGrabber_Params
{
};

// Function WebCameraFeed.WebCameraWidget.GetFrontCameraId
struct UWebCameraWidget_GetFrontCameraId_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function WebCameraFeed.WebCameraWidget.GetBackCameraId
struct UWebCameraWidget_GetBackCameraId_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

}

