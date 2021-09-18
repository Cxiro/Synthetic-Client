#ifndef CLIENT_SYNTHETIC_MODULE_MODULES_VISUALS_ZOOM
#define CLIENT_SYNTHETIC_MODULE_MODULES_VISUALS_ZOOM

#include "../../Module.h"

class Zoom : public Module {
public:
    Zoom(Manager* manager, Category* category) : Module(manager, category, "Zoom"){
        this->setKey(0x43);
    };

    void onGameMode(GameMode*) override;
    void onDisable() override;
};

#endif /* CLIENT_SYNTHETIC_MODULE_MODULES_VISUALS_ZOOM */