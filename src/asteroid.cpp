#include "asteroid.h"
#include "headers.h"
#include "globals.h"
#include "utils.h"
#include "gameobject.h"

Asteroid::Asteroid(const char *name, int xSize, int ySize, b2PolyDef *polyDef) {
  spriteWidth = xSize;
  spriteHeight = ySize;
  scale = spriteWidth / UNIT_SIZE;
  bodyDef.position.Set(0, 0);
  polyDef->categoryBits = 0x0004;
  polyDef->maskBits = 0x0002;
  bodyDef.AddShape(polyDef);
  bodyDef.userData = NULL;
  textureID = Globals::getTexture(name);
}

Asteroid::Asteroid(const Asteroid &obj, float x, float y, float rotation) {
  spriteWidth = obj.spriteWidth;
  spriteHeight = obj.spriteHeight;
  scale = obj.scale;
  bodyDef = obj.bodyDef;
  bodyDef.position.Set(x, y);
  bodyDef.userData = this;
  textureID = obj.textureID;
  body = Globals::world->CreateBody(&bodyDef);
  body->SetAngularVelocity(0.5);
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
