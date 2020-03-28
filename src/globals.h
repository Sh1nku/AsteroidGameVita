#pragma once
#include "headers.h"
#include "vectormath.h"

#define UNIT_SIZE 32
#define PLAYAREA_X 6
#define PLAYAREA_Y_TOP 5
#define PLAYEAREA_Y_BOT -5

#define ROTATION_MAX 3
#define SPEED_MAX 4
#define SPEED_MIN 2.5f
#define SCALE_MIN 1
#define SCALE_MAX 2

#define FILTER_PLAYER 0x0002
#define FILTER_ASTEROID 0x0004
#define FILTER_BULLET 0x0008

class Asteroid;
class Bullet;

enum PLAYSTATE {
	MAIN_MENU, GAME, EXIT
};

class Globals
{
public:
	static void init();
	static bool quit;
	static b2World *world;
	static GLuint getTexture(const char* name);
	static void createRandomAsteroid();
	static void createBullet(Vector2f &pos);
	static void renderObjects();
	static void checkObjectsAndDestroy();
	static std::vector<Asteroid*> asteroids;
	static std::vector<Bullet*> bullets;

	static PLAYSTATE state;

private:
	static bool outsideBounds(b2Vec2 &pos);

	static std::map<std::string ,GLuint> textures;
	static std::vector<Asteroid*> asteroidPrefabs;
};
