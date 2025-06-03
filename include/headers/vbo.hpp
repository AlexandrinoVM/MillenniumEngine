#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class VBO{
    public:
    VBO(float *data,size_t size);
    void bindVBO();
    void unbidVBO();
    void destroyVBO();
    unsigned int getVBO(){return vbo;};
    private:
    unsigned int vbo;
};