#include "PhysicsEngine.hpp"
#include <chrono>
#include <thread>

PhysicsEngine::PhysicsEngine(std::vector<Ball>& balls, int screenW, int screenH)
    : balls(balls), screenW(screenW), screenH(screenH), running(true) {}

void PhysicsEngine::run() {
    using namespace std::chrono;
    const float dt = 1.0f / 60.0f;

    while (running) {
        auto start = high_resolution_clock::now();

        for (auto& ball : balls) {
            ball.update(dt);
            ball.checkCollision(screenW, screenH);
        }

        auto end = high_resolution_clock::now();
        auto elapsed = duration_cast<milliseconds>(end - start);
        std::this_thread::sleep_for(milliseconds(16) - elapsed);
    }
}

void PhysicsEngine::stop() {
    running = false;
}