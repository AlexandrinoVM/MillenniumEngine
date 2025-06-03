cmake_minimum_required(VERSION 3.10.0)
project(MillenniumEngine VERSION 0.1.0 LANGUAGES C CXX)

add_executable(MillenniumEngine src/main.cpp src/stb_image.cpp src/ebo.cpp src/render.cpp src/vao.cpp src/vbo.cpp src/window.cpp src/core.cpp src/shader.cpp src/glad.c)

target_include_directories(MillenniumEngine PRIVATE include)
target_link_libraries(MillenniumEngine glfw GL)