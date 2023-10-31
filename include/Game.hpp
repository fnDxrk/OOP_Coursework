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
    void initFont();

    void changeState(std::unique_ptr<State> newState);

    void handleInput();
    void update();
    void render();

public:
    Game();
    void run();
};
