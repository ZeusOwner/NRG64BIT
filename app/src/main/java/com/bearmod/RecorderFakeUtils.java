package com.bearmod;

import android.annotation.SuppressLint;
import android.os.Build;
import android.text.TextUtils;
import android.view.WindowManager;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.reflect.Field;
import java.lang.reflect.Method;
import java.util.Arrays;
import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;
import android.view.View;

public class RecorderFakeUtils {

    public static final String ROM_MIUI = "MIUI";
    public static final String ROM_EMUI = "EMUI";
    public static final String ROM_FLYME = "FLYME";
    public static final String ROM_OPPO = "OPPO";
    public static final String ROM_SMARTISAN = "SMARTISAN";
    public static final String ROM_VIVO = "VIVO";
    public static final String ROM_QIKU = "QIKU";
    public static final String ROM_NUBIAUI = "NUBIAUI";
    public static final String ROM_ONEPLUS = "HYDROGEN";
    public static final String ROM_SAMSUNG = "ONEUI";
    public static final String ROM_BLACKSHARK = "JOYUI";
    public static final String ROM_ROG = "REPLIBLIC";

    private static final String KEY_VERSION_MIUI = "ro.miui.ui.version.name";
    private static final String KEY_VERSION_EMUI = "ro.build.version.emui";
    private static final String KEY_VERSION_OPPO = "ro.build.version.opporom";
    private static final String KEY_VERSION_SMARTISAN = "ro.smartisan.version";
    private static final String KEY_VERSION_VIVO = "ro.vivo.os.version";
    private static final String KEY_VERSION_NUBIA = "ro.build.nubia.rom.name";
    private static final String KEY_VERSION_ONEPLIS = "ro.build.ota.versionname";
    private static final String KEY_VERSION_SAMSUNG = "ro.channel.officehubrow";
    private static final String KEY_VERSION_BLACKSHARK = "ro.blackshark.rom";
    private static final String KEY_VERSION_ROG = "ro.build.fota.version";
    private static String sName;
    private static final Map<String, Field> FIELD_CACHE = new ConcurrentHashMap<>();
    private static final Map<String, Method> METHOD_CACHE = new ConcurrentHashMap<>();
    private static final Map<String, Class<?>> CLASS_CACHE = new ConcurrentHashMap<>();

    private static Field getDeclaredFieldCached(Class<?> cls, String name) throws NoSuchFieldException {
        String key = cls.getName() + "#" + name;
        Field field = FIELD_CACHE.get(key);
        if (field == null) {
            field = cls.getDeclaredField(name);
            field.setAccessible(true);
            FIELD_CACHE.put(key, field);
        }
        return field;
    }

    private static Field getPublicFieldCached(Class<?> cls, String name) throws NoSuchFieldException {
        String key = cls.getName() + "@" + name;
        Field field = FIELD_CACHE.get(key);
        if (field == null) {
            field = cls.getField(name);
            field.setAccessible(true);
            FIELD_CACHE.put(key, field);
        }
        return field;
    }

    private static Method getMethodCached(Class<?> cls, String name, Class<?>... parameterTypes) throws NoSuchMethodException {
        String key = cls.getName() + "#" + name + Arrays.toString(parameterTypes);
        Method method = METHOD_CACHE.get(key);
        if (method == null) {
            method = cls.getMethod(name, parameterTypes);
            method.setAccessible(true);
            METHOD_CACHE.put(key, method);
        }
        return method;
    }

    private static Class<?> getClassCached(String className) throws ClassNotFoundException {
        Class<?> cls = CLASS_CACHE.get(className);
        if (cls == null) {
            cls = Class.forName(className);
            CLASS_CACHE.put(className, cls);
        }
        return cls;
    }

    private static int getRoundedCornerOverlayFlag(WindowManager.LayoutParams params) {
        try {
            Field privateflagField = getDeclaredFieldCached(params.getClass(), "PRIVATE_FLAG_IS_ROUNDED_CORNERS_OVERLAY");
            Object value = privateflagField.get(params.getClass());
            if (value instanceof Integer) {
                return (Integer) value;
            }
        } catch (Throwable ignored) {
        }
        return 0;
    }

    private static Field getPrivateFlagsField(WindowManager.LayoutParams params) throws NoSuchFieldException {
        return getDeclaredFieldCached(params.getClass(), "privateFlags");
    }

