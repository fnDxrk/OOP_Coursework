#include "../include/Ball.hpp"

Ball::Ball(float initRadius, float speedBall)
    : radius(initRadius)
    , position({ SCREEN_WIDTH / 2 - initRadius, SCREEN_HEIGHT - SCREEN_HEIGHT / 6 - initRadius})
    , velocity(speedBall, -speedBall)
{
    ball.setRadius(radius);
    ball.setPosition(position.x, position.y);
    ball.setFillColor(Color::White);
}

float Ball::getRadius() const {
    return radius;
}

void Ball::setPosition(const Vector2f& newPosition) {
    ball.setPosition(newPosition);
}

void Ball::setVelocityX(const float newVelocity) {
    velocity.x = newVelocity;
}

void Ball::setVelocityY(const float newVelocity) {
    velocity.y = newVelocity;
}

sf::FloatRect Ball::getGlobalBounds() const {
    return ball.getGlobalBounds();
}

sf::Vector2f Ball::getPosition() const {
    return ball.getPosition();
}

void Ball::move() {
    position.x += velocity.x;
    position.y += velocity.y;
    if (ball.getPosition().x < 0 || ball.getPosition().x > SCREEN_WIDTH - 2 * radius) {
        velocity.x = -velocity.x;
    }

    if (ball.getPosition().y < 0 || ball.getPosition().y > SCREEN_HEIGHT - 2 * radius) {
        velocity.y = -velocity.y;
    }

    ball.move(velocity.x, velocity.y);
}

void Ball::draw(RenderWindow* window) {
    window->draw(ball);
}