#include "Helper/StrEnc.h"
#include "Helper/struct.h"
#include "Helper/Includes.h"

#include "Helper/obfuscate.h"
#include <curl/curl.h>
#include "Tools.h"
#include "Helper/json.hpp"
#include "base64/base64.h"
#include "md5.h"
#include "enc.h"
//#include "Engine/Canvas.h"

#include "Engine/Vector2.hpp"
#include "Engine/Vector3.hpp"
#include "Engine/Rect.h"

#include "KittyMemory/MemoryPatch.h"

#include "TEAMNRG/Utils.h"
#include "TEAMNRG/Macros.h"
#include "ESP.h"
#include "timer.h"
#include "all_items_data.h"
#include "UpdateSkinManager.h"

#include <array>

// Modern skin table data (post-migration cleanup).
#include "skin_tables/backpack_skins.h"
#include "skin_tables/helmet_skins.h"
#include "skin_tables/akm_skins.h"
#include "skin_tables/m16a4_skins.h"
#include "skin_tables/m416_skins.h"
#include "skin_tables/scarl_skins.h"
#include "skin_tables/m762_skins.h"
ESP espOverlay;

using json = nlohmann::json;

json items_data;
//using json = nlohmann::ordered_json;

using namespace std;
//#include "Quaternion.hpp"

#include "SDK.hpp"
using namespace SDK;
extern void StartRuntimeHook(const char *);
#include "UE4.h"

// Auto Feedback (chicken dinner report) — requires stb_image_write.h next to AutoFeedback.h
#if __has_include("AutoFeedback.h")
#define BEAR_HAS_AUTO_FEEDBACK 1
#include "AutoFeedback.h"
#else
#define BEAR_HAS_AUTO_FEEDBACK 0
#endif
#define PI 3.14159265358979323846f
#define SLEEP_TIME 1000LL / 60LL
#define W2S(w, s) UGameplayStatics::ProjectWorldToScreen(localController, w, true, s)

uintptr_t UE4 = 0, anogs, gcloud;
bool BYPASSLOGO;
bool BYPASSISLAND;
int g_screenWidth = 0, g_screenHeight = 0, g_screenDensity = 0;
float density = -1;
//static bool switchState;
std::string g_Token, g_Auth;
std::map<std::string, u_long> Config;
char extra[30];

bool bValid = true, bScanPatternCompleted = false;
bool SOON_OPEN = false;
bool BypassLogo = true;
std::string expiredDate = "";
std::string DisplayNotice = "";

std::map<int, bool> itemConfig;
json itemData;


struct sRegion {
	uintptr_t start, end;
};

std::vector<sRegion> trapRegions;

int SizeXx = 0;
int SizeYy = 0;
int MainSuit = 0;

//4.4 update
#define GNames_Offset 0x85dbcec
#define GUObject_Offset 0xea31560
#define ProcessEvent_Offset 0x884e068

/*
#define Gnames_Offset 0x85dbcec
#define GEngine_Offset 0xecf15c0 //UEngine
#define GUObject_Offset 0xea31560
#define GetActorArray_Offset 0xa34a0d0
#define PostRender_Offset 0xa253214
#define GNativeAndroidApp_Offset 0xe775f98
#define Process_Event 0x884e068
#define K2_drawLine_Offset 0xa845168
#define K2_drawTexture_Offset 0xa8451ec
#define K2_drawText_Offset 0xa8453f8
#define LaunchBP_Offset 0x7221730
*/

//===========================================================================================================================================================================\\


int pid = -1;
int initPid() {
    pid = getpid();
    return pid;
}
#define BYTE1024 0x00000400
#define BYTE16 0x00000010

long GetModuleBase(const char *moduleName) {
    initPid();
    char path[BYTE1024], line[BYTE1024];
    if (pid == -1)
        sprintf(path, "/proc/self/maps");
    else
        sprintf(path, "/proc/%d/maps", pid);
    FILE *file = fopen(path, "r");
    long len = 0;
    if (file) {
        while (fgets(line, sizeof(line), file)) {
            if (strstr(line, moduleName) != NULL) {
                len = strtoul(line, NULL, BYTE16);
                break;
            }
        }
    }
    return len;
}


ASTExtraPlayerCharacter *g_LocalPlayer;
ASTExtraPlayerController *g_PlayerController;
FCameraCacheEntry  CameraCache = FCameraCacheEntry();


android_app *g_App = 0;
template<typename T>
void Write(uintptr_t addr, T value) {
	Tools::WriteAddr((void *) addr, &value, sizeof(T));
}
template<typename T = uintptr_t>
T Read(uintptr_t addr) {
	T result{};
	if (Tools::ReadAddr((void *) addr, &result, sizeof(T))) {
		return result;
	}
	return result;
}


TNameEntryArray *GetGNames() {
    return ((TNameEntryArray *(*)()) (UE4 + GNames_Offset))();
}


UWorld *GEWorld;
int GWorldNum = 0;
TUObjectArray gobjects;
UWorld *GetWorld()
{
 if(GWorldNum == 0) {
  gobjects = UObject::GUObjectArray->ObjObjects;
  for (int i=0; i< gobjects.Num(); i++)
  if (auto obj = gobjects.GetByIndex(i)) {
if(obj->IsA(UEngine::StaticClass())) {
auto GEngine = (UEngine *) obj;
if(GEngine) {
auto ViewPort = GEngine->GameViewport;
if (ViewPort)
{
GEWorld = ViewPort->World;
GWorldNum = i;
return ViewPort->World;
}
}
}
  }
 }else {
  auto GEngine = (UEngine *) (gobjects.GetByIndex(GWorldNum));
  if(GEngine) {
  auto ViewPort = GEngine->GameViewport;
  if(ViewPort) {
GEWorld = ViewPort->World;
return ViewPort->World;
  }
  }
 }
 return 0;
}

std::vector<AActor *> getActors() 
{
    UGameplayStatics *gGameplayStatics = (UGameplayStatics *)gGameplayStatics->StaticClass();
 AActor* Actor1 = (AActor*)Actor1->StaticClass();
 auto GWorld = GetWorld();
    if (!GWorld) 
  return std::vector<AActor *>();
  
    auto Level = GWorld->PersistentLevel;
    if (!Level)
  return std::vector<AActor *>();
        
    std::vector<AActor*> actor;
    TArray<AActor*> Actors;
    gGameplayStatics->GetAllActorsOfClass((UObject *)GWorld, Actor1->StaticClass(), &Actors);
    for (int i = 0; i < Actors.Num(); i++)
        {
   auto Actor = Actors[i];
   actor.push_back((AActor*)Actor);
  }
   return actor;
 }
 
bool isObjectInvalid(UObject *obj) {
    if (!Tools::IsPtrValid(obj)) {
        return true;
    }

    if (!Tools::IsPtrValid(obj->ClassPrivate)) {
        return true;
    }

    if (obj->InternalIndex <= 0) {
        return true;
    }

    if (obj->NamePrivate.ComparisonIndex <= 0) {
        return true;
    }

    if ((uintptr_t)(obj) % sizeof(uintptr_t) != 0x0 && (uintptr_t)(obj) % sizeof(uintptr_t) != 0x4) {
        return true;
    }

    if (std::any_of(trapRegions.begin(), trapRegions.end(), [obj](sRegion region) { return ((uintptr_t) obj) >= region.start && ((uintptr_t) obj) <= region.end; }) ||
        std::any_of(trapRegions.begin(), trapRegions.end(), [obj](sRegion region) { return ((uintptr_t) obj->ClassPrivate) >= region.start && ((uintptr_t) obj->ClassPrivate) <= region.end; })) {
        return true;
    }

    return false;
}
bool isObjectController(UObject *Object) {
    if (!Tools::IsPtrValid(Object)) {
        return false;
    }
    for (auto super = Object->ClassPrivate; Tools::IsPtrValid(super); super = (UClass *) super->SuperStruct) {
        if (super == ASTExtraPlayerController::StaticClass()) {
            return true;
        }
    }
    return false;
}

string getObjectPath(UObject *Object) {
	string s;
	for (auto super = Object->ClassPrivate; super; super = (UClass *) super->SuperStruct) {
		if (!s.empty())
			s += ".";
		s += super->GetName();
	}
	return s;
}
bool isObjectPlayer(UObject *Object) {
	if (!Tools::IsPtrValid(Object)) {
		return false;
	}
	for (auto super = Object->ClassPrivate; Tools::IsPtrValid(super); super = (UClass *) super->SuperStruct) {
		if (super == ASTExtraPlayerCharacter::StaticClass()) {
			return true;
		}
	}
	return false;
}
bool isObjectGrenade(UObject *Object) {
	if (!Tools::IsPtrValid(Object)) {
		return false;
	}
	for (auto super = Object->ClassPrivate; Tools::IsPtrValid(super); super = (UClass *) super->SuperStruct) {
		if (super == ASTExtraGrenadeBase::StaticClass()) {
			return true;
		}
	}
	return false;
}
bool isObjectVehicle(UObject *Object) {
	if (!Tools::IsPtrValid(Object)) {
		return false;
	}
	for (auto super = Object->ClassPrivate; Tools::IsPtrValid(super); super = (UClass *) super->SuperStruct) {
		if (super == ASTExtraVehicleBase::StaticClass()) {
			return true;
		}
	}
	return false;
}
bool isObjectLoot(UObject *Object) {
	if (!Tools::IsPtrValid(Object)) {
		return false;
	}
	for (auto super = Object->ClassPrivate; Tools::IsPtrValid(super); super = (UClass *) super->SuperStruct) {
		if (super == APickUpWrapperActor::StaticClass()) {
			return true;
		}
	}
	return false;
}
bool isObjectLootBox(UObject *Object) {
	if (!Tools::IsPtrValid(Object)) {
		return false;
	}
	for (auto super = Object->ClassPrivate; Tools::IsPtrValid(super); super = (UClass *) super->SuperStruct) {
		if (super == APickUpListWrapperActor::StaticClass()) {
			return true;
		}
	}
	return false;
}

FVector GetBoneLocation(ASTExtraPlayerCharacter *Actor, const char *BoneName) {
    return Actor->GetBonePos(BoneName, FVector());
}


FMatrix RotatorToMatrix(FRotator rotation) {
    float radPitch = rotation.Pitch * ((float) PI / 180.f);
    float radYaw = rotation.Yaw * ((float) PI / 180.f);
    float radRoll = rotation.Roll * ((float) PI / 180.f);

    float SP = sinf(radPitch);
    float CP = cosf(radPitch);
    float SY = sinf(radYaw);
    float CY = cosf(radYaw);
    float SR = sinf(radRoll);
    float CR = cosf(radRoll);

    FMatrix matrix;

    matrix.M[0][0] = (CP * CY);
    matrix.M[0][1] = (CP * SY);
    matrix.M[0][2] = (SP);
    matrix.M[0][3] = 0;

    matrix.M[1][0] = (SR * SP * CY - CR * SY);
    matrix.M[1][1] = (SR * SP * SY + CR * CY);
    matrix.M[1][2] = (-SR * CP);
    matrix.M[1][3] = 0;

    matrix.M[2][0] = (-(CR * SP * CY + SR * SY));
    matrix.M[2][1] = (CY * SR - CR * SP * SY);
    matrix.M[2][2] = (CR * CP);
    matrix.M[2][3] = 0;

    matrix.M[3][0] = 0;
    matrix.M[3][1] = 0;
    matrix.M[3][2] = 0;
    matrix.M[3][3] = 1;

    return matrix;
}


FVector WorldToScreen(FVector world) 
{
    if (!g_PlayerController->PlayerCameraManager)
        return {0, 0, 0};
    
    FMinimalViewInfo camViewInfo = g_PlayerController->PlayerCameraManager->CameraCache.POV;
    
    auto CameraLocation = camViewInfo.Location;
    auto CameraRotation = camViewInfo.Rotation;
    
    FMatrix tempMatrix = RotatorToMatrix(CameraRotation);

    FVector vAxisX(tempMatrix.M[0][0], tempMatrix.M[0][1], tempMatrix.M[0][2]);
    FVector vAxisY(tempMatrix.M[1][0], tempMatrix.M[1][1], tempMatrix.M[1][2]);
    FVector vAxisZ(tempMatrix.M[2][0], tempMatrix.M[2][1], tempMatrix.M[2][2]);

    FVector vDelta = world - CameraLocation;

    FVector vTransformed(vDelta.Dot(vAxisY), vDelta.Dot(vAxisZ), vDelta.Dot(vAxisX));

    auto FovAngle = camViewInfo.FOV;
    float screenCenterX = g_screenWidth / 2;
    float screenCenterY = g_screenHeight / 2;

    float X = (screenCenterX + vTransformed.X * (screenCenterX / tanf(FovAngle * ((float)PI / 360.0f))) / vTransformed.Z);
    float Y = (screenCenterY - vTransformed.Y * (screenCenterX / tanf(FovAngle * ((float)PI / 360.0f))) / vTransformed.Z);
    float Z = vTransformed.Z;
    
    return {X, Y, Z};
}



FVector2D WorldToScreen33(FVector worldLocation) {
    FMinimalViewInfo camViewInfo = g_PlayerController->PlayerCameraManager->CameraCache.POV;
    
    FMatrix tempMatrix = RotatorToMatrix(camViewInfo.Rotation);
    
    
FVector vAxisX(tempMatrix.M[0][0], tempMatrix.M[0][1], tempMatrix.M[0][2]);
    FVector vAxisY(tempMatrix.M[1][0], tempMatrix.M[1][1], tempMatrix.M[1][2]);
    FVector vAxisZ(tempMatrix.M[2][0], tempMatrix.M[2][1], tempMatrix.M[2][2]);

    FVector vDelta = worldLocation - camViewInfo.Location;
    
    FVector vTransformed(vDelta.Dot(vAxisY), vDelta.Dot(vAxisZ), vDelta.Dot(vAxisX));

    if (vTransformed.Z < 1.0f) {
        vTransformed.Z = 1.0f;
    }
    
    float fov = camViewInfo.FOV;
    float screenCenterX = g_screenWidth / 2;
    float screenCenterY = g_screenHeight / 2;
    
    return FVector2D(
                     (screenCenterX + vTransformed.X * (screenCenterX / tanf(fov * ((float) M_PI / 360.0f))) / vTransformed.Z),
                     (screenCenterY - vTransformed.Y * (screenCenterX / tanf(fov * ((float) M_PI / 360.0f))) / vTransformed.Z)
                     );
    
    
}



     //screenWidth screenHeight


FVector2D WorldToScreen360(FVector worldLocation, FMinimalViewInfo camViewInfo, int width, int height) {
    FMatrix tempMatrix = RotatorToMatrix(camViewInfo.Rotation);
    
    
FVector vAxisX(tempMatrix.M[0][0], tempMatrix.M[0][1], tempMatrix.M[0][2]);
    FVector vAxisY(tempMatrix.M[1][0], tempMatrix.M[1][1], tempMatrix.M[1][2]);
    FVector vAxisZ(tempMatrix.M[2][0], tempMatrix.M[2][1], tempMatrix.M[2][2]);

    FVector vDelta = worldLocation - camViewInfo.Location;
    
    FVector vTransformed(vDelta.Dot(vAxisY), vDelta.Dot(vAxisZ), vDelta.Dot(vAxisX));

    if (vTransformed.Z < 1.0f) {
        vTransformed.Z = 1.0f;
    }
    
    float fov = camViewInfo.FOV;
    float screenCenterX = g_screenWidth / 2;
    float screenCenterY = g_screenHeight / 2;
    
    return FVector2D(
                     (screenCenterX + vTransformed.X * (screenCenterX / tanf(fov * ((float) M_PI / 360.0f))) / vTransformed.Z),
                     (screenCenterY - vTransformed.Y * (screenCenterX / tanf(fov * ((float) M_PI / 360.0f))) / vTransformed.Z)
                     );
    
    
}


FRotator ToRotator(FVector local, FVector target) {
    FVector rotation;
    rotation.X = local.X - target.X;
    rotation.Y = local.Y - target.Y;
    rotation.Z = local.Z - target.Z;
 
    FRotator newViewAngle = {0};
 
    float hyp = sqrt(rotation.X * rotation.X + rotation.Y * rotation.Y);
 
    newViewAngle.Pitch = -atan(rotation.Z / hyp) * (180.f / (float) 3.14159265358979323846);
    newViewAngle.Yaw = atan(rotation.Y / rotation.X) * (180.f / (float) 3.14159265358979323846);
    newViewAngle.Roll = (float) 0.f;
 
    if (rotation.X >= 0.f)
        newViewAngle.Yaw += 180.0f;
 
    return newViewAngle;
}


namespace Stream  {
bool Switch{false};  
};

template <class T>
void GetAllActors(std::vector<T *> &Actors)
{
    UGameplayStatics *gGameplayStatics = (UGameplayStatics *)gGameplayStatics->StaticClass();
    auto GWorld = GetWorld();
    if (GWorld)
    {
        TArray<AActor *> Actors2;
        gGameplayStatics->GetAllActorsOfClass((UObject *)GWorld, T::StaticClass(), &Actors2);
        for (int i = 0; i < Actors2.Num(); i++)
        {
            Actors.push_back((T *)Actors2[i]);
        }
    }
}
void NekoHook(FRotator &angles) {
    if (angles.Pitch > 180)
        angles.Pitch -= 360;
    if (angles.Pitch < -180)
        angles.Pitch += 360;

    if (angles.Pitch < -75.f)
        angles.Pitch = -75.f;
    else if (angles.Pitch > 75.f)
        angles.Pitch = 75.f;

    while (angles.Yaw < -180.0f)
        angles.Yaw += 360.0f;
    while (angles.Yaw > 180.0f)
        angles.Yaw -= 360.0f;
}

void NekoHook(float *angles) {
    if (angles[0] > 180)
        angles[0] -= 360;
    if (angles[0] < -180)
        angles[0] += 360;

    if (angles[0] < -75.f)
        angles[0] = -75.f;
    else if (angles[0] > 75.f)
        angles[0] = 75.f;

    while (angles[1] < -180.0f)
        angles[1] += 360.0f;
    while (angles[1] > 180.0f)
        angles[1] -= 360.0f;
}


