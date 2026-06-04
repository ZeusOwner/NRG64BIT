
/*
struct Matrix {
    float M[4][4];
};
*/
FVector MatrixToVector(FMatrix matrix) {
    return {matrix.M[3][0], matrix.M[3][1], matrix.M[3][2]};
}

FMatrix MatrixMultiplication(FMatrix m1, FMatrix m2) {
    FMatrix matrix = FMatrix();
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                matrix.M[i][j] += m1.M[i][k] * m2.M[k][j];
            }
        }
    }
    return matrix;
}

FMatrix TransformToMatrix(FTransform transform) {
    FMatrix matrix;

    matrix.M[3][0] = transform.Translation.X;
    matrix.M[3][1] = transform.Translation.Y;
    matrix.M[3][2] = transform.Translation.Z;

    float x2 = transform.Rotation.X + transform.Rotation.X;
    float y2 = transform.Rotation.Y + transform.Rotation.Y;
    float z2 = transform.Rotation.Z + transform.Rotation.Z;

    float xx2 = transform.Rotation.X * x2;
    float yy2 = transform.Rotation.Y * y2;
    float zz2 = transform.Rotation.Z * z2;

    matrix.M[0][0] = (1.f - (yy2 + zz2)) * transform.Scale3D.X;
    matrix.M[1][1] = (1.f - (xx2 + zz2)) * transform.Scale3D.Y;
    matrix.M[2][2] = (1.f - (xx2 + yy2)) * transform.Scale3D.Z;

    float yz2 = transform.Rotation.Y * z2;
    float wx2 = transform.Rotation.W * x2;
    matrix.M[2][1] = (yz2 - wx2) * transform.Scale3D.Z;
    matrix.M[1][2] = (yz2 + wx2) * transform.Scale3D.Y;

    float xy2 = transform.Rotation.X * y2;
    float wz2 = transform.Rotation.W * z2;
    matrix.M[1][0] = (xy2 - wz2) * transform.Scale3D.Y;
    matrix.M[0][1] = (xy2 + wz2) * transform.Scale3D.X;

    float xz2 = transform.Rotation.X * z2;
    float wy2 = transform.Rotation.W * y2;
    matrix.M[2][0] = (xz2 + wy2) * transform.Scale3D.Z;
    matrix.M[0][2] = (xz2 - wy2) * transform.Scale3D.X;

    matrix.M[0][3] = 0;
    matrix.M[1][3] = 0;
    matrix.M[2][3] = 0;
    matrix.M[3][3] = 1;

    return matrix;
}



FVector TransformToLocation(FTransform c2w, FTransform transform) {
    return MatrixToVector(MatrixMultiplication(TransformToMatrix(transform), TransformToMatrix(c2w)));
}


const char *GetLootName(APickUpListWrapperActor *Loot) {
     switch (Loot->BoxType) {
	case EPickUpBoxType::EPickUpBoxType__EPickUpBoxType_LootBox:
		return "LootBox";
		default:
        return "LootBox";
}
}

const char *GetVehicleName(ASTExtraVehicleBase *Vehicle) {
    switch (Vehicle->VehicleShapeType) {
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Motorbike:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Motorbike_SideCart:
            return "Motorbike";
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Dacia:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_HeavyDacia:
            return "Dacia";
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_MiniBus:
            return "Mini Bus";
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_PickUp:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_PickUp01:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_HeavyPickup:
            return "Pick Up";
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Buggy:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_HeavyBuggy:
            return "Buggy";
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_UAZ:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_UAZ01:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_UAZ02:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_UAZ03:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_HeavyUAZ:
            return "UAZ";
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_PG117:
            return "PG117";
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Aquarail:
            return "Aquarail";
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Mirado:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Mirado01:
            return "Mirado";
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Rony:
            return "Rony";
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Scooter:
            return "Scooter";
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_SnowMobile:
            return "Snow Mobile";
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_TukTukTuk:
            return "Tuk Tuk";
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_SnowBike:
            return "Snow Bike";
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Surfboard:
            return "Surf Board";
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Snowboard:
            return "Snow Board";
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Amphibious:
            return "Amphibious";
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_LadaNiva:
            return "Lada Niva";
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_UAV:
            return "UAV";
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_MegaDrop:
            return "Mega Drop";
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Lamborghini:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Lamborghini01:
            return "Lamborghini";
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_GoldMirado:
            return "Gold Mirado";
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_BigFoot:
            return "Big Foot";
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_UH60:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_HeavyUH60:
            return "UH60";
        default:
            return "Vehicle";
    }
}

