#include "SoundEngine.h"


SoundEngine::SoundEngine(void)
{
}


SoundEngine::~SoundEngine(void)
{
}

bool SoundEngine::Init(){
	if (!bufferAmbiant.loadFromFile(SOUND_AMBIANT)) return false;
	if (!bufferFlip.loadFromFile(SOUND_FLIP)) return false;
	if (!bufferKick.loadFromFile(SOUND_KICK)) return false;

	return true;
}

void SoundEngine::PlayAmbiance()
{
	ambiant.setBuffer(bufferAmbiant);
	ambiant.setLoop(true);
	ambiant.play();
}

void SoundEngine::StopAmbiant()
{
	ambiant.stop();
}

void SoundEngine::PlayFlip()
{
	flip.setBuffer(bufferFlip);
	flip.play();
}

void SoundEngine::PlayKick()
{
	kick.setBuffer(bufferKick);
	kick.play();
}
