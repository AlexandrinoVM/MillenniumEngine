#pragma once

#include <glm/glm.hpp>
#include <string>

struct Vertex{
    glm::vec3 Position;
    glm::vec3 Normal;
    glm::vec2 Textcoords;
    glm::vec3 tangent;
    glm::vec3 bitangent;
};

struct texture{
    unsigned int id;
    std::string type;
    std::string path;
};