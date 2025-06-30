#pragma once
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "camera.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
class Renderer{
    public:

    bool isRunning(){return running;}
    void init(GLFWwindow*win,Camera *cam);
    void wiredMode(bool active);
    void events();
    void processInput();
    void RenderWindow();
    void clear();
    glm::vec3 getPositions(){return positions;};
    void pickColor(double x,double y);
    private:
    double mx,my;
    bool running;
    int count = 0;
    glm::vec3 positions =glm::vec3(1.0f);


    
    
    bool firstclick = false;
    bool mouseOnscreen = false;

};