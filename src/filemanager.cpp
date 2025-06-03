#include "../include/headers/filemanager.hpp"

std::string fileManager::loadSource(const std::string& path){
    std::ifstream file(path);
    if(!file){
        std::cerr << "faild to open file:" << path << std::endl;
        return "";
    }
    
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}