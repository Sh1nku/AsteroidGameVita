#ifdef DEBUG

#include "globals.h"
#include "time.h"

unsigned int lastFrame;
unsigned int currentFrame;

Time::Time() {
  currentFrame = SDL_GetTicks();
  lastFrame = SDL_GetTicks();
}

float Time::getDeltaTime() {
  return deltaTime;
}

void Time::update() {
  currentFrame = SDL_GetTicks();
  deltaTime = ((float)currentFrame - lastFrame) / 1000;
  lastFrame = currentFrame;
}

float Time::getFPS() {
  return 1.0f / deltaTime;
}

#endif
