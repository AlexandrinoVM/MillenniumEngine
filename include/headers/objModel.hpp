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


struct Vec3Compare {
    bool operator()(const glm::vec3& a, const glm::vec3& b) const {
        if (a.x != b.x) return a.x < b.x;
        if (a.y != b.y) return a.y < b.y;
        return a.z < b.z;
    }
};

class ObjModel{
    private:
    VAO vao;
    EBO ebo;
    VBO vbo;
    public:
    glm::vec3 rotatePos = glm::vec3(1.f);
    std::vector<glm::vec3> vertices;
    std::vector<unsigned int>indices;
    std::vector<glm::vec3>finalindex;
    std::vector<glm::vec3> finalVertices;
    std::vector<glm::vec3> uniqueVertices;
    std::vector<glm::vec2> textures;
    std::vector<glm::vec3> Normals;
    void print();
    void atrrib(const char*filename,const char* mode="r");
    void setup();
    void draw(shader& shader,const std::string&nama,glm::mat4 view);
    glm::vec3 &getRotateposition(){return rotatePos;};
    glm::vec3 &getPosition(){return position;};
    glm::vec3 &getLightPos(){return lightPos;};
    
    private:
    glm::vec3 position = {-0.5f,0.0f,-13.f};
    glm::vec3 lightPos =glm::vec3(-2.5f,1.0f,3.f);
}; 