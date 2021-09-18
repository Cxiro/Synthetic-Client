#include "TabGui.h"

#include "../../../Manager/Manager.h"
#include "../../../Synthetic.h"
#include "../../../Category/Category.h"

void TabGui::onRenderCtx(MinecraftUIRenderContext* ctx){
    auto instance = ctx->instance;

    if(instance == nullptr)
        return;
    
    auto mcGame = instance->getMinecraftGame();
    auto data = instance->getGuiData();
    
    if(mcGame == nullptr || data == nullptr)
        return;

    this->updateAlpha();

    if(alpha <= 0.f)
        return;
    
    auto manager = getManager();
    auto client = manager->getInstance();
    auto categories = manager->getCategories();

    auto res = data->scaledRes;
    auto tSize = 1.0f;
    
    Color enabledColor = Color(50, 168, 82, alpha);
    Color textColor = Color(65, 214, 217, alpha);
    Color bgColor = Color(36, 36, 36, alpha);

    std::string clientName = std::string(client->getName() + ", " + client->getVer());
    float nameLen = RenderUtils::getTextLen(clientName, tSize);
    auto textPos = Vec2<float>((res.x / 2) - (nameLen / 2), 0);

    RenderUtils::fillRectangle(Vec4<float>(textPos.x - 2.f, textPos.y, textPos.x + nameLen, 12.f), bgColor);
    RenderUtils::drawString(clientName, tSize, textPos, textColor);

    /* Categories */

    float catLen = 0.f;
    
    for(auto c : categories){
        auto currLen = RenderUtils::getTextLen(c->name, tSize);
        if(currLen > catLen)
            catLen = currLen;
    };

    int I = 0;

    auto startCatRect = Vec2<float>(10.f, 10.f);
    auto endCatRect = Vec2<float>(startCatRect.x + catLen, startCatRect.y + (categories.size() * 13 + 1.f));
    auto rect = Vec4<float>(startCatRect.x - 1.f, startCatRect.y - 2.f, endCatRect.x + 6.f, endCatRect.y);

    RenderUtils::fillRectangle(rect, bgColor);
    RenderUtils::drawRectangle(rect, textColor, 1);

    if(selectedCat){
        if(selectedCatOff <= 0.f)
            selectedCatOff = startCatRect.x + 2.f;
        
        float yOff = (startCatRect.y + (currCat * 13));
        RenderUtils::fillRectangle(Vec4<float>(startCatRect.x + 2.f, yOff + 11, selectedCatOff, yOff + 12), textColor);

        {
            float target = endCatRect.x + 2.f;
            float modifier = 0.5f;

            if(selectedCatOff < target)
                selectedCatOff += modifier;
            else
                if(selectedCatOff > target)
                    selectedCatOff = target;
        };
    };

    for(auto c : categories){
        RenderUtils::drawString(c->name, tSize, Vec2<float>(startCatRect.x + 3.f, startCatRect.y + (I * 13) + 1.f), selectedCat && currCat == I ? Color(65, 217, 126, alpha) : textColor);
        I++;
    };

    if(selectedCat){
        float modRectLen = 0.f;
        auto category = manager->getCategories().at(currCat);

        for(auto m : category->modules){
            auto currLen = RenderUtils::getTextLen(m->getName(), tSize);
            if(currLen > modRectLen)
                modRectLen = currLen;
        };

        I = 0;

        auto startModRect = Vec2<float>(endCatRect.x + 6.f, startCatRect.y);
        auto endModRect = Vec2<float>(startModRect.x + modRectLen, startModRect.y + (category->modules.size() * 13) + 1.f);
        auto modRect = Vec4<float>(startModRect.x - 1.f, startModRect.y - 2.f, endModRect.x + 6.f, endModRect.y);
        
        RenderUtils::fillRectangle(modRect, bgColor);
        RenderUtils::drawRectangle(modRect, textColor, 1);

        if(selectedMod){
            if(selectedModOff <= 0.f)
                selectedModOff = startModRect.x + 2.f;
            
            float yOff = (startModRect.y + (currMod * 13));
            auto module = category->modules.at(currMod);

            RenderUtils::fillRectangle(Vec4<float>(startModRect.x + 2.f, yOff + 11, selectedModOff, yOff + 12), module != nullptr && module->getState() ? Color(65, 217, 126, alpha) : textColor);

            {
                float target = endModRect.x + 2.f;
                float modifier = 0.5f;

                if(selectedModOff < target)
                    selectedModOff += modifier;
                else
                    if(selectedModOff > target)
                        selectedModOff = target;
            };
        };

        for(auto m : category->modules){
            RenderUtils::drawString(m->getName(), tSize, Vec2<float>(startModRect.x + 3.f, startModRect.y + (I * 13) + 1.f), m->getState() ? Color(65, 217, 126, alpha) : textColor);
            I++;
        };
    };
};

void TabGui::onKey(uint64_t key, bool isDown, bool* cancel){
    if(!isDown)
        return;
    
    bool lArrow = (key == 0x25);
    bool rArrow = (key == 0x27);
    bool uArrow = (key == 0x26);
    bool dArrow = (key == 0x28);

    auto manager = this->getManager();
    auto category = manager->getCategories().at(currCat);
    auto module = category->modules.size() > 0 ? category->modules.at(currMod) : nullptr;

    if(!lArrow && !rArrow && !dArrow && !uArrow)
        return;
    
    if(rArrow){
        if(!selectedCat){
            selectedCat = true;
        }
        else {
            if(!selectedMod){
                selectedMod = true;
            }
            else {
                if(module != nullptr)
                    module->toggleState();
            };
        };
    };
    
    if(lArrow){
        if(selectedMod){
            selectedMod = false;
            selectedModOff = 0.f;
        }
        else if(selectedCat){
            selectedCat = false;
            selectedCatOff = 0.f;
        };
    };

    if(dArrow){
        if(selectedMod){
            currMod++;
            selectedModOff = 0.f;

            if(currMod >= category->modules.size())
                currMod = 0;
        }
        else if(selectedCat){
            currCat++;
            selectedCatOff = 0.f;

            if(currCat >= manager->getCategories().size())
                currCat = 0;
        };
    };

    if(uArrow){
        if(selectedMod){
            if(currMod <= 0)
                currMod = category->modules.size();
            
            currMod--;
            selectedModOff = 0.f;
        }
        else if(selectedCat){
            if(currCat <= 0)
                currCat = manager->getCategories().size();
            
            currCat--;
            selectedCatOff = 0.f;
        };
    };
};

void TabGui::onDisable(){
    alpha = 0.f;

    currCat = 0;
    currMod = 0;
    selectedCat = false;
    selectedMod = false;
};

void TabGui::updateAlpha(){
    auto instance = Minecraft::getClientInstance();

    if(instance == nullptr)
        return;
    
    auto mcGame = instance->getMinecraftGame();

    if(mcGame == nullptr)
        return;
    
    float modifier = 0.005f;

    if(mcGame->canUseKeys){
        if(alpha < .9f)
            alpha += modifier;
        else if(alpha >= 1.f)
            alpha = .9f;
    }
    else {
        if(alpha > 0.f)
            alpha -= modifier;
    };
};