#pragma once

#include "includes.hpp"

class Grid {
public:
    static constexpr uint8_t S_ROWS = 20;
    static constexpr uint8_t S_COLUMNS = 10;

    Grid();

    void draw(const Texture2D& sprites) const;

private:
    uint8_t _grid[S_ROWS][S_COLUMNS];
    uint8_t _cell_size;

};
