#include "pch.h"
#include "MemoGameObject.h"

// -------------- SPRITE --------------
// It's a sprite without a texture, but it has only a color

MEMOENGINE_API Sprite::Sprite(Camera2D* camera, float x, float y, float width, float height)
{
	this->camera = camera;
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;

	this->scaleX = width;
	this->scaleY = height;

	float vertices[12] = {
		this->x, this->y, 0,
		this->x + this->width, this->y, 0,
		this->x + this->width, this->y + this->height, 0,
		this->x, this->y + this->height, 0
	};

	int indices[6] = {
		0, 1, 2,
		2, 3, 0
	};

	shape = new Shape(vertices, sizeof(vertices), indices, sizeof(indices));
	shader = new Shader("simple");
}

MEMOENGINE_API Sprite::~Sprite()
{
	delete shader;
	delete shape;
}

MEMOENGINE_API void Sprite::draw()
{
	shader->useProgram();
	shader->setUniform("position", new Vector2D(x, y));
	shader->setUniform("scale", new Vector2D(1/scaleX*width, 1/scaleY*height));
	shader->setUniform("color", new Vector4D(color.red, color.green, color.blue, color.alpha));
	shader->setUniform("model", camera->model);
	shader->setUniform("projection", camera->projection);
	shader->setUniform("view", camera->view);
	shape->draw();
}

// --------- TEXTURED SPRITE -----------
// It's a sprite with a texture

MEMOENGINE_API TexturedSprite::TexturedSprite(Camera2D* camera, float x, float y, float width, float height, Texture* texture) :
	Sprite(camera, x, y, width, height)
{
	this->texture = texture;

	float vertices[12] = {
		this->x, this->y, 0,
		this->x + this->width, this->y, 0,
		this->x + this->width, this->y + this->height, 0,
		this->x, this->y + this->height, 0
	};

	float textures[8] = {
		0, 0,
		1, 0,
		1, 1,
		0, 1
	};

	int indices[6] = {
		0, 1, 2,
		2, 3, 0
	};

	shape = new Shape(vertices, sizeof(vertices), textures, sizeof(textures), indices, sizeof(indices));
	shader = new Shader("texture");
}

MEMOENGINE_API TexturedSprite::~TexturedSprite()
{
	delete texture;
}

MEMOENGINE_API void TexturedSprite::draw()
{
	shader->useProgram();
	texture->bind(0);
	shader->setUniform("position", new Vector2D(x, y));
	shader->setUniform("scale", new Vector2D(1 / scaleX * width, 1 / scaleY * height));
	shader->setUniform("color", new Vector4D(color.red, color.green, color.blue, color.alpha));
	shader->setUniform("model", camera->model);
	shader->setUniform("projection", camera->projection);
	shader->setUniform("view", camera->view);
	shape->draw();
}