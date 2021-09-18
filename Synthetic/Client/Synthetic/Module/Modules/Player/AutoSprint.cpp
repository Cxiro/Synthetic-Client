#include "AutoSprint.h"

void AutoSprint::onGameMode(GameMode* GM){
    if(GM == nullptr)
        return;
    
    auto player = GM->player;

    if(player == nullptr)
        return;
    
    player->setSprinting(true);
};