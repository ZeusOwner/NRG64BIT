#pragma once

// PUBG MOBILE (4.5.0 -- 64bit Beta) SDK Generate By @ByDwoz
// Telegram Channel:- @XelahotOfficial
// Generate on Wed Jul  8 13:37:57 2026
 
namespace SDK
{
//---------------------❣︎➪ 𝗕𝗬𝗗𝗪𝗢𝗭 𝗗𝗘𝗩𝗘𝗟𝗢𝗣𝗘𝗥༆✈︎🇪🇬---------------------------
//Classes
//---------------------❣︎➪𝗕𝗬𝗗𝗪𝗢𝗭 𝗗𝗘𝗩𝗘𝗟𝗢𝗣𝗘𝗥༆✈︎🇪🇬---------------------------

// BlueprintGeneratedClass CameraPostProcessActor.CameraPostProcessActor_C
// 0x05C0 (0x0A70 - 0x04B0)
class ACameraPostProcessActor_C : public AActor
{
public:
	struct FPointerToUberGraphFrame                    UberGraphFrame;                                           // 0x04B0(0x0008) (Transient, DuplicateTransient)
	class USceneComponent*                             DefaultSceneRoot;                                         // 0x04B8(0x0008) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              Timeline_LerpPPSettings_104_7E99B53D425173C51E1B2D83BB82148A;// 0x04C0(0x0004) (ZeroConstructor, IsPlainOldData)
	float                                              Timeline_LerpPPSettings_103_7E99B53D425173C51E1B2D83BB82148A;// 0x04C4(0x0004) (ZeroConstructor, IsPlainOldData)
	float                                              Timeline_LerpPPSettings_102_7E99B53D425173C51E1B2D83BB82148A;// 0x04C8(0x0004) (ZeroConstructor, IsPlainOldData)
	float                                              Timeline_LerpPPSettings_101_7E99B53D425173C51E1B2D83BB82148A;// 0x04CC(0x0004) (ZeroConstructor, IsPlainOldData)
	TEnumAsByte<ETimelineDirection>                    Timeline_LerpPPSettings__Direction_7E99B53D425173C51E1B2D83BB82148A;// 0x04D0(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x04D1(0x0007) MISSED OFFSET
	class UTimelineComponent*                          Timeline_LerpPPSettings;                                  // 0x04D8(0x0008) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	class APostProcessVolume*                          currentPostProcessVolumn;                                 // 0x04E0(0x0008) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, DisableEditOnInstance, IsPlainOldData)
	int                                                isLerp;                                                   // 0x04E8(0x0004) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData01[0x4];                                       // 0x04EC(0x0004) MISSED OFFSET
	TArray<TEnumAsByte<EDepthOfFieldMethod>>           depthOfFieldMethodArray;                                  // 0x04F0(0x0010) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance)
	float                                              LerpAlpha;                                                // 0x0500(0x0004) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               isReverse;                                                // 0x0504(0x0001) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData02[0xB];                                       // 0x0505(0x000B) MISSED OFFSET
	struct FPostProcessSettings                        previousPPSettingsStruct;                                 // 0x0510(0x0560) (Edit, BlueprintVisible, DisableEditOnInstance)

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass CameraPostProcessActor.CameraPostProcessActor_C");
		return pStaticClass;
	}


	void UserConstructionScript();
	void Timeline_LerpPPSettings__FinishedFunc();
	void Timeline_LerpPPSettings__UpdateFunc();
	void Event_LerpPostProcessSettings(class APostProcessVolume* currentPPVolumn, const struct FBP_STRUCT_CameraPostProcessSettings_type& targetPPSettingsStruct, float Time, int ID, bool isReverse);
	void ExecuteUbergraph_CameraPostProcessActor(int EntryPoint);
};


}

