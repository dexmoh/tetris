#include "grid.hpp"

Grid::Grid() : _rows(20), _cols(10), _cell_size(30) {
    // Initialize grid.
    _grid = new uint8_t*[_rows];
    for (int i = 0; i < _rows; i++) {
        _grid[i] = new uint8_t[_cols];
        for (int j = 0; j < _cols; j++)
            _grid[i][j] = 0;
    }
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

std::string Grid::to_string() const {
    auto out_str = std::string("");

    // Convert the grid to a string.
    for (int i = 0; i < _rows; i++) {
        for (int j = 0; j < _cols; j++) {
            out_str += std::to_string(_grid[i][j]);
            out_str += ' ';
        }
        out_str += '\n';
    }

    return out_str;
}
