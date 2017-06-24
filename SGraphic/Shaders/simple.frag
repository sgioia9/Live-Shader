#version 330 core

in vec2 fragTexCoords;

out vec4 color;

uniform vec3 cameraPosition;

uniform sampler2D texture_diffuse1;
uniform sampler2D texture_specular1;

uniform float shininess;

void main()
{
  color = texture(texture_diffuse1, fragTexCoords);
}
