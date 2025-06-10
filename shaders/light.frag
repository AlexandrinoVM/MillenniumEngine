#version 330 core
in vec3 ourColor;
out vec4 FragColor;

//uniform vec4 ourColor;

uniform sampler2D texture1;
uniform sampler2D texture2;
uniform float oFsset;
void main() {
    FragColor = vec4(1.0f);
    //FragColor = ourColor;
    
    //FragColor =mix(texture(texture1,TextCoord),texture(texture2,vec2(1.0 - TextCoord.x, TextCoord.y)),0.2)*vec4(ourColor,1.0);
}