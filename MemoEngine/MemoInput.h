#pragma once

#ifdef MEMOENGINE_EXPORTS
#define MEMOENGINE_API __declspec(dllexport)
#else
#define MEMOENGINE_API __declspec(dllimport)
#endif

#include <GLFW/glfw3.h>
#include "MemoWindow.h"

class Input
{
public:
	MEMOENGINE_API static bool getKeyDown(Window* window, int key);
	MEMOENGINE_API static bool getKeyUp(Window* window, int key);
};