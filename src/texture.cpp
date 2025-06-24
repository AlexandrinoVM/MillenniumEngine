#include <headers/texture.hpp>


void Texture::loadTexture(const char *Path){
    reverseImage();
    data = stbi_load(Path,&width,&height,&nerchannels,0);
    
}

unsigned int Texture::generateTexture(){
    unsigned int texture;
    glGenTextures(1,&texture);
    glBindTexture(GL_TEXTURE_2D,texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    if(data){
        glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,width,height,0,GL_RGB,GL_UNSIGNED_BYTE,data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }else{
        std::cout << "Failed to load texture" << '\n';
    }
    stbi_image_free(data);
    return texture;

}

void Texture::bindTexture(unsigned int Texture){
    glBindTexture(GL_TEXTURE_2D,Texture);
}

void Texture::reverseImage(){
    stbi_set_flip_vertically_on_load(true);
}

void Texture::activeText(int type){
    glActiveTexture(type);
}