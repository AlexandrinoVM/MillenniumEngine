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
#include <glm/gtc/matrix_inverse.hpp> 
#include <headers/model.hpp>
#include <headers/terrarian.hpp>

int main() {
    float vertices[] = {
    // Frente (+Z)
     0.5f,  0.5f,  0.5f,   0, 0, 1,
     0.5f, -0.5f,  0.5f,   0, 0, 1,
    -0.5f, -0.5f,  0.5f,   0, 0, 1,

    -0.5f, -0.5f,  0.5f,   0, 0, 1,
    -0.5f,  0.5f,  0.5f,   0, 0, 1,
     0.5f,  0.5f,  0.5f,   0, 0, 1,

    // Trás (-Z)
     0.5f,  0.5f, -0.5f,   0, 0, -1,
    -0.5f,  0.5f, -0.5f,   0, 0, -1,
    -0.5f, -0.5f, -0.5f,   0, 0, -1,

    -0.5f, -0.5f, -0.5f,   0, 0, -1,
     0.5f, -0.5f, -0.5f,   0, 0, -1,
     0.5f,  0.5f, -0.5f,   0, 0, -1,

    // Direita (+X)
     0.5f,  0.5f,  0.5f,   1, 0, 0,
     0.5f,  0.5f, -0.5f,   1, 0, 0,
     0.5f, -0.5f, -0.5f,   1, 0, 0,

     0.5f, -0.5f, -0.5f,   1, 0, 0,
     0.5f, -0.5f,  0.5f,   1, 0, 0,
     0.5f,  0.5f,  0.5f,   1, 0, 0,

    // Esquerda (-X)
    -0.5f,  0.5f,  0.5f,  -1, 0, 0,
    -0.5f, -0.5f,  0.5f,  -1, 0, 0,
    -0.5f, -0.5f, -0.5f,  -1, 0, 0,

    -0.5f, -0.5f, -0.5f,  -1, 0, 0,
    -0.5f,  0.5f, -0.5f,  -1, 0, 0,
    -0.5f,  0.5f,  0.5f,  -1, 0, 0,

    // Topo (+Y)
    -0.5f,  0.5f,  0.5f,   0, 1, 0,
    -0.5f,  0.5f, -0.5f,   0, 1, 0,
     0.5f,  0.5f, -0.5f,   0, 1, 0,

     0.5f,  0.5f, -0.5f,   0, 1, 0,
     0.5f,  0.5f,  0.5f,   0, 1, 0,
    -0.5f,  0.5f,  0.5f,   0, 1, 0,

    // Fundo (-Y)
    -0.5f, -0.5f,  0.5f,   0, -1, 0,
     0.5f, -0.5f,  0.5f,   0, -1, 0,
     0.5f, -0.5f, -0.5f,   0, -1, 0,

     0.5f, -0.5f, -0.5f,   0, -1, 0,
    -0.5f, -0.5f, -0.5f,   0, -1, 0,
    -0.5f, -0.5f,  0.5f,   0, -1, 0
};
   float floorVertices[] = {
    //   X     Y     Z      NX   NY   NZ     U     V
    -1.0f, 0.0f, -1.0f,   0.0f, 1.0f, 0.0f,  0.0f, 0.0f,  // V0
     1.0f, 0.0f, -1.0f,   0.0f, 1.0f, 0.0f,  1.0f, 0.0f,  // V1
     1.0f, 0.0f,  1.0f,   0.0f, 1.0f, 0.0f,  1.0f, 1.0f,  // V2
    -1.0f, 0.0f,  1.0f,   0.0f, 1.0f, 0.0f,  0.0f, 1.0f   // V3
    };
    unsigned int floorIndices[] = {
    0, 1, 2,   // triângulo 1
    0, 2, 3    // triângulo 2
    };

    float LightVertices[] = {
  
   
     0.5f,  0.5f,  0.5f,   // 0: frente topo dir
     0.5f, -0.5f,  0.5f,   // 1: frente baixo dir
    -0.5f, -0.5f,  0.5f,     // 2: frente baixo esq
    -0.5f,  0.5f,  0.5f,     // 3: frente topo esq

   
     0.5f,  0.5f, -0.5f,    // 4: trás topo dir
     0.5f, -0.5f, -0.5f,  // 5: trás baixo dir
    -0.5f, -0.5f, -0.5f,   // 6: trás baixo esq
    -0.5f,  0.5f, -0.5f   // 7: trás topo esq
};

unsigned int indices[] = {
    // Frente
    0, 1, 2,
    0, 2, 3,

    // Direita
    0, 4, 5,
    0, 5, 1,

    // Trás
    4, 7, 6,
    4, 6, 5,

    // Esquerda
    3, 2, 6,
    3, 6, 7,

    // Topo
    0, 3, 7,
    0, 7, 4,

    // Fundo
    1, 5, 6,
    1, 6, 2
};

    Core core;
    core.init("janela",800,600);

    Texture t;
    t.loadTexture("../assets/floor.jpg");
    unsigned int textura1 = t.generateTexture();
    t.loadTexture("../assets/linux-ico.jpg");
    unsigned int textura2 = t.generateTexture();

    // VAO vao;
    // VBO vbo1(floorVertices,sizeof(floorVertices));
    // vbo1.bindVBO();
    // vao.VAOatribs(0,3,8,0);
    // vao.VAOatribs(1,3,8,3);
    // vao.VAOatribs(2,2,8,6);
    // vbo1.unbidVBO();
    // //VBO vbocolor(colors,sizeof(colors));
    // //vao.VAOatribs(1,3,3,0);
    // //vbocolor.unbidVBO();
    // EBO ebo1(floorIndices,6);
    // vao.unbidVAO();

    
    glm::vec3 lightColor = glm::vec3(1.0f);

    core.loadShaders("model","../shaders/shader.vert","../shaders/shader2.frag");
    //Model mochila("../models/van/van/source/combi.glb");
   // Model mochila("../models/gun/mp7.glb");
    //Model mochila("../models/teste/m2.glb");
    Model mochila("../models/backpack/backpack.obj");
    glm::vec3 lightPos = {0.5f,1.0f,-10.f};
    core.useProgram("model");
    //core.shaderConfig().setVec3("model","lightPos",lightPos);
    core.shaderConfig().setFloat("model","light.ambient",0.1);
    core.shaderConfig().setVec3("model","light.ambient", {1.0f, 0.5f, 0.31f});
    core.shaderConfig().setVec3("model","light.diffuse", {1.0f, 0.0f, 0.0f});
    core.shaderConfig().setVec3("model","light.specular", {0.5f, 0.5f, 0.5f});
    core.shaderConfig().setFloat("model","light.shininess", 0.1f);
    core.shaderConfig().stop();


    core.loadShaders("terrarian","../shaders/terrarian.vert","../shaders/terrarian.frag");
    Terrarian terrarian;




    shader teste;

    // core.loadShaders("teste","../shaders/shader.vert","../shaders/shader.frag");
    // core.useProgram("teste");
    // core.shaderConfig().setVec3("teste","objectColor",{1.0f, 0.5f, 0.31f});
    // core.shaderConfig().setVec3("teste","lightColor",lightColor);
    // //glm::vec3 lightPos = {1.2f,1.0f,-8.0f};
    // glm::vec3 lightPos = {0.5f,1.0f,-10.f};
    // core.shaderConfig().setVec3("teste","lightPos",lightPos);
    // core.shaderConfig().setFloat("teste","ambientLight",0.1);
    // core.shaderConfig().setVec3("teste","material.ambient", {1.0f, 0.5f, 0.31f});
    // core.shaderConfig().setVec3("teste","material.diffuse", {1.0f, 0.5f, 0.31f});
    // core.shaderConfig().setVec3("teste","material.specular", {0.5f, 0.5f, 0.5f});
    // core.shaderConfig().setFloat("teste","material.shininess", 32.0f);
    // core.shaderConfig().stop();
    
    // VAO vao2;
    // VBO vbo2(LightVertices,sizeof(LightVertices));
    // vbo2.bindVBO();
    // vao2.VAOatribs(0,3,3,0);
    // vbo2.unbidVBO();
    // EBO ebo2(indices,36);
    // vao2.unbidVAO();
    
    // core.loadShaders("lightCube","../shaders/light.vert","../shaders/light.frag");
    // core.useProgram("lightCube");
    // core.shaderConfig().setVec3("lightCube","lightColor",lightColor);
    // core.shaderConfig().stop();
    float lastFrame = 0.0f;
    float angle = 0.0f;
    int count =0; 
    while(core.isrunning()){
        
        core.clear();
    //     float currentTime = glfwGetTime();
    //     float deltaTime = currentTime - lastFrame;
    //     lastFrame = currentTime;
    //     angle += 0.05f;
        
    //     //first cube
    //     core.useProgram("teste");
    //     vao.bindVAO();
    //     t.activeText(GL_TEXTURE0);
    //     t.bindTexture(textura1);

            core.useProgram("terrarian");

            glm::mat4 projection = glm::perspective(glm::radians(45.0f),800.0f/600.0f,0.01f,1000.0f);
            glm::mat4 view = core.CameraConfigs().getCamera();
            glm::mat4 model2 = glm::mat4(1.0f);

            model2 = glm::translate(model2, glm::vec3(0.0f,-5.0f,20.0f));
            //model2 = glm::rotate(model2, glm::radians(10.f),core.RendererConfigs().getPositions());
            core.shaderConfig().setMat4("terrarian","model", model2);
            core.shaderConfig().setMat4("terrarian","projection",projection);
            core.shaderConfig().setMat4("terrarian","view",view);
    
            terrarian.draw(teste);


            core.shaderConfig().stop();




            core.useProgram("model");
            
            //glm::mat4 projection = glm::perspective(glm::radians(45.0f),800.0f/600.0f,0.1f,100.0f);
            //glm::mat4 view = core.CameraConfigs().getCamera();
            glm::mat4 model = glm::mat4(1.0f);
            model = glm::translate(model, glm::vec3(0.5f,-1.0f,-10.f));
            model = glm::rotate(model, glm::radians(10.f),core.RendererConfigs().getPositions());
            core.shaderConfig().setMat4("model","model", model);
            core.shaderConfig().setMat4("model","projection",projection);
            core.shaderConfig().setMat4("model","view",view);
            core.shaderConfig().setFloat("model", "light.shininess", 20.0f);
            glm::vec3 camView = glm::vec3(glm::inverse(view)[3]);
            core.shaderConfig().setVec3("model","camPos",camView);
            mochila.DrawModel(teste,"model");
       
            core.shaderConfig().stop();
        
    //     glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_INT,0);
    //     core.shaderConfig().stop();
    //     vao.unbidVAO();

    //     //segundo cubo
    //     core.useProgram("lightCube");
    //     vao2.bindVAO();

    //     glm::mat4 model2 = glm::mat4(1.0f);
    //     model2 = glm::translate(model2, glm::vec3(0.5f,1.0f,-10.f));
    //     model2 = glm::scale(model2, glm::vec3(0.5f));
    //    // model2 = glm::rotate(model2, glm::radians(1.0f), glm::vec3(1.0f, 0.3f, 0.5f));

        // core.shaderConfig().setMat4("lightCube","model", model2);
        // core.shaderConfig().setMat4("lightCube","projection", projection);
        // core.shaderConfig().setMat4("lightCube","view", view);
       
        // glDrawElements(GL_TRIANGLES,36,GL_UNSIGNED_INT,0);
        // core.shaderConfig().stop();
        // vbo2.unbidVBO();
       
        core.run();
           
        
        
    }
    //vao.unbidVAO();
    core.close();
    return 0;
}
