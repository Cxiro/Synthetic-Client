#ifndef CLIENT_SYNTHETIC_HOOK_HOOKS_CLIENTINSTANCE_CLIENTINSTANCE
#define CLIENT_SYNTHETIC_HOOK_HOOKS_CLIENTINSTANCE_CLIENTINSTANCE

#include "../../Hook.h"

class Hook_ClientInstance : public Hook {
public:
    Hook_ClientInstance(Manager*);
    void init() override;
};

#endif /* CLIENT_SYNTHETIC_HOOK_HOOKS_CLIENTINSTANCE_CLIENTINSTANCE */