#pragma once

// PUBG MOBILE (4.5.0 -- 64bit Beta) SDK Generate By @ByDwoz
// Telegram Channel:- @XelahotOfficial
// Generate on Wed Jul  8 13:37:47 2026
 
namespace SDK
{
//---------------------❣︎➪ 𝗕𝗬𝗗𝗪𝗢𝗭 𝗗𝗘𝗩𝗘𝗟𝗢𝗣𝗘𝗥༆✈︎🇪🇬---------------------------
//Classes
//---------------------❣︎➪𝗕𝗬𝗗𝗪𝗢𝗭 𝗗𝗘𝗩𝗘𝗟𝗢𝗣𝗘𝗥༆✈︎🇪🇬---------------------------

// Class PandoraPickerPlugin.BP_PandoraPickerLibraryLibrary
// 0x0020 (0x0048 - 0x0028)
class UBP_PandoraPickerLibraryLibrary : public UBlueprintFunctionLibrary
{
public:
	struct FScriptMulticastDelegate                    m_PickerEventDelegate;                                    // 0x0028(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    m_PickerVideoEventDelegate;                               // 0x0038(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class PandoraPickerPlugin.BP_PandoraPickerLibraryLibrary");
		return pStaticClass;
	}


	static class UBP_PandoraPickerLibraryLibrary* GetInstance();
	static void BP_SetVideoExportQuality(int Quality);
	static class UTexture2D* BP_PandoraPickerLoadImageTest(const struct FString& fImagePath, const struct FString& fOrgImagePath, class UTexture2D** orgTex2D);
	static int BP_PandoraPickerInit();
	static void BP_PandoraPickerGetSavedPath(struct FString* strSavePath);
	static void BP_OpenImageLibraryWithOrg(int Width, int Height, const struct FString& SecretKey, const struct FString& SavedPath);
	static void BP_OpenImageLibraryVideo(const struct FString& SecretKey);
	static void BP_OpenImageLibraryNoCut(int Width, int Height, const struct FString& SecretKey, const struct FString& SavedPath);
	static void BP_OpenImageLibrary(int Width, int Height, const struct FString& SecretKey, const struct FString& SavedPath);
};


}

