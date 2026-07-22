#pragma once

// PUBG MOBILE (4.5.0 -- 64bit Beta) SDK Generate By @ByDwoz
// Telegram Channel:- @XelahotOfficial
// Generate on Wed Jul  8 13:37:46 2026
 
namespace SDK
{
//---------------------❣︎➪ 𝗕𝗬𝗗𝗪𝗢𝗭 𝗗𝗘𝗩𝗘𝗟𝗢𝗣𝗘𝗥༆✈︎🇪🇬---------------------------
//Classes
//---------------------❣︎➪𝗕𝗬𝗗𝗪𝗢𝗭 𝗗𝗘𝗩𝗘𝗟𝗢𝗣𝗘𝗥༆✈︎🇪🇬---------------------------

// Class AWSHelper.AWSHelper
// 0x0150 (0x0178 - 0x0028)
class UAWSHelper : public UObject
{
public:
	unsigned char                                      UnknownData00[0xA8];                                      // 0x0028(0x00A8) MISSED OFFSET
	TMap<struct FString, struct FString>               DownloadFilePaths;                                        // 0x00D0(0x0050) (ZeroConstructor)
	float                                              Timeout;                                                  // 0x0120(0x0004) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x54];                                      // 0x0124(0x0054) MISSED OFFSET

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class AWSHelper.AWSHelper");
		return pStaticClass;
	}

};


// Class AWSHelper.AWSHelperBlueprintLibrary
// 0x0000 (0x0028 - 0x0028)
class UAWSHelperBlueprintLibrary : public UBlueprintFunctionLibrary
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class AWSHelper.AWSHelperBlueprintLibrary");
		return pStaticClass;
	}


	static void UploadFile(class UAWSHelper* CosHelper, const struct FString& FromFilePath, const struct FString& ToURL, const struct FString& NoneMatchHeader, const struct FScriptDelegate& OnComplete, const struct FScriptDelegate& OnProgress);
	static void UploadBinary(class UAWSHelper* CosHelper, TArray<unsigned char> FromBinaries, const struct FString& ToURL, const struct FString& NoneMatchHeader, const struct FScriptDelegate& OnComplete, const struct FScriptDelegate& OnProgress);
	static void DownloadFile(class UAWSHelper* CosHelper, const struct FString& FromURL, const struct FString& ToFilePath, const struct FScriptDelegate& OnComplete, const struct FScriptDelegate& OnProgress);
	static void DownloadBinary(class UAWSHelper* CosHelper, const struct FString& FromURL, const struct FScriptDelegate& OnComplete, const struct FScriptDelegate& OnProgress);
	static void DestroyAWSHelper(class UAWSHelper* AWSHelper);
	static class UAWSHelper* ConstructAWSHelper();
};


// Class AWSHelper.AWSResponse
// 0x0048 (0x0070 - 0x0028)
class UAWSResponse : public UObject
{
public:
	unsigned char                                      UnknownData00[0x48];                                      // 0x0028(0x0048) MISSED OFFSET

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class AWSHelper.AWSResponse");
		return pStaticClass;
	}


	bool IsOK();
	int GetResponseCode();
	struct FString GetRequestURL();
	struct FString GetErrorMessage();
	struct FString GetErrorCode();
	struct FString GetContentAsString();
	TArray<unsigned char> GetContent();
};


}

