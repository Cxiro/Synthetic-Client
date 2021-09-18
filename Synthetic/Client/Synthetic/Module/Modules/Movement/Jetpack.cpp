#include "Jetpack.h"

#include "../../../Manager/Manager.h"

void Jetpack::onGameMode(GameMode* GM){
    if(GM == nullptr || GM->player == nullptr)
        return;
    
    if(!this->getManager()->isUsingKey(this->getKey()))
        return this->setState(false);
    
    auto bodyRot = *GM->player->bodyRot();
    auto angles = Vec2<float>((bodyRot.x) * -(3.14159 / 180.f), (bodyRot.y + 90.f) * (3.14159 / 180.f));
    *GM->player->velocity() = Vec3<float>(cos(angles.y) * cos(angles.x) * speed, sin(angles.x) * speed, sin(angles.y) * cos(angles.x) * speed);
};