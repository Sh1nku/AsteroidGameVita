#pragma once

#ifdef DEBUG
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <SDL2/SDL_image.h>
#include <Box2D/Box2D.h>
#include "imgui/imgui.h"
#include "imgui/imgui_impl_sdl.h"
#include "imgui/imgui_impl_opengl2.h"
#else
#include <vita2d.h>
#include <vitaGL.h>
#include <Box2D.h>
#include <psp2/kernel/processmgr.h>
#include <psp2/ctrl.h>
#include <psp2/rtc.h>
#include <imgui_vita.h>
#endif
#include <math.h>
#include <string>
#include <map>
#include <vector>
#include <cstdlib>
