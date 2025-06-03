#pragma once
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Renderer{
    public:

    bool isRunning(){return running;}
    void init(GLFWwindow*window);
    void events();
    void processInput(GLFWwindow*window);
    void RenderWindow();
    void clear();
    private:
    bool running;
    int count = 0;
    GLFWwindow *win;

};