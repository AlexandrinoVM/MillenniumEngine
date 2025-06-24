#pragma once
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <headers/shaders.hpp>
#include <headers/vao.hpp>
#include <headers/ebo.hpp>
#include <headers/vbo.hpp>

class Terrarian{
    public:
    std::vector<float> vertices; 
    std::vector<unsigned int> indices; 
    glm::vec3 color = glm::vec3(1.f);
    Terrarian(){setupTerrarian(); initBuffers();};
    void draw(shader &shader,glm::mat4 vi);
    private:
    void initBuffers();
    void setupTerrarian();
    unsigned int vbo;
    unsigned int vao;
    unsigned int ebo;
    VAO Vao;
    VBO Vbo;
    EBO Ebo;
};