#pragma once

#include "includes.hpp"
#include "blocks.hpp"
#include "grid.hpp"

class Game {
public:
    Game();

    void draw() const;
    void handle_input();

private:
    std::vector<Block> _get_new_blocks() const;
    Block _get_rand_block();

private:
    Grid _grid;
    std::vector<Block> _blocks;
    Block _current_block;
    Block _next_block;

    Texture2D _block_sprites;

};
