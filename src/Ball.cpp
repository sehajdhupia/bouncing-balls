#include "Ball.hpp"

Ball::Ball(float x, float y)
    : position(x, y), velocity(0.0f, 0.0f), radius(20.0f), gravity(500.0f) {}

void Ball::update(float dt) {
    velocity.y += gravity * dt;
    position += velocity * dt;
}

void Ball::checkCollision(int screenW, int screenH) {
    if (position.y + radius > screenH) {
        position.y = screenH - radius;
        velocity.y *= -0.8f;  // bounce with damping
    }
    if (position.y - radius < 0) {
        position.y = radius;
        velocity.y *= -0.8f;
    }
    if (position.x - radius < 0) {
        position.x = radius;
        velocity.x *= -0.8f;
    }
    if (position.x + radius > screenW) {
        position.x = screenW - radius;
        velocity.x *= -0.8f;
    }
}

glm::vec2 Ball::getPosition() const {
    return position;
}

float Ball::getRadius() const {
    return radius;
}