
#include "Helper/Includes.h"
#include "NRG.h"


bool TestGGG = false;
bool IsHideEsp(JNIEnv * env, jobject activityObject)
{
 if (TestGGG == true){
return true;
}
}
void native_onSendConfig(JNIEnv *env, jobject thiz, jstring s, jstring v) {
    const char *config = env->GetStringUTFChars(s, 0);
    const char *value = env->GetStringUTFChars(v, 0);

    if (!strcmp(config, "CMD_PARSE_ITEMS")) {
        itemData = json::parse(value);
    } else if (!strcmp(config, "ESP::ITEMS")) {
        u_long itemId = strtoul(value, 0, 0);
        itemConfig[itemId] = !itemConfig[itemId];
    } else {
        Config[config] = (u_long) strtoul(value, 0, 0);
    }
}
    extern "C" JNIEXPORT jstring JNICALL
Java_com_bearmod_Floating_timeshow(JNIEnv *env, jobject activityObject) {
    return env->NewStringUTF(expiredDate.c_str());
}
        

#include "MOD/LOGO.h"
#include "MOD/AimOn.h"
#include "MOD/AimOff.h"
extern "C" JNIEXPORT jstring JNICALL
Java_com_bearmod_Floating_onlinename(JNIEnv *env, jobject activityObject) {
    return env->NewStringUTF(OBFUSCATE("NRG MOD 64bit < v1.4"));
}
extern "C" JNIEXPORT jstring JNICALL
Java_com_bearmod_Floating_aimOnIcon(JNIEnv *env, jobject activityObject) {
    return env->NewStringUTF(AIMON_B64);
}
extern "C" JNIEXPORT jstring JNICALL
Java_com_bearmod_Floating_aimOffIcon(JNIEnv *env, jobject activityObject) {
    return env->NewStringUTF(AIMOFF_B64);
}
extern "C" JNIEXPORT jstring JNICALL
Java_com_bearmod_Floating_channellink(JNIEnv *env, jobject activityObject) {
    return env->NewStringUTF(OBFUSCATE("https://t.me/TeamNRG_MOD"));
}
extern "C" JNIEXPORT jstring JNICALL
Java_com_bearmod_Floating_feedbacklink(JNIEnv *env, jobject activityObject) {
    return env->NewStringUTF(OBFUSCATE("https://t.me/TMNrgOwnerBot"));
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_bearmod_Floating_ChannelName(JNIEnv *env, jobject activityObject) {
    return env->NewStringUTF(OBFUSCATE("JOIN OFFICIAL CHANNEL"));
}
extern "C" JNIEXPORT jstring JNICALL
Java_com_bearmod_Floating_FeedBackName(JNIEnv *env, jobject activityObject) {
    return env->NewStringUTF(OBFUSCATE("FeedBack"));
}


extern "C" JNIEXPORT jstring JNICALL
Java_com_bearmod_Floating_cfg(JNIEnv *env, jobject activityObject ) {
jstring str = env->NewStringUTF(OBFUSCATE("NRG_SaveFile.cfg"));
return str;
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_bearmod_Launcher_LoginNameNrg(JNIEnv *env, jobject activityObject) {
    return env->NewStringUTF(OBFUSCATE("NRG MOD Login"));
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_bearmod_Launcher_Pleaselog(JNIEnv *env, jobject activityObject) {
    return env->NewStringUTF(OBFUSCATE("Please log in"));
}
extern "C" JNIEXPORT jstring JNICALL
Java_com_bearmod_Launcher_KeyAdd(JNIEnv *env, jobject activityObject) {
    return env->NewStringUTF(OBFUSCATE("Key..."));
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_bearmod_Launcher_Login(JNIEnv *env, jobject activityObject) {
    return env->NewStringUTF(OBFUSCATE("                Login                "));
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_bearmod_Launcher_Cancel(JNIEnv *env, jobject activityObject) {
    return env->NewStringUTF(OBFUSCATE("               Cancel                "));
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_bearmod_Launcher_Error(JNIEnv *env, jobject activityObject) {
    return env->NewStringUTF(OBFUSCATE("Error"));
}


extern "C" JNIEXPORT jstring JNICALL
Java_com_bearmod_Launcher_Pleasecheck(JNIEnv *env, jobject activityObject) {
    return env->NewStringUTF(OBFUSCATE("                               Please check your key                               "));
}
extern "C" JNIEXPORT jstring JNICALL
Java_com_bearmod_Launcher_Ok(JNIEnv *env, jobject activityObject) {
    return env->NewStringUTF(OBFUSCATE("                         OK                         "));
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_bearmod_Launcher_Loging(JNIEnv *env, jobject activityObject) {
    return env->NewStringUTF(OBFUSCATE("  KEY LOADING...  "));//Loging in...
}
jclass (*orig_FindClass)(JNIEnv *env, const char *name);
int Register1(JNIEnv *env) {
    JNINativeMethod methods[] = {{"onSendConfig", "(Ljava/lang/String;Ljava/lang/String;)V", (void *) native_onSendConfig}/*,
                                 {"onCanvasDraw", "(Landroid/graphics/Canvas;IIF)V",         (void *) native_onCanvasDraw}*/};
    jclass clazz = env->FindClass("com/bearmod/Floating");
    if (!clazz)
        return -1;

    if (env->RegisterNatives(clazz, methods, sizeof(methods) / sizeof(methods[0])) != 0)
        return -1;

    return 0;
}


int Register2(JNIEnv *env) {
    JNINativeMethod methods[] = {{"Init",  "(Landroid/content/Context;)V", (void *) native_Init},
                                 {"Check", "(Landroid/content/Context;Ljava/lang/String;)Ljava/lang/String;", (void *) native_Check}};

    jclass clazz = env->FindClass("com/bearmod/Launcher");
    if (!clazz)
        return -1;

    if (env->RegisterNatives(clazz, methods, sizeof(methods) / sizeof(methods[0])) != 0)
        return -1;

    return 0;
}

int Register3(JNIEnv *env) {
JNINativeMethod methods[] = {{"IsHideEsp","()Z", (void *) IsHideEsp}};
jclass clazz = env->FindClass("com/bearmod/Floating");
if (!clazz)
return -1;
if (env->RegisterNatives(clazz, methods, sizeof(methods) / sizeof(methods[0])) != 0)
return -1;
return 0;
} 
void* hook_dlsym(void* handle, const char* s)
{
 if (strstr(s, "memcpy"))
 {
LOGI("s : %s" , s);
 return dlsym(handle, s);
 }
 return dlsym(handle, s);
}


unsigned int libanogsSize1 = 0x549000;
char *Offset1;
uintptr_t libanogsBase1 = 0;
uintptr_t libanogsAlloc1 = 0;
uintptr_t NewBase1 = 0;

void* hook_memcpy2(char *dest, const char *src, size_t size)
{
    if ((DWORD2)src >= libanogsBase1 && (DWORD2)src <= (DWORD2)(libanogsBase1 + libanogsSize1))
    {
        Offset1 = (char *)(src - (char *)libanogsBase1);
        NewBase1 = libanogsAlloc1;
        src = &Offset1[NewBase1];
        return memcpy(dest, src, size);
    }
    
    return memcpy(dest, src, size);
}
///////


class _BYTE;
class _QWORD;
class _WORD;

#define _QWORD long
#define _BYTE long
#define _WORD long

DWORD2 libanogsBase = 0;
DWORD2 libUE4Base = 0;
DWORD2 libanortBase = 0;
DWORD2 libEGLBase = 0;
DWORD2 libanogsAlloc = 0;
DWORD2 libUE4Alloc = 0;
DWORD2 libEGLAlloc = 0; 

unsigned int libUE4Size  = 0x3598972;
unsigned int libanogsSize  = 0x487579;
unsigned int libEglSize = 0x2000;
char *Offset;
DWORD2 NewBase = 0;

int64_t memcpy_chk()
{
 return 0LL;
}


__int64 __fastcall (*subx)(unsigned int *);
__int64 __fastcall (*sub_58BE638)(unsigned int *a1, char a2);
__int64 __fastcall hsub_58BE638(unsigned int *a1, char a2)
{
 auto result = subx(a1 + 258);
  if ( (result & 1) != 0 )
  {
    return 0;
  }
  return sub_58BE638(a1, a2);
}


size_t hook_strlen(const char *s)
{
if (strstr(s, "GuestBindHandler") || strstr(s, "eglSwapBuffers"))
    {
        return 0;
    }
    return strlen(s);
}
size_t hook_strlen2(const char *s)
{
if (strstr(s, "eglSwapBuffers"))
    {
        return 0;
    }
    return strlen(s);
}

int ret() {
return 0;
}

void*hook_memcpy(char *dest, const char *src, size_t size)
{
    if ((DWORD2)src >= libanogsBase && (DWORD2)src <= (DWORD2)(libanogsBase + libanogsSize))
    {
        Offset = (char *)(src - (char *)libanogsBase);
        NewBase = libanogsAlloc;
        src = &Offset[NewBase];
        return memcpy(dest, src, size);
    }
    if ((DWORD2)src >= libUE4Base && (DWORD2)src <= (DWORD2)(libUE4Base + libUE4Size))
    {
        Offset = (char *)(src - (char *)libUE4Base);
        NewBase = libUE4Alloc;
        src = &Offset[NewBase];
        return memcpy(dest, src, size);
    }
    return memcpy(dest, src, size);
}

__int64 (*osub_1749A8)(__int64 a1, __int64 a2, char a3);
__int64 hsub_1749A8(__int64 a1, __int64 a2, char a3){
    if(strstr((const char *)a2,"scan1") ||
     strstr((const char *)a2,"inline_hook_opcode_dismatch") ||
     strstr((const char *)a2,"set_inline_hook_error") ||
     strstr((const char *)a2,"opcode_crash")) {
     return 0;
     }
        return osub_1749A8(a1,a2,a3);
}

int return_0(){
return 0;
}


_QWORD * (*sub_3DE65C)(int a1, unsigned int a2);
_QWORD *__fastcall hsub_3DE65C(int a1, unsigned int a2)
{
    if ( a2 <= 6 )
    {
        return sub_3DE65C(a1,0);
        
    }
    return sub_3DE65C(a1,a2);
}

__int64 (*sub_3C2CE8)(__int64 inputString);
__int64 hsub_3C2CE8(__int64 inputString) {
    __int64 tempPointer = inputString - 1;
    while (*(unsigned char*)++tempPointer != 0);
    if (strstr((const char *)inputString, "various_opcode_objvm") ||
        strstr((const char *)inputString, "various_opcode")) {
        return tempPointer - inputString < 1;
    }
return tempPointer - inputString;
}


int64_t (*osub_1672E8)(int64_t a1, unsigned __int8  *a2,  int a3);
int64_t hsub_1672E8(int64_t a1, unsigned __int8  *a2, int a3)
{
    void *v7;
    v7 = *(void **)(a1 + 26);
    *(_WORD *)(a1 + 24) = a3;

    if(a3 == 0x3E){
        memcpy(v7, a2, a3);
        return osub_1672E8(a1,a2,a3);
    }
    if(a3 == 0x33){
        memcpy(v7, a2, a3);
        return osub_1672E8(a1,a2,a3);
    }
    if(a3 == 0x35){
        memcpy(v7, a2, a3);
        return osub_1672E8(a1,a2,a3);
    }
    return 0LL;
}
const char *sub_3DB4D8()
{
  return "FooGameClientIPC";
}



#define targetLibName OBFUSCATE("libanogs.so")
void *IsAntiCheat(void *) {
do {
sleep(1);
} while (!isLibraryLoaded(targetLibName));


return 0; 
}


__int64 __fastcall (*sub_16E72C)(__int64 a1);
__int64 __fastcall hsub_16E72C(__int64 a1)
 {
 while (true) {
 sleep(1);
 }
 return sub_16E72C(a1);
} 
void *IsAntiCheat2(void *) {
do {
//sleep(1);
} while (!isLibraryLoaded(targetLibName));

return 0;
}


__attribute((constructor)) void _bypass() {
pthread_t t;
pthread_create(&t, 0, IsAntiCheat, 0);
pthread_create(&t, 0, IsAntiCheat2, 0);
}


JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *reserved) {
    JNIEnv *env;
    vm->GetEnv((void **) &env, JNI_VERSION_1_6);

    if (Register1(env) != 0)
        return -1;

    if (Register2(env) != 0)
        return -1;
        
    if (Register3(env) != 0)
        return -1;
        
    
        pthread_t t;
      pthread_create(&t, 0, Init_Thread, 0);
        
    return JNI_VERSION_1_6;
}
