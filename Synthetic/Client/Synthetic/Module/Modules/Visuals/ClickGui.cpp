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

    Color titleColor = Color(255, 255, 255);
    Color textColor = Color(255, 255, 255);
    Color bgColor = Color(32, 32, 32);
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
        if(windowRect.z > 0 || windowRect.w > 0)
            return;
        
        windowRect.w = (windowRect.y + 10.f) + (windowItems.size() * 13) + 2.f;
        
        auto currLen = RenderUtils::getTextLen(name, 1) + 2;

        for(auto item : windowItems){
            auto len = RenderUtils::getTextLen(item->getText(), 1) + 2;

            if(len > currLen)
                currLen = len;
        };

        windowRect.z = windowRect.x + currLen;
    };

    auto getTextColor() -> Color {
        return this->textColor;
    };

    auto setTextColor(Color color) -> void {
        this->textColor = color;
    };

    auto getTitleColor() -> Color {
        return this->titleColor;
    };

    auto setTitleColor(Color color) -> void {
        this->titleColor = color;
    };

    auto getBgColor() -> Color {
        return this->bgColor;
    };

    auto setBgColor(Color color) -> void {
        this->bgColor = color;
    };

    auto addWindowItem(VWindowItem* item) -> void {
        this->windowItems.push_back(item);
    };

    auto getItems() -> std::vector<VWindowItem*> {
        return this->windowItems;
    };

    auto moveWindow(Vec2<float> position){
        this->windowRect.x = position.x;
        this->windowRect.y = position.y;
        this->windowRect.z = 0;
        this->windowRect.w = 0;
    };
};

std::vector<VWindow*> windows = std::vector<VWindow*>();

VWindow* draggingWindow = nullptr;

void ClickGui::onRenderCtx(MinecraftUIRenderContext* ctx){
    if(windows.empty()){
        int I = 0;
        for(auto c : this->getManager()->getCategories()){
            if(c->modules.empty())
                continue;
            
            auto windowRect = Vec4<float>((I * 60) + 20, 10, 0, 0);
            auto window = new VWindow(c->name, windowRect);

            window->setTitleColor(Color(65, 214, 217));

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

        RenderUtils::fillRectangle(windowRect, window->getBgColor());
        
        RenderUtils::fillRectangle(Vec4<float>(windowRect.x + 1, windowRect.y, windowRect.z - 1, windowRect.y + 10), Color(18, 18, 18));
        RenderUtils::drawString(window->getName(), 1, Vec2<float>(windowRect.x + 2, windowRect.y), window->getTitleColor());

        int I = 0;

        for(auto item : window->getItems()){
            RenderUtils::drawString(item->getText(), 1, Vec2<float>(windowRect.x + 2, windowRect.y + (I * 13) + 13.f), window->getTextColor());
            I++;
        };
    };
};

void ClickGui::onKey(uint64_t key, bool isDown, bool* cancel){
    if(key == VK_ESCAPE || key == 0x45)
        return this->setState(false);
    
    *cancel = true;
};

void inGameMsg(std::string msg){
    auto instance = Minecraft::getClientInstance();
    if(instance == nullptr)
        return;
    
    auto player = instance->getPlayer();
    if(player == nullptr)
        return;
    
    player->displayClientMessage(&msg);
}

void ClickGui::onMouse(char action, bool isDown, Vec2<short> pos, bool* cancel){
    if(action == 2)
        return;
    
    auto instance = Minecraft::getClientInstance();
    
    if(instance == nullptr)
        return;
    
    auto data = instance->getGuiData();
    
    if(data == nullptr)
        return;
    
    auto scale = data->scale;
    Vec2 scaledMouse = Vec2<float>(data->mousePos.x * scale, data->mousePos.y * scale);

    if(isDown && draggingWindow == nullptr){
        for(size_t I = windows.size(); I > 0; I--){
            if(draggingWindow != nullptr)
                break;
            
            auto window = windows.at(I - 1);
            auto windowRect = window->getWindowRect();
            
            auto titleRect = windowRect;
            titleRect.w = windowRect.y + 10.f;

            if(titleRect.intersects(scaledMouse)){
                draggingWindow = window;
                dragStart = scaledMouse;
            };
        };
    }
    else {
        if(draggingWindow != nullptr)
            draggingWindow = nullptr;
    };
};

void ClickGui::onMouseMove(char action, bool isDown, Vec2<short> pos, bool* cancel){
    if(action == 2)
        return;
    
    auto instance = Minecraft::getClientInstance();
    
    if(instance == nullptr)
        return;
    
    auto data = instance->getGuiData();
    
    if(data == nullptr)
        return;
    
    auto scale = data->scale;
    Vec2 scaledMouse = Vec2<float>(data->mousePos.x * scale, data->mousePos.y * scale);

    if(draggingWindow != nullptr){
        Vec2<float> diff = Vec2<float>(scaledMouse.x - dragStart.x, scaledMouse.y - dragStart.y);
        auto windowRect = draggingWindow->getWindowRect();
        draggingWindow->moveWindow(Vec2<float>(windowRect.x + diff.x, windowRect.y + diff.y));
        dragStart = scaledMouse;
    };
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