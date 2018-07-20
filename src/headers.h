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
#include <psp2/kernel/processmgr.h>
#include <psp2/ctrl.h>
#include <psp2/rtc.h> 
#endif
#include <string>
