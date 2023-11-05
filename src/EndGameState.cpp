#include "../include/EndGameState.hpp"

#define logoutFile "images/logout.png"
#define reloadFile "images/reload.png"

EndGameState::EndGameState(RenderWindow& windowGame, Font& fontGame, int& score)
    : window(windowGame)
    , text(fontGame)
    , scoreFinal(score)
    , gameOver(true)
    , restart(false)
{
    text.setCharacterSize(64);
    text.setPosition(SCREEN_WIDTH / 2 - 150, SCREEN_HEIGHT / 5);

    if (!logout.loadFromFile(logoutFile) || !reload.loadFromFile(reloadFile))
        exit(0);

    logout.setSmooth(true);
    button[0].setTexture(&logout);

    reload.setSmooth(true);
    button[1].setTexture(&reload);

    initButton(button[0], 350, 450);
    initButton(button[1], 670, 450);
}

void EndGameState::initButton(RectangleShape& button, float x, float y)
{
    button.setSize(Vector2f(160, 160));
    x = x - button.getGlobalBounds().width / 2;
    y = y - button.getGlobalBounds().height / 2;

    button.setPosition(x, y);
}

void EndGameState::handleInput()
{
    while (window.pollEvent(ev)) {
        switch (ev.key.code) {
        case Keyboard::Escape:
            window.close();
            break;
        }
        if (Mouse::getPosition(window).x > button[0].getPosition().x + 10 && Mouse::getPosition(window).x < button[0].getPosition().x + button[0].getSize().x - 12 && Mouse::getPosition(window).y > button[0].getPosition().y + 10 && Mouse::getPosition(window).y < button[0].getPosition().y + button[0].getSize().y - 12)
            if (Mouse::isButtonPressed(Mouse::Left))
                window.close();
        if (Mouse::getPosition(window).x > button[1].getPosition().x + 10 && Mouse::getPosition(window).x < button[1].getPosition().x + button[1].getSize().x - 12 && Mouse::getPosition(window).y > button[1].getPosition().y + 10 && Mouse::getPosition(window).y < button[1].getPosition().y + button[1].getSize().y - 12)
            if (Mouse::isButtonPressed(Mouse::Left)) {
                setShouldRestart(true);
                setGameOver(false);
            }
    }
}

void EndGameState::update()
{
}

void EndGameState::render(sf::RenderWindow& window)
{
    text.draw(&window, scoreFinal);
    window.draw(button[0]);
    window.draw(button[1]);
}

bool EndGameState::isGameOver() const
{
    return gameOver;
}

void EndGameState::setGameOver(bool value)
{
    gameOver = value;
}

bool EndGameState::shouldRestart()
{
    return restart;
}

void EndGameState::setShouldRestart(bool value)

{
    restart = value;
}

int EndGameState::getScore()
{
    return scoreFinal;
}