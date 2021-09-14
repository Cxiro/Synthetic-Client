#include "ClientInstance.h"

#include "../../../Manager/Manager.h"
#include "../../../Category/Category.h"
#include "../../../Module/Module.h"

Hook_ClientInstance::Hook_ClientInstance(Manager* manager){
    this->setManager(manager);
    this->init();
};

typedef void(__thiscall* tick)(void*, ClientInstance*);
tick _tick;

void callback(void* a1, ClientInstance* instance){
    Minecraft::setClientInstance(instance);
    _tick(a1, instance);
};

void Hook_ClientInstance::init(){
    auto sig = Mem::findSig("48 8B 89 ? ? ? ? 48 85 C9 ? ? 33 C0 48 8B 5C 24 ?");
    
    if(!sig)
        return;
    
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