#ifndef CLIENT_UTILS_RENDERUTILS
#define CLIENT_UTILS_RENDERUTILS

#include "../Math/Math.h"

class MinecraftUIRenderContext;
class Font;
class Color;

class RenderUtils {
private:
    static MinecraftUIRenderContext* _ctx;
    static Font* _font;
public:
    static auto setData(MinecraftUIRenderContext*, Font*) -> void;
    static auto drawString(std::string, float, Vec2<float>, Color) -> void;
    static auto drawRectangle(Vec4<float>, Color, int) -> void;
    static auto fillRectangle(Vec4<float>, Color) -> void;

    static auto getTextLen(std::string, float) -> float;

    static auto getCtx() -> MinecraftUIRenderContext*;
    static auto getFont() -> Font*;
    static auto getScale() -> float;
    static auto flushText() -> void;
};

#endif /* CLIENT_UTILS_RENDERUTILS */