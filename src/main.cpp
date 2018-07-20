#include "init.h"
#include "player.h"
#include "headers.h"
#include "globals.h"
#include "time.h"

int main(int argc, char* args[]) {
	init();
	initGL();
	Globals::init();
	Player player;
	Time timer;

	while(!Globals::quit) {
		timer.update();
		player.update();
		Globals::world->Step(timer.getDeltaTime(), 10);
		startDraw();
		player.render();
		endDraw();
	}
	exit();
}
