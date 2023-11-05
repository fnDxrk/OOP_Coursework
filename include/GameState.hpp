#pragma once

#include "Const.hpp"
#include "State.hpp"
#include "TextGame.hpp"
#include "Ball.hpp"
#include "Board.hpp"
#include "Blocks.hpp"

class GameState : public State {
private:
    RenderWindow& window;
    Event ev;

    TextGame text;
    Font& font;
    
    Ball ball;
    Board board;
    Blocks blocks;

    int score;

    bool ballMove;
    bool gameOver;

public:
    GameState(RenderWindow& windowGame, Font& fontGame);

    void handleInput() override;
    void update() override;
    void render(sf::RenderWindow& window) override;

    int getScore() override;

    bool isGameOver() const override;
    void setGameOver(bool value);
    bool shouldRestart() override;
};
