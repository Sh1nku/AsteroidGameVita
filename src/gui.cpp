#include "gui.h"
#include "headers.h"

bool p_open = true;

GUI::GUI() {

}

GUI::~GUI() {

}

void GUI::drawGame() {
    startGUIDraw();

    endGUIDraw();
}

void GUI::drawMainMenu() {
    startGUIDraw();
    ImGui::SetNextWindowPos(ImVec2(870, 524));
    ImGui::SetNextWindowSize(ImVec2(90,20));
    ImGui::SetNextWindowBgAlpha(0);
    ImGui::Begin("AsteroidGameGUI", &p_open,
     ImGuiWindowFlags_NoTitleBar |  ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoMove
    | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoNav);
    ImGui::Text("FPS: %.1f", ImGui::GetIO().Framerate);
    ImGui::End();
    endGUIDraw();
}