FRotator ClampAngles(FRotator inRot) {
    FRotator outRot = inRot;
    if (outRot.Pitch > 180)
        outRot.Pitch -= 360;
    if (outRot.Pitch < -180)
        outRot.Pitch += 360;

    if (outRot.Pitch < -75.f)
        outRot.Pitch = -75.f;
    else if (outRot.Pitch > 75.f)
        outRot.Pitch = 75.f;

    while (outRot.Yaw < -180.0f)
        outRot.Yaw += 360.0f;
    while (outRot.Yaw > 180.0f)
        outRot.Yaw -= 360.0f;
    return outRot;
}/*
uint32_t Colors[] = {0x53BB0C, 0x530826, 0x0FC3F4, 0xDC2855, 0x0A31DE, 0xBAA7FD, 0xCEDB3F, 0x286A45, 0x58F014, 0x45CAE6, 0x773702, 0xB0CEF0, 0x3C5F51, 0x453CD7, 0x364024, 0x439997, 0x4CB612, 0xC6B564, 0x17F250, 0xE41BC0, 0xAF8E27, 0x8E382E, 0x47A101, 0x9DAC33, 0x66F4CF, 0x59A9F0, 0x798D1A, 0x2EBB59, 0xBF66C3, 0x4BD8FB, 0xBBFA54, 0x6B9881, 0x144967, 0xBAA3AE, 0xE80B9D, 0x7BA552, 0x96A456, 0x17D7B4, 0x130C39, 0x3C06A8, 0x62737E, 0xA87E89, 0xB6D3E4, 0x66B77D, 0x66E304, 0x1B80E1, 0x7A06BC, 0xBFFB1B, 0x618506, 0x7E4D34};
long GetRandomColorByIndex(int index) {
    srand(index);
    int a = 135;
    int r = ((Colors[rand() % sizeof(Colors)] & 0xFF0000) >> 16);
    int g = ((Colors[rand() % sizeof(Colors)] & 0x00FF00) >> 8);
    int b = (Colors[rand() % sizeof(Colors)] & 0x0000FF);
    return ARGB(r, g, b, a);
}
long GetRandomColorByIndex2(int index) {
    srand(index);
    int a = 255;
    int r = ((Colors[rand() % sizeof(Colors)] & 0xFF0000) >> 16);
    int g = ((Colors[rand() % sizeof(Colors)] & 0x00FF00) >> 8);
    int b = (Colors[rand() % sizeof(Colors)] & 0x0000FF);

    return ARGB(r, g, b, a);
}
*/
/*
uint32_t Colors[] = {
    0x53BB0C,
    0x530826, 
    0x0FC3F4, 
    0xDC2855, 
    0x0A31DE, 
    0xBAA7FD, 
    0xCEDB3F, 
    0x286A45, 
    0x58F014, 
    0x45CAE6,
    0x773702, 
    0xB0CEF0,
    0x3C5F51,
    0x453CD7,
    0x364024, 
    0x439997, 
    0x4CB612, 
    0xC6B564, 
    0x17F250, 
    0xE41BC0, 
    0xAF8E27,
    0x8E382E,
    0x47A101, 
    0x9DAC33, 
    0x66F4CF, 
    0x59A9F0,
    0x798D1A,
    0x2EBB59,
    0xBF66C3, 
    0x4BD8FB, 
    0xBBFA54,
    0x6B9881, 
    0x144967, 
    0xBAA3AE, 
    0xE80B9D, 
    0x7BA552,
    0x96A456, 
    0x17D7B4, 
    0x130C39, 
    0x3C06A8,
    0x62737E,
    0xA87E89,
    0xB6D3E4, 
    0x66B77D,
    0x66E304,
    0x1B80E1, 
    0x7A06BC,
    0xBFFB1B, 
    0x618506, 
    0x7E4D34,
    
                0x818181,
                0x0096FF,
                0xE91E63,
                0xFF00E1,
                0xAB00FF,
                0x6100FF,
                0x0051FF,
                0x00BCFF,
                0x00E4FF,
                0x00FFAE,
                0x00FF79,
                0x00FF31,
                0x8FFF00,
                0xE2FF00,
                0xE2FF00,
                0xFFC900,
                0xFF8000,
                0xB00082,
                0xA700B0,
                0x7600B0,
                0x4100B0,
                0x003EB0,
                0x0074B0,
                0x009BB0,
                0x00B07B,
                0x00B019,
                0x51B000,
                0x98B000,
                0xB08B00,
                0xB05800,

                0x818181,
                0x0096FF,
                0xE91E63,
                0xFF00E1,
                0xAB00FF,
                0x6100FF,
                0x0051FF,
                0x00BCFF,
                0x00E4FF,
                0x00FFAE,
                0x00FF79,
                0x00FF31,
                0x8FFF00,
                0xE2FF00,
                0xE2FF00,
                0xFFC900,
                0xFF8000,
                0xB00082,
                0xA700B0,
                0x7600B0,
                0x4100B0,
                0x003EB0,
                0x0074B0,
                0x009BB0,
                0x00B07B,
                0x00B019,
                0x51B000,
                0x98B000,
                0xB08B00,
                0xB05800,

                0x818181,
                0x0096FF,
                0xE91E63,
                0xFF00E1,
                0xAB00FF,
                0x6100FF,
                0x0051FF,
                0x00BCFF,
                0x00E4FF,
                0x00FFAE,
                0x00FF79,
                0x00FF31,
                0x8FFF00,
                0xE2FF00,
                0xE2FF00,
                0xFFC900,
                0xFF8000,
                0xB00082,
                0xA700B0,
                0x7600B0,
                0x4100B0,
                0x003EB0,
                0x0074B0,
                0x009BB0,
                0x00B07B,
                0x00B019,
                0x51B000,
                0x98B000,
                0xB08B00,
                0xB05800,

                0x818181,
                0x0096FF,
                0xE91E63,
                0xFF00E1,
                0xAB00FF,
                0x6100FF,
                0x0051FF,
                0x00BCFF,
                0x00E4FF,
                0x00FFAE,
                0x00FF79,
                0x00FF31,
                0x8FFF00,
                0xE2FF00,
                0xE2FF00,
                0xFFC900,
                0xFF8000,
                0xB00082,
                0xA700B0,
                0x7600B0,
                0x4100B0,
                0x003EB0,
                0x0074B0,
                0x009BB0,
                0x00B07B,
                0x00B019,
                0x51B000,
                0x98B000,
                0xB08B00,
                0xB05800,

                0x818181,
                0x0096FF,
                0xE91E63,
                0xFF00E1,
                0xAB00FF,
                0x6100FF,
                0x0051FF,
                0x00BCFF,
                0x00E4FF,
                0x00FFAE,
                0x00FF79,
                0x00FF31,
                0x8FFF00,
                0xE2FF00,
                0xE2FF00,
                0xFFC900,
                0xFF8000,
                0xB00082,
                0xA700B0,
                0x7600B0,
                0x4100B0,
                0x003EB0,
                0x0074B0,
                0x009BB0,
                0x00B07B,
                0x00B019,
                0x51B000,
                0x98B000,
                0xB08B00,
                0xB05800,

                0x818181,
                0x0096FF,
                0xE91E63,
                0xFF00E1,
                0xAB00FF,
                0x6100FF,
                0x0051FF,
                0x00BCFF,
                0x00E4FF,
                0x00FFAE,
                0x00FF79,
                0x00FF31,
                0x8FFF00,
                0xE2FF00,
                0xE2FF00,
                0xFFC900,
                0xFF8000,
                0xB00082,
                0xA700B0,
                0x7600B0,
                0x4100B0,
                0x003EB0,
                0x0074B0,
                0x009BB0,
                0x00B07B,
                0x00B019,
                0x51B000,
                0x98B000,
                0xB08B00,
                0xB05800,

                0x818181,
                0x0096FF,
                0xE91E63,
                0xFF00E1,
                0xAB00FF,
                0x6100FF,
                0x0051FF,
                0x00BCFF,
                0x00E4FF,
                0x00FFAE,
                0x00FF79,
                0x00FF31,
                0x8FFF00,
                0xE2FF00,
                0xE2FF00,
                0xFFC900,
                0xFF8000,
                0xB00082,
                0xA700B0,
                0x7600B0,
                0x4100B0,
                0x003EB0,
                0x0074B0,
                0x009BB0,
                0x00B07B,
                0x00B019,
                0x51B000,
                0x98B000,
                0xB08B00,
                0xB05800,

                0x818181,
                0x0096FF,
                0xE91E63,
                0xFF00E1,
                0xAB00FF,
                0x6100FF,
                0x0051FF,
                0x00BCFF,
                0x00E4FF,
                0x00FFAE,
                0x00FF79,
                0x00FF31,
                0x8FFF00,
                0xE2FF00,
                0xE2FF00,
                0xFFC900,
                0xFF8000,
                0xB00082,
                0xA700B0,
                0x7600B0,
                0x4100B0,
                0x003EB0,
                0x0074B0,
                0x009BB0,
                0x00B07B,
                0x00B019,
                0x51B000,
                0x98B000,
                0xB08B00,
                0xB05800,

                0x818181,
                0x0096FF,
                0xE91E63,
                0xFF00E1,
                0xAB00FF,
                0x6100FF,
                0x0051FF,
                0x00BCFF,
                0x00E4FF,
                0x00FFAE,
                0x00FF79,
                0x00FF31,
                0x8FFF00,
                0xE2FF00,
                0xE2FF00,
                0xFFC900,
                0xFF8000,
                0xB00082,
                0xA700B0,
                0x7600B0,
                0x4100B0,
                0x003EB0,
                0x0074B0,
                0x009BB0,
                0x00B07B,
                0x00B019,
                0x51B000,
                0x98B000,
                0xB08B00,
                0xB05800,

                0x818181,
                0x0096FF,
                0xE91E63,
                0xFF00E1,
                0xAB00FF,
                0x6100FF,
                0x0051FF,
                0x00BCFF,
                0x00E4FF,
                0x00FFAE,
                0x00FF79,
                0x00FF31,
                0x8FFF00,
                0xE2FF00,
                0xE2FF00,
                0xFFC900,
                0xFF8000,
                0xB00082,
                0xA700B0,
                0x7600B0,
                0x4100B0,
                0x003EB0,
                0x0074B0,
                0x009BB0,
                0x00B07B,
                0x00B019,
                0x51B000,
                0x98B000,
                0xB08B00,
                0xB05800,

                0x818181,
                0x0096FF,
                0xE91E63,
                0xFF00E1,
                0xAB00FF,
                0x6100FF,
                0x0051FF,
                0x00BCFF,
                0x00E4FF,
                0x00FFAE,
                0x00FF79,
                0x00FF31,
                0x8FFF00,
                0xE2FF00,
                0xE2FF00,
                0xFFC900,
                0xFF8000,
                0xB00082,
                0xA700B0,
                0x7600B0,
                0x4100B0,
                0x003EB0,
                0x0074B0,
                0x009BB0,
                0x00B07B,
                0x00B019,
                0x51B000,
                0x98B000,
                0xB08B00,
                0xB05800,

                0x818181,
                0x0096FF,
                0xE91E63,
                0xFF00E1,
                0xAB00FF,
                0x6100FF,
                0x0051FF,
                0x00BCFF,
                0x00E4FF,
                0x00FFAE,
                0x00FF79,
                0x00FF31,
                0x8FFF00,
                0xE2FF00,
                0xE2FF00,
                0xFFC900,
                0xFF8000,
                0xB00082,
                0xA700B0,
                0x7600B0,
                0x4100B0,
                0x003EB0,
                0x0074B0,
                0x009BB0,
                0x00B07B,
                0x00B019,
                0x51B000,
                0x98B000,
                0xB08B00,
                0xB05800,

                0x818181,
                0x0096FF,
                0xE91E63,
                0xFF00E1,
                0xAB00FF,
                0x6100FF,
                0x0051FF,
                0x00BCFF,
                0x00E4FF,
                0x00FFAE,
                0x00FF79,
                0x00FF31,
                0x8FFF00,
                0xE2FF00,
                0xE2FF00,
                0xFFC900,
                0xFF8000,
                0xB00082,
                0xA700B0,
                0x7600B0,
                0x4100B0,
                0x003EB0,
                0x0074B0,
                0x009BB0,
                0x00B07B,
                0x00B019,
                0x51B000,
                0x98B000,
                0xB08B00,
                0xB05800,

                0x818181,
                0x0096FF,
                0xE91E63,
                0xFF00E1,
                0xAB00FF,
                0x6100FF,
                0x0051FF,
                0x00BCFF,
                0x00E4FF,
                0x00FFAE,
                0x00FF79,
                0x00FF31,
                0x8FFF00,
                0xE2FF00,
                0xE2FF00,
                0xFFC900,
                0xFF8000,
                0xB00082,
                0xA700B0,
                0x7600B0,
                0x4100B0,
                0x003EB0,
                0x0074B0,
                0x009BB0,
                0x00B07B,
                0x00B019,
                0x51B000,
                0x98B000,
                0xB08B00,
                0xB05800,

                0x818181,
                0x0096FF,
                0xE91E63,
                0xFF00E1,
                0xAB00FF,
                0x6100FF,
                0x0051FF,
                0x00BCFF,
                0x00E4FF,
                0x00FFAE,
                0x00FF79,
                0x00FF31,
                0x8FFF00,
                0xE2FF00,
                0xE2FF00,
                0xFFC900,
                0xFF8000,
                0xB00082,
                0xA700B0,
                0x7600B0,
                0x4100B0,
                0x003EB0,
                0x0074B0,
                0x009BB0,
                0x00B07B,
                0x00B019,
                0x51B000,
                0x98B000,
                0xB08B00,
                0xB05800,

                0x818181,
                0x0096FF,
                0xE91E63,
                0xFF00E1,
                0xAB00FF,
                0x6100FF,
                0x0051FF,
                0x00BCFF,
                0x00E4FF,
                0x00FFAE,
                0x00FF79,
                0x00FF31,
                0x8FFF00,
                0xE2FF00,
                0xE2FF00,
                0xFFC900,
                0xFF8000,
                0xB00082,
                0xA700B0,
                0x7600B0,
                0x4100B0,
                0x003EB0,
                0x0074B0,
                0x009BB0,
                0x00B07B,
                0x00B019,
                0x51B000,
                0x98B000,
                0xB08B00,
                0xB05800,

                0x818181,
                0x0096FF,
                0xE91E63,
                0xFF00E1,
                0xAB00FF,
                0x6100FF,
                0x0051FF,
                0x00BCFF,
                0x00E4FF,
                0x00FFAE,
                0x00FF79,
                0x00FF31,
                0x8FFF00,
                0xE2FF00,
                0xE2FF00,
                0xFFC900,
                0xFF8000,
                0xB00082,
                0xA700B0,
                0x7600B0,
                0x4100B0,
                0x003EB0,
                0x0074B0,
                0x009BB0,
                0x00B07B,
                0x00B019,
                0x51B000,
                0x98B000,
                0xB08B00,
                0xB05800,

                0x818181,
                0x0096FF,
                0xE91E63,
                0xFF00E1,
                0xAB00FF,
                0x6100FF,
                0x0051FF,
                0x00BCFF,
                0x00E4FF,
                0x00FFAE,
                0x00FF79,
                0x00FF31,
                0x8FFF00,
                0xE2FF00,
                0xE2FF00,
                0xFFC900,
                0xFF8000,
                0xB00082,
                0xA700B0,
                0x7600B0,
                0x4100B0,
                0x003EB0,
                0x0074B0,
                0x009BB0,
                0x00B07B,
                0x00B019,
                0x51B000,
                0x98B000,
                0xB08B00,
                0xB05800,

                0x818181,
                0x0096FF,
                0xE91E63,
                0xFF00E1,
                0xAB00FF,
                0x6100FF,
                0x0051FF,
                0x00BCFF,
                0x00E4FF,
                0x00FFAE,
                0x00FF79,
                0x00FF31,
                0x8FFF00,
                0xE2FF00,
                0xE2FF00,
                0xFFC900,
                0xFF8000,
                0xB00082,
                0xA700B0,
                0x7600B0,
                0x4100B0,
                0x003EB0,
                0x0074B0,
                0x009BB0,
                0x00B07B,
                0x00B019,
                0x51B000,
                0x98B000,
                0xB08B00,
                0xB05800,

                0x818181,
                0x0096FF,
                0xE91E63,
                0xFF00E1,
                0xAB00FF,
                0x6100FF,
                0x0051FF,
                0x00BCFF,
                0x00E4FF,
                0x00FFAE,
                0x00FF79,
                0x00FF31,
                0x8FFF00,
                0xE2FF00,
                0xE2FF00,
                0xFFC900,
                0xFF8000,
                0xB00082,
                0xA700B0,
                0x7600B0,
                0x4100B0,
                0x003EB0,
                0x0074B0,
                0x009BB0,
                0x00B07B,
                0x00B019,
                0x51B000,
                0x98B000,
                0xB08B00,
                0xB05800,

                0x818181,
                0x0096FF,
                0xE91E63,
                0xFF00E1,
                0xAB00FF,
                0x6100FF,
                0x0051FF,
                0x00BCFF,
                0x00E4FF,
                0x00FFAE,
                0x00FF79,
                0x00FF31,
                0x8FFF00,
                0xE2FF00,
                0xE2FF00,
                0xFFC900,
                0xFF8000,
                0xB00082,
                0xA700B0,
                0x7600B0,
                0x4100B0,
                0x003EB0,
                0x0074B0,
                0x009BB0,
                0x00B07B,
                0x00B019,
                0x51B000,
                0x98B000,
                0xB08B00,
                0xB05800,

                0x818181,
                0x0096FF,
                0xE91E63,
                0xFF00E1,
                0xAB00FF,
                0x6100FF,
                0x0051FF,
                0x00BCFF,
                0x00E4FF,
                0x00FFAE,
                0x00FF79,
                0x00FF31,
                0x8FFF00,
                0xE2FF00,
                0xE2FF00,
                0xFFC900,
                0xFF8000,
                0xB00082,
                0xA700B0,
                0x7600B0,
                0x4100B0,
                0x003EB0,
                0x0074B0,
                0x009BB0,
                0x00B07B,
                0x00B019,
                0x51B000,
                0x98B000,
                0xB08B00,
                0xB05800,

                0x818181,
                0x0096FF,
                0xE91E63,
                0xFF00E1,
                0xAB00FF,
                0x6100FF,
                0x0051FF,
                0x00BCFF,
                0x00E4FF,
                0x00FFAE,
                0x00FF79,
                0x00FF31,
                0x8FFF00,
                0xE2FF00,
                0xE2FF00,
                0xFFC900,
                0xFF8000,
                0xB00082,
                0xA700B0,
                0x7600B0,
                0x4100B0,
                0x003EB0,
                0x0074B0,
                0x009BB0,
                0x00B07B,
                0x00B019,
                0x51B000,
                0x98B000,
                0xB08B00,
                0xB05800,

                0x818181,
                0x0096FF,
                0xE91E63,
                0xFF00E1,
                0xAB00FF,
                0x6100FF,
                0x0051FF,
                0x00BCFF,
                0x00E4FF,
                0x00FFAE,
                0x00FF79,
                0x00FF31,
                0x8FFF00,
                0xE2FF00,
                0xE2FF00,
                0xFFC900,
                0xFF8000,
                0xB00082,
                0xA700B0,
                0x7600B0,
                0x4100B0,
                0x003EB0,
                0x0074B0,
                0x009BB0,
                0x00B07B,
                0x00B019,
                0x51B000,
                0x98B000,
                0xB08B00,
                0xB05800,

                0x818181,
                0x0096FF,
                0xE91E63,
                0xFF00E1,
                0xAB00FF,
                0x6100FF,
                0x0051FF,
                0x00BCFF,
                0x00E4FF,
                0x00FFAE,
                0x00FF79,
                0x00FF31,
                0x8FFF00,
                0xE2FF00,
                0xE2FF00,
                0xFFC900,
                0xFF8000,
                0xB00082,
                0xA700B0,
                0x7600B0,
                0x4100B0,
                0x003EB0,
                0x0074B0,
                0x009BB0,
                0x00B07B,
                0x00B019,
                0x51B000,
                0x98B000,
                0xB08B00,
                0xB05800,

                0x818181,
                0x0096FF,
                0xE91E63,
                0xFF00E1,
                0xAB00FF,
                0x6100FF,
                0x0051FF,
                0x00BCFF,
                0x00E4FF,
                0x00FFAE,
                0x00FF79,
                0x00FF31,
                0x8FFF00,
                0xE2FF00,
                0xE2FF00,
                0xFFC900,
                0xFF8000,
                0xB00082,
                0xA700B0,
                0x7600B0,
                0x4100B0,
                0x003EB0,
                0x0074B0,
                0x009BB0,
                0x00B07B,
                0x00B019,
                0x51B000,
                0x98B000,
                0xB08B00,
                0xB05800,

                0x818181,
                0x0096FF,
                0xE91E63,
                0xFF00E1,
                0xAB00FF,
                0x6100FF,
                0x0051FF,
                0x00BCFF,
                0x00E4FF,
                0x00FFAE,
                0x00FF79,
                0x00FF31,
                0x8FFF00,
                0xE2FF00,
                0xE2FF00,
                0xFFC900,
                0xFF8000,
                0xB00082,
                0xA700B0,
                0x7600B0,
                0x4100B0,
                0x003EB0,
                0x0074B0,
                0x009BB0,
                0x00B07B,
                0x00B019,
                0x51B000,
                0x98B000,
                0xB08B00,
                0xB05800,

                0x818181,
                0x0096FF,
                0xE91E63,
                0xFF00E1,
                0xAB00FF,
                0x6100FF,
                0x0051FF,
                0x00BCFF,
                0x00E4FF,
                0x00FFAE,
                0x00FF79,
                0x00FF31,
                0x8FFF00,
                0xE2FF00,
                0xE2FF00,
                0xFFC900,
                0xFF8000,
                0xB00082,
                0xA700B0,
                0x7600B0,
                0x4100B0,
                0x003EB0,
                0x0074B0,
                0x009BB0,
                0x00B07B,
                0x00B019,
                0x51B000,
                0x98B000,
                0xB08B00,
                0xB05800,

                0x818181,
                0x0096FF,
                0xE91E63,
                0xFF00E1,
                0xAB00FF,
                0x6100FF,
                0x0051FF,
                0x00BCFF,
                0x00E4FF,
                0x00FFAE,
                0x00FF79,
                0x00FF31,
                0x8FFF00,
                0xE2FF00,
                0xE2FF00,
                0xFFC900,
                0xFF8000,
                0xB00082,
                0xA700B0,
                0x7600B0,
                0x4100B0,
                0x003EB0,
                0x0074B0,
                0x009BB0,
                0x00B07B,
                0x00B019,
                0x51B000,
                0x98B000,
                0xB08B00,
                0xB05800,

                0x818181,
                0x0096FF,
                0xE91E63,
                0xFF00E1,
                0xAB00FF,
                0x6100FF,
                0x0051FF,
                0x00BCFF,
                0x00E4FF,
                0x00FFAE,
                0x00FF79,
                0x00FF31,
                0x8FFF00,
                0xE2FF00,
                0xE2FF00,
                0xFFC900,
                0xFF8000,
                0xB00082,
                0xA700B0,
                0x7600B0,
                0x4100B0,
                0x003EB0,
                0x0074B0,
                0x009BB0,
                0x00B07B,
                0x00B019,
                0x51B000,
                0x98B000,
                0xB08B00,
                0xB05800,

                0x818181,
                0x0096FF,
                0xE91E63,
                0xFF00E1,
                0xAB00FF,
                0x6100FF,
                0x0051FF,
                0x00BCFF,
                0x00E4FF,
                0x00FFAE,
                0x00FF79,
                0x00FF31,
                0x8FFF00,
                0xE2FF00,
                0xE2FF00,
                0xFFC900,
                0xFF8000,
                0xB00082,
                0xA700B0,
                0x7600B0,
                0x4100B0,
                0x003EB0,
                0x0074B0,
                0x009BB0,
                0x00B07B,
                0x00B019,
                0x51B000,
                0x98B000,
                0xB08B00,
                0xB05800,

                0x818181,
                0x0096FF,
                0xE91E63,
                0xFF00E1,
                0xAB00FF,
                0x6100FF,
                0x0051FF,
                0x00BCFF,
                0x00E4FF,
                0x00FFAE,
                0x00FF79,
                0x00FF31,
                0x8FFF00,
                0xE2FF00,
                0xE2FF00,
                0xFFC900,
                0xFF8000,
                0xB00082,
                0xA700B0,
                0x7600B0,
                0x4100B0,
                0x003EB0,
                0x0074B0,
                0x009BB0,
                0x00B07B,
                0x00B019,
                0x51B000,
                0x98B000,
                0xB08B00,
                0xB05800,

                0x818181,
                0x0096FF,
                0xE91E63,
                0xFF00E1,
                0xAB00FF,
                0x6100FF,
                0x0051FF,
                0x00BCFF,
                0x00E4FF,
                0x00FFAE,
                0x00FF79,
                0x00FF31,
                0x8FFF00,
                0xE2FF00,
                0xE2FF00,
                0xFFC900,
                0xFF8000,
                0xB00082,
                0xA700B0,
                0x7600B0,
                0x4100B0,
                0x003EB0,
                0x0074B0,
                0x009BB0,
                0x00B07B,
                0x00B019,
                0x51B000,
                0x98B000,
                0xB08B00,
                0xB05800,

                0x818181,
                0x0096FF,
                0xE91E63,
                0xFF00E1,
                0xAB00FF,
                0x6100FF,
                0x0051FF,
                0x00BCFF,
                0x00E4FF,
                0x00FFAE,
                0x00FF79,
                0x00FF31,
                0x8FFF00,
                0xE2FF00,
                0xE2FF00,
                0xFFC900,
                0xFF8000,
                0xB00082,
                0xA700B0,
                0x7600B0,
                0x4100B0,
                0x003EB0,
                0x0074B0,
                0x009BB0,
                0x00B07B,
                0x00B019,
                0x51B000,
                0x98B000,
                0xB08B00,
                0xB05800,

                0x818181,
                0x0096FF,
                0xE91E63,
                0xFF00E1,
                0xAB00FF,
                0x6100FF,
                0x0051FF,
                0x00BCFF,
                0x00E4FF,
                0x00FFAE,
                0x00FF79,
                0x00FF31,
                0x8FFF00,
                0xE2FF00,
                0xE2FF00,
                0xFFC900,
                0xFF8000,
                0xB00082,
                0xA700B0,
                0x7600B0,
                0x4100B0,
                0x003EB0,
                0x0074B0,
                0x009BB0,
                0x00B07B,
                0x00B019,
                0x51B000,
                0x98B000,
                0xB08B00,
                0xB05800

        };
*/
// ================================================================================================================================ //
uint32_t Colorshh[] = {
   0x53BB0C, 0x530826, 0x0FC3F4, 0xDC2855, 0x0A31DE, 0xBAA7FD, 0xCEDB3F, 0x286A45, 0x58F014, 0x45CAE6, 0x773702, 0xB0CEF0, 0x3C5F51, 0x453CD7, 0x364024, 0x439997, 0x4CB612, 0xC6B564, 0x17F250, 0xE41BC0, 0xAF8E27, 0x8E382E, 0x47A101, 0x9DAC33, 0x66F4CF, 0x59A9F0, 0x798D1A, 0x2EBB59, 0xBF66C3, 0x4BD8FB, 0xBBFA54, 0x6B9881, 0x144967, 0xBAA3AE, 0xE80B9D, 0x7BA552, 0x96A456, 0x17D7B4, 0x130C39, 0x3C06A8, 0x62737E, 0xA87E89, 0xB6D3E4, 0x66B77D, 0x66E304, 0x1B80E1, 0x7A06BC, 0xBFFB1B, 0x618506, 0x7E4D34};
