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
    void setYaw(int nval){yaw = nval;};
    void setPitch(int npitch){pitch = npitch;};
    void setdirection(glm::vec3 &Direction);
    bool firstclick(){return firstclicks;};
    void setClick(){firstclicks = !firstclicks;};
    void scrollMouse(double ypos);
    private:
    glm::vec3 cameraPos;
    glm::vec3 cameraTarget;
    glm::vec3 cameraup;  
    glm::vec3 cameraLeft;  
    glm::mat4 view;
    bool firstclicks = true;
    float pitch = 0.f;
    float yaw = -90.f;
    float speed = 1.0f;
};