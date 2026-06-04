const char* mySkinLuaScript = R"lua(

_G.skinIdMappings = {
    [101004]={101004,1101004046,1101004226,1101004236,1101004062,1101004078,1101004086,1101004098,1101004138,1101004163,1101004201,1101004209,1101004218},
    [101001]={101001,1101001089,1101001213,1101001172,1101001127,1101001142,1101001153,1101001115,1101001102,1101001230,1101001241},
    [101003]={101003,1103003208,1101003195,1101003187,1101003098,1101003166,1101003069,1101003218,1101003079,1101003118,1101003145,1101003180,1101003056},
    [103001]={103001,1103001191,1103001101,1103001178,1103001145},
    [102002]={102002,1102002136,1102002043,1102002061,1102002424},
    [103002]={103002,1103002030,1103002087,1103002105,1103002112},
    [103003]={103003,1103003042,1103003087,1103003062,1103003022,1103003051,1103003030,1103003079},
    [101008]={101008,1101008079,1101008126,1101008104,1101008146,1101008026,1101008061,1101008116,1101008051},
    [102003]={102003,1102003019,1102003030,1102003064,1102003079},
    [105010]={105010,1105010018,1105010007},
    [102004]={102004,1102004017,1102004033},
    [105002]={105002,1105002090,1105002075,1105002018,1105002034,1105002057,1105002062},
    [105001]={105001,1105001047,1105001068,1105001033,1105001061},
    [101006]={101006,1101006061,1101006074,1101006043,1101006032,1101006084},
    [104004]={104004,1104004034,1104004015,1104004040}
}
_G.skinIdMappings2 = _G.skinIdMappings
_G.WeaponSkinMap = _G.skinIdMappings

_G.LastBackApplyValue = 0
_G.CurrentBagApplicationValue = 0
_G.LastHelmetApplyValue = 0
_G.CurrentHelmetApplicationValue = 0
_G.UpdateMyKillCounter = false
_G.OutfitIndex = _G.OutfitIndex or {Suit=1,Bag=1,Helmet=1,Parachut=1,Pet=1}
_G.WeaponSkinIndex = _G.WeaponSkinIndex or {}

local lastConfig = {}

local function ReadConfigFile()
    -- Include all possible paths for Global, KR, VN, TW
    local possiblePaths = {
        '/storage/emulated/0/Android/data/com.tencent.ig/files/config.ini',
        '/storage/emulated/0/Android/data/com.pubg.krmobile/files/config.ini',
        '/storage/emulated/0/Android/data/com.vng.pubgmobile/files/config.ini',
        '/storage/emulated/0/Android/data/com.rekoo.pubgm/files/config.ini',
        '/storage/emulated/0/config.ini' -- Backup
    }
    
    local configPath = nil
    for _, path in ipairs(possiblePaths) do
        local file = io.open(path, 'r')
        if file then 
            file:close()
            configPath = path
            break 
        end
    end
    
    if not configPath then return end
    
    local file = io.open(configPath, 'r')
    local content = file:read('*all')
    file:close()
    
    local newConfig = {}
    for line in content:gmatch('[^\r\n]+') do
        local key, value = line:match('(%w+)=(%d+)')
        if key and value then newConfig[key] = tonumber(value) end
    end
    
    local function UpdateWep(key, id)
        if newConfig[key] and newConfig[key] ~= lastConfig[key] then
            if not _G.WeaponSkinIndex then _G.WeaponSkinIndex = {} end
            _G.WeaponSkinIndex[id] = newConfig[key] + 1
            lastConfig[key] = newConfig[key]
        end
    end
    
    UpdateWep('M416', 101004); UpdateWep('AKM', 101001); UpdateWep('SCAR', 101003); UpdateWep('M16A4', 101002)
    UpdateWep('GROZA', 101005); UpdateWep('AUG', 101006); UpdateWep('QBZ', 101007); UpdateWep('M762', 101008)
    UpdateWep('MK47', 101009); UpdateWep('G36C', 101010); UpdateWep('FAMAS', 101011)
    UpdateWep('Kar98', 103001); UpdateWep('M24', 103002); UpdateWep('AWM', 103003); UpdateWep('SKS', 103004)
    UpdateWep('VSS', 103005); UpdateWep('Mini14', 103006); UpdateWep('MK14', 103007); UpdateWep('SLR', 103009)
    UpdateWep('QBU', 103010); UpdateWep('MK12', 103011); UpdateWep('AMR', 103012); UpdateWep('Mosin', 103013)
    UpdateWep('UZI', 102001); UpdateWep('UMP', 102002); UpdateWep('Vector', 102003); UpdateWep('Thompson', 102004)
    UpdateWep('Bizon', 102005); UpdateWep('MP5K', 102007); UpdateWep('P90', 102009)
    UpdateWep('S12K', 104003); UpdateWep('DBS', 104004); UpdateWep('S1897', 104001); UpdateWep('S686', 104002)
    UpdateWep('M249', 105002); UpdateWep('DP28', 105001); UpdateWep('MG3', 105010)
    UpdateWep('Pan', 106001); UpdateWep('Machete', 106003); UpdateWep('Crowbar', 106002); UpdateWep('Sickle', 106004)
