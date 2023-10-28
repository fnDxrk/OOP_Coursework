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

void Blocks::draw(RenderWindow* window) {
    for (int i = 0; i < NUM_BLOCKS_X; i++) {
        for (int j = 0; j < NUM_BLOCKS_Y; j++) {
            window->draw(blocks[i][j]);
        }
    }
}
