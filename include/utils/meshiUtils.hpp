#pragma once

#include <glm/glm.hpp>
#include <string>

struct Vertex{
    glm::vec3 Position;
    glm::vec3 Normal;
    glm::vec2 Textcoords;
};

struct Texture{
    unsigned int id;
    std::string type;
};