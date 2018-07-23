#include "gui.h"
#include "headers.h"

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
        if (ImGui::BeginMenuBar())
        {
            if (ImGui::BeginMenu("Menu"))
            {
                ImGui::MenuItem("Main menu bar", NULL, false);
                ImGui::MenuItem("Main menu bar", NULL, false);
                ImGui::MenuItem("Main menu bar", NULL, false);
                ImGui::MenuItem("Main menu bar", NULL, false);
                ImGui::MenuItem("Main menu bar", NULL, false);
                ImGui::EndMenu();
            }
            ImGui::EndMenuBar();
        }
    ImGui::Text("FPS: %.1f", ImGui::GetIO().Framerate);
    endGUIDraw();
}