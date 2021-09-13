#ifndef CLIENT_SYNTHETIC_MODULE_MODULES_TESTMODULE
#define CLIENT_SYNTHETIC_MODULE_MODULES_TESTMODULE

#include "../Module.h"

class TestModule : public Module {
public:
    TestModule(Manager* manager) : Module(manager, "Test Module"){
        //
    };
};

#endif /* CLIENT_SYNTHETIC_MODULE_MODULES_TESTMODULE */