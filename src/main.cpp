#include "init.h"
#include "player.h"
#include "headers.h"
#include "globals.h"

int main(int argc, char* args[]) {
	Globals::init();
	init();
	initGL();
	Player player;

	while(!Globals::quit) {
		startDraw();
		glLoadIdentity();
		player.render();
		endDraw();
		player.update();
		Globals::world->Step(0.016, 10);
	}
	exit();
}
