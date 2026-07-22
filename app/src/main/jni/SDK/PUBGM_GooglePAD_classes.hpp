#pragma once

// PUBG MOBILE (4.5.0 -- 64bit Beta) SDK Generate By @ByDwoz
// Telegram Channel:- @XelahotOfficial
// Generate on Wed Jul  8 13:37:48 2026
 
namespace SDK
{
//---------------------❣︎➪ 𝗕𝗬𝗗𝗪𝗢𝗭 𝗗𝗘𝗩𝗘𝗟𝗢𝗣𝗘𝗥༆✈︎🇪🇬---------------------------
//Classes
//---------------------❣︎➪𝗕𝗬𝗗𝗪𝗢𝗭 𝗗𝗘𝗩𝗘𝗟𝗢𝗣𝗘𝗥༆✈︎🇪🇬---------------------------

// Class GooglePAD.GooglePADFunctionLibrary
// 0x0000 (0x0028 - 0x0028)
class UGooglePADFunctionLibrary : public UBlueprintFunctionLibrary
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class GooglePAD.GooglePADFunctionLibrary");
		return pStaticClass;
	}


	static EGooglePADErrorCode ShowCellularDataConfirmation();
	static EGooglePADErrorCode RequestRemoval(const struct FString& Name);
	static EGooglePADErrorCode RequestInfo(TArray<struct FString> AssetPacks);
	static EGooglePADErrorCode RequestDownload(TArray<struct FString> AssetPacks);
	static void ReleaseDownloadState(int State);
	static void ReleaseAssetPackLocation(int Location);
	static int GetTotalBytesToDownload(int State);
	static EGooglePADStorageMethod GetStorageMethod(int Location);
	static EGooglePADErrorCode GetShowCellularDataConfirmationStatus(EGooglePADCellularDataConfirmStatus* status);
	static EGooglePADDownloadStatus GetDownloadStatus(int State);
	static EGooglePADErrorCode GetDownloadState(const struct FString& Name, int* State);
	static int GetBytesDownloaded(int State);
	static struct FString GetAssetsPath(int Location);
	static EGooglePADErrorCode GetAssetPackLocation(const struct FString& Name, int* Location);
	static EGooglePADErrorCode CancelDownload(TArray<struct FString> AssetPacks);
};


}

