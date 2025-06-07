#include "../include/headers/render.hpp"


void Renderer::events(){
    processInput();
}

void Renderer::init(GLFWwindow *win,Camera *cam){
    window = win;
    camera = cam;
    running = true;
    glClearColor(0,0,0,0);
}

void Renderer::processInput(){
    if(glfwGetKey(window,GLFW_KEY_ESCAPE) == GLFW_PRESS){
        running = false;
    }
    if(glfwGetKey(window,GLFW_KEY_W) == GLFW_PRESS && glfwGetKey(window,GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS){
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
}

void Renderer::clear(){
    glEnable(GL_DEPTH_TEST);
    glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
}

void Renderer::RenderWindow(){
    glfwPollEvents();
    glfwSwapBuffers(window);
}

