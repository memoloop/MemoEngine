#include "pch.h"
#include "MemoInput.h"

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