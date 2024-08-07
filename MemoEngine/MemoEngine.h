#pragma once

#ifdef MEMOENGINE_EXPORTS
#define MEMOENGINE_API __declspec(dllexport)
#else
#define MEMOENGINE_API __declspec(dllimport)
#endif

#include "MemoWindow.h"
#include "IMemoGame.h"
#include "MemoInput.h"
#include "MemoMath.h"
#include "MemoGraphic.h"
#include "MemoShader.h"
#include "MemoCamera.h"
#include "MemoTexture.h"
#include "MemoGameObject.h"
#include "MemoAudioManager.h"