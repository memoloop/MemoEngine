#include "pch.h"
#include "MemoMath.h"

MEMOENGINE_API Vector2D::Vector2D(float x, float y)
{
	this->x = x;
	this->y = y;
}

MEMOENGINE_API Vector3D::Vector3D(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

MEMOENGINE_API Vector4D::Vector4D(float x, float y, float z, float w)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}