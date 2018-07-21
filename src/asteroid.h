#pragma once
#include "headers.h"
#include "gameobject.h"
#include "vectormath.h"

class Asteroid : public GameObject {
public:
  Asteroid(const char *name, int xSize, int ySize, b2PolyDef *polyDef);
  Asteroid(const Asteroid &obj, Vector2f pos = Vector2f(), Vector2f direction = Vector2f(), float rotation = 0, float speed = 0);
  ~Asteroid();
  void render();
  TYPE getType();
	void hit();

  bool destroy = false;
  b2BodyDef bodyDef;
  b2Body *body;
private:
  void registerBody();

  GLuint textureID;
  int spriteWidth;
  int spriteHeight;
  int scale;
};
