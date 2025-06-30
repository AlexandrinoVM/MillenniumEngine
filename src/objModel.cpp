#include "headers/objModel.hpp"


void ObjModel::setupInstancedObjes(){
    if(instaces.size() == 0 && InstancedQtd > 1){
        glm::vec3 data;
        for(int i=0;i<InstancedQtd; i++){
            int randonX = std::rand() % 101;
            int randonY = std::rand() % 50;
            int randonZ = std::rand() % -101;
                data.x = (float)randonX;
                data.y = (float)randonY;
                data.z = (float)randonZ;
            instaces.push_back(data);
        }
        for(int i=0;i<InstancedQtd; i++){
            glm::mat4 model =glm::mat4(1.f);
            instancesMath.push_back(glm::translate(glm::mat4(1.0f),(instaces[i])));
        }
        
        instanceObjsVbo.bindVBO();
        instanceObjsVbo.setData(instancesMath);
    }else{
        instanceObjsVbo.bindVBO();
    }
    glEnableVertexAttribArray(3);
    for (unsigned int i = 0; i < 4; i++) {
    glEnableVertexAttribArray(3 + i);
    glVertexAttribPointer(3 + i, 4, GL_FLOAT, GL_FALSE, sizeof(glm::mat4), (void*)(sizeof(float) * i * 4));
    glVertexAttribDivisor(3 + i, 1);
    }
    // vao.VAOatribs(3,3,instancesMath.size() *  sizeof(glm::mat4),0);
    // glVertexAttribDivisor(3,1);
    instanceObjsVbo.unbidVBO();
    
    
}


void ObjModel::atrrib(const char*filename,const char* mode){
    
    std::filesystem::path pathModel = filename;
    searchFiles(pathModel);

    const char *test= objModelPath.data();
    FILE *file = fopen(test,mode);
    
    std::vector< unsigned int > vertexIndices, uvIndices, normalIndices;
    std::vector<glm::vec3> temp_Vertices;
    std::vector<glm::vec3> temp_normals;
    std::vector<glm::vec2> temp_texts;
    if(file == NULL){
        std::cout << "ERROR::COULD::NOT::OPEN::MODEL::DATA" << '\n';
        return;
    }
    while(1){
        char lineHeader[128];

        int res = fscanf(file,"%s",lineHeader);
        if(res == EOF){
            break;
        }
        if(strcmp(lineHeader,"v") == 0){
            glm::vec3 tempVertices;
            fscanf(file,"%f%f%f",&tempVertices.x,&tempVertices.y,&tempVertices.z);
            temp_Vertices.push_back(tempVertices);
        

        }else if(strcmp(lineHeader,"vt")== 0){
            glm::vec3 temTexts;
            fscanf(file,"%f%f",&temTexts.x,&temTexts.y);
            temp_texts.push_back(temTexts);

        }else if(strcmp(lineHeader,"vn")== 0){
            glm::vec3 tempNormals;
            fscanf(file,"%f%f%f",&tempNormals.x,&tempNormals.y,&tempNormals.z);
            temp_normals.push_back(tempNormals);
        }
        else if(strcmp(lineHeader,"f")== 0){
            
            std::string Vertex1,Vertex2,Vertex3;
            unsigned int vertexIndex[4], uvIndex[4], normalIndex[4];
            int moreThenThre = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d %d/%d/%d", &vertexIndex[0], &uvIndex[0], &normalIndex[0], &vertexIndex[1], &uvIndex[1], &normalIndex[1], &vertexIndex[2], &uvIndex[2], &normalIndex[2],&vertexIndex[3], &uvIndex[3], &normalIndex[3] );
            //int matches = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &vertexIndex[0], &uvIndex[0], &normalIndex[0], &vertexIndex[1], &uvIndex[1], &normalIndex[1], &vertexIndex[2], &uvIndex[2], &normalIndex[2] );
            //std::cout << "matchs:"<<matches << '\n';
            
            if(moreThenThre == 12){
                vertexIndices.push_back(vertexIndex[0]);
                vertexIndices.push_back(vertexIndex[1]);
                vertexIndices.push_back(vertexIndex[2]);
                uvIndices.push_back(uvIndex[0]);
                uvIndices.push_back(uvIndex[1]);
                uvIndices.push_back(uvIndex[2]);
                normalIndices.push_back(normalIndex[0]);
                normalIndices.push_back(normalIndex[1]);
                normalIndices.push_back(normalIndex[2]);

                
                vertexIndices.push_back(vertexIndex[0]);
                vertexIndices.push_back(vertexIndex[2]);
                vertexIndices.push_back(vertexIndex[3]);
                uvIndices.push_back(uvIndex[0]);
                uvIndices.push_back(uvIndex[2]);
                uvIndices.push_back(uvIndex[3]);
                normalIndices.push_back(normalIndex[0]);
                normalIndices.push_back(normalIndex[2]);
                normalIndices.push_back(normalIndex[3]);


            }else if(moreThenThre == 9 ){
                vertexIndices.push_back(vertexIndex[0]);
                vertexIndices.push_back(vertexIndex[1]);
                vertexIndices.push_back(vertexIndex[2]);
                uvIndices    .push_back(uvIndex[0]);
                uvIndices    .push_back(uvIndex[1]);
                uvIndices    .push_back(uvIndex[2]);
                normalIndices.push_back(normalIndex[0]);
                normalIndices.push_back(normalIndex[1]);
                normalIndices.push_back(normalIndex[2]);
            }else{
                std::cout << "ERROR::COULD::NOT::READ::MODEL::DATA" << '\n';
                return;
            }
        }
        
    }
    
    for (unsigned int i = 0; i < vertexIndices.size(); i++) {
        glm::vec3 vertex  = temp_Vertices[vertexIndices[i] - 1];
        glm::vec3 normal  = temp_normals[normalIndices[i] - 1];
        glm::vec2 uv      = temp_texts[uvIndices[i] - 1];

        vertices.push_back(vertex);
        Normals.push_back(normal);
        textures.push_back(uv);

        indices.push_back(i); 
    }
    
   
};

