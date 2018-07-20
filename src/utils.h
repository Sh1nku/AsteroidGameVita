#pragma once
#include "headers.h"

#define PI 3.141592


extern GLuint loadTexture(const char* name);

static int radToDeg(float rad) {
	int deg = rad*(180/PI);
}

static void gluPerspective(float fov, float aspectRatio, float zNear, float zFar) {
	float yMax, xMax;
	yMax = zNear * tanf(fov * PI / 360.0);
	xMax = yMax * aspectRatio;
	glFrustum(-xMax, xMax, -yMax, yMax, zNear, zFar);
}
