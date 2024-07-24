#pragma once

#ifdef MEMOENGINE_EXPORTS
#define MEMOENGINE_API __declspec(dllexport)
#else
#define MEMOENGINE_API __declspec(dllimport)
#endif

#include <iostream>

#include "MemoWindow.h"
#include "IMemoGame.h"
#include "MemoInput.h"