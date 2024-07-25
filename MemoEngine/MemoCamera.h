#pragma once

#ifdef MEMOENGINE_EXPORTS
#define MEMOENGINE_API __declspec(dllexport)
#else
#define MEMOENGINE_API __declspec(dllimport)
#endif

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "MemoWindow.h"
#include "MemoMath.h"

class Camera2D
{
public:
	Matrix model;
	Matrix view;
	Matrix projection;

	Vector3D pos;

	MEMOENGINE_API Camera2D(Window* window, float x, float y, float z);
	MEMOENGINE_API ~Camera2D();

	MEMOENGINE_API void update();
};

