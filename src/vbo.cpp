#include "../include/headers/vbo.hpp"


VBO::VBO(float *data,size_t size){
    glGenBuffers(1,&vbo);

    glBindBuffer(GL_ARRAY_BUFFER,vbo);

    glBufferData(GL_ARRAY_BUFFER,size,data,GL_STATIC_DRAW);
}

void VBO::bindVBO(){
    glBindBuffer(GL_ARRAY_BUFFER,vbo);
}

void VBO::unbidVBO(){
    glBindBuffer(GL_ARRAY_BUFFER,0);
}