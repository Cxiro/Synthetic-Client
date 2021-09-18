#include "TestModule.h"

void TestModule::onEnable(){
    //
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
    RenderUtils::drawString("Test", 1.f, Vec2<float>(10.f, 10.f), Color(255, 255, 255));
};