end
_G.ReadConfigFile = ReadConfigFile

local function get_skin_id(weaponID)
    if not weaponID then return nil end
    local index = (_G.WeaponSkinIndex and _G.WeaponSkinIndex[weaponID]) or 1
    local weaponSkins = _G.skinIdMappings[weaponID]
    if not weaponSkins then return weaponID end
    local skinID = weaponSkins[index]
    if not skinID then return weaponID end
    if not _G.skinIdCache2[skinID] then
        pcall(_G.download_item, skinID) 
        _G.skinIdCache2[skinID] = true
    end
    return skinID
end
_G.get_skin_id = get_skin_id
_G.get_skin_id2 = get_skin_id
-- 6. Damage Number UI Hook
pcall(function()
    local MyDamageNumMainUI = require("GameLua.Mod.Library.Client.UI.DamageNumMainUI")
    if MyDamageNumMainUI then
        local UWidgetLayoutLibrary = import("WidgetLayoutLibrary")
        local GameplayData = require("GameLua.GameCore.Data.GameplayData")
        
        MyDamageNumMainUI.__inner_impl.ShowDamage = function(self, Damage, X, Y, Z, uFSlateColor, nFontSize)
            if not self.FlyNumItemPool or Damage == 0 then return end
            
            local Item = self.FlyNumItemPool:GetOneItem()
            self.UIRoot.CanvasPanel_28:AddChild(Item)
            
            local damageInfo = { item = Item, worldPosition = FVector(X, Y, Z), updateHandle = nil }
            local uPlayerController = GameplayData.GetPlayerController()
            
            local function UpdateScreenPosition()
                if slua.isValid(damageInfo.item) then
                    local ScreenPos = UWidgetLayoutLibrary.ProjectWorldLocationToWidgetPositionReturnValue(uPlayerController, damageInfo.worldPosition)
                    if ScreenPos then damageInfo.item:SetRenderTranslation(ScreenPos) end
                end
            end
            
            UpdateScreenPosition()
            
            damageInfo.updateHandle = self:AddGameTimer(0.016, true, function()
                if slua.isValid(damageInfo.item) then UpdateScreenPosition()
                else if damageInfo.updateHandle then self:RemoveGameTimer(damageInfo.updateHandle) end end
            end)
            
            Item.DamageText:SetText(tostring(Damage))
            
            if slua.isValid(uFSlateColor) then Item.DamageText:SetColorAndOpacity(uFSlateColor)
            else Item.DamageText:SetColorAndOpacity(FSlateColor(FLinearColor(1, 1, 1, 1))) end
            
            local Font = Item.DamageText.Font
            Font.Size = (nFontSize and type(nFontSize) == "number") and nFontSize or 18
            Item.DamageText:SetFont(Font)
            
            local animTime = 5.0
            if _G.bFadeAnim then
                Item:PlayAnimation(Item.Fadein, 0, 1, 0, 1)
                animTime = Item.Fadein:GetEndTime()
            end
            
            self:AddGameTimer(animTime, false, function()
                if slua.isValid(Item) then
                    if damageInfo.updateHandle then self:RemoveGameTimer(damageInfo.updateHandle) end
                    self.FlyNumItemPool:FreeOneItem(Item)
                end
            end)
        end
    end
end)