    private static Field getMeizuParamsField(WindowManager.LayoutParams params) throws NoSuchFieldException {
        return getPublicFieldCached(params.getClass(), "meizuParams");
    }

    private static Field getMeizuFlagField() throws NoSuchFieldException, ClassNotFoundException {
        return getDeclaredFieldCached(getClassCached("android.view.MeizuLayoutParams"), "flags");
    }

    private static Method getSemAddExtensionFlagsMethod(WindowManager.LayoutParams params) throws NoSuchMethodException {
        return getMethodCached(params.getClass(), "semAddExtensionFlags", Integer.TYPE);
    }

    private static Method getSemAddPrivateFlagsMethod(WindowManager.LayoutParams params) throws NoSuchMethodException {
        return getMethodCached(params.getClass(), "semAddPrivateFlags", Integer.TYPE);
    }

    private static Method getSemRemoveExtensionFlagsMethod(WindowManager.LayoutParams params) throws NoSuchMethodException {
        return getMethodCached(params.getClass(), "semRemoveExtensionFlags", Integer.TYPE);
    }

    private static Method getSemRemovePrivateFlagsMethod(WindowManager.LayoutParams params) throws NoSuchMethodException {
        return getMethodCached(params.getClass(), "semRemovePrivateFlags", Integer.TYPE);
    }

    //华为
    public static boolean isEmui() {
        return check(ROM_EMUI);
    }

    //小米
    public static boolean isMiui() {
        return check(ROM_MIUI);
    }

    //vivo
    public static boolean isVivo() {
        return check(ROM_VIVO);
    }

    //oppo
    public static boolean isOppo() {
        return check(ROM_OPPO);
    }

    //魅族
    public static boolean isFlyme() {
        return check(ROM_FLYME);
    }

    //红魔
    public static boolean isNubia() {
        return check(ROM_NUBIAUI);
    }

    //一加
    public static boolean isOnePlus() {
        return check(ROM_ONEPLUS);
    }

    //三星
    public static boolean isSanSung() {
        return check(ROM_SAMSUNG);
    }

    //黑鲨
    public static boolean isBLACKSHARK() {
        return check(ROM_BLACKSHARK);
    }

    //ROG
    public static boolean isRog() {
        return check(ROM_ROG);
    }

    public static boolean isActivice() { return false;}







    public static void setFakeRecorderWindowLayoutParams(WindowManager.LayoutParams mainParams, WindowManager.LayoutParams iconParams, WindowManager.LayoutParams canvasParams, OverlayWindowRegistry windowRegistry, View mainView, View iconView, View canvasView) {

        try {               
            mainParams.setTitle(RecorderFakeUtils.getFakeRecordWindowTitle());
            if (check(ROM_FLYME)) {
                if (!setMeizuParams(mainParams, 0x2000)) {
                    if (isActivice()) {
                        setMeizuParams_new(mainParams, 1024); //最新魅族
                    }
                }
            } else if (check(ROM_MIUI) || check(ROM_BLACKSHARK)) { 
                setXiaomiParams(mainParams,6666);
            } else if (check(ROM_ONEPLUS) && (isActivice() || Build.VERSION.SDK_INT == 30)) {
                setOnePlusParams(mainParams, getRoundedCornerOverlayFlag(mainParams));
            } else if (isSanSung()) {
                setSamsungFlags(mainParams);
            } else if (check(ROM_ROG)) {
                mainParams.memoryType |= 0x10000000;
            }

            iconParams.setTitle(RecorderFakeUtils.getFakeRecordWindowTitle());
            if (check(ROM_FLYME)) {
                if (!setMeizuParams(iconParams, 0x2000)) {
                    if (isActivice()) {
                        setMeizuParams_new(iconParams, 1024); //最新魅族
                    }
                }
            } else if (check(ROM_MIUI) || check(ROM_BLACKSHARK)) { 
                setXiaomiParams(iconParams,6666);
            } else if (check(ROM_ONEPLUS) && (isActivice() || Build.VERSION.SDK_INT == 30)) {
                setOnePlusParams(iconParams, getRoundedCornerOverlayFlag(iconParams));
            } else if (isSanSung()) {
                setSamsungFlags(iconParams);
            } else if (check(ROM_ROG)) {
                iconParams.memoryType |= 0x10000000;
            }

            canvasParams.setTitle(RecorderFakeUtils.getFakeRecordWindowTitle());
            if (check(ROM_FLYME)) {
                if (!setMeizuParams(canvasParams, 0x2000)) {
                    if (isActivice()) {
                        setMeizuParams_new(canvasParams, 1024); //最新魅族
                    }
                }
            } else if (check(ROM_MIUI) || check(ROM_BLACKSHARK)) { 
                setXiaomiParams(canvasParams,6666);
            } else if (check(ROM_ONEPLUS) && (isActivice() || Build.VERSION.SDK_INT == 30)) {
                setOnePlusParams(canvasParams, getRoundedCornerOverlayFlag(canvasParams));
            } else if (isSanSung()) {
                setSamsungFlags(canvasParams);
            } else if (check(ROM_ROG)) {
                canvasParams.memoryType |= 0x10000000;
            }
        }catch (Exception e){
            e.printStackTrace();
        }



        updateViewLayout(windowRegistry, mainView, mainParams);
        updateViewLayout(windowRegistry, iconView, iconParams);
        updateViewLayout(windowRegistry, canvasView, canvasParams);
        //Toast.makeText(context, "Fake Recorder Window Layout Params set", Toast.LENGTH_SHORT).show();
    }

