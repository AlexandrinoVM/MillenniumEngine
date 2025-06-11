#version 330 core
in vec3 ourColor;
out vec4 FragColor;

//uniform vec4 ourColor;
in vec2 TextCoord;
uniform sampler2D texture1;
uniform sampler2D texture2;
uniform vec3 objectColor;
uniform vec4 lightColor;
uniform float ambientLight;

in vec3 FragPos;
in vec3 Normal;
uniform vec3 lightPos ;
uniform float oFsset;

void main() {
    float ambient = 0.20f;

    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(lightPos - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec4 diffuse = vec4(diff * objectColor,1.0);
    vec4 finalColor = (diffuse + ambient);
    //FragColor = lightColor * finalColor;
    
    
    //if(ambientLight < 0.1){
    //    FragColor = vec4(objectColor *lightColor,1.0);
    //}else{
    //    FragColor = vec4(ambientLight*objectColor,1.0);
    //}
    //FragColor = vec4(ourColor,1.0);
    FragColor =texture(texture1,TextCoord) *vec4(lightColor * finalColor);
}