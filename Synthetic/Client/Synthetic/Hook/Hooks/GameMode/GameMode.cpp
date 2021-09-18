#include "GameMode.h"

#include "../../../Manager/Manager.h"
#include "../../../Category/Category.h"
#include "../../../Module/Module.h"

Hook_GameMode::Hook_GameMode(Manager* manager){
    this->setManager(manager);
    this->init();
};

typedef void(__thiscall* tick)(GameMode*);
tick _tick;

Manager* g_manager = nullptr;

void tick_Callback(GameMode* GM){
    
    if(g_manager != nullptr){
        for(auto c : g_manager->getCategories()){
            for(auto m : c->modules){
                if(m->getState())
                    m->onGameMode(GM);
            };
        };
    };

    _tick(GM);
};

void Hook_GameMode::init(){
    auto sig = Mem::findSig("48 8D 05 ? ? ? ? 48 89 01 48 89 51 08 48 C7 41 ? ? ? ? ? C7 41 ? ? ? ? ? 44 88 61 1C");

    g_manager = this->getManager();

    if(!sig)
        return Utils::debugLogF("Failed to find signature for GameMode VTable!");
    
    int offset = *reinterpret_cast<int*>(sig + 3);
    uintptr_t** VTable = reinterpret_cast<uintptr_t**>(sig + offset + 7);
    
    if(MH_CreateHook((void*)VTable[8], &tick_Callback, reinterpret_cast<LPVOID*>(&_tick)) == MH_OK){
        Utils::debugLogF("Successfully created hook for GameMode tick");
        MH_EnableHook((void*)VTable[8]);
    }
    else {
        Utils::debugLogF("Failed to hook onto GameMode tick");
    };
};