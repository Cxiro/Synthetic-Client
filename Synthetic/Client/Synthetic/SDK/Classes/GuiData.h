#ifndef CLIENT_SYNTHETIC_SDK_CLASSES_GUIDATA
#define CLIENT_SYNTHETIC_SDK_CLASSES_GUIDATA

class GuiData {
public:
    char pad_0000[24]; //0x0000
	Vec2<float> res; //0x0018
	char pad_0020[8]; //0x0020
	Vec2<float> scaledRes; //0x0028
	char pad_0030[8]; //0x0030
	float scale; //0x0038
	char pad_003C[20]; //0x003C
	Vec2<short> mousePos; //0x0050
};

#endif /* CLIENT_SYNTHETIC_SDK_CLASSES_GUIDATA */