#include "Ball.hpp"
#include "Renderer.hpp"

#include <GLFW/glfw3.h>
#include <vector>
#include <chrono>
#include <thread>

int main() {
    Renderer renderer(800, 600, "Bouncing Ball Simulator");
    if (!renderer.init()) return -1;

    std::vector<Ball> balls;
    balls.emplace_back(400.0f, 100.0f);  // Initial position

    float lastTime = glfwGetTime();

    while (!renderer.shouldClose()) {
        float currentTime = glfwGetTime();
        float deltaTime = currentTime - lastTime;
        lastTime = currentTime;

        // Physics update
        for (auto& ball : balls) {
            ball.update(deltaTime);       // 🔧 TODO: Apply gravity and velocity
            ball.checkCollision(800, 600); // 🔧 TODO: Bounce off walls
        }

        renderer.beginFrame();
        for (auto& ball : balls) {
            renderer.draw(ball);          // 🔧 TODO: Draw a square for the ball
        }
        renderer.endFrame();

        std::this_thread::sleep_for(std::chrono::milliseconds(16)); // cap to ~60fps
    }

    renderer.cleanup();
    return 0;
}