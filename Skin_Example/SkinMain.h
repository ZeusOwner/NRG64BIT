
#include "skin.h"
#include "skin_data.h"


bool UpdateClothSkin(UCharacterAvatarComponent2*);
using on_change_callback = void(*)(int);

ASTExtraVehicleBase* lastVehicle = nullptr;
bool isModded = false, isLoggedIn = false;
static DWORD Last_Gun_Used_To_Kill = 0, Current_Weapon = 0;
static std::string package_name = "";

int ReceiveDrawHUD_Index = -1, OnRep_AvatarMeshChanged_Index = -1, OnRep_BodySlotStateChanged_Index = -1;
int GetItemAvatarHandle_Index = -1, CreateBattleItemHandle_Index = -1, CreateWeaponAndChangeSkin_Index = -1;
int DeadBoxAvatarComponent_Index = -1, DeadBoxAvatarComponent_GetLuaFilePath_Index = -1;

template<typename T>
bool Write(DWORD address, T value) {
    KittyMemory::ProtectAddr((void*)address, sizeof(T), PROT_READ | PROT_EXEC);
    return KittyMemory::memWrite((void*)address, &value, sizeof(T)) == KittyMemory::Memory_Status::SUCCESS;
}

int GetWeap(int w) {
    static const std::unordered_map<int, int> weaponMap = {
        {ID_AKM, skin.gun->AKM}, {ID_M16A4, skin.gun->M16A4}, {ID_SCARL, skin.gun->SCARL}, {ID_M416, skin.gun->M416},
        {ID_AUG, skin.gun->AUG}, {ID_ACE32, skin.gun->ACE32}, {ID_M762, skin.gun->M762}, {ID_QBZ, skin.gun->QBZ},
        {ID_GROZA, skin.gun->GROZA}, {ID_HONEY_BADGER, skin.gun->HONEY}, {ID_UMP45, skin.gun->UMP45},
        {ID_VECTOR, skin.gun->VECTOR}, {ID_THOMPSON, skin.gun->TOMMY}, {ID_UZI, skin.gun->UZI}, {ID_PP19, skin.gun->PP19},
        {ID_AWM, skin.gun->AWM}, {ID_AMR, skin.gun->AMR}, {ID_M24, skin.gun->M24}, {ID_KAR98K, skin.gun->KAR98},
        {ID_MK14, skin.gun->MK14}, {ID_MINI14, skin.gun->MINI14}, {ID_M249, skin.gun->M249}, {ID_DP28, skin.gun->DP28},
        {ID_PAN, skin.gun->PAN}, {ID_M1014, skin.gun->XM1014}, {ID_DBS, skin.gun->DBS}, {ID_S12K, skin.gun->S12K},
        {ID_MG3, skin.gun->MG3}, {ID_P90, skin.gun->P90}
    };
    return weaponMap.count(w) ? weaponMap.at(w) : 0;
}

struct Gun {
    DWORD GUN, flash, compe, silent, quickmag, extmag, quickextmag, canced, reddot, holo, X2, X3, X4, X6, X8,
          vertical, angle, light, pink, lazer, thumb, stock, pak, bullet;

    void ChangeSkin(ASTExtraWeapon* gun) {
        auto data = gun->synData;
        if (data.Num() < 6 || data[7].DefineID.TypeSpecificID <= 0) return;

        data[7].DefineID.TypeSpecificID = GUN;

        auto updateAttachment = [&](int index, DWORD value, const std::vector<int>& validIds) {
            if (value > 0 && data[index].DefineID.TypeSpecificID > 0 && 
                std::find(validIds.begin(), validIds.end(), data[index].DefineID.TypeSpecificID) != validIds.end()) {
                data[index].DefineID.TypeSpecificID = value;
            }
        };

        updateAttachment(0, flash, {201010, 201005, 201004});
        updateAttachment(0, compe, {201009, 201003, 201002});
        updateAttachment(0, silent, {201011, 201007, 201006});
        updateAttachment(4, canced, {203018});
        updateAttachment(4, reddot, {203001});
        updateAttachment(4, holo, {203002});
        updateAttachment(4, X2, {203003});
        updateAttachment(4, X3, {203014});
        updateAttachment(4, X4, {203004});
        updateAttachment(4, X6, {203015});
        updateAttachment(4, X8, {203005});
        updateAttachment(2, quickmag, {204012, 204005, 204008});
        updateAttachment(2, extmag, {204011, 204004, 204007});
        updateAttachment(2, quickextmag, {204013, 204006, 204009});
        updateAttachment(1, vertical, {202002});
        updateAttachment(1, angle, {202001});
        updateAttachment(1, light, {202004});
        updateAttachment(1, pink, {202005});
        updateAttachment(1, lazer, {202007});
        updateAttachment(1, thumb, {202006});
        if (stock > 0 && data[3].DefineID.TypeSpecificID > 0) data[3].DefineID.TypeSpecificID = stock;
        updateAttachment(5, pak, {205003});
        updateAttachment(5, bullet, {204014});
    }

    std::string ToString() {
        char a[512];
        sprintf(a, "GUN: %d, flash: %d, compe: %d, silent: %d, quick: %d, extmag: %d, quickextmag: %d, canced: %d, reddot: %d, holo: %d, X2: %d, X3: %d, X4: %d, X6: %d, X8: %d, vertical: %d, angel: %d, light: %d, pink: %d, lazer: %d, thumb: %d, stock: %d, pak: %d, bullet: %d",
                GUN, flash, compe, silent, quickmag, extmag, quickextmag, canced, reddot, holo, X2, X3, X4, X6, X8, vertical, angle, light, pink, lazer, thumb, stock, pak, bullet);
        return std::string(a);
    }
};

