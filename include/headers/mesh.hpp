#pragma once 
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <string>
#include <vector>
#include "shaders.hpp"
#include "vbo.hpp"
#include "ebo.hpp"
#include "vao.hpp"
#include <utils/meshiUtils.hpp>

class Mesh{
    public:
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;
    std::vector<texture> textures;

    Mesh(std::vector<Vertex> vertices,std::vector<unsigned int> indices,std::vector<texture> textures);
    void draw(shader &shader,std::string &shaderName);
    private:
    VAO vao;
    VBO vbo;
    EBO ebo;
    unsigned int Vao,Vbo,Ebo;
    void setupMeshi();
};