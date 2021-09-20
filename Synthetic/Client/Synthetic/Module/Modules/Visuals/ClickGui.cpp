#include "ClickGui.h"

#include "../../../Manager/Manager.h"
#include "../../../Synthetic.h"
#include "../../../Category/Category.h"

class VItem;

class VWindow {
public:
    std::vector<VItem*> items = std::vector<VItem*>();
    
    Vec4<float> windowTitleRect = Vec4<float>();
    Vec4<float> windowRect = Vec4<float>();

    float titleBarStretchY = 0;
    bool expanded = false;
    std::string name;

    Color titleBarColor = Color(20, 20, 20);
    Color titleColor = Color(50, 200, 220);

    Color bgColor = Color(36, 36, 36);
    Color textColor = Color(60, 245, 168);

    Vec2<float> titlePos;
    Vec4<float> titleRect;
    Vec4<float> bodyRect;
public:
    VWindow(std::string name, Vec2<float> titleRect){
        this->name = name;
        this->titlePos = Vec2<float>(titleRect.x + RenderUtils::getTextLen(name, 1), titleRect.y);
        this->titleBarStretchY = 20.f;
    };
};

enum class VItemType {
    Button,
    ModuleButton,
    Unknown
};

class VItem {
public:
    VWindow* window;
    std::string text;
    VItemType type = VItemType::Unknown;
    Vec4<float> elementRect = Vec4<float>();
public:
    VItem(VWindow* window, std::string text) {
        this->window = window;
        this->text = text;
        this->type = VItemType::Unknown;
    };
};

class VButton : public VItem {
private:
    bool* toggle;
public:
    VButton(VWindow* window, std::string text, bool* toggle) : VItem(window, text) {
        this->toggle = toggle;
        this->type = VItemType::Button;
    };
};

class VModuleButton : public VItem {
public:
    Module* module;
public:
    VModuleButton(VWindow* window, Module* module) : VItem(window, module->getName()) {
        this->module = module;
        this->type = VItemType::ModuleButton;
    };
};

std::vector<VWindow*> windows = std::vector<VWindow*>();
VWindow* draggingWindow = nullptr;

void ClickGui::onRenderCtx(MinecraftUIRenderContext* ctx){
    if(!grabbedMouse)
        return;
    
    auto instance = ctx->instance;
    
    if(instance == nullptr)
        return this->setState(false);
    
    auto data = instance->getGuiData();
    auto mcGame = instance->getMinecraftGame();

    if(data == nullptr || mcGame == nullptr)
        return this->setState(false);
    
    if(mcGame->canUseKeys)
        return this->setState(false);
    
    auto scale = data->scale;
    this->mousePos = Vec2<float>(data->mousePos.x * scale, data->mousePos.y * scale);

    if(windows.empty()){
        int I = 0;
        for(auto c : getManager()->getCategories()){
            if(c->modules.empty())
                continue;
            auto stretchX = RenderUtils::getTextLen(c->name, 1);

            for(auto m : c->modules){
                auto currLen = RenderUtils::getTextLen(m->getName(), 1);
                if(currLen > stretchX)
                    stretchX = currLen;
            };

            auto window = new VWindow(c->name, Vec2<float>((I * 80 + stretchX) + 10, 10));
            
            for(auto m : c->modules){
                window->items.push_back(new VModuleButton(window, m));
            };

            windows.push_back(window);
            I++;
        };
    };

    for(auto window : windows){
        auto titlePos = window->titlePos;

        auto stretchX = RenderUtils::getTextLen(window->name, 1);
        auto titleBarY = window->titleBarStretchY;

        for(auto item : window->items){
            auto currLen = RenderUtils::getTextLen(item->text, 1);
            if(currLen > stretchX)
                stretchX = currLen;
        };

        stretchX += 4.f;

        window->titleRect = Vec4<float>(titlePos.x, titlePos.y, titlePos.x + stretchX, titlePos.y + titleBarY);
        window->bodyRect = Vec4<float>(window->titleRect.x, window->titleRect.y + titleBarY, window->titleRect.z, window->titleRect.w + (window->items.size() * 13));

        RenderUtils::fillRectangle(window->titleRect, window->titleBarColor);
        RenderUtils::fillRectangle(window->bodyRect, window->bgColor);

        RenderUtils::drawString(window->name, 1, Vec2<float>(window->titleRect.x + 2, window->titleRect.y + 2), window->titleColor);
        
        int I = 0;
        for(auto item : window->items){
            auto textPos = Vec2<float>(window->bodyRect.x + 2, window->bodyRect.y + (I * 13));
            item->elementRect = Vec4<float>(textPos.x - 1, textPos.y - 1, window->bodyRect.z - 1, textPos.y + 11);

            if(item->type == VItemType::ModuleButton){
                auto button = (VModuleButton*)(item);
                if(button->module != nullptr && button->module->getState())
                    RenderUtils::drawRectangle(item->elementRect, window->textColor, 1);
            };
            
            RenderUtils::drawString(item->text, 1, textPos, window->textColor);
            
            I++;
        };

        RenderUtils::flushText();
    };
};

void ClickGui::onKey(uint64_t key, bool isDown, bool* cancel){
    //
};

void chatMsg(std::string msg){
    auto inst = Minecraft::getClientInstance();

    if(inst == nullptr)
        return;
    
    auto player = inst->getPlayer();

    if(player == nullptr)
        return;
    
    player->displayClientMessage(&msg);
};

void ClickGui::onMouse(char action, bool isDown, Vec2<float> mousePos, bool* cancel){
    if(action == 2)
        return;
    
    if(isDown){
        for(auto I = windows.size(); I > 0; I--){
            if(draggingWindow != nullptr)
                break;
            
            auto window = windows.at(I - 1);
            
            if(window->titleRect.intersects(this->mousePos)){
                chatMsg("Dragging!");
                draggingWindow = window;
                dragStart = mousePos;
                break;
            };
        };
    }
    else {
        //
    };
};

void ClickGui::onMouseMove(char action, bool isDown, Vec2<float> mousePos, bool* cancel){
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