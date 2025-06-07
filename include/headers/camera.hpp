#pragma once 
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Camera{
    public:
    Camera();
    glm::mat4 getCamera(){return view;};
    void moveFoward();
    void moveBackward();
    void moveLeft();
    void moveRigth();
    private:
    glm::vec3 cameraPos;
    glm::vec3 cameraTarget;
    glm::vec3 cameraup;  
    glm::vec3 cameraLeft;  
    glm::mat4 view;
    float speed = 0.5f;
};