#version 400 core
out vec4 FragColor;

in vec3 v_color;
in vec2 v_texture;

uniform sampler2D diffuse_texture;

void main()
{
  FragColor = texture(diffuse_texture, v_texture);
}