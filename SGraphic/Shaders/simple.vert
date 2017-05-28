#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 texCoords;

out vec2 fragTexCoords;

uniform mat4 model;
uniform mat4 vpMatrix;

void main()
{
    gl_Position = vpMatrix * model * vec4(position, 1.0f);
    fragTexCoords = texCoords;
}
