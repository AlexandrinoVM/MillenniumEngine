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
        0.5f,  0.5f, 0.0f, 1.0f, 0.0f, 0.0f,  
        0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,  
        -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f,   
        -0.5f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f   
    };

    unsigned int indices[] = {  
    0, 1, 3,   
    1, 2, 3    
    }; 
    
    Core core;
    core.init("janela",800,600);
   
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
        
        s.setFloat("oFsset",0.5);

        vao.bindVAO();
        glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_INT,0);
        core.run();
    }
    vao.unbidVAO();
    core.close();
    return 0;
}
