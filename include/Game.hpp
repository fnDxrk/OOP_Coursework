#pragma once

#include "Const.hpp"
#include "State.hpp"
#include "GameState.hpp"
#include "EndGameState.hpp"

class Game {
private:
    RenderWindow window;
    Font font;
    std::unique_ptr<State> currentState;

    void initWindow();

public:
    Game();
    virtual ~Game();

    void handleInput();
    void update();
    void render();
    void changeState(std::unique_ptr<State> newState);
    void run();
};
