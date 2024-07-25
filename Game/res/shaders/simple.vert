#version 330 core

layout(location=0) in vec3 vertices;

uniform vec2 position;

void main() 
{
	gl_Position = vec4(vertices.xy+position, vertices.z, 1);
}