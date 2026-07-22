#pragma once

// PUBG MOBILE (4.5.0 -- 64bit Beta) SDK Generate By @ByDwoz
// Telegram Channel:- @XelahotOfficial
// Generate on Wed Jul  8 13:37:46 2026
 
#include "../SDK.hpp"

namespace SDK
{
//---------------------❣︎➪ 𝗕𝗬𝗗𝗪𝗢𝗭 𝗗𝗘𝗩𝗘𝗟𝗢𝗣𝗘𝗥༆✈︎🇪🇬---------------------------
//Parameters
//---------------------❣︎➪𝗕𝗬𝗗𝗪𝗢𝗭 𝗗𝗘𝗩𝗘𝗟𝗢𝗣𝗘𝗥༆✈︎🇪🇬---------------------------

// Function AWSHelper.AWSHelperBlueprintLibrary.UploadFile
struct UAWSHelperBlueprintLibrary_UploadFile_Params
{
	class UAWSHelper*                                  CosHelper;                                                // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     FromFilePath;                                             // (Parm, ZeroConstructor)
	struct FString                                     ToURL;                                                    // (Parm, ZeroConstructor)
	struct FString                                     NoneMatchHeader;                                          // (Parm, ZeroConstructor)
	struct FScriptDelegate                             OnComplete;                                               // (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm)
	struct FScriptDelegate                             OnProgress;                                               // (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm)
};

// Function AWSHelper.AWSHelperBlueprintLibrary.UploadBinary
struct UAWSHelperBlueprintLibrary_UploadBinary_Params
{
	class UAWSHelper*                                  CosHelper;                                                // (Parm, ZeroConstructor, IsPlainOldData)
	TArray<unsigned char>                              FromBinaries;                                             // (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm)
	struct FString                                     ToURL;                                                    // (Parm, ZeroConstructor)
	struct FString                                     NoneMatchHeader;                                          // (Parm, ZeroConstructor)
	struct FScriptDelegate                             OnComplete;                                               // (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm)
	struct FScriptDelegate                             OnProgress;                                               // (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm)
};

// Function AWSHelper.AWSHelperBlueprintLibrary.DownloadFile
struct UAWSHelperBlueprintLibrary_DownloadFile_Params
{
	class UAWSHelper*                                  CosHelper;                                                // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     FromURL;                                                  // (Parm, ZeroConstructor)
	struct FString                                     ToFilePath;                                               // (Parm, ZeroConstructor)
	struct FScriptDelegate                             OnComplete;                                               // (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm)
	struct FScriptDelegate                             OnProgress;                                               // (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm)
};

// Function AWSHelper.AWSHelperBlueprintLibrary.DownloadBinary
struct UAWSHelperBlueprintLibrary_DownloadBinary_Params
{
	class UAWSHelper*                                  CosHelper;                                                // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     FromURL;                                                  // (Parm, ZeroConstructor)
	struct FScriptDelegate                             OnComplete;                                               // (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm)
	struct FScriptDelegate                             OnProgress;                                               // (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm)
};

// Function AWSHelper.AWSHelperBlueprintLibrary.DestroyAWSHelper
struct UAWSHelperBlueprintLibrary_DestroyAWSHelper_Params
{
	class UAWSHelper*                                  AWSHelper;                                                // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function AWSHelper.AWSHelperBlueprintLibrary.ConstructAWSHelper
struct UAWSHelperBlueprintLibrary_ConstructAWSHelper_Params
{
	class UAWSHelper*                                  ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function AWSHelper.AWSResponse.IsOK
struct UAWSResponse_IsOK_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function AWSHelper.AWSResponse.GetResponseCode
struct UAWSResponse_GetResponseCode_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function AWSHelper.AWSResponse.GetRequestURL
struct UAWSResponse_GetRequestURL_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function AWSHelper.AWSResponse.GetErrorMessage
struct UAWSResponse_GetErrorMessage_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function AWSHelper.AWSResponse.GetErrorCode
struct UAWSResponse_GetErrorCode_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function AWSHelper.AWSResponse.GetContentAsString
struct UAWSResponse_GetContentAsString_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function AWSHelper.AWSResponse.GetContent
struct UAWSResponse_GetContent_Params
{
	TArray<unsigned char>                              ReturnValue;                                              // (ConstParm, Parm, OutParm, ZeroConstructor, ReturnParm, ReferenceParm)
};

}

