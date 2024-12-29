#include "includes.hpp"
#include "game.hpp"

int main(void) {
    const int SCREEN_W = 320;
    const int SCREEN_H = 640;
    const char* SCREEN_TITLE = "Tetris";

    // Create a window.
    InitWindow(SCREEN_W, SCREEN_H, SCREEN_TITLE);
    SetTargetFPS(60);
    HideCursor();

    auto game = Game();
    game.run();

    CloseWindow();
    return 0;
}
