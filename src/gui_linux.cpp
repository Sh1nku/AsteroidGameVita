#ifdef DEBUG
#include "gui.h"
#include "headers.h"

void GUI::startGUIDraw() {
	ImGui_ImplOpenGL2_NewFrame();
	ImGui_ImplSDL2_NewFrame((SDL_Window*)ptrWindow);
	ImGui::NewFrame();
}

void GUI::endGUIDraw() {
    ImGui::Render();
	ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());
}

#endif