#include "../include/headers/ebo.hpp"

EBO::EBO(){
    glGenBuffers(1,&ebo);
}

EBO::EBO(unsigned int *indices,int count){
    glGenBuffers(1,&ebo);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,ebo);

    glBufferData(GL_ELEMENT_ARRAY_BUFFER, count *sizeof(indices),indices,GL_STATIC_DRAW);

}

void EBO::setData(std::vector<unsigned int>indices){

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,ebo);

    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int),indices.data(),GL_STATIC_DRAW);

}

void EBO::setData(std::vector<glm::vec3>indices){

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,ebo);

    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(glm::vec3),indices.data(),GL_STATIC_DRAW);

}



void EBO::bindEBO(){
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,ebo);
}


void EBO::unbidEBO(){
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
}

void EBO::EBOatribs(int location,int quantPos,int stride,int offset){
    glVertexAttribPointer(location, quantPos, GL_FLOAT, GL_FALSE, stride * sizeof(float), (void*)(offset * sizeof(float)));
    glEnableVertexAttribArray(location); 
}