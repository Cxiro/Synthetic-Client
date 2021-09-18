#include "MineplexFlight.h"

Vec3<float> savedPos = Vec3<float>(0, 0, 0);

void MineplexFlight::onGameMode(GameMode* GM){
    if(GM == nullptr)
        return;
    
    auto player = GM->player;

    if(player == nullptr)
        return;
    
    if(savedPos == Vec3<float>(0, 0, 0))
        savedPos = *player->getPos();

    float yaw = (player->bodyRot()->y + 90.f);
    float speed = 1.f;

    auto vel = Vec3<float>(cos((yaw) * (PI / 180.f)) * speed, 1.f, sin((yaw) * (PI / 180.f)) * speed);

    float x = -vel.x;
    float y = 0.006f;
    float z = -vel.z;
    float idk = 1.f;

    player->knockback(player, 0.f, x, z, idk, y, y);
    player->velocity()->y = 0.f;
    
    if(player->getPos()->y != savedPos.y) {
        auto currPos = *player->getPos();
        currPos.y = savedPos.y;
        player->setPos(&currPos);
    };
};

void MineplexFlight::onPacket(Packet* packet, bool* cancel){
    if(strcmp(packet->getName().c_str(), "MovePlayerPacket") == 0){
        auto currPacket = (MovePlayerPacket*)packet;
        currPacket->pos.y = savedPos.y;
    };
};

void MineplexFlight::onTick(){
    auto instance = Minecraft::getClientInstance();
    
    if(instance == nullptr)
        return;
    
    auto player = instance->getPlayer();

    if(player == nullptr)
        this->setState(false);
};

void MineplexFlight::onEnable(){
    auto instance = Minecraft::getClientInstance();
    
    if(instance == nullptr)
        return;
    
    auto player = instance->getPlayer();

    if(player == nullptr)
        return;
    
    savedPos = *player->getPos();
};

void MineplexFlight::onDisable(){
    savedPos = Vec3<float>(0, 0, 0);
};