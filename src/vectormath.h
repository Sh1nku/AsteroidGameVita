#pragma once
#include "headers.h"

struct Vector2f {
    float x, y;
    Vector2f() : x(0), y(0) {}
    Vector2f(float x, float y) : x(x), y(y) {}

    void normalize();
    float getLength();

    static Vector2f getVector(Vector2f &v1, Vector2f &v2);
};

static float randomFloatBetween(float a, float b) {
    return ((b - a) * ((float)rand() / RAND_MAX)) + a;
}