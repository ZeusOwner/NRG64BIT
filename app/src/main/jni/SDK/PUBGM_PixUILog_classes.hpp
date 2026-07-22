#pragma once

// PUBG MOBILE (4.5.0 -- 64bit Beta) SDK Generate By @ByDwoz
// Telegram Channel:- @XelahotOfficial
// Generate on Wed Jul  8 13:37:47 2026
 
namespace SDK
{
//---------------------❣︎➪ 𝗕𝗬𝗗𝗪𝗢𝗭 𝗗𝗘𝗩𝗘𝗟𝗢𝗣𝗘𝗥༆✈︎🇪🇬---------------------------
//Classes
//---------------------❣︎➪𝗕𝗬𝗗𝗪𝗢𝗭 𝗗𝗘𝗩𝗘𝗟𝗢𝗣𝗘𝗥༆✈︎🇪🇬---------------------------

// Class PixUILog.PxLogMgr
// 0x0010 (0x0038 - 0x0028)
class UPxLogMgr : public UObject
{
public:
	struct FScriptMulticastDelegate                    LogDelegate;                                              // 0x0028(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class PixUILog.PxLogMgr");
		return pStaticClass;
	}


	static void PxLogToggleSwitchLevel(EPxLogLevels eLogLevel, bool beOpen);
	static void PxLogToggleSwitchGroup(EPxLogGroups eLogGroup, bool beOpen);
	static void PxLogToggleForceLocalOutPut(bool beOpen);
	static void PxLogEnable(bool beEnable);
	static class UPxLogMgr* Get();
	static void DispatchLog(EPxLogGroups eLogGroup, EPxLogLevels eLogLevel, const struct FString& strLogContent);
};


}

