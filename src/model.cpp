#include <headers/model.hpp>

unsigned int TextureFromFile(const char *path, const std::string &directory, bool gamma = false);

void Model::DrawModel(shader &shader,const std::string &shaderName){
    for(unsigned int i=0; i < meshes.size();i++){
        meshes[i].draw(shader,shaderName);
    }
}

void Model::loadModel(std::string Path){
    //assim importer namespace
    Assimp::Importer import;

    //create a scene usind the import to read the file in the path
    const aiScene *scene = import.ReadFile(Path,aiProcess_Triangulate | aiProcess_FlipUVs);
    if(!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode){
        std::cout <<"ERROR::ASSIMP::" << import.GetErrorString() << std::endl;
        return;
    }
    //getting the directory path
    //directory = Path.substr(0,Path.find_last_of('/'));
    directory = Path.substr(0,Path.find_last_of('/'));

    
    processNode(scene->mRootNode,scene);
    std::cout << "Scene has " << scene->mNumMeshes << " total meshes." << std::endl;
    std::cout << "Root node has " << scene->mRootNode->mNumChildren << " children." << std::endl;
    std::cout << meshes.data() << std::endl;

}


void Model::processNode(aiNode *node,const aiScene *scene){
    for (unsigned int i = 0; i < node->mNumMeshes; i++) {
        aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
        meshes.push_back(processMesh(mesh, scene));
    }
    for (unsigned int i = 0; i < node->mNumChildren; i++) {
        processNode(node->mChildren[i], scene);
    }
}


Mesh Model::processMesh(aiMesh *mesh,const aiScene *scene){
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;
    std::vector<texture> textures;
    for(unsigned int i =0;i < mesh->mNumVertices;i++){
        glm::vec3 positions;
        Vertex vertex ;
        positions.x = mesh->mVertices[i].x;
        positions.y = mesh->mVertices[i].y;
        positions.z = mesh->mVertices[i].z;
        vertex.Position = positions;

        if(mesh->HasNormals()){
            positions.x = mesh->mNormals[i].x;
            positions.y = mesh->mNormals[i].y;
            positions.z = mesh->mNormals[i].z;
            vertex.Normal = positions;
        }

        if(mesh->mTextureCoords[0]){
            glm::vec2 vec;
            
            vec.x = mesh->mTextureCoords[0][i].x;
            vec.y = mesh->mTextureCoords[0][i].y;
            vertex.Textcoords = vec;

            // positions.x = mesh->mTangents[i].x;
            // positions.y = mesh->mTangents[i].y;
            // positions.z = mesh->mTangents[i].z;
            // vertex.tangent = positions;
            
            // positions.x = mesh->mBitangents[i].x;
            // positions.y = mesh->mBitangents[i].y;
            // positions.z = mesh->mBitangents[i].z;
            // vertex.bitangent = positions;


        }else{
            vertex.Textcoords = glm::vec2(0.0f,0.0f);
        }
        vertices.push_back(vertex);
        
    }
    for(unsigned int i = 0; i < mesh->mNumFaces; i++)
    {
    aiFace face = mesh->mFaces[i];
        for(unsigned int j = 0; j < face.mNumIndices; j++){
            indices.push_back(face.mIndices[j]);
        }
    }  

    if(mesh->mMaterialIndex >= 0)
    {
        aiMaterial *material = scene->mMaterials[mesh->mMaterialIndex];
        std::vector<texture> diffuseMaps = loadMaterialTextures(material, 
                                            aiTextureType_DIFFUSE, "texture_diffuse");
        textures.insert(textures.end(), diffuseMaps.begin(), diffuseMaps.end());
        std::vector<texture> specularMaps = loadMaterialTextures(material, 
                                            aiTextureType_SPECULAR, "texture_specular");
        textures.insert(textures.end(), specularMaps.begin(), specularMaps.end());
    }  
    std::cout << indices.data() << std::endl;
    return Mesh(vertices,indices,textures);
}


std::vector<texture> Model::loadMaterialTextures(aiMaterial *mat,aiTextureType type, std::string typeName)
{
    std::vector<texture> textures;
    for(unsigned int i = 0; i < mat->GetTextureCount(type); i++)
    {
        aiString str;
        mat->GetTexture(type, i, &str);
        bool skip = false;
        for(unsigned int j = 0; j < textures_loaded.size(); j++)
        {
            if(std::strcmp(textures_loaded[j].path.data(), str.C_Str()) == 0)
            {
                textures.push_back(textures_loaded[j]);
                skip = true; 
                break;
            }
        }
        if(!skip)
        {  
            texture texture;
            texture.id = TextureFromFile(str.C_Str(), directory);
            texture.type = typeName;
            texture.path = str.C_Str();
            textures.push_back(texture);
            textures_loaded.push_back(texture); 
            std::cout << "Loaded texture: " << texture.path << ", id: " << texture.id << std::endl;
        }
    }
    return textures;
}  


unsigned int TextureFromFile(const char *path, const std::string &directory, bool gamma)
{
    std::string filename = std::string(path);
    filename = directory + '/' + filename;

    unsigned int textureID;
    glGenTextures(1, &textureID);

    int width, height, nrComponents;
    unsigned char *data = stbi_load(filename.c_str(), &width, &height, &nrComponents, 0);
    if (data)
    {
        GLenum format;
        if (nrComponents == 1)
            format = GL_RED;
        else if (nrComponents == 3)
            format = GL_RGB;
        else if (nrComponents == 4)
            format = GL_RGBA;

        glBindTexture(GL_TEXTURE_2D, textureID);
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        stbi_image_free(data);
    }
    else
    {
        std::cout << "Texture failed to load at path: " << path << std::endl;
        stbi_image_free(data);
    }

    return textureID;
}