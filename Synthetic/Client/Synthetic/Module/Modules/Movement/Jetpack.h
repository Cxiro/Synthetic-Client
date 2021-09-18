#ifndef CLIENT_SYNTHETIC_MODULE_MODULES_MOVEMENT_JETPACK
#define CLIENT_SYNTHETIC_MODULE_MODULES_MOVEMENT_JETPACK

#include "../../Module.h"

class Jetpack : public Module {
public:
    Jetpack(Manager* manager, Category* category) : Module(manager, category, "Jetpack"){
        this->setKey(0x46); /* F */
    };

    void onGameMode(GameMode*) override;

    float speed = 1.f;
};

#endif /* CLIENT_SYNTHETIC_MODULE_MODULES_MOVEMENT_JETPACK */