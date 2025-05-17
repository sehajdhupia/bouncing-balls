#define GL_SILENCE_DEPRECATION
#include "Renderer.hpp"
#include <iostream>

Renderer::Renderer(int w, int h, const char* title)
    : width(w), height(h), window(nullptr) {}

    bool Renderer::init() {
        if (!glfwInit()) {
            std::cerr << "Failed to init GLFW\n";
            return false;
        }
    
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    
        window = glfwCreateWindow(width, height, "Bouncing Ball Simulator", nullptr, nullptr);
        if (!window) {
            std::cerr << "Failed to create window\n";
            glfwTerminate();
            return false;
        }
    
        glfwMakeContextCurrent(window);
    
        // Set viewport and projection for 2D rendering
        glViewport(0, 0, width, height);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0, width, height, 0, -1, 1);  // Top-left is (0, 0)
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
    
        return true;
    }

void Renderer::beginFrame() {
    glClearColor(0.05f, 0.05f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::draw(const Ball& ball) {
    glm::vec2 pos = ball.getPosition();
    float r = ball.getRadius();

    float left   = pos.x - r;
    float right  = pos.x + r;
    float top    = pos.y - r;
    float bottom = pos.y + r;

    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.2f, 0.2f); // Bright red
    glVertex2f(left, top);
    glVertex2f(right, top);
    glVertex2f(right, bottom);
    glVertex2f(left, bottom);
    glEnd();
}

void Renderer::endFrame() {
    glfwSwapBuffers(window);
    glfwPollEvents();
}

bool Renderer::shouldClose() const {
    return glfwWindowShouldClose(window);
}

void Renderer::cleanup() {
    glfwDestroyWindow(window);
    glfwTerminate();
}