#pragma once
#include "headers.h"
#include "gameobject.h"
#include "vectormath.h"
#include "globals.h"

#define BULLET_SPEED 20
#define BULLET_RADIUS 0.07

extern GLuint bulletTexture;
const int FRAMES = 4;

class Bullet : public GameObject {
public:
    Bullet(Vector2f &pos);
    virtual ~Bullet();
    void hit();
    void render();
    TYPE getType();
    b2Body *body;
    bool destroy = false;
    static GLuint bulletTexture;
private:
    int textureWidth = 64;
    int textureHeight = 16;
    int frame = 0;
    float scale = ((float)textureHeight) / UNIT_SIZE;
};