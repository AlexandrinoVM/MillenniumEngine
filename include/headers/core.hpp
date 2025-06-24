#pragma once
#include <iostream>
#include "render.hpp"
#include "window.hpp"
#include "camera.hpp"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "shaders.hpp"
//#include "gui.hpp"
class Core {
    public:
    void init(const char*text,int w,int h);
    void run();
    bool isrunning(){return Render->isRunning();}
    void close(){Window.close(); glfwTerminate();};
    void clear();
    void loadShaders(const std::string &ShaderName,const std::string &vert,const std::string &frag);
    void useProgram(const std::string &Shadername);
    shader& shaderConfig(){return Shader;};
    // shader& shaderConfig(){return Shader;};
    Camera& CameraConfigs() { return camera;};
    Renderer& RendererConfigs() { return *Render;};
    int getProgramId();
    GLFWwindow *getWindow(){return Window.getWindow();};
    void fpsCounter();
    void GuiInit(const char *GLSLVERSION);
    public:
    double fps =0;
    double startCounter = 0.0;
    double end;
    window Window;
    Renderer *Render;
    shader Shader;
    Camera camera;
    //GUI gui;

};