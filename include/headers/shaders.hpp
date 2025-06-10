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
    
    void setBool(const std::string &name,bool value)const;
    void setFloat(const std::string &name,float value)const;
    void setint(const std::string &name,int value)const;
    void setMat4(const std::string &name, glm::mat4 data)const;
    void setVec3(const std::string &nameProgram,const std::string &name, glm::vec3 data);
    private:
    std::string loadSource(const std::string &VertexPath);
    std::map<std::string,int> shaders;
    int ID;
};