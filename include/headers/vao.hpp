#pragma once 
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <utils/meshiUtils.hpp>
class VAO{
    public:
    VAO();
    void bindVAO();
    void bindVAO(unsigned int vao);
    void unbidVAO();
    void destroyVAO();
    unsigned int getVAO(){return vao;};
    void VAOatribs(int location,int quantPos,int stride,int offset);
    private:
    unsigned int vao;
};
