#include "Zoom.h"

#include "../../../Manager/Manager.h"

void Zoom::onGameMode(GameMode* GM){
    if(GM == nullptr || GM->player == nullptr)
        return this->setState(false);
    
    GM->player->setFieldOfViewModifier(0.4f);

    if(!this->getManager()->isUsingKey(this->getKey()))
        this->setState(false);
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