std::string toLower(std::string str){
    std::transform(str.begin(),str.end(),str.begin(),[](unsigned char c){return std::towlower(c);});
    return str;
}

void ObjModel::searchFiles(std::filesystem::path &path){
    std::string occurency;

     if(std::filesystem::exists(path) && std::filesystem::is_directory(path)){
        for (const auto &entry : std::filesystem::recursive_directory_iterator(path)) {
        occurency = toLower(entry.path().c_str());
        if(occurency.find(".jpg") != std::string::npos){
            TextureDiffusePath = entry.path().c_str();
        }else if(occurency.find(".obj") != std::string::npos){
            objModelPath = entry.path().c_str();
        }
    }
    }else{
       return;
    }
}

void ObjModel::print(){
    // std::cout << "------------------------VERTICES-------------------------------" << '\n';
    // for(int i =0;i<vertices.size();i++){
    //    std::cout<< "x:"<< vertices[i].x<< " y:"<< vertices[i].y << " z:"<< vertices[i].z<< '\n';
    // }
    // std::cout << "------------------------NORMALS-------------------------------" << '\n';
    //  for(int j =0;j<Normals.size();j++){
    //     std::cout<< "x:"<< Normals[j].x<< " y:"<< Normals[j].y << " z:"<< Normals[j].z<< '\n';
    // }
    //  std::cout << "------------------------TEXTURES-------------------------------" << '\n';
    //  for(int k =0;k<textures.size();k++){
    //     std::cout<< "x:"<< textures[k].x<< " y:"<< textures[k].y << '\n';
    // }

    //  std::cout << "------------------------INDICES-------------------------------" << '\n';
    //  for(int j =0;j<indices.size();j+=3){
    //     if(j + 1 > indices.size()){
    //         break;
    //     }
    //     std::cout<< "x:"<< indices[j]<< " y:"<< indices[j+1]<< " z:"<< indices[j+2]<< '\n';
    // }
   
}
void ObjModel::setup(){
    setupInstancedObjes();
    if(!TextureDiffusePath.empty()){
        text.TexTureSetup(TextureDiffusePath.c_str(),GL_TEXTURE0);
    }

    
    for (size_t i = 0; i < vertices.size(); ++i) {
    SendData data;
    data.vertices = vertices[i];      
    data.Normals  = Normals[i];       
    data.texts    = textures[i];      
    finalData.push_back(data);
    }
   
    vao.bindVAO();
    vbo.bindVBO();
    ebo.bindEBO();
       
    vbo.setData(finalData);
    vao.VAOatribs(0,3,sizeof(SendData),0);
    vao.VAOatribs(1,3,sizeof(SendData),offsetof(SendData,Normals));
    vao.VAOatribs(2,2,sizeof(SendData),offsetof(SendData,texts));

    ebo.setData(indices);
    vao.unbidVAO();
    vbo.unbidVBO();
}

void ObjModel::draw(shader& shader,const std::string&nama,glm::mat4 view){
    glm::mat4 model(1.f);
    glm::mat4 projection = glm::perspective(glm::radians(45.0f),800.0f/600.0f,0.01f,1000.0f);
    if(instaces.size() > 0){
        shader.setMat4(nama,"model",model);
        shader.setMat4(nama,"projection",projection);
        shader.setMat4(nama,"view",view);
        shader.setVec3(nama,"light.position",lightPos);
        shader.setVec3(nama,"light.ambient",objColor);
        shader.setVec3(nama,"light.diffuse",glm::vec3(1.0));
        shader.setVec3(nama,"light.specular",glm::vec3(1.0f));
        shader.setFloat(nama,"material.shininess", 32.0f);
    }else{
        model = glm::translate(model,position);
        model = glm::rotate(model,glm::radians(45.f),rotatePos);
        model = glm::scale(model,glm::vec3(2.f));
        shader.setMat4(nama,"model",model);
        shader.setMat4(nama,"projection",projection);
        shader.setMat4(nama,"view",view);
        shader.setVec3(nama,"light.position",lightPos);
        shader.setVec3(nama,"light.ambient",objColor);
        shader.setVec3(nama,"light.diffuse",glm::vec3(1.0));
        shader.setVec3(nama,"light.specular",glm::vec3(1.0f));
        shader.setFloat(nama,"material.shininess", 32.0f);

    }
    if(!TextureDiffusePath.empty()){
        text.activeText();
        text.TextureBind();
        shader.setint(nama,"material.diffuse",0);
    }
    vao.bindVAO();
    if(InstancedQtd > 1){
        if(instaces.size() == 0){
            setupInstancedObjes();
        }
        glDrawElementsInstanced(GL_TRIANGLES,indices.size(),GL_UNSIGNED_INT,0,instancesMath.size());
    }else{
        glDrawElements(GL_TRIANGLES, indices.size() ,GL_UNSIGNED_INT, 0);
    }
    vao.unbidVAO();
    //glDrawArrays(GL_TRIANGLES, 0, vertices.size());

}

