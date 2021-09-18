#include "RenderUtils.h"
#include "../Synthetic/SDK/Minecraft.h"

MinecraftUIRenderContext* RenderUtils::_ctx = nullptr;
Font* RenderUtils::_font = nullptr;

void RenderUtils::setData(MinecraftUIRenderContext* ctx, Font* font){
    _ctx = ctx;
    _font = font;
};

void RenderUtils::drawString(std::string text, float size, Vec2<float> position, Color color){
    if(_ctx == nullptr || _font == nullptr)
        return;
    
    TextMeasureData textMeasureData = TextMeasureData(size);
    CaretMeasureData caretMeasureData = CaretMeasureData();

    Rect rect = Rect(position.x, position.x + (position.x * size), position.y, position.y + (position.y * size / 2));

    _ctx->drawText(_font, &rect, &text, &color, color.w * 255.f, nullptr, &textMeasureData, &caretMeasureData);
    _ctx->flushText(0);
};

void RenderUtils::drawRectangle(Vec4<float> position, Color color, int lineWidth){
    if(_ctx == nullptr)
        return;
    
    _ctx->drawRectangle(Vec4<float>(position.x, position.z, position.y, position.w), color, color.w * 255.f, lineWidth);
};

void RenderUtils::fillRectangle(Vec4<float> position, Color color){
    if(_ctx == nullptr)
        return;
    
    _ctx->fillRectangle(Vec4<float>(position.x, position.z, position.y, position.w), color, color.w * 255.f);
};

float RenderUtils::getTextLen(std::string text, float size){
    if(_ctx == nullptr || _font == nullptr)
        return 0.f;
    
    return _ctx->getLineLength(getFont(), &text, size, false);
};

MinecraftUIRenderContext* RenderUtils::getCtx(){
    return _ctx;
};

Font* RenderUtils::getFont(){
    return _font;
};

float RenderUtils::getScale(){
    if(_ctx == nullptr)
        return 0.f;
    
    auto instance = _ctx->instance;

    if(instance == nullptr)
        return 0.f;
    
    auto data = instance->getGuiData();

    if(data == nullptr)
        return 0.f;
    
    return data->scale;
};