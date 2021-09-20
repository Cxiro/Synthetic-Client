#include "Mouse.h"

#include "../../../Manager/Manager.h"
#include "../../../Category/Category.h"
#include "../../../Module/Module.h"

Hook_Mouse::Hook_Mouse(Manager* manager){
    this->setManager(manager);
    this->init();
};

typedef void(__thiscall* Mouse)(void*, char, bool, short x, short y, void*, void*, void*);
Mouse _Mouse;

Manager* m_manager = nullptr;

void mouse_Callback(void* p1, char action, bool isDown, float x, float y, void* p6, void* p7, void* p8){
    bool cancel = false;

    if(m_manager != nullptr){
        for(auto c : m_manager->getCategories()){
            for(auto m : c->modules){
                if(m->getState()){
                    if(action){
                        m->onMouse(action, isDown, Vec2<float>(x, y), &cancel);
                    }
                    else {
                        m->onMouseMove(action, isDown, Vec2<float>(x, y), &cancel);
                    };
                }
            };
        };
    };
    
    if(!cancel) _Mouse(p1, action, isDown, x, y, p6, p7, p8);
};

void Hook_Mouse::init(){
    auto sig = Mem::findSig("48 8B C4 48 89 58 ? 48 89 68 ? 48 89 70 ? 57 41 54 41 55 41 56 41 57 48 83 EC ? 44 0F");

    m_manager = this->getManager();

    if(!sig)
        return Utils::debugLogF("Failed to find signature for Mouse hook!");
    
    if(MH_CreateHook((void*)sig, &mouse_Callback, reinterpret_cast<LPVOID*>(&_Mouse)) == MH_OK){
        Utils::debugLogF("Successfully created hook for Mouse hook!");
        MH_EnableHook((void*)sig);
    }
    else {
        Utils::debugLogF("Failed to create hook for Mouse hook!");
    };
};