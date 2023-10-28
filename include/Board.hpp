#pragma once

#include "Const.hpp"

class Board {
private:
    RectangleShape board;  // Графический объект доски
    Vector2f size;
    Vector2f position;  // Позиция доски
    float speed;  // Скорость перемещения доски

public:
    Board(float initWidth = 150.f, float initHeight = 20.f, float initSpeed = 15.f);

    void setPosition(const Vector2f& newPosition);
    Vector2f getPosition() const;

    Vector2f getSize() const;

    void moveLeft();
    void moveRight();

    void draw(RenderWindow* window);
    FloatRect getGlobalBounds() const;
};

