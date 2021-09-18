#ifndef CLIENT_SYNTHETIC_MODULE_MODULES_VISUALS_MODULELIST
#define CLIENT_SYNTHETIC_MODULE_MODULES_VISUALS_MODULELIST

#include "../../Module.h"

class ModuleList : public Module {
public:
    ModuleList(Manager* manager, Category* category) : Module(manager, category, "Module List"){
        this->setState(true);
    };

    void onRenderCtx(MinecraftUIRenderContext*) override;

    void updateAlpha();

    bool init = false;
    float alpha = 0.f;
};

#endif /* CLIENT_SYNTHETIC_MODULE_MODULES_VISUALS_MODULELIST */