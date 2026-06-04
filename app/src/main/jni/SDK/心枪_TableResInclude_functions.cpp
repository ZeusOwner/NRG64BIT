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
// Function TableResInclude.EvoBaseMapUIMarkTableMap.TraversTable
// (Final, Native, Public)
// Parameters:
// class UUAEDataTable*           TableData                      (Parm, ZeroConstructor, IsPlainOldData)
// struct FName                   Key                            (Parm, ZeroConstructor, IsPlainOldData)

void UEvoBaseMapUIMarkTableMap::TraversTable(class UUAEDataTable* TableData, const struct FName& Key)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function TableResInclude.EvoBaseMapUIMarkTableMap.TraversTable");

	UEvoBaseMapUIMarkTableMap_TraversTable_Params params;
	params.TableData = TableData;
	params.Key = Key;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


// Function TableResInclude.EvoBaseModTableTestTableMap.TraversTable
// (Final, Native, Public)
// Parameters:
// class UUAEDataTable*           TableData                      (Parm, ZeroConstructor, IsPlainOldData)
// struct FName                   Key                            (Parm, ZeroConstructor, IsPlainOldData)

void UEvoBaseModTableTestTableMap::TraversTable(class UUAEDataTable* TableData, const struct FName& Key)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function TableResInclude.EvoBaseModTableTestTableMap.TraversTable");

	UEvoBaseModTableTestTableMap_TraversTable_Params params;
	params.TableData = TableData;
	params.Key = Key;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


}