/*
long GetRandomColorByIndex(int index) {
    srand(index);

    int a = 135;
    int r = ((Colorshh[rand() % sizeof(Colorshh)] & 0xFF0000) >> 16);
    int g = ((Colorshh[rand() % sizeof(Colorshh)] & 0x00FF00) >> 8);
    int b = (Colorshh[rand() % sizeof(Colorshh)] & 0x0000FF);

    return ARGB(a, r, g, b);
}

long GetRandomColorByIndex2(int index) {
    srand(index);

    int a = 255;
    int r = ((Colorshh[rand() % sizeof(Colorshh)] & 0xFF0000) >> 16);
    int g = ((Colorshh[rand() % sizeof(Colorshh)] & 0x00FF00) >> 8);
    int b = (Colorshh[rand() % sizeof(Colorshh)] & 0x0000FF);

    return ARGB(a, r, g, b);
}

long GetRandomColorByIndexAlpa(int index) {
    srand(index);
    int a = 100;
    int r = ((Colorshh[rand() % sizeof(Colorshh)] & 0xFF0000) >> 16);
    int g = ((Colorshh[rand() % sizeof(Colorshh)] & 0x00FF00) >> 8);
    int b = (Colorshh[rand() % sizeof(Colorshh)] & 0x0000FF);
    return ARGB(a, r, g, b);
}
*/
int skeletonByDistance2(int distance){
    int _colorByDistance;
    if (distance < 450)
        _colorByDistance = 0xFF6AFF4B;
    if (distance < 100)
        _colorByDistance = 0xFF6AFF4B;
    if (distance < 60)
        _colorByDistance = 0xFFFFF51C;
    if (distance < 15)
        _colorByDistance = 0xFFFF0000;
    return _colorByDistance;
}




