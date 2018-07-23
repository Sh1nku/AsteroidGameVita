#ifndef DEBUG
#include "gui.h"
#include "headers.h"

void GUI::startGUIDraw() {
    ImGui_ImplVitaGL_NewFrame();
}

void GUI::endGUIDraw() {
    ImGui::Render();
    ImGui_ImplVitaGL_RenderDrawData(ImGui::GetDrawData());
}

#endif