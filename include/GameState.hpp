#pragma once

#include "State.hpp"

class Game : public State {
private:
    RenderWindow* window;
    Event ev;

    void initWindow();

public:
    Game();
    virtual ~Game();

    void handleInput() override;
    void update() override;
    void render(RenderWindow* window) override;
    void run();
};