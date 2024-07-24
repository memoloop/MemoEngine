#pragma once

#ifdef MEMOENGINE_EXPORTS
#define MEMOENGINE_API __declspec(dllexport)
#else
#define MEMOENGINE_API __declspec(dllimport)
#endif

class Vector2D
{
public:
	int x;
	int y;

	MEMOENGINE_API Vector2D(int x, int y);
};