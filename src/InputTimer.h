#pragma once
#include <SFML/Graphics.hpp>
class InputTimer
{
public:
	InputTimer(void);
	~InputTimer(void);
	void Init();
	void Start();
	int GetEllapsed();
	void Update();

private:
	sf::Clock clock;
	int ellapsed;
};

