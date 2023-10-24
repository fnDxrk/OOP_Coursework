#pragma once

#include "Constants.hpp"

class Ball {
private:
    CircleShape ball;
    Vector2f position; //Положение
    Vector2f speed; //Скорость
    float radius; //Радиус
    Color color; //Цвет

public:
    Ball(float speed = 10);
    void setPosition(float x, float y);
    Vector2f getPosition() const;
    void setSpeed(float x, float y);
    Vector2f getSpeed() const;
    void move();
    void draw(RenderWindow *window);
};