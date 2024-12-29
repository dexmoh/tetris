#pragma once

#include "grid.hpp"
#include "blocks.hpp"

class Game {
public:
    Game();

    void run();

private:
    Grid _grid;
    std::vector<Block> _blocks;
    Block& _current_block;
    Block& _next_block;

    void _draw() const;
    std::vector<Block> _get_new_blocks() const;

};
