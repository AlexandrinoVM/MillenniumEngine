#include "../include/headers/shaders.hpp"


std::string shader::loadSource(const std::string &pathShader){
        std::string shaderCode;
        std::ifstream shdaderFile;

        shdaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
        try{
            shdaderFile.open(pathShader);
            std::stringstream shaderStream;

            shaderStream << shdaderFile.rdbuf();

            shdaderFile.close();

            shaderCode = shaderStream.str();
            return shaderCode;

        }catch(std::ifstream::failure e){
            std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
            return "";
        }
}

void shader::Loadshader(const std::string &ShaderName,const std::string &vertfrag,const std::string &fragment){
    
    std::string vert = loadSource(vertfrag);
    std::string frag = loadSource(fragment);
    
    int sucess;
    char infolog[512];


    if (vert.empty() || frag.empty()) {
    std::cerr << "Shader source is empty!" << std::endl;
    return;
    }
    const char *vertexShaderSource = vert.c_str();
    const char * fragmentShaderSource = frag.c_str();



    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader,1,&vertexShaderSource,NULL);
    glCompileShader(vertexShader);

    glGetShaderiv(vertexShader,GL_COMPILE_STATUS,&sucess);
    if(!sucess){
        glGetShaderInfoLog(vertexShader,512,NULL,infolog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infolog << std::ends;
    }


    unsigned int fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    glGetShaderiv(fragmentShader,GL_COMPILE_STATUS,&sucess);
    if(!sucess){
        glGetShaderInfoLog(fragmentShader,512,NULL,infolog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infolog << std::ends;
    }


    crateProgram(vertexShader,fragmentShader);
    
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);  
    std::cout <<ShaderName << ":" <<ID << std::endl;
    shaders.insert(std::make_pair(ShaderName,ID));
}

  
void shader::crateProgram(const unsigned int vert,const unsigned int frag){
    int sucess;
    char infolog[512];
    ID = glCreateProgram();

    glAttachShader(ID,vert);
    glAttachShader(ID,frag);
    glLinkProgram(ID);

    glGetShaderiv(ID,GL_LINK_STATUS,&sucess);
    if(!sucess){
        glGetShaderInfoLog(ID,512,NULL,infolog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infolog << std::endl;
    }
}


void shader::setint(const std::string &nameProgram,const std::string &name,int value){
    std::cout << "nome textura:" << name.c_str() << std::endl;
    glUniform1i(glGetUniformLocation(shaders[nameProgram],name.c_str()),value);
}

void shader::setBool(const std::string &nameProgram,const std::string &name,bool value){
    glUniform1i(glGetUniformLocation(shaders[nameProgram],name.c_str()),(int)value);
}

void shader::setFloat(const std::string &nameProgram,const std::string &name,float value){
    glUniform1f(glGetUniformLocation(shaders[nameProgram],name.c_str()),value);
}


void shader::setMat4(const std::string &nameProgram,const std::string &name,glm::mat4 data){
    glUniformMatrix4fv(glGetUniformLocation(shaders[nameProgram],name.c_str()),1,GL_FALSE,glm::value_ptr(data));
}

void shader::setVec3(const std::string &nameProgram,const std::string &nameShader, glm::vec3 data){
    glUniform3fv(glGetUniformLocation(shaders[nameProgram],nameShader.c_str()),1,glm::value_ptr(data));
};
void shader::setVec4(const std::string &nameProgram,const std::string &nameShader, glm::vec4 data){
    glUniform4fv(glGetUniformLocation(shaders[nameProgram],nameShader.c_str()),1,glm::value_ptr(data));
};

void shader::useProgram(const std::string &Shadername){
    glUseProgram(shaders[Shadername]);
}

void shader::stop(){
    glUseProgram(0);
}
