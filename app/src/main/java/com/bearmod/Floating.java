package com.bearmod;

import android.annotation.SuppressLint;
import android.app.AlertDialog;
import android.app.Service;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.SharedPreferences;
import android.content.res.ColorStateList;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.PixelFormat;
import android.graphics.Point;
import android.graphics.Typeface;
import android.graphics.drawable.GradientDrawable;
import android.os.Build;
import android.os.IBinder;
import android.util.Base64;
import android.view.Display;
import android.view.Gravity;
import android.view.MotionEvent;
import android.view.View;
import android.view.ViewGroup;
import android.view.WindowManager;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.CompoundButton;
import android.widget.HorizontalScrollView;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.RadioButton;
import android.widget.RadioGroup;
import android.widget.RelativeLayout;
import android.widget.ScrollView;
import android.widget.SeekBar;
import android.widget.Spinner;
import android.widget.Switch;
import android.widget.TextView;
import android.widget.Toast;
import java.io.File;
import android.app.*;
import android.widget.*;
import android.content.*;
import android.view.*;
import android.graphics.*;
import android.graphics.drawable.*;
import android.content.res.*;
import android.util.*;
import android.os.*;
import java.io.*;
import java.security.spec.*;
import android.text.*;
import android.net.*;
import java.nio.charset.*;
import org.json.*;
import android.annotation.TargetApi;
import android.view.WindowManager.LayoutParams;
import android.graphics.Canvas;
import android.annotation.SuppressLint;
import java.util.Random;
import java.lang.ref.WeakReference;
import java.text.SimpleDateFormat;
import java.util.Date;

import java.util.Locale;
import android.animation.ArgbEvaluator;
import android.animation.ValueAnimator;
import android.animation.TimeAnimator;
import java.util.Map;
import java.util.HashMap;
import androidx.core.content.ContextCompat;
import androidx.core.app.ActivityCompat;
import java.util.List;
import java.util.ArrayList;


//public class 
public class Floating extends Service implements OverlayUpdateLoop.Callback {
    static final int PANEL_BG = Color.rgb(54, 54, 54);
    static final int PANEL_BORDER = Color.rgb(216, 216, 216);
    static final int SIDEBAR_BG = Color.rgb(74, 70, 68);
    static final int SIDEBAR_ACTIVE_BG = Color.rgb(90, 85, 82);
    static final int TEXT_PRIMARY = Color.rgb(244, 244, 244);
    static final int TEXT_SECONDARY = Color.rgb(208, 208, 208);
    static final int DIVIDER = Color.rgb(122, 122, 122);
    static final int ACCENT_GREEN = Color.rgb(32, 224, 32);
    static final int SWITCH_ON = Color.rgb(76, 122, 63);
    static final int SWITCH_OFF = Color.rgb(119, 119, 119);
    static final String PAGE_MAIN = "main";
    static final String PAGE_ESP = "esp";
    static final String PAGE_AIM = "aim";
    static final String PAGE_SKIN = "skin";
    static final String PAGE_ITEMS = "items";

    private static WeakReference<Floating> sInstanceRef;
    private WindowManager windowManager;
    private OverlayWindowRegistry overlayWindowRegistry;
    private OverlayUpdateLoop overlayUpdateLoop;
    Map<String, String> configMap = new HashMap<>();
    public static int REQUEST_OVERLAY_PERMISSION = 5469;
    int screenWidth, screenHeight, type,  CheckAttY = 0;
   // float density;
//    int screenDpi;
    boolean EnableFakeRecord = false;
    GradientDrawable gdMenuBody, gdAnimation = new GradientDrawable();
	LayoutParams layoutParams;
    private WindowManager.LayoutParams iconLayoutParams, aimIconLayoutParams, mainLayoutParams, canvasLayoutParams;
   
    
    private WindowManager.LayoutParams vParams;
    private View vTouch;
    
    
    
    private RelativeLayout iconLayout;
    private RelativeLayout aimIconLayout;
    private LinearLayout mainLayout;
   // CanvasView canvasLayout;
    private ESPView canvasLayout;
	TextView textTitle;
    RelativeLayout closeLayout, maximizeLayout, minimizeLayout;
    RelativeLayout.LayoutParams closeLayoutParams, maximizeLayoutParams, minimizeLayoutParams;

   // private static boolean isScreenRecorderEnabled;
    private native String ChannelName(); 
    private native String FeedBackName(); 
    private native String channellink(); 
	private native String feedbacklink(); 
    private native String onlinename(); 
    private native String aimOnIcon();
    private native String aimOffIcon();
    private native String timeshow();
    private native String device();
    int EngChIndex = -1;
    ImageView iconImg;
    ImageView aimIconImg;
    private CompoundButton aimEnableSwitch;
    private boolean aimIconRequested;
    private boolean syncingAimEnableSwitch;
	private native String iconenc(); 
    static boolean isBullet;
    boolean CheckAtt;
    SharedPreferences configPrefs;
    int ToggleON = Color.GREEN;
    int ToggleOFF = Color.LTGRAY;
    
    boolean isMaximized = false;
    int lastMaximizedX = 0, lastMaximizedY = 0;
    int lastMaximizedW = 0, lastMaximizedH = 0;
    int action;
    int layoutWidth;
    int layoutHeight;
    int iconSize;
    int iconSize2;
     //  int MENU_BG_COLOR = 0xC819181C;
        int MENU_TEXT_COLOR = Color.parseColor("#FFFFFFFF");
        int MENU_LIST_STROKE = Color.argb(255, 200, 100, 0);

    private native boolean IsHideEsp(); 
 //   boolean isScreenRecorderEnabled/* = IsHideEsp()*/;
    
    private boolean SaveKey;
 
    int RadioColor = Color.parseColor("#FFFF9700");
    int MENU_BG_COLOR = Color.parseColor("#fff7f7f7"); //#AARRGGBB
    
    static  boolean isHIDE;
    int Storage_Permission = 142;
    TextView mTitle;
    
    float mediumSize = 5.0f;
    private native String cfg();
    
   // private native void onSendConfig(String s, String v);
    private native void onSendConfig(String s, String v);
    static native  void Switch(int i,boolean jboolean1);
    public static native void DrawOn(ESPView espView, Canvas canvas);
    private boolean destroyed;
    private int cachedMaxFps = 60;
    private UIDimensions uiDims;
    private OverlayComponentFactory componentFactory;
    private SidebarMenuController sidebarMenuController;

    private static class ConfigSeekBarListener implements SeekBar.OnSeekBarChangeListener {
        private final WeakReference<Floating> ownerRef;
        private final String key;

        ConfigSeekBarListener(Floating owner, String key) {
            this.ownerRef = new WeakReference<>(owner);
            this.key = key;
        }

        @Override
        public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {
            Floating owner = ownerRef.get();
            if (owner == null) return;
            try {
                owner.UpdateConfiguration2(key, Integer.valueOf(progress));
            } catch (Throwable ignored) {
            }
        }

        @Override
        public void onStartTrackingTouch(SeekBar seekBar) {
            Floating owner = ownerRef.get();
            if (owner == null) return;
            try { owner.SaveConfiguration(); } catch (Throwable ignored) {}
        }

