#ifndef CLIENT_SYNTHETIC_HOOK_HOOKS_KEY_KEY
#define CLIENT_SYNTHETIC_HOOK_HOOKS_KEY_KEY

#include "../../Hook.h"

class Hook_Key : public Hook {
public:
    Hook_Key(Manager*);
    void init() override;
};

#endif /* CLIENT_SYNTHETIC_HOOK_HOOKS_KEY_KEY */