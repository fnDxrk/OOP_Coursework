#include "../include/GameState.hpp"

void Game::initWindow() {
    window = new RenderWindow(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Arkanoid");
    window->setFramerateLimit(60);
}

Game::Game()
{
    initWindow();
}

Game::~Game()
{
    delete window;
}

void Game::handleInput() {
    while (window->pollEvent(ev)) {
        if (ev.type == Event::Closed) {
            window->close();
        }
        
    }
}

void Game::update()
{

}

void Game::render(RenderWindow* window)
{
    window->clear();

    

    window->display();
}

void Game::run()
{
    while(window->isOpen()) {
        handleInput();
        update(); 
        render(window);
    }
}
