#include <headers/terrarian.hpp>
#include <iostream>
void Terrarian::setupTerrarian(){
    float colunsize = 10.0f;
    float init = -400.0f;
    float end = 400.0f;

    vertices.clear();
    indices.clear();

    int index = 0;

    // Linhas paralelas ao eixo X (variação em Z)
    for (float z = init; z <= end; z += colunsize) {
        vertices.push_back(init); vertices.push_back(0.0f); vertices.push_back(z); // ponto inicial
        vertices.push_back(end);  vertices.push_back(0.0f); vertices.push_back(z); // ponto final

        indices.push_back(index++);
        indices.push_back(index++);
    }

    // Linhas paralelas ao eixo Z (variação em X)
    for (float x = init; x <= end; x += colunsize) {
        vertices.push_back(x); vertices.push_back(0.0f); vertices.push_back(init); // ponto inicial
        vertices.push_back(x); vertices.push_back(0.0f); vertices.push_back(end);  // ponto final

        indices.push_back(index++);
        indices.push_back(index++);
    }
}

void Terrarian::draw(shader &teste,glm::mat4 vi){
    glm::mat4 projection = glm::perspective(glm::radians(45.0f),800.0f/600.0f,0.01f,1000.0f);
    glm::mat4 view = vi;
    glm::mat4 model2 = glm::mat4(1.0f);

    model2 = glm::translate(model2, glm::vec3(0.0f,-5.0f,20.0f));
    teste.setMat4("terrarian","model", model2);
    teste.setMat4("terrarian","projection",projection);
    teste.setMat4("terrarian","view",view);
    Vao.bindVAO(vao);

    glDrawElements(GL_LINES,indices.size(),GL_UNSIGNED_INT,0);
    glBindVertexArray(0);
}


void Terrarian::initBuffers(){

    Vao.bindVAO();
    Vbo.bindVBO();
    Ebo.bindEBO();
    Vbo.setData(vertices);
    Vao.VAOatribs(0,3,3*sizeof(float),0);
    Ebo.setData(indices);

    vao = Vao.getVAO();
    ebo = Ebo.getEBO();
    vbo = Vbo.getVBO();

    Vao.unbidVAO();
    Ebo.unbidEBO();
    Vbo.unbidVBO();
}