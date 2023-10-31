#pragma once

#include <Const.hpp>

class State {
public:
    virtual void handleInput() = 0;
    virtual void update() = 0;
    virtual void render(sf::RenderWindow& window) = 0;
    virtual bool isGameOver() const { return false; }
    virtual int getScore() = 0;

    virtual ~State() { }
};
