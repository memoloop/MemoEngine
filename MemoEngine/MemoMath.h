#pragma once

#ifdef MEMOENGINE_EXPORTS
#define MEMOENGINE_API __declspec(dllexport)
#else
#define MEMOENGINE_API __declspec(dllimport)
#endif

class Vector2D
{
public:
	float x;
	float y;

	MEMOENGINE_API Vector2D(float x, float y);
};

class Vector3D
{
public:
	float x;
	float y;
	float z;

	MEMOENGINE_API Vector3D(float x, float y, float z);
};

class Vector4D
{
public:
	float x;
	float y;
	float z;
	float w;

	MEMOENGINE_API Vector4D(float x, float y, float z, float w);
};