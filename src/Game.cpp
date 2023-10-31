#include "../include/Game.hpp"

Game::Game()
{
    initWindow();
    initFont();
    currentState = std::make_unique<GameState>(window, font);
}

void Game::initWindow()
{
    window.create(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Arkanoid");
    window.setFramerateLimit(60);
}

void Game::initFont()
{
    if (!font.loadFromFile("fonts/mont_extralightdemo.ttf"))
        exit(0);
}

void Game::changeState(std::unique_ptr<State> newState)
{
    currentState = std::move(newState);
}

void Game::handleInput()
{
    currentState->handleInput();
}

void Game::update()
{
    currentState->update();

    if (currentState->isGameOver()) {
        int score = currentState->getScore();
        std::unique_ptr<State> newState = std::make_unique<EndGameState>(window, font, score);
        changeState(std::move(newState));

    }
}

void Game::render()
{
    window.clear();
    currentState->render(window);
    window.display();
}

void Game::run()
{
    while (window.isOpen()) {
        handleInput();
        update();
        render();
    }
}