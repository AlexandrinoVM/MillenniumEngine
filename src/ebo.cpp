#include "../include/headers/ebo.hpp"


EBO::EBO(unsigned int *indices,int count){
    glGenBuffers(1,&ebo);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,ebo);

    glBufferData(GL_ELEMENT_ARRAY_BUFFER, count *sizeof(indices),indices,GL_STATIC_DRAW);

}

void EBO::bindEBO(){
    glBindVertexArray(ebo);
}

void EBO::unbidEBO(){
    
}

void EBO::EBOatribs(int location,int quantPos,int stride,int offset){
    glVertexAttribPointer(location, quantPos, GL_FLOAT, GL_FALSE, stride * sizeof(float), (void*)(offset * sizeof(float)));
    glEnableVertexAttribArray(location); 
}