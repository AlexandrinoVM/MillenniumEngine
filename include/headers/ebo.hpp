#pragma once 
#include <glad/glad.h>
#include <GLFW/glfw3.h>
 
 class EBO{
    public:
    EBO(unsigned  *indices,int count);
    void bindEBO();
    void unbidEBO();
    void destroyEBO();
    unsigned int getEBO(){return ebo;};
    void EBOatribs(int location,int quantPos,int stride,int offset);
    private:
    unsigned int ebo;
};