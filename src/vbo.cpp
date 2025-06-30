#include "../include/headers/vbo.hpp"


VBO::VBO(){
    glGenBuffers(1,&vbo);
    glGenBuffers(1,&normals);
    glGenBuffers(1,&vertices);
    glGenBuffers(1,&texture);
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
void VBO::setData(std::vector<glm::mat4> data){
    glGenBuffers(1,&vbo);

    glBindBuffer(GL_ARRAY_BUFFER,vbo);

    glBufferData(GL_ARRAY_BUFFER,data.size() * sizeof(glm::mat4),data.data(),GL_STATIC_DRAW);
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

void VBO::setData(std::vector<float> data){

    glBindBuffer(GL_ARRAY_BUFFER,vbo);

    glBufferData(GL_ARRAY_BUFFER,data.size() *sizeof(float),data.data(),GL_STATIC_DRAW);
}

// void VBO::setData(SendAta data){

//     glBindBuffer(GL_ARRAY_BUFFER,vbo);

//     glBufferData(GL_ARRAY_BUFFER,data *sizeof(SendAta),data,GL_STATIC_DRAW);
// }

void VBO::setData(std::vector<glm::vec3> data){

    glBindBuffer(GL_ARRAY_BUFFER,vbo);

    glBufferData(GL_ARRAY_BUFFER,data.size() *sizeof(glm::vec3),&data[0],GL_STATIC_DRAW);
}

// void VBO::setData(SendData data){

//     bindVBO(vertices);
//     glBufferData(GL_ARRAY_BUFFER,data.vertices.size() * sizeof(glm::vec3),data.vertices.data(),GL_STATIC_DRAW);
//     bindVBO(normals);
//     glBufferData(GL_ARRAY_BUFFER,data.Normals.size() * sizeof(glm::vec3),data.Normals.data(),GL_STATIC_DRAW);
//     bindVBO(texture);
//     glBufferData(GL_ARRAY_BUFFER,data.texts.size() * sizeof(glm::vec2),data.texts.data(),GL_STATIC_DRAW);
    
// }

void VBO::setData(std::vector<SendData> data){

    bindVBO(vbo);
    glBufferData(GL_ARRAY_BUFFER,data.size() * sizeof(SendData),data.data(),GL_STATIC_DRAW);
    
}



void VBO::setData(std::vector<glm::vec2> data){

    glBindBuffer(GL_ARRAY_BUFFER,vbo);

    glBufferData(GL_ARRAY_BUFFER,data.size() *sizeof(glm::vec2),data.data(),GL_STATIC_DRAW);
}