LOCAL_PATH := $(call my-dir)
MAIN_LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := libcurl
LOCAL_SRC_FILES := curl/curl-android-$(TARGET_ARCH_ABI)/lib/libcurl.a
include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := libssl
LOCAL_SRC_FILES := curl/openssl-android-$(TARGET_ARCH_ABI)/lib/libssl.a
include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := libcrypto
LOCAL_SRC_FILES := curl/openssl-android-$(TARGET_ARCH_ABI)/lib/libcrypto.a
include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE    := bear

LOCAL_CFLAGS := -Wno-error=format-security -fvisibility=hidden -ffunction-sections -fdata-sections -w
LOCAL_CFLAGS += -fno-rtti -fno-exceptions -fpermissive
LOCAL_CPPFLAGS := -Wno-error=format-security -fvisibility=hidden -ffunction-sections -fdata-sections -w -Werror -s -std=c++17
LOCAL_CPPFLAGS += -Wno-error=c++11-narrowing -fms-extensions -fno-rtti -fno-exceptions -fpermissive
LOCAL_LDFLAGS += -Wl,--gc-sections,--strip-all, -llog
LOCAL_ARM_MODE := arm


LOCAL_C_INCLUDES += $(MAIN_LOCAL_PATH)


# Here you add the cpp file
LOCAL_SRC_FILES := Main.cpp \
        Tools.cpp \
        UpdateSkinManager.cpp \
        SkinMapping.cpp \
        skin_tables/ace32_skins.cpp \
        skin_tables/akm_skins.cpp \
        skin_tables/amr_skins.cpp \
        skin_tables/aug_skins.cpp \
        skin_tables/awm_skins.cpp \
        skin_tables/backpack_skins.cpp \
        skin_tables/bizon_skins.cpp \
        skin_tables/boat_skins.cpp \
        skin_tables/buggy_skins.cpp \
        skin_tables/couplerb_skins.cpp \
        skin_tables/dacia_skins.cpp \
        skin_tables/dbs_skins.cpp \
        skin_tables/dp28_skins.cpp \
        skin_tables/groza_skins.cpp \
        skin_tables/helmet_skins.cpp \
        skin_tables/honey_skins.cpp \
        skin_tables/kar98_skins.cpp \
        skin_tables/m16a4_skins.cpp \
        skin_tables/m24_skins.cpp \
        skin_tables/m249_skins.cpp \
        skin_tables/m416_skins.cpp \
        skin_tables/m762_skins.cpp \
        skin_tables/mg3_skins.cpp \
        skin_tables/mini14_skins.cpp \
        skin_tables/minibus_skins.cpp \
        skin_tables/mk14_skins.cpp \
        skin_tables/moto_skins.cpp \
        skin_tables/p90_skins.cpp \
        skin_tables/pan_skins.cpp \
        skin_tables/parachute_skins.cpp \
        skin_tables/qbz_skins.cpp \
        skin_tables/s12k_skins.cpp \
        skin_tables/scarl_skins.cpp \
        skin_tables/thompson_skins.cpp \
        skin_tables/uaz_skins.cpp \
        skin_tables/ump45_skins.cpp \
        skin_tables/uzi_skins.cpp \
        skin_tables/vector_skins.cpp \
        skin_tables/xm1014_skins.cpp \
        skin_tables/xsuit_skins.cpp \
        md5.cpp\
        KittyMemory/KittyMemory.cpp \
        KittyMemory/MemoryPatch.cpp \
        KittyMemory/MemoryBackup.cpp \
        KittyMemory/KittyUtils.cpp \
        base64/base64.cpp \
        Substrate/hde64.c \
        Substrate/SubstrateDebug.cpp \
        Substrate/SubstrateHook.cpp \
        Substrate/SubstratePosixMemory.cpp \
        Substrate/And64InlineHook.cpp \
        SDK/PUBGM_Basic.cpp\
        SDK/PUBGM_Basic_functions.cpp\
        SDK/PUBGM_CoreUObject_functions.cpp\
        SDK/PUBGM_Engine_functions.cpp\
        SDK/PUBGM_ShadowTrackerExtra_functions.cpp\
        SDK/PUBGM_Client_functions.cpp\
        
        
LOCAL_C_INCLUDES := $(LOCAL_PATH)/curl/curl-android-$(TARGET_ARCH_ABI)/include
LOCAL_C_INCLUDES += $(LOCAL_PATH)/curl/openssl-android-$(TARGET_ARCH_ABI)/include


 LOCAL_CPP_FEATURES                      := exceptions   
LOCAL_LDLIBS                            := -llog -landroid -lz
LOCAL_STATIC_LIBRARIES                  := libcurl libssl libcrypto
include $(BUILD_SHARED_LIBRARY)
