#pragma once
#include "headers.h"
#include "gameobject.h"

const int FRAMES = 4;
const int ANIMATIONS = 3;

enum ANIMATION {
	IDLE, LEFT, RIGHT
};

class Controller;

class Player : public GameObject{
public:

	Player();
	~Player();
	void render();
	void update();
	void setAnimation(ANIMATION anim);
	TYPE getType();
	void hit();

	b2Vec2 texCoords[ANIMATIONS][FRAMES];
	GLuint textureID;
	int currentFrame = 0;
	int currentAnimation = ANIMATION::IDLE;
private:
	void updateAnimation();
	void updateControls();

	int spriteWidth = 32;
	int spriteHeight = 32;
	float scale;
	int textureWidth = 128;
	int textureHeight = 96;
	b2Body *body;
	b2BodyDef bodyDef;
	b2PolyDef polygonDef;
	Controller *controller;

};
