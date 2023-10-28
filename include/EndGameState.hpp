#pragma once

#include "State.hpp"

class EndGameState : public State {
private:
    int score; // Счет игрока

public:
    EndGameState(int finalScore);

    // Обработка ввода в состоянии завершения игры
    virtual void handleInput() override;

    // Обновление состояния завершения игры, если это необходимо
    virtual void update() override;

    // Отрисовка текста о завершении игры и счета игрока
    virtual void render(RenderWindow* window) override;
};
