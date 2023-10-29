#pragma once

#include "Const.hpp"

class State {
public:
    virtual void handleInput() = 0;
    virtual void update() = 0;
    virtual void render(RenderWindow* window) = 0;
    
};