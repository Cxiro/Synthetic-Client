#ifndef CLIENT_SYNTHETIC_SDK_CLASSES_MINECRAFTUIRENDERCONTEXT
#define CLIENT_SYNTHETIC_SDK_CLASSES_MINECRAFTUIRENDERCONTEXT

class Rect : public Vec4<float> {
public:
    Rect(float top = 0.f, float left = 0.f, float right = 0.f, float bottom = 0.f){
        this->x = top;
        this->y = left;
        this->z = right;
        this->w = bottom;
    };
};

class Color : public Vec4<float> {
public:
    Color(float r = 0.f, float g = 0.f, float b = 0.f, float a = 1.f){
        this->x = r / 255.f;
        this->y = g / 255.f;
        this->z = b / 255.f;
        this->w = a / 255.f;
    };

    Color(){
        this->x = 0.f;
        this->y = 0.f;
        this->z = 0.f;
        this->w = 1.f;
    };
};

class TextAlignment {
public:
    //
};

struct TextMeasureData {
    float scale;

    TextMeasureData(){
        this->scale = 1.0f;
    };

    TextMeasureData(float scale){
        this->scale = scale;
    };
};

struct CaretMeasureData {
    int a;
    int b;

    CaretMeasureData(){
        CaretMeasureData(0xFFFFFFFF, false);
    };

    CaretMeasureData(int paramA, bool paramB){
        this->a = paramA;
        this->b = paramB;
    };
};

class ClientInstance;

class MinecraftUIRenderContext {
public:
    ClientInstance* instance;
private:
    virtual ~MinecraftUIRenderContext();
public:
    virtual auto getLineLength(Font*, std::string*, float, bool) -> float;
    virtual auto getTextAlpha(void) -> float;
    virtual auto setTextAlpa(float) -> void;
    virtual auto drawDebugText(Rect*, std::string*, Color*, float, unsigned int, float*, void*) -> __int64;
    virtual auto drawText(Font*, Rect*, std::string*, Color*, float, TextAlignment*, TextMeasureData*, CaretMeasureData*) -> __int64;
    virtual auto flushText(float) -> void;
private:
    virtual auto Function7() -> void;
    virtual auto Function8() -> void;
    virtual auto Function9() -> void;
    virtual auto Function10() -> void;
    virtual auto Function11() -> void;
public:
    virtual void drawRectangle(Vec4<float>, Color, float, int);
    virtual void fillRectangle(Vec4<float>, Color, float);
};

#endif /* CLIENT_SYNTHETIC_SDK_CLASSES_MINECRAFTUIRENDERCONTEXT */