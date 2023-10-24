#include "../include/Ball.hpp"

Ball::Ball(float speed)
    : radius(15) 
    , position({ SCREEN_WIDTH / 2 - radius, SCREEN_HEIGHT - SCREEN_HEIGHT / 6 - radius })
    , speed({ speed, speed })
    , color(Color::White)
{
    ball.setRadius(radius);
    ball.setFillColor(color);
    ball.setPosition(position.x, position.y);
}

void Ball::setPosition(float x, float y) {
    position.x = x;
    position.y = y;
    ball.setPosition(x, y);
}

Vector2f Ball::getPosition() const {
    return position;
}

void Ball::setSpeed(float dx, float dy) {
    speed.x = dx;
    speed.y = dy;
}

Vector2f Ball::getSpeed() const {
    return speed;
}

void Ball::move()
{
}

void Ball::draw(RenderWindow* window)
{
    window->draw(ball);
}