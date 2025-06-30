#version 330 core
out vec4 FragColor;

in vec3 normal;
in vec3 fraPos;
in vec3 vi;
in vec2 textCoord;

struct Light {
    vec3 position;
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

struct Material {
    sampler2D diffuse;
    float shininess;
};

in float instancedIds;

uniform Material material;
uniform Light light;

void main() {
    // Normalize
    vec3 norm = normalize(normal);
    vec3 lightDir = normalize(light.position - fraPos);
    vec3 viewDir = normalize(vi);
    vec3 reflectDir = reflect(-lightDir, norm);

    // Ambient                      case have texture
    vec3 ambient = light.ambient ;//* texture(material.diffuse, textCoord).rgb;
    vec3 colorwhite = vec3(1.f);
    // Diffuse
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = light.diffuse * diff;//* texture(material.diffuse, textCoord).rgb;
    // vec3 diffuse = light.diffuse * diff;//* texture(material.diffuse, textCoord).rgb;

    // Specular
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    vec3 specular = light.specular * spec;

    vec3 result = ambient + diffuse + specular;
    uint colorsid = uint(instancedIds);
    vec3 finalcolors = vec3(
        float((colorsid & 0x000000FFu))/255.0,
        float((colorsid &  0x0000FF00u)>>8)/255.0,
        float((colorsid & 0x00FF0000u)>> 16)/255.0
    );

    // FragColor = vec4(result, 1.0);
    FragColor = vec4(finalcolors, 1.0);
}
