#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <utils/meshiUtils.hpp>
#include <vector>

class VBO{
    public:
    VBO();
    VBO(float *data,size_t size);
    void setData(std::vector<Vertex> indices);
    void bindVBO();
    void bindVBO(unsigned int VBO);
    void unbidVBO();
    void destroyVBO();
    void setData(glm::vec3 *data,size_t size);
    unsigned int getVBO(){return vbo;};
    private:
    unsigned int vbo;
};