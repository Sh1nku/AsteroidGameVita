#pragma once
#include "headers.h"

const int FRAMES = 4;
const int ANIMATIONS = 3;

enum ANIMATION {
	IDLE, LEFT, RIGHT
};

class Player {
	public:

	Player();
	~Player();
	void render();
	void updateAnimation();
	void setAnimation(ANIMATION anim);

	b2Vec2 texCoords[ANIMATIONS][FRAMES];
	GLuint textureID;
	int currentFrame = 0;
	int currentAnimation = ANIMATION::IDLE;
	private:
	int spriteWidth = 32;
	int spriteHeight = 32;
	int textureWidth = 128;
	int textureHeight = 96;
	b2Body *body;
	
};
