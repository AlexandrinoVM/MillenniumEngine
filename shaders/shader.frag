#version 330 core
in vec3 ourColor;
out vec4 FragColor;


struct Material{
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shininess;
};

//uniform vec4 ourColor;
in vec2 TextCoord;
uniform sampler2D texture_diffuse1;
uniform sampler2D texture_specular1;
uniform Material material;

uniform vec3 objectColor;
uniform vec3 lightColor;
uniform float ambientLight;

in vec3 FragPos;
in vec3 Normal;
in vec3 viewPos;
uniform vec3 lightPos ;
uniform float oFsset;

void main() {
    //ambient
    vec3 ambient =vec3(lightColor) * material.ambient;

    //diffuse
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(lightPos - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = lightColor * (diff *material.diffuse);

    //especular
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir,norm);
    float spec = pow(max(dot(viewDir,reflectDir),0.0),material.shininess);
    vec3 specular = lightColor * (spec * material.specular);

    vec3 result = ambient + diffuse + specular;

    FragColor =texture(texture_diffuse1,TextCoord) *vec4(result,1.0);
}