#include "init.h"
#include "player.h"
#include "headers.h"
#include "globals.h"
#include "time.h"
#include "gameobject.h"
#include "gui.h"
#include "background.h"

int main(int argc, char* args[]) {
	init();
	initGL();
	Globals::init();
	GUI gui;
	Player player;
	Time timer;
	float spawnAsteroidPer = 0.1;
	float timeTaken = 0;

	while(!Globals::quit) {
		timer.update();
		timeTaken += timer.getDeltaTime();
		startDraw();
		renderBackground(timer.getDeltaTime());
		player.render();
		if(timeTaken > spawnAsteroidPer) {
			Globals::createRandomAsteroid();
			timeTaken -= spawnAsteroidPer;
		}
		Globals::renderObjects();
		gui.drawMainMenu();
		endDraw();

		player.update(timer.getDeltaTime());
		Globals::world->Step(timer.getDeltaTime(), 10);
		for (b2Contact* c = Globals::world->GetContactList(); c; c = c->GetNext()) {
		    if (c->GetManifoldCount() > 0) {
					b2Body* body1 = c->GetShape1()->GetBody();
					b2Body* body2 = c->GetShape2()->GetBody();
					GameObject* go1 = (GameObject*) body1->GetUserData();
					GameObject* go2 = (GameObject*) body2->GetUserData();
					go1->hit();
					go2->hit();
		    }
		}
		Globals::checkObjectsAndDestroy();

	}
	exit();
}
