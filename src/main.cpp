#include "init.h"
#include "player.h"
#include "headers.h"
#include "globals.h"

int main(int argc, char* args[]) {
	Globals::init();
	init();
	initGL();
	Player player;

	while(true) {
		startDraw();
		glLoadIdentity();
		player.render();
		endDraw();
		player.updateAnimation();
	}
	exit();
}