-- Dynamic path detection for KillCounter (Writing)
function _G.GetKillCounterPath()
    local possiblePaths = {
        '/storage/emulated/0/Android/data/com.tencent.ig/files/NumberUpdate.txt',
        '/storage/emulated/0/Android/data/com.pubg.krmobile/files/NumberUpdate.txt',
        '/storage/emulated/0/Android/data/com.vng.pubgmobile/files/NumberUpdate.txt',
        '/storage/emulated/0/Android/data/com.rekoo.pubgm/files/NumberUpdate.txt'
    }
    
    -- Try to find existing file
    for _, path in ipairs(possiblePaths) do
        local file = io.open(path, 'r')
        if file then
            file:close()
            return path
        end
    end
    
    -- If no file, try to find writable directory
    for _, path in ipairs(possiblePaths) do
        local dir = path:match("(.*)/NumberUpdate.txt")
        -- Simple check: try open config in that dir to see if folder exists
        local f = io.open(dir .. "/config.ini", 'r') -- check if config exists in that folder
        if f then
            f:close()
            return path -- Return this path to write new file
        end
    end
    
    -- Default fallback
    return '/storage/emulated/0/Android/data/com.tencent.ig/files/NumberUpdate.txt'
end

_G.ActiveKillCounterPath = nil

local function saveKillCountToFile()
    if not _G.ActiveKillCounterPath then _G.ActiveKillCounterPath = _G.GetKillCounterPath() end
    local path = _G.ActiveKillCounterPath
    
    local file = io.open(path, 'w+')
    if not file then return end
    
    local content = '{\n'
    for weaponID, count in pairs(_G.killCountInfo) do
        content = content .. string.format('    [%d] = %d,\n', weaponID, count)
    end
    content = content .. '}'
    file:write(content)
    file:close()
    _G.lastFileContent = content
end

function _G.loadKillCountFromFile()
    if not _G.ActiveKillCounterPath then _G.ActiveKillCounterPath = _G.GetKillCounterPath() end
    local path = _G.ActiveKillCounterPath
    
    local file = io.open(path, 'r')
    if file then
        local content = file:read('*a')
        file:close()
        _G.lastFileContent = content
        
        if content ~= '' then
            content = content:gsub('\239\187\191', ''):gsub('^%s+', '')
            local tempTable = {}
            for weaponID, count in content:gmatch('%[(%d+)%]%s*=%s*(%d+)') do
                tempTable[tonumber(weaponID)] = tonumber(count)
            end
            if next(tempTable) then 
                _G.killCountInfo = tempTable 
            end
        end
    end
end

function _G.getKills(weaponID)
    return weaponID and _G.killCountInfo[weaponID] or 0
end

