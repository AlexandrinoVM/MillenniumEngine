#include "headers/objModel.hpp"


void ObjModel::atrrib(const char*filename,const char* mode){
    FILE *file = fopen(filename,mode);
    std::vector< unsigned int > vertexIndices, uvIndices, normalIndices;
    std::vector<glm::vec3> temp_Vertices;
    std::vector<glm::vec3> temp_normals;
    std::vector<glm::vec2> temp_texts;
    if(file == NULL){
        std::cout << "ERROR::COULD::NOT::OPEN::MODEL::DATA" << std::endl;
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
            unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];
            int matches = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &vertexIndex[0], &uvIndex[0], &normalIndex[0], &vertexIndex[1], &uvIndex[1], &normalIndex[1], &vertexIndex[2], &uvIndex[2], &normalIndex[2] );
            if(matches != 9){
                std::cout << "ERROR::COULD::NOT::READ::MODEL::DATA" << std::endl;
                return;
            }
            vertexIndices.push_back(vertexIndex[0]);
            vertexIndices.push_back(vertexIndex[1]);
            vertexIndices.push_back(vertexIndex[2]);
            uvIndices    .push_back(uvIndex[0]);
            uvIndices    .push_back(uvIndex[1]);
            uvIndices    .push_back(uvIndex[2]);
            normalIndices.push_back(normalIndex[0]);
            normalIndices.push_back(normalIndex[1]);
            normalIndices.push_back(normalIndex[2]);
        }
        
    }

//     for (unsigned int i = 0; i < vertexIndices.size(); ++i) {
//     unsigned int vertexIndex = vertexIndices[i];
//     // Os arquivos .obj começam em 1, por isso vertexIndex - 1
//         glm::vec3 vertex = temp_Vertices[vertexIndex - 1];
//         indices.push_back(vertex.x);
//         indices.push_back(vertex.y);
//         indices.push_back(vertex.z);
// }
    

   

    // for (auto index : vertexIndices) {
    //     finalVertices.push_back(temp_Vertices[index - 1]);
    // }
    
    // std::vector<unsigned int> indices;
    // for (auto index : vertexIndices) {
    //     indices.push_back(index - 1);  // Corrige para base 0
    // }
    //indices.push_back(indices.begin(),finalVertices.begin(),finalVertices.end());

    // for( unsigned int i=0; i<vertexIndices.size(); i++ ){
    //     unsigned int vertexIndex = vertexIndices[i];
    //     glm::vec3 vertex = temp_Vertices[ vertexIndex-1 ];
    //     vertices.push_back(vertex);
    // }
    for(const auto&vert : temp_Vertices){
        vertices.push_back(vert);
    }

     for( unsigned int i=0; i<vertexIndices.size(); i++ ){
        indices.push_back(vertexIndices[i] -1);
    }

    for (unsigned int i = 0; i < uvIndices.size(); i++) {
        unsigned int uvIndex = uvIndices[i];
        glm::vec2 uv = temp_texts[uvIndex - 1];
        textures.push_back(uv);
    }



    for( unsigned int i=0;i<normalIndices.size(); i++ ){
        unsigned int normalIndice =normalIndices[i];
        glm::vec3 vertex = temp_Vertices[normalIndice -1];
        Normals.push_back(vertex);
    }

    //vertices.insert(vertices.begin(),temp_Vertices.begin(),temp_Vertices.end());
    //indices.insert(indices.begin(),vertexIndices.begin(),vertexIndices.end());
   
};

void ObjModel::print(){
    std::cout << "------------------------VERTICES-------------------------------" << std::endl;
    for(int i =0;i<vertices.size();i++){
       std::cout<< "x:"<< vertices[i].x<< " y:"<< vertices[i].y << " z:"<< vertices[i].z<< std::endl;
    }
    // std::cout << "------------------------NORMALS-------------------------------" << std::endl;
    //  for(int j =0;j<Normals.size();j++){
    //     std::cout<< "x:"<< Normals[j].x<< " y:"<< Normals[j].y << " z:"<< Normals[j].z<< std::endl;
    // }
    //  std::cout << "------------------------TEXTURES-------------------------------" << std::endl;
    //  for(int k =0;k<textures.size();k++){
    //     std::cout<< "x:"<< textures[k].x<< " y:"<< textures[k].y << std::endl;
    // }

     std::cout << "------------------------INDICES-------------------------------" << std::endl;
     for(int j =0;j<indices.size();j+=3){
        if(j + 1 > indices.size()){
            break;
        }
        std::cout<< "x:"<< indices[j]<< " y:"<< indices[j+1]<< " z:"<< indices[j+2]<< std::endl;
    }
   
}
void ObjModel::setup(){
    
  
    //createIndexedMesh(finalVertices, uniqueVertices, indices);
   
    vao.bindVAO();
    vbo.bindVBO();
    ebo.bindEBO();
    vbo.setData(vertices);
    vao.VAOatribs(0,3,sizeof(glm::vec3),0);
    ebo.setData(indices);
    std::cout<< "vertices:"<< vertices.size()<<  std::endl;
    std::cout<< "indices:"<< indices.size()<<  std::endl;
    vao.unbidVAO();
    vbo.unbidVBO();
    ebo.unbidEBO();
}

void ObjModel::draw(shader& shader,const std::string&nama,glm::mat4 view){
    vao.bindVAO();
    glm::mat4 model(1.f);
    glm::mat4 projection = glm::perspective(glm::radians(45.0f),800.0f/600.0f,0.01f,1000.0f);
    model = glm::translate(model,position);
    model = glm::scale(model,glm::vec3(2.f));
    shader.setMat4(nama,"model",model);
    shader.setMat4(nama,"projection",projection);
    shader.setMat4(nama,"view",view);
    //glDrawArrays(GL_TRIANGLES,0,vertices.size());
    glDrawElements(GL_TRIANGLES, indices.size() ,GL_UNSIGNED_INT, 0);
    vao.unbidVAO();
}

