#pragma once

#ifdef MEMOENGINE_EXPORTS
#define MEMOENGINE_API __declspec(dllexport)
#else
#define MEMOENGINE_API __declspec(dllimport)
#endif

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "MemoMath.h"

class Shader
{
public:
	MEMOENGINE_API Shader(std::string filename);
	MEMOENGINE_API ~Shader();

	MEMOENGINE_API void useProgram();

	MEMOENGINE_API void setUniform(std::string name, int value);
	MEMOENGINE_API void setUniform(std::string name, float value);
	MEMOENGINE_API void setUniform(std::string name, Vector2D* value);
	MEMOENGINE_API void setUniform(std::string name, Vector3D* value);
	MEMOENGINE_API void setUniform(std::string name, Vector4D* value);
	MEMOENGINE_API void setUniform(std::string name, Matrix value);

private:
	GLuint program;
	GLuint vertexShader;
	GLuint fragmentShader;

	MEMOENGINE_API GLuint createShader(int type, const GLchar* source);
	MEMOENGINE_API std::string loadSource(std::string filename);
};