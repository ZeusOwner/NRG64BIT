package com.bearmod;

import android.content.SharedPreferences;
import android.view.View;
import android.widget.TextView;

import java.lang.ref.WeakReference;
import java.util.ArrayList;
import java.util.EnumMap;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map;

public class LanguageManager {
    public static final String LANGUAGE_EN = "en";
    public static final String LANGUAGE_ZH = "zh";
    public static final String PREF_LANGUAGE_CODE = "LANGUAGE_CODE";
    public static final String PREF_LANGUAGE_LEGACY = "LANGUAGE";

    private static final LanguageManager INSTANCE = new LanguageManager();

    private final Map<String, EnumMap<LanguageKey, String>> translations = new HashMap<>();
    private final List<LocalizedTextBinding> bindings = new ArrayList<>();
    private String currentLanguage = LANGUAGE_EN;
    private SharedPreferences prefs;

    private LanguageManager() {
        registerLanguage(LANGUAGE_EN, createEnglishMap());
        registerLanguage(LANGUAGE_ZH, createChineseMap());
    }

    public static LanguageManager getInstance() {
        return INSTANCE;
    }

    public void initialize(SharedPreferences prefs) {
        this.prefs = prefs;
        String code = prefs != null ? prefs.getString(PREF_LANGUAGE_CODE, null) : null;
        if (isSupportedLanguage(code)) {
            currentLanguage = code;
            return;
        }
        int legacyIndex = 0;
        if (prefs != null) {
            try {
                legacyIndex = Integer.parseInt(prefs.getString(PREF_LANGUAGE_LEGACY, "0"));
            } catch (NumberFormatException ignored) {
                legacyIndex = 0;
            }
        }
        currentLanguage = legacyIndex == 1 ? LANGUAGE_ZH : LANGUAGE_EN;
    }

    public void registerLanguage(String languageCode, EnumMap<LanguageKey, String> map) {
        if (languageCode == null || map == null) return;
        translations.put(languageCode, map);
    }

    public String getString(LanguageKey key) {
        if (key == null) return "";
        EnumMap<LanguageKey, String> currentMap = translations.get(currentLanguage);
        String value = currentMap != null ? currentMap.get(key) : null;
        if (value != null) return value;
        EnumMap<LanguageKey, String> englishMap = translations.get(LANGUAGE_EN);
        value = englishMap != null ? englishMap.get(key) : null;
        return value != null ? value : key.name();
    }

    public void setLanguage(String languageCode) {
        if (!isSupportedLanguage(languageCode)) {
            languageCode = LANGUAGE_EN;
        }
        if (languageCode.equals(currentLanguage)) {
            persistSelectedLanguage();
            return;
        }
        currentLanguage = languageCode;
        persistSelectedLanguage();
        refreshVisibleUI();
    }

    public String getLanguage() {
        return currentLanguage;
    }

    public int getLegacyLanguageIndex() {
        return LANGUAGE_ZH.equals(currentLanguage) ? 1 : 0;
    }

    public void bind(TextView textView, LanguageKey key) {
        if (textView == null || key == null) return;
        textView.setText(getString(key));
        bindings.add(new LocalizedTextBinding(textView, key));
    }

    public void refreshVisibleUI() {
        Iterator<LocalizedTextBinding> iterator = bindings.iterator();
        while (iterator.hasNext()) {
            LocalizedTextBinding binding = iterator.next();
            TextView view = binding.viewRef.get();
            if (view == null) {
                iterator.remove();
                continue;
            }
            view.setText(getString(binding.key));
            View parent = view;
            while (parent != null) {
                parent.requestLayout();
                parent.invalidate();
                Object maybeParent = parent.getParent();
                parent = maybeParent instanceof View ? (View) maybeParent : null;
            }
        }
    }

    public void clearBindings() {
        bindings.clear();
    }

