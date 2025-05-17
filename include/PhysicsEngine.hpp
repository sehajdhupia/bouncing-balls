#pragma once
#include <vector>
#include <atomic>
#include <thread>
#include "Ball.hpp"

class PhysicsEngine{

public: 
    PhysicsEngine(std::vector<Ball>& balls, int screenW, int screenH);
    void run();
    void stop();

private:
    std::vector<Ball>& balls;
    std::atomic<bool> running;
    int screenW, screenH
};