#pragma once

// PUBG MOBILE (4.5.0 -- 64bit Beta) SDK Generate By @ByDwoz
// Telegram Channel:- @XelahotOfficial
// Generate on Wed Jul  8 13:37:46 2026
 
namespace SDK
{
//---------------------❣︎➪ 𝗕𝗬𝗗𝗪𝗢𝗭 𝗗𝗘𝗩𝗘𝗟𝗢𝗣𝗘𝗥༆✈︎🇪🇬---------------------------
//Classes
//---------------------❣︎➪𝗕𝗬𝗗𝗪𝗢𝗭 𝗗𝗘𝗩𝗘𝗟𝗢𝗣𝗘𝗥༆✈︎🇪🇬---------------------------

// Class ModularGameplay.GameFrameworkComponent
// 0x0000 (0x0178 - 0x0178)
class UGameFrameworkComponent : public UActorComponent
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class ModularGameplay.GameFrameworkComponent");
		return pStaticClass;
	}

};


// Class ModularGameplay.ControllerComponent
// 0x0000 (0x0178 - 0x0178)
class UControllerComponent : public UGameFrameworkComponent
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class ModularGameplay.ControllerComponent");
		return pStaticClass;
	}

};


// Class ModularGameplay.GameFrameworkComponentManager
// 0x00F0 (0x0120 - 0x0030)
class UGameFrameworkComponentManager : public UGameInstanceSubsystem
{
public:
	unsigned char                                      UnknownData00[0xF0];                                      // 0x0030(0x00F0) MISSED OFFSET

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class ModularGameplay.GameFrameworkComponentManager");
		return pStaticClass;
	}


	void RemoveReceiver(class AActor* Receiver);
	void AddReceiver(class AActor* Receiver, bool bAddOnlyInGameWorlds);
};


// Class ModularGameplay.GameStateComponent
// 0x0000 (0x0178 - 0x0178)
class UGameStateComponent : public UGameFrameworkComponent
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class ModularGameplay.GameStateComponent");
		return pStaticClass;
	}

};


// Class ModularGameplay.PawnComponent
// 0x0000 (0x0178 - 0x0178)
class UPawnComponent : public UGameFrameworkComponent
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class ModularGameplay.PawnComponent");
		return pStaticClass;
	}

};


// Class ModularGameplay.PlayerStateComponent
// 0x0000 (0x0178 - 0x0178)
class UPlayerStateComponent : public UGameFrameworkComponent
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class ModularGameplay.PlayerStateComponent");
		return pStaticClass;
	}

};


}

