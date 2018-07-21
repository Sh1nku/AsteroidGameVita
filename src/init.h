#pragma once
#include "headers.h"
#include "utils.h"

#define SCREEN_WIDTH 960
#define SCREEN_HEIGHT 544
const float RATIO = (float)SCREEN_WIDTH / SCREEN_HEIGHT;

extern void init();
extern void startDraw();
extern void endDraw();
extern void exit();

static void initGL() {
	glEnable (GL_BLEND);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER,0);
	glEnable (GL_CULL_FACE);
	glCullFace (GL_BACK);
	glFrontFace (GL_CCW);

	glClearColor(0.1f, 0, 0, 1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, RATIO, 7, 10);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
