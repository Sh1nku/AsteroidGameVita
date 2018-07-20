#include "globals.h"
#include "utils.h"

b2World *Globals::world;
std::map<std::string, GLuint> Globals::textures;
bool Globals::quit = false;

void Globals::init() {
	b2AABB worldAABB;
	worldAABB.minVertex.Set(-100.0f, -100.0f);
	worldAABB.maxVertex.Set(100.0f, 100.0f);
	world = new b2World(worldAABB, b2Vec2(0,0), false);
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
