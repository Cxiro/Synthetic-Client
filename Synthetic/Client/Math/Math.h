#ifndef CLIENT_MATH_MATH
#define CLIENT_MATH_MATH

#include <vector>
#include <string>

#define PI 3.14159

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

    bool operator == (const Vec2 v){
        return this->x == v.x && this->y == v.y;
    };

    bool operator != (const Vec2 v){
        return this->x != v.x || this->y != v.y;
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

    bool operator == (const Vec3<T> v){
        return this->x == v.x && this->y == v.y && this->z == v.z;
    };

    bool operator != (const Vec3<T> v){
        return this->x != v.x || this->y != v.y || this->z != v.z;
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

    Vec4(Vec2<T> vecA, Vec2<T> vecB){
        this->x = vecA.x;
        this->y = vecA.y;
        this->z = vecB.x;
        this->y = vecB.y;
    };
    
    bool operator == (const Vec4<T> v){
        return this->x == v.x && this->y == v.y && this->z == v.z && this->w == v.w;
    };

    bool operator != (const Vec4<T> v){
        return this->x != v.x || this->y != v.y || this->z != v.z || this->w != v.w;
    };
};

class AABB {
public:
    Vec3<float> pointA;
    Vec3<float> pointB;
};

#endif /* CLIENT_MATH_MATH */
