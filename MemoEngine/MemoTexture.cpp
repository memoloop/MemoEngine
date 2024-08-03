#include "pch.h"
#define STB_IMAGE_IMPLEMENTATION
#include "MemoTexture.h"

MEMOENGINE_API Texture::Texture(std::string filename)
{
	// Load image file
	pixels = stbi_load(filename.c_str(), &width, &height, &channels, 4);
	if (pixels == nullptr)
	{
		std::cerr << "Unable to load image: " << stbi_failure_reason() << std::endl;
		std::exit(-1);
	}

	// Create OpenGL texture
	glGenTextures(1, &id);
	glBindTexture(GL_TEXTURE_2D, id);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
	glGenerateMipmap(GL_TEXTURE_2D);

	// Unbind texture and delete pixels
	// Now pixels is in texture data
	glBindTexture(GL_TEXTURE_2D, 0);
	stbi_image_free(pixels);
}

MEMOENGINE_API Texture::~Texture()
{
	// Delete texture id
	glDeleteTextures(1, &id);
}

MEMOENGINE_API void Texture::bind(int slot) const
{
	glActiveTexture(GL_TEXTURE0+slot);
	glBindTexture(GL_TEXTURE_2D, id);
}