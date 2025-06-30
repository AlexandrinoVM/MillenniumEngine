#pragma once 
#include <vector>
#include <iostream>
#include <string>
#include <cstdio>
#include "shaders.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "vbo.hpp"
#include "vao.hpp"
#include "ebo.hpp"
#include <map>
#include <cstdlib>
#include <fstream>
#include <filesystem>
#include <algorithm>
#include "texture.hpp"


#include "utils/meshiUtils.hpp"

class ObjModel{
    public:
    SendData atribs;
    void print();
    void atrrib(const char*filename,const char* mode="r");
    void setup();
    void draw(shader& shader,const std::string&nama,glm::mat4 view);
    glm::vec3 &getRotateposition(){return rotatePos;};
    glm::vec3 &getPosition(){return position;};
    glm::vec3 &getLightPos(){return lightPos;};
    glm::vec3 &getobjColor(){return objColor;};
    void setupInstancedObjes();

    std::vector<SendData> finalData;
    std::vector<unsigned int> idColor;
    void searchFiles(std::filesystem::path &path);

    private:
    int InstancedQtd = 10000;
    std::vector<glm::vec3> instaces;
    std::vector<glm::mat4> instancesMath;
    std::string objModelPath;
    std::string TextureDiffusePath;
    Texture text;
    VBO instanceObjsVbo;
    VAO vao;
    EBO ebo;
    VBO vbo;
    glm::vec3 rotatePos = glm::vec3(1.f);
    std::vector<glm::vec3> vertices;
    std::vector<unsigned int>indices;
    std::vector<glm::vec2> textures;
    std::vector<glm::vec3> Normals;

    glm::vec3 objColor = {0.38, 0.72, 0.72};
    glm::vec3 position = {-0.5f,0.0f,-13.f};
    glm::vec3 lightPos =glm::vec3(-2.5f,1.0f,3.f);
}; 