#include "../include/Blocks.hpp"

Blocks::Blocks(float initWidth, float initHeight)
    : size({ initWidth, initHeight })
{
    for (int i = 0; i < NUM_BLOCKS_X; i++) {
        for (int j = 0; j < NUM_BLOCKS_Y; j++) {
            blocks[i][j].setSize(size);
            blocks[i][j].setFillColor(Color::White);
            blocks[i][j].setPosition(i * (size.x + 20) + 60, j * (size.y + 15) + 120);
        }
    }
}

void Blocks::setPosition(float x, float y) {
    for (int i = 0; i < NUM_BLOCKS_X; i++) {
        for (int j = 0; j < NUM_BLOCKS_Y; j++) {
            blocks[i][j].setPosition(x, y);
        }
    }    
}

bool Blocks::handleCollision(const FloatRect& ballBounds) {
    for (int i = 0; i < NUM_BLOCKS_X; ++i) {
        for (int j = 0; j < NUM_BLOCKS_Y; ++j) {
            if (blocks[i][j].getGlobalBounds().intersects(ballBounds)) {
                blocks[i][j].setSize(Vector2f(0, 0));
                blocks[i][j].setPosition(-100, -100);
                return true;
            }
        }
    }
    return false;
}

void Blocks::draw(RenderWindow* window) {
    for (int i = 0; i < NUM_BLOCKS_X; i++) {
        for (int j = 0; j < NUM_BLOCKS_Y; j++) {
            window->draw(blocks[i][j]);
        }
    }
}

