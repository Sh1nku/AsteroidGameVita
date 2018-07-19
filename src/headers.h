#pragma once

#ifdef DEBUG
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <SDL2/SDL_image.h>
#include <Box2D/Box2D.h>
#else
#include <vita2d.h>
#include <vitaGL.h>
#include <Box2D.h>
#endif
#include <string>
