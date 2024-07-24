#pragma once

#ifdef MEMOENGINE_EXPORTS
#define MEMOENGINE_API __declspec(dllexport)
#else
#define MEMOENGINE_API __declspec(dllimport)
#endif

#include <GLFW/glfw3.h>
#include "MemoWindow.h"
#include "MemoMath.h"

// Get mouse position
class Mouse
{
public:
	MEMOENGINE_API void setPosition(Window* window, int x, int y);
	MEMOENGINE_API Vector2D* getPosition(Window* window);
};

class Input
{
public:
	// Keyboard events
	MEMOENGINE_API static bool getKeyDown(Window* window, int key);
	MEMOENGINE_API static bool getKeyUp(Window* window, int key);

	// Mouse events
	MEMOENGINE_API static bool getMouseButtonDown(Window* window, int mouseButton);
	MEMOENGINE_API static bool getMouseButtonUp(Window* window, int mouseButton);
};