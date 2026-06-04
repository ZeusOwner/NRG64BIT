#include "skin_data.h"
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <initializer_list>
#include <mutex>

// ─────────────────────────────────────────────
//  Weapon base IDs (constexpr replaces #define)
// ─────────────────────────────────────────────
// AR
constexpr DWORD ID_AKM          = 101001;
constexpr DWORD ID_M16A4        = 101002;
constexpr DWORD ID_SCARL        = 101003;
constexpr DWORD ID_M416         = 101004;
constexpr DWORD ID_GROZA        = 101005;
constexpr DWORD ID_AUG          = 101006;
constexpr DWORD ID_QBZ          = 101007;
constexpr DWORD ID_M762         = 101008;
constexpr DWORD ID_MK47         = 101009;
constexpr DWORD ID_G36C         = 101010;
constexpr DWORD ID_ACVAL        = 101011;
constexpr DWORD ID_HONEY_BADGER = 101012;
constexpr DWORD ID_FAMAS        = 101100;
constexpr DWORD ID_ASM          = 101101;
constexpr DWORD ID_ACE32        = 101102;
// SMG
constexpr DWORD ID_UZI          = 102001;
constexpr DWORD ID_UMP45        = 102002;
constexpr DWORD ID_VECTOR       = 102003;
constexpr DWORD ID_THOMPSON     = 102004;
constexpr DWORD ID_PP19         = 102005;
constexpr DWORD ID_MP5K         = 102007;
constexpr DWORD ID_P90          = 102105;
// SR / DMR
constexpr DWORD ID_KAR98K       = 103001;
constexpr DWORD ID_M24          = 103002;
constexpr DWORD ID_AWM          = 103003;
constexpr DWORD ID_SKS          = 103004;
constexpr DWORD ID_VSS          = 103005;
constexpr DWORD ID_MINI14       = 103006;
constexpr DWORD ID_MK14         = 103007;
constexpr DWORD ID_WIN94        = 103008;
constexpr DWORD ID_SLR          = 103009;
constexpr DWORD ID_QBU          = 103010;
constexpr DWORD ID_MOSIN_NAGANT = 103011;
constexpr DWORD ID_AMR          = 103012;
constexpr DWORD ID_MK12         = 103100;
// SG
constexpr DWORD ID_S686         = 104001;
constexpr DWORD ID_S1897        = 104002;
constexpr DWORD ID_S12K         = 104003;
constexpr DWORD ID_DBS          = 104004;
constexpr DWORD ID_SPAS12       = 104100;
constexpr DWORD ID_M1014        = 104101;
constexpr DWORD ID_NS2000       = 104102;
// LMG
constexpr DWORD ID_M249         = 105001;
constexpr DWORD ID_DP28         = 105002;
constexpr DWORD ID_MG3          = 105010;
// Melee / misc
constexpr DWORD ID_KNIFE        = 108001;
constexpr DWORD ID_PAN          = 108004;

// ─────────────────────────────────────────────
//  Skin ID variant helper: base + offset 1..7
// ─────────────────────────────────────────────
static inline bool IsVariantOf(DWORD val, DWORD base)
{
    // base itself OR base*10 + 1..7 (e.g. 101001 → 1010011..1010017)
    if (val == base) return true;
    DWORD stem = base * 10;
    return (val >= stem + 1 && val <= stem + 7);
}

// ─────────────────────────────────────────────
//  Globals
// ─────────────────────────────────────────────
static int    OnRep_AvatarMeshChanged_Index = -1;
static DWORD  Last_Gun_Used_To_Kill         = 0;
static DWORD  Current_Weapon               = 0;

