# NRG64BIT Android Mod

This repository contains an Android mod project targeting `com.bearmod` with native JNI code and an overlay/service UI for in-game modifications.

## Project structure

- `app/` - Android app module
  - `src/main/java/com/bearmod/` - Java source code
  - `src/main/jni/` - Native C/C++ source and JNI bridge
  - `src/main/AndroidManifest.xml` - App manifest
- `gradle/`, `gradle-wrapper.properties`, `gradlew`, `gradlew.bat` - Gradle wrapper and build tooling
- `CLAUDE.md` - project architecture and JNI reference notes

## Key build commands

From the repository root:

- `./gradlew assembleDebug` or `gradlew.bat assembleDebug --console=plain`
- `./gradlew clean` to clean the Gradle build

Native build is typically driven from the app module and may use `ndk-build` as configured in `app/src/main/jni/Android.mk`.

## Notes

- The native library `libbear.so` is loaded by Java code in the app.
- JNI entry points and method names are critical: avoid renaming bridge methods without carefully verifying JNI registration.
- The repository currently has an embedded SDK/UE4 native integration and custom overlay UI logic.

## Recommended files to inspect first

- `CLAUDE.md` - architecture overview and risk notes
- `app/src/main/jni/Main.cpp` - JNI entry and native bridge
- `app/src/main/java/com/bearmod/Floating.java` - overlay service logic
- `app/build.gradle` - app module Gradle settings
