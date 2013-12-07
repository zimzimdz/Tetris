#pragma once

#include <Windows.h>
const int LEFT = VK_LEFT;
const int RIGHT = VK_RIGHT;
const int Q = 0x51;
const int D = 0x44;
const int SPACE = VK_SPACE;

class InputEngine
{
public:
	InputEngine(void);
	~InputEngine(void);

	void Init();
	void KeyDown(unsigned int);
	void KeyUp(unsigned int);

	bool IsKeyDown(unsigned int);

private:
	bool m_keys[256];

};

