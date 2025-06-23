#include "headers/gui.hpp"


GUI::GUI(const std::string&GLSLCONTEX,GLFWwindow*window){
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(GLSLCONTEX.c_str());
}

void GUI::newFrame(){
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
}

void GUI::inteface(){
    ImGui::Begin("Janela Teste");
      
}

void GUI::close(){
    ImGui::End();
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void GUI::Button(const std::string& nameButton,char x,std::function<void(char)>callback){
    if(ImGui::Button(nameButton.c_str())){
        callback(x);
    }
}

void GUI::CheckBox(const std::string& nameButton,bool &bolean,std::function<void(bool)>callback ){
    if(ImGui::Checkbox(nameButton.c_str(),&bolean)){
        callback(bolean);
    }
}
void GUI::CheckBox(const std::string& nameButton,bool &bolean,glm::vec3 &data){
    ImGui::Checkbox(nameButton.c_str(),&bolean);
    if(getAnotherwindow()){
        showAnotherwindow(data);
    }
}

void GUI::showAnotherwindow(glm::vec3 &data){
    if(objectWindow){
    ImGui::Begin("Another Window", &objectWindow);   
    ImGui::Text("Hello from another window!");
    if (ImGui::Button("Close Me")){
        objectWindow = false;
    }
    slideObject(data);

    ImGui::End(); 
    }
}

void GUI::slideObject(glm::vec3 &data){
   ImGui::SliderFloat("x",&data.x,-5.f,10.f,"%.3f",0);
   ImGui::SliderFloat("y",&data.y,-60.f,60.f,"%.3f",0);
   ImGui::SliderFloat("z",&data.z,-60.f,60.f,"%.3f",0);

}