#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;

#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 720

class State {
public:
    virtual ~State() {};

    virtual void handleInput() = 0;
    virtual void update() = 0;
    virtual void render(RenderWindow* window) = 0;
};