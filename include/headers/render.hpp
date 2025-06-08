#pragma once
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "camera.hpp"
#include <iostream>
class Renderer{
    public:

    bool isRunning(){return running;}
    void init(GLFWwindow*win,Camera *cam);
    
    void events();
    void processInput();
    void RenderWindow();
    void clear();
    private:
    
    bool running;
    int count = 0;
    
    
    bool firstclick = false;
    bool mouseOnscreen = false;

};