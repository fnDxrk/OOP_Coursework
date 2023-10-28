#include "../include/GameState.hpp"

GameState::GameState(RenderWindow* window)
    : window(window)
    , ballMove(false)
{
    ball = new Ball();
    board = new Board();
    blocks = new Blocks();
}

GameState::~GameState()
{
    delete window;
    delete ball;
    delete board;
}

void GameState::handleInput()
{   
    if (!ballMove) {
        if (Keyboard::isKeyPressed(Keyboard::D)) {
            board->moveRight();
            ball->setPosition(Vector2f(board->getPosition().x + board->getSize().x / 2 - ball->getRadius(), ball->getPosition().y));
        }
        if (Keyboard::isKeyPressed(Keyboard::A)) {
            board->moveLeft();
            ball->setPosition(Vector2f(board->getPosition().x + board->getSize().x / 2 - ball->getRadius(), ball->getPosition().y));
        }
    }
    else if (ballMove) {
        if (Keyboard::isKeyPressed(Keyboard::D)) {
            board->moveRight();
        }
        if (Keyboard::isKeyPressed(Keyboard::A)) {
            board->moveLeft();
        }
    }

    while (window->pollEvent(ev)) {
        switch (ev.key.code) {
            case Keyboard::Escape :
                window->close();
                break;
            case Keyboard::Space :
                ballMove = true;

        }
    }
}

void GameState::update()
{   
    if (ballMove) {
        ball->move();
        if (ball->getGlobalBounds().intersects(board->getGlobalBounds()))
            ball->setVelocityY(-(rand()%7 + 3));
        if (blocks->handleCollision(ball->getGlobalBounds())) 
            ball->setVelocityY((rand()%7 + 3));
        if (ball->getPosition().y > board->getPosition().y)
            exit(0);
    }
}

void GameState::render(RenderWindow* window)
{
    ball->draw(window);
    board->draw(window);
    blocks->draw(window);
}