function _G.ForceUpdateKillCounterUI()
    pcall(function()
        local PlayerController = slua_GameFrontendHUD and slua_GameFrontendHUD:GetPlayerController()
        if not PlayerController or not slua.isValid(PlayerController) then return end
        
        local uCharacter = PlayerController:GetPlayerCharacterSafety()
        if not uCharacter or not slua.isValid(uCharacter) then return end
        
        local currweapon = uCharacter:GetCurrentWeapon()
        if not currweapon or not slua.isValid(currweapon) then return end
        
        local DefineID = currweapon:GetItemDefineID() and 
                         currweapon:GetItemDefineID().TypeSpecificID or 0
        if DefineID == 0 then return end
        
        local currentEquipAvatarID = slua.IndexReference(currweapon.synData:Get(7), "defineID").TypeSpecificID
        
        local UIManager = require("client.slua_ui_framework.manager")
        local MainKillCounter = UIManager.GetUI(UIManager.UI_Config_InGame.MainKillCounter)
        
        if MainKillCounter and slua.isValid(MainKillCounter) then
            local ModuleManager = require("client.module_framework.ModuleManager")
            local LogicKillCounter = ModuleManager.GetModule(ModuleManager.CommonModuleConfig.LogicKillCounter)
            
            local curEquipedKillCounter = LogicKillCounter:GetEquipedKillCounterId(6114302174, currentEquipAvatarID)
            if not curEquipedKillCounter or curEquipedKillCounter == 0 then
                curEquipedKillCounter = LogicKillCounter:GetBaseKillCounterIdByWeaponId(DefineID)
            end
            
            local kills = _G.getKills(DefineID)
            
            MainKillCounter:SetKillCounterItemShowWithNum(
                curEquipedKillCounter, 
                kills,
                currentEquipAvatarID
            )
            
            if MainKillCounter.KillCounterItem and MainKillCounter.KillCounterItem.SetVisibility then
                local ESlateVisibility = import("ESlateVisibility")
                MainKillCounter.KillCounterItem:SetVisibility(ESlateVisibility.Collapsed)
                MainKillCounter.KillCounterItem:SetVisibility(ESlateVisibility.SelfHitTestInvisible)
            end
            
            print('[KillCounter] UI Refreshed! Kills: ' .. kills)
        end
    end)
end

function _G.FileWatcher()
    if not _G.isFileWatcherActive then return end
    
    pcall(function()
        if not _G.ActiveKillCounterPath then _G.ActiveKillCounterPath = _G.GetKillCounterPath() end
        local path = _G.ActiveKillCounterPath
        
        local file = io.open(path, 'r')
        if not file then return end
        
        local currentContent = file:read('*a') or ""
        file:close()
        
        currentContent = currentContent:gsub('\239\187\191', ''):gsub('^%s+', ''):gsub('%s+$', '')
        
        if currentContent == "" or currentContent == _G.lastFileContent then return end
        
        _G.lastFileContent = currentContent
        
        -- Parse Content
        local tempTable = {}
        for weaponID, count in currentContent:gmatch('%[(%d+)%]%s*=%s*(%d+)') do
            tempTable[tonumber(weaponID)] = tonumber(count)
        end
        
        if not next(tempTable) then return end
        
        _G.killCountInfo = tempTable
        
        _G.ForceUpdateKillCounterUI()
        
        print('[FileWatcher] File changed! Force updating UI...')
    end)
end

function _G.addKill(weaponID, count)
    if not weaponID or not count then return end

    _G.killCountInfo[weaponID] =
        (_G.killCountInfo[weaponID] or 0) + count

    pcall(saveKillCountToFile)

    local PlayerController = slua_GameFrontendHUD and slua_GameFrontendHUD:GetPlayerController()
    if PlayerController then
        local uCharacter = PlayerController:GetPlayerCharacterSafety()
        if uCharacter then
            local currweapon = uCharacter:GetCurrentWeapon()
            if currweapon then
                local SkinID = slua.IndexReference(
                    currweapon.synData:Get(7),
                    "defineID"
                ).TypeSpecificID

                _G.OurkillCountSystem:UpdateMainKillCounterUI(
                    true,
                    weaponID,
                    SkinID
                )
            end
        end
    end
end


local SKillInfo = require("GameLua.Mod.BaseMod.Client.KillInfoTips.KillInfo")
local ECharacterHealthStatus = import("ECharacterHealthStatus")

local SKillInfoModuleManager = require("client.module_framework.ModuleManager")
local O_FileItem = SKillInfo.__inner_impl.FileItem

