#include "Ball.hpp"
#include "Renderer.hpp"
#include "PhysicsEngine.hpp"
#include <thread>
#include <vector>

int main() {
    Renderer renderer(800, 600, "Bouncing Ball Simulator");
    if (!renderer.init()) return -1;

    std::vector<Ball> balls;
    balls.emplace_back(400.0f, 100.0f);

    PhysicsEngine physics(balls, 800, 600);
    std::thread physicsThread([&]() {
        physics.run();  // Separate thread updates physics
    });

    while (!renderer.shouldClose()) {
        renderer.beginFrame();
        for (auto& ball : balls) {
            renderer.draw(ball);
        }
        renderer.endFrame();
    }

    physics.stop();
    physicsThread.join();
    renderer.cleanup();
    return 0;
}