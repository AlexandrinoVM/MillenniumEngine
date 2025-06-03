#pragma once
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "../include/headers/filemanager.hpp"

class shader{
    public:
    shader(const std::string &vert,const std::string &frag);
    void crateProgram(const unsigned int vert,const unsigned int frag);
    void useProgram();
    int getID(){return ID;};
    private:
    int ID;
};