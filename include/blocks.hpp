#pragma once

#include "includes.hpp"
#include "position.hpp"

class Block {
public:
    enum Type : uint8_t {
        NONE = 0,
        Z, S, J, O, T, I, L
    };

    enum RotationState : uint8_t {
        NORTH = 0,
        EAST,
        SOUTH,
        WEST
    };

    Block();
    void draw(const Texture2D& sprites) const;
    Type get_type() const;

protected:
    Type _type;
    uint8_t _cell_size;

    // We'll save different rotation states in a map.
    RotationState _rot_state;
    std::map<RotationState, std::vector<Position>> _cells;

};

class OBlock : public Block {
public:
    OBlock();
};

class IBlock : public Block {
public:
    IBlock();
};

class TBlock : public Block {
public:
    TBlock();
};

class LBlock : public Block {
public:
    LBlock();
};

class JBlock : public Block {
public:
    JBlock();
};

class SBlock : public Block {
public:
    SBlock();
};

class ZBlock : public Block {
public:
    ZBlock();
};