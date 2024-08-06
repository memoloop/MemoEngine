#version 330 core

in vec2 tex_coords;

out vec4 FragColor;

uniform vec2 tex_position;
uniform vec2 tex_scale;
uniform vec4 color;
uniform sampler2D sampler;

void main() 
{
	vec2 scaled_tex_coords = (tex_coords * tex_scale) + tex_position;
	FragColor = texture(sampler, scaled_tex_coords) * color;
}