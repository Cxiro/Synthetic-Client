#ifndef CLIENT_SYNTHETIC_HOOK_HOOKS_GAMEMODE_GAMEMODE
#define CLIENT_SYNTHETIC_HOOK_HOOKS_GAMEMODE_GAMEMODE

#include "../../Hook.h"

class Hook_GameMode : public Hook {
public:
    Hook_GameMode(Manager* manager);
    void init() override;
};

#endif /* CLIENT_SYNTHETIC_HOOK_HOOKS_GAMEMODE_GAMEMODE */