        @Override
        public void onStopTrackingTouch(SeekBar seekBar) {
            Floating owner = ownerRef.get();
            if (owner == null) return;
            try { owner.SaveConfiguration(); } catch (Throwable ignored) {}
        }
    }

    private static class ConfigToggleListener implements CompoundButton.OnCheckedChangeListener {
        private final WeakReference<Floating> ownerRef;
        private final String key;

        ConfigToggleListener(Floating owner, String key) {
            this.ownerRef = new WeakReference<>(owner);
            this.key = key;
        }

        @Override
        public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
            Floating owner = ownerRef.get();
            if (owner == null) return;
            try {
                owner.UpdateConfiguration2(key, Integer.valueOf(isChecked ? 1 : 0));
            } catch (Throwable ignored) {
            }
        }
    }

    public static void hideesp() {
        Floating instance = sInstanceRef != null ? sInstanceRef.get() : null;
        if (instance != null) {
            instance.hideEspInternal();
        }
    }

    public static void stopHideesp() {
        Floating instance = sInstanceRef != null ? sInstanceRef.get() : null;
        if (instance != null) {
            instance.stopHideEspInternal();
        }
    }

    private void hideEspInternal() {
        applyHideModeWindowParams();
    }

    private void stopHideEspInternal() {
        clearHideModeWindowParams();
    }

    private void applyHideModeWindowParams() {
        RecorderFakeUtils.setFakeRecorderWindowLayoutParams(mainLayoutParams, iconLayoutParams, canvasLayoutParams, aimIconLayoutParams, overlayWindowRegistry, mainLayout, iconLayout, canvasLayout, aimIconLayout);
    }

    private void clearHideModeWindowParams() {
        RecorderFakeUtils.unsetFakeRecorderWindowLayoutParams(mainLayoutParams, iconLayoutParams, canvasLayoutParams, aimIconLayoutParams, overlayWindowRegistry, mainLayout, iconLayout, canvasLayout, aimIconLayout);
    }

    private Boolean GetBoolean(String str) {
        boolean z = true;
        if (configMap.get(str) == null || Integer.parseInt(configMap.get(str)) != 1) {
            z = false;
        }
        return Boolean.valueOf(z);
    }
    private Integer GetInteger(String str) {
        return Integer.valueOf(configMap.get(str) != null ? Integer.parseInt(configMap.get(str)) : 0);
    }
    
    Date time;
    SimpleDateFormat formatter;
    SimpleDateFormat formatter2;
   
    
    void CreateCanvas() {

        /* final LayoutParams params*/canvasLayoutParams = new LayoutParams(
            LayoutParams.MATCH_PARENT,
            LayoutParams.MATCH_PARENT,
            getLayoutType(),
            LayoutParams.FLAG_NOT_FOCUSABLE | LayoutParams.FLAG_NOT_TOUCHABLE | LayoutParams.FLAG_NOT_TOUCH_MODAL,

            PixelFormat.TRANSLUCENT);
        canvasLayoutParams.gravity = Gravity.TOP | Gravity.START;
        canvasLayoutParams.x = 0;
        canvasLayoutParams.y = 0;
      if (Build.VERSION.SDK_INT >= 30) {
            canvasLayoutParams.layoutInDisplayCutoutMode = LayoutParams.LAYOUT_IN_DISPLAY_CUTOUT_MODE_SHORT_EDGES;
        }
        canvasLayout = new ESPView(this);
        overlayWindowRegistry.add(canvasLayout, canvasLayoutParams);
    }
    

    public int getLayoutType() {
        int LAYOUT_FLAG;
        
        LAYOUT_FLAG = WindowManager.LayoutParams.FLAG_NOT_FOCUSABLE |
            WindowManager.LayoutParams.FLAG_NOT_TOUCHABLE |
            WindowManager.LayoutParams.FLAG_LAYOUT_NO_LIMITS |
            WindowManager.LayoutParams.FLAG_LAYOUT_IN_SCREEN;
            
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.O) {
            LAYOUT_FLAG = LayoutParams.TYPE_APPLICATION_OVERLAY;
        } else if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.N) {
            LAYOUT_FLAG = LayoutParams.TYPE_PHONE;
        } else if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.M) {
            LAYOUT_FLAG = LayoutParams.TYPE_PHONE;
        } else {
            LAYOUT_FLAG = LayoutParams.TYPE_SYSTEM_ALERT;
        }
        return LAYOUT_FLAG;
    }


    private boolean isNotInGame() {
        ActivityManager.RunningAppProcessInfo runningAppProcessInfo = new ActivityManager.RunningAppProcessInfo();
        ActivityManager.getMyMemoryState(runningAppProcessInfo);
        return runningAppProcessInfo.importance != 100;
    }

    private void Thread() {
        if (isNotInGame()) {
            overlayWindowRegistry.remove(mainLayout);
        } else {
      
          mainLayoutParams = new WindowManager.LayoutParams(layoutWidth, layoutHeight,  WindowManager.LayoutParams.TYPE_APPLICATION_OVERLAY, WindowManager.LayoutParams.FLAG_NOT_FOCUSABLE, PixelFormat.TRANSLUCENT);
      
            overlayWindowRegistry.add(mainLayout, mainLayoutParams);
        }
    }

    private void LoadConfiguration(/*String customPat*/) {
        }
    private void LoadConfiguration1(/*String customPat*/) {
        try {
            File file;

            file = new File(getFilesDir(), "NRG_SaveFile.cfg");
            try (BufferedReader bufferedReader = new BufferedReader(new FileReader(file))) {
                String readLine;
                while ((readLine = bufferedReader.readLine()) != null) {
                    String[] split = readLine.split(" = ");
                    if (split.length == 2) {
                        sendConfigToNative(split[0], split[1]);
                    }
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    
 
    private void sendConfigToNative(String key, Object value) {
        String stringValue = String.valueOf(value);
        configMap.put(key, stringValue);
        onSendConfig(key, stringValue);
	}
    

    private void SaveConfiguration(/*String customPath*/) {
        }
    
    private void SaveConfiguration1(/*String customPath*/) {
        try {
            File file;

            file = new File(getFilesDir(), "NRG_SaveFile.cfg");


            try (PrintWriter printWriter = new PrintWriter((OutputStream) new FileOutputStream(file), true)) {
                for (Map.Entry<String, String> entry : configMap.entrySet()) {
                    printWriter.println(entry.getKey() + " = " + entry.getValue());
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    
    
    private void UpdateConfiguration2(String s, Object v) {
        try {
            sendConfigToNative(s, v);
            // persist via ConfigManager (debounced, off UI thread)
            try {
                ConfigManager.getInstance().put(s, v.toString());
            } catch (Throwable ignored) {
            }
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }
    private void UpdateConfiguration(String s, Object v) {
        UpdateConfiguration2(s, v);
    }

    @Override
    public void onDestroy() {
        destroyed = true;
        if (overlayUpdateLoop != null) {
            overlayUpdateLoop.stop();
            overlayUpdateLoop = null;
        }
        clearOverlayListeners();
        if (overlayWindowRegistry != null) {
            overlayWindowRegistry.shutdown();
            overlayWindowRegistry = null;
        }

        if (iconImg != null) {
            iconImg.setImageDrawable(null);
        }
        if (aimIconImg != null) {
            aimIconImg.setImageDrawable(null);
        }
        iconLayout = null;
        aimIconLayout = null;
        mainLayout = null;
        canvasLayout = null;
        uiDims = null;
        componentFactory = null;
        sidebarMenuController = null;
        textTitle = null;
        mTitle = null;
        closeLayout = null;
        maximizeLayout = null;
        minimizeLayout = null;
        iconImg = null;
        aimIconImg = null;
        aimEnableSwitch = null;
        iconLayoutParams = null;
        aimIconLayoutParams = null;
        mainLayoutParams = null;
        canvasLayoutParams = null;
        vTouch = null;
        vParams = null;
        closeLayoutParams = null;
        maximizeLayoutParams = null;
        minimizeLayoutParams = null;
        windowManager = null;
        if (sInstanceRef != null && sInstanceRef.get() == this) {
            sInstanceRef = null;
        }
        LanguageManager.getInstance().clearBindings();
        ConfigManager.getInstance().shutdown();
        super.onDestroy();
    }

    private void clearOverlayListeners() {
        clearViewListeners(iconLayout);
        clearViewListeners(aimIconLayout);
        clearViewListeners(mainLayout);
        clearViewListeners(canvasLayout);
    }

    private void clearViewListeners(View view) {
        if (view == null) {
            return;
        }
        view.setOnTouchListener(null);
        view.setOnClickListener(null);
        view.setOnLongClickListener(null);

        if (view instanceof CompoundButton) {
            ((CompoundButton) view).setOnCheckedChangeListener(null);
        }
        if (view instanceof SeekBar) {
            ((SeekBar) view).setOnSeekBarChangeListener(null);
        }
        if (view instanceof AdapterView) {
            ((AdapterView<?>) view).setOnItemSelectedListener(null);
            ((AdapterView<?>) view).setOnItemClickListener(null);
        }
        if (view instanceof ViewGroup) {
            ViewGroup group = (ViewGroup) view;
            for (int i = 0; i < group.getChildCount(); i++) {
                clearViewListeners(group.getChildAt(i));
            }
        }
    }

    private void handleScreenSizeChanged() {
        try {
            Point screenSize = new Point();
            if (windowManager == null || mainLayoutParams == null || canvasLayoutParams == null) return;
            Display display = windowManager.getDefaultDisplay();
            display.getRealSize(screenSize);

            screenWidth = screenSize.x;
            screenHeight = screenSize.y;

            updateUIDimensions();
            mainLayoutParams.width = layoutWidth;
            mainLayoutParams.height = layoutHeight;
            clampMainLayoutPosition();

            if (mainLayout != null) {
                String selectedPage = sidebarMenuController != null && sidebarMenuController.getCurrentPageId() != null
                        ? sidebarMenuController.getCurrentPageId()
                        : PAGE_MAIN;
                LanguageManager.getInstance().clearBindings();
                mainLayout.removeAllViews();
                buildSidebarLayout(selectedPage);
            }

            if (mainLayout != null) {
                overlayWindowRegistry.update(mainLayout, mainLayoutParams);
            }

            canvasLayoutParams.width = screenWidth;
            canvasLayoutParams.height = screenHeight;

            if (canvasLayout != null) {
                overlayWindowRegistry.update(canvasLayout, canvasLayoutParams);
            }
            if (GetBoolean("RECORDER_HIDE")) {
                applyHideModeWindowParams();
            }
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }

    @Override
    public int onStartCommand(Intent intent, int flags, int startId) {
        super.onStartCommand(intent, flags, startId);
        return START_NOT_STICKY;
    }

    @Override
    public IBinder onBind(Intent intent) {
        return null;
    }
    
    @Override
    public void onCreate() {
        System.loadLibrary("bear");
        super.onCreate();
        destroyed = false;
        sInstanceRef = new WeakReference<>(this);
        configPrefs = getSharedPreferences("config", MODE_PRIVATE);
        // initialize central config manager to offload prefs I/O
        try {
            ConfigManager.getInstance().initialize(configPrefs);
            configMap = ConfigManager.getInstance().getMap();
        } catch (Throwable ignored) {
        }
        LanguageManager.getInstance().initialize(configPrefs);
        EngChIndex = LanguageManager.getInstance().getLegacyLanguageIndex();
        windowManager = (WindowManager) getSystemService(WINDOW_SERVICE);
        overlayWindowRegistry = new OverlayWindowRegistry(windowManager);

        time = new Date();
        formatter = new SimpleDateFormat(" HH:mm:ss", Locale.getDefault());
        formatter2 = new SimpleDateFormat("yyyy-MM-dd", Locale.getDefault());
        
        
        Point screenSize = new Point();
        try {
            Display display = windowManager.getDefaultDisplay();
            display.getRealSize(screenSize);
        } catch (Exception ignored) {
        }
        screenWidth = screenSize.x;
        screenHeight = screenSize.y;
        cachedMaxFps = GetDeviceMaxFps();

		
        updateUIDimensions();
		
        
        iconSize = uiDims != null ? uiDims.iconSizePx : convertSizeToDp(40);
        
        iconSize2 = 150;
        
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.O) {
            type = 2038;
        } else {
            type = 2002;
        }

      //  startAnimation();
      
        CreateCanvas();
        CreateLayout();
        CreateIcon();
        aimIconRequested = GetBoolean("NRG_AIMBOT");
        if (aimIconRequested) {
            ensureAimIconOverlay();
        }
        if (GetBoolean("RECORDER_HIDE")) {
            applyHideModeWindowParams();
        }
        
        UpdateConfiguration("AIM::TRIGGER1", (byte) 1);
        UpdateConfiguration("AIM::TARGET1", (byte) 1);
        UpdateConfiguration("ESP::BOXTYPE1", (byte) 1);
        UpdateConfiguration("AIM_MOD1", (byte) 1);
        UpdateConfiguration("SMOOT::HNESS1", (byte) 1);
        UpdateConfiguration("RADAR::SIZE", (byte) 60);

        overlayUpdateLoop = new OverlayUpdateLoop(this);
        overlayUpdateLoop.start();


    }

    int convertSizeToDp(float size) {
        DisplayMetrics metrics = getResources().getDisplayMetrics();
        float fpixels = TypedValue.applyDimension(TypedValue.COMPLEX_UNIT_DIP, size, metrics);
        return Math.round(fpixels);
    }

    private void updateUIDimensions() {
        uiDims = new UIDimensions(this, Math.max(1, screenWidth), Math.max(1, screenHeight));
        if (componentFactory == null) {
            componentFactory = new OverlayComponentFactory(this, uiDims);
        } else {
            componentFactory.setDimensions(uiDims);
        }
        layoutWidth = uiDims.menuWidthPx;
        layoutHeight = uiDims.menuHeightPx;
    }

    private UIDimensions dims() {
        if (uiDims == null) {
            updateUIDimensions();
        }
        return uiDims;
    }

    private OverlayComponentFactory components() {
        if (componentFactory == null) {
            componentFactory = new OverlayComponentFactory(this, dims());
        }
        return componentFactory;
    }

    private void clampMainLayoutPosition() {
        if (mainLayoutParams == null) {
            return;
        }
        int maxX = Math.max(0, screenWidth - layoutWidth);
        int maxY = Math.max(0, screenHeight - layoutHeight);
        if (mainLayoutParams.x < 0) mainLayoutParams.x = 0;
        if (mainLayoutParams.y < 0) mainLayoutParams.y = 0;
        if (mainLayoutParams.x > maxX) mainLayoutParams.x = maxX;
        if (mainLayoutParams.y > maxY) mainLayoutParams.y = maxY;
    }
    private TextView createText(String text, float sp, int color, int gravity) {
        return components().createText(text, sp, color, gravity);
    }

    private TextView createText(LanguageKey key, float sp, int color, int gravity) {
        return components().createBoundText(key, sp, color, gravity);
    }

    private void addSectionTitle(String label, LinearLayout parent) {
        components().addSectionTitle(label, parent, TEXT_SECONDARY);
    }

    private void addSectionTitle(LanguageKey key, LinearLayout parent) {
        components().addSectionTitle(key, parent, TEXT_SECONDARY);
    }

    private CompoundButton addToggleRow(String label, boolean checked, String key, LinearLayout parent) {
        return addToggleRow(label, checked, new ConfigToggleListener(this, key), parent);
    }

    private CompoundButton addToggleRow(LanguageKey labelKey, boolean checked, String key, LinearLayout parent) {
        return addToggleRow(labelKey, checked, new ConfigToggleListener(this, key), parent);
    }

    private CompoundButton addToggleRow(String label, boolean checked, CompoundButton.OnCheckedChangeListener listener, LinearLayout parent) {
        return components().addToggleRow(label, checked, listener, parent, TEXT_PRIMARY, SWITCH_ON, SWITCH_OFF, DIVIDER);
    }

    private CompoundButton addToggleRow(LanguageKey labelKey, boolean checked, CompoundButton.OnCheckedChangeListener listener, LinearLayout parent) {
        return components().addToggleRow(labelKey, checked, listener, parent, TEXT_PRIMARY, SWITCH_ON, SWITCH_OFF, DIVIDER);
    }

    private void addSeekRow(String label, int min, int max, int value, String key, LinearLayout parent) {
        components().addSeekRow(label, min, max, value, new ConfigSeekBarListener(this, key), parent, TEXT_PRIMARY, TEXT_SECONDARY, SWITCH_OFF, DIVIDER);
    }

    private void addSeekRow(LanguageKey labelKey, int min, int max, int value, String key, LinearLayout parent) {
        components().addSeekRow(labelKey, min, max, value, new ConfigSeekBarListener(this, key), parent, TEXT_PRIMARY, TEXT_SECONDARY, SWITCH_OFF, DIVIDER);
    }

    private void addSegmentedRow(LanguageKey labelKey, LanguageKey[] optionKeys, int selectedIndex, LinearLayout parent, final View.OnClickListener[] callbacks) {
        components().addSegmentedRow(labelKey, optionKeys, selectedIndex, parent, callbacks, TEXT_PRIMARY, TEXT_SECONDARY, DIVIDER);
    }

    private Bitmap decodeNativeBitmap(String base64) {
        if (base64 == null || base64.length() == 0) return null;
        try {
            byte[] data = Base64.decode(base64, Base64.DEFAULT);
            return BitmapFactory.decodeByteArray(data, 0, data.length);
        } catch (Exception ex) {
            ex.printStackTrace();
            return null;
        }
    }

    private void updateAimStatusIcon(ImageView target, boolean aimEnabled) {
        if (target == null) return;
        Bitmap bitmap = decodeNativeBitmap(aimEnabled ? aimOnIcon() : aimOffIcon());
        if (bitmap != null) {
            target.setImageBitmap(bitmap);
        }
    }

    private void syncAimIconOverlay(boolean aimEnabled) {
        aimIconRequested = aimEnabled;
        if (aimEnabled) {
            ensureAimIconOverlay();
            updateAimStatusIcon(aimIconImg, true);
            if (aimIconLayout != null) {
                aimIconLayout.setVisibility(View.VISIBLE);
            }
        } else {
            removeAimIconOverlay(false);
        }
    }

    private void setAimLogicEnabled(boolean enabled, boolean updateSwitch) {
        UpdateConfiguration("NRG_AIMBOT", Byte.parseByte(String.valueOf(enabled ? 1 : 0)));
        updateAimStatusIcon(aimIconImg, enabled);
        if (updateSwitch && aimEnableSwitch != null && aimEnableSwitch.isChecked() != enabled) {
            syncingAimEnableSwitch = true;
            aimEnableSwitch.setChecked(enabled);
            syncingAimEnableSwitch = false;
        }
    }

    private View.OnTouchListener createPanelDragListener() {
        return new View.OnTouchListener() {
            float pressedX;
            float pressedY;
            float deltaX;
            float deltaY;

            @Override
            public boolean onTouch(View v, MotionEvent event) {
                switch (event.getActionMasked()) {
                    case MotionEvent.ACTION_DOWN:
                        deltaX = mainLayoutParams.x - event.getRawX();
                        deltaY = mainLayoutParams.y - event.getRawY();
                        pressedX = event.getRawX();
                        pressedY = event.getRawY();
                        return true;
                    case MotionEvent.ACTION_MOVE:
                        float newX = event.getRawX() + deltaX;
                        float newY = event.getRawY() + deltaY;
                        float maxX = Math.max(0, screenWidth - layoutWidth);
                        float maxY = Math.max(0, screenHeight - layoutHeight);
                        if (newX < 0) newX = 0;
                        if (newX > maxX) newX = maxX;
                        if (newY < 0) newY = 0;
                        if (newY > maxY) newY = maxY;
                        mainLayoutParams.x = (int) newX;
                        mainLayoutParams.y = (int) newY;
                        overlayWindowRegistry.update(mainLayout, mainLayoutParams);
                        return true;
                    case MotionEvent.ACTION_UP:
                        return Math.abs(pressedX - event.getRawX()) > 1 || Math.abs(pressedY - event.getRawY()) > 1;
                    default:
                        return false;
                }
            }
        };
    }

    private void buildSidebarLayout() {
        buildSidebarLayout(PAGE_MAIN);
    }

    private void buildSidebarLayout(String initialPageId) {
        sidebarMenuController = new SidebarMenuController(this, dims(), components(), new SidebarMenuController.HideMenuCallback() {
            @Override
            public void onHideMenu() {
                mainLayout.setVisibility(View.GONE);
                iconLayout.setVisibility(View.VISIBLE);
            }
        });
        registerSidebarPages();
        sidebarMenuController.build(mainLayout, initialPageId, createPanelDragListener());
    }

    private void registerSidebarPages() {
        sidebarMenuController.registerPage(PAGE_MAIN, LanguageKey.MENU_MAIN, new SidebarMenuController.PageRenderer() {
            @Override
            public void render(LinearLayout parent) {
                renderMainPage(parent);
            }
        });
        sidebarMenuController.registerPage(PAGE_ESP, LanguageKey.MENU_ESP, new SidebarMenuController.PageRenderer() {
            @Override
            public void render(LinearLayout parent) {
                renderEspPage(parent);
            }
        });
        sidebarMenuController.registerPage(PAGE_AIM, LanguageKey.MENU_AIMBOT, new SidebarMenuController.PageRenderer() {
            @Override
            public void render(LinearLayout parent) {
                renderAimPage(parent);
            }
        });
        sidebarMenuController.registerPage(PAGE_SKIN, LanguageKey.MENU_SKIN, new SidebarMenuController.PageRenderer() {
            @Override
            public void render(LinearLayout parent) {
                renderSkinPage(parent);
            }
        });
        sidebarMenuController.registerPage(PAGE_ITEMS, LanguageKey.MENU_ITEMS, new SidebarMenuController.PageRenderer() {
            @Override
            public void render(LinearLayout parent) {
                renderItemsPage(parent);
            }
        });
    }

    private int selectedIndexByKeys(String[] keys, int defaultIndex) {
        for (int i = 0; i < keys.length; i++) {
            if (GetBoolean(keys[i])) {
                return i;
            }
        }
        return defaultIndex;
    }

    private void renderMainPage(LinearLayout parent) {
        addSegmentedRow(LanguageKey.TEXT_LANGUAGE, new LanguageKey[]{LanguageKey.LANG_ENGLISH, LanguageKey.LANG_CHINESE}, LanguageManager.getInstance().getLegacyLanguageIndex(), parent, new View.OnClickListener[]{
            new View.OnClickListener() {
                @Override
                public void onClick(View v) {
                    EngChIndex = 0;
                    LanguageManager.getInstance().setLanguage(LanguageManager.LANGUAGE_EN);
                    UpdateConfiguration2("LANGUAGE", 0);
                    UpdateConfiguration2("LANGUAGE_CODE", LanguageManager.LANGUAGE_EN);
                }
            },
            new View.OnClickListener() {
                @Override
                public void onClick(View v) {
                    EngChIndex = 1;
                    LanguageManager.getInstance().setLanguage(LanguageManager.LANGUAGE_ZH);
                    UpdateConfiguration2("LANGUAGE", 1);
                    UpdateConfiguration2("LANGUAGE_CODE", LanguageManager.LANGUAGE_ZH);
                }
            }
        });
        addToggleRow(LanguageKey.SWITCH_HIDE_MODE, GetBoolean("RECORDER_HIDE"), new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                UpdateConfiguration2("RECORDER_HIDE", Integer.valueOf(isChecked ? 1 : 0));
                if (isChecked) {
                    applyHideModeWindowParams();
                } else {
                    clearHideModeWindowParams();
                }
            }
        }, parent);
    }

    private void renderEspPage(LinearLayout parent) {
        addSectionTitle(LanguageKey.SECTION_ESP, parent);
        addToggleRow(LanguageKey.SWITCH_ESP_LINE, GetBoolean("ESP_LINE"), "ESP_LINE", parent);
        addToggleRow(LanguageKey.SWITCH_ESP_BONE, GetBoolean("ESP_BONE"), "ESP_BONE", parent);
        addToggleRow(LanguageKey.SWITCH_ESP_INFO, GetBoolean("ESP_INFO"), "ESP_INFO", parent);
        addToggleRow(LanguageKey.SWITCH_ESP_WEAPON, GetBoolean("ESP_WEAPON"), "ESP_WEAPON", parent);
        addToggleRow(LanguageKey.SWITCH_GRENADE_WARNING, GetBoolean("ESP_WARNING"), "ESP_WARNING", parent);
        addToggleRow(LanguageKey.SWITCH_360_ALERT, GetBoolean("ESP_ALERT"), "ESP_ALERT", parent);
        addToggleRow(LanguageKey.SWITCH_RADAR_MAP, GetBoolean("ESP_RADAR"), "ESP_RADAR", parent);
        int radarSize = GetInteger("RADAR_SIZE").intValue();
        addSeekRow(LanguageKey.SLIDER_RADAR_SIZE, 60, 350, radarSize == 0 ? 60 : radarSize, "RADAR_SIZE", parent);
        addToggleRow(LanguageKey.SWITCH_IGNOREBOT_ESP, GetBoolean("ESP_IGNOREBOTS"), "ESP_IGNOREBOTS", parent);
    }

    private void renderAimPage(LinearLayout parent) {
        addSectionTitle(LanguageKey.SECTION_AIMBOT, parent);
        aimEnableSwitch = addToggleRow(LanguageKey.SWITCH_AIM_ENABLE, GetBoolean("NRG_AIMBOT"), new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                if (syncingAimEnableSwitch) {
                    return;
                }
                setAimLogicEnabled(isChecked, false);
                syncAimIconOverlay(isChecked);
            }
        }, parent);
        addSegmentedRow(LanguageKey.TEXT_AIM_MODE, new LanguageKey[]{LanguageKey.OPTION_AIMBOT, LanguageKey.OPTION_BULLET_1, LanguageKey.OPTION_BULLET_2}, selectedIndexByKeys(new String[]{"AIM_MOD1", "AIM_MOD2", "AIM_MOD3"}, 0), parent, new View.OnClickListener[]{
            new View.OnClickListener() {
                @Override
                public void onClick(View v) {
                    UpdateConfiguration("AIM_MOD1", (byte) 1);
                    UpdateConfiguration("AIM_MOD2", (byte) 0);
                    UpdateConfiguration("AIM_MOD3", (byte) 0);
                }
            },
            new View.OnClickListener() {
                @Override
                public void onClick(View v) {
                    UpdateConfiguration("AIM_MOD1", (byte) 0);
                    UpdateConfiguration("AIM_MOD2", (byte) 1);
                    UpdateConfiguration("AIM_MOD3", (byte) 0);
                }
            },
            new View.OnClickListener() {
                @Override
                public void onClick(View v) {
                    UpdateConfiguration("AIM_MOD1", (byte) 0);
                    UpdateConfiguration("AIM_MOD2", (byte) 0);
                    UpdateConfiguration("AIM_MOD3", (byte) 1);
                }
            }
        });
        int aimDistance = GetInteger("AIM_DISTANCE").intValue();
        addSeekRow(LanguageKey.SLIDER_AIM_DIST, 0, 200, aimDistance == 0 ? 1 : aimDistance, "AIM_DISTANCE", parent);
        addSegmentedRow(LanguageKey.TEXT_AIM_TRIGGER, new LanguageKey[]{LanguageKey.OPTION_FIRE, LanguageKey.OPTION_SCOPE, LanguageKey.OPTION_FIRE_SCOPE}, selectedIndexByKeys(new String[]{"AIM::TRIGGER1", "AIM::TRIGGER2", "AIM::TRIGGER3"}, 0), parent, new View.OnClickListener[]{
            new View.OnClickListener() {
                @Override
                public void onClick(View v) {
                    UpdateConfiguration("AIM::TRIGGER1", (byte) 1);
                    UpdateConfiguration("AIM::TRIGGER2", (byte) 0);
                    UpdateConfiguration("AIM::TRIGGER3", (byte) 0);
                }
            },
            new View.OnClickListener() {
                @Override
                public void onClick(View v) {
                    UpdateConfiguration("AIM::TRIGGER1", (byte) 0);
                    UpdateConfiguration("AIM::TRIGGER2", (byte) 1);
                    UpdateConfiguration("AIM::TRIGGER3", (byte) 0);
                }
            },
            new View.OnClickListener() {
                @Override
                public void onClick(View v) {
                    UpdateConfiguration("AIM::TRIGGER1", (byte) 0);
                    UpdateConfiguration("AIM::TRIGGER2", (byte) 0);
                    UpdateConfiguration("AIM::TRIGGER3", (byte) 1);
                }
            }
        });
        int aimSize = GetInteger("AIM_SIZE").intValue();
        addSeekRow(LanguageKey.SLIDER_FOV_AIM, 50, 400, aimSize == 0 ? 50 : aimSize, "AIM_SIZE", parent);
        addToggleRow(LanguageKey.SWITCH_AIM_IGNOREBOT, GetBoolean("AIM_IGNOREBOTS"), "AIM_IGNOREBOTS", parent);
        addToggleRow(LanguageKey.SWITCH_AIM_KNOCKED, GetBoolean("AIM_KNOCKED"), "AIM_KNOCKED", parent);
        addToggleRow(LanguageKey.SWITCH_AIM_VISICHECK, GetBoolean("AIM_VISCHECK"), "AIM_VISCHECK", parent);
        addToggleRow(LanguageKey.SWITCH_AIM_RECOIL, GetBoolean("RECOI_LCOMPARISON"), "RECOI_LCOMPARISON", parent);
        int recoil = GetInteger("RECOIL_SIZE").intValue();
        addSeekRow(LanguageKey.SLIDER_AIM_RECOIL_SIZE, 0, 30, recoil, "RECOIL_SIZE", parent);
        addToggleRow(LanguageKey.SWITCH_PLAYER_VIEW, GetBoolean("MEMORY_WIDEVIEW"), "MEMORY_WIDEVIEW", parent);
    }

    private void renderSkinPage(LinearLayout parent) {
        addSectionTitle(LanguageKey.SECTION_SKIN, parent);
        addToggleRow(LanguageKey.SWITCH_SKIN_ENABLE, GetBoolean("SKIN_ENABLE"), "SKIN_ENABLE", parent);
        addToggleRow(LanguageKey.SWITCH_GUN_BOX, GetBoolean("GUN_BOX"), "GUN_BOX", parent);
        addSeekRow(LanguageKey.SLIDER_X_SUIT, 0, 13, GetInteger("SKIN_XSUIT"), "SKIN_XSUIT", parent);
        addSeekRow(LanguageKey.SLIDER_SET_1, 0, 28, GetInteger("SKIN_SET1"), "SKIN_SET1", parent);
        addSeekRow(LanguageKey.SLIDER_SET_2, 0, 28, GetInteger("SKIN_SET2"), "SKIN_SET2", parent);
        addSeekRow(LanguageKey.SLIDER_TDM_PLAYER_SET, 0, 28, GetInteger("SKIN_TDMSET"), "SKIN_TDMSET", parent);
        addSeekRow(LanguageKey.SLIDER_SKIN_BACKPACK, 0, 24, GetInteger("SKIN_BACKPACK"), "SKIN_BACKPACK", parent);
        addSeekRow(LanguageKey.SLIDER_SKIN_HELMET, 0, 15, GetInteger("SKIN_HELMET"), "SKIN_HELMET", parent);
        addSectionTitle("VEHICLE SKIN", parent);
        addSeekRow("Dacia", 0, 24, GetInteger("SKIN_VEHICLE_DACIA"), "SKIN_VEHICLE_DACIA", parent);
        addSeekRow("UAZ", 0, 14, GetInteger("SKIN_VEHICLE_UAZ"), "SKIN_VEHICLE_UAZ", parent);
        addSeekRow("Buggy", 0, 33, GetInteger("SKIN_VEHICLE_BUGGY"), "SKIN_VEHICLE_BUGGY", parent);
        addSeekRow("Moto", 0, 10, GetInteger("SKIN_VEHICLE_MOTO"), "SKIN_VEHICLE_MOTO", parent);
        addSeekRow("MiniBus", 0, 12, GetInteger("SKIN_VEHICLE_MINIBUS"), "SKIN_VEHICLE_MINIBUS", parent);
        addSeekRow("CoupeRB", 0, 30, GetInteger("SKIN_VEHICLE_COUPERB"), "SKIN_VEHICLE_COUPERB", parent);
        addSeekRow("Boat", 0, 11, GetInteger("SKIN_VEHICLE_BOAT"), "SKIN_VEHICLE_BOAT", parent);
        addSectionTitle(LanguageKey.SECTION_AR, parent);
        addSeekRow("M416", 0, 12, GetInteger("SKIN_M416"), "SKIN_M416", parent);
        addSeekRow("AKM", 0, 16, GetInteger("SKIN_AKM"), "SKIN_AKM", parent);
        addSeekRow("SCAR-L", 0, 13, GetInteger("SKIN_SCARL"), "SKIN_SCARL", parent);
        addSeekRow("M762", 0, 15, GetInteger("SKIN_M762"), "SKIN_M762", parent);
        addSeekRow("M16A4", 0, 10, GetInteger("SKIN_M16A4"), "SKIN_M16A4", parent);
        addSeekRow("GROZAR", 0, 8, GetInteger("SKIN_GROZAR"), "SKIN_GROZAR", parent);
        addSeekRow("AUG", 0, 6, GetInteger("SKIN_AUG"), "SKIN_AUG", parent);
        addSeekRow("QBZ", 0, 2, GetInteger("SKIN_QBZ"), "SKIN_QBZ", parent);
        addSeekRow("Honey Badger", 0, 1, GetInteger("SKIN_HONEY"), "SKIN_HONEY", parent);
        addSeekRow("ACE32", 0, 6, GetInteger("SKIN_ACE32"), "SKIN_ACE32", parent);
        addSeekRow("M249", 0, 6, GetInteger("SKIN_M249"), "SKIN_M249", parent);
        addSeekRow("DP28", 0, 8, GetInteger("SKIN_DP28"), "SKIN_DP28", parent);
        addSeekRow("MG3", 0, 3, GetInteger("SKIN_MG3"), "SKIN_MG3", parent);
        addSeekRow("Pan", 0, 4, GetInteger("SKIN_PAN"), "SKIN_PAN", parent);
        addSectionTitle(LanguageKey.SECTION_SMG, parent);
        addSeekRow("UZI", 0, 10, GetInteger("SKIN_UZI"), "SKIN_UZI", parent);
        addSeekRow("UMP45", 0, 12, GetInteger("SKIN_UMP45"), "SKIN_UMP45", parent);
        addSeekRow("VECTOR", 0, 9, GetInteger("SKIN_VECTOR"), "SKIN_VECTOR", parent);
        addSeekRow("THOMPSON", 0, 2, GetInteger("SKIN_THOMPSON"), "SKIN_THOMPSON", parent);
        addSeekRow("Bizon", 0, 1, GetInteger("SKIN_BIZON"), "SKIN_BIZON", parent);
        addSeekRow("P90", 0, 3, GetInteger("SKIN_P90"), "SKIN_P90", parent);
        addSectionTitle(LanguageKey.SECTION_SNIPER, parent);
        addSeekRow("M24", 0, 12, GetInteger("SKIN_M24"), "SKIN_M24", parent);
        addSeekRow("KAR98K", 0, 12, GetInteger("SKIN_KAR98K"), "SKIN_KAR98K", parent);
        addSeekRow("AWM", 0, 9, GetInteger("SKIN_AWM"), "SKIN_AWM", parent);
        addSeekRow("AMR", 0, 7, GetInteger("SKIN_AMR"), "SKIN_AMR", parent);
        addSeekRow("MK14", 0, 11, GetInteger("SKIN_MK14"), "SKIN_MK14", parent);
        addSeekRow("Mini14", 0, 4, GetInteger("SKIN_MINI14"), "SKIN_MINI14", parent);
        addSectionTitle("SHOTGUN", parent);
        addSeekRow("S12K", 0, 4, GetInteger("SKIN_S12K"), "SKIN_S12K", parent);
        addSeekRow("DBS", 0, 6, GetInteger("SKIN_DBS"), "SKIN_DBS", parent);
        addSeekRow("M1014", 0, 1, GetInteger("SKIN_XM1014"), "SKIN_XM1014", parent);
    }

    private void renderItemsPage(LinearLayout parent) {
        addSectionTitle(LanguageKey.SECTION_ITEMS, parent);
        addToggleRow(LanguageKey.SWITCH_VEHICLE, GetBoolean("ESP::VEHICLE"), new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                UpdateConfiguration("ESP::VEHICLE", Byte.parseByte(String.valueOf(isChecked ? 1 : 0)));
            }
        }, parent);
        addToggleRow(LanguageKey.SWITCH_LOOT_BOX, GetBoolean("ESP::LOOTBOX"), new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                UpdateConfiguration("ESP::LOOTBOX", Byte.parseByte(String.valueOf(isChecked ? 1 : 0)));
            }
        }, parent);
        addToggleRow(LanguageKey.SWITCH_LOOT_BOX_ITEMS, GetBoolean("ESP::LOOT_BOX_ITEMS"), new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                UpdateConfiguration("ESP::LOOT_BOX_ITEMS", Byte.parseByte(String.valueOf(isChecked ? 1 : 0)));
            }
        }, parent);

        try (InputStream is = getAssets().open("items.json")) {
            int size = is.available();
            byte[] buffer = new byte[size];
            if (is.read(buffer) > 0) {
                String json = new String(buffer, StandardCharsets.UTF_8);
                UpdateConfiguration("CMD_PARSE_ITEMS", json);
                JSONArray arr = new JSONArray(json);
                for (int i = 0; i < arr.length(); i++) {
                    JSONObject obj = arr.getJSONObject(i);
                    if (obj.has("itemCategory")) {
                        addSectionTitle(obj.getString("itemCategory"), parent);
                    } else {
                        String itemName = obj.getString("itemName");
                        final int itemId = obj.getInt("itemId");
                        addToggleRow(itemName, false, new CompoundButton.OnCheckedChangeListener() {
                            @Override
                            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                                UpdateConfiguration("ESP::ITEMS", itemId);
                            }
                        }, parent);
                    }
                }
            }
        } catch (Exception ex) {
            TextView error = createText(LanguageKey.TEXT_ITEMS_LOAD_ERROR, 12.0f, TEXT_SECONDARY, Gravity.START);
            parent.addView(error, new LinearLayout.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.WRAP_CONTENT));
            ex.printStackTrace();
        }
    }



    @SuppressLint("ClickableViewAccessibility")
    void CreateLayout() {

       mainLayoutParams = new WindowManager.LayoutParams(layoutWidth, layoutHeight, type, WindowManager.LayoutParams.FLAG_NOT_FOCUSABLE | WindowManager.LayoutParams.FLAG_LAYOUT_NO_LIMITS | WindowManager.LayoutParams.FLAG_TRANSLUCENT_STATUS, PixelFormat.RGBA_8888); 
        
        mainLayoutParams.gravity = Gravity.TOP | Gravity.START;
        mainLayoutParams.x = Math.max(0, (screenWidth - layoutWidth) / 2);
        mainLayoutParams.y = Math.max(0, (screenHeight - layoutHeight) / 2);
        
        mainLayout = new LinearLayout(this);
        mainLayout.setOrientation(LinearLayout.VERTICAL);
        mainLayout.setLayoutParams(new LinearLayout.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.MATCH_PARENT));

        buildSidebarLayout();
        overlayWindowRegistry.add(mainLayout, mainLayoutParams);
    }
   

    @SuppressLint("ClickableViewAccessibility")
    void CreateIcon() {
        iconLayout = new RelativeLayout(this);
        RelativeLayout.LayoutParams iconParams = new RelativeLayout.LayoutParams(ViewGroup.LayoutParams.WRAP_CONTENT, ViewGroup.LayoutParams.WRAP_CONTENT);
        iconLayout.setLayoutParams(iconParams);

        iconImg = new ImageView(this);
        ViewGroup.LayoutParams iconImgParams = new ViewGroup.LayoutParams(dims().iconSizePx, dims().iconSizePx);
        iconImg.setLayoutParams(iconImgParams);

        iconLayout.addView(iconImg);

        try {
            String iconBase64 = iconenc();  
            byte[] iconData = Base64.decode(iconBase64, Base64.DEFAULT);
            
            Bitmap bmp = BitmapFactory.decodeByteArray(iconData, 0, iconData.length);
            iconImg.setImageBitmap(bmp);
        } catch (Exception ex) {
            ex.printStackTrace();
        }

        iconLayoutParams = new WindowManager.LayoutParams(ViewGroup.LayoutParams.WRAP_CONTENT, ViewGroup.LayoutParams.WRAP_CONTENT, type, WindowManager.LayoutParams.FLAG_NOT_FOCUSABLE | WindowManager.LayoutParams.FLAG_TRANSLUCENT_STATUS, PixelFormat.TRANSLUCENT);
        iconLayoutParams.gravity = Gravity.START | Gravity.TOP;

        iconLayoutParams.x = 0;
        iconLayoutParams.y = 0;

        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.P) {
            iconLayoutParams.layoutInDisplayCutoutMode = WindowManager.LayoutParams.LAYOUT_IN_DISPLAY_CUTOUT_MODE_SHORT_EDGES;
        }

        iconLayout.setVisibility(View.GONE);

        iconLayout.setOnTouchListener(new View.OnTouchListener() {
            float pressedX;
            float pressedY;
            float deltaX;
            float deltaY;
            float newX;
            float newY;
                float maxX;
                float maxY;
            @Override
            public boolean onTouch(View v, MotionEvent event) {

                switch (event.getActionMasked()) {
                    case MotionEvent.ACTION_DOWN:

                        deltaX = iconLayoutParams.x - event.getRawX();
                        deltaY = iconLayoutParams.y - event.getRawY();

                        pressedX = event.getRawX();
                        pressedY = event.getRawY();

                        break;
                    case MotionEvent.ACTION_UP:
                        int Xdiff = (int) (event.getRawX() - pressedX);
                        int Ydiff = (int) (event.getRawY() - pressedY);

                        if (Xdiff == 0 && Ydiff == 0) {
                            mainLayout.setVisibility(View.VISIBLE);
                            iconLayout.setVisibility(View.GONE);
                        }
                        return true;
                        
                
                    case MotionEvent.ACTION_MOVE:
                        newX = event.getRawX() + deltaX;
                        newY = event.getRawY() + deltaY;

                        float maxX = screenWidth - v.getWidth();
                        float maxY = screenHeight - v.getHeight();

                        if (newX < 0)
                            newX = 0;
                        if (newX > maxX)
                            newX = (int) maxX;
                        if (newY < 0)
                            newY = 0;
                        if (newY > maxY)
                            newY = (int) maxY;

                        iconLayoutParams.x = (int) newX;
                        iconLayoutParams.y = (int) newY;

                        overlayWindowRegistry.update(iconLayout, iconLayoutParams);
                        break;

                    default:
                        break;
                }

                return false;
            }
        });

        overlayWindowRegistry.add(iconLayout, iconLayoutParams);
    }

    @SuppressLint("ClickableViewAccessibility")
    private void ensureAimIconOverlay() {
        if (aimIconLayout != null && aimIconLayout.getParent() != null) {
            updateAimStatusIcon(aimIconImg, GetBoolean("NRG_AIMBOT"));
            aimIconLayout.setVisibility(aimIconRequested ? View.VISIBLE : View.GONE);
            return;
        }

        aimIconLayout = new RelativeLayout(this);
        aimIconLayout.setLayoutParams(new RelativeLayout.LayoutParams(ViewGroup.LayoutParams.WRAP_CONTENT, ViewGroup.LayoutParams.WRAP_CONTENT));
        aimIconLayout.setAlpha(0.8f);

        aimIconImg = new ImageView(this);
        int aimIconSize = Math.max(dims().iconSizePx, dims().dp(56));
        aimIconImg.setLayoutParams(new ViewGroup.LayoutParams(aimIconSize, aimIconSize));
        aimIconImg.setScaleType(ImageView.ScaleType.FIT_CENTER);
        aimIconLayout.addView(aimIconImg);

        aimIconLayoutParams = new WindowManager.LayoutParams(ViewGroup.LayoutParams.WRAP_CONTENT, ViewGroup.LayoutParams.WRAP_CONTENT, type, WindowManager.LayoutParams.FLAG_NOT_FOCUSABLE | WindowManager.LayoutParams.FLAG_LAYOUT_NO_LIMITS, PixelFormat.TRANSLUCENT);
        aimIconLayoutParams.gravity = Gravity.START | Gravity.TOP;
        aimIconLayoutParams.x = 0;
        aimIconLayoutParams.y = 0;

        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.P) {
            aimIconLayoutParams.layoutInDisplayCutoutMode = WindowManager.LayoutParams.LAYOUT_IN_DISPLAY_CUTOUT_MODE_SHORT_EDGES;
        }

        updateAimStatusIcon(aimIconImg, GetBoolean("NRG_AIMBOT"));
        aimIconLayout.setVisibility(aimIconRequested ? View.VISIBLE : View.GONE);

        aimIconLayout.setOnTouchListener(new View.OnTouchListener() {
            float pressedX;
            float pressedY;
            float deltaX;
            float deltaY;

            @Override
            public boolean onTouch(View v, MotionEvent event) {
                switch (event.getActionMasked()) {
                    case MotionEvent.ACTION_DOWN:
                        deltaX = aimIconLayoutParams.x - event.getRawX();
                        deltaY = aimIconLayoutParams.y - event.getRawY();
                        pressedX = event.getRawX();
                        pressedY = event.getRawY();
                        return true;
                    case MotionEvent.ACTION_UP:
                        int xDiff = (int) Math.abs(event.getRawX() - pressedX);
                        int yDiff = (int) Math.abs(event.getRawY() - pressedY);
                        if (xDiff <= 1 && yDiff <= 1) {
                            setAimLogicEnabled(!GetBoolean("NRG_AIMBOT"), false);
                        }
                        return true;
                    case MotionEvent.ACTION_MOVE:
                        float newX = event.getRawX() + deltaX;
                        float newY = event.getRawY() + deltaY;
                        float maxX = screenWidth - v.getWidth();
                        float maxY = screenHeight - v.getHeight();

                        if (newX < 0) newX = 0;
                        if (newX > maxX) newX = maxX;
                        if (newY < 0) newY = 0;
                        if (newY > maxY) newY = maxY;

                        aimIconLayoutParams.x = (int) newX;
                        aimIconLayoutParams.y = (int) newY;
                        overlayWindowRegistry.update(aimIconLayout, aimIconLayoutParams);
                        return true;
                    default:
                        return false;
                }
            }
        });

        overlayWindowRegistry.add(aimIconLayout, aimIconLayoutParams);
        if (GetBoolean("RECORDER_HIDE")) {
            applyHideModeWindowParams();
        }
    }

    private void removeAimIconOverlay() {
        removeAimIconOverlay(true);
    }

    private void removeAimIconOverlay(boolean updateConfig) {
        aimIconRequested = false;
        if (updateConfig) {
            UpdateConfiguration("NRG_AIMBOT", (byte) 0);
        }
        if (aimIconLayout != null) {
            if (overlayWindowRegistry != null) {
                overlayWindowRegistry.removeImmediate(aimIconLayout);
            }
        }
        if (aimIconImg != null) {
            aimIconImg.setImageDrawable(null);
        }
        aimIconLayout = null;
        aimIconLayoutParams = null;
        aimIconImg = null;
    }
    @Override
    public View getCanvasView() {
        return destroyed ? null : canvasLayout;
    }

    @Override
    public boolean readScreenSize(Point outSize) {
        if (destroyed || windowManager == null || outSize == null) {
            return false;
        }
        try {
            Display display = windowManager.getDefaultDisplay();
            display.getRealSize(outSize);
            return true;
        } catch (RuntimeException ignored) {
            return false;
        }
    }

    @Override
    public int getKnownScreenWidth() {
        return screenWidth;
    }

    @Override
    public int getKnownScreenHeight() {
        return screenHeight;
    }

    @Override
    public int getMaxFps() {
        return cachedMaxFps;
    }

    @Override
    public void onScreenSizeChanged() {
        if (destroyed) {
            return;
        }
        cachedMaxFps = GetDeviceMaxFps();
        handleScreenSizeChanged();
    }

    public int GetDeviceMaxFps() {
        try {
            Display display = windowManager != null ? windowManager.getDefaultDisplay() : null;
            if (display != null) {
                float refreshRate = display.getRefreshRate();
                int fps = Math.round(refreshRate);
                return fps > 0 ? fps : 60;
            }
        } catch (Exception ex) {
            ex.printStackTrace();
        }
        return 60;
    }
}
