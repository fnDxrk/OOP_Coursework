#include "../include/GameState.hpp"

GameState::GameState(RenderWindow& windowGame, Font& fontGame)
    : window(windowGame)
    , font(fontGame)
    , ball()
    , board()
    , blocks()
    , ballMove(false)
    , text(fontGame)
    , gameOver(false)
    , score(0)
{
}

void GameState::handleInput()
{
    if (!ballMove) {
        if (Keyboard::isKeyPressed(Keyboard::D)) {
            board.moveRight();
            ball.setPosition(Vector2f(board.getPosition().x + board.getSize().x / 2 - ball.getRadius(), ball.getPosition().y));
        }
        if (Keyboard::isKeyPressed(Keyboard::A)) {
            board.moveLeft();
            ball.setPosition(Vector2f(board.getPosition().x + board.getSize().x / 2 - ball.getRadius(), ball.getPosition().y));
        }
    } else if (ballMove) {
        if (Keyboard::isKeyPressed(Keyboard::D)) {
            board.moveRight();
        }
        if (Keyboard::isKeyPressed(Keyboard::A)) {
            board.moveLeft();
        }
    }

    while (window.pollEvent(ev)) {
        switch (ev.key.code) {
        case Keyboard::Escape:
            window.close();
            break;
        case Keyboard::Space:
            ballMove = true;
            break;
        }
    }
}

void GameState::update()
{
    if (ballMove) {
        ball.move();
        if (ball.getGlobalBounds().intersects(board.getGlobalBounds()))
            ball.setVelocityY(-(rand() % 7 + 3));
        if (blocks.handleCollision(ball.getGlobalBounds())) {
            ball.setVelocityY((rand() % 7 + 3));
            score += 50;
        }
        if (ball.getPosition().y > board.getPosition().y || score == 3500)
            setGameOver(true);
    }
}

void GameState::render(RenderWindow& window)
{
    text.draw(&window, score);
    ball.draw(&window);
    board.draw(&window);
    blocks.draw(&window);
}

int GameState::getScore()
{
    return score;
}

bool GameState::isGameOver() const
{
    return gameOver;
}

void GameState::setGameOver(bool value)
{
    gameOver = value;
}

bool GameState::shouldRestart()
{
    return false; 
}