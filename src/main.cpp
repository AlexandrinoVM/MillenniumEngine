#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "../include/headers/core.hpp"
#include "../include/headers/shaders.hpp"
#include "../include/headers/vbo.hpp"
#include "../include/headers/vao.hpp"
#include "../include/headers/ebo.hpp"
#include <headers/texture.hpp>

int main() {
    float vertices[] = {
        0.5f, 0.5f, 0.0f,   1.0f, 0.0f, 0.0f,  1.0f,1.0f,  //topo direita
        0.5f,-0.5f, 0.0f,   0.0f, 1.0f, 0.0f,  1.0f,0.0f,  //baixo direita
        -0.5f,-0.5f, 0.0f,  0.0f, 0.0f, 1.0f,  0.0f,0.0f,  //baixo esqueda
        -0.5f, 0.5f, 0.0f,  0.0f, 0.0f,1.0f,   0.0f,1.0f  //topo esquerda
    };

    unsigned int indices[] = {  
    0, 1, 3,   
    1, 2, 3    
    }; 
    
    Core core;
    core.init("janela",800,600);
   
    Texture t;
    t.loadTexture("../assets/container.jpg");
    unsigned int textura1 = t.generateTexture();
    t.loadTexture("../assets/linux-ico.jpg");
    unsigned int textura2 = t.generateTexture();

    VAO vao;
    VBO vbo1(vertices,sizeof(vertices));
    vbo1.bindVBO();
    vao.VAOatribs(0,3,8,0);
    vao.VAOatribs(1,3,8,3);
    vao.VAOatribs(2,2,8,6);
    EBO ebo1(indices,6);

    shader s("../shaders/shader.vert","../shaders/shader.frag");
    s.useProgram();
    s.setint("texture1",0);
    s.setint("texture2",1);
    while(core.isrunning()){
        
        core.clear();
        
        s.setFloat("oFsset",0.5);
        glActiveTexture(GL_TEXTURE0);
        t.bindTexture(textura1);
        glActiveTexture(GL_TEXTURE1);
       
        t.bindTexture(textura2);
        
        vao.bindVAO();
        glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_INT,0);
        core.run();
    }
    vao.unbidVAO();
    core.close();
    return 0;
}
