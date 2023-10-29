#pragma once

#include "Const.hpp"

class TextGame {
private:
    Text text;
    
public:
    TextGame(Font& font);

    void setPosition(float x, float y);
    void setCharacterSize(int size);
    void draw(RenderWindow* window, int score);
};