SKillInfo.__inner_impl.FileItem = function(self, DamageRecordData)
    if not self or not DamageRecordData then 
        return O_FileItem(self, DamageRecordData) 
    end

    local LogicKillCounter = SKillInfoModuleManager.GetModule(
        SKillInfoModuleManager.CommonModuleConfig.LogicKillCounter
    )
    if not LogicKillCounter then 
        return O_FileItem(self, DamageRecordData) 
    end

    local uCharacter = slua_GameFrontendHUD and 
                       slua_GameFrontendHUD:GetPlayerController() and
                       slua_GameFrontendHUD:GetPlayerController():GetPlayerCharacterSafety()
    if not uCharacter or not slua.isValid(uCharacter) then 
        return O_FileItem(self, DamageRecordData) 
    end

    local SelfName = uCharacter:GetPlayerNameSafety()
    if DamageRecordData.Causer == SelfName then
        local currWeapon = uCharacter:GetCurrentWeapon()
        if currWeapon and slua.isValid(currWeapon) then
            local DefineID = currWeapon:GetItemDefineID() and 
                             currWeapon:GetItemDefineID().TypeSpecificID or 0
            
            if DefineID ~= 0 then
                local ExpandData = slua.LuaArchiverDecode(
                    LuaStateWrapper, 
                    DamageRecordData.ExpandDataContent
                ) or {}
                
                local SupportKillCounter = LogicKillCounter:GetBaseKillCounterIdByWeaponId(DefineID)
                
                if SupportKillCounter and 
                   DamageRecordData.ResultHealthStatus == ECharacterHealthStatus.FinishedLastBreath then
                    ExpandData.KillCounterItemId = DefineID
                    ExpandData.KillCounterNum = (ExpandData.KillCounterNum or 0) + 1
                    
                    _G.addKill(DefineID, 1)
                end
                
                local synData = currWeapon.synData
                if synData and slua.isValid(synData) then
                    local weaponDefineID = slua.IndexReference(synData:Get(7), "defineID")
                    if weaponDefineID and slua.isValid(weaponDefineID) then
                        DamageRecordData.CauserWeaponAvatarID = weaponDefineID.TypeSpecificID
                    end
                end
                
                DamageRecordData.ExpandDataContent = slua.LuaArchiverEncode(
                    LuaStateWrapper, 
                    ExpandData
                )
            end
        end
    end

    O_FileItem(self, DamageRecordData)
end

local MyMainKillCounter = require("GameLua.Mod.BaseMod.Client.KillCounter.MainKillCounter")
local MyKillCountSubSystem = require("GameLua.Mod.BaseMod.Client.KillCounter.KillCounterUISubsystem")
local MyMainWeaponInfoItemUI = require("GameLua.Mod.BaseMod.Client.Backpack.MainWeaponInfoItemUI")
local MyMainWeaponKillCounter = require("GameLua.Mod.BaseMod.Client.KillCounter.MainWeaponKillCounter")
local SubsystemMgr = require("GameLua.GameCore.Module.Subsystem.SubsystemMgr")
local SlotBase = require("GameLua.Mod.BaseMod.Client.MainControlUI.SwitchWeaponSlotMode2")

_G.WeaponEvents = _G.WeaponEvents or { onWeaponChanged = function() end }
_G.OurkillCountSystem = MyKillCountSubSystem.__inner_impl

MyMainKillCounter.__inner_impl.OnRefreshUI = function(self, _, _, UID)
    pcall(function()
        local ModuleManager = require("client.module_framework.ModuleManager")
        local LogicKillCounter = ModuleManager.GetModule(ModuleManager.CommonModuleConfig.LogicKillCounter)
        local uCharacter = slua_GameFrontendHUD:GetPlayerController():GetPlayerCharacterSafety()
        if not uCharacter then return end
        
        local currweapon = uCharacter:GetCurrentWeapon()
        if currweapon then
            local DefineID = currweapon:GetItemDefineID().TypeSpecificID
            local currentEquipAvatarID = slua.IndexReference(currweapon.synData:Get(7), "defineID").TypeSpecificID
            local curEquipedKillCounter = LogicKillCounter:GetEquipedKillCounterId(6114302174, currentEquipAvatarID)
            
            self.KillCounterItem:SetKillCounterItemShowWithNum(
                curEquipedKillCounter, 
                _G.getKills(DefineID),
                currentEquipAvatarID
            )
        end
    end)
