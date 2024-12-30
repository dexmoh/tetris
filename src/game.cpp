#include "game.hpp"

Game::Game()
    : _tick_interval(0.3), _time_since_last_tick(GetTime())
{
    // Create a new seed for the random gen.
    srand(time(0));

    // Load block textures.
    _block_sprites = LoadTexture("blocks.png");
    
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

void Game::handle_logic() {
    double current_time = GetTime();
    if (current_time > _time_since_last_tick + _tick_interval) {
        _time_since_last_tick = current_time;
        _current_block.move({1, 0});

        // Testing.
        bool collision = false;
        std::vector<Position> positions = _current_block.get_positions();
        for (const auto& pos : positions) {
            if (pos.get_row() >= Grid::S_ROWS - 1) {
                collision = true;
                break;
            }
        }

        // This is so cursed.
        Block future_block = _current_block;
        future_block.move({1, 0});

        if (_grid.collides(future_block))
            collision = true;

        if (collision) {
            _grid.set_block(_current_block);
            _current_block = _next_block;
            _next_block = _get_rand_block();
        }
    }
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
