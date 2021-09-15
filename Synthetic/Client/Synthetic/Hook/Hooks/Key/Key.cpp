#include "Key.h"

#include "../../../Manager/Manager.h"
#include "../../../Category/Category.h"
#include "../../../Module/Module.h"

Hook_Key::Hook_Key(Manager* manager){
    this->setManager(manager);
    this->init();
};

typedef void(__thiscall* key)(uint64_t, bool);
key _key;

Manager* k_manager = nullptr;

void key_Callback(uint64_t key, bool isDown){
    auto canUseKeys = [] (){
        auto instance = Minecraft::getClientInstance();

        if(instance == nullptr)
            return false;
        
        auto game = instance->getMinecraftGame();

        if(game != nullptr)
            return game->canUseKeys;

        return false;
    };

    if(canUseKeys() && isDown){
        for(auto c : k_manager->getCategories()){
            for(auto m : c->modules){
                if(m->getKey() == key)
                    m->toggleState();
            };
        };
    };

    bool cancel = false;

    for(auto c : k_manager->getCategories()){
        for(auto m : c->modules){
            if(m->getState())
                m->onKey(key, isDown, &cancel);
        };
    };

    if(!cancel) _key(key, isDown);
};

void Hook_Key::init(){
    auto sig = Mem::findSig("48 89 5C 24 ? ? 48 83 EC ? 8B 05 ? ? ? ? 8B DA");

    k_manager = this->getManager();

    if(!sig)
        return Utils::debugLogF("Unable to find signature needed for Key hook!");
    
    if(MH_CreateHook((void*)sig, &key_Callback, reinterpret_cast<LPVOID*>(&_key)) == MH_OK){
        Utils::debugLogF("Successfully created hook for Key hook!");
        MH_EnableHook((void*)sig);
    }
    else {
        Utils::debugLogF("Failed to create hook for Key hook!");
    };
};