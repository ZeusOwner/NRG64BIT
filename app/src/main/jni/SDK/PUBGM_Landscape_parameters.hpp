#pragma once

// PUBG MOBILE (4.5.0 -- 64bit Beta) SDK Generate By @ByDwoz
// Telegram Channel:- @XelahotOfficial
// Generate on Wed Jul  8 13:37:44 2026
 
#include "../SDK.hpp"

namespace SDK
{
//---------------------❣︎➪ 𝗕𝗬𝗗𝗪𝗢𝗭 𝗗𝗘𝗩𝗘𝗟𝗢𝗣𝗘𝗥༆✈︎🇪🇬---------------------------
//Parameters
//---------------------❣︎➪𝗕𝗬𝗗𝗪𝗢𝗭 𝗗𝗘𝗩𝗘𝗟𝗢𝗣𝗘𝗥༆✈︎🇪🇬---------------------------

// Function Landscape.LandscapeProxy.SetLandScapeRenderMask
struct ALandscapeProxy_SetLandScapeRenderMask_Params
{
	int                                                Index;                                                    // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
	bool                                               bUseRenderMask;                                           // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
	unsigned char                                      RenderMask;                                               // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
};

// Function Landscape.LandscapeProxy.EditorApplySpline
struct ALandscapeProxy_EditorApplySpline_Params
{
	class USplineComponent*                            InSplineComponent;                                        // (Parm, ZeroConstructor, InstancedReference, IsPlainOldData)
	float                                              StartWidth;                                               // (Parm, ZeroConstructor, IsPlainOldData)
	float                                              EndWidth;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
	float                                              StartSideFalloff;                                         // (Parm, ZeroConstructor, IsPlainOldData)
	float                                              EndSideFalloff;                                           // (Parm, ZeroConstructor, IsPlainOldData)
	float                                              StartRoll;                                                // (Parm, ZeroConstructor, IsPlainOldData)
	float                                              EndRoll;                                                  // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                NumSubdivisions;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               bRaiseHeights;                                            // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               bLowerHeights;                                            // (Parm, ZeroConstructor, IsPlainOldData)
	class ULandscapeLayerInfoObject*                   PaintLayer;                                               // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Landscape.LandscapeProxy.ChangeLODDistributionSettingConsoleVariable
struct ALandscapeProxy_ChangeLODDistributionSettingConsoleVariable_Params
{
};

// Function Landscape.LandscapeProxy.ChangeLODDistanceFactor
struct ALandscapeProxy_ChangeLODDistanceFactor_Params
{
	float                                              InLODDistanceFactor;                                      // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Landscape.LandscapeProxy.ChangeLOD0DistributionSettingConsoleVariable
struct ALandscapeProxy_ChangeLOD0DistributionSettingConsoleVariable_Params
{
};

// Function Landscape.LandscapeProxy.ChangebUseScreenSizeLOD
struct ALandscapeProxy_ChangebUseScreenSizeLOD_Params
{
	bool                                               InbUseScreenSizeLOD;                                      // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Landscape.IdeaGrassFieldFunctionLibrary.IdeaGrassRenderForceTextureTrample
struct UIdeaGrassFieldFunctionLibrary_IdeaGrassRenderForceTextureTrample_Params
{
	struct FIdeaGrassFieldData                         GrassFieldData;                                           // (Parm)
};

// Function Landscape.IdeaGrassFieldFunctionLibrary.IdeaGrassRenderForceTextureSkill
struct UIdeaGrassFieldFunctionLibrary_IdeaGrassRenderForceTextureSkill_Params
{
	struct FIdeaGrassFieldData                         GrassFieldData;                                           // (Parm)
};

// Function Landscape.IdeaGrassFieldFunctionLibrary.IdeaGrassRenderForceTextureFade
struct UIdeaGrassFieldFunctionLibrary_IdeaGrassRenderForceTextureFade_Params
{
	struct FIdeaGrassFieldData                         GrassFieldData;                                           // (Parm)
};

// Function Landscape.IdeaGrassFieldFunctionLibrary.IdeaGrassRenderForceTexture
struct UIdeaGrassFieldFunctionLibrary_IdeaGrassRenderForceTexture_Params
{
	struct FIdeaGrassFieldData                         GrassFieldData;                                           // (Parm)
};

}

