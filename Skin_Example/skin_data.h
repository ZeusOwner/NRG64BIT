
//
// Created by Administrator on 3/4/2024.
//

#ifndef MRTHANG_SKIN_DATA_H
#define MRTHANG_SKIN_DATA_H
#pragma once
#include <iostream>
#include <vector>
#include <string>

typedef unsigned long DWORD;

class CModBase {};

class CWeapAttack : public CModBase {
public:
    DWORD Default = 0;
};

class CGunSkinSetting : public CModBase {
public:
    DWORD AKM = 1101001213, M16A4 = 1101002081, SCARL = 1101003188, M416 = 1101004046, GROZA = 1101005052,
          AUG = 1101006062, QBZ = 1101007046, M762 = 1101008126, HONEY = 0, ACE32 = 1101102017,
          UZI = 1102001024, UMP45 = 1102002136, VECTOR = 1102003080, TOMMY = 1102004018, PP19 = 1102005057,
          KAR98 = 1103001179, M24 = 1103002087, AWM = 1103003062, MINI14 = 1103006030, MK14 = 1103007020,
          AMR = 1103012010, M249 = 1105001048, DP28 = 1105002063, MG3 = 1101102017, DBS = 1104101001,
          S12K = 1104003027, XM1014 = 1104101001, PAN = 1108004356, KNIFE = 1108001057, KNIFE1 = 1108005050,
          P90 = 1102105012;
};

class CClothSetting : public CModBase {
public:
    DWORD SHIRT = 1405628, HAT = 0, PANT = 0, SHOE = 0, PARACHUTE = 0, HELMET1 = 1502001023,
          BACKPACK1 = 1501001220, HELMET2 = 1502002023, BACKPACK2 = 1501002220, HELMET3 = 1502003023,
          BACKPACK3 = 1501003220, GLIDER = 0;
};

class CVehicleSetting : public CModBase {
public:
    DWORD MOTOR = 1901047, COUPE = 1961015, UAZ = 1908067, DACIA = 1903075, MIRADO = 1915010, BUGGY = 1907054;
};

class CModSkinSetting {
public:
    DWORD dwPassword = 0xBEEF;
    bool bEnable = false, bGunSkin = false, bClothSkin = false, bVehicleSkin = false, bKillMsg = false, bDeadbox = false;
    CGunSkinSetting* gun;
    CClothSetting* cloth;
    CVehicleSetting* vehicle;

    CModSkinSetting() {
        gun = new CGunSkinSetting();
        cloth = new CClothSetting();
        vehicle = new CVehicleSetting();
    }

    ~CModSkinSetting() {
        delete gun;
        delete cloth;
        delete vehicle;
    }
};

static CModSkinSetting skin;

struct FSkinItem {
    std::string name;
    DWORD value;
    FSkinItem(std::string n, DWORD v) : name(std::move(n)), value(v) {}
    std::string ToStructString() const { return std::to_string(value); }
};

class CSkinsInfo {
public:
    DWORD* out = nullptr;
    bool bFirstInit = false;
    int current_index = 0;
    std::vector<FSkinItem> items;

    CSkinsInfo() = default;

    void Init(std::vector<FSkinItem> _items, DWORD* _out) {
        out = _out;
        items = std::move(_items);
        if (out && !items.empty()) {
            *out = items[0].value;
        }
    }

    DWORD At(int index) const { return (index < items.size()) ? items[index].value : 0; }
    DWORD Get() const { return At(current_index); }
};

class SkinData {
public:
    CSkinsInfo m416, m16, akm, scarl, aug, m762, groza, ace32, honey, qbz,
               ump45, vector, tommy, uzi, pp19, kar98, m24, awm, amr, mk14,
               mini14, m249, dp28, mg3, pan, s12k, xm1014, dbs, cloth, hat,
               pant, shoe, parachute, glider, backpack1, helmet1, backpack2,
               helmet2, backpack3, helmet3, coupe, uaz, dacia, motor, buggy,
               mirado, knife, knife1;

