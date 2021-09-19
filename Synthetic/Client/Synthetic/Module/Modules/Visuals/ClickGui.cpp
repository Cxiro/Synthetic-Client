#include "ClickGui.h"

#include "../../../Manager/Manager.h"
#include "../../../Category/Category.h"

class VWindowItem {
public:
    //
};

class VWindow {
private:
    std::string name;
    bool expanded = false;
    Vec4<float> windowRect = Vec4<float>();
    std::vector<VWindowItem*> windowItems = std::vector<VWindowItem*>();
public:
    VWindow(std::string name, Vec4<float> windowRect, bool expanded = false){
        this->name = name;
        this->windowRect = windowRect;
        this->expanded = expanded;
    };

    auto addWindowItem(VWindowItem* item) -> void {
        this->windowItems.push_back(item);
    };

    bool intersects(Vec2<float> position){
        //
    };
};

std::vector<VWindow*> windows = std::vector<VWindow*>();

void ClickGui::onRenderCtx(MinecraftUIRenderContext* ctx){
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
    
    //
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