#include "globals.h"
#include "utils.h"
#include "asteroid.h"
#include "vectormath.h"
#include "bullet.h"
#include "background.h"

b2World *Globals::world;
std::map<std::string, GLuint> Globals::textures;
std::vector<Asteroid*> Globals::asteroidPrefabs;
std::vector<Asteroid*> Globals::asteroids;
std::vector<Bullet*> Globals::bullets;
bool Globals::quit = false;
PLAYSTATE Globals::state = PLAYSTATE::MAIN_MENU;

std::vector<std::vector<float>> asteroidPolygons;

GLuint Bullet::bulletTexture = 0;

std::vector<float> asteroid1Polygons = { 
-0.3125, -0.21875, 0.125,  -0.3125,
0.3125, -0.15625, -0.0625, 0.1875,
-0.21875, 0.09375, -0.3125, -0.0625 };

std::vector<float> asteroid2Polygons = { 
-0.328125, -0.1875, -0.15625, -0.375,
0.25, -0.40625, 0.390625, -0.25, 
0.25, 0.21875, -0.015625, 0.328125,
-0.15625, 0.328125, -0.34375, 0.21875 };

void Globals::init() {
	b2AABB worldAABB;
	worldAABB.minVertex.Set(-100.0f, -100.0f);
	worldAABB.maxVertex.Set(100.0f, 100.0f);
	world = new b2World(worldAABB, b2Vec2(0,0), false);

	asteroidPolygons.push_back(asteroid1Polygons);
	asteroidPolygons.push_back(asteroid2Polygons);

	asteroidPrefabs.push_back(new Asteroid("textures/asteroid1.png", 32, 32));
	asteroidPrefabs.push_back(new Asteroid("textures/asteroid2.png", 48, 48));
	Bullet::bulletTexture = getTexture("textures/bullet.png");
	initBackground();
}

GLuint Globals::getTexture(const char* name) {
	std::map<std::string, GLuint>::iterator it = textures.find(name);
	if(it != textures.end()) {
		return it->second;
	}
	else {
		GLuint id = loadTexture(name);
		textures.insert(std::pair<std::string, GLuint>(name, id));
		return id;
	}
}

void Globals::createRandomAsteroid() {
	int randomAsteroid = rand() % asteroidPrefabs.size();
	Vector2f startPos(randomFloatBetween(-PLAYAREA_X, PLAYAREA_X), PLAYAREA_Y_TOP);
	Vector2f endPos(randomFloatBetween(-PLAYAREA_X, PLAYAREA_X), PLAYEAREA_Y_BOT);
	Vector2f normalizedBetween = Vector2f::getVector(startPos, endPos);
	normalizedBetween.normalize();
	float rotation = randomFloatBetween(-ROTATION_MAX, ROTATION_MAX);
	float speed = randomFloatBetween(SPEED_MIN, SPEED_MAX);
	float scale = randomFloatBetween(SCALE_MIN, SCALE_MAX);
	Asteroid *ast = new Asteroid(*asteroidPrefabs.at(randomAsteroid), startPos, normalizedBetween,asteroidPolygons.at(randomAsteroid),
	scale ,rotation, speed);
	asteroids.push_back(ast);
}

void Globals::renderObjects() {
	for(int i = 0; i < asteroids.size(); i++) {
		asteroids.at(i)->render();
	}
	for(int i = 0; i < bullets.size(); i++) {
		bullets.at(i)->render();
	}
}

void Globals::checkObjectsAndDestroy() {
	std::vector<Asteroid*>::iterator it = asteroids.begin();
	for( ; it != asteroids.end();) {
		b2Vec2 pos = (*it)->body->GetOriginPosition();
		if ((*it)->destroy || outsideBounds(pos)) {
			world->DestroyBody((*it)->body);
			delete (*it);
			it = asteroids.erase(it);
		}
		else {
			++it;
		}
	}
	std::vector<Bullet*>::iterator it2 = bullets.begin();
	for( ; it2 != bullets.end();) {
		b2Vec2 pos2 = (*it2)->body->GetOriginPosition();
		if ((*it2)->destroy || outsideBounds(pos2)) {
			world->DestroyBody((*it2)->body);
			delete (*it2);
			it2 = bullets.erase(it2);
		}
		else {
			++it2;
		}
	}
}

bool Globals::outsideBounds(b2Vec2 &pos) {
	if(pos.x < -PLAYAREA_X || pos.x > PLAYAREA_X) {
		return true;
	}
	else if(pos.y < PLAYEAREA_Y_BOT || pos.y > PLAYAREA_Y_TOP) {
		return true;
	}
	else {
		return false;
	}

}

void Globals::createBullet(Vector2f &pos) {
	Bullet *bullet = new Bullet(pos);
	bullets.push_back(bullet);
}