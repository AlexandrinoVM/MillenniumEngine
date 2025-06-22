#pragma once 
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <utils/meshiUtils.hpp>
#include <vector>

 class EBO{
    public:
    EBO();
    EBO(unsigned  *indices,int count);
    void setData(std::vector<unsigned int>indices);
    void setData(std::vector<glm::vec3>indices);
    void bindEBO();
    void bindEBO(unsigned int ebo);
    void unbidEBO();
    void destroyEBO();
    unsigned int getEBO(){return ebo;};
    void EBOatribs(int location,int quantPos,int stride,int offset);
    private:
    unsigned int ebo;
};