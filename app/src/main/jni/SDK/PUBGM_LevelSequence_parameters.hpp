#pragma once

// PUBG MOBILE (4.5.0 -- 64bit Beta) SDK Generate By @ByDwoz
// Telegram Channel:- @XelahotOfficial
// Generate on Wed Jul  8 13:37:43 2026
 
#include "../SDK.hpp"

namespace SDK
{
//---------------------❣︎➪ 𝗕𝗬𝗗𝗪𝗢𝗭 𝗗𝗘𝗩𝗘𝗟𝗢𝗣𝗘𝗥༆✈︎🇪🇬---------------------------
//Parameters
//---------------------❣︎➪𝗕𝗬𝗗𝗪𝗢𝗭 𝗗𝗘𝗩𝗘𝗟𝗢𝗣𝗘𝗥༆✈︎🇪🇬---------------------------

// Function LevelSequence.LevelSequenceActor.SetSequence
struct ALevelSequenceActor_SetSequence_Params
{
	class ULevelSequence*                              InSequence;                                               // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function LevelSequence.LevelSequenceActor.SetEventReceivers
struct ALevelSequenceActor_SetEventReceivers_Params
{
	TArray<class AActor*>                              AdditionalReceivers;                                      // (Parm, ZeroConstructor)
};

// Function LevelSequence.LevelSequenceActor.SetBinding
struct ALevelSequenceActor_SetBinding_Params
{
	struct FMovieSceneObjectBindingID                  Binding;                                                  // (Parm)
	TArray<class AActor*>                              Actors;                                                   // (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm)
	bool                                               bAllowBindingsFromAsset;                                  // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function LevelSequence.LevelSequenceActor.SetAllMovieSceneSectionsToKeepState
struct ALevelSequenceActor_SetAllMovieSceneSectionsToKeepState_Params
{
};

// Function LevelSequence.LevelSequenceActor.ResetBindings
struct ALevelSequenceActor_ResetBindings_Params
{
};

// Function LevelSequence.LevelSequenceActor.ResetBinding
struct ALevelSequenceActor_ResetBinding_Params
{
	struct FMovieSceneObjectBindingID                  Binding;                                                  // (Parm)
};

// Function LevelSequence.LevelSequenceActor.RemoveBinding
struct ALevelSequenceActor_RemoveBinding_Params
{
	struct FMovieSceneObjectBindingID                  Binding;                                                  // (Parm)
	class AActor*                                      Actor;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function LevelSequence.LevelSequenceActor.ReceiveInitailizePlayer
struct ALevelSequenceActor_ReceiveInitailizePlayer_Params
{
};

// Function LevelSequence.LevelSequenceActor.GetSequence
struct ALevelSequenceActor_GetSequence_Params
{
	bool                                               bLoad;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               bInitializePlayer;                                        // (Parm, ZeroConstructor, IsPlainOldData)
	class ULevelSequence*                              ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function LevelSequence.LevelSequenceActor.GetPossessableByName
struct ALevelSequenceActor_GetPossessableByName_Params
{
	struct FString                                     NameKeyString;                                            // (Parm, ZeroConstructor)
	struct FMovieSceneObjectBindingID                  ReturnValue;                                              // (Parm, OutParm, ReturnParm)
};

// Function LevelSequence.LevelSequenceActor.AddBinding
struct ALevelSequenceActor_AddBinding_Params
{
	struct FMovieSceneObjectBindingID                  Binding;                                                  // (Parm)
	class AActor*                                      Actor;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               bAllowBindingsFromAsset;                                  // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function LevelSequence.LevelSequenceBurnIn.SetSettings
struct ULevelSequenceBurnIn_SetSettings_Params
{
	class UObject*                                     InSettings;                                               // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function LevelSequence.LevelSequenceBurnIn.GetSettingsClass
struct ULevelSequenceBurnIn_GetSettingsClass_Params
{
	class UClass*                                      ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function LevelSequence.LevelSequencePlayer.SetCanUpdateCameraCut
struct ULevelSequencePlayer_SetCanUpdateCameraCut_Params
{
	bool                                               bEnable;                                                  // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function LevelSequence.LevelSequencePlayer.IsActorBoundToSequence
struct ULevelSequencePlayer_IsActorBoundToSequence_Params
{
	class AActor*                                      InActor;                                                  // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function LevelSequence.LevelSequencePlayer.EnablePrimitiveComponentTracking
struct ULevelSequencePlayer_EnablePrimitiveComponentTracking_Params
{
};

// Function LevelSequence.LevelSequencePlayer.DisablePrimitiveComponentTracking
struct ULevelSequencePlayer_DisablePrimitiveComponentTracking_Params
{
};

// Function LevelSequence.LevelSequencePlayer.CreateLevelSequencePlayer
struct ULevelSequencePlayer_CreateLevelSequencePlayer_Params
{
	class UObject*                                     WorldContextObject;                                       // (Parm, ZeroConstructor, IsPlainOldData)
	class ULevelSequence*                              LevelSequence;                                            // (Parm, ZeroConstructor, IsPlainOldData)
	struct FMovieSceneSequencePlaybackSettings         Settings;                                                 // (Parm)
	class ALevelSequenceActor*                         OutActor;                                                 // (Parm, OutParm, ZeroConstructor, IsPlainOldData)
	class ULevelSequencePlayer*                        ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

}

