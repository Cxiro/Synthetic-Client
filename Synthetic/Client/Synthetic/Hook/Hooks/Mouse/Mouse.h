#ifndef CLIENT_SYNTHETIC_HOOK_HOOKS_MOUSE_MOUSE
#define CLIENT_SYNTHETIC_HOOK_HOOKS_MOUSE_MOUSE

#include "../../Hook.h"

class Hook_Mouse : public Hook {
public:
    Hook_Mouse(Manager* manager);
    void init() override;
};

#endif /* CLIENT_SYNTHETIC_HOOK_HOOKS_MOUSE_MOUSE */