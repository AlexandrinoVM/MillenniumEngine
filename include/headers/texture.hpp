#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stimage/stb_image.h>
#include <string>
#include <iostream>

class Texture{
    public:
    void loadTexture(const char *Path);
    void TexTureSetup(const char* Path,unsigned int TextType);
    unsigned int generateTexture();
    void bindTexture(unsigned int Texture);
    void reverseImage();
    void activeText(int type);
    void TextureBind(){glBindTexture(GL_TEXTURE_2D,TextureId);};
    void activeText(){glActiveTexture(GL_TEXTURE0);};
    private:
    unsigned int TextureId;;
    int width,height,nerchannels;
    unsigned char* data;
};