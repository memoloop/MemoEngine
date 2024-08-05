#version 330 core

layout(location=0) in vec3 vertices;
layout(location=1) in vec2 textures;

uniform vec2 position;
uniform vec2 scale;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec2 tex_coords;

void main() 
{
	tex_coords = textures;

	vec3 scaledPosition = vertices;
	scaledPosition.xy = (scaledPosition.xy * scale) + position;
	gl_Position = projection * view * model * vec4(scaledPosition, 1);
}