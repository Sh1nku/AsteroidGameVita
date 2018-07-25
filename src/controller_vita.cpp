#ifndef DEBUG
#include "controller.h"
#include "headers.h"
#include "globals.h"

SceCtrlData ctrl;
const int DEADZONE = 20;

float constrainAxis(int axis) {
  axis -= 127;
  float floatAxis;
  if((axis < DEADZONE && axis > 0) ||
   (axis > -DEADZONE && axis < 0)) {
     floatAxis = 0;
  }
  else {
    floatAxis = (float)axis/127;
  }
  return floatAxis;
}

Controller::Controller() {
  sceCtrlSetSamplingMode(SCE_CTRL_MODE_ANALOG);
}

void Controller::update() {
  sceCtrlPeekBufferPositive(0, &ctrl, 1);
  x = (ctrl.buttons & SCE_CTRL_CROSS) > 0 ? true : false;
  square = (ctrl.buttons & SCE_CTRL_SQUARE) > 0 ? true : false;
  circle = (ctrl.buttons & SCE_CTRL_CIRCLE) > 0 ? true : false;
  triangle = (ctrl.buttons & SCE_CTRL_TRIANGLE) > 0 ? true : false;
  l1 = (ctrl.buttons & SCE_CTRL_L1) > 0 ? true : false;
  r1 = (ctrl.buttons & SCE_CTRL_R1) > 0 ? true : false;
  leftAxisX = constrainAxis(ctrl.lx);
  leftAxisY = constrainAxis(ctrl.ly);

}

Controller::~Controller() {
}

#endif
