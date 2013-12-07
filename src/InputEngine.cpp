#include "InputEngine.h"


InputEngine::InputEngine(void)
{
}


InputEngine::~InputEngine(void)
{
}

void InputEngine::Init()
{
	// Initialize all the keys to being released and not pressed.
	for(unsigned int i=0; i<256; i++)
	{
		m_keys[i] = false;
	}

}

void InputEngine::KeyUp(unsigned int key)
{
	// If a key is pressed then save that state in the key array.

	m_keys[key] = false;
}

void InputEngine::KeyDown(unsigned int key)
{
	// If a key is pressed then save that state in the key array.
	 m_keys[key] = true;


}

bool InputEngine::IsKeyDown(unsigned int key)
{

	return m_keys[key];
}
