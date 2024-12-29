#pragma once

#include "includes.hpp"

class Grid {
public:
    Grid();
    ~Grid();

    void draw() const;

private:
    uint8_t** _grid;

    int _rows;
    int _cols;
    int _cell_size;

    Texture2D _block_sprites;

};
