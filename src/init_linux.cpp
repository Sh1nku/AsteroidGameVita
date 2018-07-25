#ifdef DEBUG
#include "init.h"
#include "gui.h"
#include "headers.h"

SDL_Window* gWindow = NULL;
SDL_GLContext gContext;
void* GUI::ptrWindow;

void init() {
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK | SDL_INIT_TIMER);
	IMG_Init(IMG_INIT_PNG);
	SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 ); 
	SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 2 );
  	SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, 2 );
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
	SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
	SDL_DisplayMode current;
    SDL_GetCurrentDisplayMode(0, &current);
	gWindow = SDL_CreateWindow( "AsteroidsGame", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 960, 544,SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
	gContext = SDL_GL_CreateContext( gWindow );
	SDL_GL_SetSwapInterval(1);
	ImGui::CreateContext();
	IMGUI_CHECKVERSION();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
	io.IniFilename = NULL;
	GUI::ptrWindow = gWindow;
	ImGui_ImplSDL2_InitForOpenGL(gWindow, gContext);
    ImGui_ImplOpenGL2_Init();
	ImGui::StyleColorsDark();
	ImGuiStyle& style = ImGui::GetStyle();
    style.WindowBorderSize = 0.0f;
}

void startDraw() {
	glViewport(0, 0, 960, 544);
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
