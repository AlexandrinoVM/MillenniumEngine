#include <headers/mesh.hpp>


Mesh::Mesh(std::vector<Vertex> vertices,std::vector<unsigned int> indices,std::vector<Texture> textures){
    Mesh::vertices = vertices;
    Mesh::indices = indices;
    Mesh::textures = textures;

    setupMeshi();
}


void Mesh::setupMeshi(){
    VAO vao;
    VBO vbo;
    EBO ebo;

    vao.bindVAO();
    vbo.bindVBO();
    vbo.setData(vertices);
    ebo.bindEBO();
    ebo.setData(indices);
    vao.VAOatribs(0,3,sizeof(Vertex),0);
    vao.VAOatribs(1,3,sizeof(Vertex),offsetof(Vertex,Vertex::Normal));
    vao.VAOatribs(2,2,sizeof(Vertex),offsetof(Vertex,Vertex::Textcoords));

    Vao = vao.getVAO();
    Vbo = vbo.getVBO();
    Ebo = ebo.getEBO();

    vao.unbidVAO();
    vbo.unbidVBO();
    ebo.unbidEBO();

    


}