#pragma once

#include "Const.hpp"

const int NUM_BLOCKS_X = 10;
const int NUM_BLOCKS_Y = 7;

class Blocks {
private:
    RectangleShape blocks[NUM_BLOCKS_X][NUM_BLOCKS_Y];
    Vector2f size;
    Vector2f position;

public:
    Blocks(float initWidth = 70.f, float initHeight = 30.f);

    void setPosition(float x, float y);
    bool handleCollision(const FloatRect& ballBounds);
    void draw(RenderWindow* window);
};