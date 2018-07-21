#include "init.h"
#include "player.h"
#include "headers.h"
#include "globals.h"
#include "time.h"
#include "gameobject.h"
#include <iostream>

int main(int argc, char* args[]) {
	init();
	initGL();
	Globals::init();
	Player player;
	Globals::createRandomAsteroid();
	Globals::createRandomAsteroid();
	Globals::createRandomAsteroid();
	Globals::createRandomAsteroid();
	Globals::createRandomAsteroid();
	Time timer;

	while(!Globals::quit) {
		timer.update();
		startDraw();
		player.render();
		Globals::renderAsteroids();
		endDraw();

		player.update();
		Globals::world->Step(timer.getDeltaTime(), 10);

		for (b2Contact* c = Globals::world->GetContactList(); c; c = c->GetNext()) {
		    if (c->GetManifoldCount() > 0) {
					b2Body* body1 = c->GetShape1()->GetBody();
					b2Body* body2 = c->GetShape2()->GetBody();
					GameObject* go1 = (GameObject*) body1->GetUserData();
					GameObject* go2 = (GameObject*) body2->GetUserData();
					if(go1->getType() == TYPE::ASTEROID && go2->getType() == TYPE::PLAYER) {
						go1->hit();
						Globals::world->DestroyBody(body1);
					}
					if(go2->getType() == TYPE::ASTEROID && go1->getType() == TYPE::PLAYER) {
						go2->hit();
						Globals::world->DestroyBody(body2);
					}
		    }
		}
		Globals::checkAsteroidsAndDestroy();

	}
	exit();
}
