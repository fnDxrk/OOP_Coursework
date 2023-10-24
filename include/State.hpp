#pragma once

#include "Constants.hpp"

class State {
public:
    virtual ~State() {};

    virtual void handleInput() = 0;
    virtual void update() = 0;
    virtual void render(RenderWindow *window) = 0;
};