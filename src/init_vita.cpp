#ifndef DEBUG
#include "init.h"
#include "headers.h"

void init() {
	vglInit(0x800000);
}

void startDraw() {
	vglStartRendering();
	glClear(GL_COLOR_BUFFER_BIT);
	glClear(GL_DEPTH_BUFFER_BIT);
}

void endDraw() {
	vglStopRendering();
}

void exit() {
	
}

#endif
