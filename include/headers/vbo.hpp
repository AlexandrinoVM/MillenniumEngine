#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

class VBO{
    public:
    VBO(float *data,size_t size);
    void bindVBO();
    void unbidVBO();
    void destroyVBO();
    void setData(glm::vec3 data);
    unsigned int getVBO(){return vbo;};
    private:
    unsigned int vbo;
};