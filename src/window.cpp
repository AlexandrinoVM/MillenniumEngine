#include "../include/headers/window.hpp"


void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

void window::init(const char*text,int w,int h){
    if(!glfwInit()){
        std::cerr <<"faild to initialize GLFW\n";
        exit(EXIT_FAILURE);
    }
    widht = w;
    height = h;
    winName = text;
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(w,h,text,nullptr,nullptr);

    if(!window){
        std::cerr << "Failed to create GLFW window\n";
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD\n";
        exit(EXIT_FAILURE);
    }
    //function to adjust viewport on hyprland because the manegement window system can adjust de window making the objets out of center
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    //glfwSwapInterval(0);
};

void window::close(){
    glfwDestroyWindow(window);
}









