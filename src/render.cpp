#include "../include/headers/render.hpp"

void mouseCalback(GLFWwindow *window, double xpos, double ypos);

float lastX = 400, lastY = 300; // centro da tela (ajuste se necessário)
float yaw = -90.0f;             // rotação em Y
float pitch = 0.0f;             // rotação em X
bool firstMouse = true;

Camera *camera;
GLFWwindow *window;


void Renderer::events(){
    processInput();
}

void Renderer::init(GLFWwindow *win,Camera *cam){
    window = win;
    camera = cam;
    running = true;
    glClearColor(0,0,0,0);
}


void mouseCalback(GLFWwindow *window, double xpos, double ypos){
    
    if(firstMouse){
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = xpos -  lastX;
    float yoffset = ypos -  lastY;

    lastX = xpos;
    lastY = ypos;

    yaw += xoffset;
    pitch += yoffset;


    if (pitch > 89.0f) pitch = 89.0f;
    if (pitch < -89.0f) pitch = -89.0f;

    glm::vec3 direction;
    direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    direction.y = sin(glm::radians(-pitch));
    direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    std::cout << "x: " << direction.x << " y:" << direction.y <<" z:" << direction.z << std::endl;
    glm::vec3 newview = glm::normalize(direction);
    camera->setdirection(newview);
}

void Renderer::processInput(){
    if(glfwGetKey(window,GLFW_KEY_ESCAPE) == GLFW_PRESS){
        running = false;
    }
    if(glfwGetKey(window,GLFW_KEY_F8) == GLFW_PRESS){
        if(!count){
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
            std::cout << count << std::endl;
            count = 1;
        }else{
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
            std::cout << count << std::endl;
            count = 0;
        }
    } 
    //WSDA keys actioin
    if(glfwGetKey(window,GLFW_KEY_W) == GLFW_PRESS){
        camera->moveFoward();
    }
     if(glfwGetKey(window,GLFW_KEY_S) == GLFW_PRESS){
        camera->moveBackward();
    }
     if(glfwGetKey(window,GLFW_KEY_A) == GLFW_PRESS){
        camera->moveLeft();
    }
     if(glfwGetKey(window,GLFW_KEY_D) == GLFW_PRESS){
        camera->moveRigth();
    }

    //mouse inputs
    if(glfwGetMouseButton(window,GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS){
        mouseOnscreen = true;
        glfwSetInputMode(window,GLFW_CURSOR,GLFW_CURSOR_HIDDEN);
        if(mouseOnscreen){
            glfwSetCursorPosCallback(window,mouseCalback);
        }
        
    }else if(mouseOnscreen){
        if(glfwGetMouseButton(window,GLFW_MOUSE_BUTTON_LEFT) == GLFW_RELEASE){
            glfwSetInputMode(window,GLFW_CURSOR,GLFW_CURSOR_NORMAL);
            
            mouseOnscreen = false;
        }
    }


}



void Renderer::clear(){
    glEnable(GL_DEPTH_TEST);
    glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
}

void Renderer::RenderWindow(){
    glfwPollEvents();
    glfwSwapBuffers(window);
}

