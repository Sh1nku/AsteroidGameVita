#include "vectormath.h"
#include "headers.h"

Vector2f Vector2f::getVector(Vector2f &v1, Vector2f &v2) {
    Vector2f retVec;
    retVec.x = v2.x - v1.x;
    retVec.y = v2.y - v1.x;
    return retVec;
}

Vector2f Vector2f::operator+(const Vector2f& b) {
    Vector2f vec2;
    vec2.x = this->x + b.x;
    vec2.y = this->y + b.y;
    return vec2;
}

void Vector2f::normalize() {
    float length = getLength();
    x /= length; y /= length;
}

float Vector2f::getLength() {
    return (float) sqrt(pow(x, 2) + pow(y, 2));
}