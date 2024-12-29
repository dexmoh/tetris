#include "blocks.hpp"

#include "grid.hpp"

/* ### Base Block Class ### */
Block::Block()
    : _type(Type::NONE),
      _cell_size(32),
      _rot_state(RotationState::NORTH),
      _offset({0, 3})
{}

void Block::draw(const Texture2D& sprites) const {
    for (const auto& pos : _cells.at(_rot_state)) {
        DrawTexturePro(
            sprites,
            { (float)_type * 32, 0, 32, 32 },
            {
                (float)((pos.get_column() + _offset.get_column())* _cell_size),
                (float)((pos.get_row() + _offset.get_row()) * _cell_size),
                (float)_cell_size, (float)_cell_size
            },
            { 0, 0 }, 0.0f, WHITE
        );
    }
}

void Block::move(Position offset) {
    int8_t new_row = _offset.get_row() + offset.get_row();
    int8_t new_column = _offset.get_column() + offset.get_column();

    // Check if the block is still inside the grid.
    for (const auto& pos : _cells.at(_rot_state)) {
        int8_t column = pos.get_column() + new_column;
        if (column < 0 || column >= Grid::S_COLUMNS)
            return;

        int8_t row = pos.get_row() + new_row;
        if (row < 0 || row >= Grid::S_ROWS)
            return;
    }

    // Update offset.
    _offset = { new_row, new_column };
}

void Block::rotate() {
    // TODO: Check if the block is still inside the grid after rotation.
    RotationState original_state = _rot_state;

    switch (_rot_state)
    {
    case RotationState::NORTH:
        _rot_state = RotationState::EAST;
        break;
    case RotationState::EAST:
        _rot_state = RotationState::SOUTH;
        break;
    case RotationState::SOUTH:
        _rot_state = RotationState::WEST;
        break;
    case RotationState::WEST:
        _rot_state = RotationState::NORTH;
        break;
    default:
        _rot_state = RotationState::NORTH;
        break;
    }
}

Block::Type Block::get_type() const {
    return _type;
}

/* ### Derived Block Classes ### */
OBlock::OBlock() {
    _type = Type::O;
    _cells[RotationState::NORTH] = { {0, 0}, {0, 1}, {1, 0}, {1, 1} };
    _cells[RotationState::EAST] = { {0, 0}, {0, 1}, {1, 0}, {1, 1} };
    _cells[RotationState::SOUTH] = { {0, 0}, {0, 1}, {1, 0}, {1, 1} };
    _cells[RotationState::WEST] = { {0, 0}, {0, 1}, {1, 0}, {1, 1} };
    _offset = {0, 4};
}

IBlock::IBlock() {
    _type = Type::I;
    _cells[RotationState::NORTH] = { {1, 0}, {1, 1}, {1, 2}, {1, 3} };
    _cells[RotationState::EAST] = { {0, 2}, {1, 2}, {2, 2}, {3, 2} };
    _cells[RotationState::SOUTH] = { {2, 0}, {2, 1}, {2, 2}, {2, 3} };
    _cells[RotationState::WEST] = { {0, 1}, {1, 1}, {2, 1}, {3, 1} };
    _offset = {-1, 3};
}

TBlock::TBlock() {
    _type = Type::T;
    _cells[RotationState::NORTH] = { {0, 1}, {1, 0}, {1, 1}, {1, 2} };
    _cells[RotationState::EAST] = { {0, 1}, {1, 1}, {1, 2}, {2, 1} };
    _cells[RotationState::SOUTH] = { {1, 0}, {1, 1}, {1, 2}, {2, 1} };
    _cells[RotationState::WEST] = { {0, 1}, {1, 0}, {1, 1}, {2, 1} };
}

LBlock::LBlock() {
    _type = Type::L;
    _cells[RotationState::NORTH] = { {0, 2}, {1, 0}, {1, 1}, {1, 2} };
    _cells[RotationState::EAST] = { {0, 1}, {1, 1}, {2, 1}, {2, 2} };
    _cells[RotationState::SOUTH] = { {1, 0}, {1, 1}, {1, 2}, {2, 0} };
    _cells[RotationState::WEST] = { {0, 0}, {0, 1}, {1, 1}, {2, 1} };
}

JBlock::JBlock() {
    _type = Type::J;
    _cells[RotationState::NORTH] = { {0, 0}, {1, 0}, {1, 1}, {1, 2} };
    _cells[RotationState::EAST] = { {0, 1}, {0, 2}, {1, 1}, {2, 1} };
    _cells[RotationState::SOUTH] = { {1, 0}, {1, 1}, {1, 2}, {2, 2} };
    _cells[RotationState::WEST] = { {0, 1}, {1, 1}, {2, 0}, {2, 1} };
}

SBlock::SBlock() {
    _type = Type::S;
    _cells[RotationState::NORTH] = { {0, 1}, {0, 2}, {1, 0}, {1, 1} };
    _cells[RotationState::EAST] = { {0, 1}, {1, 1}, {1, 2}, {2, 2} };
    _cells[RotationState::SOUTH] = { {1, 1}, {1, 2}, {2, 0}, {2, 1} };
    _cells[RotationState::WEST] = { {0, 0}, {1, 0}, {1, 1}, {2, 1} };
}

ZBlock::ZBlock() {
    _type = Type::Z;
    _cells[RotationState::NORTH] = { {0, 0}, {0, 1}, {1, 1}, {1, 2} };
    _cells[RotationState::EAST] = { {0, 2}, {1, 1}, {1, 2}, {2, 1} };
    _cells[RotationState::SOUTH] = { {1, 0}, {1, 1}, {2, 1}, {2, 2} };
    _cells[RotationState::WEST] = { {0, 1}, {1, 0}, {1, 1}, {2, 0} };
}
