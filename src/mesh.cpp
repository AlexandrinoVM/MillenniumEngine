#include <headers/mesh.hpp>


Mesh::Mesh(std::vector<Vertex> vertices,std::vector<unsigned int> indices,std::vector<texture> textures){
    Mesh::vertices = vertices;
    Mesh::indices = indices;
    Mesh::textures = textures;
    setupMeshi();
}


void Mesh::setupMeshi(){
    

    vao.bindVAO();
    vbo.bindVBO();
    vbo.setData(vertices);
    vao.VAOatribs(0,3,sizeof(Vertex),0);
    vao.VAOatribs(1,3,sizeof(Vertex),offsetof(Vertex,Normal));
    vao.VAOatribs(2,2,sizeof(Vertex),offsetof(Vertex,Textcoords));
    ebo.bindEBO();
    ebo.setData(indices);

    Vao = vao.getVAO();
    Vbo = vbo.getVBO();
    Ebo = ebo.getEBO();

    vao.unbidVAO();
    vbo.unbidVBO();
    ebo.unbidEBO();
}

void Mesh::draw(shader &shader,const std::string &shaderName){

    unsigned int diffuseNr =1;
    unsigned int specularNr =1;
    unsigned int normalNr =1;
    unsigned int heightNr =1;
    for(int i=0; i < textures.size();i++){

        glActiveTexture(GL_TEXTURE0 + i);

        std::string number;
        std::string name = textures[i].type;
        if(name == "texture_diffuse"){
            diffuseNr = diffuseNr +1;
            number = std::to_string(diffuseNr++);
        }else if(name == "texture_specular"){
            number = std::to_string(specularNr++);
        }
        else if(name == "texture_normal")
                number = std::to_string(normalNr++);
        else if(name == "texture_height")
                number = std::to_string(heightNr++);
                
        shader.setint(shaderName,("material."+name+number).c_str(),i);
        glBindTexture(GL_TEXTURE_2D,textures[i].id);
    }
    glActiveTexture(GL_TEXTURE0);
    
    vao.bindVAO(Vao);
    glDrawElements(GL_TRIANGLES,indices.size() ,GL_UNSIGNED_INT,0);
    glBindVertexArray(0);
}