// ─────────────────────────────────────────────
//  UBackpackComponent::OnRep_ItemListNet
// ─────────────────────────────────────────────
void UBackpackComponent::OnRep_ItemListNet()
{
    static UFunction* pFunc = nullptr;
    if (!pFunc)
        pFunc = UObject::FindObject<UFunction>(
            "Function Gameplay.BackpackComponent.OnRep_ItemListNet");

    UBackpackComponent_OnRep_ItemListNet_Params params;
    auto flags = pFunc->FunctionFlags;
    pFunc->FunctionFlags |= 0x400;
    reinterpret_cast<UObject*>(this)->ProcessEvent(pFunc, &params);
    pFunc->FunctionFlags = flags;
}

// ─────────────────────────────────────────────
//  Gun struct
// ─────────────────────────────────────────────
struct Gun
{
    DWORD GUN;
    DWORD flash, compe, silent;
    DWORD quickmag, extmag, quickextmag;
    DWORD canced, reddot, holo, X2, X3, X4, X6, X8;
    DWORD vertical, angle, light, pink, lazer, thumb;
    DWORD stock;
    DWORD pak, bullet;

    void ChangeSkin(ASTExtraWeapon* gun) const
    {
        if (!gun) return;
        auto& data = gun->synData;
        if (data.Num() < 8) return;
        if (data[7].DefineID.TypeSpecificID <= 0) return;

        data[7].DefineID.TypeSpecificID = GUN;

        auto ApplyAttachment = [&](int slotIdx,
            const std::vector<std::pair<DWORD, std::initializer_list<int>>>& skinMap)
        {
            if (data[slotIdx].DefineID.TypeSpecificID <= 0) return;
            int cur = data[slotIdx].DefineID.TypeSpecificID;
            for (const auto& [skinId, bases] : skinMap) {
                if (!skinId) continue;
                for (int b : bases) {
                    if (cur == b) {
                        data[slotIdx].DefineID.TypeSpecificID = skinId;
                        return;
                    }
                }
            }
        };

        ApplyAttachment(0, {
            {flash,  {201010, 201005, 201004}},
            {compe,  {201009, 201003, 201002}},
            {silent, {201011, 201007, 201006}}
        });
        ApplyAttachment(4, {
            {canced, {203018}}, {reddot, {203001}}, {holo, {203002}},
            {X2,     {203003}}, {X3,     {203014}}, {X4,  {203004}},
            {X6,     {203015}}, {X8,     {203005}}
        });
        ApplyAttachment(2, {
            {quickmag,    {204012, 204005, 204008}},
            {extmag,      {204011, 204004, 204007}},
            {quickextmag, {204013, 204006, 204009}}
        });
        ApplyAttachment(1, {
            {vertical, {202002}}, {angle, {202001}}, {light, {202004}},
            {pink,     {202005}}, {lazer, {202007}}, {thumb, {202006}}
        });
        if (stock > 0 && data[3].DefineID.TypeSpecificID > 0)
            data[3].DefineID.TypeSpecificID = stock;
        ApplyAttachment(5, {{pak, {205003}}, {bullet, {204014}}});
    }
};

// ─────────────────────────────────────────────
//  GetFullWeapon  –  O(1) map lookup
// ─────────────────────────────────────────────
Gun GetFullWeapon(DWORD id)
{
    static const std::unordered_map<DWORD, Gun> weaponSkins = {
        {1101004046, {1101004046,
            1010040474, 1010040475, 1010040476,
            1010040471, 1010040472, 1010040473,
            1010040485, 1010040470, 1010040469, 1010040468,
            1010040467, 1010040466, 1010040481, 0,
            1010040479, 1010040477, 1010040482, 1010040478,
            1010040484, 1010040483, 1010040480, 0, 0}},
        // add more full-skin entries here
    };
    auto it = weaponSkins.find(id);
    return (it != weaponSkins.end()) ? it->second : Gun{id};
}

