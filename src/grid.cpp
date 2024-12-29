#include "grid.hpp"

Grid::Grid()
    : _cell_size(32) {
    // Initialize grid.
    for (int i = 0; i < S_ROWS; i++)
        for (int j = 0; j < S_COLUMNS; j++)
            _grid[i][j] = 0;
}

void Grid::draw(const Texture2D& sprites) const {
    for (int i = 0; i < S_ROWS; i++) {
        for (int j = 0; j < S_COLUMNS; j++) {
            DrawTexturePro(
                sprites,
                { (float)_grid[i][j] * 32, 0, 32, 32 },
                {
                    (float)_cell_size * j,
                    (float)_cell_size * i,
                    (float)_cell_size,
                    (float)_cell_size
                },
                { 0, 0 }, 0.0f, WHITE
            );
        }
    }
}
