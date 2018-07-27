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
    glBindTexture(GL_TEXTURE_2D, bulletTexture);
    glPushMatrix();
	glTranslatef(body->GetOriginPosition().x,body->GetOriginPosition().y,-8.15);
	glRotatef((float) radToDeg(body->GetRotation()), 0, 0, 1);
    glBegin(GL_QUADS);
    glTexCoord2f(((float)frame) / FRAMES, 1);

	glVertex3f(-0.5f * scale, -0.5f * scale, 0);
	glTexCoord2f(((float)frame + 1) / FRAMES ,1);

	glVertex3f(0.5f * scale, -0.5f * scale, 0);
	glTexCoord2f(((float)frame + 1) / FRAMES, 0);

	glVertex3f(0.5f * scale, 0.5f * scale, 0);
	glTexCoord2f(((float)frame) / FRAMES, 0);

	glVertex3f(-0.5f * scale, 0.5f * scale, 0);
    glEnd();

	glPopMatrix();
    frame++;
    if(frame >= FRAMES) {
        frame = 0;
    }
}

TYPE Bullet::getType() {
	return TYPE::BULLET;
}