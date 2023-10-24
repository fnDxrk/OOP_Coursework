#include "../include/Game.hpp"

//Initializer func
void Game::initWindow() {
    window = new RenderWindow(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Arkanoid");
    window->setFramerateLimit(60);
}

//Constructors/Destructors
Game::Game()
{
    initWindow();
}

Game::~Game()
{
    delete window;
}

// Functions

void Game::updateEvent()
{
    while(window->pollEvent(ev)) {
        if (ev.type == Event::Closed) 
            window->close();
    }
}

void Game::update()
{
    updateEvent();
}

void Game::render()
{
    window->clear();

    //Render items

    window->display();
}

void Game::run()
{
    while(window->isOpen()) {
        update();
        render();
    }
}
