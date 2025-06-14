#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTexCoord;
layout (location = 3) in vec2 aTangent;
layout (location = 4) in vec2 aBtangent;

layout (location = 5) in vec3 aColor;
out vec3 ourColor;
uniform mat4 model;
uniform mat4 projection;
uniform mat4 view;
uniform vec3 lightPos;
uniform vec3 camPos;

out vec3 viewPos;
out vec3 Normal;
out vec2 TextCoord;
out vec3 FragPos;

void main() {
    FragPos = vec3(model*vec4(aPos,1.0));
    //gl_Position = projection*view*model*vec4(FragPos, 1.0);
    gl_Position = projection*view*model*vec4(aPos, 1.0);
    ourColor = aColor;
    TextCoord = aTexCoord;
    Normal = aNormal;
    viewPos = camPos;
}