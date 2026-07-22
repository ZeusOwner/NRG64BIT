#pragma once

// PUBG MOBILE (4.5.0 -- 64bit Beta) SDK Generate By @ByDwoz
// Telegram Channel:- @XelahotOfficial
// Generate on Wed Jul  8 13:37:47 2026
 
namespace SDK
{
//---------------------❣︎➪ 𝗕𝗬𝗗𝗪𝗢𝗭 𝗗𝗘𝗩𝗘𝗟𝗢𝗣𝗘𝗥༆✈︎🇪🇬---------------------------
//Classes
//---------------------❣︎➪𝗕𝗬𝗗𝗪𝗢𝗭 𝗗𝗘𝗩𝗘𝗟𝗢𝗣𝗘𝗥༆✈︎🇪🇬---------------------------

// Class ActorSequence.ActorSequence
// 0x0028 (0x0310 - 0x02E8)
class UActorSequence : public UMovieSceneSequence
{
public:
	class UMovieScene*                                 MovieScene;                                               // 0x02E8(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	struct FActorSequenceObjectReferenceMap            ObjectReferences;                                         // 0x02F0(0x0020)

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class ActorSequence.ActorSequence");
		return pStaticClass;
	}

};


// Class ActorSequence.ActorSequenceComponent
// 0x0040 (0x01B8 - 0x0178)
class UActorSequenceComponent : public UActorComponent
{
public:
	struct FMovieSceneSequencePlaybackSettings         PlaybackSettings;                                         // 0x0178(0x0028) (Edit)
	class UActorSequence*                              Sequence;                                                 // 0x01A0(0x0008) (Edit, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UActorSequencePlayer*                        SequencePlayer;                                           // 0x01A8(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData)
	bool                                               bAutoPlay;                                                // 0x01B0(0x0001) (Edit, ZeroConstructor, IsPlainOldData)
	bool                                               bRunOnServer;                                             // 0x01B1(0x0001) (Edit, ZeroConstructor, IsPlainOldData)
	bool                                               bEnableOptimize;                                          // 0x01B2(0x0001) (Edit, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x5];                                       // 0x01B3(0x0005) MISSED OFFSET

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class ActorSequence.ActorSequenceComponent");
		return pStaticClass;
	}


	void StopPlay();
	void StartPlay(float StartTime);
	void OnStopOrFinsh();
	float GetLength();
};


// Class ActorSequence.ActorSequencePlayer
// 0x0000 (0x07B8 - 0x07B8)
class UActorSequencePlayer : public UMovieSceneSequencePlayer
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class ActorSequence.ActorSequencePlayer");
		return pStaticClass;
	}

};


}

