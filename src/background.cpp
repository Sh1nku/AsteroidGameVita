#include "background.h"
#include "globals.h"

const float scale = 12;
float yVel = 0;

void initBackground() {
    backgroundID = Globals::getTexture("textures/bg.png");
}

void renderBackground(float dt) {

    glBindTexture(GL_TEXTURE_2D, backgroundID);
    glPushMatrix();

    glTranslatef(0, 0, -8.2f);
	glBegin(GL_QUADS);
	glTexCoord2f(0, BACKGROUND_SCROLL_SIZE - yVel);
	glVertex3f(-0.5f * scale, -0.5f * scale, 0);
	glTexCoord2f(BACKGROUND_SCROLL_SIZE, BACKGROUND_SCROLL_SIZE - yVel);
	glVertex3f(0.5f * scale, -0.5f * scale, 0);
	glTexCoord2f(BACKGROUND_SCROLL_SIZE, 0 - yVel);
	glVertex3f(0.5f * scale, 0.5f * scale, 0);
	glTexCoord2f(0, 0 - yVel);
	glVertex3f(-0.5f * scale, 0.5f * scale, 0);
    glEnd();

    glPopMatrix();

    yVel += BACKGROUND_SCROLL_SPEED * dt;
    if(yVel > BACKGROUND_SCROLL_SIZE) {
        yVel -= BACKGROUND_SCROLL_SIZE;
    }
    
}