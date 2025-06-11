#pragma once
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <string>
#include <fstream>
#include <sstream>
#include <map>

class shader{
    public:
    void Loadshader(const std::string &ShaderName,const std::string &vert,const std::string &frag);
    void crateProgram(const unsigned int vert,const unsigned int frag);
    void useProgram(const std::string &Shadername);
    int getID(){return ID;};
    void stop();
    
    void setBool(const std::string &nameProgram,const std::string &name,bool value);
    void setFloat(const std::string &nameProgram,const std::string &name,float value);
    void setint(const std::string &nameProgram,const std::string &name,int value);
    void setMat4(const std::string &nameProgram,const std::string &name, glm::mat4 data);
    void setVec3(const std::string &nameProgram,const std::string &name, glm::vec3 data);
    void setVec4(const std::string &nameProgram,const std::string &name, glm::vec4 data);
    private:
    std::string loadSource(const std::string &VertexPath);
    std::map<std::string,int> shaders;
    int ID;
};