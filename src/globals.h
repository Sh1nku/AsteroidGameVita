#pragma once
#include "headers.h"

class Globals
{
public:
	static void init();
	static bool quit;
	static b2World *world;
};
