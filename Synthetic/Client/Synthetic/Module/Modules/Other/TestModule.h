#ifndef CLIENT_SYNTHETIC_MODULE_MODULES_TESTMODULE
#define CLIENT_SYNTHETIC_MODULE_MODULES_TESTMODULE

#include "../../Module.h"

class TestModule : public Module {
public:
    TestModule(Manager* manager, Category* category) : Module(manager, category, "Test Module"){
        //
    };

    void onEnable() override;
    void onDisable() override;

    void onClientInstance(ClientInstance*) override;
    void onActorRot(Actor*, Vec2<float>*) override;
    void onRenderCtx(MinecraftUIRenderContext*) override;

private:
    int savedCameraState = 0;
};

#endif /* CLIENT_SYNTHETIC_MODULE_MODULES_TESTMODULE */