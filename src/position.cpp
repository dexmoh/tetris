#include "position.hpp"

Position::Position(uint8_t row, uint8_t column) : _row(row), _column(column)
{}

uint8_t Position::get_row() const {
    return _row;
}

uint8_t Position::get_column() const {
    return _column;
}
