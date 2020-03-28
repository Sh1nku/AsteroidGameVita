#include "gui.h"
#include "headers.h"
#include "globals.h"

bool p_open = true;

ImVec2 fpsCounterPos(870, 524);
ImVec2 fpsCounterSize(90,20);

ImVec2 mainMenuPos(300, 92);
ImVec2 mainMenuSize(360, 360);

GUI::GUI() {

}

GUI::~GUI() {

}

void GUI::drawGame() {
    startGUIDraw();

    ImGui::SetNextWindowPos(fpsCounterPos, ImGuiCond_FirstUseEver);
    ImGui::SetNextWindowSize(fpsCounterSize, ImGuiCond_FirstUseEver);
    ImGui::SetNextWindowBgAlpha(0);
    ImGui::Begin("FPSCounter", &p_open,
     ImGuiWindowFlags_NoTitleBar |  ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoMove
    | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoNav);
    ImGui::Text("FPS: %.1f", ImGui::GetIO().Framerate);
    ImGui::End();

    endGUIDraw();
}

void GUI::drawMainMenu() {
    startGUIDraw();

    ImGui::SetNextWindowPos(mainMenuPos);
    ImGui::SetNextWindowSize(mainMenuSize);
    ImGui::Begin("MainMenu", &p_open,
     ImGuiWindowFlags_NoTitleBar |  ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoMove
    | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoNav);
    if(ImGui::Button("Start", ImVec2(ImGui::GetWindowSize().x - 16, ImGui::GetWindowSize().y / 3.2))) {
        Globals::state = PLAYSTATE::GAME;
    }
    if(ImGui::Button("Controls", ImVec2(ImGui::GetWindowSize().x - 16, ImGui::GetWindowSize().y / 3.2))) {
        ImGui::SetCursorPosX(870);
    }
    if(ImGui::Button("Exit", ImVec2(ImGui::GetWindowSize().x - 16, ImGui::GetWindowSize().y / 3.2))) {
        Globals::state = PLAYSTATE::EXIT;
    }
    ImGui::End();
    endGUIDraw();
}