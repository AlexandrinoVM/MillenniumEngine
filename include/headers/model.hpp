#pragma once 
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <string>
#include <vector>
#include "headers/mesh.hpp"
#include <stimage/stb_image.h>
#include <utils/meshiUtils.hpp>
#include "headers/shaders.hpp"

class Model{

    public:
    Model(std::string Path){
        loadModel(Path);
    }
    void DrawModel(shader &shader,const std::string &shaderName);
    private:
    std::string directory;
    std::vector<Mesh> meshes;
    std::vector<texture> textures_loaded;
    void loadModel(std::string path);
    void processNode(aiNode *node,const aiScene *scene);
    Mesh processMesh(aiMesh *mesh,const aiScene *scene);
    std::vector<texture> loadMaterialTextures(aiMaterial *mat,aiTextureType type, std::string typeName); 
};