#pragma once

#include "includes.hpp"

class Printable {
public:
    virtual std::string to_string() const = 0;
    
    virtual ~Printable() = default;

};
