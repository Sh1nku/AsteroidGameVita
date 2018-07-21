#include "globals.h"
#include "utils.h"
#include "asteroid.h"

b2World *Globals::world;
std::map<std::string, GLuint> Globals::textures;
std::vector<Asteroid> Globals::asteroidPrefabs;
std::vector<Asteroid> Globals::asteroids;
bool Globals::quit = false;

b2PolyDef asteroid1Polygons;

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

	asteroidPrefabs.push_back(Asteroid("textures/asteroid1.png", 32, 32, &asteroid1Polygons));
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
	asteroids.push_back(Asteroid(asteroidPrefabs.at(randomAsteroid),
	1, 1, 0));
}

void Globals::renderAsteroids() {
	for(int i = 0; i < asteroids.size(); i++) {
		asteroids.at(i).render();
	}
}
