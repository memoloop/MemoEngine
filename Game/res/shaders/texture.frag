#version 330 core

in vec2 tex_coords;

out vec4 FragColor;

uniform vec2 tex_position;
uniform vec4 color;
uniform sampler2D sampler;

void main() 
{
	FragColor = texture(sampler, tex_coords+tex_position) * color;
}