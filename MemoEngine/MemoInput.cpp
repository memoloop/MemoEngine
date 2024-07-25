#include "pch.h"
#include "MemoInput.h"

MEMOENGINE_API void Mouse::setPosition(Window* window, float x, float y)
{
	glfwSetCursorPos(window->getID(), (double) x, (double) y);
}

MEMOENGINE_API Vector2D* Mouse::getPosition(Window* window)
{
	double x;
	double y;

	glfwGetCursorPos(window->getID(), &x, &y);

	return new Vector2D((float) x, (float) y);
}

MEMOENGINE_API bool Input::getKeyDown(Window* window, int key)
{
	if (glfwGetKey(window->getID(), key) == GLFW_PRESS)
	{
		return true;
	}
	else
	{
		return false;
	}
}

MEMOENGINE_API bool Input::getKeyUp(Window* window, int key)
{
	if (glfwGetKey(window->getID(), key) == GLFW_RELEASE)
	{
		return true;
	}
	else
	{
		return false;
	}
}

MEMOENGINE_API bool Input::getMouseButtonDown(Window* window, int mouseButton)
{
	if (glfwGetMouseButton(window->getID(), mouseButton) == GLFW_PRESS)
	{
		return true;
	}
	else 
	{
		return false;
	}
}

MEMOENGINE_API bool Input::getMouseButtonUp(Window* window, int mouseButton)
{
	if (glfwGetMouseButton(window->getID(), mouseButton) == GLFW_RELEASE)
	{
		return true;
	}
	else
	{
		return false;
	}
}