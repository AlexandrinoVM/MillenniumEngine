#include "../include/headers/vbo.hpp"


VBO::VBO(){
    glGenBuffers(1,&vbo);
}

VBO::VBO(float *data,size_t size){
    glGenBuffers(1,&vbo);

    glBindBuffer(GL_ARRAY_BUFFER,vbo);

    glBufferData(GL_ARRAY_BUFFER,size,data,GL_STATIC_DRAW);
}

void VBO::setData(std::vector<Vertex> indices){
    glGenBuffers(1,&vbo);

    glBindBuffer(GL_ARRAY_BUFFER,vbo);

    glBufferData(GL_ARRAY_BUFFER,indices.size() * sizeof(Vertex),&indices[0],GL_STATIC_DRAW);
}


void VBO::bindVBO(){
    glBindBuffer(GL_ARRAY_BUFFER,vbo);
}
void VBO::bindVBO(unsigned int vbo){
    glBindBuffer(GL_ARRAY_BUFFER,vbo);
}

void VBO::unbidVBO(){
    glBindBuffer(GL_ARRAY_BUFFER,0);
}

void VBO::setData(glm::vec3 *data,size_t size){
    glGenBuffers(1,&vbo);

    glBindBuffer(GL_ARRAY_BUFFER,vbo);

    glBufferData(GL_ARRAY_BUFFER,size,data,GL_STATIC_DRAW);
}