#define IM_PI                   3.14159265358979323846f
#define RAD2DEG(x) ((float)(x) * (float)(180.f / IM_PI))
#define DEG2RAD(x) ((float)(x) * (float)(IM_PI / 180.f))


FVector WorldToRadar(float Yaw, FVector Origin, FVector LocalOrigin, float PosX, float PosY, Vector3 Size, bool & outbuff) {
    bool flag = false;
    double num = (double)Yaw;
    double num2 = num * 0.017453292519943295;
    float num3 = (float)std::cosf(num2);
    float num4 = (float)std::sinf(num2);
    float num5 = Origin.X - LocalOrigin.X;
    float num6 = Origin.Y - LocalOrigin.Y;
    FVector Xector;
    Xector.X = (num6 * num3 - num5 * num4) / 150.f;
    Xector.Y = (num5 * num3 + num6 * num4) / 150.f;
    FVector Xector2;
    Xector2.X = Xector.X + PosX + Size.X / 2.f;
    Xector2.Y = -Xector.Y + PosY + Size.Y / 2.f;
    bool flag2 = Xector2.X > PosX + Size.X;
    if (flag2) {
        Xector2.X = PosX + Size.X;
    } else {
        bool flag3 = Xector2.X < PosX;
        if (flag3) {
            Xector2.X = PosX;
        }
    }
    bool flag4 = Xector2.Y > PosY + Size.Y;
    if (flag4) {
        Xector2.Y = PosY + Size.Y;
    } else {
        bool flag5 = Xector2.Y < PosY;
        if (flag5) {
            Xector2.Y = PosY;
        }
    }
    bool flag6 = Xector2.Y == PosY || Xector2.X == PosX;
    if (flag6) {
        flag = true;
    }
    outbuff = flag;
    return Xector2;
}

