#pragma once

#include "State.hpp"
#include "Ball.hpp"
#include "Board.hpp"
#include "Blocks.hpp"
#include "Text.hpp"

class GameState : public State {
private:
    RenderWindow* window;
    Event ev;

    Ball* ball;
    Board* board;
    Blocks* blocks; 

    TextGame* text;

    int score;

    bool ballMove;
    
public:
    GameState(RenderWindow* window, Font& font);
    ~GameState();

    // Обработка ввода в игровом состоянии
    virtual void handleInput() override;

    // Обновление игровой логики : проверка столкновений, перемещение объектов и т. д.
    virtual void update() override;

    // Отрисовка игровых объеков
    virtual void render(RenderWindow* window) override;
};
