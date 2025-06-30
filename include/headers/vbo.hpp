#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <utils/meshiUtils.hpp>
#include <vector>
// struct SendAta{
//    std::vector<glm::vec3> pos;
//    std::vector<glm::vec3> normal;
//    std::vector<glm::vec2> uc;

// };


class VBO{
    public:
    VBO();
    VBO(float *data,size_t size);
    void setData(std::vector<Vertex> indices);
    void setData(std::vector<glm::vec3> indices);
    void setData(std::vector<glm::vec2> data);
    void setData(SendData data);
    void setData(std::vector<SendData> data);
    void setData(std::vector<glm::mat4> data);
    
    void bindVBO();
    void bindVBO(unsigned int VBO);
    void unbidVBO();
    void destroyVBO();
    void setData(std::vector<float>data);
    unsigned int getVBO(){return vbo;};
    private:
    unsigned int vbo,vertices,normals,texture;
};