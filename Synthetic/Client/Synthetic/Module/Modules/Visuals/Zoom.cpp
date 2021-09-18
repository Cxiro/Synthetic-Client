#include "Zoom.h"

void Zoom::onGameMode(GameMode* GM){
    if(GM == nullptr || GM->player == nullptr)
        return;
    
    GM->player->setFieldOfViewModifier(0.4f);
};

void Zoom::onDisable(){
    auto instance = Minecraft::getClientInstance();

    if(instance == nullptr)
        return;
    
    auto player = instance->getPlayer();

    if(player == nullptr)
        return;
    
    player->setFieldOfViewModifier(1.0f);
};