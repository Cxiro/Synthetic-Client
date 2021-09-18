#ifndef CLIENT_SYNTHETIC_SDK_CLASSES_PACKET
#define CLIENT_SYNTHETIC_SDK_CLASSES_PACKET

class PacketFuncs {
private:
    virtual ~PacketFuncs();
public:
    virtual void Function0();
    virtual std::string getName();
};

class Packet {
public:
    uintptr_t** VTable;
    std::string getName(){
        return ((PacketFuncs*)(this))->getName();
    };

    template<class T>
    bool isType(){
        T packet;
        return packet.VTable == this->VTable;
    };
};

class MovePlayerPacket : public Packet {
private:
	char pad_0008[40];  //0x0008
public:
	uint64_t runtimeId; //0x0030
	Vec3<float> pos;    //0x0038
	Vec2<float> rot;    //0x0044
	float headYaw;      //0x004C
	char pad_0050[60];  //0x0050
public:
    MovePlayerPacket(){
        memset(this, 0, sizeof(this));
        this->VTable = GetVTable();
    };
    MovePlayerPacket(__int64 runtimeId, Vec3<float> pos, Vec2<float> bodyRot, float headYaw = 0.f){
        memset(this, 0, sizeof(this));
        this->VTable = GetVTable();
        this->runtimeId = runtimeId;
        this->pos = pos;
        this->rot = bodyRot;
        this->headYaw = headYaw ? headYaw : bodyRot.y;
    };
    uintptr_t** GetVTable(){
        static uintptr_t** vtable = nullptr;
        if(vtable == nullptr){
            auto sig = Mem::findSig("48 8D 05 ? ? ? ? 48 89 01 48 8B 82 70 ? ? ? 48 89");
            int offset = *reinterpret_cast<int*>(sig + 3);
            vtable = reinterpret_cast<uintptr_t**>(sig + offset + 7);
        }
        return vtable;
    };
};

class PlayerAuthInputPacket : public Packet {
public:
    PlayerAuthInputPacket(){
        memset(this, 0, sizeof(this));
        this->VTable = GetVTable();
    };
    uintptr_t** GetVTable(){
        static uintptr_t** vtable = nullptr;
        if(vtable == nullptr){
            auto sig = Mem::findSig("48 8D 05 ? ? ? ? 48 8B D9 48 89 01 48 81 C1 ? ? ? ? E8 ? ? ? ? 48 8B BB ? ? ? ? 48 85 FF");
            int offset = *reinterpret_cast<int*>(sig + 3);
            vtable = reinterpret_cast<uintptr_t**>(sig + offset + 7);
        }
        return vtable;
    };
};

class TextPacket : public Packet {
private:
    char pad_0008[40];
public:
	int8_t type;
private:
    char pad_0031[7];
public:
    std::string sourceName;
    std::string message;
private:
    char pad_0048[24];
public:
    bool translationNeeded = false;
private:
    char pad_0061[7];
public:
    std::string xboxUserId;
    std::string platformChatId;
public:
    TextPacket(){
        memset(this, 0, sizeof(this));
        VTable = GetVTable();
    };
    TextPacket(std::string message){
        memset(this, 0, sizeof(this));
        VTable = GetVTable();
        this->type = 1;
        this->translationNeeded = false;
        this->message = message;
        this->sourceName = std::string("");
    };
    uintptr_t** GetVTable(){
        static uintptr_t** vtable = nullptr;
        if(vtable == nullptr){
            auto sig = Mem::findSig("48 8D 05 ?? ?? ?? ?? 48 8B F9 48 89 01 48 83 C1 ?? E8 ?? ?? ?? ?? 48 8D 8F");
            int offset = *reinterpret_cast<int*>(sig + 3);
            vtable = reinterpret_cast<uintptr_t**>(sig + offset + 7);
        }
        return vtable;
    };
};

#endif /* CLIENT_SYNTHETIC_SDK_CLASSES_PACKET */