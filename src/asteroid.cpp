#include "asteroid.h"
#include "headers.h"
#include "globals.h"
#include "utils.h"
#include "gameobject.h"

Asteroid::Asteroid(const char *name, int xSize, int ySize) {
  spriteWidth = xSize;
  spriteHeight = ySize;
  scale = spriteWidth / UNIT_SIZE;
  bodyDef.position.Set(0, 0);
  bodyDef.userData = NULL;
  textureID = Globals::getTexture(name);
}

Asteroid::Asteroid(const Asteroid &obj, Vector2f pos, Vector2f direction, std::vector<float> polyCoords, float scale2, float rotation, float speed) {
  spriteWidth = obj.spriteWidth;
  spriteHeight = obj.spriteHeight;
  scale = obj.scale * scale2;
  bodyDef = obj.bodyDef;
  bodyDef.position.Set(pos.x, pos.y);
  bodyDef.userData = this;
  b2PolyDef polyDef;
  polyDef.categoryBits = FILTER_ASTEROID;
  polyDef.maskBits = FILTER_PLAYER | FILTER_BULLET;
  polyDef.density = 1.0f;
  polyDef.vertexCount = polyCoords.size() / 2;
  int j = 0;
  for(int i = 0; i < polyCoords.size(); i+=2) {
    polyDef.vertices[j].Set(polyCoords.at(i) * scale, polyCoords.at(i+1) * scale);
    j++;
  }
  bodyDef.AddShape(&polyDef);
  textureID = obj.textureID;
  body = Globals::world->CreateBody(&bodyDef);
  body->SetLinearVelocity(b2Vec2(direction.x * speed, direction.y * speed));
  body->SetAngularVelocity(rotation);
}

Asteroid::~Asteroid() {}

void Asteroid::render() {
	glBindTexture(GL_TEXTURE_2D, textureID);
	glPushMatrix();
	glTranslatef(body->GetOriginPosition().x,body->GetOriginPosition().y,-8.1);
	glRotatef((float) radToDeg(body->GetRotation()), 0, 0, 1);
	glBegin(GL_QUADS);
  glTexCoord2f(0, 1);
	glVertex3f(-0.5f * scale, -0.5f * scale, 0);
  glTexCoord2f(1, 1);
	glVertex3f(0.5f * scale, -0.5f * scale, 0);
  glTexCoord2f(1, 0);
	glVertex3f(0.5f * scale, 0.5f * scale, 0);
  glTexCoord2f(0, 0);
	glVertex3f(-0.5f * scale, 0.5f * scale, 0);
	glEnd();
	glPopMatrix();
}

void Asteroid::hit() {
  destroy = true;
}

TYPE Asteroid::getType() {
	return TYPE::ASTEROID;
}
