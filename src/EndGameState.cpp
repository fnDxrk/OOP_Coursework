#include "../include/EndGameState.hpp"

EndGameState::EndGameState(RenderWindow& windowGame, Font& fontGame, int& score)
    : window(windowGame)
    , text(fontGame)
    , scoreFinal(score)
{
    text.setCharacterSize(64);
    text.setPosition(SCREEN_WIDTH / 2 - 150, SCREEN_HEIGHT / 8);

}

void EndGameState::handleInput() {
    while (window.pollEvent(ev)) {
        switch (ev.key.code) {
        case Keyboard::Escape:
            window.close();
            break;
        }
    }
}

void EndGameState::update() {

}

void EndGameState::render(sf::RenderWindow& window) {
    text.draw(&window, scoreFinal);
}

bool EndGameState::isGameOver() const {
    return true;
}

int EndGameState::getScore() {
    return scoreFinal;
}