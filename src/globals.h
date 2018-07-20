#pragma once
#include "headers.h"

class Globals
{
public:
	static void init();
	static bool quit;
	static b2World *world;
	static GLuint getTexture(const char* name);

private:
	static std::map<std::string ,GLuint> textures;
};