    private void persistSelectedLanguage() {
        if (prefs == null) return;
        prefs.edit()
                .putString(PREF_LANGUAGE_CODE, currentLanguage)
                .putString(PREF_LANGUAGE_LEGACY, String.valueOf(getLegacyLanguageIndex()))
                .apply();
    }

    private boolean isSupportedLanguage(String languageCode) {
        return LANGUAGE_EN.equals(languageCode) || LANGUAGE_ZH.equals(languageCode);
    }

    private static EnumMap<LanguageKey, String> createEnglishMap() {
        EnumMap<LanguageKey, String> map = new EnumMap<>(LanguageKey.class);
        map.put(LanguageKey.MENU_MAIN, "Main Menu");
        map.put(LanguageKey.MENU_ESP, "ESP Menu");
        map.put(LanguageKey.MENU_AIMBOT, "Aim Menu");
        map.put(LanguageKey.MENU_SKIN, "Skin Menu");
        map.put(LanguageKey.MENU_ITEMS, "Item Menu");
        map.put(LanguageKey.TEXT_LANGUAGE, "Language");
        map.put(LanguageKey.LANG_ENGLISH, "English");
        map.put(LanguageKey.LANG_CHINESE, "Chinese");
        map.put(LanguageKey.BUTTON_HIDE_MENU, "Hide Menu");
        map.put(LanguageKey.SWITCH_HIDE_MODE, "Hide Mode");
        map.put(LanguageKey.SECTION_ESP, "ESP");
        map.put(LanguageKey.SWITCH_ESP_LINE, "Line");
        map.put(LanguageKey.SWITCH_ESP_BONE, "Bone");
        map.put(LanguageKey.SWITCH_ESP_INFO, "Info");
        map.put(LanguageKey.SWITCH_ESP_WEAPON, "Weapon");
        map.put(LanguageKey.SWITCH_GRENADE_WARNING, "Grenade Warning");
        map.put(LanguageKey.SWITCH_360_ALERT, "360 Alert");
        map.put(LanguageKey.SWITCH_RADAR_MAP, "Radar MAP");
        map.put(LanguageKey.SLIDER_RADAR_SIZE, "RadarMAP-Size");
        map.put(LanguageKey.SWITCH_IGNOREBOT_ESP, "IgnoreBot-ESP");
        map.put(LanguageKey.SECTION_AIMBOT, "AIMBOT");
        map.put(LanguageKey.SWITCH_AIM_ENABLE, "Enable");
        map.put(LanguageKey.TEXT_AIM_MODE, "Aim-Mod");
        map.put(LanguageKey.OPTION_AIMBOT, "AimBot");
        map.put(LanguageKey.OPTION_BULLET_1, "Bullet 1.0");
        map.put(LanguageKey.OPTION_BULLET_2, "Bullet 2.0");
        map.put(LanguageKey.SLIDER_AIM_DIST, "Aim-Dist");
        map.put(LanguageKey.TEXT_AIM_TRIGGER, "Aim-Trigger");
        map.put(LanguageKey.OPTION_FIRE, "Fire");
        map.put(LanguageKey.OPTION_SCOPE, "Scope");
        map.put(LanguageKey.OPTION_FIRE_SCOPE, "Fire/Scope");
        map.put(LanguageKey.SLIDER_FOV_AIM, "Fov-Aim");
        map.put(LanguageKey.SWITCH_AIM_IGNOREBOT, "Aim-IgnoreBot");
        map.put(LanguageKey.SWITCH_AIM_KNOCKED, "Aim-Knocked");
        map.put(LanguageKey.SWITCH_AIM_VISICHECK, "Aim-VisiCheck");
        map.put(LanguageKey.SWITCH_AIM_RECOIL, "Aim-Recoil");
        map.put(LanguageKey.SLIDER_AIM_RECOIL_SIZE, "Aim-RecoilSize");
        map.put(LanguageKey.SWITCH_PLAYER_VIEW, "Player View");
        map.put(LanguageKey.SECTION_SKIN, "SKIN");
        map.put(LanguageKey.SWITCH_SKIN_ENABLE, "Skin-Enable");
        map.put(LanguageKey.SWITCH_GUN_BOX, "Gun-Box");
        map.put(LanguageKey.SLIDER_X_SUIT, "X-suit");
        map.put(LanguageKey.SLIDER_SET_1, "Set(1)");
        map.put(LanguageKey.SLIDER_SET_2, "Set(2)");
        map.put(LanguageKey.SLIDER_TDM_PLAYER_SET, "TDM-PlayerSet");
        map.put(LanguageKey.SLIDER_SKIN_BACKPACK, "Skin-BackPack");
        map.put(LanguageKey.SLIDER_SKIN_HELMET, "Skin-Helmet");
        map.put(LanguageKey.SECTION_AR, "AR");
        map.put(LanguageKey.SECTION_SMG, "SMG");
        map.put(LanguageKey.SECTION_SNIPER, "SNIPER");
        map.put(LanguageKey.SECTION_ITEMS, "ITEMS");
        map.put(LanguageKey.SWITCH_VEHICLE, "Vehicle");
        map.put(LanguageKey.SWITCH_LOOT_BOX, "Loot-Box");
        map.put(LanguageKey.SWITCH_LOOT_BOX_ITEMS, "Loot-Box Items");
        map.put(LanguageKey.TEXT_ITEMS_LOAD_ERROR, "Unable to load items.json");
        return map;
    }

