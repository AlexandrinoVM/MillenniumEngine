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
#include <headers/camera.hpp>


int main() {
    float vertices[] = {
    // Posição           // Cor           // UV
    // Frente
     0.5f,  0.5f,  0.5f,   // 0: frente topo dir
     0.5f, -0.5f,  0.5f,   // 1: frente baixo dir
    -0.5f, -0.5f,  0.5f,     // 2: frente baixo esq
    -0.5f,  0.5f,  0.5f,     // 3: frente topo esq

    // Trás
     0.5f,  0.5f, -0.5f,    // 4: trás topo dir
     0.5f, -0.5f, -0.5f,  // 5: trás baixo dir
    -0.5f, -0.5f, -0.5f,   // 6: trás baixo esq
    -0.5f,  0.5f, -0.5f   // 7: trás topo esq
};

    float colors[] = {
        1.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f, 
        0.0f, 0.0f, 1.0f,
        1.0f, 1.0f, 0.0f,
        1.0f, 0.0f, 1.0f,
        0.0f, 1.0f, 1.0f, 
        1.0f, 1.0f, 1.0f, 
        0.0f, 0.0f, 0.0f
    };


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

    Texture t;
    t.loadTexture("../assets/container.jpg");
    unsigned int textura1 = t.generateTexture();
    t.loadTexture("../assets/linux-ico.jpg");
    unsigned int textura2 = t.generateTexture();

    VAO vao;
    VBO vbo1(vertices,sizeof(vertices));
    vbo1.bindVBO();
    vao.VAOatribs(0,3,3,0);
    vbo1.unbidVBO();
    VBO vbocolor(colors,sizeof(colors));
    vao.VAOatribs(1,3,3,0);
    vbocolor.unbidVBO();
    EBO ebo1(indices,36);
    vao.unbidVAO();
    core.loadShaders("../shaders/shader.vert","../shaders/shader.frag");
    core.shaderConfig().stop();

    VAO vao2;
    VBO vbo2(vertices,sizeof(vertices));
    vbo2.bindVBO();
    vao2.VAOatribs(0,3,3,0);
    vbo2.unbidVBO();
    EBO ebo2(indices,36);

    shader ligth;
    ligth.Loadshader("../shaders/light.vert","../shaders/light.frag");
    vao2.unbidVAO();
    //Camera cam;
    //core.shaderConfig().setMat4("view",cam.getCamera());
    float lastFrame = 0.0f;
    float angle = 0.0f;
    int count =0; 
    while(core.isrunning()){
        
        core.clear();
        float currentTime = glfwGetTime();
        float deltaTime = currentTime - lastFrame;
        lastFrame = currentTime;
        angle += 0.05f;
        
        //first cube
        core.useProgram();
        vao.bindVAO();
        
        glm::mat4 projection = glm::perspective(glm::radians(45.0f),800.0f/600.0f,0.1f,100.0f);
        glm::mat4 view = core.CameraConfigs().getCamera();
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, cubePositions[3]);
        model = glm::rotate(model, angle, glm::vec3(1.0f, 0.3f, 0.5f));
        core.shaderConfig().setMat4("model", model);
        core.shaderConfig().setMat4("projection",projection);
        core.shaderConfig().setMat4("view",view);
       
        
        glDrawElements(GL_TRIANGLES,36,GL_UNSIGNED_INT,0);
        core.shaderConfig().stop();
        vao.unbidVAO();

        //segundo cubo
        ligth.useProgram();
        vao2.bindVAO();

        glm::mat4 model2 = glm::mat4(1.0f);
        model2 = glm::translate(model2, cubePositions[4]);
        model2 = glm::rotate(model2, glm::radians(45.0f), glm::vec3(1.0f, 0.3f, 0.5f));

        ligth.setMat4("model", model2);
        ligth.setMat4("projection", projection);
        ligth.setMat4("view", view);

        glDrawElements(GL_TRIANGLES,36,GL_UNSIGNED_INT,0);
        ligth.stop();
        vbo2.unbidVBO();
        t.activeText(GL_TEXTURE0);
        t.bindTexture(textura1);
        t.activeText(GL_TEXTURE1);
        t.bindTexture(textura2);
        core.run();
           
        
        
    }
    vao.unbidVAO();
    core.close();
    return 0;
}
