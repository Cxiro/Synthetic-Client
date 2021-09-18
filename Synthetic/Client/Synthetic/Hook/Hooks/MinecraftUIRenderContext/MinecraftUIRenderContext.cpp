#include "MinecraftUIRenderContext.h"

#include "../../../Manager/Manager.h"
#include "../../../Category/Category.h"
#include "../../../Module/Module.h"

Hook_MinecraftUIRenderContext::Hook_MinecraftUIRenderContext(Manager* manager){
    this->setManager(manager);
    this->init();
};

typedef void(__thiscall* tick)(void*, MinecraftUIRenderContext*);
tick _tick;

Manager* r_manager = nullptr;

void tick_Callback(void* a1, MinecraftUIRenderContext* ctx){

    auto instance = ctx->instance;

    if(instance != nullptr){
        auto mcGame = instance->getMinecraftGame();
        if(mcGame != nullptr)
            RenderUtils::setData(ctx, mcGame->font);
    };
    
    if(r_manager != nullptr){
        for(auto c : r_manager->getCategories()){
            for(auto m : c->modules){
                if(m->getState())
                    m->onRenderCtx(ctx);
            };
        };
    };

    _tick(a1, ctx);
};

void Hook_MinecraftUIRenderContext::init(){
    auto sig = Mem::findSig("48 8B C4 48 89 58 ? 55 56 57 41 54 41 55 41 56 41 57 48 8D A8 ? ? ? ? 48 81 EC ? ? ? ? 0F 29 70 ? 0F 29 78 ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 85 ? ? ? ? 4C 8B FA 48 89 54 24 ?");

    r_manager = this->getManager();

    if(!sig)
        return Utils::debugLogF("Failed to find signature for MinecraftUIRenderContext hook!");
    
    if(MH_CreateHook((void*)sig, &tick_Callback, reinterpret_cast<LPVOID*>(&_tick)) == MH_OK){
        Utils::debugLogF("Successfully created hook for MinecraftUIRenderContext");
        MH_EnableHook((void*)sig);
    }
    else {
        Utils::debugLogF("Failed to hook onto MinecraftUIRenderContext");
    };
};