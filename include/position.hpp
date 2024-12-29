#pragma once

#include "includes.hpp"

class Position {
public:
    Position(uint8_t row, uint8_t column);

    uint8_t get_row() const;
    uint8_t get_column() const;

private:
    uint8_t _row;
    uint8_t _column;

};
