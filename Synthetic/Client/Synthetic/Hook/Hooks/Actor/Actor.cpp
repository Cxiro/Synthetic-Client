#include "Actor.h"

#include "../../../Manager/Manager.h"
#include "../../../Category/Category.h"
#include "../../../Module/Module.h"

Hook_Actor::Hook_Actor(Manager* manager){
    this->setManager(manager);
    this->init();
};

typedef void(__thiscall* setRot)(Actor*, Vec2<float>*);
setRot _setRot;

Manager* a_manager = nullptr;

void setRot_Callback(Actor* entity, Vec2<float>* rot){
    
    if(a_manager != nullptr){
        for(auto c : a_manager->getCategories()){
            for(auto m : c->modules){
                if(m->getState())
                    m->onActorRot(entity, rot);
            };
        };
    };

    _setRot(entity, rot);
};

void Hook_Actor::init(){
    auto sig = Mem::findSig("48 89 5C 24 ? 57 48 83 EC ? 8B 42 ? 48 8B F9 48 81");

    a_manager = this->getManager();
    
    if(sig){
        if(MH_CreateHook((void*)sig, &setRot_Callback, reinterpret_cast<LPVOID*>(&_setRot)) == MH_OK){
            Utils::debugLogF("Successfully created hook for Actor Rotation hook!");
            MH_EnableHook((void*)sig);
        }
        else {
            Utils::debugLogF("Failed to create hook for Actor Rotation hook!");
        };
    }
    else {
        Utils::debugLogF("Failed to find signature for Actor Rotation hook!");
    };
};