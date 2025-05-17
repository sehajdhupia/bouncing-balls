#pragma once
#include <glm/glm.hpp>

class Ball {
public:
    Ball(float x, float y);

    void update(float dt);                        // gravity & update position
    void checkCollision(int screenW, int screenH); // bounce off screen edges

    glm::vec2 getPosition() const;
    float getRadius() const;

private:
    glm::vec2 position;
    glm::vec2 velocity;
    float radius;
    float gravity;
};