void VectorAnglesRadar(Vector3 & forward, FVector & angles) {
    if (forward.X == 0.f && forward.Y == 0.f) {
        angles.X = forward.Z > 0.f ? -90.f : 90.f;
        angles.Y = 0.f;
    } else {
        angles.X = RAD2DEG(atan2(-forward.Z, forward.Magnitude(forward)));
        angles.Y = RAD2DEG(atan2(forward.Y, forward.X));
    }
    angles.Z = 0.f;
}



void RotateTriangle(std::array<Vector3, 3> & points, float rotation) {
    const auto points_center = (points.at(0) + points.at(1) + points.at(2)) / 3;
    for (auto & point : points) {
        point = point - points_center;
        const auto temp_x = point.X;
        const auto temp_y = point.Y;
        const auto theta = DEG2RAD(rotation);
        const auto c = cosf(theta);
        const auto s = sinf(theta);
        point.X = temp_x * c - temp_y * s;
        point.Y = temp_x * s + temp_y * c;
        point = point + points_center;
    }
}

void RotateArrows(std::array<Vector3, 7>& points, float rotation) {
const auto points_center = (points.at(0) + points.at(1) + points.at(2)) / 3;
for (auto& point : points) {
point = point - points_center;
const auto temp_x = point.X;
const auto temp_y = point.Y;
const auto theta = DEG2RAD(rotation);
const auto c = cosf(theta);
const auto s = sinf(theta);
point.X = temp_x * c - temp_y * s;
point.Y = temp_x * s + temp_y * c;
point = point + points_center;
 }
}