end

MyKillCountSubSystem.__inner_impl.CheckSupportKCUI = function(self)
    return true
end

o_CheckNeedMainKillCounterUI = MyKillCountSubSystem.__inner_impl.CheckNeedMainKillCounterUI
MyKillCountSubSystem.__inner_impl.CheckNeedMainKillCounterUI = function(self, Weapon, PlayerID)
    pcall(function()
        local uCharacter = slua_GameFrontendHUD:GetPlayerController():GetPlayerCharacterSafety()
        if not uCharacter then return end
        
        local currweapon = uCharacter:GetCurrentWeapon()
        if currweapon then
            local DefineID = currweapon:GetItemDefineID().TypeSpecificID
            _G.WeaponEvents.onWeaponChanged(DefineID)
            self:UpdateMainKillCounterUI(true, DefineID,
                slua.IndexReference(currweapon.synData:Get(7), "defineID").TypeSpecificID)
        end
    end)
end

o_UpdateMainKillCounterUI = MyKillCountSubSystem.__inner_impl.UpdateMainKillCounterUI
MyKillCountSubSystem.__inner_impl.UpdateMainKillCounterUI = function(self, bShow, WeaponID, AvatarID)
    pcall(function()
        o_UpdateMainKillCounterUI(self, bShow, WeaponID, AvatarID)
        
        local UIManager = require("client.slua_ui_framework.manager")
        local MainKillCounter = UIManager.GetUI(UIManager.UI_Config_InGame.MainKillCounter)
        local uCharacter = slua_GameFrontendHUD:GetPlayerController():GetPlayerCharacterSafety()
        
        if not uCharacter then return end
        
        local currweapon = uCharacter:GetCurrentWeapon()
        
        if not bShow and MainKillCounter then
            UIManager.CloseUI(UIManager.UI_Config_InGame.MainKillCounter)
        elseif bShow and currweapon then
            local DefineID = currweapon:GetItemDefineID().TypeSpecificID
            local currentEquipAvatarID = slua.IndexReference(currweapon.synData:Get(7), "defineID").TypeSpecificID
            
            local ModuleManager = require("client.module_framework.ModuleManager")
            local LogicKillCounter = ModuleManager.GetModule(ModuleManager.CommonModuleConfig.LogicKillCounter)
            local SupportKillCounter = LogicKillCounter:GetBaseKillCounterIdByWeaponId(DefineID)
            
            if SupportKillCounter == nil and MainKillCounter then
                UIManager.CloseUI(UIManager.UI_Config_InGame.MainKillCounter)
            elseif DefineID == currentEquipAvatarID and MainKillCounter then
                UIManager.CloseUI(UIManager.UI_Config_InGame.MainKillCounter)
            else
                local curEquipedKillCounter = LogicKillCounter:GetEquipedKillCounterId(6114302174, currentEquipAvatarID)
                
                if not MainKillCounter then
                    UIManager.ShowUI(UIManager.UI_Config_InGame.MainKillCounter, DefineID, currentEquipAvatarID)
                    MainKillCounter = UIManager.GetUI(UIManager.UI_Config_InGame.MainKillCounter)
                    if MainKillCounter then
                        MainKillCounter:SetKillCounterItemShowWithNum(
                            curEquipedKillCounter, 
                            _G.getKills(DefineID),
                            currentEquipAvatarID
                        )
                    end
                else
                    MainKillCounter:UpdateWeaponID(DefineID, currentEquipAvatarID)
                    MainKillCounter:SetKillCounterItemShowWithNum(
                        curEquipedKillCounter, 
                        _G.getKills(DefineID),
                        currentEquipAvatarID
                    )
                end
            end
        end
    end)
