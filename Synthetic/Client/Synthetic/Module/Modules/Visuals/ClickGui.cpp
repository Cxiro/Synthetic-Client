#include "ClickGui.h"

#include "../../../Manager/Manager.h"
#include "../../../Category/Category.h"

class VWindowItem {
private:
    std::string text;
public:
    VWindowItem(std::string text) {
        this->text = text;
    };

    auto getText() -> std::string {
        return this->text;
    };
    auto setText(std::string text) -> void {
        this->text = text;
    };
};

class VWindowButton : public VWindowItem {
private:
    bool* toggle;
public:
    VWindowButton(std::string text, bool* toggle) : VWindowItem(text) {
        this->toggle = toggle;
    };
};

class VWindow {
private:
    std::string name;
    bool expanded = false;
    Vec4<float> windowRect = Vec4<float>();
    std::vector<VWindowItem*> windowItems = std::vector<VWindowItem*>();
public:
    VWindow(std::string name, Vec4<float> windowRect, bool expanded = false) {
        this->name = name;
        this->windowRect = windowRect;
        this->expanded = expanded;
    };

    auto getName() -> std::string {
        return this->name;
    };

    auto getWindowRect() -> Vec4<float> {
        return this->windowRect;
    };

    auto fixWindowRect() -> void {
        windowRect.w = windowItems.size() * 13;
        
        auto currLen = RenderUtils::getTextLen(name, 1);

        for(auto item : windowItems){
            auto len = RenderUtils::getTextLen(item->getText(), 1);

            if(len > currLen)
                currLen = len;
        };

        windowRect.z = windowRect.x + currLen;
    };

    auto addWindowItem(VWindowItem* item) -> void {
        this->windowItems.push_back(item);
    };
};

std::vector<VWindow*> windows = std::vector<VWindow*>();

void ClickGui::onRenderCtx(MinecraftUIRenderContext* ctx){
    if(windows.empty()){
        int I = 0;
        for(auto c : this->getManager()->getCategories()){
            if(c->modules.empty())
                continue;
            
            auto windowRect = Vec4<float>(I * 60, I * 10, 0, 0);
            auto window = new VWindow(c->name, windowRect);

            for(auto m : c->modules){
                auto button = new VWindowButton(m->getName(), &m->isEnabled);
                window->addWindowItem(button);
            };

            windows.push_back(window);

            I++;
        };
    };

    if(!canUseMod(ctx))
        return;
    
    auto instance = ctx->instance;
    
    if(instance == nullptr)
        return this->setState(false);
    
    auto data = instance->getGuiData();
    
    if(data == nullptr)
        return this->setState(false);
    
    auto scale = data->scale;
    auto mousePos = data->mousePos;

    mousePos.x *= scale;
    mousePos.y *= scale;
    
    if(windows.empty())
        return;
    
    for(auto window : windows){
        window->fixWindowRect();

        auto windowRect = window->getWindowRect();
    };
};

void ClickGui::onKey(uint64_t key, bool isDown, bool* cancel){
    if(key == VK_ESCAPE || key == 0x45)
        return this->setState(false);
    
    *cancel = true;
};

void ClickGui::onMouse(char action, bool isDown, Vec2<short> pos, bool* cancel){
    this->mouseAction = action;
    this->mouseIsDown = isDown;
    this->mousePos = pos;
};

void ClickGui::onEnable(){
    auto instance = Minecraft::getClientInstance();

    if(instance == nullptr)
        return;
    
    instance->releaseMouse();
    grabbedMouse = true;
};

void ClickGui::onDisable(){
    auto instance = Minecraft::getClientInstance();

    if(instance == nullptr)
        return;
    
    instance->grabMouse();
    grabbedMouse = false;
};

bool ClickGui::canUseMod(MinecraftUIRenderContext* ctx){
    if(!grabbedMouse)
        return false;

    auto instance = ctx->instance;

    if(instance == nullptr){
        this->setState(false);
        return false;
    };
    
    auto mcGame = instance->getMinecraftGame();

    if(mcGame == nullptr){
        this->setState(false);
        return false;
    };
    
    if(mcGame->canUseKeys){
        this->setState(false);
        return false;
    };
    
    auto data = instance->getGuiData();

    if(data == nullptr){
        this->setState(false);
        return false;
    };
    
    return true;
};