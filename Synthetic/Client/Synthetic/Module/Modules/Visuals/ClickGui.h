#ifndef CLIENT_SYNTHETIC_MODULE_MODULES_VISUALS_CLICKGUI
#define CLIENT_SYNTHETIC_MODULE_MODULES_VISUALS_CLICKGUI

#include "../../Module.h"

class ClickGui : public Module {
public:
    ClickGui(Manager* manager, Category* category) : Module(manager, category, "Click GUI"){
        this->setKey(VK_INSERT);
    };

    void onRenderCtx(MinecraftUIRenderContext*) override;
    void onKey(uint64_t, bool, bool*) override;
    void onMouse(char, bool, Vec2<short>, bool*) override;
    void onEnable() override;
    void onDisable() override;

    char mouseAction = (char)NULL;
    bool mouseIsDown = false;
    Vec2<short> mousePos = Vec2<short>();

    bool grabbedMouse = false;
    bool canUseMod(MinecraftUIRenderContext*);
};

#endif /* CLIENT_SYNTHETIC_MODULE_MODULES_VISUALS_CLICKGUI */