#ifndef CLIENT_SYNTHETIC_MODULE_MODULES_VISUALS_FREELOOK
#define CLIENT_SYNTHETIC_MODULE_MODULES_VISUALS_FREELOOK

#include "../../Module.h"

class FreeLook : public Module {
public:
    FreeLook(Manager* manager, Category* category) : Module(manager, category, "Free Look"){
        this->setKey(0x43);
    };

    void onEnable() override;
    void onDisable() override;

    void onClientInstance(ClientInstance*) override;
    void onActorRot(Actor*, Vec2<float>*) override;

private:
    bool writeToRot = false;
    Vec2<float> bodyRot;
};

#endif /* CLIENT_SYNTHETIC_MODULE_MODULES_VISUALS_FREELOOK */
