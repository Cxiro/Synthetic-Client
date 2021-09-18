#ifndef CLIENT_SYNTHETIC_MODULE_MODULES_PLAYER_AUTOSPRINT
#define CLIENT_SYNTHETIC_MODULE_MODULES_PLAYER_AUTOSPRINT

#include "../../Module.h"

class AutoSprint : public Module {
public:
    AutoSprint(Manager* manager, Category* category) : Module(manager, category, "AutoSprint"){
        //
    };

    void onGameMode(GameMode*) override;
};

#endif /* CLIENT_SYNTHETIC_MODULE_MODULES_PLAYER_AUTOSPRINT */