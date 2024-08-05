#version 330 core

layout(location=0) in vec3 vertices;

uniform vec2 position;
uniform vec2 scale;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main() 
{
	vec3 scaledPosition = vertices;
	scaledPosition.xy = (scaledPosition.xy * scale) + position;
	gl_Position = projection * view * model * vec4(scaledPosition, 1);
}