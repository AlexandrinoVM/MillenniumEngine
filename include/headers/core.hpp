#pragma once
#include <iostream>
#include "render.hpp"
#include "window.hpp"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Core {
    public:
    void init(const char*text,int w,int h);
    void run();
    bool isrunning(){return Render.isRunning();}
    void close(){Window.close(); glfwTerminate();};
    void clear();
    GLFWwindow *getWindow(){return Window.getWindow();}
    public:
    window Window;
    Renderer Render;

};