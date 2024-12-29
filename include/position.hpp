#pragma once

#include "includes.hpp"

class Position {
public:
    inline Position(int8_t row, int8_t column)
        : _row(row), _column(column)
    {}

    inline int8_t get_row() const {
        return _row;
    }

    inline int8_t get_column() const {
        return _column;
    }

private:
    int8_t _row;
    int8_t _column;

};
