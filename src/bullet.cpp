#include "bullet.h"
#include "headers.h"
#include "globals.h"
#include "utils.h"

Bullet::Bullet(Vector2f &pos) {
    b2BodyDef bodyDef;
    bodyDef.isFast = true;
    bodyDef.position.Set(pos.x, pos.y);
    bodyDef.userData = this;

    b2CircleDef circleDef;
    circleDef.categoryBits = FILTER_BULLET;
    circleDef.maskBits = FILTER_ASTEROID;
    circleDef.radius = BULLET_RADIUS;
    circleDef.density = 1;

    bodyDef.AddShape(&circleDef);
    body = Globals::world->CreateBody(&bodyDef);
    body->SetLinearVelocity(b2Vec2(0, BULLET_SPEED));
}

Bullet::~Bullet() {

}

void Bullet::hit() {
    destroy = true;
}

void Bullet::render() {
    glPushMatrix();
	glTranslatef(body->GetOriginPosition().x,body->GetOriginPosition().y,-8.2);
	glRotatef((float) radToDeg(body->GetRotation()), 0, 0, 1);
    glDisable(GL_TEXTURE_2D);
    glColor3f(1,1,1);
    DrawCircle(9, BULLET_RADIUS);
    glEnable(GL_TEXTURE_2D);
	glPopMatrix();
}

TYPE Bullet::getType() {
	return TYPE::BULLET;
}