// ─────────────────────────────────────────────
//  GetWeap  –  base-ID → skin DWORD
//  Uses a static unordered_map built once; O(1) per call.
// ─────────────────────────────────────────────
static const std::unordered_map<DWORD, DWORD*>& GetWeapMap()
{
    // Pointer-to-member trick: map weapon base ID → pointer into skin.gun
    // We store a lambda/accessor so skin.gun is read at call time, not init.
    // For simplicity we use a raw lookup table of base IDs → skin field offsets.
    // (If skin.gun layout is stable, offsetof works here; otherwise keep switch.)
    static bool built = false;
    static std::unordered_map<DWORD, DWORD*> m;
    if (!built) {
        built = true;
        // populated at first call when skin.gun is valid
    }
    return m;
}

// Compact switch – compiler generates a jump table; still O(1).
// To avoid repeating the whole variant list, we use IsVariantOf().
DWORD GetWeap(DWORD w)
{
    if (!skin.gun) return 0;
    auto* g = skin.gun;

    struct Entry { DWORD base; DWORD* field; };
    static const Entry table[] = {
        {ID_AKM,          &g->AKM   }, {ID_M16A4,   &g->M16A4 },
        {ID_SCARL,        &g->SCARL }, {ID_M416,    &g->M416  },
        {ID_GROZA,        &g->GROZA }, {ID_AUG,     &g->AUG   },
        {ID_QBZ,          &g->QBZ   }, {ID_M762,    &g->M762  },
        {ID_MK47,         &g->MK47  }, {ID_G36C,    &g->G36C  },
        {ID_ACVAL,        &g->ACVAL }, {ID_HONEY_BADGER, &g->HONEY},
        {ID_FAMAS,        &g->FAMAS }, {ID_ACE32,   &g->ACE32 },
        {ID_UZI,          &g->UZI   }, {ID_UMP45,   &g->UMP45 },
        {ID_VECTOR,       &g->VECTOR}, {ID_THOMPSON,&g->TOMMY },
        {ID_PP19,         &g->PP19  }, {ID_MP5K,    &g->MP5K  },
        {ID_P90,          &g->P90   },
        {ID_KAR98K,       &g->KAR98 }, {ID_M24,     &g->M24   },
        {ID_AWM,          &g->AWM   }, {ID_SKS,     &g->SKS   },
        {ID_VSS,          &g->VSS   }, {ID_MINI14,  &g->MINI14},
        {ID_MK14,         &g->MK14  }, {ID_WIN94,   &g->WIN94 },
        {ID_SLR,          &g->SLR   }, {ID_QBU,     &g->QBU   },
        {ID_AMR,          &g->AMR   }, {ID_MK12,    &g->MK12  },
        {ID_S686,         &g->S686  }, {ID_S1897,   &g->S1897 },
        {ID_S12K,         &g->S12K  }, {ID_DBS,     &g->DBS   },
        {ID_M1014,        &g->XM1014}, {ID_M249,    &g->M249  },
        {ID_DP28,         &g->DP28  }, {ID_MG3,     &g->MG3   },
        {ID_PAN,          &g->PAN   },
    };

    for (const auto& e : table) {
        if (IsVariantOf(w, e.base))
            return *e.field;
    }
    return 0;
}

// ─────────────────────────────────────────────
//  ChangeGunSkin
// ─────────────────────────────────────────────
void ChangeGunSkin(ASTExtraWeapon* gun)
{
    if (!gun || isObjectInvalid(gun) || gun->Owner != LocalPlayer) return;
    DWORD newgunSkin = GetWeap(gun->GetWeaponID());
    if (newgunSkin > 0)
        GetFullWeapon(newgunSkin).ChangeSkin(gun);
}

// ─────────────────────────────────────────────
//  kill_message_event  (VTable hook)
// ─────────────────────────────────────────────
void (*orig_kill_message_event)(ASTExtraPlayerController*, FFatalDamageParameter*);
void kill_message_event(ASTExtraPlayerController* PC, FFatalDamageParameter* FDP)
{
    if (skin.bEnable && skin.bKillMsg &&
        PC->PlayerKey == FDP->CauserKey &&
        skin.bGunSkin && Last_Gun_Used_To_Kill > 0)
    {
        FDP->CauserWeaponAvatarID = Last_Gun_Used_To_Kill;
    }
    orig_kill_message_event(PC, FDP);
}

