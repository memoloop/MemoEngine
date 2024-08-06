#pragma once

#ifdef MEMOENGINE_EXPORTS
#define MEMOENGINE_API __declspec(dllexport)
#else
#define MEMOENGINE_API __declspec(dllimport)
#endif

#include <GL/glew.h>
#include <stb_image.h>
#include <vector>
#include "MemoMath.h"

class Texture
{
public:
	float x = 0;
	float y = 0;
	float width = 0;
	float height = 0;

	MEMOENGINE_API Texture(std::string filename);
	MEMOENGINE_API Texture(std::string filename, Rect rect);

	MEMOENGINE_API ~Texture();

	MEMOENGINE_API void bind(int slot) const;

	MEMOENGINE_API int getImageWidth();
	MEMOENGINE_API int getImageHeight();

private:
	GLuint id;
	unsigned char* pixels;
	int imageWidth;
	int imageHeight;
	int channels;
};

class Spritesheet
{
public:
	MEMOENGINE_API static std::vector<Texture*> create(std::string filename, int rows, int columns);
};