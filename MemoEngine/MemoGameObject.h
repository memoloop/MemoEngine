#pragma once

#ifdef MEMOENGINE_EXPORTS
#define MEMOENGINE_API __declspec(dllexport)
#else
#define MEMOENGINE_API __declspec(dllimport)
#endif

#include "IMemoGame.h"
#include "MemoGraphic.h"
#include "MemoShader.h"
#include "MemoCamera.h"
#include "MemoMath.h"
#include "MemoTexture.h"

class Sprite
{
public:
	float x;
	float y;
	float width;
	float height;

	RGBAColor color = { 1, 1, 1, 1 };

	MEMOENGINE_API Sprite(Camera2D* camera, float x, float y, float width, float height);
	MEMOENGINE_API virtual ~Sprite();
	
	MEMOENGINE_API virtual void draw();

protected:
	Shape* shape;
	Shader* shader;
	Camera2D* camera;

	float scaleX;
	float scaleY;
};

class TexturedSprite : public Sprite
{
public:
	MEMOENGINE_API TexturedSprite(Camera2D* camera, float x, float y, float width, float height, Texture* texture);
	MEMOENGINE_API ~TexturedSprite() override;

	MEMOENGINE_API void draw() override;

	Texture* texture;
};