#include "grid.hpp"

#include "blocks.hpp"

Grid::Grid() : _rows(20), _cols(10), _cell_size(32) {
    // Initialize grid.
    _grid = new uint8_t*[_rows];
    for (int i = 0; i < _rows; i++) {
        _grid[i] = new uint8_t[_cols];
        for (int j = 0; j < _cols; j++)
            _grid[i][j] = 0;
    }

    // Load block textures.
    _block_sprites = LoadTexture("res/blocks.png");
}

Grid::~Grid() {
    // Delete grid.
    if (_grid != nullptr) {
        for (int i = 0; i < _rows; i++)
            delete [] _grid[i];

        delete [] _grid;
        _grid = nullptr;
    }
}

void Grid::draw() const {
    for (int i = 0; i < _rows; i++) {
        for (int j = 0; j < _cols; j++) {
            DrawTexturePro(
                _block_sprites,
                { (float)_grid[i][j] * 32, 0, 32, 32 },
                { (float)_cell_size * j, (float)_cell_size * i, (float)_cell_size, (float)_cell_size },
                { 0, 0 }, 0.0f, WHITE
            );
        }
    }

    // Testing
    Block block;
    switch (rand() % 7) {
    case 0:
        block = OBlock();
        break;
    case 1:
        block = IBlock();
        break;
    case 2:
        block = TBlock();
        break;
    case 3:
        block = LBlock();
        break;
    case 4:
        block = JBlock();
        break;
    case 5:
        block = SBlock();
        break;
    case 6:
        block = ZBlock();
        break;
    }
    
    block.draw(_block_sprites);
}
