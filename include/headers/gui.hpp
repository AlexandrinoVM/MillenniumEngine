#pragma once
#include <imgui/imgui.h>
#include <imgui/imgui_impl_glfw.h>
#include <imgui/imgui_impl_opengl3.h>
#include <string>
#include <functional>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class GUI{
    public:
    GUI(const std::string& GLSLCONTEXT,GLFWwindow*window);
    void newFrame();
    void inteface();
    void close();
    bool &getAnotherwindow(){return objectWindow;};
    void Button(const std::string& nameButton,char x,std::function<void(char)>callback);
    void CheckBox(const std::string& nameButton,bool &bolean,std::function<void(bool)>callbac );
    // void CheckBox(const std::string& nameButton,bool &bolean,void(*func)(bool) );
    void CheckBox(const std::string& nameButton,bool &bolean,glm::vec3 &data);
    void showDemo(){bool demo = true;ImGui::ShowDemoWindow(&demo); };
    void slideObject(const std::string& name,glm::vec3 &data);
    void slider(const std::string& name,glm::vec3 &data);
    void showAnotherwindow(const std::string& name,glm::vec3 &data);
    void headersWithSliders(const std::string& nameHeader,const std::string& name,glm::vec3 &data);
    void coloPickermenu(glm::vec3 &color);
    private:
    bool objectWindow = false;
};