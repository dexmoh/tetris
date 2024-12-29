#include "blocks.hpp"

/* ### Base Block Class ### */
Block::Block()
    : _type(Type::NONE), _cell_size(32), _rot_state(RotationState::NORTH)
{}

void Block::draw(const Texture2D& sprites) const {
    for (const auto& pos : _cells.at(_rot_state)) {
        DrawTexturePro(
            sprites,
            { (float)_type * 32, 0, 32, 32 },
            {
                (float)(pos.get_column() * _cell_size),
                (float)(pos.get_row() * _cell_size),
                (float)_cell_size, (float)_cell_size
            },
            { 0, 0 }, 0.0f, WHITE
        );
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
}

IBlock::IBlock() {
    _type = Type::I;
    _cells[RotationState::NORTH] = { {1, 0}, {1, 1}, {1, 2}, {1, 3} };
    _cells[RotationState::EAST] = { {0, 2}, {1, 2}, {2, 2}, {3, 2} };
    _cells[RotationState::SOUTH] = { {2, 0}, {2, 1}, {2, 2}, {2, 3} };
    _cells[RotationState::WEST] = { {0, 1}, {1, 1}, {2, 1}, {3, 1} };
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
    _cells[RotationState::SOUTH] = { {1, 0}, {1, 1}, {1, 2}, {2, 1} };
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