void NekoHook(Vector3 angles) {
    if (angles.X > 180)
        angles.X -= 360;
    if (angles.X < -180)
        angles.X += 360;

    if (angles.X < -75.f)
        angles.X = -75.f;
    else if (angles.X > 75.f)
        angles.X = 75.f;

    while (angles.Y < -180.0f)
        angles.Y += 360.0f;
    while (angles.Y > 180.0f)
        angles.Y -= 360.0f;
}

FVector GetBoneLocationByName(ASTExtraPlayerCharacter *Actor, const char *BoneName) {
	return Actor->GetBonePos(BoneName, FVector());
}
struct Threat_t {
	ASTExtraPlayerCharacter *m_Player;
	bool bAiming;
	bool bBehind;
	float mFOV;
	float mDIS;
};
std::vector<Threat_t> GetThreats() {
	std::vector<Threat_t> result;
	auto Actors = getActors();
	auto localPlayer = g_LocalPlayer;
	auto localController = g_PlayerController;
	if (localPlayer) {
		for (auto Actor : Actors) {
			if (isObjectInvalid(Actor))
				continue;
			if (Actor->IsA(ASTExtraPlayerCharacter::StaticClass())) {
				auto Player = (ASTExtraPlayerCharacter *)Actor;
				if (Player->PlayerKey == localPlayer->PlayerKey)
					continue;
				if (Player->TeamID == localPlayer->TeamID)
					continue;
				if (Player->bDead)
					continue;
				auto RootComponent = Player->RootComponent;
				if (RootComponent) {
					FRotator RelativeRotation = RootComponent->RelativeRotation;
					ClampAngles(RelativeRotation);
					FVector myHeadPosition = localPlayer->GetBonePos("Head", {});
					FVector headLocation = Player->GetBonePos("Head", {});
					auto Angle = UKismetMathLibrary::Conv_VectorToRotator(UKismetMathLibrary::Subtract_VectorVector(headLocation, myHeadPosition));
					ClampAngles(Angle);
					float num = abs(RelativeRotation.Pitch - Angle.Pitch);
					float num2 = abs(RelativeRotation.Yaw - Angle.Yaw);
					bool num3 = (num + num2) >= 60.f && (num + num2) <= 80.f;
					if (num + num2 >= 65.f) {
					//	if (localController->LineOfSightTo(Player, {0, 0, 0}, true)) {
							float dist = localPlayer->GetDistanceTo(Player);
							FVector2D HeadPosSC;
							result.push_back({Player, num3, NULL, num + num2, dist});
						}
					//}
				}
			}
		}
	}
	std::sort(result.begin(), result.end(),
	[](const Threat_t &a, const Threat_t &b) -> bool {
		return a.mDIS < b.mDIS;
	});
	return result;
}

// ================================================================================================================================ //
class FPSCounter {
	protected:
	unsigned int m_fps;
	unsigned int m_fpscount;
	long m_fpsinterval;
	public:
	FPSCounter() : m_fps(0), m_fpscount(0), m_fpsinterval(0) {
	}
	void update() {
		m_fpscount++;
		if (m_fpsinterval < time(0)) {
			m_fps = m_fpscount;
			m_fpscount = 0;
			m_fpsinterval = time(0) + 1;
		}
	}
	unsigned int get() const {
		return m_fps;
	}
}; FPSCounter fps;
bool isInsideFOV(int x, int y) {
	if (!Config["NRG_AIMBOT"])
		return true;
	int circle_x = g_screenWidth / 2;
	int circle_y = g_screenHeight / 2;
	int rad = Config["AIM_SIZE"];
	return (x - circle_x) * (x - circle_x) + (y - circle_y) * (y - circle_y) <= rad * rad;
}


bool isInsideFOV2(int x, int y) {
      if (!Config["NRG_AIMBOT"])
        return true;
    int circle_x = SizeXx / 2;
    int circle_y = SizeYy / 2;
    int rad = Config["AIM_SIZE"];
    return (x - circle_x) * (x - circle_x) + (y - circle_y) * (y - circle_y) <= rad * rad;
}
auto GetTargetForAimBot()
{
    ASTExtraPlayerCharacter *result = 0;
    float max = std::numeric_limits<float>::infinity();
    auto GWorld = GetWorld();
    if (GWorld)
    {
        ULevel *PersistentLevel = GWorld->PersistentLevel;
        if (PersistentLevel)
        {
            TArray<AActor *> Actors = *(TArray<AActor *> *)((uintptr_t)PersistentLevel + 0xA0);
            auto localPlayer = g_LocalPlayer;
            auto localController = g_PlayerController;
            if (localPlayer)
            {
                for (int i = 0; i < Actors.Num(); i++)
                {
                    auto Actor = Actors[i];
                    if (isObjectInvalid(Actor))
                        continue;

                    if (Actor->IsA(ASTExtraPlayerCharacter::StaticClass()))
                    {
                        auto Player = (ASTExtraPlayerCharacter *)Actor;

                        if (Player->PlayerKey == localPlayer->PlayerKey)
                            continue;

                        if (Player->TeamID == localPlayer->TeamID)
                            continue;

                            
      float Distance = localPlayer->GetDistanceTo(Player) / 100.0f;
                    if (Distance > Config["AIM_DISTANCE"])
                        continue;
                            
                        if (Player->bDead)
                            continue;

                            
if (Player->bHidden)
continue;
                     if (!Config["AIM_KNOCKED"]) {
                    if (Player->Health == 0.0f)
                        continue;
				}
                   if (Config["AIM_VISCHECK"]) {
                      //  if (!localController->LineOfSightTo(Actor, {0, 0, 0}, true)) {
                            if(!localController->LineOfSightTo(localController->PlayerCameraManager,Player->GetBonePos("Head", {}), true)) {
                            continue;
                            }
                       // }
                    }
  if (Config["AIM_IGNOREBOTS"]) {
                    if (Player->bEnsure)
                        continue;
				}
                        

                    //    auto Root = Player->GetBonePos("Root", {});
                        auto Head = Player->GetBonePos("Head", {});

                        FVector2D /*RootSc,*/ HeadSc;
                        if (/*W2S(Root, &RootSc) && */W2S(Head, &HeadSc))
                        {
                          //  float height = abs(HeadSc.Y - RootSc.Y);
                          //  float width = height * 0.65f;

                          //  FVector middlePoint = {HeadSc.X + (width / 2), HeadSc.Y + (height / 2), 0};
                         if ((HeadSc.X >= 0 && HeadSc.X <= SizeXx) && (HeadSc.Y >= 0 && HeadSc.Y <= SizeYy))
                            {
                                FVector2D v2Middle = FVector2D((float)(SizeXx / 2), (float)(SizeYy / 2));
                                FVector2D v2Loc = FVector2D(HeadSc.X, HeadSc.Y);
                                  if (isInsideFOV2((int) HeadSc.X, (int) HeadSc.Y)) {
                                float dist = FVector2D::Distance(v2Middle, v2Loc);
                                if (dist < max)
                                {
                                    max = dist;
                                    result = Player;
                                }
                                }
                            }
                        }
                    }
                }
            }
            return result;
        }
    }
}

ASTExtraPlayerCharacter *GetTargetByCrosshairDistance() {
	ASTExtraPlayerCharacter *result = 0;
	float max = std::numeric_limits<float>::infinity();
	auto localPlayer = g_LocalPlayer;
	auto localController = g_PlayerController;
	auto Actors = getActors();   

	if (localPlayer && localController) {
		for (int i = 0; i < Actors.size(); i++) {
			if (Actors[i] && isObjectPlayer(Actors[i])) {
				auto Actor = (ASTExtraPlayerCharacter *) Actors[i];
				if (Actor->PlayerKey == localPlayer->PlayerKey)
					continue;
				if (Actor->TeamID == localPlayer->TeamID)
					continue;
				if (Actor->bDead)
					continue;
                        if (Actor->bHidden)
                            continue;
                    float Distance = localPlayer->GetDistanceTo(Actor) / 100.0f;
                    if (Distance > Config["AIM_DISTANCE"])
                        continue;
                    
				for (int i = 0; i < Actors.size(); i++) {
					if (!isObjectInvalid(Actors[i]) && isObjectPlayer(Actors[i])) {
						auto Actor = (ASTExtraPlayerCharacter *) Actors[i];
						if (Actor->PlayerKey == localController->PlayerKey) {
							localPlayer = Actor;
							break;
						}
					}
				}
			        if (Config["AIM_VISCHECK"]) {
                        if (!localController->LineOfSightTo(Actor, {0, 0, 0}, true)) {
                            if(!localController->LineOfSightTo(localController->PlayerCameraManager,Actor->GetBonePos("Head", {}), true)) {
                            continue;
                            }
                        }
                    }
				if (!Config["AIM_KNOCKED"]) {
					if (Actor->Health == 0.0f)
						continue;
				}
				if (Config["AIM_IGNOREBOTS"]) {
					if (Actor->bEnsure)
						continue;
				}
		            auto Root = GetBoneLocation(Actor, "pelvis");
                auto Head = GetBoneLocation(Actor, "Head");
                auto PlayerCameraManager = localController->PlayerCameraManager;
                    CameraCache =PlayerCameraManager->CameraCache;
        
                
                
                FVector RootSc = WorldToScreen(Root);
                FVector HeadSc = WorldToScreen(Head);
               if (RootSc.Z > 0 && HeadSc.Z > 0) {
             
                 //   float height = abs(HeadSc.Y - RootSc.Y);
                  //  float width = height * 0.65f;
                    FVector middlePoint = {HeadSc.X, HeadSc.Y, 0};
                    if ((middlePoint.X >= 0 && middlePoint.X <= g_screenWidth) && (middlePoint.Y >= 0 && middlePoint.Y <= g_screenHeight)) {
                        FVector2D v2Middle = FVector2D((float) (g_screenWidth / 2), (float) (g_screenHeight / 2));
                        FVector2D v2Loc = FVector2D(middlePoint.X, middlePoint.Y);
                        if (isInsideFOV((int) middlePoint.X, (int) middlePoint.Y)) {
                            float dist = FVector2D::Distance(v2Middle, v2Loc);
                            if (dist < max) {
                                max = dist;
                                result = Actor;
							}
						}
					}
				}
			}
		}
	}
	return result;
}
ASTExtraPlayerCharacter *GetTargetByDistance() {
    ASTExtraPlayerCharacter *result = 0;
    float max = numeric_limits<float>::infinity();
    
    auto localPlayer = g_LocalPlayer;
    auto localController = g_PlayerController;
    
    FVector LocalPos{0, 0, 0}, ViewPos{0, 0, 0};
    if (localPlayer) {
        LocalPos = GetBoneLocationByName(localPlayer, "Root");
        ViewPos = GetBoneLocationByName(localPlayer, "Head");
        ViewPos.Z += 15.f;
    }
    
    auto GWorld = GetWorld();
    if (GWorld) {
        ULevel *PersistentLevel = GWorld->PersistentLevel;
        if (GWorld->PersistentLevel) {
            TArray<AActor *> Actors = *(TArray<AActor *> *)((uintptr_t)PersistentLevel + 0xA0);

            if (localPlayer && localController) {
                   for (int i = 0; i < Actors.Num(); i++) {
                if (Actors[i] && isObjectPlayer(Actors[i])) {
                    auto Actor = (ASTExtraPlayerCharacter *) Actors[i];
                    if (Actor->PlayerKey == localPlayer->PlayerKey)
                        continue;

                    if (Actor->TeamID == localPlayer->TeamID)
                        continue;

                    if (Actor->bDead)
                        continue;
                            if (Actor->bHidden)
                            continue;
                          float Distance = localPlayer->GetDistanceTo(Actor) / 100.0f;
                    if (Distance > Config["AIM_DISTANCE"])
                        continue;
                    
                       for (int i = 0; i < Actors.Num(); i++) {
                        if (!isObjectInvalid(Actors[i]) && isObjectPlayer(Actors[i])) {
                            auto Actor = (ASTExtraPlayerCharacter *) Actors[i];
                        if (Actor->PlayerKey == localController->PlayerKey) {
                             localPlayer = Actor;
                              break;
                             }
                          }
                       }            
        
                       
                       
                      if (Config["AIM_VISCHECK"]) {
                        if (!localController->LineOfSightTo(Actor, {0, 0, 0}, true)) {
                            if(!localController->LineOfSightTo(localController->PlayerCameraManager,Actor->GetBonePos("Head", {}), true)) {
                            continue;
                            }
                        }
                    }
                if (!Config["AIM_KNOCKED"]) {
                    if (Actor->Health == 0.0f)
                        continue;
                }
                if (Config["AIM_IGNOREBOTS"]) {
                    if (Actor->bEnsure)
                        continue;
				}
                        
float dist = g_LocalPlayer->GetDistanceTo(Actor);
                        if (dist < max) {
                            max = dist;
                            result = Actor;
                        }
                    }
                }
            }
        }
    }
    return result;
}


void
(*orig_shoot_event)(USTExtraShootWeaponComponent *thiz, FVector start, FRotator rot, void *unk1,
                    int unk2) = 0;

void shoot_event(USTExtraShootWeaponComponent *thiz, FVector start, FRotator rot,
                 ASTExtraShootWeapon *weapon, int unk1) {
                         if (Config["NRG_AIMBOT"]) {
                   if (Config["AIM_MOD2"] || Config["AIM_MOD3"]) {
          ASTExtraPlayerCharacter *Target = GetTargetByCrosshairDistance();
                            
                    if (Target)
                    {
                        bool triggerOk = false;
                       if (Config["AIM::TRIGGER1"]) {
                    triggerOk = g_LocalPlayer->bIsWeaponFiring;
                } else if (Config["AIM::TRIGGER2"]) {
                    triggerOk = g_LocalPlayer->bIsGunADS;
                } else if (Config["AIM::TRIGGER3"]) {
                    triggerOk = g_LocalPlayer->bIsWeaponFiring || g_LocalPlayer->bIsGunADS;
                
            } else triggerOk = true;
                        if (triggerOk)
                        {
                                        FVector targetAimPos = GetBoneLocation(Target, "Head");//Target->GetBonePos("Head", {});
                

                UShootWeaponEntity *ShootWeaponEntityComponent = thiz->ShootWeaponEntityComponent;

                
                if (ShootWeaponEntityComponent) {
                    ASTExtraVehicleBase *CurrentVehicle = Target->CurrentVehicle;
                    if (CurrentVehicle) {
                        FVector LinearVelocity = CurrentVehicle->ReplicatedMovement.LinearVelocity;

                        float dist = g_LocalPlayer->GetDistanceTo(Target);
                        auto timeToTravel = dist / ShootWeaponEntityComponent->BulletFireSpeed;

                        targetAimPos = UKismetMathLibrary::Add_VectorVector(targetAimPos, UKismetMathLibrary::Multiply_VectorFloat(LinearVelocity, timeToTravel));
                    } else {
                        FVector Velocity = Target->GetVelocity();

                        float dist = g_LocalPlayer->GetDistanceTo(Target);
                        auto timeToTravel = dist / ShootWeaponEntityComponent->BulletFireSpeed;

                        targetAimPos = UKismetMathLibrary::Add_VectorVector(targetAimPos, UKismetMathLibrary::Multiply_VectorFloat(Velocity, timeToTravel));
                    }
                     if (Config["AIM_MOD2"]) {
                    FVector fDir = UKismetMathLibrary::Subtract_VectorVector(targetAimPos, g_PlayerController->PlayerCameraManager->CameraCache.POV.Location);
                    rot = UKismetMathLibrary::Conv_VectorToRotator(fDir);
                    }
                    
                     if (Config["AIM_MOD3"]) {
                    FVector fDir = UKismetMathLibrary::Subtract_VectorVector(targetAimPos, start);
                   FRotator sex = UKismetMathLibrary::Conv_VectorToRotator(fDir);
                   rot = sex;
                    }
                }
            }
        }
    }
            
            }
    return orig_shoot_event(thiz, start, rot, weapon, unk1);
  //  return orig_shoot_event(thiz, start, sex, weapon, unk1);
}

std::string playerstatus(int GetEnemyState)
{    
     switch (GetEnemyState)
     {
        case 0:
            return "AFK";
            break;
        case 1032:
            return "TILT HEAD";
            break;
        case 268435464:
            return "PLAY EMOTION";
            break;
        case 1552:
            return "AIMING";
            break;
        case 8388616:
            return "PARACHUTE";
            break;
        case 131072:
            return "KNOCKED";
            break;
        case 33554440:
            return "PLANE";
            break;
        case 8205:
            return "SHOT";
            break;
        case 32:
            return "SIT";
            break;
        case 4194303:
            return "SWIMMING";
            break;
        case 72:
            return "JUMPING";
            break;
        case 8388608:
            return "PARACHUTE";
            break;
        case 16392:
            return "THROW SOMETHING";
            break;
        case 262:
            return "RELOADING";
            break;
        case 1048584:
            return "RIDE";
            break;
        case 8200:
            return "FIST";
            break;
        case 2056:
            return "CUT GUN";
            break;
        case 4194302:
            return "SWIMMING";
            break;
        case 269:
            return "RELOADING";
            break;
        case 16777224:
            return "CLIMBING";
            break;
        case 10:
            return "RUN";
            break;
        case 263:
            return "RELOADING";
            break;
        case 65568 || 65544:
            return "FIGHT MEDICINE";
            break;
        case 4194308:
            return "SWIMMING";
            break;
        case 268:
            return "RELOADING";
            break;
        case 35:
            return "GET SIT";
            break;
        case 8388617:
            return "PARACHUTE";
            break;
        case 33:
            return "AIMING";
            break;
        case 75:
            return "JUMPING";
            break;
        case 8201:
            return "FIST";
            break;
        case 266:
            return "RELOADING";
            break;
        case 32776:
            return "KNOCKED";
            break;
        case 270:
            return "RELOADING";
            break;
        case 4194301:
            return "SWIMMING";
            break;
        case 1033:
            return "RUN";
            break;
        case 131073:
            return "KNOCKED";
            break;
        case 524296:
            return "DRIVING";
            break;
        case 1114120:
            return "FIGHT MEDICINE";
            break;
        case 265:
            return "RELOADING";
            break;
        case 9:
            return "RUN";
            break;
        case 262144:
            return "SMOKE";
            break;
        case 8203:
            return "FIST";
            break;
        case 8202:
            return "SHOT";
            break;
        case 262152:
            return "DEATH";
            break;
        case 17416:
            return "THROW SOMETHING";
            break;
        case 17:
            return "SIT";
            break;
        case 11:
            return "RUN";
            break;
        case 65545:
            return "FIGHT MEDICINE";
            break;
        case 33554432:
            return "PLANE";
            break;
        case 19:
            return "SQUAT";
            break;
        case 8208:
            return "SHOT";
            break;
        case 520:
            return "AIMING";
            break;
        case 8206:
            return "SHOT";
            break;
        case 8:
            return "STAND";
            break;
        case 16:
            return "SIT";
            break;
        case 13180:
            return "KNOCKED";
            break;
        case 4194310:
            return "SWIMMING";
            break;
        case 16393:
            return "THROW SOMETHING";
            break;
        case 4194309:
            return "SWIMMING";
            break;
        case 264:
            return "RELOADING";
            break;
        case 4194305:
            return "SWIMMING";
            break;
        case 8207:
            return "SHOT";
            break;
        case 4194307:
            return "SWIMMING";
            break;
        return "";
    }
}

