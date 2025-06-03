#include "../include/headers/core.hpp"

void Core::init(const char*text,int w,int h){
    Window.init(text,w,h);
    Render.init(Window.getWindow());
}

void Core::run(){
        Render.events();
        Render.RenderWindow();
}

void Core::clear(){
    Render.clear();
}