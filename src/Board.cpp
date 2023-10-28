#include "../include/Board.hpp"

Board::Board(float initWidth, float initHeight, float initSpeed)
    : position({ (SCREEN_WIDTH - initWidth) / 2, SCREEN_HEIGHT - SCREEN_HEIGHT / 7.5 - initHeight / 2 })
    , size({ initWidth,initHeight })
    , speed(initSpeed)
{
    board.setSize(size);
    board.setFillColor(Color::White);
    board.setPosition(position);
}

void Board::setPosition(const Vector2f& newPosition)
{
    position = newPosition;
    board.setPosition(position);
}

Vector2f Board::getPosition() const {
    return board.getPosition();
}

Vector2f Board::getSize() const {
    return board.getSize();
}

void Board::moveLeft()
{
    position.x -= speed;
    if (position.x < 0) {
        position.x = 0;
    }
    board.setPosition(position);
}

void Board::moveRight()
{
    position.x += speed;
    if (position.x + size.x > SCREEN_WIDTH) {
        position.x = SCREEN_WIDTH - size.x;
    }
    board.setPosition(position);
}

void Board::draw(RenderWindow* window)
{
    window->draw(board);
}

FloatRect Board::getGlobalBounds() const
{
    return board.getGlobalBounds();
}
