#include <headers/cube.hpp>


void Cube::setupBuffers(){
    vao.bindVAO();
    vbo.bindVBO();
    ebo.bindEBO();
    vbo.setData(cubeVertices);
    vao.VAOatribs(0,3,3*sizeof(float),0);
    ebo.setData(cubeIndices);

    VBo = vao.getVAO();
   

    vao.unbidVAO();
    ebo.unbidEBO();
    vbo.unbidVBO();
    std::cout << "buffers setados" << std::endl;
}

void Cube::draw(shader &Shader,const std::string &nameshader,glm::mat4 view){
    Shader.useProgram(nameshader);
    vao.bindVAO(VBo);
    glm::mat4 projection = glm::perspective(glm::radians(45.0f),800.0f/600.0f,0.01f,1000.0f);
    Shader.setMat4(nameshader, "projection", projection);
    Shader.setMat4(nameshader, "view",view);
    for(const glm::vec3 &pos : cubePositions){
        glm::mat4 model = glm::mat4(1.f);
        model = glm::translate(model,pos);
        Shader.setMat4(nameshader, "model", model);
        glDrawElements(GL_TRIANGLES,cubeIndices.size(),GL_UNSIGNED_INT,0);
    }
    
    vao.unbidVAO();
}

void Cube::createCubes(char x){
    glm::vec3 lastPos(0.f);

    if (cubePositions.empty()) {
        cubePositions.push_back(lastPos);
        cubCount = 1; // inicializa contador
        return;
    }
    lastPos = cubePositions.back();

    glm::vec3 offset(0.f);

    switch (x)
    {
    case 'x': offset = glm::vec3(1.0f, 0.0f, -3.0f); break;
    case 'y': offset = glm::vec3(0.0f, 1.0f, -3.0f); break;
    case 'z': offset = glm::vec3(0.0f, 0.0f, -3.5f); break;
    default: return; 
    }

    cubePositions.push_back(lastPos + offset);
    std::cout << cubePositions.size() << std::endl;
    cubCount++;
}