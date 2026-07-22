#pragma once

// PUBG MOBILE (4.5.0 -- 64bit Beta) SDK Generate By @ByDwoz
// Telegram Channel:- @XelahotOfficial
// Generate on Wed Jul  8 13:37:53 2026
 
namespace SDK
{
//---------------------❣︎➪ 𝗕𝗬𝗗𝗪𝗢𝗭 𝗗𝗘𝗩𝗘𝗟𝗢𝗣𝗘𝗥༆✈︎🇪🇬---------------------------
//Classes
//---------------------❣︎➪𝗕𝗬𝗗𝗪𝗢𝗭 𝗗𝗘𝗩𝗘𝗟𝗢𝗣𝗘𝗥༆✈︎🇪🇬---------------------------

// BlueprintGeneratedClass BattleItemHandle_AvatarBP.BattleItemHandle_AvatarBP_C
// 0x0092 (0x0B92 - 0x0B00)
class UBattleItemHandle_AvatarBP_C : public UBackpackAvatarHandle
{
public:
	class ASTExtraPlayerController*                    OwningPlayerController;                                   // 0x0B00(0x0008) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, IsPlainOldData)
	class ASTExtraBaseCharacter*                       OwningCharacter;                                          // 0x0B08(0x0008) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, DisableEditOnInstance, IsPlainOldData)
	class UBackpackComponent*                          OwningBackpackComponent;                                  // 0x0B10(0x0008) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x8];                                       // 0x0B18(0x0008) MISSED OFFSET
	struct FTransform                                  SourceWrapperTrans;                                       // 0x0B20(0x0030) (Edit, BlueprintVisible, DisableEditOnInstance, IsPlainOldData)
	struct FTransform                                  WrapperPutdownTrans;                                      // 0x0B50(0x0030) (Edit, BlueprintVisible, DisableEditOnInstance, IsPlainOldData)
	class UClass*                                      WrapperClass;                                             // 0x0B80(0x0008) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UBattleItemHandleBase*                       CharacterItemHandle;                                      // 0x0B88(0x0008) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<EnumAvatarSlotNameConfig>              SlotNameConfig;                                           // 0x0B90(0x0001) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<EnumAvatarForceGender>                 ForceGender;                                              // 0x0B91(0x0001) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass BattleItemHandle_AvatarBP.BattleItemHandle_AvatarBP_C");
		return pStaticClass;
	}


	bool IsSwimConfig();
	bool BPNeedCheckCapacityInHandleDisuse(EBattleItemDisuseReason* Reason);
	void GetWrapperClass(class UClass** WrapperClass);
	struct FBattleItemData ExtractItemData();
	void LocalHandleDisuse();
	class UWorld* GetWorldInternal();
	void SpawnWrapperOnGround(class UClass* WrapperClass, bool bUseRandomLoc);
	bool HandleDisuse(EBattleItemDisuseReason* Reason);
	bool HandleDrop(int* InCount, EBattleItemDropReason* Reason);
	bool HandlePickup(struct FBattleItemPickupInfo* PickupInfo, EBattleItemPickupReason* Reason, TScriptInterface<class UItemContainerInterface>* ItemContainer);
	bool HandleUse(struct FBattleItemUseTarget* Target, EBattleItemUseReason* Reason);
};


}

