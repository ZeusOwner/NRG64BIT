#pragma once
#include <cstring>
#include "Lua/SkinLua.cpp"
namespace Lua
{
    int (*luaL_loadbufferx_Ptr)(void* L, const char* buff, size_t size, const char* name, const char* mode);
    int (*lua_pcall_Ptr)(void* L, int nargs, int nresults, int errfunc);
    int64_t (*sub_BA003F8_Ptr)(int a1);
    const char* (*lua_tostring_Ptr)(void* L, int index);

    void* GetLuaState()
    {
        if (sub_BA003F8_Ptr)
        {
            for (int i = 0; i < 16; i++)
            {
                int64_t result = sub_BA003F8_Ptr(i);
                if (result)
                {
                    void* L = *(void**)(result + 80);
                    if (L)
                    {
                        return L;
                    }
                }
            }
        }
        return nullptr;
    }

    bool ExecuteLuaScript(void* L, const char* script, const char* name)
    {
        if (!L || !luaL_loadbufferx_Ptr || !lua_pcall_Ptr) return false;        
        int load_result = luaL_loadbufferx_Ptr(L, script, strlen(script), name, "t");
        if (load_result == 0)
        {
            int exec_result = lua_pcall_Ptr(L, 0, 0, 0);
            if (exec_result != 0 && lua_tostring_Ptr)
            {
                const char* err = lua_tostring_Ptr(L, -1);
                if (err) LOGE("[Lua] Error: %s", err);
            }
            LOGI("[Lua] Executed script: %s", name);
            return exec_result == 0;
        } else {
            if (lua_tostring_Ptr)
            {
                const char* err = lua_tostring_Ptr(L, -1);
                if (err) LOGE("[Lua] Error: %s", err);
            }
            return false;
        }
    }
    void Initialize()
    {
        static bool initialized = false;
        if (initialized) return;
        if (!luaL_loadbufferx_Ptr || !lua_pcall_Ptr)
        {
            LOGE("[Lua] Lua function pointers not initialized");
            return;
        }        
        void* ctx = GetLuaState();
        if (!ctx)
        {
            return;
        }
        ExecuteLuaScript(ctx, mySkinLuaScript, "SkinSystem");
        initialized = true;
        LOGI("[Lua] Initializing Lua injection system");
        LOGI("[Lua] Initialization complete");
    }
}
