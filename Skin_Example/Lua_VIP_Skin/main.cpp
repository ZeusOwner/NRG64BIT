#include "Skins.h"

#include <thread>
#include <chrono>
#include "Lua/LuaGlobal.cpp"
void Main_Thread2()
{
    while (!UE4) 
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        
    *(uintptr_t *)&Lua::luaL_loadbufferx_Ptr = UE4 + (0xAEE68A8);
    *(uintptr_t *)&Lua::lua_pcall_Ptr = UE4 + (0xAEC3098);
    *(uintptr_t *)&Lua::sub_BA003F8_Ptr = UE4 + (0xBBF98B4);
    *(uintptr_t *)&Lua::lua_tostring_Ptr = UE4 + (0xAEC14B8);

    Lua::Initialize();
}
__attribute__((constructor)) void library_constructor()
{
    std::thread(Main_Thread2).detach();
}
void *main_thread(void *) {
    UE4 = GetBaseAddress("libUE4.so");
    while (!UE4) {
        UE4 = GetBaseAddress("libUE4.so");
        sleep(1);
    }
    if (UE4) {
        DobbyHook((void *)(UE4 + Process_Event_Skins), (void *)hkProcessEvent, (void **)&oProcessEvent);
    }
    return 0;
}
__attribute__((constructor)) void _init() {
    pthread_t thread;
    pthread_create(&thread, 0, main_thread, 0);
}
