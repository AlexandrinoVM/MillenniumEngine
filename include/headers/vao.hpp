#pragma once 
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
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
    void VAOatribs(int location,int quantPos,int stride,int offset,int type);
    private:
    unsigned int vao;
};
