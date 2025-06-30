#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTexCoord;
layout (location = 3) in mat4 aOffsets;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out float instancedIds;

out vec3 normal;
out vec3 fraPos;
out vec3 vi;
out vec2 textCoord;

void main()
{

    mat4 finalModel = model;
     finalModel = finalModel * aOffsets;
    // vec4 worldPos = model * vec4(aPos, 1.0);
    vec4 worldPos = finalModel * vec4(aPos, 1.0);
    fraPos = vec3(worldPos);
    normal = mat3(transpose(inverse(model))) * aNormal;
    vi = vec3(view[3]) - fraPos; 
    textCoord = aTexCoord;
    instancedIds = float(gl_InstanceID);
    gl_Position = projection * view * worldPos;
}