end

o_DOnRefresh = MyMainWeaponKillCounter.__inner_impl.OnRefresh
MyMainWeaponKillCounter.__inner_impl.OnRefresh = function(self, SelfUID)
    pcall(function()
        local ModuleManager = require("client.module_framework.ModuleManager")
        local LogicKillCounter = ModuleManager.GetModule(ModuleManager.CommonModuleConfig.LogicKillCounter)
        local curEquipedKillCounter = LogicKillCounter:GetMyEquipedKillCounterId(_G.get_skin_id2(self.WeaponID))
        
        self.KillCounterItem:SetKillCounterItemShowWithNum(
            curEquipedKillCounter, 
            _G.getKills(self.WeaponID),
            _G.get_skin_id2(self.WeaponID)
        )
    end)
end

o_DUpdateWeaponAppearanceInfo = MyMainWeaponInfoItemUI.__inner_impl.UpdateWeaponAppearanceInfo
MyMainWeaponInfoItemUI.__inner_impl.UpdateWeaponAppearanceInfo = function(self, TypeSpecificID, BattleData, DragOrigin)
    pcall(function()
        o_DUpdateWeaponAppearanceInfo(self, TypeSpecificID, BattleData, DragOrigin)
        self:UpdateKillCounter(true)
    end)
end

o_DUpdateKillCounter = MyMainWeaponInfoItemUI.__inner_impl.UpdateKillCounter
MyMainWeaponInfoItemUI.__inner_impl.UpdateKillCounter = function(self, bShow)
    pcall(function()
        local KillCounterUISubsystem = SubsystemMgr:Get("KillCounterUISubsystem")
        
        if not KillCounterUISubsystem then bShow = false end
        
        if bShow then
            local ModuleManager = require("client.module_framework.ModuleManager")
            local LogicKillCounter = ModuleManager.GetModule(ModuleManager.CommonModuleConfig.LogicKillCounter)
            local curEquipedKillCounter = LogicKillCounter:GetBaseKillCounterIdByWeaponId(self.ItemID)
            
            if self.ItemID == self.WeaponIDOrAvatarID then
                self.UIRoot.CanvasPanel_KillCounter:SetVisibility(UEnums.GSlateVisibility.Collapsed)
                return
            end
            
            if not curEquipedKillCounter then
                self.UIRoot.CanvasPanel_KillCounter:SetVisibility(UEnums.GSlateVisibility.Collapsed)
                return
            end
            
            local UIManager = require("client.slua_ui_framework.manager")
            if not self.KillCounterUI then
                self.KillCounterUI = UIManager.ShowUI(UIManager.UI_Config_InGame.MainWeaponKillCounter, 
                    self.ItemID, self.WeaponIDOrAvatarID, self)
                self.UIRoot.CanvasPanel_KillCounter.Slot:SetLayer(1)
            else
                self.KillCounterUI:UpdateWeaponID(self.ItemID, self.WeaponIDOrAvatarID)
                self.UIRoot.CanvasPanel_KillCounter:SetVisibility(UEnums.GSlateVisibility.SelfHitTestInvisible)
            end
        end
    end)
end

local o_CheckShowKCIcon = SlotBase.__inner_impl.CheckShowKCIcon
SlotBase.__inner_impl.CheckShowKCIcon = function(self)
    pcall(function()
        o_CheckShowKCIcon(self)
        
        local ESlateVisibility = import("ESlateVisibility")
        local ModuleManager = require("client.module_framework.ModuleManager")
        local LogicKillCounter = ModuleManager.GetModule(ModuleManager.CommonModuleConfig.LogicKillCounter)
        local CurWeapon = self:GetCurrentWeapon()
        
        if not slua.isValid(CurWeapon) then
            self.KillCounterImg:SetVisibility(ESlateVisibility.Collapsed)
            return
        end
        
        local WeaponID = CurWeapon:GetWeaponID()
        local SupportKillCounter = LogicKillCounter:GetBaseKillCounterIdByWeaponId(WeaponID)
        if SupportKillCounter then
            self.KillCounterImg:SetVisibility(ESlateVisibility.SelfHitTestInvisible)
        end
    end)
