#include "ClientInstance.h"

#include "../../../Manager/Manager.h"
#include "../../../Category/Category.h"
#include "../../../Module/Module.h"

Hook_ClientInstance::Hook_ClientInstance(Manager* manager){
    this->setManager(manager);
    this->init();
};

typedef void(__thiscall* tick)(ClientInstance*, void*);
tick _tick;

Manager* c_manager = nullptr;

void callback(ClientInstance* instance, void* a2){
    Minecraft::setClientInstance(instance);
    if(c_manager != nullptr){
        for(auto c : c_manager->getCategories()){
            for(auto m : c->modules)
                m->onClientInstance(instance);
        };
    };
    _tick(instance, a2);
};

void Hook_ClientInstance::init(){
    auto sig = Mem::findSig("48 8B 81 ? ? ? ? C3 CC CC CC CC CC CC CC CC 40 55 53");

    c_manager = this->getManager();
    
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