#include "pch.h"
#include "MemoCamera.h"

MEMOENGINE_API Camera2D::Camera2D(Window* window, float x, float y, float z)
{
	pos = Vector3D(x, y, z);

	model = Matrix(1.0f);
	view = glm::translate(Matrix(1.0F), -pos);
	projection = glm::ortho(0.0f, (float) window->getWidth(), 0.0f, (float) window->getHeight(), -1.0f, 1.0f);
}

MEMOENGINE_API Camera2D::~Camera2D() {}

MEMOENGINE_API void Camera2D::update()
{
	view = glm::translate(Matrix(1.0f), -pos);
}