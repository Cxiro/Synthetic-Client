#include "ModuleList.h"

#include "../../../Manager/Manager.h"
#include "../../../Category/Category.h"

class TComp {
public:
    Module* module;
    float xOff;
    float len;

    TComp(Module* mod, float xOff, float len){
        this->module = mod;
        this->xOff = xOff;
        this->len = len;
    };
};

struct compare {
    inline bool operator()(const std::string& first,
            const std::string& second) const
    {
        return first.size() < second.size();
    }
};

auto comps = std::vector<TComp*>();

void ModuleList::onRenderCtx(MinecraftUIRenderContext* ctx){
    auto manager = this->getManager();

    if(manager == nullptr)
        return;
    
    auto categories = manager->getCategories();
    auto instance = ctx->instance;

    if(categories.empty() || instance == nullptr)
        return;
    
    auto data = instance->getGuiData();

    if(data == nullptr)
        return;
    
    auto res = data->scaledRes;
    
    if(!init && comps.empty()){
        auto stringsVec = std::vector<std::string>();

        for(auto c : categories){
            for(auto m : c->modules){
                stringsVec.push_back(m->getName());
            };
        };

        compare c;

        std::sort(stringsVec.begin(), stringsVec.end(), c);

        for(auto s : stringsVec){
            for(auto c : categories){
                for(auto m : c->modules){
                    if(strcmp(m->getName().c_str(), s.c_str()) == 0){
                        comps.push_back(new TComp(m, res.x, RenderUtils::getTextLen(m->getName(), 1) + 2.f));
                    };
                };
            };
        };

        init = true;
    };

    updateAlpha();

    if(alpha <= 0.f)
        return;

    float modifier = 0.5f;
    int I = 0;

    for(auto c : comps){
        auto mod = c->module;

        if(mod->getState()){
            if(c->xOff > (res.x - (c->len + 2.f)))
                c->xOff -= modifier;
        }
        else {
            if(c->xOff < res.x)
                c->xOff += modifier;
        };

        if(c->xOff < (res.x - (c->len + 2.f)) || c->xOff > res.x){
            if(mod->getState())
                c->xOff = (res.x - (c->len + 2.f));
            else
                c->xOff = res.x;
        };

        if(c->xOff < res.x){
            auto textPos = Vec2<float>(c->xOff, (I * 13) + 5);
            RenderUtils::fillRectangle(Vec4<float>(textPos.x - 2.f, textPos.y - 2.f, res.x - 1, (I * 13) + 16.f), Color(36, 36, 36, alpha));
            RenderUtils::drawRectangle(Vec4<float>(textPos.x - 2.f, textPos.y - 2.f, res.x - 1, (I * 13) + 16.f), Color(65, 214, 217, alpha), 1);
            RenderUtils::drawString(mod->getName(), 1, textPos, Color(65, 214, 217, alpha));
            I++;
        };
    };
};

void ModuleList::updateAlpha(){
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