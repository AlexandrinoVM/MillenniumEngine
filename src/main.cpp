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

#include <headers/model.hpp>
#include <headers/terrarian.hpp>

#include <headers/objModel.hpp>

#include <headers/gui.hpp>


#include <headers/cube.hpp>

int main() {
    

    Core core;
    core.init("janela",800,600);

    
    //glm::vec3 lightColor = glm::vec3(1.0f);
    
   
    //core.loadShaders("model","../shaders/shader.vert","../shaders/shader2.frag");
    //Model mochila("../models/van/van/source/combi.glb");
    // Model mochila("../models/gun/mp7.glb");
    //Model mochila("../models/teste/m2.glb");
    //Model mochila("../models/backpack/backpack.obj");
    //glm::vec3 lightPos = {0.5f,1.0f,-10.f};
    //core.useProgram("model");
  
    core.loadShaders("terrarian","../shaders/terrarian.vert","../shaders/terrarian.frag");
    Terrarian terrarian;

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

    float scale = 1.f;
    float rotation = 45.f;
    glm::vec3 rotatexy = glm::vec3(1.f);

    GUI janela("#version 330", core.getWindow());
    
    Cube cube;
    core.loadShaders("teste","../shaders/cube/cube.vert","../shaders/cube/cube.frag");
    core.loadShaders("newObjtModel","../shaders/cube/cube.vert","../shaders/cube/cube.frag");
    ObjModel obj;
   
    obj.atrrib("../models/monkey/suzanne.obj");
    obj.setup();
    //obj.print();
    bool wiredActivate = false;
    bool drawCubes = false;
    while(core.isrunning()){
        core.clear();
            janela.newFrame();
            core.useProgram("terrarian");
            terrarian.draw(core.shaderConfig(),core.CameraConfigs().getCamera());
            core.shaderConfig().stop();

            core.useProgram("newObjtModel");
            obj.draw(core.shaderConfig(),"newObjtModel",core.CameraConfigs().getCamera());
            
            core.shaderConfig().stop();
            
            janela.showDemo();
            janela.inteface();
           
            janela.CheckBox("wiredMode",wiredActivate,[&](bool newvalue){core.RendererConfigs().wiredMode(newvalue);});
            janela.headersWithSliders("Rotate Object","Rotate to",obj.getRotateposition());
            janela.headersWithSliders("Move Object","Move to",obj.getPosition());
            janela.headersWithSliders("Move the Light Source","Move light to",obj.getLightPos());
        
            core.shaderConfig().stop();
            janela.close();
       
        core.run();
        core.fpsCounter();
           
    }
    cube.clearCubes();
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    //vao.unbidVAO();
    core.close();
    return 0;
}
