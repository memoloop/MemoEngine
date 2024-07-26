#version 330 core

layout(location=0) in vec3 vertices;
layout(location=1) in vec2 textures;

uniform vec2 position;
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main() 
{
	gl_Position = projection * view * model * vec4(vertices.xy+position.xy, vertices.z, 1);
}