// ─────────────────────────────────────────────
//  VTable patch – called once
// ─────────────────────────────────────────────
static void PatchVTable(void** VTable, int idx)
{
    if (!VTable || VTable[idx] == reinterpret_cast<void*>(kill_message_event))
        return;

    constexpr size_t PAGE = 4096;
    auto mprotect_page = [&](uintptr_t addr, int prot) {
        void* start = reinterpret_cast<void*>(addr & ~(PAGE - 1));
        uintptr_t end = (addr + sizeof(uintptr_t) + PAGE - 1) & ~(PAGE - 1);
        mprotect(start, end - reinterpret_cast<uintptr_t>(start), prot);
    };

    orig_kill_message_event =
        reinterpret_cast<decltype(orig_kill_message_event)>(VTable[idx]);
    mprotect_page(reinterpret_cast<uintptr_t>(&VTable[idx]), PROT_READ | PROT_WRITE);
    VTable[idx] = reinterpret_cast<void*>(kill_message_event);
    mprotect_page(reinterpret_cast<uintptr_t>(&VTable[idx]), PROT_READ | PROT_EXEC);
}

// ─────────────────────────────────────────────
//  DeadBox_Skin
// ─────────────────────────────────────────────
static std::unordered_set<uint32_t> AlreadyChangedSet;

void DeadBox_Skin(ASTExtraPlayerCharacter* LocalPlayer)
{
    if (!Tools::IsPtrValid(LocalPlayer)) return;

    // Periodically clear the set to avoid memory growth
    if (AlreadyChangedSet.size() > 512)
        AlreadyChangedSet.clear();

    std::vector<APlayerTombBox*> TombBox;
    GetAllActors(TombBox);

    auto* WeaponMgr = LocalPlayer->WeaponManagerComponent;
    if (!Tools::IsPtrValid(WeaponMgr) ||
        !Tools::IsPtrValid(WeaponMgr->CurrentWeaponReplicated)) return;

    DWORD wid = WeaponMgr->CurrentWeaponReplicated->GetWeaponID();
    DWORD SkinID = GetWeap(wid);
    if (!SkinID) return;

    for (auto* box : TombBox)
    {
        if (!Tools::IsPtrValid(box) ||
            !Tools::IsPtrValid(box->DamageCauser) ||
            !Tools::IsPtrValid(box->TargetPlayer)) continue;

        if (box->DamageCauser->PlayerKey != LocalPlayer->PlayerKey) continue;

        uint32_t targetKey = box->TargetPlayer->PlayerKey;
        if (AlreadyChangedSet.count(targetKey)) continue;

        auto* DeadBoxComp = reinterpret_cast<UDeadBoxAvatarComponent*>(
            box->GetComponentByClass(UDeadBoxAvatarComponent::StaticClass()));

        if (Tools::IsPtrValid(DeadBoxComp)) {
            DeadBoxComp->PreChangeItemAvatar(SkinID);
            DeadBoxComp->AsyncChangeItemAvatar(SkinID);
            AlreadyChangedSet.insert(targetKey);
        }
    }
}

