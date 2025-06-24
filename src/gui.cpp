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
        showAnotherwindow(nameButton,data);
    }
}

void GUI::showAnotherwindow(const std::string &name,glm::vec3 &data){
    if(objectWindow){
    ImGui::Begin("Another Window", &objectWindow);   
    ImGui::Text("Hello from another window!");
    if (ImGui::Button("Close Me")){
        objectWindow = false;
    }
    ImGui::Text("position object");
    slideObject(name,data);

    ImGui::End(); 
    }
}

void GUI::slideObject(const std::string& name,glm::vec3 &data){
   std::string nameSlider = name + ":"; 
   ImGui::SliderFloat((nameSlider+"x").c_str(),&data.x,-5.f,10.f,"%.2f",0);
   ImGui::SliderFloat((nameSlider+"y").c_str(),&data.y,-5.f,10.f,"%.2f",0);
   ImGui::SliderFloat((nameSlider+"z").c_str(),&data.z,-5.f,10.f,"%.2f",0);
}

void GUI::headersWithSliders(const std::string& nameHeader, const std::string& nameSliders,glm::vec3 &data){
    if(ImGui::CollapsingHeader(nameHeader.c_str())){
        slideObject(nameSliders,data);
    }
}