    public static void setFakeRecorderWindowLayoutParams(WindowManager.LayoutParams mainParams, WindowManager.LayoutParams iconParams, WindowManager.LayoutParams canvasParams, WindowManager.LayoutParams aimParams, OverlayWindowRegistry windowRegistry, View mainView, View iconView, View canvasView, View aimView) {
        setFakeRecorderWindowLayoutParams(mainParams, iconParams, canvasParams, windowRegistry, mainView, iconView, canvasView);
        applyFakeRecorderParams(aimParams);
        updateViewLayout(windowRegistry, aimView, aimParams);
    }


    public static void unsetFakeRecorderWindowLayoutParams(WindowManager.LayoutParams mainParams, WindowManager.LayoutParams iconParams, WindowManager.LayoutParams canvasParams, OverlayWindowRegistry windowRegistry, View mainView, View iconView, View canvasView) {

        try {

            mainParams.setTitle(RecorderFakeUtils.getFakeRecordWindowTitle());    
            if (check(ROM_FLYME)) {     
                if (!unsetMeizuParams(mainParams, 0x2000)) {
                    if (isActivice()) {
                        unsetMeizuParams_new(mainParams, 1024); //最新魅族
                    }
                }
            } else if (check(ROM_MIUI) || check(ROM_BLACKSHARK)) {      
                unsetXiaomiParams(mainParams, 6666);
            } else if (check(ROM_ONEPLUS) && (isActivice() || Build.VERSION.SDK_INT == 30)) {
                unsetOnePlusParams(mainParams, getRoundedCornerOverlayFlag(mainParams));
            } else if (isSanSung()) {
                unsetSamsungFlags(mainParams);
            } else if (check(ROM_ROG)) {                
                mainParams.memoryType &= ~0x10000000;
            } else if (check(ROM_EMUI)) {
                unsetHuaweiParams(mainParams);
            } else if (check(ROM_OPPO)) {
                unsetOppoParams(mainParams);
            } else if (check(ROM_VIVO)) {
                unsetVivoParams(mainParams);
            }

            canvasParams.setTitle(RecorderFakeUtils.getFakeRecordWindowTitle());  
            if (check(ROM_FLYME)) {     
                if (!unsetMeizuParams(canvasParams, 0x2000)) {
                    if (isActivice()) {
                        unsetMeizuParams_new(canvasParams, 1024); //最新魅族
                    }
                }
            } else if (check(ROM_MIUI) || check(ROM_BLACKSHARK)) {      
                unsetXiaomiParams(canvasParams, 6666);
            } else if (check(ROM_ONEPLUS) && (isActivice() || Build.VERSION.SDK_INT == 30)) {
                unsetOnePlusParams(canvasParams, getRoundedCornerOverlayFlag(canvasParams));
            } else if (isSanSung()) {
                unsetSamsungFlags(canvasParams);
            } else if (check(ROM_ROG)) {                
                canvasParams.memoryType &= ~0x10000000;
            } else if (check(ROM_EMUI)) {
                unsetHuaweiParams(canvasParams);
            } else if (check(ROM_OPPO)) {
                unsetOppoParams(canvasParams);
            } else if (check(ROM_VIVO)) {
                unsetVivoParams(canvasParams);
            }

            iconParams.setTitle(RecorderFakeUtils.getFakeRecordWindowTitle());    
            if (check(ROM_FLYME)) {     
                if (!unsetMeizuParams(iconParams, 0x2000)) {
                    if (isActivice()) {
                        unsetMeizuParams_new(iconParams, 1024); //最新魅族
                    }
                }
            } else if (check(ROM_MIUI) || check(ROM_BLACKSHARK)) {      
                unsetXiaomiParams(iconParams, 6666);
            } else if (check(ROM_ONEPLUS) && (isActivice() || Build.VERSION.SDK_INT == 30)) {
                unsetOnePlusParams(iconParams, getRoundedCornerOverlayFlag(iconParams));
            } else if (isSanSung()) {
                unsetSamsungFlags(iconParams);
            } else if (check(ROM_ROG)) {                
                iconParams.memoryType &= ~0x10000000;
            } else if (check(ROM_EMUI)) {
                unsetHuaweiParams(iconParams);
            } else if (check(ROM_OPPO)) {
                unsetOppoParams(iconParams);
            } else if (check(ROM_VIVO)) {
                unsetVivoParams(iconParams);
            }


        } catch (Exception e) {
            e.printStackTrace();
        }

        updateViewLayout(windowRegistry, mainView, mainParams);
        updateViewLayout(windowRegistry, iconView, iconParams);
        updateViewLayout(windowRegistry, canvasView, canvasParams);
        //Toast.makeText(context, "Fake Recorder Window Layout Params removed", Toast.LENGTH_SHORT).show();
    }

