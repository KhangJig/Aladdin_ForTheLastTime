#include "Sound.h"
Sound *Sound::__instance = NULL;


Sound::~Sound()
{

}

bool Sound::Init_DirectSound(HWND hwnd)
{
	this->hwnd = hwnd;
	this->dsound = NULL;
	HRESULT result;

	dsound = new GSoundManager();

	result = dsound->Initialize(hwnd, DSSCL_PRIORITY);

	if (result != DS_OK)
	{

		return false;
	}

	result = dsound->SetPrimaryBufferFormat(2, 22050, 16);

	if (result != DS_OK)
	{
		return false;
	}
	return true;
}

GSound* Sound::LoadSound(LPTSTR filename)
{
	HRESULT result;

	GSound *wave;

	result = dsound->Create(&wave, filename);

	if (result != DS_OK)
	{
		return NULL;
	}

	return wave;
}

void Sound::PlaySound(GSound *sound)
{
	sound->Play();
}

void Sound::LoopSound(GSound *sound)
{
	sound->Play(0, DSBPLAY_LOOPING);
}

void Sound::StopSound(GSound *sound)
{
	sound->Stop();
}

Sound *Sound::GetInstance()
{
	if (__instance == NULL) __instance = new Sound();
	return __instance;
}