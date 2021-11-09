#version 400 core
layout (location = 0) in vec3 in_position;
layout (location = 1) in vec3 in_color;
layout (location = 2) in vec2 in_texture;

out vec3 v_color;
out vec2 v_texture;

void main()
{
  gl_Position = vec4(in_position, 1.0);
  v_color = in_color;
  v_texture = in_texture;
}
