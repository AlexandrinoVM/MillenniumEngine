#pragma once
#include <iostream>
#include "render.hpp"
#include "window.hpp"
#include "camera.hpp"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "shaders.hpp"

class Core {
    public:
    void init(const char*text,int w,int h);
    void run();
    bool isrunning(){return Render.isRunning();}
    void close(){Window.close(); glfwTerminate();};
    void clear();
    void loadShaders(const std::string &ShaderName,const std::string &vert,const std::string &frag);
    void useProgram(const std::string &Shadername);
    shader& shaderConfig(){return Shader;};
    Camera& CameraConfigs() { return camera;};
    int getProgramId();
    GLFWwindow *getWindow(){return Window.getWindow();}
    public:
    window Window;
    Renderer Render;
    shader Shader;
    Camera camera;

};