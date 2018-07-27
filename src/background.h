#pragma once
#include "headers.h"

#define BACKGROUND_SCROLL_SPEED 0.2
#define BACKGROUND_SCROLL_SIZE 6

static GLuint backgroundID;

extern void initBackground();

extern void renderBackground(float dt);