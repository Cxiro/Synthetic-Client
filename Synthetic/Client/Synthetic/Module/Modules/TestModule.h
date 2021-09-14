#ifndef CLIENT_SYNTHETIC_MODULE_MODULES_TESTMODULE
#define CLIENT_SYNTHETIC_MODULE_MODULES_TESTMODULE

#include "../Module.h"

class TestModule : public Module {
public:
    TestModule(Manager* manager, Category* category) : Module(manager, category, "Test Module"){
        this->setState(true);
    };

    void onTick() override;
    void onEnable() override;
    void onDisable() override;
};

#endif /* CLIENT_SYNTHETIC_MODULE_MODULES_TESTMODULE */