#include "TestModule.h"

void TestModule::onEnable(){
    auto instance = Minecraft::getClientInstance();

    if(instance == nullptr)
        return;
    
    auto player = instance->getPlayer();

    if(player == nullptr)
        return;
    
    auto level = player->getLevel();

    if(level == nullptr)
        return;
    
    auto entities = level->getEntities();

    if(entities.empty())
        return Utils::debugLogF("Empty!");
    
    std::string msg = std::string(std::string("Entities: " + std::to_string(entities.size())));

    player->displayClientMessage(&msg);

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