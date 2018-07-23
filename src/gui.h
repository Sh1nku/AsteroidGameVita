#pragma once

class GUI {
public:
    GUI();
    ~GUI();
    void drawMainMenu();
    void drawGame();

    static void* ptrWindow;

private:
    void startGUIDraw();
    void endGUIDraw();
};