std::string playerstatusAim(int GetEnemyState)
{    
     switch (GetEnemyState)
     {
/*
            case 33:
            return "1 âš ï¸ ENEMY AIMING AT YOU! âš ï¸";
            break;
        */
           case 1552:
            return "2  âš ï¸ ENEMY AIMING AT YOU! âš ï¸";
            break;
            
            case 520:
            return "3   âš ï¸ ENEMY AIMING AT YOU! âš ï¸";
            break;
            
  
        return "";
    }
}

// ================================================================================================================================ //

unsigned long getModuleBase(char* module_name) {
    char* phgsr;
    char jjjj_N[64];
    long startaddr = 0;
    char path[256], line[1024];
    bool bssOF = false, LastIsSo = false;
    strcpy(jjjj_N, module_name);
    phgsr = strtok(jjjj_N, ":");
    module_name = phgsr;
    phgsr = strtok(nullptr, ":");
    if (phgsr) {
        if (strcmp(phgsr, "bss") == 0) {
            bssOF = true;
        }
    }
    sprintf(path, "/proc/%d/maps", getpid());
    FILE* p = fopen(path, "r");
    if (p) {
        while (fgets(line, sizeof(line), p)) {
            if (LastIsSo) {
                if (strstr(line, "[anon:.bss]") != NULL) {
                    sscanf(line, "%lx-%*lx", &startaddr);
                    break;
                } else {
                    LastIsSo = false;
                }
            }
            if (strstr(line, module_name) != nullptr) {
                if (!bssOF) {
                    sscanf(line, "%lx-%*lx", &startaddr);
                    break;
                } else {
                    LastIsSo = true;
                }
            }
        }
        fclose(p);
    }
    return startaddr;
}
// ============================================================================================================= //
/*
unsigned long getModuleBase(char *module_name)
{
char*phgsr;
char jjjj_N[64];
long startaddr = 0;
char path[256],line[1024];
bool bssOF = false,LastIsSo = false;
strcpy(jjjj_N,module_name);
phgsr = strtok(jjjj_N,":");
module_name = phgsr;
phgsr = strtok(NULL,":");
if(phgsr)
{
if(strcmp(phgsr,"bss")==0)
{
bssOF = true;
}
}
sprintf(path,"/proc/%d/maps",getpid());
FILE*p = fopen(path,"r");
if(p)
{
while(fgets(line,sizeof(line),p))
{
if(LastIsSo)
{
if(strstr(line,"[anon:.bss]")!=NULL)
{
sscanf(line,"%lx-%*lx",&startaddr);
break;
}
else
{
LastIsSo = false;
}
}
if(strstr(line,module_name)!=NULL)
{
if(!bssOF)
{
sscanf(line,"%lx-%*lx",&startaddr);
break;
}
else
{
LastIsSo = true;
}
}
}
fclose(p);
}
return startaddr;
}

//static Canvas *m_Canvas = 0;

// TODO : FPS DATA
uint64_t GetTickCount()
{
    using namespace std::chrono;
    return duration_cast < milliseconds > (steady_clock::now().time_since_epoch()).count();
}

class Interval
{
  private:
    int initial_;

  public:
      inline Interval():initial_(GetTickCount())
    {
    }
    virtual ~ Interval()
    {
    }
    inline unsigned int value() const
    {
        return GetTickCount() - initial_;
    }
};
class FPS
{
  protected:
    int32_t m_fps;
    int32_t m_fpscount;
    Interval m_fpsinterval;
  public:
      FPS():m_fps(0), m_fpscount(0)
    {
    }
    void Update()
    {
        m_fpscount++;
        if (m_fpsinterval.value() > 1000)
        {
            m_fps = m_fpscount;
            m_fpscount = 0;
            m_fpsinterval = Interval();
        }
    }

    int32_t get() const
    {
        return m_fps;
    }
};

FPS m_fps;

float BulletFireSpeed = 0;
*/

// ================================================================================================================================ //
class FPS {
   private:
    int32_t m_fps;
    int32_t m_count;
    std::chrono::steady_clock::time_point m_lastTick;

   public:
    FPS() : m_fps(0), m_count(0), m_lastTick(std::chrono::steady_clock::now()) {}

    inline void Update() {
        ++m_count;
        auto now = std::chrono::steady_clock::now();
        if (std::chrono::duration_cast<std::chrono::milliseconds>(now - m_lastTick).count() >= 1000) {
            m_fps = m_count;
            m_count = 0;
            m_lastTick = now;
        }
    }

    inline int32_t get() const { return m_fps; }
};
static FPS m_fps;
float BulletFireSpeed = 0;

FRotator aimproAIM (FVector targetAimPos){
    
    
}


void aim(FRotator rot){
    
    
    
    g_PlayerController->AController::SetControlRotation(rot, "");
    
    
}

bool bull = 0;
std::string GetPackageName() {
    FILE *f = fopen("/proc/self/cmdline", "rb");
    if (f) {
        char *buf = new char[64];
        fread(buf, sizeof(char), 64, f);
        fclose(f);
        return buf;
    }
    return 0;
}


