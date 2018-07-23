#pragma once
#include "headers.h"

#define UNIT_SIZE 32
#define PLAYAREA_X 6
#define PLAYAREA_Y_TOP 5
#define PLAYEAREA_Y_BOT -5
#define ROTATION_MAX 3
#define SPEED_MAX 4
#define SPEED_MIN 2.5f
#define SCALE_MIN 1
#define SCALE_MAX 2

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
	static void checkAsteroidsAndDestroy();
	static std::vector<Asteroid*> asteroids;

private:
	static bool outsideBounds(b2Vec2 &pos);

	static std::map<std::string ,GLuint> textures;
	static std::vector<Asteroid*> asteroidPrefabs;
};
