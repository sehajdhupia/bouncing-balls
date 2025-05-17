#pragma once
#include <glm/glm.hpp>

class Ball {
public:
    Ball(float x, float y);

    void update(float dt);                        // 🔧 Apply gravity & update position
    void checkCollision(int screenW, int screenH); // 🔧 Bounce off screen edges

    glm::vec2 getPosition() const;
    float getRadius() const;

private:
    glm::vec2 position;
    glm::vec2 velocity;
    float radius;
    float gravity;
};