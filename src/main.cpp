#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "../include/headers/core.hpp"
#include "../include/headers/shaders.hpp"
#include "../include/headers/vbo.hpp"
#include "../include/headers/vao.hpp"
#include "../include/headers/ebo.hpp"
#include <headers/texture.hpp>
#include <headers/tranfomation.hpp>

int main() {
    float vertices[] = {
    // Posição           // Cor           // UV
    // Frente
     0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 0.0f,  1.0f, 1.0f, // 0: frente topo dir
     0.5f, -0.5f,  0.5f,  0.0f, 1.0f, 0.0f,  1.0f, 0.0f, // 1: frente baixo dir
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 1.0f,  0.0f, 0.0f, // 2: frente baixo esq
    -0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 0.0f,  0.0f, 1.0f, // 3: frente topo esq

    // Trás
     0.5f,  0.5f, -0.5f,  1.0f, 0.0f, 1.0f,  1.0f, 1.0f, // 4: trás topo dir
     0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 1.0f,  1.0f, 0.0f, // 5: trás baixo dir
    -0.5f, -0.5f, -0.5f,  1.0f, 1.0f, 1.0f,  0.0f, 0.0f, // 6: trás baixo esq
    -0.5f,  0.5f, -0.5f,  0.0f, 0.0f, 0.0f,  0.0f, 1.0f  // 7: trás topo esq
};

    float colors[] = {
        
    }


unsigned int indices[] = {
    // Frente
    0, 1, 3,
    1, 2, 3,

    // Direita
    0, 1, 4,
    1, 5, 4,

    // Trás
    4, 5, 7,
    5, 6, 7,

    // Esquerda
    3, 2, 7,
    2, 6, 7,

    // Topo
    0, 3, 4,
    3, 7, 4,

    // Fundo
    1, 2, 5,
    2, 6, 5
};


glm::vec3 cubePositions[] = {
    glm::vec3( 0.0f,  0.0f,  0.0f), 
    glm::vec3( 2.0f,  5.0f, -15.0f), 
    glm::vec3(-1.5f, -2.2f, -2.5f),  
    glm::vec3(-3.8f, -2.0f, -12.3f),  
    glm::vec3( 2.4f, -0.4f, -3.5f),  
    glm::vec3(-1.7f,  3.0f, -7.5f),  
    glm::vec3( 1.3f, -2.0f, -2.5f),  
    glm::vec3( 1.5f,  2.0f, -2.5f), 
    glm::vec3( 1.5f,  0.2f, -1.5f), 
    glm::vec3(-1.3f,  1.0f, -1.5f)  
};

    Core core;
    core.init("janela",800,600);
   
    Tranformations trans;


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
    EBO ebo1(indices,36);
   
    shader s("../shaders/shader.vert","../shaders/shader.frag");
    s.useProgram();
    s.setint("texture1",0);
    s.setint("texture2",1);
    
    
    
    int modell = glGetUniformLocation(s.getID(),"model");
    int projectionl = glGetUniformLocation(s.getID(),"projection");
    int viewl = glGetUniformLocation(s.getID(),"view");
    
    
    float lastFrame = 0.0f;
    float angle = 0.0f;
    while(core.isrunning()){
        for(int i;i < 0;i++){
            
        }
        float currentTime = glfwGetTime();
        float deltaTime = currentTime - lastFrame;
        lastFrame = currentTime;
        angle += 45.0f * deltaTime;
        glm::mat4 model = glm::mat4(1.0f);
        float dt = glfwGetTime();
        model = glm::rotate(model,glm::radians(angle),glm::vec3(0.5f,0.1f,0.5f));
        
        glm::mat4 view = glm::mat4(1.0f);
        view = glm::translate(view,glm::vec3(0.0f,0.0f,-5.0f));
        
        glm::mat4 projection = glm::perspective(glm::radians(45.0f),800.0f/600.0f,0.1f,100.0f);
        
        core.clear();
        
        s.setFloat("oFsset",dt);
        t.activeText(GL_TEXTURE0);
        t.bindTexture(textura1);
        t.activeText(GL_TEXTURE1);
        t.bindTexture(textura2);
        glUniformMatrix4fv(modell,1,GL_FALSE,glm::value_ptr(model));
        glUniformMatrix4fv(viewl,1,GL_FALSE,glm::value_ptr(view));
        glUniformMatrix4fv(projectionl,1,GL_FALSE,glm::value_ptr(projection));
        
        vao.bindVAO();
        glDrawElements(GL_TRIANGLES,36,GL_UNSIGNED_INT,0);
        core.run();
    }
    vao.unbidVAO();
    core.close();
    return 0;
}
