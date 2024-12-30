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

    // Game loop.
    while (!WindowShouldClose()) {
        // Event handling.
        game.handle_input();

        // Game logic.
        game.handle_logic();

        // Rendering.
        BeginDrawing();
        ClearBackground(BLACK);

        game.draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
