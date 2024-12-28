#pragma once

#include "includes.hpp"
#include "printable.hpp"

class Grid : public Printable {
public:
    Grid();
    ~Grid();

    std::string to_string() const override;

private:
    uint8_t** _grid;

    int _rows;
    int _cols;
    int _cell_size;

};
