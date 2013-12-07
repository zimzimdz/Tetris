#pragma once
#include <SFML/Audio.hpp>
#include <string>

const std::string SOUND_AMBIANT = "Sound/salsa.wav";
const std::string SOUND_FLIP = "Sound/flip.wav";
const std::string SOUND_KICK = "Sound/kick.wav";
class SoundEngine
{
public:
	SoundEngine(void);
	~SoundEngine(void);
	bool Init();
	void PlayAmbiance();
	void StopAmbiant();
	void PlayFlip();
	void PlayKick();
private:
	sf::SoundBuffer bufferAmbiant;
	sf::SoundBuffer bufferFlip;
	sf::SoundBuffer bufferKick;
	sf::Sound ambiant;
	sf::Sound flip;
	sf::Sound kick;
};

