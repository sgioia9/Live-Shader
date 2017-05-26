#version 330 core

in vec2 texCoords;

out vec4 color;

uniform sampler2D the_texture;

void main()
{
  color = texture(the_texture, texCoords);
}
