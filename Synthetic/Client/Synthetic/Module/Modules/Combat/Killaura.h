#ifndef CLIENT_SYNTHETIC_MODULE_MODULES_COMBAT_KILLAURA
#define CLIENT_SYNTHETIC_MODULE_MODULES_COMBAT_KILLAURA

#include "../../Module.h"

class Killaura : public Module {
public:
    Killaura(Manager* manager, Category* category) : Module(manager, category, "Killaura"){
        this->setKey(0x4B); /* K */
    };

    void onGameMode(GameMode*) override;
    void onActorRot(Actor*, Vec2<float>*) override;

    bool targetPlayers = true;
    bool targetMobs = true;
    bool multi = true;
    float dist = 12.f;
};

#endif /* CLIENT_SYNTHETIC_MODULE_MODULES_COMBAT_KILLAURA */