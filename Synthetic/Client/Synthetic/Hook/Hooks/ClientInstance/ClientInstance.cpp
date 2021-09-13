#include "ClientInstance.h"

Hook_ClientInstance::Hook_ClientInstance(Manager* manager){
    this->setManager(manager);
    this->init();
};

typedef void(__thiscall* tick)(void*, ClientInstance*);
tick _tick;

Manager* i_manager = nullptr;

void callback(void* a1, ClientInstance* instance){
    Minecraft::setClientInstance(instance);

    if(i_manager != nullptr){
        //
    };

    _tick(a1, instance);
};

void Hook_ClientInstance::init(){
    auto sig = Mem::findSig("48 8B 81 ? ? ? ? C3 CC CC CC CC CC CC CC CC 40 55");
    
    if(!sig)
        return;
    
    i_manager = this->getManager();
    
    if(MH_CreateHook((void*)sig, &callback, reinterpret_cast<LPVOID*>(&_tick)) == MH_OK){
        Utils::debugLogF("Successfully created hook for ClientInstance tick!");
        if(MH_EnableHook((void*)sig) == MH_OK){
            Utils::debugLogF("Successfully enabled hook!");
        }
        else {
            Utils::debugLogF("Failed to enable hook!");
        };
    }
    else {
        Utils::debugLogF("Failed to hook onto ClientInstance tick!");
    };
};