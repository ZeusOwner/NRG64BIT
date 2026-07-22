// PUBG MOBILE (4.5.0 -- 64bit Beta) SDK Generate By @ByDwoz
// Telegram Channel:- @XelahotOfficial
// Generate on Wed Jul  8 13:37:57 2026
 
#include "../SDK.hpp"

namespace SDK
{
//---------------------❣︎➪ 𝗕𝗬𝗗𝗪𝗢𝗭 𝗗𝗘𝗩𝗘𝗟𝗢𝗣𝗘𝗥༆✈︎🇪🇬---------------------------
//Functions
//---------------------❣︎➪𝗕𝗬𝗗𝗪𝗢𝗭 𝗗𝗘𝗩𝗘𝗟𝗢𝗣𝗘𝗥༆✈︎🇪🇬---------------------------

// Function GlobalLuaWidget.GlobalLuaWidget_C.GetNewLevelTaskData
// (Public, HasOutParms, BlueprintCallable, BlueprintEvent)
// Parameters:
// struct FString                 TaskId                         (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor)
// bool                           Has                            (Parm, OutParm, ZeroConstructor, IsPlainOldData)
// struct FBP_STRUCT_NewLevelTask_type BP_STRUCT_NewLevelTask_type    (Parm, OutParm)

void UGlobalLuaWidget_C::GetNewLevelTaskData(const struct FString& TaskId, bool* Has, struct FBP_STRUCT_NewLevelTask_type* BP_STRUCT_NewLevelTask_type)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function GlobalLuaWidget.GlobalLuaWidget_C.GetNewLevelTaskData");

	UGlobalLuaWidget_C_GetNewLevelTaskData_Params params;
	params.TaskId = TaskId;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	if (Has != nullptr)
		*Has = params.Has;
	if (BP_STRUCT_NewLevelTask_type != nullptr)
		*BP_STRUCT_NewLevelTask_type = params.BP_STRUCT_NewLevelTask_type;
}


}

