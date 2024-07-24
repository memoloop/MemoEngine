#pragma once

#ifdef MEMOENGINE_EXPORTS
#define MEMOENGINE_API __declspec(dllexport)
#else
#define MEMOENGINE_API __declspec(dllimport)
#endif

class IGame
{
public:
	MEMOENGINE_API virtual void init() = 0;
	MEMOENGINE_API virtual void update() = 0;
	MEMOENGINE_API virtual void draw() = 0;
	MEMOENGINE_API virtual void cleanUp() = 0;
	MEMOENGINE_API virtual ~IGame() {}
};

