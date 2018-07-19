#include "globals.h"

b2World *Globals::world;

void Globals::init() {
	b2AABB worldAABB;
	worldAABB.minVertex.Set(-100.0f, -100.0f);
	worldAABB.maxVertex.Set(100.0f, 100.0f);
	world = new b2World(worldAABB, b2Vec2(0,1), true);
}
