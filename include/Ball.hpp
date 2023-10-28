#pragma once

#include "Const.hpp"

class Ball {
private:
    CircleShape ball;
    float radius;
    Vector2f position;
    Vector2f velocity;

public:
    Ball(float initRadius = 15.f, float speedBall = 12.f);

    float getRadius() const;

    void setPosition(const Vector2f& newPosition);
    void setVelocityX(const float newVelocity);
    void setVelocityY(const float newVelocity);
    sf::FloatRect getGlobalBounds() const;
    sf::Vector2f getPosition() const;
    //sf::Vector2f getVelocity() const;

    void move();
    void draw(RenderWindow* window);
};