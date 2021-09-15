#ifndef CLIENT_SYNTHETIC_HOOK_HOOKS_ACTOR_ACTOR
#define CLIENT_SYNTHETIC_HOOK_HOOKS_ACTOR_ACTOR

#include "../../Hook.h"

class Hook_Actor : public Hook {
public:
    Hook_Actor(Manager*);
    void init() override;
};

#endif /* CLIENT_SYNTHETIC_HOOK_HOOKS_ACTOR_ACTOR */