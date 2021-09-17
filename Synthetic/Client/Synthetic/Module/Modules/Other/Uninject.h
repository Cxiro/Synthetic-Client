#ifndef CLIENT_SYNTHETIC_MODULE_MODULES_OTHER_UNINJECT
#define CLIENT_SYNTHETIC_MODULE_MODULES_OTHER_UNINJECT

#include "../../Module.h"

class Uninject : public Module {
public:
    Uninject(Manager* manager, Category* category) : Module(manager, category, "Uninject"){
        this->setKey(0x55);
    };

    void onEnable() override;
};

#endif /* CLIENT_SYNTHETIC_MODULE_MODULES_OTHER_UNINJECT */