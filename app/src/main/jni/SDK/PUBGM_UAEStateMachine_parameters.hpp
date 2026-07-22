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

// Function UAEStateMachine.UAEStateMachineComponent.Start
struct UUAEStateMachineComponent_Start_Params
{
};

// Function UAEStateMachine.UAEStateMachineComponent.SetTag
struct UUAEStateMachineComponent_SetTag_Params
{
	struct FString                                     InTag;                                                    // (Parm, ZeroConstructor)
};

// DelegateFunction UAEStateMachine.UAEStateMachineComponent.OnTransientEvent__DelegateSignature
struct UUAEStateMachineComponent_OnTransientEvent__DelegateSignature_Params
{
	struct FString                                     TransientEvent;                                           // (Parm, ZeroConstructor)
	struct FString                                     CurrentState;                                             // (Parm, ZeroConstructor)
	struct FString                                     TransientToState;                                         // (Parm, ZeroConstructor)
};

// Function UAEStateMachine.UAEStateMachineComponent.IsInState
struct UUAEStateMachineComponent_IsInState_Params
{
	struct FString                                     StateName;                                                // (Parm, ZeroConstructor)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function UAEStateMachine.UAEStateMachineComponent.GetCurrentState
struct UUAEStateMachineComponent_GetCurrentState_Params
{
	class UUAEState*                                   ReturnValue;                                              // (ExportObject, Parm, OutParm, ZeroConstructor, ReturnParm, InstancedReference, IsPlainOldData)
};

// Function UAEStateMachine.UAEStateMachineComponent.ForceDoEvent
struct UUAEStateMachineComponent_ForceDoEvent_Params
{
	struct FString                                     EventName;                                                // (Parm, ZeroConstructor)
};

// Function UAEStateMachine.UAEStateMachineComponent.Finish
struct UUAEStateMachineComponent_Finish_Params
{
};

// Function UAEStateMachine.UAEStateMachineComponent.DoEvent
struct UUAEStateMachineComponent_DoEvent_Params
{
	struct FString                                     EventName;                                                // (Parm, ZeroConstructor)
};

// Function UAEStateMachine.UAEStateMachineComponent.CanDoEvent
struct UUAEStateMachineComponent_CanDoEvent_Params
{
	struct FString                                     EventName;                                                // (Parm, ZeroConstructor)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function UAEStateMachine.UAEState.Update
struct UUAEState_Update_Params
{
	float                                              DeltaTime;                                                // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function UAEStateMachine.UAEState.OnLeave
struct UUAEState_OnLeave_Params
{
	class UUAEState*                                   TranitToState;                                            // (ConstParm, Parm, ZeroConstructor, InstancedReference, IsPlainOldData)
};

// Function UAEStateMachine.UAEState.OnEnter
struct UUAEState_OnEnter_Params
{
	class UUAEState*                                   PrevState;                                                // (ConstParm, Parm, ZeroConstructor, InstancedReference, IsPlainOldData)
};

}

