#include "../include/GameState.hpp"

void Game::initWindow()
{
    window = new RenderWindow(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Arkanoid");
    window->setFramerateLimit(60);
}

Game::Game()
{
    initWindow();
    ball = new Ball();
}

Game::~Game()
{
    delete window;
    delete ball;
}

void Game::handleInput()
{
    while (window->pollEvent(ev)) {
        if (ev.type == Event::KeyPressed) {
            switch (ev.key.code) {
                case Keyboard::Escape :
                    window->close();
                default:
                    break;
            }
        }
    }
}

void Game::update()
{
}

void Game::render(RenderWindow* window)
{
    window->clear();

    ball->draw(window);

    window->display();
}

void Game::run()
{
    while (window->isOpen()) {
        handleInput();
        update();
        render(window);
    }
}
