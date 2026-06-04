# NRG MOD — PROJECT MEMORY
**Package:** `com.bearmod` | **ABI:** arm64-v8a | **SDK:** 35 | **Min:** 28 | **Java 17 | NDK r24**

---

## BUILD COMMANDS
```bash
# Java build
./gradlew assembleDebug

# Native build (from jni/ dir)
ndk-build NDK_PROJECT_PATH=. APP_BUILD_SCRIPT=Android.mk

# Full clean
./gradlew clean && ndk-build clean
```
**Native lib:** `libbear.so` | **Load:** `System.loadLibrary("bear")` ← MainActivity + Floating + Launcher

---

## ARCHITECTURE (Read before ANY edit)
```
MainActivity
  └─ Launcher.Init() [static native → native_Init]
       └─ Login/Check → startService(Floating)
            └─ Floating (Service — GOD CLASS 2156 lines)
                 ├─ WindowManager: canvasLayout(ESPView) + mainLayout + iconLayout
                 ├─ ConfigManager.getInstance() [singleton]
                 ├─ Handler loop → postInvalidate() [canvas redraw]
                 └─ onSendConfig() → JNI → C++ Config map → NRG.h toggles

ESPView.onDraw()
  └─ Floating.DrawOn(this, canvas) [static native]
       └─ C++ DrawESP() → ESP.h → CallVoidMethod → ESPView.NRG_Draw*()
```

---

## JNI BRIDGE REFERENCE

### Inbound (Java → C++)
| Java Class | Method | C++ Export | File |
|---|---|---|---|
| Floating | onSendConfig(String,String) | native_onSendConfig | Main.cpp:13 |
| Floating | Switch(int,boolean) | Java_..._Switch | Main.cpp |
| Floating | DrawOn(ESPView,Canvas) | Java_..._DrawOn | Main.cpp |
| Floating | IsHideEsp() | registered dynamic | Main.cpp:134 |
| Floating | cfg/timeshow/onlinename/channellink etc. | Java_com_bearmod_Floating_* | Main.cpp:27-57 |
| Launcher | Init(Context) | native_Init | Main.cpp:121 |
| Launcher | Check(Context,String) | native_Check | Main.cpp:122 |
| Launcher | Login/Cancel/Error/Ok/Loging etc. | Java_com_bearmod_Launcher_* | Main.cpp:63-102 |

### Outbound (C++ → Java) — ESP.h
| C++ Method | Java Method | Class |
|---|---|---|
| ESP::DrawText | NRG_DrawText | ESPView |
| ESP::DrawLine2 | NRG_DrawLine | ESPView |
| ESP::DrawCircle | NRG_DrawCircle | ESPView |
| ESP::DrawFilledRect | NRG_DrawFilledRect | ESPView |
| ESP::DrawRect | DrawRect | ESPView |
| ESP::DrawWeaponIcon | NRG_DrawWeaponIcon | ESPView |
| ESP::DrawOTH | NRG_DrawOTH | ESPView |

**⚠️ NEVER rename any JNI method without running /jni-verify first**

---

## MODULE OVERVIEW
| Module | Files | Role |
|---|---|---|
| Overlay UI | Floating.java, ESPView.java, Launcher.java | WindowManager 3-layer overlay, settings UI, auth |
| Game Engine | NRG.h/.cpp, UE4.h/.cpp | UE4 actor scan, aimbot, ESP render logic |
| JNI Entry | Main.cpp | JNI_OnLoad, method registration, bypass hooks |
| SDK Reflection | SDK/*.cpp (~194 files) | UE4 ProcessEvent wrappers (auto-generated) |
| Hooks/Bypass | Substrate/, KittyMemory/, And64InlineHook | ARM64 inline hooks, memory patches |
| Auth/Network | curl/ + OpenSSL (static .a) | HTTPS key check via libcurl |
| Utilities | FileUtil.java, RecorderFakeUtils.java, Tools.cpp | File I/O, screen-rec hide, memory R/W |
| Config | ConfigManager.java | ConcurrentHashMap + debounced SharedPrefs flush |

---

## KNOWN RISKS (Do NOT ignore)
| Severity | Location | Risk |
|---|---|---|
| 🔴 HIGH | Floating.java ~line 354 | **onSendConfig() INFINITE RECURSION** — Java shadows native; calls itself |
| 🔴 HIGH | Floating.java ~line 87-97 | Static WindowManager/LayoutParams hold Context refs |
| 🔴 HIGH | Floating.java ~line 136 | Non-static Handler holds implicit Floating ref |
| 🔴 HIGH | Launcher.java line 247 | Anonymous Handler holds Activity ref (@SuppressLint HandlerLeak) |
| 🔴 HIGH | NRG.h line 50 | Config std::map — null/garbage if called after lib unload |
| 🟠 MED | ESP.h line 36-43 | JNI FindClass/GetMethodID — NO null checks |
| 🟠 MED | Launcher.java line 343 | Thread with no lifecycle; can fire after Context GC'd |
| 🟠 MED | Main.cpp line 351 | _bypass() pthread loops sleep(1) forever — no recovery |
| 🟠 MED | Floating.java LoadConfiguration1() | BufferedReader not in finally → FD leak on exception |
| 🟡 LOW | Tools.cpp IsPtrValid() | open("/dev/random") FD leak on repeated calls |

---

## CODING STANDARDS
- Java UI only — no XML generation ever
- No static Context fields — pass as method parameter
- WeakReference for all Service/Activity refs in Handler
- Check JNI return values (FindClass, GetMethodID, NewStringUTF)
- Cleanup JNI LocalRefs after use
- No blind rename of native bridge methods
- Explain → Risk → Approve → Execute (always)
- Module-by-module work only — never scan full project at once

---

## THREADING RULES
- Handler must use `WeakReference<Floating>` pattern
- Threads spawned in Service must stop in onDestroy()
- ConfigManager uses ScheduledExecutorService — do not replace with Handler
- Canvas loop: handler.post(mUpdateCanvasRunnable) — postInvalidate() only
- Native _bypass() thread is intentional infinite loop — do not touch

---

## CONFIG KEY NAMESPACE
Keys used in `onSendConfig(key, value)` → C++ Config map:
```
NRG_AIMBOT, AIM_DISTANCE, AIM_FOV, AIM_MOD (0/1/2/3)
ESP_LINE, ESP_BONE, ESP_INFO, ESP_WEAPON, ESP_GRENADE
ESP_RADAR, RADAR_SIZE, IGNORE_BOT, KNOCKED, VISI_CHECK
RECOIL, WIDE_VIEW, TRIGGER, HIDE_ESP
Skin keys: per-weapon index (40+ SeekBar values)
```

---

## ACTIVE SKILLS
| Command | File | Purpose |
|---|---|---|
| /audit | .claude/skills/audit/SKILL.md | Full module architecture audit |
| /jni-verify | .claude/skills/jni-verify/SKILL.md | JNI bridge safety check |
| /risk-check | .claude/skills/risk-check/SKILL.md | Memory/leak risk assessment |
| /refactor-plan | .claude/skills/refactor-plan/SKILL.md | Safe incremental refactor proposal |
| /fix-recursion | .claude/skills/fix-recursion/SKILL.md | Fix onSendConfig infinite recursion |

---

## COMPLETED TASKS
_(Claude updates this section after each task)_

## SESSION LOG
_(Claude appends brief summary after each session)_
