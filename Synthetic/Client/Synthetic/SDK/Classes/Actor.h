#ifndef CLIENT_SYNTHETIC_SDK_CLASSES_ACTOR
#define CLIENT_SYNTHETIC_SDK_CLASSES_ACTOR

class Actor {
public:
    Vec2<float>* getRot(){
        return reinterpret_cast<Vec2<float>*>((uintptr_t)(this) + 0x140);
    };
};

#endif /* CLIENT_SYNTHETIC_SDK_CLASSES_ACTOR */