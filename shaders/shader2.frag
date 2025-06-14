#version 330 core
in vec3 ourColor;
out vec4 FragColor;
in vec2 TextCoord;


struct Material{
    sampler2D diffuse;
    sampler2D specular;
};

struct Light{
    vec3 position;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shininess;
};


uniform Material material;

uniform vec3 objectColor;
uniform vec3 lightColor;
uniform float ambientLight;
uniform Light light;

in vec3 FragPos;
in vec3 Normal;
in vec3 viewPos;
uniform vec3 lightPos ;
uniform float oFsset;

void main() {
    //ambient
    vec3 ambient = light.ambient * texture(material.diffuse,TextCoord).rgb;

    //diffuse
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(lightPos - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = light.diffuse * diff * texture(material.diffuse, TextCoord).rgb;

    //especular
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir,norm);
    float spec = pow(max(dot(viewDir,reflectDir),0.0),light.shininess);
    vec3 specular = lightColor * spec *texture(material.specular,TextCoord).rgb;

    vec3 result = ambient + diffuse + specular;

    FragColor = vec4(result,1.0);
}