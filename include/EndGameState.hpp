#pragma once

#include "Const.hpp"
#include "State.hpp"
#include "TextGame.hpp"

class EndGameState : public State {
private:
    RenderWindow& window;
    Event ev;

    TextGame text;
    
    RectangleShape button[2];
    Texture logout;
    Texture reload;

    int scoreFinal;

    bool gameOver;
    bool restart;

    void initButton(RectangleShape& button, float x, float y);

public:
    EndGameState(RenderWindow& windowGame, Font& fontGame, int& score);

    void handleInput() override;
    void update() override;
    void render(sf::RenderWindow& window) override;

    bool isGameOver() const override;
    void setGameOver(bool value);
    bool shouldRestart() override;
    void setShouldRestart(bool value);
    int getScore() override;
};