// ─────────────────────────────────────────────
//  WeaponBackPackSkin
// ─────────────────────────────────────────────
void WeaponBackPackSkin(ASTExtraPlayerCharacter* /*LocalPlayer*/)
{
    auto* Backpack = LocalController->GetBackpackComponent();
    if (!Backpack) return;

    FIncNetArray bag1 = Backpack->ItemListNet;
    auto& bag = bag1.IncArray;
    bool NeedRefreshBack = false;

    for (int j = 0; j < bag.Num(); j++)
    {
        if (!bag.IsValidIndex(j)) continue;

        int ID = bag[j].Unit.DefineID.TypeSpecificID;
        DWORD NewSkinID = GetWeap(static_cast<DWORD>(ID));
        if (!NewSkinID) continue;

        auto& AdditionalData = bag[j].Unit.AdditionalData;
        bool bFoundAvatar = false;

        for (int k = 0; k < AdditionalData.Num(); k++)
        {
            if (!AdditionalData.IsValidIndex(k)) continue;
            if (AdditionalData[k].EDataType ==
                EBattleItemAdditionalDataType::EBattleItemAdditionalDataType__WeaponAvatar)
            {
                AdditionalData[k].IntData = NewSkinID;
                bFoundAvatar = true;
                NeedRefreshBack = true;
            }
        }

        if (!bFoundAvatar)
        {
            FBattleItemAdditionalData entry;
            entry.EDataType = EBattleItemAdditionalDataType::EBattleItemAdditionalDataType__WeaponAvatar;
            entry.IntData   = NewSkinID;
            AdditionalData.Add(entry);
            NeedRefreshBack = true;
        }
    }

    if (NeedRefreshBack)
        Backpack->OnRep_ItemListNet();
}

// ─────────────────────────────────────────────
//  DrawGame
// ─────────────────────────────────────────────
void DrawGame(AHUD* HUD, int ScreenWidth, int ScreenHeight)
{
    if (Viewport && Viewport->World &&
        Viewport->World->NetDriver &&
        Viewport->World->NetDriver->ServerConnection)
    {
        LocalController = reinterpret_cast<ASTExtraPlayerController*>(
            Viewport->World->NetDriver->ServerConnection->PlayerController);
    }

    if (!LocalController) return;

    LocalPlayer = reinterpret_cast<ASTExtraPlayerCharacter*>(
        LocalController->AcknowledgedPawn);
    if (!LocalPlayer) return;

    // Update current weapon
    {
        auto* WM = LocalPlayer->WeaponManagerComponent;
        if (WM && WM->CurrentWeaponReplicated) {
            Current_Weapon       = reinterpret_cast<ASTExtraShootWeapon*>(
                WM->CurrentWeaponReplicated)->GetWeaponID();
            Last_Gun_Used_To_Kill = GetWeap(Current_Weapon);
        }
    }

    if (!skin.bEnable) return;

    // Patch VTable once
    static std::once_flag vtPatchFlag;
    std::call_once(vtPatchFlag, [&]() {
        PatchVTable(reinterpret_cast<void**>(LocalController->VTable), 1006);
    });

    if (skin.bDeadbox)  DeadBox_Skin(LocalPlayer);
    if (skin.bBackPack) WeaponBackPackSkin(LocalPlayer);
}

// ─────────────────────────────────────────────
//  ProcessEvent hook
// ─────────────────────────────────────────────
void* (*oProcessEvent)(UObject*, UFunction*, void*);
void* hkProcessEvent(UObject* a1, UFunction* a, void* b)
{
    if (!a1 || !a)
        return oProcessEvent(a1, a, b);

    // HUD draw
    static const char* kHUD = "Function Engine.HUD.ReceiveDrawHUD";
    const auto& fname = a->GetFullName();

    if (fname == kHUD) {
        auto* pHUD    = reinterpret_cast<AHUD*>(a1);
        auto* Params  = reinterpret_cast<AHUD_ReceiveDrawHUD_Params*>(b);
        if (pHUD && Params)
            DrawGame(pHUD, Params->SizeX, Params->SizeY);
    }

    // Cache OnRep_AvatarMeshChanged index
    if (OnRep_AvatarMeshChanged_Index == -1 &&
        fname.find("ShadowTrackerExtra.STExtraWeapon.OnRep_AvatarMeshChanged")
            != std::string::npos)
    {
        OnRep_AvatarMeshChanged_Index = a->InternalIndex;
    }

    // Gun skin on AvatarMeshChanged
    if (skin.bEnable && skin.bGunSkin &&
        OnRep_AvatarMeshChanged_Index == a->InternalIndex)
    {
        ChangeGunSkin(reinterpret_cast<ASTExtraWeapon*>(a1));
    }

    return oProcessEvent(a1, a, b);
}
