#include "../include/headers/shaders.hpp"

shader::shader(const std::string &vertfrag,const std::string &fragment){
    std::string vert = fileManager::loadSource(vertfrag);
    std::string frag = fileManager::loadSource(fragment);
    if (vert.empty() || frag.empty()) {
    std::cerr << "Shader source is empty!" << std::endl;
    return;
    }
    const char *test = vert.c_str();
    const char * f = frag.c_str();

    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader,1,&test,NULL);
    glCompileShader(vertexShader);

    unsigned int fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &f, NULL);
    glCompileShader(fragmentShader);

    crateProgram(vertexShader,fragmentShader);
    
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);  
}

  
void shader::crateProgram(const unsigned int vert,const unsigned int frag){
    ID = glCreateProgram();

    glAttachShader(ID,vert);
    glAttachShader(ID,frag);
    glLinkProgram(ID);
}

void shader::useProgram(){
    glUseProgram(ID);
}