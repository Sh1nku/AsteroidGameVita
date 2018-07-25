#pragma once
#include "headers.h"
#include "gameobject.h"
#include "vectormath.h"

#define BULLET_SPEED 20
#define BULLET_RADIUS 0.07

class Bullet : public GameObject {
public:
    Bullet(Vector2f &pos);
    virtual ~Bullet();
    void hit();
    void render();
    TYPE getType();
    b2Body *body;
    bool destroy = false;
private:
};