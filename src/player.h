#pragma once
#include "headers.h"
#include "gameobject.h"
#include "vectormath.h"

#define PLAYER_SPEED 3
#define PLAYER_SPEED_MODIFIER 1.7
#define TIME_BETWEEEN_SHOTS 0.3

const static Vector2f BULLET_POS(0.35, -0.2);

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
	void update(float dt);
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
	float lastShot = TIME_BETWEEEN_SHOTS;
	b2Body *body;
	b2BodyDef bodyDef;
	b2PolyDef polygonDef;
	Controller *controller;

};
