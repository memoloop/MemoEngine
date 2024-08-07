#pragma once

#ifdef MEMOENGINE_EXPORTS
#define MEMOENGINE_API __declspec(dllexport)
#else
#define MEMOENGINE_API __declspec(dllimport)
#endif

#include <vector>
#include <AL/al.h>
#include <AL/alc.h>
#include <sndfile.h>

class AudioManager
{
public:
	static ALCdevice* device;
	static ALCcontext* context;

	MEMOENGINE_API static void init();
	MEMOENGINE_API static void destroy();
};

class Audio
{
public:
	MEMOENGINE_API Audio(std::string filename);
	MEMOENGINE_API ~Audio();

	MEMOENGINE_API bool play();
	MEMOENGINE_API void stop();

private:
	std::vector<short> audioBuffer; // contains file audio
	ALenum format;
	ALsizei freq;
	ALuint buffer; // it's openal buffer
	ALuint source;
};