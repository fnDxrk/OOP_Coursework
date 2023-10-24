#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;

#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 720

class Game {
private:
    //Variables
    RenderWindow* window;
    Event ev;

    //Initialization
    void initWindow();

public:
    Game();
    virtual ~Game();

    //Functions
    void updateEvent();
    void update();
    void render();
    void run();
};