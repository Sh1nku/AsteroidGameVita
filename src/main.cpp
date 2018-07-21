#include "init.h"
#include "player.h"
#include "headers.h"
#include "globals.h"
#include "time.h"
#include "gameobject.h"

int main(int argc, char* args[]) {
	init();
	initGL();
	Globals::init();
	Player player;
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
					if(body1->GetUserData() != NULL) {
						GameObject* go1 = (GameObject*) body1->GetUserData();
						go1->hit();
						if(go1->getType() == TYPE::ASTEROID) {
							Globals::world->DestroyBody(body1);
						}
					}
					if(body2->GetUserData() != NULL) {
						GameObject* go2 = (GameObject*) body2->GetUserData();
						go2->hit();
						if(go2->getType() == TYPE::ASTEROID) {
							Globals::world->DestroyBody(body2);
						}
					}
		    }
		}
		Globals::checkAsteroidsAndDestroy();

	}
	exit();
}
