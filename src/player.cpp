#include "player.h"
#include "utils.h"
#include "headers.h"
#include "globals.h"
#include "controller.h"

Player::Player() {

	scale = spriteWidth / UNIT_SIZE;
	b2BodyDef bodyDef;
	bodyDef.position.Set(0.0f, 0.0f);
	bodyDef.preventRotation = true;
	b2PolyDef polygonDef;
	polygonDef.vertexCount = 5;
	polygonDef.vertices[0].Set(-0.40625 * scale, -0.375 * scale);
	polygonDef.vertices[1].Set(0.40625 * scale,  -0.375 * scale);
	polygonDef.vertices[2].Set(0.40625 * scale, -0.1875 * scale);
	polygonDef.vertices[3].Set(0 * scale, 0.375 * scale);
	polygonDef.vertices[4].Set(-0.40625 * scale, -0.1875 * scale);
	polygonDef.density = 1.0f;
	bodyDef.AddShape(&polygonDef);
	body = Globals::world->CreateBody(&bodyDef);

	for(int i = 0; i < ANIMATIONS; i++) {
		for(int j = 0; j < FRAMES; j++) {
			texCoords[i][j] = b2Vec2(spriteWidth*j, (spriteHeight*i));
		}
	}
	textureID = Globals::getTexture("textures/ship.png");

	controller = new Controller();
}

Player::~Player() {
	delete controller;
}

void Player::render() {
	int x = texCoords[currentAnimation][currentFrame].x;
	int y = texCoords[currentAnimation][currentFrame].y;
	glBindTexture(GL_TEXTURE_2D, textureID);
	glPushMatrix();
	glTranslatef(body->GetOriginPosition().x,body->GetOriginPosition().y,-8);
	glRotatef((float) radToDeg(body->GetRotation()), 0, 0, 1);
	glBegin(GL_QUADS);
	glTexCoord2f((float)x / textureWidth, ((float)y + spriteHeight) / textureHeight);
	glVertex3f(-0.5f * scale, -0.5f * scale, 0);
	glTexCoord2f(((float)x + spriteWidth) / textureWidth,((float)y + spriteHeight) / textureHeight);
	glVertex3f(0.5f * scale, -0.5f * scale, 0);
	glTexCoord2f(((float)x + spriteWidth) / textureWidth, (float)y / textureHeight);
	glVertex3f(0.5f * scale, 0.5f * scale, 0);
	glTexCoord2f((float)x / textureWidth, (float)y / textureHeight);
	glVertex3f(-0.5f * scale, 0.5f * scale, 0);
	glEnd();
	glPopMatrix();
}

void Player::update() {
	updateAnimation();
	controller->update();
	updateControls();
}

void Player::updateControls() {
	body->SetLinearVelocity(b2Vec2(controller->leftAxisX*3, -controller->leftAxisY*3));
	if(controller->leftAxisX > 0) {
		setAnimation(ANIMATION::RIGHT);
	}
	else if(controller->leftAxisX < 0) {
		setAnimation(ANIMATION::LEFT);
	}
	else {
		setAnimation(ANIMATION::IDLE);
	}
}

void Player::updateAnimation() {
	if(currentFrame == FRAMES-1) {
		currentFrame = 0;
	}
	else {
		currentFrame++;
	}
}

void Player::setAnimation(ANIMATION anim) {
	if(anim == currentAnimation) {

	}
	else {
		currentAnimation = anim;
		currentFrame = 0;
	}
}
