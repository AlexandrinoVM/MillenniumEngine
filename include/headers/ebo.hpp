#pragma once 
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <utils/meshiUtils.hpp>
#include <vector>

 class EBO{
    public:
    EBO();
    EBO(unsigned  *indices,int count);
    void setData(std::vector<unsigned int>indices);
    void bindEBO();
    void bindEBO(unsigned int ebo);
    void unbidEBO();
    void destroyEBO();
    unsigned int getEBO(){return ebo;};
    void EBOatribs(int location,int quantPos,int stride,int offset);
    private:
    unsigned int ebo;
};