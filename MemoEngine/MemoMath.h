#pragma once

#ifdef MEMOENGINE_EXPORTS
#define MEMOENGINE_API __declspec(dllexport)
#else
#define MEMOENGINE_API __declspec(dllimport)
#endif

#include <glm/glm.hpp>

typedef glm::vec1 Vector1D;
typedef glm::vec2 Vector2D;
typedef glm::vec3 Vector3D;
typedef glm::vec4 Vector4D;

typedef glm::mat4 Matrix;

struct Rect
{
	float x, y, width, height;
};