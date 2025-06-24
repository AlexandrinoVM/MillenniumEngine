#version 330 core
out vec4 FragColor;

in vec3 normal;
in vec3 fraPos;
in vec3 vi;

struct Light{
    vec3 position;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shininess;
};

//light source
uniform vec3 lightSource;

void main() {
    vec3 ambient = vec3(0.5,0.5,0.5f);
    vec3 norm = normalize(normal);
    //source lightining
    vec3 lightining = ambient;
    vec3 modelColor = vec3(0.7, 0.06, 0.06);
    //light color
    vec3 lightcolor = vec3(0.87, 0.27, 0.27);
    //vec3 lightSource = vec3(-2.5f,1.0f,3.f);
    float diffuseStrenth = max(0.0,dot(lightSource,normal));
    vec3 diffuse = diffuseStrenth * lightcolor;

    vec3 vviewSource = normalize(vi);
    vec3 reflection = normalize(reflect(-lightSource,norm));
    float specularStrenth = max(0.0,dot(vviewSource,reflection));
    specularStrenth = pow(specularStrenth,32.f);
    vec3 especular = specularStrenth * lightcolor;
    lightining = ambient * 0.0 + diffuse * 0.5f + especular;

    vec3 color = lightining * modelColor;
    FragColor = vec4(color, 1.0);
}