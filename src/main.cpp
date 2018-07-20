#include "init.h"
#include "player.h"
#include "headers.h"
#include "globals.h"
#include "time.h"

int main(int argc, char* args[]) {
	Globals::init();
	init();
	initGL();
	Player player;
	Time timer;

	while(!Globals::quit) {
		timer.update();
		startDraw();
		glLoadIdentity();
		player.render();
		endDraw();
		player.update();
		Globals::world->Step(timer.getDeltaTime(), 10);
	}
	exit();
}
