#include "Killaura.h"

void Killaura::onGameMode(GameMode* GM){
    auto player = GM->player;

    if(player == nullptr)
        return;
    
    auto myPos = player->getPos();
    auto level = player->getLevel();

    if(level == nullptr)
        return;
    
    std::vector<Actor*> entities = std::vector<Actor*>();

    if(targetPlayers){
        auto players = level->getPlayers();
        
        for(auto p : players){
            if(p == nullptr || p == player)
                continue;
            
            if(!p->isAlive() || p->outOfWorld())
                continue;
            
            entities.push_back(p);
        };
    };

    if(targetMobs){
        auto mobs = level->getEntities();
        
        for(auto e : mobs){
            if(e == nullptr)
                continue;
            
            if(!e->isAlive() || e->outOfWorld())
                continue;
            
            entities.push_back(e);
            Utils::debugLogF("Pushed Mob!");
        };
    };

    if(multi){
        for(auto e : entities){
            if(e == nullptr || !e->isAlive() || e->outOfWorld())
                continue;
            
            auto pos = e->getPos();
            
            float dX = myPos->x - pos->x;
            float dY = myPos->y - pos->y;
            float dZ = myPos->z - pos->z;

            auto distance = std::sqrt(dX * dX + dY * dY + dZ * dZ);

            if(distance <= dist){
                GM->attack(e);
                player->swing();
            };
        };
    }
    else {
        std::vector<float> dists = std::vector<float>();

        for(auto e : entities){
            if(e == nullptr || !e->isAlive() || e->outOfWorld())
                continue;
            
            auto pos = e->getPos();
            
            float dX = myPos->x - pos->x;
            float dY = myPos->y - pos->y;
            float dZ = myPos->z - pos->z;

            auto distance = std::sqrt(dX * dX + dY * dY + dZ * dZ);

            dists.push_back(distance);
        };

        if(dists.empty())
            return;

        std::sort(dists.begin(), dists.end());

        for(auto e : entities){
            if(e == nullptr || !e->isAlive() || e->outOfWorld())
                continue;
            
            auto pos = e->getPos();
            
            float dX = myPos->x - pos->x;
            float dY = myPos->y - pos->y;
            float dZ = myPos->z - pos->z;

            auto distance = std::sqrt(dX * dX + dY * dY + dZ * dZ);

            if(distance == dists.at(0)){
                GM->attack(e);
                player->swing();
                
                break;
            };
        };
    };
};

void Killaura::onActorRot(Actor*, Vec2<float>* bodyRot){
    //
};