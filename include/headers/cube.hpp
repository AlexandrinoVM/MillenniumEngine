#pragma once
#include "vbo.hpp"
#include "ebo.hpp"
#include "vao.hpp"
#include <iostream>
#include <map>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "shaders.hpp"
#include <string>

class Cube{
    public:
    std::vector<glm::vec3> cubePositions;
    Cube(){setupBuffers(); cubePositions.push_back(glm::vec3(-0.5f, 0.0f, -15.0f));};
    void createCubes(char x);
    int getSize(){return cubCount;};
    void draw(shader& shader,const std::string &nameshader,glm::mat4 view);
    void clearCubes(){cubePositions.clear();};
    void setupBuffers();
    private:
    void setupPositions();
    unsigned int cubCount;

    VAO vao;
    VBO vbo;
    EBO ebo;
    unsigned int VBo;

    std::vector<float> cubeVertices = {
    // Frente
    -0.5f, -0.5f,  0.5f,  // inferior esquerdo
     0.5f, -0.5f,  0.5f,  // inferior direito
     0.5f,  0.5f,  0.5f,  // superior direito
    -0.5f,  0.5f,  0.5f,  // superior esquerdo

    // Trás
    -0.5f, -0.5f, -0.5f,  // inferior esquerdo
     0.5f, -0.5f, -0.5f,  // inferior direito
     0.5f,  0.5f, -0.5f,  // superior direito
    -0.5f,  0.5f, -0.5f,  // superior esquerdo
    };
    std::vector<unsigned int> cubeIndices = {
    // Frente
    0, 1, 2,
    2, 3, 0,
    // Direita
    1, 5, 6,
    6, 2, 1,
    // Trás
    7, 6, 5,
    5, 4, 7,
    // Esquerda
    4, 0, 3,
    3, 7, 4,
    // Topo
    3, 2, 6,
    6, 7, 3,
    // Base
    4, 5, 1,
    1, 0, 4
};
};