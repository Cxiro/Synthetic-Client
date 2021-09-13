#include "Minecraft.h"

ClientInstance* Minecraft::instance = nullptr; /* Static pointer */

ClientInstance* Minecraft::getClientInstance(){
    if(instance == nullptr)
        return nullptr;
    return instance;
};

void Minecraft::setClientInstance(ClientInstance* ptr){
    if(ptr == nullptr)
        return;
    instance = ptr;
};