FVector2D pushToScreenBorder(FVector2D Pos, FVector2D screen, int borders, int offset) {
    int x = (int)Pos.X;
    int y = (int)Pos.Y;
    if ((borders & 1) == 1) {
        y = 0 - offset;
    }
    if ((borders & 2) == 2) {
        x = (int)screen.X + offset;
    }
    if ((borders & 4) == 4) {
        y = (int)screen.Y + offset;
    }
    if ((borders & 8) == 8) {
        x = 0 - offset;
    }
    return FVector2D(x, y);
}

int isOutsideSafezone(Vector2 pos, Vector2 screen) {
    Vector2 mSafezoneTopLeft(screen.X * 0.04f, screen.Y * 0.04f);
    Vector2 mSafezoneBottomRight(screen.X * 0.96f, screen.Y * 0.96f);

    int result = 0;
    if (pos.Y < mSafezoneTopLeft.Y) {
        result |= 1;
    }
    if (pos.X > mSafezoneBottomRight.X) {
        result |= 2;
    }
    if (pos.Y > mSafezoneBottomRight.Y) {
        result |= 4;
    }
    if (pos.X < mSafezoneTopLeft.X) {
        result |= 8;
    }
    return result;
}

Vector2 pushToScreenBorder(Vector2 Pos, Vector2 screen, int borders, int offset) {
    int x = (int)Pos.X;
    int y = (int)Pos.Y;
    if ((borders & 1) == 1) {
        y = 0 - offset;
    }
    if ((borders & 2) == 2) {
        x = (int)screen.X + offset;
    }
    if ((borders & 4) == 4) {
        y = (int)screen.Y + offset;
    }
    if ((borders & 8) == 8) {
        x = 0 - offset;
    }
    return Vector2(x, y);
}

void AimAngle(FRotator &angles) {
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
