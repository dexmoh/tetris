#include "includes.hpp"

#include "grid.hpp"

int main(void) {
    const int SCREEN_W = 300;
    const int SCREEN_H = 600;
    const char* SCREEN_TITLE = "Tetris";

    // Create a window.
    InitWindow(SCREEN_W, SCREEN_H, SCREEN_TITLE);
    SetTargetFPS(30);
    HideCursor();

    auto grid = Grid();
    std::cout << grid.to_string();

    // Main loop.
    while (!WindowShouldClose()) {
        // 1. Event handling.

        // 2. Update game logic.
        Vector2 mouse_pos = GetMousePosition();

        // 3. Rendering.
        BeginDrawing();
        ClearBackground(SKYBLUE);

        DrawFPS(10, 10);
        DrawCircle(mouse_pos.x, mouse_pos.y, 10, WHITE);
        DrawText("Hello, raylib!", 10, 40, 30, BLACK);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
