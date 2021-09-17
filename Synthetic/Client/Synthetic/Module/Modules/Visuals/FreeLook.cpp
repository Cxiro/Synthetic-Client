#include "FreeLook.h"

void FreeLook::onEnable(){
    auto instance = Minecraft::getClientInstance();

    if(instance == nullptr)
        return;

    auto player = instance->getPlayer();

    if(player == nullptr)
        return;

    bodyRot = *player->bodyRot();
    writeToRot = true;
};

void FreeLook::onDisable(){
    writeToRot = false;

    auto instance = Minecraft::getClientInstance();

    if(instance == nullptr)
        return;
    
    auto player = instance->getPlayer();
    auto settings = instance->getSettings();

    if(settings == nullptr || player == nullptr)
        return;
    
    settings->cameraState = 0;
    *player->bodyRot() = bodyRot;
};

void FreeLook::onClientInstance(ClientInstance* instance){
    if(instance == nullptr)
        return;
    
    auto player = instance->getPlayer();

    if(player == nullptr)
        return;
    
    auto settings = instance->getSettings();

    if(settings == nullptr)
        return;
    
    if(writeToRot)
        settings->cameraState = 1;
};

void FreeLook::onActorRot(Actor* entity, Vec2<float>* rot){
    auto instance = Minecraft::getClientInstance();

    if(instance == nullptr)
        return;
    
    auto player = instance->getPlayer();

    if(player == nullptr)
        return;
    
    if(player != entity)
        return;
    
    if(writeToRot)
        *rot = bodyRot;
};