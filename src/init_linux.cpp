#ifdef DEBUG
#include "init.h"
#include "headers.h"

SDL_Window* gWindow = NULL;
SDL_GLContext gContext;

void init() {
	SDL_Init(SDL_INIT_VIDEO);
	IMG_Init(IMG_INIT_PNG);
  	SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 2 );
  	SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, 1 );
	SDL_GL_SetSwapInterval(1);
	gWindow = SDL_CreateWindow( "AsteroidsGame", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 960, 544,SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
	gContext = SDL_GL_CreateContext( gWindow );
}

void startDraw() {
	glClear((GLbitfield)GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void endDraw() {
	SDL_GL_SwapWindow(gWindow);
}

void exit() {
  	SDL_DestroyWindow( gWindow );
	SDL_Quit();
}

#endif
