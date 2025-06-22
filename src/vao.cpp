#include "../include/headers/vao.hpp"


VAO::VAO(){
    glGenVertexArrays(1,&vao);

    glBindVertexArray(vao);
}

void VAO::bindVAO(){
    glBindVertexArray(vao);
}

void VAO::bindVAO(unsigned int vao){
    glBindVertexArray(vao);
}


void VAO::unbidVAO(){
    glBindVertexArray(0);
}

void VAO::VAOatribs(int location,int quantPos,int stride,int offset){
    if(quantPos == 2){
        glVertexAttribPointer(location, quantPos, GL_FLOAT, GL_FALSE, stride, (void*)offsetof(Vertex,Textcoords));
        glEnableVertexAttribArray(location);
    }else{
        glVertexAttribPointer(location, quantPos, GL_FLOAT, GL_FALSE, stride, (void*)(offset * sizeof(float)));
        glEnableVertexAttribArray(location); 
    }
}

void VAO::VAOatribs(int location,int quantPos,int stride,int offset,int type){
    if(type != 0){
         glVertexAttribPointer(location, quantPos, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), (void*)(offset * sizeof(float)));
        glEnableVertexAttribArray(location); 
    }
}