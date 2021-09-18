#include "AirJump.h"

void AirJump::onGameMode(GameMode* GM){
    if(GM == nullptr)
        return;
    
    auto player = GM->player;

    if(player == nullptr)
        return;
    
    *player->groundState() = true;
};