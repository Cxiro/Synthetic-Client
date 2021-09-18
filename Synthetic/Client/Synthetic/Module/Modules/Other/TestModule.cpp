#include "TestModule.h"

void TestModule::onEnable(){
    auto instance = Minecraft::getClientInstance();

    if(instance == nullptr)
        return;
    
    instance->releaseMouse();

    Sleep(2000);

    instance->grabMouse();

    this->setState(false);
};

void TestModule::onDisable(){
    //
};

void TestModule::onClientInstance(ClientInstance* instance){
    //
};

void TestModule::onActorRot(Actor* entity, Vec2<float>* rot){
    //
};

void TestModule::onRenderCtx(MinecraftUIRenderContext* ctx){
    //
};