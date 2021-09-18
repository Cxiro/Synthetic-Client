#ifndef CLIENT_SYNTHETIC_MODULE_MODULES_MOVEMENT_AIRJUMP
#define CLIENT_SYNTHETIC_MODULE_MODULES_MOVEMENT_AIRJUMP

#include "../../Module.h"

class AirJump : public Module {
public:
    AirJump(Manager* manager, Category* category) : Module(manager, category, "AirJump"){
        //
    };

    void onGameMode(GameMode*) override;
};

#endif /* CLIENT_SYNTHETIC_MODULE_MODULES_MOVEMENT_AIRJUMP */