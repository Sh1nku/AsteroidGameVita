#ifndef DEBUG
#include "init.h"
#include "headers.h"

void init() {
	vglInit(0x800000);
	vglWaitVblankStart(true);
	IMG_Init(IMG_INIT_PNG);
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	io.IniFilename = NULL;
	ImGui_ImplVitaGL_Init();
	ImGui::StyleColorsDark();
	ImGuiStyle& style = ImGui::GetStyle();
    style.WindowBorderSize = 0.0f;

	ImGui_ImplVitaGL_TouchUsage(true);
	ImGui_ImplVitaGL_UseIndirectFrontTouch(false);
	ImGui_ImplVitaGL_MouseStickUsage(false);
	ImGui_ImplVitaGL_UseRearTouch(false);
	ImGui_ImplVitaGL_GamepadUsage(false);
}

void startDraw() {
	vglStartRendering();
	glViewport(0, 0, 960, 544);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void endDraw() {
	vglStopRendering();
}

void exit() {
	ImGui::DestroyContext();
}

#endif
