#ifndef CLIENT_SYNTHETIC_MODULE_MODULES_COMBAT_HITBOX
#define CLIENT_SYNTHETIC_MODULE_MODULES_COMBAT_HITBOX

#include "../../Module.h"

class Hitbox : public Module {
public:
    Hitbox(Manager* manager, Category* category) : Module(manager, category, "Hitbox"){
        //
    };

    void onGameMode(GameMode*) override;
    void onDisable() override;

    bool doMobs = true;
    bool doPlayers = true;

    Vec2<float> colis = Vec2<float>(2.f, 6.f);
};

#endif /* CLIENT_SYNTHETIC_MODULE_MODULES_COMBAT_HITBOX */