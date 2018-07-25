#include "player.h"
#include "utils.h"
#include "headers.h"
#include "globals.h"
#include "controller.h"
#include "gameobject.h"
#include "vectormath.h"

Player::Player() {

	scale = spriteWidth / UNIT_SIZE;
	bodyDef.position.Set(0.0f, 0.0f);
	bodyDef.preventRotation = true;
	bodyDef.userData = this;
	polygonDef.vertexCount = 5;
	polygonDef.vertices[0].Set(-0.40625 * scale, -0.375 * scale);
	polygonDef.vertices[1].Set(0.40625 * scale,  -0.375 * scale);
	polygonDef.vertices[2].Set(0.40625 * scale, -0.1875 * scale);
	polygonDef.vertices[3].Set(0 * scale, 0.375 * scale);
	polygonDef.vertices[4].Set(-0.40625 * scale, -0.1875 * scale);
	polygonDef.density = 1.0f;
	polygonDef.categoryBits = FILTER_PLAYER;
	polygonDef.maskBits = FILTER_ASTEROID;
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

void Player::update(float dt) {
	lastShot += dt;
	updateAnimation();
	controller->update();
	updateControls();
}

void Player::updateControls() {
	if(controller->leftAxisX > 0) {
		setAnimation(ANIMATION::RIGHT);
	}
	else if(controller->leftAxisX < 0) {
		setAnimation(ANIMATION::LEFT);
	}
	else {
		setAnimation(ANIMATION::IDLE);
	}
	if(controller->r1) {
		body->SetLinearVelocity(b2Vec2(controller->leftAxisX*PLAYER_SPEED*PLAYER_SPEED_MODIFIER, -controller->leftAxisY*PLAYER_SPEED*PLAYER_SPEED_MODIFIER));
	}
	else {
		body->SetLinearVelocity(b2Vec2(controller->leftAxisX*PLAYER_SPEED, -controller->leftAxisY*PLAYER_SPEED));
	}
	if(lastShot > TIME_BETWEEEN_SHOTS && controller->square) {
		lastShot = 0;
		Vector2f bullet1(-BULLET_POS.x + this->body->GetOriginPosition().x, BULLET_POS.y + this->body->GetOriginPosition().y);
		Vector2f bullet2(BULLET_POS.x + this->body->GetOriginPosition().x, BULLET_POS.y + this->body->GetOriginPosition().y);
		Globals::createBullet(bullet1);
		Globals::createBullet(bullet2);
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

void Player::hit() {

}

TYPE Player::getType() {
	return TYPE::PLAYER;
}
