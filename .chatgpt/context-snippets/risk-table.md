# RISK TABLE QUICK REFERENCE
# Paste this when doing risk/fix discussions — saves re-reading full audit

## Active Risks (from Kilo Code Audit 2026-05-18)

| # | Severity | Location | Risk Type | Status |
|---|---|---|---|---|
| 1 | 🔴 CRITICAL | Floating.java ~line 354 | onSendConfig() INFINITE RECURSION — Java shadows native, calls itself | OPEN |
| 2 | 🔴 HIGH | Floating.java ~line 87-97 | Static WindowManager + LayoutParams hold Context refs | OPEN |
| 3 | 🔴 HIGH | Floating.java ~line 136 | Non-static Handler holds implicit Floating Service ref | OPEN |
| 4 | 🔴 HIGH | Launcher.java line 247 | Anonymous Handler holds Activity ref (@SuppressLint HandlerLeak) | OPEN |
| 5 | 🔴 HIGH | NRG.h line 50 | Config std::map — null/garbage if called after lib unload | OPEN |
| 6 | 🟠 MED | ESP.h line 36-43 | JNI FindClass/GetMethodID — no null checks on returned IDs | OPEN |
| 7 | 🟠 MED | Launcher.java line 343 | Thread no lifecycle management — can fire after Context GC'd | OPEN |
| 8 | 🟠 MED | Main.cpp line 351 | _bypass() pthread loops sleep(1) forever — no recovery | OPEN |
| 9 | 🟠 MED | Floating.java LoadConfiguration1() | BufferedReader not in finally — FD leak on exception | OPEN |
| 10 | 🟡 LOW | Tools.cpp IsPtrValid() | open("/dev/random") FD leak on repeated calls | OPEN |
| 11 | 🟡 LOW | ESP.h wcstojstr() | LocalRef not cleaned for charset/charBuffer | OPEN |
| 12 | 🟡 LOW | Floating.java addSkinWindow() | 40+ SeekBars not recycled — 2 GradientDrawables each | OPEN |

## Fix Priority Order
1. Risk #1 — onSendConfig recursion (CRITICAL — fix first)
2. Risk #3 — Handler leak Floating
3. Risk #4 — Handler leak Launcher
4. Risk #6 — ESP.h null checks
5. Risk #9 — BufferedReader FD leak

## Update instructions
When a risk is fixed: change Status from OPEN → FIXED [date]
