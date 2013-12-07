#pragma once

#include <SFML/Graphics.hpp>
class FPSManager
{
public:
	FPSManager(void);
	~FPSManager(void);
	int ffps(void);				// time ellapsed
	void Init();
private:
	sf::Clock clock;
};

