#include "pch.h"
#include "MemoAudioManager.h"

// ------------ AUDIO MANAGER --------------
// Initialize OpenAL

ALCdevice* AudioManager::device = nullptr;
ALCcontext* AudioManager::context = nullptr;

MEMOENGINE_API void AudioManager::init()
{
	// Open audio device
	device = alcOpenDevice(nullptr);
	if (!device) 
	{
		std::cerr << "Unable to open audio device!" << std::endl;
		std::exit(-1);
	}

	// Create context
	context = alcCreateContext(device, nullptr);
	if (!context || !alcMakeContextCurrent(context))
	{
		std::cerr << "Unable to create audio context!";
		if (context) alcDestroyContext(context);
		alcCloseDevice(device);
		std::exit(-1);
	}

}

MEMOENGINE_API void AudioManager::destroy()
{
	alcMakeContextCurrent(nullptr);
	alcDestroyContext(context);
	alcCloseDevice(device);
}

// ---------------- AUDIO -------------------
// Play audio

MEMOENGINE_API Audio::Audio(std::string filename)
{
	// Load file audio
	SF_INFO sfInfo;
	SNDFILE* sndfile = sf_open(filename.c_str(), SFM_READ, &sfInfo);
	if (!sndfile) 
	{
		std::cerr << "Unable to open file audio: " << filename << std::endl;
		std::exit(-1);
	}

	// Audio format
	if (sfInfo.channels == 1)
	{
		format = AL_FORMAT_MONO16;
	}
	else if (sfInfo.channels == 2)
	{
		format = AL_FORMAT_STEREO16;
	}
	else
	{
		std::cerr << "Number of channels not supported" << std::endl;
		sf_close(sndfile);
		std::exit(-1);
	}

	freq = sfInfo.samplerate;
	audioBuffer.resize(sfInfo.frames * sfInfo.channels);
	sf_read_short(sndfile, audioBuffer.data(), audioBuffer.size());

	sf_close(sndfile);

	// Generate buffer audio
	alGenBuffers(1, &buffer);
	alBufferData(buffer, format, audioBuffer.data(), (ALsizei)(audioBuffer.size() * sizeof(short)), freq);

	// Create audio source
	alGenSources(1, &source);
	alSourcei(source, AL_BUFFER, buffer);

}

MEMOENGINE_API Audio::~Audio()
{
	alDeleteBuffers(1, &buffer);
	alDeleteSources(1, &source);
}

MEMOENGINE_API bool Audio::play()
{
	alSourcei(source, AL_BUFFER, buffer);
	alSourcePlay(source);
	ALint state;
	alGetSourcei(source, AL_SOURCE_STATE, &state);
	if (state == AL_PLAYING)
	{
		return true;
	}
}

MEMOENGINE_API void Audio::stop()
{
	isStopped = true;
	if(isStopped)
		alSourceStop(source);
}

MEMOENGINE_API void Audio::pause() 
{
	alSourcePause(source);
}

MEMOENGINE_API void Audio::resume()
{
	alSourcePlay(source);
}