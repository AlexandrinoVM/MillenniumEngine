#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>

class Tranformations{
    public:
    Tranformations();

    private:
    glm::mat4 trans;
    glm::vec4 vec{1.0f, 0.0f, 0.0f, 1.0f};
    
};