#define ARGB(a, r, g, b) 0 | a << 24 | r << 16 | g << 8 | b
// ================================================================================================================================ //
void DrawESP(ESP esp, int screenWidth, int screenHeight) {	 

            
        g_screenWidth = screenWidth;
        g_screenHeight = screenHeight;
      //  if (!g_Token.empty() && !g_Auth.empty() && g_Token == g_Auth) {
      
        
     //   m_fps.Update();
        

    sprintf(extra, OBFUSCATE("BEAR-ENGINE"));
    esp.DrawText(Color::White(), extra, FVector2D(screenWidth / 2, 95), 45);
    /*
    
        char *tsr = OBFUSCATE(" FPS : ");
                std::string Str = std::string(tsr);
                Str += std::to_string((int)m_fps.get());
                
                esp.DrawText(Color(255, 255, 255), Str.c_str(), FVector2D(210, 80), 26);
				*/
    /*
    std::string GGGGG = std::to_string(Config["AIM::SPEED"]);
    
   //  sprintf(extra, "NRG-ENGINE");
    esp.DrawText(Color::White(), GGGGG.c_str(), FVector2D(screenWidth / 2, screenHeight / 2), 45);
    
*/


    
 if (!bScanPatternCompleted)
      return;
    


          auto GWorld = GetWorld();
    if (GWorld) {
        ULevel *PersistentLevel = GWorld->PersistentLevel;
        if (GWorld->PersistentLevel) {
           TArray<AActor *> Actors = *(TArray<AActor *> *)((uintptr_t)PersistentLevel + 0xA0);
            
            int totalEnemies = 0, totalBots = 0;
            auto localPlayer = g_LocalPlayer;
            auto localController = g_PlayerController;
        if (localController) {

if (Config["ESP_RADAR"]){
struct Vector3 Pos;
Pos.X = screenWidth / 5.5;//4.395
Pos.Y = screenHeight / 10;//40
    
struct Vector3 Size;
Size.X = Config["RADAR_SIZE"];
Size.Y = Config["RADAR_SIZE"];   
float RadarCenterX = Pos.X + (Size.X / 2);
float RadarCenterY = Pos.Y + (Size.Y / 2);
esp.DrawFilledRect(Color(0, 0, 0, 130),  {Pos.X, Pos.Y},  {Size.X, Size.Y});
esp.DrawLine2(Color::White(), 1.5, FVector2D{Pos.X, Pos.Y}, FVector2D{Pos.X + Size.X, Pos.Y});
esp.DrawLine2(Color::White(), 1.5, FVector2D{Pos.X, Pos.Y + Size.Y}, FVector2D{Pos.X + Size.X, Pos.Y + Size.Y});
esp.DrawLine2(Color::White(), 1.5, FVector2D{Pos.X, Pos.Y}, FVector2D{Pos.X, Pos.Y + Size.Y});
esp.DrawLine2(Color::White(), 1.5, FVector2D{Pos.X + Size.X, Pos.Y}, FVector2D{Pos.X + Size.X, Pos.Y + Size.Y});
esp.DrawLine2(Color::White(), 1.5, FVector2D{RadarCenterX, Pos.Y}, FVector2D{RadarCenterX, Pos.Y + Size.Y});
esp.DrawLine2(Color::White(), 1.5, FVector2D{Pos.X, RadarCenterY}, FVector2D{Pos.X + Size.X, RadarCenterY});
esp.DrawRect(Color(255, 255, 255), 1.5, {Pos.X, Pos.Y}, {Size.X, Size.Y});
esp.DrawCircle(Color(255,0,0), FVector2D{RadarCenterX, RadarCenterY}, 3.0f, 10);
//esp.DrawText(Color::Red(), "â€¢", FVector2D(RadarCenterX, RadarCenterY), 40);//20
}
            if (localPlayer) {
    
                     
                #if BEAR_HAS_AUTO_FEEDBACK
                    // === AUTO FEEDBACK (chicken dinner report) ===
                    // Scan the same actor list for GameState and trigger once when win condition is met.
                    if (Config["AUTO_FEEDBACK"]) {
                        for (int i = 0; i < Actors.Num(); i++) {
                            if (isObjectInvalid(Actors[i]))
                                continue;
                            if (Actors[i]->IsA(ASTExtraGameStateBase::StaticClass())) {
                                auto GameState = (ASTExtraGameStateBase *) Actors[i];
                                DrawFeedBack(esp, localPlayer, localController, GameState);
                                break;   // only need one GameState
                            }
                        }
                    }
                    // =============================================
                #endif
            
                            for (int i = 0; i < Actors.Num(); i++) {
                    if (isObjectPlayer(Actors[i])) {
                        auto Player = (ASTExtraPlayerCharacter *) Actors[i];
                        auto RootComponent = Player->RootComponent;
                        if (!RootComponent)
                            continue;
                        
       
                        
                        float Distance = localPlayer->GetDistanceTo(Player) / 100.0f;
                              if (Distance < 1000.f)
                        {
                                       
                        int Visible;
                        
                        
                        if (localPlayer) {
                            if (Player->PlayerKey == localPlayer->PlayerKey)
                                continue;

                            if (Player->TeamID == localPlayer->TeamID)
                                continue;
                        }
             
                         if (Player->bDead)
                            continue;
                            
                            
                            
if (Player->bHidden)
continue;

Color RADARColor;
Color NameColor;
if (Player->bEnsure){
    RADARColor = Color::Green();
    NameColor = Color::White();
               } else {
RADARColor = Color::Red();  
NameColor = Color::Yellow();
}

if (Config["ESP_RADAR"]){
    bool out = false;
          struct Vector3 Pos;
Pos.X = screenWidth / 5.5;//4.395
Pos.Y = screenHeight / 10;//40
    
struct Vector3 Size;
Size.X = Config["RADAR_SIZE"];
Size.Y = Config["RADAR_SIZE"];   
float RadarCenterX = Pos.X + (Size.X / 2);
float RadarCenterY = Pos.Y + (Size.Y / 2);
                FVector MyPosition, EnemyPosition;
                ASTExtraVehicleBase * CurrentVehiclea = Player->CurrentVehicle;
                if (CurrentVehiclea) {
                    MyPosition = CurrentVehiclea->RootComponent->RelativeLocation;
                } else {
                    MyPosition = Player->RootComponent->RelativeLocation;
                }
                ASTExtraVehicleBase * CurrentVehicle = localPlayer->CurrentVehicle;
                if (CurrentVehicle) {
                    EnemyPosition = CurrentVehicle->RootComponent->RelativeLocation;
                } else {
                    EnemyPosition = localPlayer->RootComponent->RelativeLocation;
                }
                FVector RadarSketch = WorldToRadar(localController->PlayerCameraManager->CameraCache.POV.Rotation.Yaw, MyPosition, EnemyPosition, Pos.X, Pos.Y, Vector3(Size.X, Size.Y, 0), out);
         
esp.DrawCircle(RADARColor, FVector2D{RadarSketch.X,RadarSketch.Y}, 3.0f, 10);
                          std::string s;
                          s += std::to_string((int) Distance);
                                                   
                            esp.DrawText(Color::White(), s.c_str(), FVector2D(RadarSketch.X,RadarSketch.Y + 3), 16);
    
                
            }
                            
                                  if (Config["ESP_IGNOREBOTS"])
                        {
                            if (Player->bEnsure)
                                continue;
                        }
                            
                            
                        
                        
                       
                            
                             if (Player->bEnsure)             
                    totalBots++;
                else totalEnemies++;        
                
                    Color LineColor;
                       if(!localController->LineOfSightTo(localController->PlayerCameraManager,Player->GetBonePos("Head", {}), true)) {
              
          LineColor = Color::White();
               } else {
         
         
         
              if (Player->bEnsure) {
                  LineColor = Color::White();
                        }else{
                    LineColor = Color::Green();  
                    }
          
            }
            
            
            
            
            
            Color clrHealth;
      if (Player->bEnsure) {
                   //   SCOLOR4 = WHITE;
                           // HPColormmm = GREEN2;
                            
                            clrHealth = Color(0, 255, 0, 190);
                        }else{
                       //  SCOLOR4 = YELLOW;
                        //  HPColormmm = RED;
                          clrHealth = Color(255, 0, 0, 190);
                    
                    }
                    

            
                      FVector Head = GetBoneLocation(Player, "Head");//Player->GetBonePos("Head", {});
                      FVector Root = GetBoneLocation(Player, "Root");//Player->GetBonePos("Root", {});
                        FVector RootPos = GetBoneLocation(Player, "Root");
                        FVector HeadPos2 = GetBoneLocation(Player, "Head");
                        HeadPos2.Z += 17.5f;//16.5f;
                        FVector RootPos2 = GetBoneLocation(Player, "Root");
                        RootPos2.Z -= 6.5f;//5.5f;
                    //targetAimPos.Z -= 25.f;

                      auto Head_RootZ = HeadPos2.Z - RootPos2.Z;
                        
                        
                        FVector uparmr = GetBoneLocation(Player, "upperarm_r");//GetBoneLocationByName
                        FVector uparml = GetBoneLocation(Player, "upperarm_l");
                        FVector lowarmr = GetBoneLocation(Player, "lowerarm_r");
                        FVector lowarml = GetBoneLocation(Player, "lowerarm_l");
                        FVector handr = GetBoneLocation(Player, "hand_r");
                        FVector handl = GetBoneLocation(Player, "hand_l");
                        FVector itemr = GetBoneLocation(Player, "item_r");
                        FVector iteml = GetBoneLocation(Player, "item_l");
                        
                        FVector clavicler = GetBoneLocation(Player, "clavicle_r");
                        FVector claviclel = GetBoneLocation(Player, "clavicle_l");
                        
                        FVector neck = GetBoneLocation(Player, "neck_01");
                        FVector spain01 = GetBoneLocation(Player, "spine_01");
                        FVector spain02 = GetBoneLocation(Player, "spine_02");
                        FVector spain03 = GetBoneLocation(Player, "spine_03");
                        FVector pelvis = GetBoneLocation(Player, "pelvis");
                        
                        FVector calfl = GetBoneLocation(Player, "calf_l");
                        FVector calfr = GetBoneLocation(Player, "calf_r");
                        FVector thighl = GetBoneLocation(Player, "thigh_l");
                        FVector thighr = GetBoneLocation(Player, "thigh_r");
                        
                        
                        
                        FVector footr = GetBoneLocation(Player, "foot_r");
                        FVector footl = GetBoneLocation(Player, "foot_l");
                        
                      FVector uparmrSC = WorldToScreen(uparmr);
                      FVector uparmlSC = WorldToScreen(uparml);
                      FVector lowarmrSC = WorldToScreen(lowarmr);
                      FVector lowarmlSC = WorldToScreen(lowarml);
                      FVector handrSC = WorldToScreen(handr);
                      FVector handlSC = WorldToScreen(handl);
                      FVector itemrSC = WorldToScreen(itemr);
                      FVector itemlSC = WorldToScreen(iteml);
                      
                      FVector claviclerSC = WorldToScreen(clavicler);
                      FVector claviclelSC = WorldToScreen(claviclel);
                      
                      FVector neckSC = WorldToScreen(neck);
                      FVector spain01SC = WorldToScreen(spain01);
                      FVector spain02SC = WorldToScreen(spain02);
                      FVector spain03SC = WorldToScreen(spain03);
                      FVector pelvisSC = WorldToScreen(pelvis);
                      
                      FVector calflSC = WorldToScreen(calfl);
                      FVector calfrSC = WorldToScreen(calfr);
                      FVector thighlSC = WorldToScreen(thighl);
                      FVector thighrSC = WorldToScreen(thighr);
                      
                      FVector footrSC = WorldToScreen(footr);
                      FVector footlSC = WorldToScreen(footl);
                      
                        
                      
                      FVector HeadSc = WorldToScreen(Head);
                     FVector RootSc = WorldToScreen(Root);
                        Vector2 screen(screenWidth, screenHeight);
                        Vector2 location(RootSc.X,HeadSc.Y);
                        float boxHeight = fabsf(RootSc.Y - HeadSc.Y);
                        float boxWidth = boxHeight * 0.68;
                        Rect2 Box(HeadSc.X - (boxWidth / 2), HeadSc.Y, boxWidth, boxHeight);
                        
                        FVector HeadNrg = GetBoneLocation(Player, "Head");
                     HeadNrg.Z += 35.f;
                    FVector2D HeadNrgSc;
                   auto PlayerCameraManager = localController->PlayerCameraManager;
                    CameraCache =PlayerCameraManager->CameraCache;
        
                    HeadNrgSc =  WorldToScreen360(HeadNrg, CameraCache.POV, screenWidth, screenHeight);
             
                    
                    
                    
                    auto isvis = localController->LineOfSightTo(localPlayer, Head, false);

                       if (HeadSc.Z > 0 && RootSc.Z > 0) {

                                  if (Config["ESP_LINE"]) {
                                      
                                      auto gunHead = Player->GetHeadLocation(true);
                                    gunHead.Z += 35.f;
                                    
                                    
                                
                               FVector GunHeadSc = WorldToScreen(gunHead);
                                auto mWidthScaleGun = std::min(0.006f * Distance, 100.f);
                                    auto mWidthGun = 20.f - mWidthScaleGun;
                                    auto mHeightGun = mWidthGun * 0.125f;
                                 //   GunHeadSc.X -= (mWidthGun / 2 - 20);
                                    GunHeadSc.Y -= (mHeightGun * 1.4f + 15);
                                
                                      
                              esp.DrawLine2(LineColor, 2, FVector2D(screenWidth / 2, 0), FVector2D(HeadSc.X , GunHeadSc.Y  - 16));//- 56
                              }
                        
                                    
if (Config["ESP_BONE"]) {

if (!localController->LineOfSightTo(localController->PlayerCameraManager,neck, true))
{
esp.DrawLine2(Color::Red(), 2.2f, FVector2D(HeadSc.X, HeadSc.Y), FVector2D(neckSC.X, neckSC.Y));
}else{
esp.DrawLine2(Color::Green(), 2.2f, FVector2D(HeadSc.X, HeadSc.Y), FVector2D(neckSC.X, neckSC.Y));
}

if (!localController->LineOfSightTo(localController->PlayerCameraManager,clavicler, true))
{
 esp.DrawLine2(Color::Red(), 2.2f, FVector2D(neckSC.X, neckSC.Y), FVector2D(claviclerSC.X, claviclerSC.Y));
}else{
esp.DrawLine2(Color::Green(), 2.2f, FVector2D(neckSC.X, neckSC.Y), FVector2D(claviclerSC.X, claviclerSC.Y));
}

if (!localController->LineOfSightTo(localController->PlayerCameraManager,uparmr, true))
{
  esp.DrawLine2(Color::Red(), 2.2f, FVector2D(claviclerSC.X, claviclerSC.Y), FVector2D(uparmrSC.X, uparmrSC.Y));
}else{
esp.DrawLine2(Color::Green(), 2.2f, FVector2D(claviclerSC.X, claviclerSC.Y), FVector2D(uparmrSC.X, uparmrSC.Y));
}

if (!localController->LineOfSightTo(localController->PlayerCameraManager,lowarmr, true))
{
   esp.DrawLine2(Color::Red(), 2.2f, FVector2D(uparmrSC.X, uparmrSC.Y), FVector2D(lowarmrSC.X, lowarmrSC.Y));
}else{
esp.DrawLine2(Color::Green(), 2.2f, FVector2D(uparmrSC.X, uparmrSC.Y), FVector2D(lowarmrSC.X, lowarmrSC.Y));
}

if (!localController->LineOfSightTo(localController->PlayerCameraManager,handr, true))
{
   esp.DrawLine2(Color::Red(), 2.2f, FVector2D(lowarmrSC.X, lowarmrSC.Y), FVector2D(handrSC.X, handrSC.Y));
}else{
    esp.DrawLine2(Color::Green(), 2.2f, FVector2D(lowarmrSC.X, lowarmrSC.Y), FVector2D(handrSC.X, handrSC.Y));

//esp.DrawLine2(Color::Green(), 2.2f, FVector2D(lowarmrSC.X, lowarmrSC.Y), FVector2D(handrSC.X, handrSC.Y));
}

if (!localController->LineOfSightTo(localController->PlayerCameraManager,itemr, true))
{
   esp.DrawLine2(Color::Red(), 2.2f, FVector2D(handrSC.X, handrSC.Y), FVector2D(itemrSC.X, itemrSC.Y));
}else{
esp.DrawLine2(Color::Green(), 2.2f, FVector2D(handrSC.X, handrSC.Y), FVector2D(itemrSC.X, itemrSC.Y));
} 


if (!localController->LineOfSightTo(localController->PlayerCameraManager,claviclel, true))
{
  esp.DrawLine2(Color::Red(), 2.2f, FVector2D(neckSC.X, neckSC.Y), FVector2D(claviclelSC.X, claviclelSC.Y));
}else{
esp.DrawLine2(Color::Green(), 2.2f, FVector2D(neckSC.X, neckSC.Y), FVector2D(claviclelSC.X, claviclelSC.Y));
}

if (!localController->LineOfSightTo(localController->PlayerCameraManager,uparml, true))
{
  esp.DrawLine2(Color::Red(), 2.2f, FVector2D(claviclelSC.X, claviclelSC.Y), FVector2D(uparmlSC.X, uparmlSC.Y));
}else{
esp.DrawLine2(Color::Green(), 2.2f, FVector2D(claviclelSC.X, claviclelSC.Y), FVector2D(uparmlSC.X, uparmlSC.Y));
}

if (!localController->LineOfSightTo(localController->PlayerCameraManager,lowarml, true))
{
  esp.DrawLine2(Color::Red(), 2.2f, FVector2D(uparmlSC.X, uparmlSC.Y), FVector2D(lowarmlSC.X, lowarmlSC.Y));
}else{
esp.DrawLine2(Color::Green(), 2.2f, FVector2D(uparmlSC.X, uparmlSC.Y), FVector2D(lowarmlSC.X, lowarmlSC.Y));
}

if (!localController->LineOfSightTo(localController->PlayerCameraManager,handl, true))
{
esp.DrawLine2(Color::Red(), 2.2f, FVector2D(lowarmlSC.X, lowarmlSC.Y), FVector2D(handlSC.X, handlSC.Y));
}else{
esp.DrawLine2(Color::Green(), 2.2f, FVector2D(lowarmlSC.X, lowarmlSC.Y), FVector2D(handlSC.X, handlSC.Y));
}

if (!localController->LineOfSightTo(localController->PlayerCameraManager,iteml, true))
{
 esp.DrawLine2(Color::Red(), 2.2f, FVector2D(handlSC.X, handlSC.Y), FVector2D(itemlSC.X, itemlSC.Y));
}else{
esp.DrawLine2(Color::Green(), 2.2f, FVector2D(handlSC.X, handlSC.Y), FVector2D(itemlSC.X, itemlSC.Y));
}

if (!localController->LineOfSightTo(localController->PlayerCameraManager,spain03, true))
{
esp.DrawLine2(Color::Red(), 2.2f, FVector2D(neckSC.X, neckSC.Y), FVector2D(spain03SC.X, spain03SC.Y));
}else{
esp.DrawLine2(Color::Green(), 2.2f, FVector2D(neckSC.X, neckSC.Y), FVector2D(spain03SC.X, spain03SC.Y));
}

if (!localController->LineOfSightTo(localController->PlayerCameraManager,spain02, true))
{
esp.DrawLine2(Color::Red(), 2.2f, FVector2D(spain03SC.X, spain03SC.Y), FVector2D(spain02SC.X, spain02SC.Y));
}else{
esp.DrawLine2(Color::Green(), 2.2f, FVector2D(spain03SC.X, spain03SC.Y), FVector2D(spain02SC.X, spain02SC.Y));
}

if (!localController->LineOfSightTo(localController->PlayerCameraManager,spain01, true))
{
esp.DrawLine2(Color::Red(), 2.2f, FVector2D(spain02SC.X, spain02SC.Y), FVector2D(spain01SC.X, spain01SC.Y));
}else{
esp.DrawLine2(Color::Green(), 2.2f, FVector2D(spain02SC.X, spain02SC.Y), FVector2D(spain01SC.X, spain01SC.Y));
}

if (!localController->LineOfSightTo(localController->PlayerCameraManager,pelvis, true))
{
esp.DrawLine2(Color::Red(), 2.2f, FVector2D(spain01SC.X, spain01SC.Y), FVector2D(pelvisSC.X, pelvisSC.Y));
}else{
esp.DrawLine2(Color::Green(), 2.2f, FVector2D(spain01SC.X, spain01SC.Y), FVector2D(pelvisSC.X, pelvisSC.Y));
}

if (!localController->LineOfSightTo(localController->PlayerCameraManager,thighr, true))
{
esp.DrawLine2(Color::Red(), 2.2f, FVector2D(pelvisSC.X, pelvisSC.Y), FVector2D(thighrSC.X, thighrSC.Y));
}else{
esp.DrawLine2(Color::Green(), 2.2f, FVector2D(pelvisSC.X, pelvisSC.Y), FVector2D(thighrSC.X, thighrSC.Y));
}

if (!localController->LineOfSightTo(localController->PlayerCameraManager,calfr, true))
{
esp.DrawLine2(Color::Red(), 2.2f, FVector2D(thighrSC.X, thighrSC.Y), FVector2D(calfrSC.X, calfrSC.Y));
}else{
esp.DrawLine2(Color::Green(), 2.2f, FVector2D(thighrSC.X, thighrSC.Y), FVector2D(calfrSC.X, calfrSC.Y));
}
if (!localController->LineOfSightTo(localController->PlayerCameraManager,footr, true))
{
esp.DrawLine2(Color::Red(), 2.2f, FVector2D(calfrSC.X, calfrSC.Y), FVector2D(footrSC.X, footrSC.Y));
}else{
esp.DrawLine2(Color::Green(), 2.2f, FVector2D(calfrSC.X, calfrSC.Y), FVector2D(footrSC.X, footrSC.Y));
}

if (!localController->LineOfSightTo(localController->PlayerCameraManager,thighl, true))
{
esp.DrawLine2(Color::Red(), 2.2f, FVector2D(pelvisSC.X, pelvisSC.Y), FVector2D(thighlSC.X, thighlSC.Y));
}else{
esp.DrawLine2(Color::Green(), 2.2f, FVector2D(pelvisSC.X, pelvisSC.Y), FVector2D(thighlSC.X, thighlSC.Y));
}

if (!localController->LineOfSightTo(localController->PlayerCameraManager,calfl, true))
{
esp.DrawLine2(Color::Red(), 2.2f, FVector2D(thighlSC.X, thighlSC.Y), FVector2D(calflSC.X, calflSC.Y));
}else{
esp.DrawLine2(Color::Green(), 2.2f, FVector2D(thighlSC.X, thighlSC.Y), FVector2D(calflSC.X, calflSC.Y));
}
if (!localController->LineOfSightTo(localController->PlayerCameraManager,footl, true))
{
esp.DrawLine2(Color::Red(), 2.2f, FVector2D(calflSC.X, calflSC.Y), FVector2D(footlSC.X, footlSC.Y));
}else{
esp.DrawLine2(Color::Green(), 2.2f, FVector2D(calflSC.X, calflSC.Y), FVector2D(footlSC.X, footlSC.Y));
}
}
                              
     
                  
                                   if (Config["ESP_INFO"]) {
                                int CurHP = (int) std::max(0, std::min((int) Player->Health, (int) Player->HealthMax));
                                int MaxHP = (int) Player->HealthMax;

                           //     long curHP_Color = ARGB(155, std::min(((510 * (MaxHP - CurHP)) / MaxHP), 255), std::min(((510 * CurHP) / MaxHP), 255), 0);
                               
                                if (Player->Health == 0.0f && !Player->bDead) {
                              //     curHP_Color = ARGB(255, 255, 0, 0);

                                   clrHealth = Color(255, 255, 0, 190);

                                    CurHP = Player->NearDeathBreath;
                                    if (Player->NearDeatchComponent) {
                                        MaxHP = Player->NearDeatchComponent->BreathMax;
                                    }
                                }
                             
                                    
                                    auto mWidthScale = std::min(0.0f * 24.0f, 0.0f); //100  75 50 | 24
 
                                    auto mWidth2 = 10.0f - mWidthScale;
                                    auto mWidth3 = 20.0f - mWidthScale;
                                    auto mWidth4 = 30.0f - mWidthScale;
                                    auto mWidth5 = 40.0f - mWidthScale;
                                    auto mWidth = 50.0f - mWidthScale;
                                    auto mWidth99 = 5.0f - mWidthScale;
                                    

                                    auto mHeight = mWidth * 0.078f;
                                    auto mHeightgg = mWidth * - 0.0f;//098f //0.07f
                                    HeadSc.X -= (mWidth / 2);
                                  HeadSc.Y -= (mHeight * 1.5f);
        
                                  auto HpHead = Player->GetHeadLocation(true);
                                    HpHead.Z += 35.f;
                                      
                                
                               FVector HpHeadSc = WorldToScreen(HpHead);
                                auto mWidthScaleGun = std::min(0.006f * Distance, 100.f);
                                    auto mWidthGun = 20.f - mWidthScaleGun;
                                    auto mHeightGun = mWidthGun * 0.125f;
                                    HpHeadSc.X -= (mWidthGun / 2/* - 20*/);
                                    HpHeadSc.Y -= (mHeightGun * 1.4f + 8);//10

                                  
                                    esp.DrawFilledRect(clrHealth,  FVector2D(HeadSc.X, HpHeadSc.Y),  FVector2D(CurHP * mWidth / MaxHP, mHeight));
                           
                                    esp.DrawRect(Color(0, 0, 0), 1.5,FVector2D(HeadSc.X, HpHeadSc.Y),FVector2D(mWidth2, mHeight));
                                    esp.DrawRect(Color(0, 0, 0), 1.5,FVector2D(HeadSc.X, HpHeadSc.Y),FVector2D(mWidth3, mHeight));
                                    esp.DrawRect(Color(0, 0, 0), 1.5,FVector2D(HeadSc.X, HpHeadSc.Y),FVector2D(mWidth4, mHeight));
                                    esp.DrawRect(Color(0, 0, 0), 1.5,FVector2D(HeadSc.X, HpHeadSc.Y),FVector2D(mWidth5, mHeight));
                                    esp.DrawRect(Color(0, 0, 0), 1.5,FVector2D(HeadSc.X, HpHeadSc.Y),FVector2D(mWidth, mHeight));
       
                            }
                            
          
 
          
 
            
                if (Config["ESP_INFO"]) {
                                                               
                                       std::string s;
                                                            s += std::to_string((int) Distance);
                                                          s += "M";
                                                        
                            esp.DrawText(Color::White(), s.c_str(), FVector2D(RootSc.X, RootSc.Y + 15), 14);
    
 
                  }
               
                            if (Config["ESP_INFO"] || Config["ESP_WEAPON"]) {
                                  auto gunHead = Player->GetHeadLocation(true);
                                    gunHead.Z += 35.f;
                                    
                                    auto nameHead = Player->GetHeadLocation(true);
                                    nameHead.Z += 35.f;
                                    
                                FVector NameHeadSc = WorldToScreen(nameHead);
                               FVector GunHeadSc = WorldToScreen(gunHead);
                                auto mWidthScaleGun = std::min(0.006f * Distance, 100.f);
                                    auto mWidthGun = 20.f - mWidthScaleGun;
                                    auto mHeightGun = mWidthGun * 0.125f;
                                    GunHeadSc.X -= (mWidthGun / 2 - 20);
                                    GunHeadSc.Y -= (mHeightGun * 1.4f + 15);
                                
                                
                                    
                                    auto mWidthScaleName = std::min(0.006f * Distance, 100.f);
                                    auto mWidthName = 20.f - mWidthScaleName;
                                    auto mHeightName = mWidthName * 0.125f;
                                //    AboveHeadSc.X -= (mWidth / 2 - 20);
                                    NameHeadSc.Y -= (mHeightName * 1.4f + 15);
                                    
                                       std::string ws;
                                       std::string ws2; 
                                            auto WeaponManagerComponent = Player->WeaponManagerComponent;
                if (WeaponManagerComponent) {
                {
                    auto CurrentWeaponReplicated = (ASTExtraShootWeapon *) WeaponManagerComponent->CurrentWeaponReplicated;
                if (CurrentWeaponReplicated) {
                    auto Maxbullet = CurrentWeaponReplicated->CurMaxBulletNumInOneClip;
                    auto CurNum = CurrentWeaponReplicated->CurBulletInClip.CurBulletNumInClip;
                    auto Weapond = CurrentWeaponReplicated -> WeaponEntityComp -> WeaponId;                       
                    auto CurrentWeaponReplicated = (ASTExtraShootWeapon *)WeaponManagerComponent->CurrentWeaponReplicated;
                if (CurrentWeaponReplicated) {
                    auto WeaponId = (int)CurrentWeaponReplicated->GetWeaponID();
                    if (WeaponId) {
                        ws2 += "(";
                        ws2 += CurrentWeaponReplicated->GetWeaponName().ToString();
                        ws2 += ")";
                        
                        
                                }
                            }
                        }
                    }
                }

                                            auto playername = Player->PlayerName;
                                            if (Player->bEnsure) {
                                        
                                             ws += std::to_string(Player->TeamID);
                                ws += " ";
                                ws += "Bot";
                                           } else if (playername.IsValid()){
                                                ws += std::to_string(Player->TeamID);
                                ws += " ";
                                                ws += playername.ToString();
                                       
                                       }
                                       
                                       
                                  
                           if (Config["ESP_WEAPON"]) {
                       esp.DrawText(Color::White(), ws2.c_str(), FVector2D(GunHeadSc.X - 11.2, GunHeadSc.Y - 19.5), 14.8f);
                       }
                       
                 if (Config["ESP_INFO"]) {
                       esp.DrawText(NameColor, ws.c_str(), FVector2D(NameHeadSc.X, NameHeadSc.Y - 2.7), 15.8);//17
             }
             
    
                       }

                        }
                        
                        
             
            
            if (Config["ESP_ALERT"]) {
                             
                bool shit = false;
                FVector MyPosition, EnemyPosition;
                ASTExtraVehicleBase * CurrentVehiclea = Player->CurrentVehicle;
                if (CurrentVehiclea) {
                    MyPosition = CurrentVehiclea->RootComponent->RelativeLocation;
                } else {
                    MyPosition = Player->RootComponent->RelativeLocation;
                }
                ASTExtraVehicleBase * CurrentVehicle = localPlayer->CurrentVehicle;
                if (CurrentVehicle) {
                    EnemyPosition = CurrentVehicle->RootComponent->RelativeLocation;
                } else {
                    EnemyPosition = localPlayer->RootComponent->RelativeLocation;
                }
                FVector EntityPos = WorldToRadar(localController->PlayerCameraManager->CameraCache.POV.Rotation.Yaw, MyPosition, EnemyPosition, NULL, NULL, Vector3(screenWidth, screenHeight, 0), shit);
                FVector angle = FVector();
                Vector3 forward = Vector3((float)(screenWidth / 2) - EntityPos.X, (float)(screenHeight / 2) - EntityPos.Y, 0.0f);
                VectorAnglesRadar(forward, angle);
                            
                const auto angle_yaw_rad = DEG2RAD(angle.Y + 180.f + 360.f);
                const auto new_point_x = (screenWidth / 2) + (55) / 2 * 13 * cosf(angle_yaw_rad);
                const auto new_point_y = (screenHeight / 2) + (55) / 2 * 13 * sinf(angle_yaw_rad);
                std::array<Vector3, 3> points { Vector3(new_point_x - ((120) / 4 + 18.0f) / 2, new_point_y - ((44) / 4 + 18.0f) / 2, 0.f), Vector3(new_point_x + ((120) / 4 + 18.0f) / 4, new_point_y, 0.f), Vector3(new_point_x - ((120) / 4 + 18.0f) / 2, new_point_y + ((44) / 4 + 18.0f) / 2, 0.f)};
                RotateTriangle(points, angle.Y + 180.f);
                Point a2{points[0].X, points[0].Y};
                Point b2{points[1].X, points[1].Y};
                Point c2{points[2].X, points[2].Y};
                        
               // m_Canvas->drawFilledTriangle(a2, b2, c2, SCOLOR2);
esp.DrawText(Color::Red(), "ðŸ”´", FVector2D(points[0].X, points[0].Y), 15);
    
            }
       
                     }
                     
                     
                     
                     
                    }
        
         
                        if (isObjectInvalid(Actors[i]))
                                continue;
                if (Config["ESP_WARNING"]) {
                                      if (isObjectGrenade(Actors[i])) {
               ASTExtraGrenadeBase *Grenade = (ASTExtraGrenadeBase *) Actors[i];
                                std::string n = getObjectPath(Grenade);
                                auto RootComponent = Actors[i]->RootComponent;
                                if (!RootComponent)
                                    continue;
                                float Distance = Grenade->GetDistanceTo(localPlayer) / 100.f;
                                FVector2D grenadePos;
FVector Location = WorldToScreen(RootComponent->RelativeLocation);
                if (Distance <= 100.f) {
                    
if (Location.Z > 0) {
                                    std::string s;
                          
                                      if(n=="BP_Grenade_Burn_C.BP_Grenade_Base_C.STExtraGrenadeBase.UAEProjectile.LuaActor.Actor.Object" || n=="BP_Grenade_Shoulei_C.BP_Grenade_Base_C.STExtraGrenadeBase.UAEProjectile.LuaActor.Actor.Object"){
                                        
                            esp.DrawText(Color::Red(), "âš ï¸ WARNING âš ï¸", FVector2D(screenWidth / 2, 195), 28);
                                    }
                                    if(n=="BP_Grenade_Burn_C.BP_Grenade_Base_C.STExtraGrenadeBase.UAEProjectile.LuaActor.Actor.Object"){
                                        
                                        s+="Molotov";
                                           s += " - [";
                                    s += std::to_string((int) Distance);
                                    s += "M]";
                                    } else if(n=="BP_Grenade_Shoulei_C.BP_Grenade_Base_C.STExtraGrenadeBase.UAEProjectile.LuaActor.Actor.Object"){
                 
                                        s+="Grenade";
                                           s += " - [";
                                    s += std::to_string((int) Distance);
                                    s += "M]";
                                    }
                        
                    esp.DrawText(Color::Red(), s.c_str(), FVector2D(Location.X, Location.Y), 15);
    
                    
                                               
                                                }  
                                                  
                                }
                            }
                        }
        
        
                        
                        
                          
                        
                        
                     if (Config["ESP::VEHICLE"]) {
            if (isObjectVehicle(Actors[i])) {
                ASTExtraVehicleBase *Vehicle = (ASTExtraVehicleBase *) Actors[i];
                auto RootComponent = Vehicle->RootComponent;
                if (!RootComponent)
                    continue;

                    float vDistance = Vehicle->GetDistanceTo(localPlayer) / 100.f;
                if (vDistance < 700.f) {
                    FVector Location = WorldToScreen(RootComponent->RelativeLocation);
                if (Location.Z > 0) {
                    std::string s = GetVehicleName(Vehicle);                                
                    s += " - ";
                    s += std::to_string((int) vDistance);
                    s += "M";
                 //   auto mText = m_Canvas->getTextBounds(s.c_str(), 0, s.size());
                    esp.DrawText(Color(255,50,255,255), s.c_str(), FVector2D(Location.X, Location.Y + 10), 15);

                    }
                }
            }
        }  
                    
                                    if (isObjectLoot(Actors[i])) {
                    APickUpWrapperActor *PickUp = (APickUpWrapperActor *) Actors[i];
                        if (Tools::IsPtrValid(PickUp)) {
                            if (itemConfig[PickUp->DefineID.TypeSpecificID]) {

                                auto RootComponent = PickUp->RootComponent;
                                if (!RootComponent)
                                    continue;

                                    float Distance = PickUp->GetDistanceTo(localPlayer) / 100.f;             
                             
                                    std::string s;
                                    int tc = 0xFF000000, oc = 0xFFFFFFFF;

                                    for (auto &e : itemData) {
                                        if (e["itemId"] == PickUp->DefineID.TypeSpecificID) {
                                             s = "[ ";
                                            s += e["itemName"].get<std::string>();
                                            tc = strtoul(e["itemTextColor"].get<std::string>().c_str(), 0, 16);
                                            oc = strtoul(e["itemOutlineColor"].get<std::string>().c_str(), 0, 16);
                                            break;
                                        }
                                    }

                                    s += " ";
                                    s += std::to_string((int) Distance);
                                    s += "M ]";

                                    FVector Location = WorldToScreen(RootComponent->RelativeLocation);
                                    if (Location.Z > 0) {
                                        //   if (!Config["FIGHT_MODE"]) {
                                            esp.DrawText(Color(255,255,255,255), s.c_str(), FVector2D(Location.X, Location.Y), 16);
    
                                     //   m_Canvas->drawText(s.c_str(), Location.X, Location.Y, 16.5f, Align::CENTER, tc, oc);
                                }
                            }
                        }
                    }
                        if (Config["ESP::LOOTBOX"]) {
            if (isObjectLootBox(Actors[i])) {
                APickUpListWrapperActor *PickUpList = (APickUpListWrapperActor *) Actors[i];
                auto PickUpDataList = (TArray<FPickUpItemData>) PickUpList->GetDataList();
                auto RootComponent = PickUpList->RootComponent;
            if (!RootComponent)
                continue;

            float Distance = PickUpList->GetDistanceTo(localPlayer) / 100.f;    
            if (Distance <= 50.f) {
                std::string s = GetLootName(PickUpList);        
                s += " [";
                s += std::to_string((int) Distance);
                s += "m]";

            FVector Location = WorldToScreen(RootComponent->RelativeLocation);
            if (Location.Z > 0) {
               // m_Canvas->drawText(s.c_str(), Location.X, Location.Y, 14.0f,Align::LEFT, WHITE, BLACK);
                esp.DrawText(Color(255,255,255,255), s.c_str(), FVector2D(Location.X, Location.Y), 14);
    
                if (Config["ESP::LOOT_BOX_ITEMS"]) {
                    if (Distance <= 15.f) {
                   //     Rect *m_Rect = m_Canvas->getTextBounds(s.c_str(), 0,
                                                                            //   s.size());
                    //    float posY = Location.Y - (m_Rect->getHeight() * 1.5f);
                        for (int j = 0; j < PickUpDataList.Num(); j++) {
                        std::vector<std::string> s2;
                        long tc = 0xFF000000, oc = 0xFFFFFFFF;

                   
                        for (auto &e : items_data) {
                            if (e["itemId"] ==
                                PickUpDataList[j].ID.TypeSpecificID) {
                                s2.push_back(e["itemName"].get<std::string>());
                                tc = strtoul(
                                        e["itemTextColor"].get<std::string>().c_str(),
                                                            0, 16);
                                oc = strtoul(
                                        e["itemOutlineColor"].get<std::string>().c_str(),
                                                            0, 16);
                                        break;
                                }
                        }
                        if (!s2.empty()) {
                            if (PickUpDataList[j].Count > 1) {s2.push_back(" * ");
                            s2.push_back(std::to_string(PickUpDataList[j].Count));
                            
                            }
                            
                            std::string s3;
                            for (auto &s4 : s2) {
                                s3 += s4;
                            }

                       //     m_Canvas->drawText(s2, Location.X, posY, 14.5f,Align::LEFT, {tc, WHITE, LIME},{oc, BLACK, BLACK});
                           esp.DrawText(Color(255,255,255,255), s.c_str(), FVector2D(Location.X, Location.Y), 14);

                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                }///
                
             
               
         }
            
           if (totalEnemies > 0) {
                                
     sprintf(extra, OBFUSCATE("[ALERT] %d Enemies in Area"), totalEnemies);
//sprintf(extra, "[ALERT] %d Enemies in Area", totalEnemies);
    esp.DrawText(Color::Red(), extra, FVector2D(screenWidth / 2, 155), 40);
    
                }

        }
              
               if (Config["NRG_AIMBOT"]) {
                     // float FOVSIZE = Config["AIM::SIZE"];
                      
                      esp.DrawCircle(Color(255,0,0), FVector2D(screenWidth / 2, screenHeight / 2), Config["AIM_SIZE"], 2);
                             }
        
        
                    
        }}
        
        
    //}
    }
    
//===================================================================================//

#define TSL_FONT_DEFAULT_SIZE 20
static UFont *tslFont = 0, *robotoTinyFont = 0;

int PhoenixCHEAT()
{
    return 0;
}


void *LoadFont(void *)
{
    while (!tslFont || !robotoTinyFont)
    {
        tslFont = UObject::FindObject<UFont>("Font Roboto.Roboto"); // Font Roboto.Roboto
        robotoTinyFont = UObject::FindObject<UFont>("Font RobotoDistanceField.RobotoDistanceField");
        sleep(1);
    }
    return 0;
}


//===================================================================================//

std::chrono::steady_clock::time_point lastWeaponChangeTimei;
std::chrono::steady_clock::time_point lastWeaponChangeTime;
static int LastGunUsedToKillSkin = 0;
static std::set<uint64_t> ChangedDeadBoxTargets;

static constexpr int kKillMessageVTableIndex = 1002;

struct SkinWeaponAvatar {
    int GUN;
    int flash;
    int compe;
    int silent;
    int quickMag;
    int extendedMag;
    int quickNextended;
    int holo;
    int x2;
    int x3;
    int x4;
    int x6;
    int angle;
    int thumb;
    int stock;
};

// -----------------------------------------------------------------------------
// Helper: many weapon skin variants in the game share the same "base" ID
// with an offset (base*10 + 1..9). This detects both the base and the variants.
// Used by GetWeap() to map a runtime weapon ID to the chosen skin stored
// in the registry-populated new_Skin struct.
// -----------------------------------------------------------------------------
static inline bool IsSkinWeaponVariant(int value, int base)
{
    if (value == base) return true;
    int stem = base * 10;
    return value >= stem + 1 && value <= stem + 9;
}

// -----------------------------------------------------------------------------
// Skin consumption / application layer (NRG.h)
// -----------------------------------------------------------------------------
// Population of new_Skin.* fields is now fully driven by the registry system
// in UpdateSkinManager.cpp (skinRegistry[] + ApplyAllRegisteredSkins() +
// per-weapon ApplyXXXFromDescriptors + SkinTableChoice data).
//
// This side (NRG.h) is the *consumer*:
// - GetWeap() maps game weapon IDs to the chosen skin ID stored in new_Skin.
// - ApplyFullWeaponSkin() + GetFullWeapon() + ApplyWeaponAttachmentSkin()
//   use the chosen skin ID + the static skin_tables::XXX lists to override
//   attachment IDs on the weapon's synData.
// - Similar for backpack/helmet/avatar/deadbox/etc.
//
// The registry (UpdateSkinManager) decides *which* skin is active based on
// Config["SKIN_*"] values. The code here just applies whatever is in new_Skin.
// -----------------------------------------------------------------------------

static inline int GetWeap(int weaponId)
{
    // Skin values in new_Skin are populated centrally via the registry system
    // in UpdateSkinManager (ApplyAllRegisteredSkins + skinRegistry[] + per-family
    // ApplyXXXFromDescriptors / SkinTableChoice descriptors).
    // See UpdateSkinManager.cpp (and the "Skin consumption / application layer" header
    // earlier in this file) for the full population story. This function is pure lookup.
    if (IsSkinWeaponVariant(weaponId, 101001)) return new_Skin.AKM;   // populated via registry (ApplyAllRegisteredSkins)
    if (IsSkinWeaponVariant(weaponId, 101002)) return new_Skin.M16A4; // populated via registry (ApplyAllRegisteredSkins)
    if (IsSkinWeaponVariant(weaponId, 101003)) return new_Skin.Scar;   // populated via registry (ApplyAllRegisteredSkins)
    if (IsSkinWeaponVariant(weaponId, 101004)) return new_Skin.M416_1; // populated via registry (ApplyAllRegisteredSkins)
    if (IsSkinWeaponVariant(weaponId, 101005)) return new_Skin.Groza;  // populated via registry (ApplyAllRegisteredSkins)
    if (IsSkinWeaponVariant(weaponId, 101006)) return new_Skin.AUG;    // populated via registry (ApplyAllRegisteredSkins)
    if (IsSkinWeaponVariant(weaponId, 101007)) return new_Skin.QBZ;    // populated via registry (ApplyAllRegisteredSkins)
    if (IsSkinWeaponVariant(weaponId, 101008)) return new_Skin.M762;   // populated via registry (ApplyAllRegisteredSkins)
    if (IsSkinWeaponVariant(weaponId, 101012)) return new_Skin.Honey;  // populated via registry (ApplyAllRegisteredSkins)
    if (IsSkinWeaponVariant(weaponId, 101102)) return new_Skin.ACE32;  // populated via registry (ApplyAllRegisteredSkins)
    if (IsSkinWeaponVariant(weaponId, 102001)) return new_Skin.UZI;    // populated via registry (ApplyAllRegisteredSkins)
    if (IsSkinWeaponVariant(weaponId, 102002)) return new_Skin.UMP;    // populated via registry (ApplyAllRegisteredSkins)
    if (IsSkinWeaponVariant(weaponId, 102003)) return new_Skin.Vector; // populated via registry (ApplyAllRegisteredSkins)
    if (IsSkinWeaponVariant(weaponId, 102004)) return new_Skin.Thompson; // populated via registry (ApplyAllRegisteredSkins)
    if (IsSkinWeaponVariant(weaponId, 102005)) return new_Skin.Bizon;  // populated via registry (ApplyAllRegisteredSkins)
    if (IsSkinWeaponVariant(weaponId, 102105)) return new_Skin.P90;     // populated via registry (ApplyAllRegisteredSkins)
    if (IsSkinWeaponVariant(weaponId, 103001)) return new_Skin.K98;    // populated via registry (ApplyAllRegisteredSkins)
    if (IsSkinWeaponVariant(weaponId, 103002)) return new_Skin.M24;    // populated via registry (ApplyAllRegisteredSkins)
    if (IsSkinWeaponVariant(weaponId, 103003)) return new_Skin.AWM;    // populated via registry (ApplyAllRegisteredSkins)
    if (IsSkinWeaponVariant(weaponId, 103004)) return new_Skin.SKS;    // populated via registry (ApplyAllRegisteredSkins)
    if (IsSkinWeaponVariant(weaponId, 103005)) return new_Skin.VSS;    // populated via registry (ApplyAllRegisteredSkins)
    if (IsSkinWeaponVariant(weaponId, 103006)) return new_Skin.Mini14; // populated via registry (ApplyAllRegisteredSkins)
    if (IsSkinWeaponVariant(weaponId, 103007)) return new_Skin.MK14;   // populated via registry (ApplyAllRegisteredSkins)
    if (IsSkinWeaponVariant(weaponId, 103009)) return new_Skin.SLR;    // populated via registry (ApplyAllRegisteredSkins)
    if (IsSkinWeaponVariant(weaponId, 103012)) return new_Skin.AMR;    // populated via registry (ApplyAllRegisteredSkins)
    if (IsSkinWeaponVariant(weaponId, 104002)) return new_Skin.S1897;  // populated via registry (ApplyAllRegisteredSkins)
    if (IsSkinWeaponVariant(weaponId, 104003)) return new_Skin.S12K;   // populated via registry (ApplyAllRegisteredSkins)
    if (IsSkinWeaponVariant(weaponId, 104004)) return new_Skin.DBS;    // populated via registry (ApplyAllRegisteredSkins)
    if (IsSkinWeaponVariant(weaponId, 104101)) return new_Skin.XM1014; // populated via registry (ApplyAllRegisteredSkins)
    if (IsSkinWeaponVariant(weaponId, 108004)) return new_Skin.Pan;    // populated via registry (ApplyAllRegisteredSkins)
    if (IsSkinWeaponVariant(weaponId, 105001)) return new_Skin.M249;   // populated via registry (ApplyAllRegisteredSkins)
    if (IsSkinWeaponVariant(weaponId, 105002)) return new_Skin.DP28;   // populated via registry (ApplyAllRegisteredSkins)
    if (IsSkinWeaponVariant(weaponId, 105010)) return new_Skin.MG3;    // populated via registry (ApplyAllRegisteredSkins)
    return 0;
}

static inline SkinWeaponAvatar GetFullWeapon(int id)
{
    // -----------------------------------------------------------------------------
    // Fills a SkinWeaponAvatar struct with the *attachment* skin IDs (quickMag, stock,
    // sights, etc.) that correspond to the chosen primary skin ID.
    // The chosen primary (e.g. new_Skin.AKM) comes from GetWeap, which in turn reads
    // values populated by the central registry (UpdateSkinManager.cpp: skinRegistry[],
    // ApplyAllRegisteredSkins, per-family ApplyXXXFromDescriptors + SkinTableChoice).
    // This struct is then used by ApplyFullWeaponSkin to drive ApplyWeaponAttachmentSkin
    // against the static skin_tables:: lists.
    // Only a subset of weapons currently have attachment mappings here (others only set .GUN).
    // See the big "Skin consumption / application layer" header above and the #if 0
    // named applicator examples in UpdateSkinManager.cpp for the unification direction.
    // -----------------------------------------------------------------------------
    SkinWeaponAvatar gun{};
    gun.GUN = id;

    if (id == new_Skin.AKM) {
        gun.quickMag = new_Skin.AKM_Mag;  // from registry-populated new_Skin (ApplyAKMFromDescriptors)
    } else if (id == new_Skin.M16A4) {
        gun.stock = new_Skin.M16A4_Stock;
        gun.quickMag = new_Skin.M16A4_Mag;
    } else if (id == new_Skin.Scar) {
        gun.quickMag = new_Skin.Scar_Mag;
    } else if (id == new_Skin.M762) {
        gun.quickMag = new_Skin.M762_Mag;
    } else if (id == new_Skin.M416_1) {
        gun.quickMag = new_Skin.M416_quickMag;
        gun.extendedMag = new_Skin.M416_extendedMag;
        gun.quickNextended = new_Skin.M416_quickNextended;
        gun.flash = new_Skin.M416_flash;
        gun.compe = new_Skin.M416_compe;
        gun.silent = new_Skin.M416_silent;
        gun.holo = new_Skin.M416_holo;
        gun.x2 = new_Skin.M416_x2;
        gun.x3 = new_Skin.M416_x3;
        gun.x4 = new_Skin.M416_x4;
        gun.x6 = new_Skin.M416_x6;
        gun.angle = new_Skin.M416_angle;
        gun.thumb = new_Skin.M416_thumb;
        gun.stock = new_Skin.M416_stock;
    }

    return gun;
}

static inline bool IsOneOfSkinIds(int id, const int *ids, size_t count)
{
    for (size_t i = 0; i < count; i++) {
        if (id == ids[i]) return true;
    }
    return false;
}

template <std::size_t N>
static inline bool IsOneOfSkinIds(int id, const std::array<int, N>& ids)
{
    for (std::size_t i = 0; i < N; ++i) {
        if (id == ids[i]) return true;
    }
    return false;
}

template <std::size_t N>
static inline void ApplyWeaponAttachmentSkin(int &id, int replacement, const std::array<int, N>& ids)
{
    if (replacement > 0 && id > 0 && IsOneOfSkinIds(id, ids)) {
        id = replacement;
    }
}

static inline void ApplyFullWeaponSkin(ASTExtraShootWeapon *weapon)
{
    // -----------------------------------------------------------------
    // Consumption side for weapon skins.
    // new_Skin.XXX values come from the registry (see top of this file
    // and UpdateSkinManager.cpp). This function uses those chosen skin
    // IDs + the static skin_tables:: lists to mutate the weapon's
    // replicated attachment data (synData).
    // -----------------------------------------------------------------
    if (!weapon) return;

    LastGunUsedToKillSkin = 0;
    int weaponSkin = GetWeap((int)weapon->GetWeaponID());
    if (weaponSkin <= 0) return;
    LastGunUsedToKillSkin = weaponSkin;

    auto &data = weapon->synData;
    if (data.Num() < 8) return;

    auto gun = GetFullWeapon(weaponSkin);
    if (data[7].DefineID.TypeSpecificID > 0) {
        data[7].DefineID.TypeSpecificID = gun.GUN;
    }

    for (int j = 0; j < data.Num(); j++) {
        int &id = data[j].DefineID.TypeSpecificID;
        if (id <= 0) continue;

        // Attachment override logic (consumption side):
        // The chosen skin ID (selected by the registry in UpdateSkinManager
        // and stored in new_Skin) is matched here against the weapon's
        // current attachment IDs. If a match is found in the static
        // skin_tables:: list for that skin, the ID is replaced.
        if (gun.GUN == new_Skin.AKM) {
            // Unified via named applicator artifact (ApplyAKMWeaponAttachments) registered in skinRegistry container.
            // See UpdateSkinManager.cpp for the centralized attachment list using skin_tables.
            ApplyWeaponAttachmentSkin(id, gun.quickMag, skin_tables::AKMMag);
        } else if (gun.GUN == new_Skin.M16A4) {
            ApplyWeaponAttachmentSkin(id, gun.stock, skin_tables::M16A4Stock);
            ApplyWeaponAttachmentSkin(id, gun.quickMag, skin_tables::M16A4Mag);
        } else if (gun.GUN == new_Skin.Scar) {
            // SCAR applicator (ApplySCARWeaponAttachments) added in container work for future direct wiring.
            ApplyWeaponAttachmentSkin(id, gun.quickMag, skin_tables::SCARMag);
        } else if (gun.GUN == new_Skin.M762) {
            // M762 applicator (ApplyM762WeaponAttachments) added alongside SCAR.
            ApplyWeaponAttachmentSkin(id, gun.quickMag, skin_tables::M762Mag);
        } else if (gun.GUN == new_Skin.M416_1) {
            // M416 uses the long list; matching named ApplyM416WeaponAttachments exists in UpdateSkinManager
            // as part of NRG.h application unification + container artifacts.
            ApplyWeaponAttachmentSkin(id, gun.quickMag, skin_tables::M416quickMag);
            ApplyWeaponAttachmentSkin(id, gun.extendedMag, skin_tables::M416extendedMag);
            ApplyWeaponAttachmentSkin(id, gun.quickNextended, skin_tables::M416quickNextended);
            ApplyWeaponAttachmentSkin(id, gun.flash, skin_tables::M416flash);
            ApplyWeaponAttachmentSkin(id, gun.compe, skin_tables::M416compe);
            ApplyWeaponAttachmentSkin(id, gun.silent, skin_tables::M416silent);
            ApplyWeaponAttachmentSkin(id, gun.holo, skin_tables::M416holo);
            ApplyWeaponAttachmentSkin(id, gun.x2, skin_tables::M416x2);
            ApplyWeaponAttachmentSkin(id, gun.x3, skin_tables::M416x3);
            ApplyWeaponAttachmentSkin(id, gun.x4, skin_tables::M416x4);
            ApplyWeaponAttachmentSkin(id, gun.x6, skin_tables::M416x6);
            ApplyWeaponAttachmentSkin(id, gun.angle, skin_tables::M416angle);
            ApplyWeaponAttachmentSkin(id, gun.thumb, skin_tables::M416thumb);
            ApplyWeaponAttachmentSkin(id, gun.stock, skin_tables::M416stock);
        }
    }
}

static void (*orig_kill_message_event)(ASTExtraPlayerController*, FFatalDamageParameter*) = nullptr;

static void kill_message_event(ASTExtraPlayerController *PC, FFatalDamageParameter *FDP)
{
    if (Config["SKIN_ENABLE"] && PC && FDP &&
        PC->PlayerKey == FDP->CauserKey &&
        LastGunUsedToKillSkin > 0) {
        FDP->CauserWeaponAvatarID = LastGunUsedToKillSkin;
    }

    if (orig_kill_message_event) {
        orig_kill_message_event(PC, FDP);
    }
}

static inline bool ProtectVTableSlot(void **slot, int prot)
{
    if (!slot) return false;

    constexpr size_t pageSize = 4096;
    uintptr_t addr = reinterpret_cast<uintptr_t>(slot);
    uintptr_t pageStart = addr & ~(pageSize - 1);
    uintptr_t pageEnd = (addr + sizeof(void*) + pageSize - 1) & ~(pageSize - 1);

    return mprotect(reinterpret_cast<void*>(pageStart), pageEnd - pageStart, prot) == 0;
}

static inline void ApplyFatalDamageSkin(ASTExtraPlayerController *localPlayerController)
{
    if (!localPlayerController || !localPlayerController->VTable) return;

    auto vtable = reinterpret_cast<void **>(localPlayerController->VTable);
    if (!vtable || vtable[kKillMessageVTableIndex] == reinterpret_cast<void*>(kill_message_event)) return;

    orig_kill_message_event =
        reinterpret_cast<decltype(orig_kill_message_event)>(vtable[kKillMessageVTableIndex]);

    if (!ProtectVTableSlot(&vtable[kKillMessageVTableIndex], PROT_READ | PROT_WRITE | PROT_EXEC)) return;
    vtable[kKillMessageVTableIndex] = reinterpret_cast<void*>(kill_message_event);
    ProtectVTableSlot(&vtable[kKillMessageVTableIndex], PROT_READ | PROT_EXEC);
}

static inline int GetCurrentWeaponSkin(ASTExtraPlayerCharacter *localPlayer)
{
    if (!localPlayer || !localPlayer->WeaponManagerComponent ||
        !localPlayer->WeaponManagerComponent->CurrentWeaponReplicated) {
        return 0;
    }

    auto CurrentWeaponReplicated =
        (ASTExtraShootWeapon *)localPlayer->WeaponManagerComponent->CurrentWeaponReplicated;
    return GetWeap((int)CurrentWeaponReplicated->GetWeaponID());
}

static inline uint64_t MakeDeadBoxChangeKey(uint32_t targetKey, int skinID)
{
    return (static_cast<uint64_t>(targetKey) << 32) |
           static_cast<uint32_t>(skinID);
}

static inline void ApplyDeadBoxSkin(ASTExtraPlayerCharacter *localPlayer)
{
    if (!localPlayer) return;

    if (ChangedDeadBoxTargets.size() > 512) {
        ChangedDeadBoxTargets.clear();
    }

    int SkinID = GetCurrentWeaponSkin(localPlayer);
    if (SkinID <= 0) return;

    std::vector<APlayerTombBox *> TombBoxes;
    GetAllActors(TombBoxes);

    for (auto box : TombBoxes) {
        if (!box || isObjectInvalid(box) ||
            !box->DamageCauser || !box->TargetPlayer) {
            continue;
        }

        if (box->DamageCauser->PlayerKey != localPlayer->PlayerKey) continue;

        uint32_t targetKey = box->TargetPlayer->PlayerKey;
        uint64_t changeKey = MakeDeadBoxChangeKey(targetKey, SkinID);
        if (ChangedDeadBoxTargets.count(changeKey)) continue;

        auto DeadBoxComp = (UDeadBoxAvatarComponent *)box->GetComponentByClass(UDeadBoxAvatarComponent::StaticClass());
        if (!DeadBoxComp) continue;

        DeadBoxComp->PreChangeItemAvatar(SkinID);
        DeadBoxComp->AsyncChangeItemAvatar(SkinID);
        ChangedDeadBoxTargets.insert(changeKey);
    }
}

static inline bool IsAvatarMeshChangedFunction(UFunction *pFunc)
{
    static int OnRepAvatarMeshChangedIndex = -1;
    if (!pFunc) return false;

    if (OnRepAvatarMeshChangedIndex == -1) {
        if (pFunc->GetFullName() == "Function ShadowTrackerExtra.STExtraWeapon.OnRep_AvatarMeshChanged") {
            OnRepAvatarMeshChangedIndex = pFunc->InternalIndex;
        }
    }

    return OnRepAvatarMeshChangedIndex != -1 && pFunc->InternalIndex == OnRepAvatarMeshChangedIndex;
}

static inline void ApplyWeaponSkinFromProcessEvent(UObject *pObj, UFunction *pFunc)
{
    if (!Config["SKIN_ENABLE"] || !pObj || !IsAvatarMeshChangedFunction(pFunc)) return;

    ApplyFullWeaponSkin((ASTExtraShootWeapon *)pObj);
}

static inline void NotifyBackpackItemListNet(UBackpackComponent *backpack)
{
    if (!backpack) return;

    static UFunction *pFunc = nullptr;
    if (!pFunc) {
        pFunc = UObject::FindObject<UFunction>("Function Gameplay.BackpackComponent.OnRep_ItemListNet");
    }
    if (!pFunc) return;

    UBackpackComponent_OnRep_ItemListNet_Params params;
    backpack->ProcessEvent(pFunc, &params);
}

static inline bool UpdateWeaponAvatarAdditionalData(TArray<FBattleItemAdditionalData> &AdditionalData, int NewSkinID)
{
    if (NewSkinID <= 0) return false;

    for (int k = 0; k < AdditionalData.Num(); k++) {
        if (AdditionalData[k].EDataType == EBattleItemAdditionalDataType::EBattleItemAdditionalDataType__WeaponAvatar) {
            if (AdditionalData[k].IntData != NewSkinID) {
                AdditionalData[k].IntData = NewSkinID;
                return true;
            }
            return false;
        }
    }

    FBattleItemAdditionalData InData{};
    InData.EDataType = EBattleItemAdditionalDataType::EBattleItemAdditionalDataType__WeaponAvatar;
    InData.IntData = NewSkinID;

    UBackpackUtils_UpdateAddtionData_Params params;
    params.InData = InData;
    params.OutAddtionData = AdditionalData;

    static UFunction *pFunc = nullptr;
    if (!pFunc) {
        pFunc = UObject::FindObject<UFunction>("Function ShadowTrackerExtra.BackpackUtils.UpdateAddtionData");
    }
    if (!pFunc) return false;

    auto defaultObj = UBackpackUtils::StaticClass()->GetDefaultObject();
    if (!defaultObj) return false;

    auto flags = pFunc->FunctionFlags;
    pFunc->FunctionFlags |= 0x400;
    defaultObj->ProcessEvent(pFunc, &params);
    pFunc->FunctionFlags = flags;

    if (params.OutAddtionData.Num() <= AdditionalData.Num()) return false;

    AdditionalData = params.OutAddtionData;
    return true;
}

template <std::size_t N>
static inline bool TryApplyInventorySkinId(int originalID, const std::array<int, N>& skinIDs, int newSkinID,
                                           int &targetID, bool &changed)
{
    for (std::size_t i = 0; i < N; ++i) {
        if (originalID == skinIDs[i]) {
            if (targetID != newSkinID) {
                targetID = newSkinID;
                changed = true;
            }
            return true;
        }
    }
    return false;
}

static inline void ApplyBackpackHelmetSkin(ASTExtraPlayerController *localPlayerController)
{
    // Backpack / Helmet skins (3-level tables) are populated via the *special*
    // registry entry (SkinEntryKind::ThreeLevel) in UpdateSkinManager.cpp:
    //   ApplyBackpackHelmetFromDescriptors() calls ApplyThreeLevelTable for
    //   SKIN_BACKPACK / SKIN_HELMET using the BackpackLv*/HelmetLv* tables
    //   and writes into new_Skin.baglv1/2/3 + helmetlv1/2/3.
    // This function (the consumer) then uses TryApplyInventorySkinId against
    // those same skin_tables lists + the registry-filled new_Skin values.
    // The central skinRegistry[] + ApplyAllRegisteredSkins() is the single
    // source of truth even for these non-gun special cases.
    if (localPlayerController && localPlayerController->BackpackComponent){
     auto &data = localPlayerController->BackpackComponent->ItemListNet;
     auto &bag = data.IncArray;
     bool NeedRefreshBack = false;
     for (int j = 0; j < bag.Num(); j++) {
     int ID = bag[j].Unit.DefineID.TypeSpecificID;

bool ItemSkinChanged = false;
int &TypeSpecificID = bag[j].Unit.DefineID.TypeSpecificID;
if (TryApplyInventorySkinId(ID, skin_tables::BackpackLv1, new_Skin.baglv1, TypeSpecificID, ItemSkinChanged) ||
    TryApplyInventorySkinId(ID, skin_tables::BackpackLv2, new_Skin.baglv2, TypeSpecificID, ItemSkinChanged) ||
    TryApplyInventorySkinId(ID, skin_tables::BackpackLv3, new_Skin.baglv3, TypeSpecificID, ItemSkinChanged) ||
    TryApplyInventorySkinId(ID, skin_tables::HelmetLv1, new_Skin.helmetlv1, TypeSpecificID, ItemSkinChanged) ||
    TryApplyInventorySkinId(ID, skin_tables::HelmetLv2, new_Skin.helmetlv2, TypeSpecificID, ItemSkinChanged) ||
    TryApplyInventorySkinId(ID, skin_tables::HelmetLv3, new_Skin.helmetlv3, TypeSpecificID, ItemSkinChanged)) {
    if (ItemSkinChanged) {
        NeedRefreshBack = true;
    }
    continue;
}

int NewSkinID = GetWeap(ID);
if (NewSkinID > 0) {
    auto &AdditionalData = bag[j].Unit.AdditionalData;
    if (UpdateWeaponAvatarAdditionalData(AdditionalData, NewSkinID)) {
        NeedRefreshBack = true;
    }
}
                
                
                 
                 
                
           
            }
            if (NeedRefreshBack) {
                NotifyBackpackItemListNet(localPlayerController->BackpackComponent);
            }
        }
}

static inline void ApplyAvatarSlotSkin(ASTExtraPlayerCharacter *localPlayer)
{
    // Avatar slot skins (character model helmet + backpack slots) are also
    // fed by the same ThreeLevel special in the registry (SkinEntryKind::ThreeLevel,
    // ApplyBackpackHelmetFromDescriptors). Uses identical TryApplyInventorySkinId
    // + skin_tables::HelmetLv*/BackpackLv* + new_Skin.*lv* values as the
    // inventory version (ApplyBackpackHelmetSkin). After changes, forces a
    // OnRep_BodySlotStateChanged repaint.
    // This keeps the "non-gun special" story consistent with the central
    // skinRegistry[] container.
if (localPlayer && localPlayer->AvatarComponent2) {
auto AvatarComp = localPlayer->AvatarComponent2;
FNetAvatarSyncData NetAvatarComp = *(FNetAvatarSyncData*)((uintptr_t)AvatarComp + 0x3e8);

auto Slotsybc = NetAvatarComp.SlotSyncData;

bool AvatarSlotSkinChanged = false;
for (int j = 0; j < Slotsybc.Num(); j++) {
auto &Slot = Slotsybc[j];
int ID = Slot.ItemId;
bool ItemSkinChanged = false;
if (TryApplyInventorySkinId(ID, skin_tables::HelmetLv1, new_Skin.helmetlv1, Slot.ItemId, ItemSkinChanged) ||
    TryApplyInventorySkinId(ID, skin_tables::HelmetLv2, new_Skin.helmetlv2, Slot.ItemId, ItemSkinChanged) ||
    TryApplyInventorySkinId(ID, skin_tables::HelmetLv3, new_Skin.helmetlv3, Slot.ItemId, ItemSkinChanged) ||
    TryApplyInventorySkinId(ID, skin_tables::BackpackLv1, new_Skin.baglv1, Slot.ItemId, ItemSkinChanged) ||
    TryApplyInventorySkinId(ID, skin_tables::BackpackLv2, new_Skin.baglv2, Slot.ItemId, ItemSkinChanged) ||
    TryApplyInventorySkinId(ID, skin_tables::BackpackLv3, new_Skin.baglv3, Slot.ItemId, ItemSkinChanged)) {
if (ItemSkinChanged) {
AvatarSlotSkinChanged = true;
}
}
}

if (AvatarSlotSkinChanged) {
localPlayer->AvatarComponent2->OnRep_BodySlotStateChanged();
}
}
}

static inline int GetVehicleSkinForShape(ESTExtraVehicleShapeType shape)
{
    // Vehicle skins are PurePrimary entries in the central skinRegistry[]
    // (ApplyDaciaFromDescriptors, ApplyUAZFromDescriptors, etc. using the
    // SKIN_VEHICLE_* / vehicle_* tables from skin_tables). They are populated
    // the same way as gun primaries and parachute (via ApplyAllRegisteredSkins).
    // This switch simply maps the game's ESTExtraVehicleShapeType to the
    // corresponding registry-fed new_Skin.* value for later avatar application.
    switch (shape) {
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Motorbike:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Motorbike_SideCart:
            return new_Skin.Moto;   // PurePrimary via registry
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Dacia:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_HeavyDacia:
            return new_Skin.Dacia;  // PurePrimary via registry
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_UAZ:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_UAZ01:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_UAZ02:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_UAZ03:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_UAZ_PS:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_HeavyUAZ:
            return new_Skin.UAZ;    // PurePrimary via registry
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Buggy:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_HeavyBuggy:
            return new_Skin.Buggy;  // PurePrimary via registry
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_MiniBus:
            return new_Skin.MiniBus; // PurePrimary via registry
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_CoupeRB:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Lamborghini:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Lamborghini01:
            return new_Skin.CoupleRB; // PurePrimary via registry
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_PG117:
            return new_Skin.Boat;   // PurePrimary via registry
        default:
            return 0;
    }
}

static inline void ApplyVehicleAvatarSkin(ASTExtraVehicleBase *vehicle, std::map<uintptr_t, int> &changedVehicles)
{
    if (!vehicle || isObjectInvalid(vehicle)) return;

    int SkinID = GetVehicleSkinForShape(vehicle->VehicleShapeType);
    if (SkinID <= 0) return;

    uintptr_t vehicleKey = reinterpret_cast<uintptr_t>(vehicle);
    if (changedVehicles[vehicleKey] == SkinID) return;

    auto VehicleAvatarComp =
        (UVehicleContainerAvatarComponent *)vehicle->GetComponentByClass(UVehicleContainerAvatarComponent::StaticClass());
    if (!VehicleAvatarComp) return;

    VehicleAvatarComp->PreChangeAvatar(SkinID);
    VehicleAvatarComp->NetAvatarID = SkinID;
    VehicleAvatarComp->AsyncLoadHandle(SkinID);
    VehicleAvatarComp->AsyncLoadResource(SkinID);
    VehicleAvatarComp->OnRep_NetAvatarID();
    VehicleAvatarComp->ChangeMesh();

    changedVehicles[vehicleKey] = SkinID;
}

static inline void ApplyVehicleSkin()
{
    static std::chrono::steady_clock::time_point lastVehicleSkinTime;
    static std::map<uintptr_t, int> ChangedVehicleTargets;

    auto currentTime = std::chrono::steady_clock::now();
    auto timeDiff = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - lastVehicleSkinTime).count();
    if (timeDiff <= 1000) {
        return;
    }

    if (ChangedVehicleTargets.size() > 512) {
        ChangedVehicleTargets.clear();
    }

    std::vector<ASTExtraVehicleBase *> Vehicles;
    GetAllActors(Vehicles);

    for (auto vehicle : Vehicles) {
        ApplyVehicleAvatarSkin(vehicle, ChangedVehicleTargets);
    }

    lastVehicleSkinTime = currentTime;
}

static inline void ApplyWeaponSkin(ASTExtraPlayerCharacter *localPlayer)
{
    if (!localPlayer || !localPlayer->WeaponManagerComponent ||
        !localPlayer->WeaponManagerComponent->CurrentWeaponReplicated) {
        return;
    }

    auto currentTime = std::chrono::steady_clock::now();
    auto timeDiff = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - lastWeaponChangeTime).count();
    if (timeDiff <= 1000) {
        return;
    }

    auto CurrentWeaponReplicated = (ASTExtraShootWeapon *)localPlayer->WeaponManagerComponent->CurrentWeaponReplicated;
    ApplyFullWeaponSkin(CurrentWeaponReplicated);
    CurrentWeaponReplicated->DelayHandleAvatarMeshChanged();
    lastWeaponChangeTime = currentTime;
    return;

}


void RenderESP(/*AHUD *HUD, *int SizeX, int SizeY*/)
{
    
    ASTExtraPlayerCharacter *localPlayer = 0;
    ASTExtraPlayerController *localPlayerController = 0;
         
    updateSkin();

        
    UGameplayStatics *gGameplayStatics = (UGameplayStatics *)UGameplayStatics::StaticClass();
UKismetMathLibrary* UMC = (UKismetMathLibrary*)UKismetMathLibrary::StaticClass();
        auto GWorld = GetWorld();
        if (GWorld) {
            UNetDriver *NetDriver = GWorld->NetDriver;
            if (NetDriver) {
                UNetConnection *ServerConnection = NetDriver->ServerConnection;
                if (ServerConnection) {
                    localPlayerController = (ASTExtraPlayerController *)ServerConnection->PlayerController;
                }
            }
       
            if (localPlayerController)
            {
                std::vector<ASTExtraPlayerCharacter *> PlayerCharacter;
                GetAllActors(PlayerCharacter);

                for (auto actor = PlayerCharacter.begin(); actor != PlayerCharacter.end(); actor++) {
                    auto Actor = *actor;
                    if (Actor->PlayerKey == ((ASTExtraPlayerController *)localPlayerController)->PlayerKey) {
                        localPlayer = Actor;
                        break;
                    }
                }
    if (localPlayer) {
        
        
        
         if (Config["SKIN_ENABLE"]) {
             ApplyBackpackHelmetSkin(localPlayerController);
          }
          

    if (Config["SKIN_ENABLE"]) {
        ApplyAvatarSlotSkin(localPlayer);
}
          
          
            if (Config["SKIN_ENABLE"]) {
                ApplyWeaponSkin(localPlayer);
}

            if (Config["SKIN_ENABLE"]) {
                ApplyVehicleSkin();
}

            if (Config["SKIN_ENABLE"]) {
                ApplyFatalDamageSkin(localPlayerController);
                ApplyDeadBoxSkin(localPlayer);
            }
        
            if (Config["MEMORY_WIDEVIEW"]) {
                        localPlayer->ThirdPersonCameraComponent->SetFieldOfView(110);
                        }
                        
                             if (localPlayer->PartHitComponent) {
                        auto ConfigCollisionDistSqAngles = localPlayer->PartHitComponent->ConfigCollisionDistSqAngles;
                        for (int j = 0; j < ConfigCollisionDistSqAngles.Num(); j++) {
                            ConfigCollisionDistSqAngles[j].Angle = 120.0f;//120
                        }
                        localPlayer->PartHitComponent->ConfigCollisionDistSqAngles = ConfigCollisionDistSqAngles;
                    }

                     if (Config["NRG_AIMBOT"]) {
                   if (Config["AIM_MOD1"]) {
    ASTExtraPlayerCharacter *Target = GetTargetByCrosshairDistance();
                    
                            
              
                    if (Target)
                    {
                        bool triggerOk = false;
                       if (Config["AIM::TRIGGER1"]) {
                    triggerOk = g_LocalPlayer->bIsWeaponFiring;
                } else if (Config["AIM::TRIGGER2"]) {
                    triggerOk = g_LocalPlayer->bIsGunADS;
                } else if (Config["AIM::TRIGGER3"]) {
                    triggerOk = g_LocalPlayer->bIsWeaponFiring || g_LocalPlayer->bIsGunADS;
                
            } else triggerOk = true;
                        if (triggerOk)
                        {
            FVector targetAimPos = Target->GetBonePos("Head", {});

                                        
                                              if (Config["RECOI_LCOMPARISON"]) {
                                                    if (localPlayer->bIsGunADS) {
                                                        if (localPlayer->bIsWeaponFiring) {
                                                            float dist = localPlayer->GetDistanceTo(Target) / 100.f;                                                                                 
                                                            targetAimPos.Z -= dist * (float) Config["RECOIL_SIZE"] * 0.1f; //
                                                        }  
                                                    }
                                                }     
                                                    
                                                    
                                              
                                                            
                                            auto WeaponManagerComponent = localPlayer->WeaponManagerComponent;
                                            if (WeaponManagerComponent) {
                                                auto propSlot = WeaponManagerComponent->GetCurrentUsingPropSlot();
                                                if ((int) propSlot.GetValue() >= 1 &&
                                                    (int) propSlot.GetValue() <= 3) {
                                                    auto CurrentWeaponReplicated = (ASTExtraShootWeapon *) WeaponManagerComponent->CurrentWeaponReplicated;
                                                    if (CurrentWeaponReplicated) {
                                                        auto ShootWeaponComponent = CurrentWeaponReplicated->ShootWeaponComponent;
                                                        if (ShootWeaponComponent) {
                                                            UShootWeaponEntity *ShootWeaponEntityComponent = ShootWeaponComponent->ShootWeaponEntityComponent;
                                                            if (ShootWeaponEntityComponent) {
                                                                ASTExtraVehicleBase *CurrentVehicle = Target->CurrentVehicle;
                                                                if (CurrentVehicle) {
                                                                    FVector LinearVelocity = CurrentVehicle->ReplicatedMovement.LinearVelocity;

float dist = localPlayer->GetDistanceTo(Target);
                                                                    auto timeToTravel = dist /
                                                                    ShootWeaponEntityComponent->BulletFireSpeed;
                                                                    targetAimPos = UMC->Add_VectorVector(targetAimPos,UMC->Multiply_VectorFloat(LinearVelocity, timeToTravel));
                                                                } else {
                                                                    FVector Velocity = Target->GetVelocity();
                                                                    float dist = localPlayer->GetDistanceTo(Target);
                                                                    auto timeToTravel = dist /
                                                                    ShootWeaponEntityComponent->BulletFireSpeed;
                                                                    targetAimPos = UMC->Add_VectorVector(targetAimPos, UMC->Multiply_VectorFloat(Velocity, timeToTravel));
                                                                }
                                                                
                                                              
                                                                localPlayerController->ClientSetLocation(localPlayer->K2_GetActorLocation(), ToRotator(localPlayerController->PlayerCameraManager->CameraCache.POV.Location, targetAimPos));

         
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }}
                    
               
                
        }

        }
    }
    
    g_LocalPlayer = localPlayer;
    g_PlayerController = localPlayerController;
    //}
}


//=======================================================================//

#define SLEEP_TIME 1000LL / 90LL
void *maps_thread(void *) {
    while (true) {
        auto t1 = std::chrono::steady_clock::now();

auto objs = UObject::GetGlobalObjects();
for (int i = 0; i < objs.Num(); i++) {
auto Object = objs.GetByIndex(i);
if (isObjectInvalid(Object))
continue;

            if (Object->IsA(UPlayerPetMovementComponent::StaticClass())) {
                auto Upload = (UPlayerPetMovementComponent *) Object;
           if (!strcmp(GetPackageName().c_str(), "com.tencent.ig")) {
             // Upload->bEnableServerAntiCheat = false;
            }
       }

if (Object->IsA(UBulletHitInfoUploadComponent::StaticClass())) {
    auto Upload = (UBulletHitInfoUploadComponent *) Object;
    Upload->bEnableTssSdkAntiData = false;
    Upload->bEnableTssSdkAntiDataFilter = false;
    Upload->bEnableTssSdkAntiDataFilterNew = false;
    Upload->bDisableDsTick = true;
    Upload->bDisableDsAntiDataReport = true;
    Upload->bEnableAddSPCShootData = false;
    Upload->NeedSendSimpleCharacterHitData = false;

    }

if (Object->IsA(UMoveAntiCheatComponent::StaticClass())) {
auto Upload = (UMoveAntiCheatComponent *) Object;
Upload->MinMoveAntiCheatCheckIntervel2 = 1;
Upload->MaxTotalMoveCheatTimes = 60;
}}


std::vector<sRegion> tmp;
FILE *f = fopen("/proc/self/maps", "r");
if (f) {
char line[512];
while (fgets(line, sizeof line, f)) {
uintptr_t start, end;
char tmpProt[16];
if (sscanf(line, "%" PRIXPTR "-%" PRIXPTR " %16s %*s %*s %*s %*s", &start, &end, tmpProt) > 0) {
if (tmpProt[0] != 'r') {
tmp.push_back({start, end});
}
}
}
fclose(f);
}

trapRegions = std::move(tmp); // Move assignment
auto td = std::chrono::steady_clock::now() - t1;
std::chrono::milliseconds sleep_time{std::max(0LL, -std::chrono::duration_cast<std::chrono::milliseconds>(td).count())};
std::this_thread::sleep_for(sleep_time);
}
}

//===================================================================================//

void *MemoryThread(void *) {
    while (bValid) {
        auto t1 = std::chrono::duration_cast<std::chrono::milliseconds>(
                std::chrono::system_clock::now().time_since_epoch()).count();

        if (!g_Token.empty()) {
            if (!g_Auth.empty()) {
                if (g_Token == g_Auth) {


                    auto localPlayer = g_LocalPlayer;
                    auto localController = g_PlayerController;
                    if (localPlayer && localController) {

                        float PlayView;

                        PlayView = Config["MEMORY::WIDEVIEWSIZE"];

                        if (Config["MEMORY::WIDEVIEW"]) {
                            localPlayer->ThirdPersonCameraComponent->SetFieldOfView(110);
                        }

                    }

                }
                // }
            }
        }
        auto td = std::chrono::duration_cast<std::chrono::milliseconds>(
                std::chrono::system_clock::now().time_since_epoch()).count() - t1;
        std::this_thread::sleep_for(
                std::chrono::milliseconds(std::max(std::min(0LL, SLEEP_TIME - td), SLEEP_TIME)));
    }
    return 0;
}

//===================================================================================//

int glWidth,  glHeight;
extern "C"
JNIEXPORT void JNICALL
Java_com_bearmod_Floating_DrawOn(JNIEnv *env, jclass type, jobject espView, jobject canvas) {
    espOverlay = ESP(env, espView, canvas);
    
    if (espOverlay.isValid()){
       // worldAutoSleep.AutoFPS();
     DrawESP(espOverlay, espOverlay.getWidth(), espOverlay.getHeight());
     //   DrawESP(espOverlay, screenWidth55, screenHeight55);
    }
    
}

//===================================================================================//
// Hooked ProcessEvent function to render ESP
void *(*oProcessEvent)(UObject *pObj, UFunction *pFunc, void *pArgs);
void *hkProcessEvent(UObject *pObj, UFunction *pFunc, void *pArgs) {

if (pFunc) {

ApplyWeaponSkinFromProcessEvent(pObj, pFunc);

if (pFunc->GetFullName() == "Function Engine.HUD.ReceiveDrawHUD")
        {
            /*
            AHUD *pHUD = (AHUD *)pObj;
            if (pHUD)
            {
                */
                RenderESP();
         }
    }
    return oProcessEvent(pObj, pFunc, pArgs);
}

//===================================================================================//

/*size_t SKINMODE(char *s) {

      if (!Config["SKIN_OUTFIT"]) {
        return strlen(s);
    }


static const std::unordered_map<std::string, std::string> replacements = {
//---------衣服-------//
{"403006", "1404049"},
{"404151", "1404050"}, //BAPE Sta Mid
{"1405884", "1406327"}, //BAPE Sta Mid
{"1405267", "1407387"},//魅夜死神
{"1405548", "1407366"},//风灵迦尔
{"403003", "1410610"},//利威尔角色皮肤(绿男孩)
{"1406748", "1406387"},//三巨头之一，衣服
{"1405113", "1407103"},//新手礼包衣服
{"1405385", "1407558"},
{"403020", "1405628"},  //金尊法老圣装
{"403032", "1407470"}, //逍遥谪仙
{"403224", "1406891"}, //蚀魂冥王
{"403160", "1406386"}, //零战斗服
{"403002", "1407387"}, //魅夜死神套装
{"403198", "1400687"}, //万圣木乃伊
{"403124", "1406387"}, //明日香
{"1404008", "1405623"}, //冥界旅行者套装
{"403193", "1407103"}, //曙光芙洛拉圣装
{"403192", "1407219"}, //圣焰伊格尼圣装
{"403153", "1407453"}, //天方旅人
{"1400043", "1405163"}, //废墟猎手
{"403162", "1407277"}, //烈焰古神
{"404056", "1404191"}, //潮酷步行者裤子
{"403177", "1407079"}, //极乐愚者
{"1400100", "1400782"}, //冰雪晶核
{"403195", "1400569"}, //BAPE MIX CAMO HOODIE
{"403163", "1404049"}, //BAPE X PUBGM迷彩鲨鱼上衣
{"404001", "1404050"}, //BAPE X PUBGM迷彩裤子
{"404049", "1404002"}, //Bape City Camo Pants
{"404026", "1400650"}, //BAPE MIX CAMO SHORTS
{"405053", "1404051"}, //BAPE X PUBGM迷彩鞋子
{"405022", "1404003"}, //BAPE Sta Mid
{"402046", "474031"}, //BAPE Sta Mid
{"10100100", "1101001242"}, // AKM
{"10100300", "1101003070"}, // SCAR-L
{"10100400", "1101004236"}, // M416
{"10100600", "1101006062"}, // Aug
{"10501000", "1105010019"}, // MG3
{"10300700", "1103007028"}, // MK14
{"10100500", "1101005038"}, // 狗砸
{"10100800", "1101008081"}, // M762
{"10110200", "1101102017"}, // ACE32
{"10110000", "1101100012"}, // 法玛斯
//---------冲锋枪-------//
{"10200100", "1102001120"}, // UZI
{"10210500", "1102105012"}, // P90
{"10200200", "1102002136"}, // UMP45
{"10200300", "1102003080"}, // 维克托
//---------狙击枪------//
{"10300100", "1103001191"}, // 98K
{"10301200", "1103012019"}, // AMR
{"10300700", "1103007028"}, // MK14
{"10300300", "1103003087"}, // AWM
{"10300200", "1103002087"}, // M24
//------------战神框----//
{"2001001", "2002941"}, // S22战神框
//-----------动作-------//
{"2200101", "12212201"}, // 极暗刺客
{"2200301", "12219561"}, // 死神之触
{"2200201", "12201301"}, //谢谢动作

//---------地铁枪械------//
{"101001300","1101001213"}, // AK完好
{"101001400","1101001213"}, // AK改进
{"101001500","1101001213"}, // AK精致
{"101001600","1101001213"}, // Ak独眼
{"101001700","1101001213"}, // AK钢铁
{"10210500","1102105012"}, // P90
{"102105300","1102105012"}, // P90完好
{"102105400","1102105012"}, // P90改进
{"102105500","1102105012"}, // P90精致
{"102105600","1102105012"}, // P90独眼
{"102105700","1102105012"}, // P90钢铁
{"103007300","1103007028"}, // MK14完好
{"103007400","1103007028"}, // MK14改进
{"103007500","1103007028"}, // MK14精致
{"103007600","1103007028"}, // MK14独眼
{"103007700","1103007028"}, // MK14钢铁
{"10501000","1105010019"}, // MG3
{"105010300","1105010019"}, // MG3完好
{"105010400","1105010019"}, // MG3改进
{"105010500","1105010019"}, // MG3精致
{"105010600","1105010019"}, // MG3独眼
{"105010700","1105010019"}, // MG3钢铁
{"10100600","1101006075"}, // aug
{"101006300","1101006075"}, // aug完好
{"101006400","1101006075"}, // aug改进
{"101006500","1101006075"}, // aug精致
{"101006600","1101006075"}, // aug独眼
{"101006700","1101006075"}, // aug钢铁
{"10400400","1104004041"}, // DBS
{"104004300","1104004041"}, // DBS完好
{"104004400","1104004041"}, // DBS改进
{"104004500","1104004041"}, // DBS精致
{"104004600","1104004041"}, // DBS独眼
{"104004700","1104004041"}, // DBS钢铁
{"101004300","1101004236"}, // m4完好
{"101004400","1101004236"}, // m4改进
{"101004500","1101004236"}, // m4精致
{"101004600","1101004236"}, //m4独眼
{"101004700","1101004236"}, // m4钢铁
{"101005500","1101005098"},
{"101004500","1101005098"},
//---------被禁的话------//
{"20300100","1010042233"}, // 冰霜红点
{"20300300","1010042297"}, // 冰霜二倍
{"20301400","1010042296"}, // 冰霜三倍
{"20300400","1010042295"}, // 冰霜四倍
{"20301500","1030070213"}, // 龙吟六倍
{"20300500","1030070212"}, // 龙吟8倍
//---------被禁的话------//
{"108001100","108120100"}, //雷鸣
//地铁配件
{"204008500","1030070221"}, // 精致狙击枪快扩
{"205003500","1030070236"}, // 精致狙击枪托腮
{"201003500","1030070233"}, // 精致狙击枪口
//配件美化
{"20401300","1010042305"}, // 冰霜弹夹
{"20200200","1010042314"}, // 垂直握把
{"20500200","1010042315"}, // 冰霜枪托
{"29300700","1030070281"}, // 龙吟弹夹
{"29500700","1050100137"}, // 风鸣G3弹夹
{"29100600","1010060771"}, // aug弹夹
//背包美化
{"501001","1501001554"},
{"501002","1501002554"},
{"501003","1501003554"},
{"501004","1501001554"},
{"501005","1501002554"},
{"501006","1501003554"},

{"501007","1501001554"},
{"501008","1501002554"},
{"501009","1501003554"},


{"5010010","1501001554"},
{"5010011","1501002554"},
{"5010012","1501003554"},


{"5010013","1501001554"},
{"5010014","1501002554"},
{"5010015","1501003554"},
//头盔美化
{"1502003008","1502003014"},
{"1502002008","1502002014"},
{"1502001008","1502001014"},
//大厅主题美化
{"202408001","202408072"},
};
auto it = replacements.find(s);
 if (it != replacements.end()) {
 strcpy((char *)s, it->second.c_str());
 }
 return strlen(s);

}*/


//===================================================================================//

void *Init_Thread(void *) {
    while (!UE4) {
        UE4 = getModuleBase("libUE4.so");
        sleep(1);
    }


    LOGI("libUE4.so: %lu", UE4);
    FName::GNames = GetGNames();
    while (!FName::GNames) {
        FName::GNames = GetGNames();
        sleep(1);
    }


    Tools::Hook((void *) (UE4 + ProcessEvent_Offset), (void *) hkProcessEvent,
                (void **) &oProcessEvent);
    UObject::GUObjectArray = (FUObjectArray *) (UE4 + GUObject_Offset);

    Config["MEMORY_WIDEVIEWSIZE"] = 80;
    Config["AIM_SPEED"] = 10;
    Config["RADAR_SIZE"] = 60;
    Config["SKIN_SUIT"] = 0;
    bScanPatternCompleted = true;

    items_data = json::parse(JSON_ITEMS222);
    pthread_t t;
    pthread_create(&t, nullptr, maps_thread, nullptr);
    return nullptr;
}



const char *GetAndroidID(JNIEnv *env, jobject context) {
	jclass contextClass = env->FindClass(/*android/content/Context*/ StrEnc("`L+&0^[S+-:J^$,r9q92(as", "\x01\x22\x4F\x54\x5F\x37\x3F\x7C\x48\x42\x54\x3E\x3B\x4A\x58\x5D\x7A\x1E\x57\x46\x4D\x19\x07", 23).c_str());
	jmethodID getContentResolverMethod = env->GetMethodID(contextClass, /*getContentResolver*/ StrEnc("E8X\\7r7ys_Q%JS+L+~", "\x22\x5D\x2C\x1F\x58\x1C\x43\x1C\x1D\x2B\x03\x40\x39\x3C\x47\x3A\x4E\x0C", 18).c_str(), /*()Landroid/content/ContentResolver;*/ StrEnc("8^QKmj< }5D:9q7f.BXkef]A*GYLNg}B!/L", "\x10\x77\x1D\x2A\x03\x0E\x4E\x4F\x14\x51\x6B\x59\x56\x1F\x43\x03\x40\x36\x77\x28\x0A\x08\x29\x24\x44\x33\x0B\x29\x3D\x08\x11\x34\x44\x5D\x77", 35).c_str());
	jclass settingSecureClass = env->FindClass(/*android/provider/Settings$Secure*/ StrEnc("T1yw^BCF^af&dB_@Raf}\\FS,zT~L(3Z\"", "\x35\x5F\x1D\x05\x31\x2B\x27\x69\x2E\x13\x09\x50\x0D\x26\x3A\x32\x7D\x32\x03\x09\x28\x2F\x3D\x4B\x09\x70\x2D\x29\x4B\x46\x28\x47", 32).c_str());
	jmethodID getStringMethod = env->GetStaticMethodID(settingSecureClass, /*getString*/ StrEnc("e<F*J5c0Y", "\x02\x59\x32\x79\x3E\x47\x0A\x5E\x3E", 9).c_str(), /*(Landroid/content/ContentResolver;Ljava/lang/String;)Ljava/lang/String;*/ StrEnc("$6*%R*!XO\"m18o,0S!*`uI$IW)l_/_knSdlRiO1T`2sH|Ouy__^}%Y)JsQ:-\"(2_^-$i{?H", "\x0C\x7A\x4B\x4B\x36\x58\x4E\x31\x2B\x0D\x0E\x5E\x56\x1B\x49\x5E\x27\x0E\x69\x0F\x1B\x3D\x41\x27\x23\x7B\x09\x2C\x40\x33\x1D\x0B\x21\x5F\x20\x38\x08\x39\x50\x7B\x0C\x53\x1D\x2F\x53\x1C\x01\x0B\x36\x31\x39\x46\x0C\x15\x43\x2B\x05\x30\x15\x41\x43\x46\x55\x70\x0D\x59\x56\x00\x15\x58\x73", 71).c_str());
	auto obj = env->CallObjectMethod(context, getContentResolverMethod);
	auto str = (jstring) env->CallStaticObjectMethod(settingSecureClass, getStringMethod, obj, env->NewStringUTF(/*android_id*/ StrEnc("ujHO)8OfOE", "\x14\x04\x2C\x3D\x46\x51\x2B\x39\x26\x21", 10).c_str()));
	return env->GetStringUTFChars(str, 0);
}
const char *GetDeviceModel(JNIEnv *env) {
	jclass buildClass = env->FindClass(/*android/os/Build*/ StrEnc("m5I{GKGWBP-VOxkA", "\x0C\x5B\x2D\x09\x28\x22\x23\x78\x2D\x23\x02\x14\x3A\x11\x07\x25", 16).c_str());
	jfieldID modelId = env->GetStaticFieldID(buildClass, /*MODEL*/ StrEnc("|}[q:", "\x31\x32\x1F\x34\x76", 5).c_str(), /*Ljava/lang/String;*/ StrEnc(".D:C:ETZ1O-Ib&^h.Y", "\x62\x2E\x5B\x35\x5B\x6A\x38\x3B\x5F\x28\x02\x1A\x16\x54\x37\x06\x49\x62", 18).c_str());
	auto str = (jstring) env->GetStaticObjectField(buildClass, modelId);
	return env->GetStringUTFChars(str, 0);
}
const char *GetDeviceBrand(JNIEnv *env) {
	jclass buildClass = env->FindClass(/*android/os/Build*/ StrEnc("0iW=2^>0zTRB!B90", "\x51\x07\x33\x4F\x5D\x37\x5A\x1F\x15\x27\x7D\x00\x54\x2B\x55\x54", 16).c_str());
	jfieldID modelId = env->GetStaticFieldID(buildClass, /*BRAND*/ StrEnc("@{[FP", "\x02\x29\x1A\x08\x14", 5).c_str(), /*Ljava/lang/String;*/ StrEnc(".D:C:ETZ1O-Ib&^h.Y", "\x62\x2E\x5B\x35\x5B\x6A\x38\x3B\x5F\x28\x02\x1A\x16\x54\x37\x06\x49\x62", 18).c_str());
	auto str = (jstring) env->GetStaticObjectField(buildClass, modelId);
	return env->GetStringUTFChars(str, 0);
}
const char *GetPackageName(JNIEnv *env, jobject context) {
	jclass contextClass = env->FindClass(/*android/content/Context*/ StrEnc("`L+&0^[S+-:J^$,r9q92(as", "\x01\x22\x4F\x54\x5F\x37\x3F\x7C\x48\x42\x54\x3E\x3B\x4A\x58\x5D\x7A\x1E\x57\x46\x4D\x19\x07", 23).c_str());
	jmethodID getPackageNameId = env->GetMethodID(contextClass, /*getPackageName*/ StrEnc("YN4DaP)!{wRGN}", "\x3E\x2B\x40\x14\x00\x33\x42\x40\x1C\x12\x1C\x26\x23\x18", 14).c_str(), /*()Ljava/lang/String;*/ StrEnc("VnpibEspM(b]<s#[9cQD", "\x7E\x47\x3C\x03\x03\x33\x12\x5F\x21\x49\x0C\x3A\x13\x20\x57\x29\x50\x0D\x36\x7F", 20).c_str());
	auto str = (jstring) env->CallObjectMethod(context, getPackageNameId);
	return env->GetStringUTFChars(str, 0);
}
const char *GetDeviceUniqueIdentifier(JNIEnv *env, const char *uuid) {
	jclass uuidClass = env->FindClass(/*java/util/UUID*/ StrEnc("B/TxJ=3BZ_]SFx", "\x28\x4E\x22\x19\x65\x48\x47\x2B\x36\x70\x08\x06\x0F\x3C", 14).c_str());
	auto len = strlen(uuid);
	jbyteArray myJByteArray = env->NewByteArray(len);
	env->SetByteArrayRegion(myJByteArray, 0, len, (jbyte *) uuid);
	jmethodID nameUUIDFromBytesMethod = env->GetStaticMethodID(uuidClass, /*nameUUIDFromBytes*/ StrEnc("P6LV|'0#A+zQmoat,", "\x3E\x57\x21\x33\x29\x72\x79\x67\x07\x59\x15\x3C\x2F\x16\x15\x11\x5F", 17).c_str(), /*([B)Ljava/util/UUID;*/ StrEnc("sW[\"Q[W3,7@H.vT0) xB", "\x5B\x0C\x19\x0B\x1D\x31\x36\x45\x4D\x18\x35\x3C\x47\x1A\x7B\x65\x7C\x69\x3C\x79", 20).c_str());
	jmethodID toStringMethod = env->GetMethodID(uuidClass, /*toString*/ StrEnc("2~5292eW", "\x46\x11\x66\x46\x4B\x5B\x0B\x30", 8).c_str(), /*()Ljava/lang/String;*/ StrEnc("P$BMc' #j?<:myTh_*h0", "\x78\x0D\x0E\x27\x02\x51\x41\x0C\x06\x5E\x52\x5D\x42\x2A\x20\x1A\x36\x44\x0F\x0B", 20).c_str());
	auto obj = env->CallStaticObjectMethod(uuidClass, nameUUIDFromBytesMethod, myJByteArray);
	auto str = (jstring) env->CallObjectMethod(obj, toStringMethod);
	return env->GetStringUTFChars(str, 0);
}

#include <curl/curl.h>
struct MemoryStruct {
	char *memory;
	size_t size;
};

static size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp) {
	size_t realsize = size * nmemb;
	struct MemoryStruct *mem = (struct MemoryStruct *) userp;
	mem->memory = (char *) realloc(mem->memory, mem->size + realsize + 1);
	if (mem->memory == NULL) {
		return 0;
	}
	memcpy(&(mem->memory[mem->size]), contents, realsize);
	mem->size += realsize;
	mem->memory[mem->size] = 0;
	return realsize;
}

void native_Init(JNIEnv *env, jclass clazz, jobject mContext) {
    auto pkgName = GetPackageName(env, mContext);
   // StartRuntimeHook(pkgName);
  //    pthread_t t;       
    //pthread_create(&t, 0, Init_Thread, 0);
}


jstring native_Check(JNIEnv *env, jclass clazz, jobject mContext, jstring mUserKey) {
    auto userKey = env->GetStringUTFChars(mUserKey, 0);
    std::string hwid = userKey;
    hwid += GetAndroidID(env, mContext);
    hwid += GetDeviceModel(env);
    hwid += GetDeviceBrand(env);
    std::string UUID = GetDeviceUniqueIdentifier(env, hwid.c_str());

    std::string errMsg;
    struct MemoryStruct chunk{};
    chunk.memory = (char *) malloc(1);
    chunk.size = 0;
    CURL *curl;
    CURLcode res;
    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, _enc_("POST"));
        curl_easy_setopt(curl, CURLOPT_URL, _enc_("https://freepanel.in/connect"));

        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, _enc_("https"));

        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers,
                                    _enc_("Content-Type: application/x-www-form-urlencoded"));
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        char data[4096];
        sprintf(data, _enc_("game=PUBG&user_key=%s&serial=%s"), userKey, UUID.c_str());
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);

        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *) &chunk);

        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);

        res = curl_easy_perform(curl);
        if (res == CURLE_OK) {
            try {
                json result = json::parse(chunk.memory);
                if (result[("status")] == true) {
                    std::string token = result[("data")][("token")].get<std::string>();
                    auto rng = result[("data")][("rng")].get<time_t>();
                    if (rng + 30 > time(0)) {
                        std::string auth = enc("PUBG");
                        auth += "-";
                        auth += userKey;
                        auth += "-";
                        auth += UUID;
                        auth += "-";
                        auth += enc("Vm8Lk7Uj2JmsjCPVPVjrLa7zgfx3uz9E");
                        std::string outputAuth = Tools::CalcMD5(auth);
                        g_Token = token;
                        g_Auth = outputAuth;
                        auto EXP = result["data"]["EXP"].get<std::string>();
                        bValid = g_Token == g_Auth;

                    }
                } else {
                    errMsg = result[("reason")].get<std::string>();
                }
            } catch (json::exception &e) {
                errMsg = e.what();
            }
        } else {
            errMsg = curl_easy_strerror(res);
        }
    }
    curl_easy_cleanup(curl);
    return bValid ? env->NewStringUTF("OK") : env->NewStringUTF(errMsg.c_str());

}


extern "C"
JNIEXPORT void JNICALL
Java_com_bearmod_Floating_Switch(JNIEnv *env, jobject thiz, jint i) {
    // TODO: implement Switch()
}
