#ifndef DEBUG

#include "globals.h"
#include "time.h"

SceRtcTick lastFrame;
SceRtcTick currentFrame;

Time::Time() {
  sceRtcGetCurrentTick(&currentFrame);
  lastFrame = currentFrame;
}

float Time::getDeltaTime() {
  return deltaTime;
}

void Time::update() {
  sceRtcGetCurrentTick(&currentFrame);

  deltaTime = (currentFrame.tick - lastFrame.tick) / (1000.0f*1000);
  lastFrame = currentFrame;
}

float Time::getFPS() {
  return 1.0f / deltaTime;
}

#endif