end

_G.lastDisplayedKills = {}

function _G.CheckAndRefreshKillUI()
    pcall(function()
        local PlayerController = slua_GameFrontendHUD and slua_GameFrontendHUD:GetPlayerController()
        if not PlayerController then return end
        
        local uCharacter = PlayerController:GetPlayerCharacterSafety()
        if not uCharacter then return end
        
        local currweapon = uCharacter:GetCurrentWeapon()
        if not currweapon then return end
        
        local DefineID = currweapon:GetItemDefineID().TypeSpecificID
        if DefineID == 0 then return end
        
        local realKills = _G.getKills(DefineID)
        local lastShown = _G.lastDisplayedKills[DefineID] or -1
        
        if realKills ~= lastShown then
            
            local UIManager = require("client.slua_ui_framework.manager")
            local MainKillCounter = UIManager.GetUI(UIManager.UI_Config_InGame.MainKillCounter)
            
            if MainKillCounter and slua.isValid(MainKillCounter) then
                local currentEquipAvatarID = slua.IndexReference(currweapon.synData:Get(7), "defineID").TypeSpecificID
                local ModuleManager = require("client.module_framework.ModuleManager")
                local LogicKillCounter = ModuleManager.GetModule(ModuleManager.CommonModuleConfig.LogicKillCounter)
                
                local curEquipedKillCounter = LogicKillCounter:GetEquipedKillCounterId(6114302174, currentEquipAvatarID)
                if not curEquipedKillCounter or curEquipedKillCounter == 0 then
                    curEquipedKillCounter = LogicKillCounter:GetBaseKillCounterIdByWeaponId(DefineID)
                end
                
                MainKillCounter:SetKillCounterItemShowWithNum(
                    curEquipedKillCounter, 
                    realKills,
                    currentEquipAvatarID
                )
                
                _G.lastDisplayedKills[DefineID] = realKills
                -- print('[Watcher] Auto-Updated UI to: ' .. realKills)
            end
        end
    end)
end

_G.WeaponEvents.onWeaponChanged = function(weaponId)
    pcall(function()
        local PlayerController = slua_GameFrontendHUD and slua_GameFrontendHUD:GetPlayerController()
        if not PlayerController or not slua.isValid(PlayerController) then return end
        
        local uCharacter = PlayerController:GetPlayerCharacterSafety()
        if not uCharacter or not slua.isValid(uCharacter) or not _G.OurkillCountSystem then return end
        
        local currweapon = uCharacter:GetCurrentWeapon()
        if not currweapon then return end
        
        local DefineID = currweapon:GetItemDefineID().TypeSpecificID
        local SkinID = slua.IndexReference(currweapon.synData:Get(7), "defineID").TypeSpecificID
        _G.OurkillCountSystem:UpdateMainKillCounterUI(true, DefineID, SkinID)
    end)
end

_G.loadKillCountFromFile()
_G.isFileWatcherActive = true
print('[KillCounter] System ready with Real-Time UI Updates!')

if _G.Mytimer_ticker then
    pcall(function()
--		_G.Mytimer_ticker.AddTimerLoop(3, AntiCheatHandler, -1, 1)
--        _G.Mytimer_ticker.AddTimerLoop(0.8, _G.GameAvatarHandlerweapons, -1, 1)
--        _G.Mytimer_ticker.AddTimerLoop(1, _G.InitializeAntiReport, -1, 1)
--        _G.Mytimer_ticker.AddTimerLoop(0.05, _G.GameAvatarHandlerkillcounter, -1, 1)        
        _G.Mytimer_ticker.AddTimerLoop(0, _G.FileWatcher, -1, 0.05)
        print('[System] All timers running!')
    end)
end
)lua";