#pragma once

// PUBG MOBILE (4.5.0 -- 64bit Beta) SDK Generate By @ByDwoz
// Telegram Channel:- @XelahotOfficial
// Generate on Wed Jul  8 13:37:55 2026
 
namespace SDK
{
//---------------------❣︎➪ 𝗕𝗬𝗗𝗪𝗢𝗭 𝗗𝗘𝗩𝗘𝗟𝗢𝗣𝗘𝗥༆✈︎🇪🇬---------------------------
//Classes
//---------------------❣︎➪𝗕𝗬𝗗𝗪𝗢𝗭 𝗗𝗘𝗩𝗘𝗟𝗢𝗣𝗘𝗥༆✈︎🇪🇬---------------------------

// BlueprintGeneratedClass Editor_login.Editor_login_C
// 0x0008 (0x04B8 - 0x04B0)
class AEditor_login_C : public ALevelScriptActor
{
public:
	struct FPointerToUberGraphFrame                    UberGraphFrame;                                           // 0x04B0(0x0008) (Transient, DuplicateTransient)

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass Editor_login.Editor_login_C");
		return pStaticClass;
	}


	void SetFpsByIndex(int idx);
	void InpActEvt_Android_Back_K2Node_InputKeyEvent_12(const struct FKey& Key);
	void InpActEvt_E_K2Node_InputKeyEvent_11(const struct FKey& Key);
	void InpActEvt_BackSpace_K2Node_InputKeyEvent_10(const struct FKey& Key);
	void InpActEvt_B_K2Node_InputKeyEvent_9(const struct FKey& Key);
	void InpActEvt_G_K2Node_InputKeyEvent_8(const struct FKey& Key);
	void InpActEvt_N_K2Node_InputKeyEvent_7(const struct FKey& Key);
	void ReceiveBeginPlay();
	void ExecuteUbergraph_Editor_login(int EntryPoint);
};


}

