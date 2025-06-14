#pragma once 
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <shaders.hpp>
#include <string>
#include <vector>
#include <mesh.hpp>

class Model{

    public:
    Model(char *Path){
        loadModel(Path);
    }
    void DrawModel(shader &shader);
    private:

    std::vector<Mesh> meshes;

    void loadModel(std::string path);
    void processNode(aiNode *node,const aiScene *scene);
    void processMeshi(aiMesh *mesh,const aiScene *scene);

};