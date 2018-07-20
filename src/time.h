#pragma once

class Time {
public:
  Time();
  float getDeltaTime();
  float getFPS();
  void update();
private:
  float deltaTime;
};