    SkinData() {
        // Hàm khởi tạo danh sách skin chung
        auto initSkin = [this](CSkinsInfo& skinInfo, DWORD* out, const std::vector<FSkinItem>& items) {
            skinInfo.Init(items, out);
        };

        // Clothes
        initSkin(cloth, &skin.cloth->SHIRT, {
            {"Default", 0}, {"Thánh Giáp Pharaoh Vàng (6 sao)", 1405628}, {"Thánh Giáp Pharaoh Vàng (7 Sao)", 1406469},
            {"Thánh Giáp Phong Linh Thiên Nữ (7 Sao)", 1407366}, {"Trang phục Miêu Nữ Công Nghệ", 1407286},
            {"Trang Phục Vệ Thần Tình Ái", 1407276}, {"Trang Phục Nữ Hoàng Giải Trí", 1407079},
            {"Trang Phục Thánh Nữ Huyền Ảo", 1407329}, {"Thánh Giáp Huyết Nha (6 Sao)", 1405870},
            {"Thánh Giáp Poseidon (6 Sao)", 1405983}, {"Thánh Giáp Băng Giá (6 Sao)", 1406152},
            {"Thánh Giáp Tinh Linh (6 Sao)", 1406311}, {"Thánh Giáp Cleopatra Vàng (6 Sao)", 1406475},
            {"Thánh Giáp Chúa Hề Bí Ẩn (6 Sao)", 1406641}, {"Thánh Giáp Huyết Thần Tai Ương (7 Sao)", 1406872},
            {"Thánh Giáp Thần Nữ Thủy Vực (7 Sao)", 1406971}, {"Trang Phục Đường Đến Địa Ngục", 1405623},
            {"Trang Phục Hỏa Thần Cổ Ngữ", 1407277}, {"Trang phục Huyền Thần", 1407275},
            {"Trang Phục Linh Hồn Xác Ướp", 1406891}, {"Trang Phục Xác Ướp Y Tá", 1400687},
            {"Zanmang Loopy Nghỉ Dưỡng", 1601048}, {"Thánh Giáp Hoa Linh Vĩnh Cửu (7 Sao)", 1407103},
            {"Trang Phục Thanh Hoa Xà", 1407161}, {"Trang phục Hỏa Diệm Ma Giáp", 1406398},
            {"Trang Phục Đô Đốc Huyễn Ảnh", 1407330}, {"Trang Phục Tiên Linh Lưu Ly", 1407225},
            {"Thánh Giáp Hỏa Linh Chí Tôn (7 sao)", 1407219}, {"Trang Phục Cô Dâu Quyến Rũ", 1405174},
            {"Trang Phục Diva Tím", 1407174}, {"Trang Phục Khủng Long Ephialtes", 1406897},
            {"Trang phục Apeachy", 1405208}, {"Trang phục Đội trưởng Ryan", 1405207},
            {"Áo Hoodie cá mập BAPE X PUBGM CAMO", 1404049}, {"Trang Phục Tử Thần Ma Xà", 1407387},
            {"Trang Phục Chúa Tể Băng Giá", 1407440}, {"Trang Phục Hồng Y Nữ Vương", 1407391},
            {"Trang Phục Ngôi Sao Tuyết Tinh Tú", 1407441}, {"Ngoại Trang Ngọc Lang Thiên Giới", 1407471},
            {"Lam Sư Đoạt Mệnh", 1407470}
        });

        initSkin(hat, &skin.cloth->HAT, {
            {"None", 0}, {"Mũ BAPE X PUBGM CAMO", 1402162}, {"Mũ Diva Tím", 1410585},
            {"Tóc 2 chùm", 40605012}, {"Tóc Cà Phê Muối", 40605014}, {"Mũ Đô Đốc Huyễn Ảnh", 1410686},
            {"Cài tóc cô dâu", 1402145}, {"Mũ Vệ Thần Tình Ái", 1410647}, {"Tiên Linh Lưu Ly", 12220054}
        });

        initSkin(pant, &skin.cloth->PANT, {{"None", 0}, {"Quần BAPE X PUBGM CAMO", 1404050}});

        initSkin(shoe, &skin.cloth->SHOE, {
            {"None", 0}, {"Giày BAPE X PUBGM CAMO", 1404051}, {"BAPE STA MID", 1400651}, {"Dép bơi", 1400371}
        });

        initSkin(parachute, &skin.cloth->PARACHUTE, {
            {"Dù Bùa Hộ Mệnh Pharaoh", 1401619}, {"Dù Huyết Nha", 1401621}, {"Dù LINE FRIENDS", 1401622},
            {"Dù Thần Horus", 1401615}, {"Dù Phượng Hoàng Adarna Ảo Diệu", 1401628}, {"Dù Lượn Lam Sư Tinh Hà", 4151092}
        });

        initSkin(glider, &skin.cloth->GLIDER, {
            {"Glider 1", 4151048}, {"Thiết bị bay Bằng Chíu", 4151010}, {"Tàu Lượn Chiến Thần Tình Yêu", 4151019}
        });

        // Backpacks and Helmets (gộp lại vì lặp lại nhiều)
        auto initLevelItems = [&](CSkinsInfo& info, DWORD* out, int level) {
            std::vector<FSkinItem> items = {
                {"Ba lô Huyết Nha (Cấp " + std::to_string(level) + ")", 1501001220 + (level - 1) * 1000},
                {"Ba Lô Neon Huyền Bí (Cấp " + std::to_string(level) + ")", 1501001582 + (level - 1) * 1000},
                {"Ba lô cánh bướm (Cấp " + std::to_string(level) + ")", 1501001047 + (level - 1) * 1000},
                {"Ba lô Pharaoh (Cấp " + std::to_string(level) + ")", 1501001174 + (level - 1) * 1000},
                {"Ba Lô Mèo Điện Tử (Cấp " + std::to_string(level) + ")", 1501001496 + (level - 1) * 1000},
                {"Ba Lô Yêu Thỏ (Cấp " + std::to_string(level) + ")", 1501001495 + (level - 1) * 1000},
                {"Ba lô chú hề (Cấp " + std::to_string(level) + ")", 1501001051 + (level - 1) * 1000},
                {"Ba Lô Phong Linh (Cấp " + std::to_string(level) + ")", 1501001588 + (level - 1) * 1000},
                {"Ba lô Đội trưởng Ryan", 1501000057},
                {"Ba lô Godzilla (Cấp " + std::to_string(level) + ")", 1501001061 + (level - 1) * 1000},
                {"Ba lô BAPE X PUBGM CAMO (Cấp " + std::to_string(level) + ")", 1501001058 + (level - 1) * 1000},
                {"Ba lô cá mập (Cấp " + std::to_string(level) + ")", 1501001069 + (level - 1) * 1000},
                {"Ba Lô Kiếm Băng Tuyết (Cấp " + std::to_string(level) + ")", 1501001618 + (level - 1) * 1000},
                {"Ba Lô Khế Ước Thi Sĩ (Cấp " + std::to_string(level) + ")", 1501001628 + (level - 1) * 1000}
            };
            info.Init(items, out);
        };

        initLevelItems(backpack1, &skin.cloth->BACKPACK1, 1);
        initLevelItems(backpack2, &skin.cloth->BACKPACK2, 2);
        initLevelItems(backpack3, &skin.cloth->BACKPACK3, 3);

        auto initHelmet = [&](CSkinsInfo& info, DWORD* out, int level) {
            info.Init({{"Mũ sắt băng tuyết (Cấp " + std::to_string(level) + ")", 1502001023 + (level - 1) * 1000},
                       {"Mũ kỵ sĩ hỏa ngục (Cấp " + std::to_string(level) + ")", 1502001014 + (level - 1) * 1000}}, out);
        };

        initHelmet(helmet1, &skin.cloth->HELMET1, 1);
        initHelmet(helmet2, &skin.cloth->HELMET2, 2);
        initHelmet(helmet3, &skin.cloth->HELMET3, 3);

        // Vehicles
        initSkin(uaz, &skin.vehicle->UAZ, {
            {"None", 0}, {"Bentley Betayga Azure (Mưa Hoa)", 1908094}, {"Bentley Betayga Azure (Đêm Yên Tĩnh)", 1908095},
            {"Xe UAZ Siêu Thú Godzilla (Cấp 3)", 1908032}, {"Xe UAZ Bí Ngô Ma Quái (Cấp 3)", 1908036},
            {"Lamborghini Urus Pink", 1908066}, {"Lamborghini Urus Giallo Inti", 1908067},
            {"Maserati Levante Blu Emozione", 1908075}, {"Maserati Luce Arancione", 1908076},
            {"Maserati Levante Neon Urbano", 1908077}, {"Maserati Levante Firmamento", 1908078},
            {"Aston Martin DBX707 (Neon Purple)", 1908084}, {"Aston Martin DBX707 (Quasar Blue)", 1908085},
            {"Dodge Hornet - Scarlet Sting", 1908086}, {"Dodge Hornet GLH Concept - Redline", 1908088},
            {"Dodge Hornet - Sunburst", 1908089}
        });

        initSkin(motor, &skin.vehicle->MOTOR, {
            {"None", 0}, {"Xe Mô Tô Bóng Ma (Cấp 7)", 1901047}, {"Xe máy Hổ gầm gừ (Cấp 3)", 1901027},
            {"MWT-9", 1901050}, {"MWT-9 (Vàng)", 1901052}, {"DUCATI Panigale V4S", 1901073},
            {"Ducati Panigale V4S Black Phantom", 1901074}, {"Ducati Panigale V4S Crimson Storm", 1901075},
            {"Ducati Panigale V4S Swift Mirage", 1901076}
        });

        initSkin(mirado, &skin.vehicle->MIRADO, {
            {"None", 0}, {"VW Beetle Convertible Mới (Hồng)", 1915010}, {"VW Beetle Convertible Mới (Quái Vật)", 1915012},
            {"Aston Martin DBS Volante (Deep Cosmos)", 1915005}, {"Aston Martin DBS Volante (Celestial Pink)", 1915006},
            {"Aston Martin DBS Volante (Black-Bronze Satin)", 1915007},
            {"Bentley Continental GTC Mulliner (Mộng Cảnh Lung Linh)", 1915009}
        });

        initSkin(dacia, &skin.vehicle->DACIA, {
            {"None", 0}, {"Bentley Flying Spur Mulliner (Tinh Vân Xanh)", 1903200},
            {"Bentley Flying Spur Mulliner (Dòng Chảy Vịnh Hẹp)", 1903201}, {"Koenigsegg Gemera (Cầu Vồng)", 1903075},
            {"Tesla Roadster (Kim Cương)", 1903071}, {"Tesla Roadster (Pha Lê Tím)", 1903072},
            {"Tesla Roadster (Xanh Biển Cả)", 1903073}, {"Koenigsegg Gemera (Xám Bạc)", 1903074},
            {"Koenigsegg Gemera (Bình Minh)", 1903076}
        });

        initSkin(buggy, &skin.vehicle->BUGGY, {
            {"None", 0}, {"Xe Đua Đội McLaren F1 (Điện Tử)", 1907054}, {"Xe Đua Đội McLaren F1", 1907058},
            {"Xe Đua Đội McLaren F1 (Chiến Thắng)", 1907059}
        });

        initSkin(coupe, &skin.vehicle->COUPE, {
            {"None", 0}, {"McLaren P1 (Trời Sao)", 1961147}, {"McLaren P1 (Hồng Rực Rỡ)", 1961148},
            {"McLaren P1 (Vàng Núi Lửa)", 1961149}, {"Bentley Betayga Azure (Vương Quốc Huyền Ảo)", 1961139},
            {"Lamborghini Invencible Rosso Efesto", 1961144}, {"Lamborghini Invencible Nebula Drift", 1961145},
            {"Bentley Batur (Holoprism)", 1961137}, {"Bentley Batur (Solar Pulse)", 1961138},
            {"Bentley Batur (Bonneville Pearlescent Silver)", 1961139}, {"Warp Green", 1961033},
            {"Warp Dawn", 1961034}, {"Warp Universe", 1961035}, {"McLaren 570S (Đen)", 1961007},
            {"McLaren 570S (Trắng)", 1961010}, {"McLaren 570S (Hồng)", 1961012}, {"McLaren 570S (Vàng Trắng)", 1961013},
            {"McLaren 570S (Vàng Đen)", 1961014}, {"McLaren 570S (Ánh Kim)", 1961015},
            {"Koenigsegg Jesko (Xám Bạc)", 1961016}, {"Koenigsegg Jesko (Cầu Vồng)", 1961017},
            {"Koenigsegg Jesko (Bình Minh)", 1961018}, {"Lamborghini Aventador SVJ Verde Alceo", 1961020},
            {"Lamborghini Centenario Galassia", 1961021}, {"Lamborghini Aventador SVJ Blue", 1961024},
            {"Lamborghini Centenario Carbon Fiber", 1961025}, {"Koenigsegg One:1 Gilt", 1961029},
            {"Koenigsegg One:1 Cyber Nebula", 1961030}, {"Koenigsegg One:1 Jade", 1961031},
            {"Bugatti Veyron 16.4 (Sắc Màu)", 1961041}, {"Bugatti Veyron 16.4 (Vàng)", 1961042},
            {"Bugatti La Voiture Noire", 1961044}, {"Aston Martin Valkyrie (Luminous Diamond)", 1961048},
            {"Dodge Challenger SRT Hellcat Jailbreak - Hellfire", 1961050}, {"Pagani Zonda R (Tricolore Carbon)", 1961051}
        });

        // Guns
        initSkin(m16, &skin.gun->M16A4, {{"Lõi Skeletal - M16A4 (Cấp 7)", 1101002081}});
        initSkin(m416, &skin.gun->M416, {
            {"Băng giá - M416 (Cấp 7)", 1101004046}, {"Lam Sư Đoạt Mệnh - M416 (Cấp 8)", 1101004236},
            {"Phong Ấn U Minh - M416 (Cấp 8)", 1101004226}, {"Chú hề - M416 (Cấp 7)", 1101004062},
            {"Bò Sát Gầm Gừ - M416 (Cấp 7)", 1101004086}, {"Hoàng Gia Lộng Lẫy - M416 (Cấp 8)", 1101004163},
            {"Bạch Lân Nhả Ngọc - M416 (Cấp 8)", 1101004201}, {"Thủy Triều Dậy Sóng - M416 (Cấp 8)", 1101004209},
            {"Ma Ảnh - M416 (Cấp 8)", 1101004218}
        });
        initSkin(akm, &skin.gun->AKM, {
            {"Đô Đốc Hải Long Tinh - AKM (Cấp 8)", 1101001213}, {"Thỏ Tinh Nghịch - AKM (Cấp 7)", 1101001231},
            {"Ngày Phán Quyết - AKM (Cấp 8)", 1101001242}, {"Thánh Quang (Lông Vũ Hoàng Kim) - AKM (Lv7)", 1101001256},
            {"Thánh Quang (Trăng Thần) - AKM (Lv7)", 1101001249}
        });
        initSkin(scarl, &skin.gun->SCARL, {
            {"Ma Vương Huyết Hồn - SCAR-L (Cấp 8)", 1101003167}, {"Cái Ôm Của Chú Hề - SCAR-L (Cấp 7)", 1101003181},
            {"Thánh Nữ Huyền Ảo - SCAR-L (Cấp 7)", 1101003195}, {"Vương Quốc Huyền Ảo -SCAR-L (Cấp 7)", 1101003208}
        });
        initSkin(aug, &skin.gun->AUG, {{"Tinh Linh Băng Giá - AUG (Cấp 8)", 1101006062}, {"Hỏa Ca - AUG (Cấp 7)", 1101006075}});
        initSkin(m762, &skin.gun->M762, {
            {"Huyết Rồng - M762 (Cấp 7)", 1101008126}, {"Tiên Linh Lưu Ly - M762 (Cấp 7)", 1101008136},
            {"Bạch Cốt U Minh - M762 (Cấp 8)", 1101008146}, {"Khung Xương - M762 (Cấp 8)", 1101008154}
        });
        initSkin(groza, &skin.gun->GROZA, {{"Lửa U Minh - Groza (Cấp 7)", 1101005052}, {"Di Tích Thượng Cổ - Groza (Cấp 5)", 1101005090}});
        initSkin(honey, &skin.gun->HONEY, {{"Sắc Màu Huyền Ảo - Honey Badger (Cấp 5)", 1101012009}});
        initSkin(ace32, &skin.gun->ACE32, {
            {"Kamehameha - ACE32 (Cấp 7)", 1101102007}, {"Ngọc Bích - ACE32 (Cấp 7)", 1101102017},
            {"Thủy Quái - ACE32 (Cấp 8)", 1101102025}
        });
        initSkin(qbz, &skin.gun->QBZ, {
            {"Công Chúa Hắc Ám - QBZ (Cấp 7)", 1101007046}, {"Hoa Kiếm Chí Mạng - QBZ (Cấp 7)", 1101007062},
            {"Thiên Mệnh - QBZ (Cấp 7)", 1101007071}
        });

        // SMG
        initSkin(ump45, &skin.gun->UMP45, {{"Băng Giá - UMP45 (Cấp 7)", 1102002136}});
        initSkin(uzi, &skin.gun->UZI, {
            {"Cam Tươi Mát - UZI (Cấp 5)", 1102001103}, {"Phong Ấn - UZI (Cấp 3)", 1102001112},
            {"Savagery - UZI (Cấp 5)", 1102001998}, {"Máy Ép Trái Cây - UZI (Cấp 5)", 1102001102},
            {"Băng Giá - UZI (Cấp 8)", 1102001120}
        });
        initSkin(vector, &skin.gun->VECTOR, {{"Cánh Rồng - Vector (Cấp 7)", 1102003080}});
        initSkin(pp19, &skin.gun->PP19, {{"Lân Sư - PP-19 Bizon (Cấp 5)", 1102005057}});
        initSkin(tommy, &skin.gun->TOMMY, {{"Kẹo ngọt - Thompson (Cấp 5)", 1102004018}});

        // Sniper
        initSkin(kar98, &skin.gun->KAR98, {{"Điện Cực Tím - Kar98K (Cấp 7)", 1103001179}, {"Hồng Hỏa Diệm - Kar98 (Cấp 7)", 1103001191}});
        initSkin(m24, &skin.gun->M24, {{"Nhịp Điệu Hoàn Mỹ - M24 (Cấp 7)", 1103002087}, {"Công Nghệ Cao - M24 (Cấp 5)", 1103002094}});
        initSkin(awm, &skin.gun->AWM, {{"Thanh Hoa Xà - AWM (Cấp 7)", 1103003087}});
        initSkin(amr, &skin.gun->AMR, {
            {"Khủng Long Ephialtes - AMR (Cấp 8)", 1103012010}, {"Hỏa Thần - AMR (Cấp 7)", 1103012019},
            {"Tinh Thể Onyx - AMR (Cấp 5)", 1103012024}, {"Vô Âm Ly Biệt - AMR (Cấp 7)", 1103012031}
        });
        initSkin(mk14, &skin.gun->MK14, {{"Vương Quốc Rồng - Mk14 (Cấp 8)", 1103007028}});
        initSkin(mini14, &skin.gun->MINI14, {{"Sông Băng - Mini14 (Cấp 7)", 1103006030}});

        // LMG
        initSkin(m249, &skin.gun->M249, {{"Nữ Đế Ánh Sáng - M249 (Cấp 7)", 1105001048}, {"Graffiti Đường Phố - M249 (Cấp 5)", 1105001062}});
        initSkin(dp28, &skin.gun->DP28, {
            {"Rồng Thần Shenron - DP-28 (Cấp 5)", 1105002063}, {"Chiến Sĩ Thần Giáp - DP-28 (Cấp 5)", 1105002071},
            {"Mèo Số Hóa - DP-28 (Cấp 5)", 1105002076}
        });
        initSkin(mg3, &skin.gun->MG3, {{"Thiên Khung - MG3 (Cấp 5)", 1105010008}, {"Chiến Thần Bầu Trời - MG3 (Cấp 7)", 1105010019}});
        initSkin(pan, &skin.gun->PAN, {
            {"Gà Rán - Chảo (Cấp 3)", 1108004356}, {"Chảo - Đội trưởng Ryan", 1108004060},
            {"Chảo - Apeachy", 1108004061}, {"Chảo - BAPE X PUBGM CAMO", 1108004062}
        });
        initSkin(knife, &skin.gun->KNIFE, {
            {"Săn Rồng - Dao (Cấp 3)", 1108001057}, {"Doản Kiếm Yor SPY×FAMILY (Lv3)", 1108001064},
            {"Ki Sword (Cấp 3)", 1108001069}
        });
        initSkin(knife1, &skin.gun->KNIFE1, {{"Rồng Băng Giá - Dao Găm (Cấp 3)", 1108005050}});

        // Shotgun
        initSkin(s12k, &skin.gun->S12K, {{"Chiến Ưng Vàng - S12K", 1104003027}, {"Kích Hoạt Nguyên Tử - S12K (Cấp 5)", 1104003037}});
        initSkin(dbs, &skin.gun->DBS, {{"Báo Sắc Màu - DBS (Cấp 3)", 1104004024}, {"Chiến Giáp Quái Thú - DBS (Cấp 5)", 1104004035}});
        initSkin(xm1014, &skin.gun->XM1014, {{"Lễ Hội Chết Chóc - M1014", 1104101001}});
    }
};

static SkinData skindata;

#endif // MRTHANG_SKIN_DATA_H
