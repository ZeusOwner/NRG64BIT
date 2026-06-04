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
//Classes
//-------------------------------------------------
// Class QRCodeUtility.VideoThumbnailGenerator
// 0x0000 (0x0028 - 0x0028)
class UVideoThumbnailGenerator : public UBlueprintFunctionLibrary
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class QRCodeUtility.VideoThumbnailGenerator");
		return pStaticClass;
	}


	static void GenerateVideoThumbnailAsync(const struct FString& videoPath, int thumbnailSize, const struct FScriptDelegate& OnThumbnailGenerated);
};


// Class QRCodeUtility.ZXingScanner
// 0x0000 (0x0028 - 0x0028)
class UZXingScanner : public UBlueprintFunctionLibrary
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class QRCodeUtility.ZXingScanner");
		return pStaticClass;
	}


	static class UTexture2D* Encode(const struct FString& Text);
	static bool Decode(class UTexture2D* Texture, const struct FVector4& InRect, struct FZXingScanResult* OutResult);
};


}

