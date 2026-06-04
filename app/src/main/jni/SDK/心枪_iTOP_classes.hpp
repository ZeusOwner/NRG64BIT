#pragma once

/*
// ------------------------------------------------
DUMP SDK BY @Sanji1_Owner V4.4.0

TELEGRAM CHANNEL @NIKA_SOURCE_MODS

All rights reserved by the NIKA TEAM AND INCLUDED TEAM

@INCLUDED_SO
// ------------------------------------------------
*/

namespace SDK
{
//-------------------------------------------------
//Classes
//-------------------------------------------------
// Class iTOP.FBHelper
// 0x0000 (0x0028 - 0x0028)
class UFBHelper : public UObject
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class iTOP.FBHelper");
		return pStaticClass;
	}


	static void DelayToSetAutoInitFacebookLog(bool IsAutoInit);
	static void DelayToInitFacebookSDK(bool IsAutoInit, bool WithLaunchOption);
};


}

