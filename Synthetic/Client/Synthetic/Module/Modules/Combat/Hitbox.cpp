#include "Hitbox.h"

std::map<uint8_t, Vec2<float>> collisions = std::map<uint8_t, Vec2<float>>();

void Hitbox::onGameMode(GameMode* GM){
    if(GM == nullptr || GM->player == nullptr)
        return;
    
    auto player = GM->player;

    auto level = player->getLevel();

    if(level == nullptr)
        return;
    
    auto entities = std::vector<Actor*>();

    if(doMobs){
        for(auto e : level->getEntities()){
            if(e == nullptr)
                continue;
            entities.push_back(e);
        };
    };

    if(doPlayers){
        for(auto e : level->getPlayers()){
            if(e == nullptr || e == player)
                continue;
            entities.push_back(e);
        };
    };

    if(entities.empty())
        return;
    
    if(collisions.empty()){
        for(auto e : entities){
            collisions[e->getEntityTypeId()] = *e->collision();
        };
    };
    
    for(auto e : entities){
        if(e == nullptr)
            continue;
        if(!e->isAlive() || e->outOfWorld())
            continue;
        if(!player->canAttack(e, false))
            continue;
        
        if(collisions.find(e->getEntityTypeId()) == collisions.end())
            collisions[e->getEntityTypeId()] = *e->collision();
        
        e->setSize(colis.x, colis.y);
    };
};

void Hitbox::onDisable(){
    auto instance = Minecraft::getClientInstance();

    if(instance == nullptr)
        return;
    
    auto player = instance->getPlayer();

    if(player == nullptr)
        return;
    
    auto level = player->getLevel();

    if(level == nullptr)
        return;
    
    auto entities = std::vector<Actor*>();

    for(auto e : level->getEntities()){
        if(e == nullptr)
            continue;
        entities.push_back(e);
    };

    for(auto e : level->getPlayers()){
        if(e == nullptr || e == player)
            continue;
        entities.push_back(e);
    };

    if(entities.empty())
        return;
    
    for(auto e : entities){
        if(e == nullptr)
            continue;
        if(collisions.find(e->getEntityTypeId()) != collisions.end()){
            auto entCollision = collisions[e->getEntityTypeId()];
            e->setSize(entCollision.x, entCollision.y);
        };
    };
};