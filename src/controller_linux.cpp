#ifdef DEBUG
#include "controller.h"
#include "headers.h"
#include "globals.h"

SDL_GameController *controller = NULL;
SDL_Event e;
const int DEADZONE = 6000;

float constrainAxis(int axis) {
  float floatAxis;
  if((axis < DEADZONE && axis > 0) ||
   (axis > -DEADZONE && axis < 0)) {
     floatAxis = 0;
  }
  else {
    floatAxis = (float)axis/32768;
  }
  return floatAxis;
}

Controller::Controller() {
  for (int i = 0; i < SDL_NumJoysticks(); ++i) {
      if (SDL_IsGameController(i)) {
          controller = SDL_GameControllerOpen(i);
          if (controller) {
              break;
          } else {
              throw "Could not open gamecontroller\n";
          }
      }
  }
}

void Controller::update() {
  while( SDL_PollEvent( &e ) != 0 )
  {
      if( e.type == SDL_QUIT )
      {
          Globals::quit = true;
      }
  }
  x = SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_A);
  square = SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_X);
  circle = SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_B);
  triangle = SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_Y);
  l1 = SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_LEFTSHOULDER);
  r1 = SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_RIGHTSHOULDER);
  leftAxisX = constrainAxis(SDL_GameControllerGetAxis(controller, SDL_CONTROLLER_AXIS_LEFTX));
  leftAxisY = constrainAxis(SDL_GameControllerGetAxis(controller, SDL_CONTROLLER_AXIS_LEFTY));

}

Controller::~Controller() {
}

#endif
