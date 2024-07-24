#pragma once

#ifdef MEMOENGINE_EXPORTS
#define MEMOENGINE_API __declspec(dllexport)
#else
#define MEMOENGINE_API __declspec(dllimport)
#endif

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "IMemoGame.h"

class Window
{
public:
	MEMOENGINE_API Window(IGame* game, int width, int height, std::string title);
	MEMOENGINE_API ~Window();

	MEMOENGINE_API void run();

	MEMOENGINE_API void setWidth(int width);
	MEMOENGINE_API int getWidth();

	MEMOENGINE_API void setHeight(int height);
	MEMOENGINE_API int getHeight();

	MEMOENGINE_API void setTitle(std::string title);
	MEMOENGINE_API std::string getTitle();

	MEMOENGINE_API GLFWwindow* getID();

private:
	IGame* game;
	int width;
	int height;
	std::string title;

	GLFWwindow* id;
};

