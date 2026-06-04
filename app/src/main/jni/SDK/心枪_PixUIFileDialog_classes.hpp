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
// Class PixUIFileDialog.PxFileDialogMgr
// 0x0000 (0x0028 - 0x0028)
class UPxFileDialogMgr : public UObject
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class PixUIFileDialog.PxFileDialogMgr");
		return pStaticClass;
	}

};


}

