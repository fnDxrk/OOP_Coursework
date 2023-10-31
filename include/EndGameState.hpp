#pragma once

#include "Const.hpp"
#include "State.hpp"
#include "TextGame.hpp"

class EndGameState : public State {
private:
    RenderWindow& window;
    Event ev;

    TextGame text;

    int scoreFinal;

    bool gameOver;

public:
    EndGameState(RenderWindow& windowGame, Font& fontGame, int& score);

    void handleInput() override;
    void update() override;
    void render(sf::RenderWindow& window) override;

    bool isGameOver() const override;
    int getScore() override;
};
