#pragma once

// PUBG MOBILE (4.5.0 -- 64bit Beta) SDK Generate By @ByDwoz
// Telegram Channel:- @XelahotOfficial
// Generate on Wed Jul  8 13:37:47 2026
 
namespace SDK
{
//---------------------❣︎➪ 𝗕𝗬𝗗𝗪𝗢𝗭 𝗗𝗘𝗩𝗘𝗟𝗢𝗣𝗘𝗥༆✈︎🇪🇬---------------------------
//Classes
//---------------------❣︎➪𝗕𝗬𝗗𝗪𝗢𝗭 𝗗𝗘𝗩𝗘𝗟𝗢𝗣𝗘𝗥༆✈︎🇪🇬---------------------------

// Class PixUIProfiler.PxProfilerMgr
// 0x0000 (0x0028 - 0x0028)
class UPxProfilerMgr : public UObject
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class PixUIProfiler.PxProfilerMgr");
		return pStaticClass;
	}


	static void StartProfiler();
	static void PxProfilerCapabilitySwitch(EPxProfilerCapability EPxProfilerCapability, bool bOpen);
	static void Print();
	static bool GetPxProfilerCapability(EPxProfilerCapability EPxProfilerCapability);
	static void EndProfiler();
	static void Check();
};


}

