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
	MEMOENGINE_API Shape(float vertices[], size_t verticesSize, int indices[], size_t indicesSize);
	MEMOENGINE_API ~Shape();

	MEMOENGINE_API void draw();

private:
	int verticesNum;
	int indicesNum;

	GLuint vao;
	GLuint vboPos;
	GLuint ebo;
};