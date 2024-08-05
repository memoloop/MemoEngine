#pragma once

#ifdef MEMOENGINE_EXPORTS
#define MEMOENGINE_API __declspec(dllexport)
#else
#define MEMOENGINE_API __declspec(dllimport)
#endif

#include "MemoWindow.h"

class Shape
{
public:
	MEMOENGINE_API Shape(float vertices[], size_t verticesSize, float textures[], size_t texturesSize, int indices[], size_t indicesSize);
	MEMOENGINE_API Shape(float vertices[], size_t verticesSize, int indices[], size_t indicesSize);
	MEMOENGINE_API ~Shape();

	MEMOENGINE_API void draw();

private:
	int verticesNum;
	int texturesNum;
	int indicesNum;

	GLuint vao;
	GLuint vboPos;
	GLuint vboTexCoord;
	GLuint ebo;
};

struct RGBAColor 
{
	// The value are between 0.0f to 1.0f
	float red, green, blue, alpha;
};