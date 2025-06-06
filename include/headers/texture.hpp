#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stimage/stb_image.h>
#include <string>
#include <iostream>

class Texture{
    public:
    void loadTexture(const char *Path);
    unsigned int generateTexture();
    void bindTexture(unsigned int Texture);
    void reverseImage();
    void activeText(int type);
    private:
    int width,height,nerchannels;
    unsigned char* data;
};