Gun GetFullWeapon(DWORD id) {
    static const std::unordered_map<DWORD, Gun> skinMap = {
        // M416 Skins
        {1101004046, {1101004046, 1010040474, 1010040475, 1010040476, 1010040471, 1010040472, 1010040473, 1010040485, 1010040470, 1010040469, 1010040468, 1010040467, 1010040466, 1010040481, 0, 1010040479, 1010040477, 1010040482, 1010040478, 1010040484, 1010040483, 1010040480, 0, 0}}, // Băng Giá
        {1101004062, {1101004062, 1010040578, 1010040577, 1010040579, 1010040575, 1010040570, 1010040576, 1010040590, 1010040569, 1010040568, 1010040567, 1010040566, 1010040565, 1010040564, 0, 1010040585, 1010040580, 1010040587, 1010040588, 1010040483, 1010040589, 1010040586, 0, 0}}, // Chú Hề
        {1101004226, {1101004226, 1010042238, 1010042237, 1010042239, 1010042235, 1010042234, 1010042236, 1010042248, 1010042233, 1010042232, 1010042231, 1010042219, 1010042218, 1010042217, 0, 1010042243, 1010042241, 1010042245, 1010042246, 1010042247, 1010042242, 1010042244, 0, 0}}, // Xác Ướp
        {1101004236, {1101004236, 1010042307, 1010042306, 1010042308, 1010042304, 1010042300, 1010042305, 1010042319, 1010042299, 1010042298, 1010042297, 1010042296, 1010042295, 1010042294, 0, 1010042314, 1010042309, 1010042316, 1010042317, 1010042318, 1010042310, 1010042315, 0, 0}}, // Lam Sư Đoạt Mệnh
        {1101004201, {1101004201, 1010041956, 1010041957, 1010041958, 1010041949, 1010041950, 1010041955, 0, 1010041948, 1010041947, 1010041946, 1010041945, 1010041944, 1010041967, 0, 1010041965, 1010041959, 0, 0, 0, 1010041960, 1010041966, 0, 0}}, // Bạch Lân
        {1101004209, {1101004209, 1010042038, 1010042037, 1010042039, 1010042034, 1010042035, 1010042036, 1010042055, 1010042029, 1010042028, 1010042027, 1010042026, 1010042025, 1010042024, 0, 1010042046, 1010042044, 1010042048, 1010042049, 1010042054, 1010042045, 1010042047, 0, 0}}, // Thủy Triều
        {1101004218, {1101004218, 1010042128, 1010042127, 1010042129, 1010042124, 1010042125, 1010042126, 1010042145, 1010042119, 1010042118, 1010042117, 1010042116, 1010042115, 1010042114, 0, 1010042136, 1010042134, 1010042138, 1010042139, 1010042144, 1010042135, 1010042137, 0, 0}}, // Ma Ảnh

        // AKM Skins
        {1101001213, {1101001213, 1010012067, 1010012068, 1010012069, 1010012072, 1010012070, 1010012073, 0, 1010012066, 1010012065, 1010012064, 1010012063, 1010012062, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // Đô Đốc Hải Trình
        {1101001231, {1101001231, 1010012267, 1010012268, 1010012269, 1010012273, 1010012272, 1010012274, 1010012275, 1010012266, 1010012265, 1010012264, 1010012263, 1010012262, 1010012276, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // Thỏ Tinh Nghịch
        {1101001242, {1101001242, 1010012357, 1010012357, 1010012359, 1010012363, 1010012362, 1010012364, 1010012365, 1010012356, 1010012355, 1010012354, 1010012353, 1010012352, 1010012366, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // Ngày Phán Quyết
        {1101001256, {1101001256, 1010012507, 1010012508, 1010012509, 1010012513, 1010012512, 1010012514, 1010012515, 1010012506, 1010012505, 1010012504, 1010012503, 1010012502, 1010012516, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // Thánh Quang (Lông Vũ)
        {1101001249, {1101001249, 1010012437, 1010012438, 1010012439, 1010012443, 1010012442, 1010012444, 1010012445, 1010012436, 1010012435, 1010012434, 1010012433, 1010012432, 1010012446, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // Thánh Quang (Trăng Thần)

        // Scar-L Skins
        {1101003167, {1101003167, 1010031609, 1010031610, 1010031613, 1010031608, 1010031607, 1010031617, 1010031623, 1010031606, 1010031605, 1010031604, 1010031603, 1010031602, 1010031618, 0, 1010031615, 1010031614, 1010031620, 1010031622, 1010031619, 1010031616, 0, 0, 0}}, // Ma Vương Huyết Hồn
        {1101003181, {1101003181, 1010031765, 1010031764, 1010031766, 1010031759, 1010031758, 1010031763, 1010031775, 1010031757, 1010031756, 1010031755, 1010031754, 1010031753, 1010031752, 0, 1010031769, 1010031767, 1010031773, 1010031774, 1010031772, 1010031768, 0, 0, 0}}, // Cái Ôm Của Hề
        {1101003195, {1101003195, 1010031912, 1010031911, 1010031913, 1010031908, 1010031907, 1010031909, 1010031921, 1010031906, 1010031905, 1010031904, 1010031903, 1010031902, 1010031901, 0, 1010031916, 1010031914, 1010031918, 1010031919, 1010031917, 1010031915, 0, 0, 0}}, // Thánh Nữ Huyền Ảo
        {1101003208, {1101003208, 1010032034, 1010032033, 1010032045, 1010032029, 1010032028, 1010032032, 0, 1010032027, 1010032026, 1010032025, 1010032024, 1010032023, 1010032022, 0, 1010032038, 1010032036, 1010032042, 1010032043, 1010032039, 1010032037, 0, 0, 0}}, // Vương Quốc Huyền Ảo

        // AUG Skins
        {1101006062, {1101006062, 1010060573, 1010060572, 1010060574, 1010060564, 1010060563, 1010060565, 1010060593, 1010060562, 1010060561, 1010060554, 1010060553, 1010060552, 1010060551, 0, 1010060583, 1010060581, 1010060591, 1010060592, 1010060584, 1010060582, 0, 0, 0}}, // Tinh Linh Băng Giá
        {1101006075, {1101006075, 1010060702, 1010060701, 1010060703, 1010060698, 1010060697, 1010060699, 1010060711, 1010060696, 1010060695, 1010060694, 1010060693, 1010060692, 1010060691, 0, 1010060706, 1010060704, 1010060708, 1010060709, 1010060707, 1010060705, 0, 0, 0}}, // Hoả Ca

        // M762 Skins
        {1101008126, {1101008126, 1010081210, 1010081213, 1010081215, 1010081208, 1010081207, 1010081209, 0, 1010081206, 1010081205, 1010081204, 1010081203, 1010081202, 1010081218, 0, 1010081217, 1010081216, 0, 0, 0, 1010081214, 0, 0, 0}}, // Huyết Rồng
        {1101008136, {1101008136, 1010081314, 1010081315, 1010081316, 1010081312, 1010081308, 1010081313, 1010081326, 1010081307, 1010081306, 1010081305, 1010081304, 1010081303, 1010081302, 0, 1010081318, 1010081317, 1010081322, 1010081323, 1010081325, 1010081324, 0, 0, 0}}, // Tiên Linh Lưu Ly
        {1101008146, {1101008146, 1010081401, 1010081402, 1010081403, 1010081398, 1010081397, 1010081399, 1010081411, 1010081396, 1010081395, 1010081394, 1010081393, 1010081392, 1010081391, 0, 1010081405, 1010081404, 1010081406, 1010081407, 1010081409, 1010081408, 0, 0, 0}}, // Bạch Cốt U Minh
        {1101008154, {1101008154, 1010081531, 1010081532, 1010081533, 1010081527, 1010081528, 1010081529, 1010081411, 1010081526, 1010081525, 1010081524, 1010081523, 1010081522, 1010081521, 0, 1010081541, 1010081534, 1010081542, 1010081543, 1010081545, 1010081544, 0, 0, 0}}, // Khung Xương

        // ACE32 Skins
        {1101102007, {1101102007, 1011020027, 1011020028, 1011020029, 1011020025, 1011020024, 1011020026, 1011020045, 1011020019, 1011020018, 1011020017, 1011020016, 1011020015, 1011020014, 0, 1011020036, 1011020034, 1011020038, 1011020039, 1011020044, 1011020035, 1011020037, 0, 0}}, // KameKameHa
        {1101102017, {1011020127, 1011020127, 1011020128, 1011020129, 1011020125, 1011020124, 1011020126, 1011020145, 1011020119, 1011020118, 1011020117, 1011020116, 1011020115, 1011020114, 0, 1011020136, 1011020134, 1011020138, 1011020139, 1011020144, 1011020135, 1011020137, 0, 0}}, // Ngọc Bích
        {1101102025, {1101102025, 1011020214, 1011020215, 1011020216, 1011020212, 1011020211, 1011020213, 1011020225, 1011020209, 1011020208, 1011020207, 1011020206, 1011020205, 1011020204, 0, 1011020219, 1011020217, 1011020222, 1011020223, 1011020224, 1011020218, 1011020221, 0, 0}}, // Thủy Quái

        // QBZ Skins
        {1101007046, {1101007046, 1010070410, 1010070413, 1010070414, 1010070408, 1010070407, 1010070409, 0, 1010070406, 1010070405, 1010070404, 1010070403, 1010070402, 1011020204, 0, 1010070416, 1010070415, 0, 0, 0, 1010070417, 0, 0, 0}}, // Công Chúa
        {1101007062, {1101007062, 1010070579, 1010070578, 1010070581, 1010070576, 1010070575, 1010070577, 1010070588, 1010070406, 1010070405, 1010070404, 1010070403, 1010070402, 1011020204, 0, 1010070584, 1010070582, 1010070585, 1010070586, 1010070587, 1010070583, 0, 0, 0}}, // Hoa Kiếm Chí Mạng
        {1101007071, {1101007071, 1010070663, 1010070662, 1010070664, 1010070659, 1010070658, 1010070660, 1010070588, 1010070657, 1010070656, 1010070655, 1010070654, 1010070653, 1010070652, 0, 1010070667, 1010070665, 1010070668, 1010070669, 1010070670, 1010070666, 0, 0, 0}}, // Thiên Mệnh

        // Uzi Skins
        {1102001120, {1102001120, 1020011137, 1020011138, 1020011139, 1020011135, 1020011134, 1020011136, 0, 1020011133, 1020011132, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1020011142, 0, 0}}, // Băng Giá

        // UMP45 Skins
        {1102002136, {1102002136, 1020021314, 1020021313, 1020021315, 1020021309, 1020021308, 1020021312, 1020021325, 1020021307, 1020021306, 1020021305, 1020021304, 1020021303, 1020021302, 0, 1020021318, 1020021316, 1020021323, 1020021324, 1020021322, 1020021317, 0, 0, 0}}, // Băng Giá

        // Vector Skins
        {1102003080, {1102003080, 1020030755, 1020030756, 1020030758, 1020030750, 1020030749, 1020030754, 0, 1020030748, 1020030747, 1020030746, 1020030745, 1020030744, 1020030764, 0, 1020030760, 0, 1020030759, 1020030757, 0, 0, 1020030765, 0, 0}}, // Cánh Rồng

        // Kar98K Skins
        {1103001179, {1103001179, 1030011738, 1030011739, 1030011741, 0, 0, 0, 1030011743, 1030011737, 1030011736, 1030011735, 1030011734, 1030011733, 1030011732, 1030011731, 0, 0, 0, 0, 0, 0, 0, 1030011742, 1030011744}}, // Điện Cực Tím
        {1103001191, {1103001191, 1030011858, 1030011859, 1030011851, 0, 0, 0, 1030011863, 1030011857, 1030011856, 1030011855, 1030011854, 1030011853, 1030011852, 1030011851, 0, 0, 0, 0, 0, 0, 0, 1030011862, 1030011864}}, // Hồng Hoả Diệm

        // M24 Skins
        {1103002087, {1103002087, 1030020824, 1030020825, 1030020826, 0, 0, 0, 1030020828, 1030020818, 1030020817, 1030020816, 1030020815, 1030020814, 1030020813, 1030020812, 0, 0, 0, 0, 0, 0, 0, 1030020827, 0}}, // Nhịp Điệu Hoàn Mỹ

        // AWM Skins
        {1103003087, {1103003087, 1030030825, 1030030826, 1030030827, 1030030823, 1030030822, 1030030824, 1030030819, 1030030818, 1030030817, 1030030816, 1030030815, 1030030814, 1030030813, 1030030812, 0, 0, 0, 0, 0, 0, 0, 1030030828, 0}}, // Thanh Hoa Xà

        // AMR Skins
        {1103012010, {1103012010, 0, 0, 0, 0, 0, 0, 0, 1030120038, 1030120037, 1030120036, 1030120035, 1030120034, 1030120033, 1030120032, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // Khủng Long
        {1103012019, {1103012019, 0, 0, 0, 0, 0, 0, 0, 1030120138, 1030120137, 1030120136, 1030120135, 1030120134, 1030120133, 1030120132, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // Hoả Thần
        {1103012031, {1103012031, 0, 0, 0, 0, 0, 0, 0, 1030120258, 1030120257, 1030120256, 1030120255, 1030120254, 1030120253, 1030120252, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // Vô Âm Ly Biệt

        // Mk14 Skins
        {1103007028, {1103007028, 1030070228, 1030070228, 1030070232, 1030070223, 1030070222, 1030070224, 1030070219, 1030070218, 1030070217, 1030070216, 1030070215, 1030070214, 1030070213, 1030070212, 0, 0, 0, 0, 0, 0, 0, 1030070236, 0}}, // Rồng

        // MG3 Skins
        {1105010019, {1105010019, 0, 0, 0, 0, 0, 0, 0, 1050100144, 1050100143, 1050100142, 1050100141, 1050100139, 1050100138, 0, 0, 0, 0, 0, 0, 0, 0, 1030070236, 0}} // Chiến Thần Bầu Trời
    };
    return skinMap.count(id) ? skinMap.at(id) : Gun{id};
}

void ChangeGunSkin(ASTExtraWeapon* gun) {
    if (isObjectInvalid(gun) || gun->Owner != Data::localPlayer) return;
    int newid = gun->GetWeaponID(), newgun = GetWeap(newid);
    if (newgun > 0) GetFullWeapon(newgun).ChangeSkin(gun);
}

template<typename T>
void GetAllActors(std::vector<T*>& Trace) {
    UGameplayStatics* gGameplayStatics = (UGameplayStatics*)gGameplayStatics->StaticClass();
    auto GWorld = GetFullWorld();
    if (!GWorld || !GWorld->PersistentLevel) return;

    TArray<AActor*> Actors;
    gGameplayStatics->GetAllActorsOfClass((UObject*)GWorld, T::StaticClass(), &Actors);
    Trace.clear();
    for (int i = 0; i < Actors.Num(); i++) {
        if (Actors[i] && Actors[i]->IsA(T::StaticClass())) Trace.push_back((T*)Actors[i]);
    }
}

bool carspring = false;
std::string item_separated_by_zero(std::vector<FSkinItem> skins) {
    std::string out;
    if (skins.empty()) return out; // Trả về chuỗi rỗng nếu không có mục nào
    for (size_t i = 0; i < skins.size(); i++) {
        out += skins[i].name;
        out += '\0'; // Thêm ký tự null sau mỗi mục
    }
    // Đảm bảo chuỗi kết thúc bằng \0 (ImGui yêu cầu chuỗi kết thúc bằng \0\0, nhưng vòng lặp đã đủ)
    return out;
}

void RenderSkinItem(std::string label, CSkinsInfo& skins, on_change_callback cb = nullptr) {
    ImGui::TableNextRow(); // Bắt đầu một hàng mới

    // Cột 0: Combo box
    ImGui::TableSetColumnIndex(0);
    std::string combo_label = "##" + label + "##combo";
    ImGui::PushItemWidth(120); // Đặt chiều rộng cố định cho Combo
    if (!skins.items.empty()) {
        const char* items_str = item_separated_by_zero(skins.items).c_str();
        if (ImGui::Combo(combo_label.c_str(), &skins.current_index, items_str)) {
            if (skins.out) {
                *skins.out = skins.Get(); // Cập nhật giá trị khi thay đổi
            }
        }
    } else {
        ImGui::Text("No items"); // Hiển thị thông báo nếu danh sách rỗng
    }
    ImGui::PopItemWidth(); // Khôi phục trạng thái sau khi dùng PushItemWidth

    // Cột 1: Nhãn
    ImGui::TableSetColumnIndex(1);
    ImGui::Text(label.c_str());

    // Cột 2: Input số
    ImGui::TableSetColumnIndex(2);
    std::string input_label = "##" + label + "##input";
    if (skins.out) {
        ImGui::PushItemWidth(80); // Đặt chiều rộng cố định cho InputScalar
        ImGui::InputScalar(input_label.c_str(), ImGuiDataType_U32, skins.out);
        ImGui::PopItemWidth(); // Khôi phục trạng thái
    }
}
bool UpdateClothSkin(UCharacterAvatarComponent2 *avatar)
{
    if (!Data::localPlayer)
        return false;
    if (!Data::localPlayer->AvatarComponent2)
        return false;
    if (avatar != Data::localPlayer->AvatarComponent2)
        return false;
    FNetAvatarSyncData NetAvatarComp = *(FNetAvatarSyncData *)((uintptr_t)avatar + Data::Offset::NetAvatarSyncData);
  auto slot = NetAvatarComp.SlotSyncData;
  for (int i = 0; i < slot.Num(); i++)
    {
        auto& id = slot[i].ItemId;
        auto sl = slot[i].SlotID;
  
        if(sl == 3 && skin.cloth->HAT > 0) //hat
        {
            id = skin.cloth->HAT;
        }
        if(sl == 5 && skin.cloth->SHIRT > 0) // cloth
        {
            id = skin.cloth->SHIRT;
        }
        if(sl == 6 && skin.cloth->PANT > 0) //pant
        {
            id = skin.cloth->PANT;
        }
        if(sl == 7 && skin.cloth->SHOE > 0) //shoe
        {
            id = skin.cloth->SHOE;
        }
    switch (id) {
        case  502004:
        case  502001:
        case  502110:
        case  502107:
        case  502104:
    if(sl == 9 && id > 0 && skin.cloth->HELMET1 > 0) //helmet
    {
      id = skin.cloth->HELMET1;
    } break; }
    switch (id) {
        case 502005:
        case 502002:
        case 502111:
        case 502108:
        case 502105:
    if(sl == 9 && id > 0 && skin.cloth->HELMET2 > 0) //helmet
    {
     id = skin.cloth->HELMET2;
    } break; }
    switch (id) {
        case 502106:
        case 502109:
        case 502112:
        case 502003:
    if(sl == 9 && id > 0 && skin.cloth->HELMET3 > 0) //helmet
    {
      id = skin.cloth->HELMET3;
    } break; }
    switch (id) {
        case 501001:
        case 501004:
        case 501007:
        case 501010:
        case 501101:
        case 501104:
    if(sl == 8 && id > 0 && skin.cloth->BACKPACK1 > 0) //backpack
    {
      id = skin.cloth->BACKPACK1;
    } break; }
    switch (id) {
        case  501002:
        case  501005:
        case  501008:
        case  501011:
        case  501102:
        case  501105:
    if(sl == 8 && id > 0 && skin.cloth->BACKPACK2 > 0) //backpack
    {
       id = skin.cloth->BACKPACK2;
    } break; }
    switch (id) {
        case 501006:
        case 501003:
        case 501009:
        case 501012:
        case 501015:
        case 501106:
        case 501103:
    if(sl == 8 && id > 0 && skin.cloth->BACKPACK3 > 0) //backpack
    {
      id = skin.cloth->BACKPACK3;
    } break; }
        if(sl == 11 && id > 0 && skin.cloth->PARACHUTE > 0) //para
        {
            id = skin.cloth->PARACHUTE;
        }
        if(sl == 15 && skin.cloth->GLIDER > 0) //glide
        {
            id = skin.cloth->GLIDER;
        }
   }
    return true;
}

bool UpdateClothSkinLobby(UCharacterAvatarComponent2 *avatar)
{
    FNetAvatarSyncData NetAvatarComp = *(FNetAvatarSyncData *)((uintptr_t)avatar + Data::Offset::NetAvatarSyncData);
  auto slot = NetAvatarComp.SlotSyncData;
  for (int i = 0; i < slot.Num(); i++)
    {
        auto& id = slot[i].ItemId;
        auto sl = slot[i].SlotID;
  
        if(sl == 3 && skin.cloth->HAT > 0) //hat
        {
            id = skin.cloth->HAT;
        }
        if(sl == 5 && skin.cloth->SHIRT > 0) // cloth
        {
            id = skin.cloth->SHIRT;
        }
        if(sl == 6 && skin.cloth->PANT > 0) //pant
        {
            id = skin.cloth->PANT;
        }
        if(sl == 7 && skin.cloth->SHOE > 0) //shoe
        {
            id = skin.cloth->SHOE;
        }
    switch (id) {
        case  502004:
        case  502001:
        case  502110:
        case  502107:
        case  502104:
    if(sl == 9 && id > 0 && skin.cloth->HELMET1 > 0) //helmet
    {
      id = skin.cloth->HELMET1;
    } break; }
    switch (id) {
        case 502005:
        case 502002:
        case 502111:
        case 502108:
        case 502105:
    if(sl == 9 && id > 0 && skin.cloth->HELMET2 > 0) //helmet
    {
     id = skin.cloth->HELMET2;
    } break; }
    switch (id) {
        case 502106:
        case 502109:
        case 502112:
        case 502003:
    if(sl == 9 && id > 0 && skin.cloth->HELMET3 > 0) //helmet
    {
      id = skin.cloth->HELMET3;
    } break; }
    switch (id) {
        case 501001:
        case 501004:
        case 501007:
        case 501010:
        case 501101:
        case 501104:
    if(sl == 8 && id > 0 && skin.cloth->BACKPACK1 > 0) //backpack
    {
      id = skin.cloth->BACKPACK1;
    } break; }
    switch (id) {
        case  501002:
        case  501005:
        case  501008:
        case  501011:
        case  501102:
        case  501105:
    if(sl == 8 && id > 0 && skin.cloth->BACKPACK2 > 0) //backpack
    {
       id = skin.cloth->BACKPACK2;
    } break; }
    switch (id) {
        case 501006:
        case 501003:
        case 501009:
        case 501012:
        case 501015:
        case 501106:
        case 501103:
    if(sl == 8 && id > 0 && skin.cloth->BACKPACK3 > 0) //backpack
    {
      id = skin.cloth->BACKPACK3;
    } break; }
        if(sl == 11 && id > 0 && skin.cloth->PARACHUTE > 0) //para
        {
            id = skin.cloth->PARACHUTE;
        }
        if(sl == 15 && skin.cloth->GLIDER > 0) //glide
        {
            id = skin.cloth->GLIDER;
        }
   }
   
    return true;
}

void(*orig_kill_message_event)(ASTExtraPlayerController*, FFatalDamageParameter*);
void kill_message_event(ASTExtraPlayerController* PlayerController, FFatalDamageParameter* FatalDamageParameter) {
    if (skin.bEnable && skin.bKillMsg && PlayerController->PlayerKey == FatalDamageParameter->CauserKey) {
        FatalDamageParameter->CauserClothAvatarID = skin.cloth->SHIRT;
        if (Last_Gun_Used_To_Kill > 0) FatalDamageParameter->CauserWeaponAvatarID = Last_Gun_Used_To_Kill;
    }
    if (Config.Memory.FakeName) {
        FatalDamageParameter->String.causerName = FString("(NBC)RAC");
        FatalDamageParameter->String.FuzzyCauserName = FString("(NBC)RAC");
        FatalDamageParameter->String.RealKillerName = FString("(NBC)RAC");
    }
    orig_kill_message_event(PlayerController, FatalDamageParameter);
}

void DrawMemory(UCanvas* Canvas, int ScreenWidth, int ScreenHeight) {
    static USTExtraGameInstance* FPS = nullptr;
    if (!FPS) FPS = UObject::FindObject<USTExtraGameInstance>("STExtraGameInstance Transient.UAEGameEngine_1.STExtraGameInstance_1");
    if (FPS) {
        auto& UserSettings = FPS->UserDetailSetting;
        UserSettings.PUBGDeviceFPSDef = UserSettings.PUBGDeviceFPSLow = UserSettings.PUBGDeviceFPSMid =
        UserSettings.PUBGDeviceFPSHigh = UserSettings.PUBGDeviceFPSHDR = UserSettings.PUBGDeviceFPSUltralHigh = Setting::FPS;
        UserSettings.DeviceMaxQualityLevel = 3;
    }

    if (!Canvas) return;

    auto GWorld = GetFullWorld();
    ASTExtraPlayerController* localController = nullptr;
    ASTExtraPlayerCharacter* localPlayer = nullptr;

    if (GWorld && GWorld->PersistentLevel && GWorld->NetDriver && GWorld->NetDriver->ServerConnection) {
        auto ServerConnection = GWorld->NetDriver->ServerConnection;
        localController = static_cast<ASTExtraPlayerController*>(ServerConnection->PlayerController);
        if (localController && localController->AcknowledgedPawn) {
            localPlayer = static_cast<ASTExtraPlayerCharacter*>(localController->AcknowledgedPawn);
        }
    }

    if (localController) {
        auto Actors = GetNecessaryActors();
        for (auto Actor : Actors) {
            if (!Actor) continue;
            if (Actor->IsA(ASTExtraPlayerCharacter::StaticClass())) {
                auto PlayerCharacter = static_cast<ASTExtraPlayerCharacter*>(Actor);
                if (PlayerCharacter->PlayerKey == localController->PlayerKey) {
                    localPlayer = PlayerCharacter;
                    break;
                }
            }
        }
    }

    Data::localController = localController;
    Data::localPlayer = localPlayer;

    if (!Data::localPlayer || !Data::localController) return;

    if (Data::localPlayer->PartHitComponent) {
        auto& ConfigCollisionDistSqAngles = Data::localPlayer->PartHitComponent->ConfigCollisionDistSqAngles;
        for (int j = 0; j < ConfigCollisionDistSqAngles.Num(); j++) ConfigCollisionDistSqAngles[j].Angle = 180.0f;
    }

    if (Config.Ragebot.Enable && Config.Ragebot.Aimtype == 0) {
        ASTExtraPlayerCharacter* Target = GetBestLineTarget();
        if (Target) {
            bool triggerOk = false;
            switch (Config.Ragebot.Trigger) {
                case EAimTrigger::Shooting: triggerOk = Data::localPlayer->bIsWeaponFiring; break;
                case EAimTrigger::Scoping: triggerOk = Data::localPlayer->bIsGunADS; break;
                case EAimTrigger::Both: triggerOk = Data::localPlayer->bIsWeaponFiring && Data::localPlayer->bIsGunADS; break;
                case EAimTrigger::Any: triggerOk = Data::localPlayer->bIsWeaponFiring || Data::localPlayer->bIsGunADS; break;
                case EAimTrigger::None: default: triggerOk = true; break;
            }

            if (triggerOk) {
                FVector targetAimPos = Target->GetBonePos("Head", {});
                if (Config.Ragebot.Target == EAimTarget::Auto) {
                    switch (AutoChooseTarget) {
                        case 1: targetAimPos = Target->GetBonePos("Head", {}); break;
                        case 2: targetAimPos = Target->GetBonePos("neck_01", {}); break;
                        case 3: targetAimPos = Target->GetBonePos("spine_03", {}); break;
                        case 4: targetAimPos = Target->GetBonePos("spine_02", {}); break;
                        case 5: targetAimPos = Target->GetBonePos("spine_01", {}); break;
                        case 6: targetAimPos = Target->GetBonePos("foot_l", {}); break;
                        case 7: targetAimPos = Target->GetBonePos("foot_r", {}); break;
                        case 8: targetAimPos = Target->GetBonePos("upper_l", {}); break;
                        case 9: targetAimPos = Target->GetBonePos("lowerarm_r", {}); break;
                        case 10: targetAimPos = Target->GetBonePos("thigh_l", {}); break;
                        case 11: targetAimPos = Target->GetBonePos("calf_l", {}); break;
                        case 12: targetAimPos = Target->GetBonePos("upper_r", {}); break;
                        case 13: targetAimPos = Target->GetBonePos("lowerarm_r", {}); break;
                        case 14: targetAimPos = Target->GetBonePos("thigh_r", {}); break;
                        case 15: targetAimPos = Target->GetBonePos("calf_r", {}); break;
                        default: targetAimPos = Target->GetBonePos("Head", {}); break;
                    }
                } else if (Config.Ragebot.Target == EAimTarget::Chest) {
                    targetAimPos.Z -= 25.0f;
                }

                if (auto WeaponManagerComponent = Data::localPlayer->WeaponManagerComponent) {
                    auto propSlot = WeaponManagerComponent->GetCurrentUsingPropSlot();
                    if ((int)propSlot.GetValue() >= 1 && (int)propSlot.GetValue() <= 3) {
                        if (auto CurrentWeapon = (ASTExtraShootWeapon*)WeaponManagerComponent->CurrentWeaponReplicated) {
                            if (auto ShootWeaponEntityComponent = CurrentWeapon->ShootWeaponComponent->ShootWeaponEntityComponent) {
                                ASTExtraVehicleBase* CurrentVehicle = Target->CurrentVehicle;
                                FVector Velocity = CurrentVehicle ? CurrentVehicle->ReplicatedMovement.LinearVelocity : Target->GetVelocity();
                                float dist = Data::localPlayer->GetDistanceTo(Target);
                                auto timeToTravel = dist / ShootWeaponEntityComponent->BulletRange;
                                targetAimPos = Add_VectorVector(targetAimPos, Multiply_VectorFloat(Velocity, timeToTravel));
                                targetAimPos.Z += Velocity.Z * timeToTravel + 0.5 * 5 * timeToTravel * timeToTravel;

                                if (Config.AimRecoil && Data::localPlayer->bIsGunADS && Data::localPlayer->bIsWeaponFiring) {
                                    float dist = Data::localPlayer->GetDistanceTo(Target) / 100.0f;
                                    targetAimPos.Z -= dist * float(Config.Ragebot.Recoil);
                                }

                                FVector fDir = Subtract_VectorVector(targetAimPos, Data::localController->PlayerCameraManager->CameraCache.POV.Location);
                                auto Rott = Conv_VectorToRotator(fDir);
                                FRotator m_Rotation = Data::localController->ControlRotation;
                                Rott.Pitch -= m_Rotation.Pitch;
                                Rott.Yaw -= m_Rotation.Yaw;
                                ClampAngles(Rott);
                                m_Rotation.Pitch += Rott.Pitch / Config.Ragebot.Smooth;
                                m_Rotation.Yaw += Rott.Yaw / Config.Ragebot.Smooth;
                                Data::localController->SetControlRotation(m_Rotation, "");
                            }
                        }
                    }
                }
            }
        }
    }

    if (Config.Memory.MagicBullet) {
        uintptr_t Mesh = *(uintptr_t*)((uintptr_t)Data::localPlayer + 0x510);
        if (Mesh) {
            uintptr_t Skeletal = *(uintptr_t*)(Mesh + 0x978);
            if (Skeletal) {
                uintptr_t Asset = *(uintptr_t*)(Skeletal + 0x138);
                if (Asset) {
                    uintptr_t ArraySkeletal = *(uintptr_t*)(Asset + 0x38);
                    if (ArraySkeletal) {
                        uintptr_t SkeletalBodySetup = *(uintptr_t*)(ArraySkeletal + sizeof(uintptr_t) * 14);
                        if (SkeletalBodySetup) {
                            uintptr_t BoxElems = *(uintptr_t*)(SkeletalBodySetup + 0x38);
                            if (BoxElems) {
                                *(float*)(BoxElems + 0x88) = Config.Memory.MagicX;
                                *(float*)(BoxElems + 0x8c) = Config.Memory.MagicY;
                                *(float*)(BoxElems + 0x90) = Config.Memory.MagicZ;
                            }
                        }
                    }
                }
            }
        }
    }
    
    if (Setting::CrazyCar && Data::localPlayer->CurrentVehicle) {
        ASTExtraVehicleBase* CurrentVehicle = Data::localPlayer->CurrentVehicle;
        float infinity = std::numeric_limits<float>::infinity();
        float coeff = (60.0f * 60.0f) * 100.f * 0.01f;

        CurrentVehicle->bUseSyncAtClient = 1;
        CurrentVehicle->bInvulnerableWhenHasRiders = 1;
        //CurrentVehicle->bEnableAntiCheat = 0;
        CurrentVehicle->VehicleDamage = 0;

        if (infinitycar) {
            CurrentVehicle->VehicleSyncComponent->MaxAllowJumpHeight = infinity;
            CurrentVehicle->VehicleSyncComponent->MaxSyncSpeedZDeltaStep1 = infinity;
            CurrentVehicle->VehicleSyncComponent->MaxSyncSpeedZDelta = infinity;
        }

        if (carspring) CurrentVehicle->VehicleSyncComponent->SetTickEnabled(false);
        CurrentVehicle->VehicleSyncComponent->Correct(true, false, 0.0f);

        if (WallHackCar) {
            CurrentVehicle->SetActorEnableCollision(false);
            CurrentVehicle->bLockZeroAngularDamping = false;
            CurrentVehicle->LockZeroAngularDampingValue = 0.0f;
            CurrentVehicle->LanscapeCheckDistance = CurrentVehicle->bCheckOnGround ? 100.0f : 10000.0f;
        } else {
            CurrentVehicle->SetActorEnableCollision(true);
            CurrentVehicle->bLockZeroAngularDamping = true;
        }

        UPrimitiveComponent* RootComponent = static_cast<UPrimitiveComponent*>(CurrentVehicle->K2_GetRootComponent());
        if (RootComponent) {
            CurrentVehicle->Mesh->SetIsReplicated(true);

            if (WallHackCar) {
                CurrentVehicle->ImmuePassageDamage = true;
                RootComponent->bApplyImpulseOnDamage = true;
                RootComponent->bIgnoreRadialForce = true;
                RootComponent->bIgnoreRadialImpulse = true;
                RootComponent->SetAllPhysicsAngularVelocity(CurrentVehicle->bIsUsingHorn ? FVector(0, 0, 10.f) : FVector(0, 0, 0), CurrentVehicle->bIsUsingHorn);
            }

            if (Setting::CarSpin && CurrentVehicle->bIsUsingHorn) {
                Active::SpinBotCar = true;
                SPINCHECK = false;
                FRotator RotationSpin = {0, Active::RotatorSpinBotCar, 0};
                CurrentVehicle->K2_SetActorRotation(RotationSpin, true);
                Active::RotatorSpinBotCar += 0.1f * SpinCar360;
                if (Active::RotatorSpinBotCar >= 360.0f) Active::RotatorSpinBotCar = 0.0f;
            } else if (Active::SpinBotCar && !CurrentVehicle->bIsUsingHorn) {
                SPINCHECK = true;
                Active::SpinBotCar = false;
                FRotator Rotation = {0, 0, 0};
                CurrentVehicle->K2_SetActorRotation(Rotation, true);
            }

            float forwardRate = CurrentVehicle->GetMoveForwardRate();
            float rightRate = CurrentVehicle->GetMoveRightRate();
            FVector vel;
            float yaw = Data::localController->PlayerCameraManager->CameraCache.POV.Rotation.Yaw;
            float pitchAngle = Data::localController->PlayerCameraManager->CameraCache.POV.Rotation.Pitch;

            float accelerationZ = (pitchAngle >= 0.0f) ? coeff * 0.5f * UKismetMathLibrary::Cos(UKismetMathLibrary::DegreesToRadians(pitchAngle))
                                                      : -coeff * 0.5f * UKismetMathLibrary::Cos(UKismetMathLibrary::DegreesToRadians(pitchAngle));
            float maxVerticalSpeed = 500.0f;
            float deltaTime = GetFullWorld()->PersistentLevel->WorldSettings->TimeDilation;
            vel.Z = UKismetMathLibrary::Clamp(vel.Z + accelerationZ * deltaTime, -maxVerticalSpeed, maxVerticalSpeed);

            float theta = 2.f * M_PI * (yaw / 720.f);
            if (forwardRate != 0 || rightRate != 0) {
                if (forwardRate > 0) theta = UKismetMathLibrary::DegreesToRadians(yaw);
                else if (forwardRate < 0) theta = UKismetMathLibrary::DegreesToRadians(yaw + 180);
                if (rightRate > 0) theta = UKismetMathLibrary::DegreesToRadians(yaw + 90);
                else if (rightRate < 0) theta = UKismetMathLibrary::DegreesToRadians(yaw - 45);

                vel.X = coeff * UKismetMathLibrary::Cos(theta);
                vel.Y = coeff * UKismetMathLibrary::Sin(theta);

                CurrentVehicle->Mesh->SetEnableGravity(false);
                CurrentVehicle->Mesh->SetAllPhysicsLinearVelocity(FVector(0, 0, 0), false);
                CurrentVehicle->Mesh->SetAllPhysicsLinearVelocity(vel, true);
            } else {
                CurrentVehicle->Mesh->SetEnableGravity(false);
                CurrentVehicle->Mesh->SetAllPhysicsLinearVelocity(FVector(0, 0, 0) * coeff, true);
            }
        }
    }

    if (Config.IpadS != 1.0f) Data::localPlayer->ThirdPersonCameraComponent->SetFieldOfView(Config.IpadS * 20);
    if (Config.IpadC != 1.0f) Data::localPlayer->ScopeCameraComp->SetFieldOfView(Config.IpadC * 10);
    if (Config.AutoTap) Data::localPlayer->SetWeaponShootType(ESTEWeaponShootType::ESTEWeaponShootType__Auto);

    if (skin.bEnable) {
        int kill_message_event_idx = 1000;
        auto VTable = (void**)Data::localController->VTable;
        auto f_mprotect = [](uintptr_t addr, size_t len, int32_t prot) -> int32_t {
            constexpr size_t page_size = 4096;
            void* start = reinterpret_cast<void*>(addr & -page_size);
            uintptr_t end = (addr + len + page_size - 1) & -page_size;
            return mprotect(start, end - reinterpret_cast<uintptr_t>(start), prot);
        };

        if (VTable && (VTable[kill_message_event_idx] != kill_message_event)) {
            orig_kill_message_event = decltype(orig_kill_message_event)(VTable[kill_message_event_idx]);
            f_mprotect((uintptr_t)(&VTable[kill_message_event_idx]), sizeof(uintptr_t), PROT_READ | PROT_WRITE);
            VTable[kill_message_event_idx] = (void*)kill_message_event;
            f_mprotect((uintptr_t)(&VTable[kill_message_event_idx]), sizeof(uintptr_t), PROT_READ | PROT_EXEC);
        }

        if (Data::localPlayer->WeaponManagerComponent && Data::localPlayer->WeaponManagerComponent->CurrentWeaponReplicated) {
            auto CurrentWeaponReplicated = (ASTExtraShootWeapon*)Data::localPlayer->WeaponManagerComponent->CurrentWeaponReplicated;
            Current_Weapon = CurrentWeaponReplicated->GetWeaponID();
            Last_Gun_Used_To_Kill = GetWeap(Current_Weapon);
        }

        if (skin.bVehicleSkin && Data::localPlayer -> CurrentVehicle != nullptr) {
        if (Data::localPlayer -> CurrentVehicle -> VehicleAvatar != nullptr) {
          std::string SkinIDStr = std::to_string((int) Data::localPlayer -> CurrentVehicle -> VehicleAvatar -> GetDefaultAvatarID());
          Active::SkinCarDefault = Data::localPlayer -> CurrentVehicle -> GetAvatarID();

          
          if (strstr(SkinIDStr.c_str(), "1901")) {
            Active::SkinCarMod = skin.vehicle->MOTOR;
            Active::SkinCarNew = true;
          } else if (strstr(SkinIDStr.c_str(), "1903")) {
            Active::SkinCarMod = skin.vehicle->DACIA;
            Active::SkinCarNew = true;
       /*   } else if (preferences.Boat && strstr(SkinIDStr.c_str(), "1911")) {
            Active::SkinCarMod = new_Skin.Boat;
            Active::SkinCarNew = true;
          } else if (preferences.MiniBus && strstr(SkinIDStr.c_str(), "1904")) {
            Active::SkinCarMod = new_Skin.MiniBus;
            Active::SkinCarNew = true;*/
          } else if (strstr(SkinIDStr.c_str(), "1914")) {
            Active::SkinCarMod = skin.vehicle->MIRADO;
            Active::SkinCarNew = true;
          } else if (strstr(SkinIDStr.c_str(), "1915")) {
            Active::SkinCarMod = skin.vehicle->MIRADO;
            Active::SkinCarNew = true;
          } else if (strstr(SkinIDStr.c_str(), "1907")) {
            Active::SkinCarMod = skin.vehicle->BUGGY;
            Active::SkinCarNew = true;
          }else if (strstr(SkinIDStr.c_str(), "1961")) {
            Active::SkinCarMod = skin.vehicle->COUPE;
            Active::SkinCarNew = true;
         /* } else if (preferences.BigFoot && strstr(SkinIDStr.c_str(), "1953")) {
            Active::SkinCarMod = Config.new_Skin.Bigfoot;
            Active::SkinCarNew = true;*/
          } else if (strstr(SkinIDStr.c_str(), "1908")) {
            Active::SkinCarMod = skin.vehicle->UAZ;
            Active::SkinCarNew = true;
          } else Active::SkinCarNew = false;

          if (Active::SkinCarDefault != Active::SkinCarMod && Active::SkinCarNew) {
            
            Data::localPlayer -> CurrentVehicle -> VehicleAvatar -> ChangeItemAvatar(Active::SkinCarMod, true);
          }
        }
      }
    

        if (skin.bDeadbox) {
            std::vector<APlayerTombBox*> TombBox;
            GetAllActors(TombBox);
            for (auto& TombBoxx : TombBox) {
                if (TombBoxx && TombBoxx->DamageCauser && TombBoxx->TargetPlayer && TombBoxx->DamageCauser->PlayerKey == Data::localController->PlayerKey) {
                    auto PlayerKey = TombBoxx->TargetPlayer->PlayerKey;
                    if (AlreadyChangedSet.find(PlayerKey) == AlreadyChangedSet.end() && Last_Gun_Used_To_Kill > 0) {
                        auto DeadBoxAvatarCompPtr = (uintptr_t*)((uintptr_t)TombBoxx + Data::Offset::DeadBoxAvatarComponent_BP_C);
                        if (DeadBoxAvatarCompPtr && *DeadBoxAvatarCompPtr) {
                            ChangeItemAVc(*DeadBoxAvatarCompPtr, Last_Gun_Used_To_Kill);
                            AlreadyChangedSet.insert(PlayerKey);
                        }
                    }
                }
            }
        }
    }
}

void* (*oPostRender)(UGameViewportClient*, UCanvas*);
void* PostRender(UGameViewportClient* GameViewport, UCanvas* Canvas) {
    DrawMemory(Canvas, Canvas->SizeX, Canvas->SizeY);
    return oPostRender(GameViewport, Canvas);
}
void PostrenderDraw() {//by 速穿
    auto GViewport = GetGameViewport();
    if (GViewport) {
        int postrender_idx = 134;//每个赛季变化都不会很大
        auto f_mprotect = [](uintptr_t addr, size_t len, int32_t prot) -> int32_t {
            static_assert(PAGE_SIZE == 4096);
            constexpr size_t page_size = static_cast<size_t>(PAGE_SIZE);
            void* start = reinterpret_cast<void*>(addr & -page_size);
            uintptr_t end = (addr+len+page_size - 1) & -page_size;
            return mprotect(start, end - reinterpret_cast<uintptr_t>(start), prot);
        };
        auto VTable = (void **)GViewport->VTable;
        if (VTable && (VTable[postrender_idx] != PostRender)) {
            oPostRender = decltype(oPostRender)(VTable[postrender_idx]);
            f_mprotect((uintptr_t)(&VTable[postrender_idx]), sizeof(uintptr_t), PROT_READ | PROT_WRITE);
            VTable[postrender_idx] = (void *)PostRender;
        }
    }
}

DWORD GetVehSkinModded(DWORD old) {
    static const std::unordered_map<DWORD, DWORD> vehSkinMap = {
        {1901001, skin.vehicle->MOTOR}, {1901002, skin.vehicle->MOTOR}, {1961001, skin.vehicle->COUPE},
        {1908001, skin.vehicle->UAZ}, {1910001, skin.vehicle->UAZ}, {1903001, skin.vehicle->DACIA},
        {1914001, skin.vehicle->MIRADO}, {1914002, skin.vehicle->MIRADO}, {1914003, skin.vehicle->MIRADO},
        {1914004, skin.vehicle->MIRADO}, {1915001, skin.vehicle->MIRADO}, {1915002, skin.vehicle->MIRADO},
        {1915003, skin.vehicle->MIRADO}, {1915004, skin.vehicle->MIRADO}, {1907001, skin.vehicle->BUGGY},
        {1907002, skin.vehicle->BUGGY}, {1907003, skin.vehicle->BUGGY}, {1907004, skin.vehicle->BUGGY},
        {1907005, skin.vehicle->BUGGY}, {1907006, skin.vehicle->BUGGY}
    };
    return vehSkinMap.count(old) ? vehSkinMap.at(old) : 0;
}

void* (*oProcessEvent)(UObject*, UFunction*, void*);
void* hkProcessEvent(UObject* a1, UFunction* a, void* b) {
    if (!a1 || !a) return oProcessEvent(a1, a, b);

    auto fnc = a->GetFullName();
    auto clazz = a1->GetFullName();

    if (ReceiveDrawHUD_Index == -1 && fnc.find("Function Engine.HUD.ReceiveDrawHUD") != std::string::npos) ReceiveDrawHUD_Index = a->InternalIndex;
    if (OnRep_AvatarMeshChanged_Index == -1 && fnc.find("ShadowTrackerExtra.STExtraWeapon.OnRep_AvatarMeshChanged") != std::string::npos) OnRep_AvatarMeshChanged_Index = a->InternalIndex;
    if (CreateBattleItemHandle_Index == -1 && fnc.find("BackpackBlueprintUtils_BP_C.CreateBattleItemHandle") != std::string::npos) CreateBattleItemHandle_Index = a->InternalIndex;
    if (CreateWeaponAndChangeSkin_Index == -1 && fnc.find("CreateWeaponAndSkin") != std::string::npos) CreateWeaponAndChangeSkin_Index = a->InternalIndex;
    if (OnRep_BodySlotStateChanged_Index == -1 && fnc.find("ShadowTrackerExtra.CharacterAvatarComponent2.OnRep_BodySlotStateChanged") != std::string::npos) OnRep_BodySlotStateChanged_Index = a->InternalIndex;
    if (skin.bDeadbox && DeadBoxAvatarComponent_GetLuaFilePath_Index == -1 && clazz.find("DeadBoxAvatarComponent_BP") != std::string::npos && fnc.find("GetLuaFilePath") != std::string::npos) DeadBoxAvatarComponent_GetLuaFilePath_Index = a->InternalIndex;

    if (Data::localPlayer && Data::localController && Config.ESPMenu.Instant && fnc.find("ClientOnDamageToOther") != std::string::npos) {
        auto localContrller = reinterpret_cast<ASTExtraPlayerController*>(a1);
        auto Params = reinterpret_cast<ASTExtraPlayerController_ClientOnDamageToOther_Params*>(b);
        if (Params) {
            auto damage = Params->_DamageToOther;
            if (auto HUD = reinterpret_cast<ASurviveHUD*>(localContrller->MyHUD)) {
                HUD->AddHitDamageNumberWithConfig(damage, Data::localPlayer, Data::localController, 0, 1, 1, 1);
            }
        }
    }

    if (fnc.find("UpdateVolleyShootParameters") != std::string::npos) {
        auto params = (USTExtraShootWeaponComponent_UpdateVolleyShootParameters_Params*)b;
        if (Config.Ragebot.Aimtype == 1 && Config.Ragebot.Enable) {
            auto Target = GetBestLineTarget();
            if (Target) {
                bool triggerOk = false;
                switch (Config.Ragebot.Trigger) {
                    case EAimTrigger::Shooting: triggerOk = Data::localPlayer->bIsWeaponFiring; break;
                    case EAimTrigger::Scoping: triggerOk = Data::localPlayer->bIsFPPOnVehicle; break;
                    case EAimTrigger::Both: triggerOk = Data::localPlayer->bIsWeaponFiring && Data::localPlayer->bIsGunADS; break;
                    case EAimTrigger::Any: triggerOk = Data::localPlayer->bIsWeaponFiring || Data::localPlayer->bIsGunADS; break;
                    default: triggerOk = true;
                }
                if (triggerOk) {
                    FVector TargetAimPosition = Target->GetBonePos("Head", {});
                    TargetAimPosition.Z -= -19.0f;
                    auto CurrentWeaponReplicated = (ASTExtraShootWeapon*)Data::localPlayer->WeaponManagerComponent->CurrentWeaponReplicated;
                    auto CurrentVehicle = Target->CurrentVehicle;
                    CurrentWeaponReplicated->ShootMode = EShootWeaponShootMode::SWST_TraceTarget;
                    float BulletFireSpeed = CurrentWeaponReplicated->GetBulletFireSpeedFromEntity();
                    FVector CurrentPlayerVelocity = CurrentVehicle ? CurrentVehicle->ReplicatedMovement.LinearVelocity : Target->GetVelocity();
                    float Distance = Data::localPlayer->GetDistanceTo(Target);
                    auto TimeToTravel = Distance / BulletFireSpeed;
                    TargetAimPosition = AddVectors(TargetAimPosition, MultiplyVectorFloat(CurrentPlayerVelocity, TimeToTravel));
                    FVector fDir = SubtractVectors(Data::localController->PlayerCameraManager->CameraCache.POV.Location, TargetAimPosition);
                    params->BulletRot = VectorToRotator(fDir);
                }
            }
        }
    }

    if (skin.bEnable) {
        if (skin.bGunSkin && OnRep_AvatarMeshChanged_Index == a->InternalIndex) {
            auto gun = reinterpret_cast<ASTExtraWeapon*>(a1);
            if (gun) ChangeGunSkin(gun);
        } else if (!Data::localController && skin.bVehicleSkin && fnc.find("VehicleAvatarComponent_BP.VehicleAvatarComponent_BP_C.GetItemAvatarHandle") != std::string::npos) {
            auto PARAMS = reinterpret_cast<UVehicleAvatarComponent_GetItemAvatarHandle_Params*>(b);
            if (PARAMS) {
                int neww = GetVehSkinModded(PARAMS->ItemId);
                if (neww > 0) PARAMS->ItemId = neww;
            }
        } else if (!Data::localController && skin.bClothSkin && fnc.find(skCrypt("OnAvatarMeshEquippedEventBP")) != std::string::npos) {
            auto avatar = reinterpret_cast<UCharacterAvatarComponent2*>(a1);
            if (avatar) UpdateClothSkinLobby(avatar);
        } else if (Data::localController && skin.bClothSkin && OnRep_BodySlotStateChanged_Index == a->InternalIndex) {
            auto avatar = reinterpret_cast<UCharacterAvatarComponent2*>(a1);
            if (avatar) UpdateClothSkin(avatar);
        } else if (skin.bGunSkin && CreateWeaponAndChangeSkin_Index == a->InternalIndex) {
            auto params = reinterpret_cast<ULobbyWeaponManagerComponent_CreateWeaponAndSkin_Params*>(b);
            if (params) {
                params->bSync = false;
                params->bUse = true;
                int g_WeaponID = params->WeaponSkinID;
                DWORD gun_val = GetWeap(g_WeaponID);
                if (gun_val > 0) params->WeaponSkinID = gun_val;
            }
        } else if (skin.bDeadbox && DeadBoxAvatarComponent_GetLuaFilePath_Index == a->InternalIndex && a1->GetName().find("DeadBoxAvatarComponent") != std::string::npos) {
            auto DeadBoxPointer = reinterpret_cast<UDeadBoxAvatarComponent*>(a1);
            if (DeadBoxPointer && Last_Gun_Used_To_Kill > 0) DeadBoxPointer->AsyncChangeItemAvatar(Last_Gun_Used_To_Kill);
        }
    }

    return oProcessEvent(a1, a, b);
}
