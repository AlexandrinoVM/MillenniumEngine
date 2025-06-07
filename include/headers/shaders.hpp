#pragma once
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <string>
#include <fstream>
#include <sstream>


class shader{
    public:
    void Loadshader(const std::string &vert,const std::string &frag);
    void crateProgram(const unsigned int vert,const unsigned int frag);
    void useProgram();
    int getID(){return ID;};

    
    void setBool(const std::string &name,bool value)const;
    void setFloat(const std::string &name,float value)const;
    void setint(const std::string &name,int value)const;
    void setMat4(const std::string &name, glm::mat4 data)const;
    private:
    std::string loadSource(const std::string &VertexPath);

    int ID;
};