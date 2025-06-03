#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "../include/headers/core.hpp"
#include "../include/headers/shaders.hpp"
#include "../include/headers/vbo.hpp"
#include "../include/headers/vao.hpp"
#include "../include/headers/ebo.hpp"



int main() {
    float vertices[] = {
           0.5f,  0.5f, 0.0f, 1.0f, 0.0f, 0.0f,  // vértice 1: vermelho
           0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,  // vértice 2: verde
           -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f,   // vértice 3: azul
           -0.5f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f   // vértice 3: azul
    };

    unsigned int indices[] = {  // note that we start from 0!
    0, 1, 3,   // first triangle
    1, 2, 3    // second triangle
    }; 
    
    Core core;
    core.init("janela",800,500);
   
    VAO vao;
    
    VBO vbo1(vertices,sizeof(vertices));
    vbo1.bindVBO();
    vao.VAOatribs(0,3,6,0);
    vao.VAOatribs(1,3,6,3);
    EBO ebo1(indices,6);

    shader s("../shaders/shader.vert","../shaders/shader.frag");
    
    while(core.isrunning()){
        core.clear();
        s.useProgram();
        vao.bindVAO();
        glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_INT,0);
        core.run();
    }
    vao.unbidVAO();
    core.close();
    return 0;
}
