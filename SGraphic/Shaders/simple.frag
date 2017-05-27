#version 330 core

in vec2 fragTexCoords;

out vec4 color;

uniform sampler2D texture_diffuse1;
uniform float shininess;

void main()
{
  color = texture(texture_diffuse1, fragTexCoords);
}
