#pragma once
#include "Ball.hpp"
#include <GLFW/glfw3.h>

class Renderer {
public:
    Renderer(int w, int h, const char* title);
    bool init();
    void beginFrame();
    void draw(const Ball& ball);     // 🔧 Draw square at ball position
    void endFrame();
    void cleanup();
    bool shouldClose() const;

private:
    GLFWwindow* window;
    int width, height;
};