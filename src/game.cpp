#include "game.hpp"

Game::Game() {
    _blocks = _get_new_blocks();
}

void Game::run()
{
    // Game loop.
    while (!WindowShouldClose()) {
        // 1. Event handling.

        // 2. Update game logic.

        // 3. Rendering.
        BeginDrawing();
        ClearBackground(BLACK);

        _grid.draw();

        EndDrawing();
    }
}

std::vector<Block> Game::_get_new_blocks() const {
    return {
        OBlock(), IBlock(), TBlock(), LBlock(), JBlock(), SBlock(), ZBlock()
    };
}
