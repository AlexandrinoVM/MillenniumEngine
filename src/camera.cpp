#include <headers/camera.hpp>



Camera::Camera(){
    cameraPos =glm::vec3(0.f);
    cameraTarget =glm::vec3(0.f,0.f,-1.f);
    cameraup =glm::vec3(0.f,0.1,0.f);
    cameraLeft = glm::vec3(-1.f,0.f,0.f);

    view= glm::lookAt(cameraPos,cameraPos + cameraTarget,cameraup);
    //glUniformMatrix4fv(glGetUniformLocation(id,"view"),1,GL_FALSE,glm::value_ptr(view));
}

void Camera::moveFoward(){
    cameraPos = cameraPos + cameraTarget * speed;
    view= glm::lookAt(cameraPos,cameraPos + cameraTarget,cameraup);
}

void Camera::moveBackward(){
    cameraPos = cameraPos + cameraTarget * (-speed);
    view= glm::lookAt(cameraPos,cameraPos + cameraTarget,cameraup);
}

void Camera::moveLeft(){
    cameraPos = cameraPos + cameraLeft * speed; 
    view= glm::lookAt(cameraPos,cameraPos + cameraTarget,cameraup);
}

void Camera::moveRigth(){
    cameraPos = cameraPos + cameraLeft * (-speed);
    view= glm::lookAt(cameraPos,cameraPos + cameraTarget,cameraup);
}