    public static void unsetFakeRecorderWindowLayoutParams(WindowManager.LayoutParams mainParams, WindowManager.LayoutParams iconParams, WindowManager.LayoutParams canvasParams, WindowManager.LayoutParams aimParams, OverlayWindowRegistry windowRegistry, View mainView, View iconView, View canvasView, View aimView) {
        unsetFakeRecorderWindowLayoutParams(mainParams, iconParams, canvasParams, windowRegistry, mainView, iconView, canvasView);
        clearFakeRecorderParams(aimParams);
        updateViewLayout(windowRegistry, aimView, aimParams);
    }

    private static void applyFakeRecorderParams(WindowManager.LayoutParams params) {
        if (params == null) {
            return;
        }
        try {
            params.setTitle(RecorderFakeUtils.getFakeRecordWindowTitle());
            if (check(ROM_FLYME)) {
                if (!setMeizuParams(params, 0x2000)) {
                    if (isActivice()) {
                        setMeizuParams_new(params, 1024);
                    }
                }
            } else if (check(ROM_MIUI) || check(ROM_BLACKSHARK)) {
                setXiaomiParams(params, 6666);
            } else if (check(ROM_ONEPLUS) && (isActivice() || Build.VERSION.SDK_INT == 30)) {
                setOnePlusParams(params, getRoundedCornerOverlayFlag(params));
            } else if (isSanSung()) {
                setSamsungFlags(params);
            } else if (check(ROM_ROG)) {
                params.memoryType |= 0x10000000;
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private static void clearFakeRecorderParams(WindowManager.LayoutParams params) {
        if (params == null) {
            return;
        }
        try {
            params.setTitle(RecorderFakeUtils.getFakeRecordWindowTitle());
            if (check(ROM_FLYME)) {
                if (!unsetMeizuParams(params, 0x2000)) {
                    if (isActivice()) {
                        unsetMeizuParams_new(params, 1024);
                    }
                }
            } else if (check(ROM_MIUI) || check(ROM_BLACKSHARK)) {
                unsetXiaomiParams(params, 6666);
            } else if (check(ROM_ONEPLUS) && (isActivice() || Build.VERSION.SDK_INT == 30)) {
                unsetOnePlusParams(params, getRoundedCornerOverlayFlag(params));
            } else if (isSanSung()) {
                unsetSamsungFlags(params);
            } else if (check(ROM_ROG)) {
                params.memoryType &= ~0x10000000;
            } else if (check(ROM_EMUI)) {
                unsetHuaweiParams(params);
            } else if (check(ROM_OPPO)) {
                unsetOppoParams(params);
            } else if (check(ROM_VIVO)) {
                unsetVivoParams(params);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private static void updateViewLayout(OverlayWindowRegistry windowRegistry, View view, WindowManager.LayoutParams layoutParams) {
        if (windowRegistry != null && view != null && layoutParams != null) {
            windowRegistry.update(view, layoutParams);
        }
    }

    private static boolean setXiaomiParams(WindowManager.LayoutParams params, int flagValue) {
        try {
            //layoutParams.flags = layoutParams.flags | WindowManager.LayoutParams.FLAG_DITHER;
            params.flags = params.flags | WindowManager.LayoutParams.FLAG_DITHER;
            return true;
        } catch (Exception e) {
            e.printStackTrace();
            return false;
        }
    }


    private static boolean unsetXiaomiParams(WindowManager.LayoutParams params, int flagValue) {
        try {
            // Удаление флага из параметров
            params.flags = params.flags & ~WindowManager.LayoutParams.FLAG_DITHER;
            return true;
        } catch (Exception e) {
            e.printStackTrace();
            return false;
        }
    }

    private static void unsetHuaweiParams(WindowManager.LayoutParams params) {
        // Вставьте код для сброса параметров для Huawei
        // Например, если был установлен какой-то флаг, его нужно снять
        try {
            // Пример сброса флага
            params.flags &= ~WindowManager.LayoutParams.FLAG_DITHER;
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    private static void unsetOppoParams(WindowManager.LayoutParams params) {
        // Вставьте код для сброса параметров для Oppo
        try {
            // Пример сброса флага
            params.flags &= ~WindowManager.LayoutParams.FLAG_DITHER;
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    private static void unsetVivoParams(WindowManager.LayoutParams params) {
        // Вставьте код для сброса параметров для Vivo
        try {
            // Пример сброса флага
            params.flags &= ~WindowManager.LayoutParams.FLAG_DITHER;
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    @SuppressLint("PrivateApi")
    private static boolean setMeizuParams(WindowManager.LayoutParams params, int flagValue) {
        try {
            Field flagField = getMeizuFlagField();
            Object MeizuParams = getClassCached("android.view.MeizuLayoutParams").newInstance();
            flagField.setInt(MeizuParams, flagValue);
            Field mzParamsField = getMeizuParamsField(params);
            mzParamsField.set(params, MeizuParams);
            return true;
        } catch (IllegalAccessException | ClassNotFoundException | NoSuchFieldException | InstantiationException e) {
            return false;
        }
    }
    @SuppressLint("PrivateApi")
    private static boolean unsetMeizuParams(WindowManager.LayoutParams params, int flagValue) {
        try {
            Field flagField = getMeizuFlagField();
            Object MeizuParams = getClassCached("android.view.MeizuLayoutParams").newInstance();
            int currentFlags = flagField.getInt(MeizuParams);
            // Удаление флага
            flagField.setInt(MeizuParams, currentFlags & ~flagValue);
            Field mzParamsField = getMeizuParamsField(params);
            mzParamsField.set(params, MeizuParams);
            return true;
        } catch (IllegalAccessException | ClassNotFoundException | NoSuchFieldException | InstantiationException e) {
            return false;
        }
    }

    private static boolean setMeizuParams_new(WindowManager.LayoutParams params, int flagValue) {
        try {
            Field mzParamsField = params.getClass().getDeclaredField("meizuFlags");
            mzParamsField.setAccessible(true);
            mzParamsField.setInt(params, flagValue);
            return true;
        } catch (Exception e) {
            return false;
        }
    }

    private static boolean unsetMeizuParams_new(WindowManager.LayoutParams params, int flagValue) {
        try {
            Field mzParamsField = params.getClass().getDeclaredField("meizuFlags");
            mzParamsField.setAccessible(true);
            int currentFlags = mzParamsField.getInt(params);
            // Удаление флага
            mzParamsField.setInt(params, currentFlags & ~flagValue);
            return true;
        } catch (Exception e) {
            return false;
        }
    }

    private static void setOnePlusParams(WindowManager.LayoutParams params, int flagValue) {
        try {
            Field flagField = getPrivateFlagsField(params);
            flagField.set(params, flagValue);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }


    private static void unsetOnePlusParams(WindowManager.LayoutParams params, int flagValue) {
        try {
            Field flagField = getPrivateFlagsField(params);
            int currentFlags = flagField.getInt(params);
            flagField.set(params, currentFlags & ~flagValue);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private static void setSamsungFlags(WindowManager.LayoutParams params) {
        try {
            Method semAddExtensionFlags = getSemAddExtensionFlagsMethod(params);
            Method semAddPrivateFlags = getSemAddPrivateFlagsMethod(params);
            semAddExtensionFlags.invoke(params, -2147352576);
            semAddPrivateFlags.invoke(params, params.flags);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    private static void unsetSamsungFlags(WindowManager.LayoutParams params) {
        try {
            Method semRemoveExtensionFlags = getSemRemoveExtensionFlagsMethod(params);
            Method semRemovePrivateFlags = getSemRemovePrivateFlagsMethod(params);
            semRemoveExtensionFlags.invoke(params, -2147352576);
            semRemovePrivateFlags.invoke(params, params.flags);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }


    private static String getFakeRecordWindowTitle() {
        if (sName == null) {
            check("");
        }
        if (sName == null) {
            return "";
        }
        switch (sName) {
            case ROM_MIUI:
                return "com.miui.screenrecorder";
            case ROM_EMUI:
                return "ScreenRecoderTimer";
            case ROM_OPPO:
                return "com.coloros.screenrecorder.FloatView";
            case ROM_VIVO:
                return "screen_record_menu";
            case ROM_ONEPLUS:
                return "op_screenrecord";
            case ROM_FLYME:
                return "SysScreenRecorder";
            case ROM_NUBIAUI:
                return "NubiaScreenDecorOverlay";
            case ROM_BLACKSHARK:
                return "com.blackshark.screenrecorder";
            case ROM_ROG:
                return "com.asus.force.layer.transparent.SR.floatingpanel";
        }
        return "";
    }

    private static boolean check(String rom) {
        if (sName != null) {
            return sName.equals(rom);
        }

        if (!TextUtils.isEmpty(getProp(KEY_VERSION_MIUI))) {
            sName = ROM_MIUI;
        } else if (!TextUtils.isEmpty(getProp(KEY_VERSION_BLACKSHARK))) {
            sName = ROM_BLACKSHARK;
        } else if (!TextUtils.isEmpty(getProp(KEY_VERSION_EMUI))) {
            sName = ROM_EMUI;
        } else if (!TextUtils.isEmpty(getProp(KEY_VERSION_OPPO))) {
            sName = ROM_OPPO;
        } else if (!TextUtils.isEmpty(getProp(KEY_VERSION_VIVO))) {
            sName = ROM_VIVO;
        } else if (!TextUtils.isEmpty(getProp(KEY_VERSION_SMARTISAN))) {
            sName = ROM_SMARTISAN;
        } else if (!TextUtils.isEmpty(getProp(KEY_VERSION_NUBIA))) {
            sName = ROM_NUBIAUI;
        } else if (!TextUtils.isEmpty(getProp(KEY_VERSION_ONEPLIS)) && getProp(KEY_VERSION_ONEPLIS).toLowerCase().contains("hydrogen")) {
            sName = ROM_ONEPLUS;
        } else if (!TextUtils.isEmpty(getProp(KEY_VERSION_ROG)) && getProp(KEY_VERSION_ROG).toLowerCase().contains("CN_Phone")) {
            sName = ROM_ROG;
        } else if (!TextUtils.isEmpty(getProp(KEY_VERSION_SAMSUNG))) {
            sName = ROM_SAMSUNG;
        } else {
            String sVersion = Build.DISPLAY;
            if (sVersion.toUpperCase().contains(ROM_FLYME)) {
                sName = ROM_FLYME;
            } else {
                sName = Build.MANUFACTURER.toUpperCase();
            }
        }
        return sName.equals(rom);
    }

    private static String getProp(String name) {
        String line = null;
        Process p = null;
        BufferedReader input = null;
        try {
            p = Runtime.getRuntime().exec("getprop " + name);
            input = new BufferedReader(new InputStreamReader(p.getInputStream()), 1024);
            line = input.readLine();
            input.close();
        } catch (IOException ex) {
            return null;
        } finally {
            if (input != null) {
                try {
                    input.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            if (p != null) {
                p.destroy();
            }
        }
        return line;
    }

}
