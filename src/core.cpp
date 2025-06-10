#include "../include/headers/core.hpp"

void Core::init(const char*text,int w,int h){
    Window.init(text,w,h);
    Render.init(Window.getWindow(),&camera);
}

void Core::run(){
    Render.events();
    //shaderConfig().setMat4("view",camera.getCamera());
    Render.RenderWindow();
}

void Core::clear(){
    Render.clear();
}

void Core::loadShaders(const std::string &ShaderName, const std::string &vert,const std::string &frag){
    Shader.Loadshader(ShaderName,vert,frag);
}

void Core::useProgram(const std::string &Shadername){
    Shader.useProgram(Shadername);
}

int Core::getProgramId(){
    return Shader.getID();
}