#ifndef CLIENT_SYNTHETIC_MODULE_MODULES_OTHER_MINEPLEXFLIGHT
#define CLIENT_SYNTHETIC_MODULE_MODULES_OTHER_MINEPLEXFLIGHT

#include "../../Module.h"

class MineplexFlight : public Module {
public:
    MineplexFlight(Manager* manager, Category* category) : Module(manager, category, "Mineplex Flight"){
        //
    };

    void onGameMode(GameMode*) override;
    void onPacket(Packet*, bool*) override;
    void onTick() override;
    void onEnable() override;
    void onDisable() override;
};

#endif /* CLIENT_SYNTHETIC_MODULE_MODULES_OTHER_MINEPLEXFLIGHT */