#include <headers/cube.hpp>

void printY(std::vector<glm::vec3> lastPositiony,glm::vec3 offset,std::vector<glm::vec3> cubePositions);


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
    std::cout << "buffers setados" << '\n';
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
   
    glm::vec3 offset(0.f);
     int tsize = lastPositiony.size();
    switch (x)
    {
    case 'x':{ 
    offset = glm::vec3(1.0f, 0.0f, 0.0f); 
     if(cubePositions.size() == 0 || cubePositions.size() <= 1){
        glm::vec3 cross = cubePositions.back() + offset;
            newPositions.push_back(cubePositions.back());
            newPositions.push_back(cross);
            cubCount++;
    }
    else{

        for(const auto&pos : cubePositions){
            glm::vec3 cross = pos+ offset;
            if(std::find(cubePositions.begin(),cubePositions.end(), cross) != cubePositions.end()){
                continue;
            }else{
                lastPositionxx.push_back(cross);
                newPositions.push_back(cross);
                cubCount++;
            }
            
        }
        
    }
    break;
}
    case 'y':{ 
    offset = glm::vec3(0.0f, 1.f, 0.0f); 
    lastPositiony.clear();
      if(cubePositions.size() <= 1){
        glm::vec3 cross = cubePositions.back() + offset;
            newPositions.push_back(cubePositions.back());
            newPositions.push_back(cross);
            lastPositiony.push_back(cross);
            cubCount++;
            layerY++;
            break;
    }else{
        for(const auto&pos :cubePositions){
            glm::vec3 cross = pos+ offset;
            if(std::find(cubePositions.begin(),cubePositions.end(), cross) != cubePositions.end()){
                cubCount++;
            }else{
                lastPositiony.push_back(cross);
                newPositions.push_back(cross);
                continue;
    
            }
       }    
       layerY++;   
    }
    break;
}
    
    case 'z': {
    offset = glm::vec3(0.0f, 0.0f, -0.5f); 
     if(cubePositions.size() == 0 || cubePositions.size() <= 1){
        glm::vec3 cross = cubePositions.back() + offset;
            newPositions.push_back(cubePositions.back());
            newPositions.push_back(cross);
            cubCount++;
    }
    else{
        for(const auto&pos : cubePositions){
            glm::vec3 cross = pos+ offset;
            if(std::find(cubePositions.begin(),cubePositions.end(), cross) != cubePositions.end()){
                continue;
            }else{
                lastPositionz.push_back(cross);
                newPositions.push_back(cross);
                cubCount++;
            }
        }

    }

    break;
}

    case '<':{

    // std::vector<glm::vec3> newY;
    // offset = glm::vec3(0.0f, 1.f, 0.0f); 
    // for(const auto&pos : lastPositiony){
    //     glm::vec3 originalPOs = offset-pos;
    //     auto it = std::find(cubePositions.begin(), cubePositions.end(), pos);
    //     if(it != cubePositions.end()){
    //         glm::vec3 cross = offset-pos ;
    //         cubePositions.erase(it);
    //         newY.push_back(cross);
    //         cubCount++;
    //     }
    // }
    // lastPositiony= std::move(newY);
    // printY(lastPositiony,offset,cubePositions);
    // newY.clear();
    removeLayery(cubePositions,layerY);
    break;
}
    default: return; 
}
    cubePositions.insert(cubePositions.end(),newPositions.begin(),newPositions.end());
    lastPositionx.insert(lastPositionx.begin(),newPositions.begin(),newPositions.end());
    newPositions.clear();
    //cubePositions.push_back(lastPos + offset);
    //std::cout << cubePositions.size() << '\n';
    
}

void printY(std::vector<glm::vec3> lastPositiony,glm::vec3 offset,std::vector<glm::vec3> cubePositions){
    for(unsigned int i = 0 ;i< lastPositiony.size()  ;i++){
        std::cout << "x:"<<lastPositiony[i].x << " y:" <<lastPositiony[i].y << " z:" << lastPositiony[i].z  << '\n';
    }
       
} 

void Cube::removeLayery(std::vector<glm::vec3> &cubepositions,int &layerY){
    float layersize = 1.f*layerY;
      auto isSameY = [](float a, float b) {
        return std::fabs(a - b) < 0.0001f;
    };
    
    cubePositions.erase(
        std::remove_if(cubePositions.begin(), cubePositions.end(),
            [layersize, isSameY](const glm::vec3 &pos) {
                return isSameY(pos.y, layersize);
            }
        ),
        cubePositions.end()
    );
    layerY--;
}