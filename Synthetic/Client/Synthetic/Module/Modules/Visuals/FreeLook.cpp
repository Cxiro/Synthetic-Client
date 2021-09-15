#include "FreeLook.h"

void FreeLook::onEnable(){
    auto instance = Minecraft::getClientInstance();

    if(instance == nullptr)
        return;

    auto player = instance->getPlayer();
    auto settings = instance->getSettings();

    if(settings == nullptr || player == nullptr)
        return;
    
    savedCameraState = settings->cameraState;
    bodyRot = *player->getRot();
};

void FreeLook::onDisable(){
    auto instance = Minecraft::getClientInstance();

    if(instance == nullptr)
        return;
    
    auto player = instance->getPlayer();
    auto settings = instance->getSettings();

    if(settings == nullptr || player == nullptr)
        return;
    
    settings->cameraState = savedCameraState;
    *player->getRot() = bodyRot;
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
    
    *rot = bodyRot;
};