#ifndef CLIENT_SYNTHETIC_MODULE_MODULES_COMBAT_KILLAURA
#define CLIENT_SYNTHETIC_MODULE_MODULES_COMBAT_KILLAURA

#include "../../Module.h"

class Killaura : public Module {
public:
    Killaura(Manager* manager, Category* category) : Module(manager, category, "Killaura"){
        this->setKey(0x4B); /* K */
    };
};

#endif /* CLIENT_SYNTHETIC_MODULE_MODULES_COMBAT_KILLAURA */