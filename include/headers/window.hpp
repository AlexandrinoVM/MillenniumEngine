#pragma once
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdlib.h>

class window{
    public:
        void init(const char*windowName,int w,int he);
        void createWindow(){};
        void close();
        GLFWwindow* getWindow(){return window;}
    private:
        int widht;
        int height;
        const char*winName;
        GLFWwindow* window;
};