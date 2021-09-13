#ifndef CLIENT_MATH_MATH
#define CLIENT_MATH_MATH

#include <vector>
#include <string>

class Math {
public:
    //
};

template<typename T>
class Vec2 {
public:
    T x;
    T y;

    Vec2(T x = 0, T y = 0){
        this->x = x;
        this->y = y;
    };
};

template<typename T>
class Vec3 : public Vec2<T> {
public:
    T z;

    Vec3(T x = 0, T y = 0, T z = 0){
        this->x = x;
        this->y = y;
        this->z = z;
    };
};

template<typename T>
class Vec4 : public Vec3<T> {
public:
    T w;

    Vec4(T x = 0, T y = 0, T z = 0, T w = 0){
        this->x = x;
        this->y = y;
        this->z = z;
        this->w = w;
    };
};

#endif /* CLIENT_MATH_MATH */