#ifndef CLIENT_SYNTHETIC_MODULE_MODULES_VISUALS_TABGUI
#define CLIENT_SYNTHETIC_MODULE_MODULES_VISUALS_TABGUI

#include "../../Module.h"

class TabGui : public Module {
public:
    TabGui(Manager* manager, Category* category) : Module(manager, category, "TabGui"){
        this->setKey(VK_TAB);
        this->setState(true);
    };

    void onRenderCtx(MinecraftUIRenderContext*) override;
    void onKey(uint64_t, bool, bool*) override;
    void onDisable() override;
    
    void updateAlpha();
    void renderLogo();

    float alpha = 0.f;

    int currCat = 0;
    int currMod = 0;
    bool selectedCat = false;
    bool selectedMod = false;
    float selectedCatOff = 0.f;
    float selectedModOff = 0.f;
};

#endif /* CLIENT_SYNTHETIC_MODULE_MODULES_VISUALS_TABGUI */