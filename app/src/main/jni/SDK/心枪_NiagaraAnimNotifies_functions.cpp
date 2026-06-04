/*
// ------------------------------------------------
DUMP SDK BY @Sanji1_Owner V4.4.0

TELEGRAM CHANNEL @NIKA_SOURCE_MODS

All rights reserved by the NIKA TEAM AND INCLUDED TEAM

@INCLUDED_SO
// ------------------------------------------------
*/

#include "../SDK.hpp"

namespace SDK
{
//-------------------------------------------------
//Functions
//-------------------------------------------------
// Function NiagaraAnimNotifies.AnimNotifyState_TimedNiagaraEffect.GetParentCharacter
// (Final, Native, Private, Const)
// Parameters:
// class USkeletalMeshComponent*  MeshComp                       (Parm, ZeroConstructor, InstancedReference, IsPlainOldData)
// class ACharacter*              ReturnValue                    (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)

class ACharacter* UAnimNotifyState_TimedNiagaraEffect::GetParentCharacter(class USkeletalMeshComponent* MeshComp)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function NiagaraAnimNotifies.AnimNotifyState_TimedNiagaraEffect.GetParentCharacter");

	UAnimNotifyState_TimedNiagaraEffect_GetParentCharacter_Params params;
	params.MeshComp = MeshComp;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


}

