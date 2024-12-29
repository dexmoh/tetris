#include "game.hpp"

Game::Game() {
    // Create a new seed for the random gen.
    srand(time(0));

    // Load block textures.
    _block_sprites = LoadTexture("res/blocks.png");
    
    // Init grid and blocks list.
    _grid = Grid();
    _blocks = _get_new_blocks();

    _current_block = _get_rand_block();
    _next_block = _get_rand_block();
}

void Game::draw() const {
    _grid.draw(_block_sprites);
    _current_block.draw(_block_sprites);
}

void Game::handle_input() {
    switch (GetKeyPressed()) {
    case KEY_LEFT: // Move left.
        _current_block.move({0, -1});
        break;
    case KEY_RIGHT: // Move right.
        _current_block.move({0, 1});
        break;
    case KEY_DOWN: // Move down.
        _current_block.move({1, 0});
        break;
    case KEY_UP: // Rotate.
        _current_block.rotate();
        break;
    // Debug
    case KEY_SPACE:
        _current_block = _get_rand_block();
        break;
    default:
        break;
    }
}

std::vector<Block> Game::_get_new_blocks() const {
    return {
        OBlock(), IBlock(), TBlock(), LBlock(), JBlock(), SBlock(), ZBlock()
    };
}

Block Game::_get_rand_block() {
    if (_blocks.empty())
        _blocks = _get_new_blocks();

    int rand_index = rand() % _blocks.size();
    Block block = _blocks.at(rand_index);
    _blocks.erase(_blocks.begin() + rand_index);

    return block;
}
