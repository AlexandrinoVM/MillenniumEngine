#include <headers/tranfomation.hpp>



Tranformations::Tranformations(){
   trans = glm::mat4(1.0f);
   trans = glm::translate(trans,glm::vec3(1.0f,1.0f,0.0f));
   vec = trans * vec;
   std::cout << vec.x << vec.y << vec.z << std::endl;
}