#ifndef CLIENT_SYNTHETIC_SDK_CLASSES_PLAYERINVENTORY
#define CLIENT_SYNTHETIC_SDK_CLASSES_PLAYERINVENTORY

#include "Container.h"

class PlayerInventory {
public:
    Container* getInventory(){
        static unsigned int offset = 0;
        if(offset == NULL)
            offset = *reinterpret_cast<int*>(Mem::findSig("48 8B 8A ? ? ? ? 8B 52 ? 48 8B 01 48 FF 60 ? 48") + 3);
        return *reinterpret_cast<Container**>((uintptr_t)(this) + offset);
    };
};

#endif /* CLIENT_SYNTHETIC_SDK_CLASSES_PLAYERINVENTORY */