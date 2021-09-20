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
    void onMouse(char, bool, Vec2<float>, bool*) override;
    void onMouseMove(char, bool, Vec2<float>, bool*) override;
    void onEnable() override;
    void onDisable() override;

    bool grabbedMouse = false;
    Vec2<float> mousePos = Vec2<float>();
    Vec2<float> dragStart = Vec2<float>();
};

#endif /* CLIENT_SYNTHETIC_MODULE_MODULES_VISUALS_CLICKGUI */
