#include "globals.h"
#include "utils.h"
#include "asteroid.h"
#include "vectormath.h"

b2World *Globals::world;
std::map<std::string, GLuint> Globals::textures;
std::vector<Asteroid*> Globals::asteroidPrefabs;
std::vector<Asteroid*> Globals::asteroids;
bool Globals::quit = false;

b2PolyDef asteroid1Polygons;
b2PolyDef asteroid2Polygons;

void Globals::init() {
	b2AABB worldAABB;
	worldAABB.minVertex.Set(-100.0f, -100.0f);
	worldAABB.maxVertex.Set(100.0f, 100.0f);
	world = new b2World(worldAABB, b2Vec2(0,0), false);

	asteroid1Polygons.vertexCount = 6;
	asteroid1Polygons.vertices[0].Set(-0.3125, -0.21875);
	asteroid1Polygons.vertices[1].Set(0.125,  -0.3125);
	asteroid1Polygons.vertices[2].Set(0.3125, -0.15625);
	asteroid1Polygons.vertices[3].Set(-0.0625, 0.1875);
	asteroid1Polygons.vertices[4].Set(-0.21875, 0.09375);
	asteroid1Polygons.vertices[5].Set(-0.3125, -0.0625);
	asteroid1Polygons.density = 1.0f;

	asteroid2Polygons.vertexCount = 8;
	asteroid2Polygons.vertices[0].Set(-0.328125 * 2, -0.1875 * 2);
	asteroid2Polygons.vertices[1].Set(-0.15625 * 2, -0.375 * 2);
	asteroid2Polygons.vertices[2].Set(0.25 * 2, -0.40625 * 2);
	asteroid2Polygons.vertices[3].Set(0.390625 * 2, -0.25 * 2);
	asteroid2Polygons.vertices[4].Set(0.25 * 2, 0.21875 * 2);
	asteroid2Polygons.vertices[5].Set(-0.015625 * 2, 0.328125 * 2);
	asteroid2Polygons.vertices[6].Set(-0.15625 * 2, 0.328125 * 2);
	asteroid2Polygons.vertices[7].Set(-0.34375 * 2, 0.21875 * 2);
	asteroid2Polygons.density = 1.0f;

	asteroidPrefabs.push_back(new Asteroid("textures/asteroid1.png", 32, 32, &asteroid1Polygons));
	asteroidPrefabs.push_back(new Asteroid("textures/asteroid2.png", 64, 64, &asteroid2Polygons));
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
	Asteroid *ast = new Asteroid(*asteroidPrefabs.at(randomAsteroid), startPos, normalizedBetween, rotation, speed);
	asteroids.push_back(ast);
}

void Globals::renderAsteroids() {
	for(int i = 0; i < asteroids.size(); i++) {
		asteroids.at(i)->render();
	}
}

void Globals::checkAsteroidsAndDestroy() {
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
}

bool Globals::outsideBounds(b2Vec2 &pos) {
	if(pos.x < -PLAYAREA_X || pos.x > PLAYAREA_X) {
		return true;
	}
	else if(pos.y < PLAYEAREA_Y_BOT) {
		return true;
	}
	else {
		return false;
	}

}