#pragma once

class Controller {

public:
  float leftAxisX = 0;
  float leftAxisY = 0;
  bool x = false;
  bool circle = false;
  bool triangle = false;
  bool square = false;
  bool l1 = false;
  bool r1 = false;

  Controller();
  ~Controller();
  void update();
};
