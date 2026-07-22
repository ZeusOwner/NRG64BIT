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

// Function QRCodeUtility.VideoThumbnailGenerator.GenerateVideoThumbnailAsync
struct UVideoThumbnailGenerator_GenerateVideoThumbnailAsync_Params
{
	struct FString                                     videoPath;                                                // (Parm, ZeroConstructor)
	int                                                thumbnailSize;                                            // (Parm, ZeroConstructor, IsPlainOldData)
	struct FScriptDelegate                             OnThumbnailGenerated;                                     // (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm)
};

// Function QRCodeUtility.ZXingScanner.Encode
struct UZXingScanner_Encode_Params
{
	struct FString                                     Text;                                                     // (Parm, ZeroConstructor)
	class UTexture2D*                                  ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function QRCodeUtility.ZXingScanner.Decode
struct UZXingScanner_Decode_Params
{
	class UTexture2D*                                  Texture;                                                  // (Parm, ZeroConstructor, IsPlainOldData)
	struct FZXingScanResult                            OutResult;                                                // (Parm, OutParm)
	struct FVector4                                    InRect;                                                   // (ConstParm, Parm, OutParm, ReferenceParm, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

}

