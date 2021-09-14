#include "ClientInstance.h"

Player* ClientInstance::getPlayer(){
    static unsigned int offset = NULL;
    if(offset == NULL)
        offset = *reinterpret_cast<int*>(Mem::findSig("48 8B 89 ? ? ? ? 48 85 C9 ? ? 33 C0 48 8B 5C 24 ?") + 3);
    return *reinterpret_cast<Player**>((uintptr_t)(this) + offset);
};