# JNI BRIDGE QUICK REFERENCE
# Paste this when discussing JNI methods — saves re-reading Main.cpp

## Inbound (Java → C++) — Main.cpp registrations
| Java Class | Method | C++ Name | Type |
|---|---|---|---|
| Floating | onSendConfig(String,String) | native_onSendConfig | RegisterNatives |
| Floating | Switch(int,boolean) | Java_com_bearmod_Floating_Switch | static |
| Floating | DrawOn(ESPView,Canvas) | Java_com_bearmod_Floating_DrawOn | static |
| Floating | IsHideEsp() | registered dynamic | Main.cpp:134 |
| Floating | cfg() | Java_com_bearmod_Floating_cfg | Main.cpp:57 |
| Floating | timeshow() | Java_com_bearmod_Floating_timeshow | Main.cpp:27 |
| Floating | onlinename() | Java_com_bearmod_Floating_onlinename | Main.cpp:34 |
| Floating | channellink() | Java_com_bearmod_Floating_channellink | Main.cpp:39 |
| Floating | feedbacklink() | Java_com_bearmod_Floating_feedbacklink | Main.cpp:43 |
| Floating | ChannelName() | Java_com_bearmod_Floating_ChannelName | Main.cpp:47 |
| Floating | FeedBackName() | Java_com_bearmod_Floating_FeedBackName | Main.cpp:51 |
| Launcher | Init(Context) | native_Init | Main.cpp:121 |
| Launcher | Check(Context,String) | native_Check | Main.cpp:122 |
| Launcher | Login() | Java_com_bearmod_Launcher_Login | Main.cpp:77 |
| Launcher | Cancel() | Java_com_bearmod_Launcher_Cancel | Main.cpp:82 |
| Launcher | Error() | Java_com_bearmod_Launcher_Error | Main.cpp:87 |
| Launcher | Ok() | Java_com_bearmod_Launcher_Ok | Main.cpp:97 |
| Launcher | Loging() | Java_com_bearmod_Launcher_Loging | Main.cpp:102 |

## Outbound (C++ → Java) — ESP.h callbacks to ESPView
| C++ Method | Java Method | Signature |
|---|---|---|
| ESP::DrawText | NRG_DrawText | (Canvas;IIIIString;FFF)V |
| ESP::DrawLine2 | NRG_DrawLine | (Canvas;IIIIFFFFF)V |
| ESP::DrawCircle | NRG_DrawCircle | (Canvas;IIIIFFFF)V |
| ESP::DrawFilledRect | NRG_DrawFilledRect | (Canvas;IIIIFFFF)V |
| ESP::DrawRect | DrawRect | (Canvas;IIIIIFFFFF)V |
| ESP::DrawWeaponIcon | NRG_DrawWeaponIcon | (Canvas;IFF)V |
| ESP::DrawOTH | NRG_DrawOTH | (Canvas;IFF)V |

## ⚠️ NEVER rename any of these without /jni-verify first
