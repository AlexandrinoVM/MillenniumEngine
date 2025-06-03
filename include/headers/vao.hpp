#pragma once 
#include <glad/glad.h>
#include <GLFW/glfw3.h>
class VAO{
    public:
    VAO();
    void bindVAO();
    void unbidVAO();
    void destroyVAO();
    unsigned int getVAO(){return vao;};
    void VAOatribs(int location,int quantPos,int stride,int offset);
    private:
    unsigned int vao;
};
