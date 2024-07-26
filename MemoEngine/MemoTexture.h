#pragma once

#ifdef MEMOENGINE_EXPORTS
#define MEMOENGINE_API __declspec(dllexport)
#else
#define MEMOENGINE_API __declspec(dllimport)
#endif

#include <GL/glew.h>
#include <stb_image.h>

class Texture
{
public:
	MEMOENGINE_API Texture(std::string filename);
	MEMOENGINE_API ~Texture();

	MEMOENGINE_API void setNew(std::string filename);
	MEMOENGINE_API void bind(int slot) const;

private:
	GLuint id;
	unsigned char* pixels;
	int width;
	int height;
	int channels;
};