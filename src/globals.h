#pragma once
#include "headers.h"

#define UNIT_SIZE 32

class Asteroid;

class Globals
{
public:
	static void init();
	static bool quit;
	static b2World *world;
	static GLuint getTexture(const char* name);
	static void createRandomAsteroid();
	static void renderAsteroids();

private:
	static std::map<std::string ,GLuint> textures;
	static std::vector<Asteroid> asteroidPrefabs;
	static std::vector<Asteroid> asteroids;
};
