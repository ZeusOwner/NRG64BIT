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
// Class PixUIRHI.PxRHIImage
// 0x0000 (0x0028 - 0x0028)
class UPxRHIImage : public UObject
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class PixUIRHI.PxRHIImage");
		return pStaticClass;
	}


	class UObject* GetHandleObject();
};


// Class PixUIRHI.PxRHIMgr
// 0x0000 (0x0028 - 0x0028)
class UPxRHIMgr : public UObject
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class PixUIRHI.PxRHIMgr");
		return pStaticClass;
	}


	static bool RHIImageUpdate(class UPxRHIMgr* pPxRHIImage);
	static class UPxRHIMgr* RHIImageFindByObject(class UObject* pCoreObject);
	static bool RHIImageDestroy(class UPxRHIMgr* pPxRHIImage);
	static class UPxRHIImage* RHIImageCreate();
	static class UPxRHIMgr* Get();
};


// Class PixUIRHI.PxRHIRender
// 0x0098 (0x00C0 - 0x0028)
class UPxRHIRender : public UObject
{
public:
	unsigned char                                      UnknownData00[0x98];                                      // 0x0028(0x0098) MISSED OFFSET

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class PixUIRHI.PxRHIRender");
		return pStaticClass;
	}

};


}