    private static EnumMap<LanguageKey, String> createChineseMap() {
        EnumMap<LanguageKey, String> map = new EnumMap<>(LanguageKey.class);
        map.put(LanguageKey.MENU_MAIN, "\u4e3b\u83dc\u5355");
        map.put(LanguageKey.MENU_ESP, "\u900f\u89c6\u83dc\u5355");
        map.put(LanguageKey.MENU_AIMBOT, "\u81ea\u7784\u83dc\u5355");
        map.put(LanguageKey.MENU_SKIN, "\u76ae\u80a4\u83dc\u5355");
        map.put(LanguageKey.MENU_ITEMS, "\u7269\u54c1\u83dc\u5355");
        map.put(LanguageKey.TEXT_LANGUAGE, "\u8bed\u8a00");
        map.put(LanguageKey.LANG_ENGLISH, "\u82f1\u6587");
        map.put(LanguageKey.LANG_CHINESE, "\u4e2d\u6587");
        map.put(LanguageKey.BUTTON_HIDE_MENU, "\u9690\u85cf\u83dc\u5355");
        map.put(LanguageKey.SWITCH_HIDE_MODE, "\u9690\u85cf\u6a21\u5f0f");
        map.put(LanguageKey.SECTION_ESP, "\u900f\u89c6");
        map.put(LanguageKey.SWITCH_ESP_LINE, "\u5c04\u7ebf");
        map.put(LanguageKey.SWITCH_ESP_BONE, "\u9aa8\u9abc");
        map.put(LanguageKey.SWITCH_ESP_INFO, "\u4fe1\u606f");
        map.put(LanguageKey.SWITCH_ESP_WEAPON, "\u6b66\u5668");
        map.put(LanguageKey.SWITCH_GRENADE_WARNING, "\u624b\u96f7\u9884\u8b66");
        map.put(LanguageKey.SWITCH_360_ALERT, "360\u9884\u8b66");
        map.put(LanguageKey.SWITCH_RADAR_MAP, "\u96f7\u8fbe\u5730\u56fe");
        map.put(LanguageKey.SLIDER_RADAR_SIZE, "\u96f7\u8fbe\u5927\u5c0f");
        map.put(LanguageKey.SWITCH_IGNOREBOT_ESP, "\u5ffd\u7565\u673a\u5668\u4eba-ESP");
        map.put(LanguageKey.SECTION_AIMBOT, "\u81ea\u52a8\u7784\u51c6");
        map.put(LanguageKey.SWITCH_AIM_ENABLE, "\u542f\u7528");
        map.put(LanguageKey.TEXT_AIM_MODE, "\u7784\u51c6\u6a21\u5f0f");
        map.put(LanguageKey.OPTION_AIMBOT, "\u81ea\u7784");
        map.put(LanguageKey.OPTION_BULLET_1, "\u5b50\u5f39 1.0");
        map.put(LanguageKey.OPTION_BULLET_2, "\u5b50\u5f39 2.0");
        map.put(LanguageKey.SLIDER_AIM_DIST, "\u7784\u51c6\u8ddd\u79bb");
        map.put(LanguageKey.TEXT_AIM_TRIGGER, "\u89e6\u53d1\u65b9\u5f0f");
        map.put(LanguageKey.OPTION_FIRE, "\u5f00\u706b");
        map.put(LanguageKey.OPTION_SCOPE, "\u5f00\u955c");
        map.put(LanguageKey.OPTION_FIRE_SCOPE, "\u5f00\u706b/\u5f00\u955c");
        map.put(LanguageKey.SLIDER_FOV_AIM, "\u7784\u51c6\u8303\u56f4");
        map.put(LanguageKey.SWITCH_AIM_IGNOREBOT, "\u81ea\u7784\u5ffd\u7565\u673a\u5668\u4eba");
        map.put(LanguageKey.SWITCH_AIM_KNOCKED, "\u5ffd\u7565\u5012\u5730");
        map.put(LanguageKey.SWITCH_AIM_VISICHECK, "\u53ef\u89c1\u68c0\u6d4b");
        map.put(LanguageKey.SWITCH_AIM_RECOIL, "\u538b\u67aa");
        map.put(LanguageKey.SLIDER_AIM_RECOIL_SIZE, "\u538b\u67aa\u5f3a\u5ea6");
        map.put(LanguageKey.SWITCH_PLAYER_VIEW, "\u89c6\u91ce");
        map.put(LanguageKey.SECTION_SKIN, "\u76ae\u80a4");
        map.put(LanguageKey.SWITCH_SKIN_ENABLE, "\u542f\u7528\u76ae\u80a4");
        map.put(LanguageKey.SWITCH_GUN_BOX, "\u67aa\u68b0\u76d2");
        map.put(LanguageKey.SLIDER_X_SUIT, "X\u5957\u88c5");
        map.put(LanguageKey.SLIDER_SET_1, "\u5957\u88c5(1)");
        map.put(LanguageKey.SLIDER_SET_2, "\u5957\u88c5(2)");
        map.put(LanguageKey.SLIDER_TDM_PLAYER_SET, "TDM\u89d2\u8272\u5957\u88c5");
        map.put(LanguageKey.SLIDER_SKIN_BACKPACK, "\u80cc\u5305\u76ae\u80a4");
        map.put(LanguageKey.SLIDER_SKIN_HELMET, "\u5934\u76d4\u76ae\u80a4");
        map.put(LanguageKey.SECTION_AR, "\u6b65\u67aa");
        map.put(LanguageKey.SECTION_SMG, "\u51b2\u950b\u67aa");
        map.put(LanguageKey.SECTION_SNIPER, "\u72d9\u51fb\u67aa");
        map.put(LanguageKey.SECTION_ITEMS, "\u7269\u54c1");
        map.put(LanguageKey.SWITCH_VEHICLE, "\u8f7d\u5177");
        map.put(LanguageKey.SWITCH_LOOT_BOX, "\u76d2\u5b50");
        map.put(LanguageKey.SWITCH_LOOT_BOX_ITEMS, "\u76d2\u5b50\u7269\u54c1");
        map.put(LanguageKey.TEXT_ITEMS_LOAD_ERROR, "\u65e0\u6cd5\u52a0\u8f7d items.json");
        return map;
    }

    private static class LocalizedTextBinding {
        final WeakReference<TextView> viewRef;
        final LanguageKey key;

        LocalizedTextBinding(TextView view, LanguageKey key) {
            this.viewRef = new WeakReference<>(view);
            this.key = key;
        }
    }
}
