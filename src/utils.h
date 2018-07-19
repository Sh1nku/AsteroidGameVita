#pragma once
#include "headers.h"

#define PI 3.141592


extern GLuint loadTexture(const char* name);

static int radToDeg(float rad) {
	int deg = rad*(180/PI);
}
