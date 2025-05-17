cmake_minimum_required(VERSION 3.10)
project(BouncingBallSim)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

add_executable(BouncingBallSim main.cpp)
target_link_libraries(BouncingBallSim OpenGL::GL glfw)