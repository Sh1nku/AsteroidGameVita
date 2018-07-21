#pragma once
#include "headers.h"



class Asteroid {
public:
  Asteroid(const char *name, int xSize, int ySize, b2PolyDef *polyDef);
  Asteroid(const Asteroid &obj, float x, float y, float rotation);
  void render();

private:
  void registerBody();

  GLuint textureID;
  b2BodyDef bodyDef;
  b2Body *body;
  int spriteWidth;
  int spriteHeight;
  int scale;
};
