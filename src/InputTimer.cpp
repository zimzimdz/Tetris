#include "InputTimer.h"


InputTimer::InputTimer(void)
{
	ellapsed = 0;
}


InputTimer::~InputTimer(void)
{
}

void InputTimer::Init()
{
	ellapsed = 0;
}

void InputTimer::Start()
{
	clock.restart();
}

int InputTimer::GetEllapsed()
{
	
	Update();
	return ellapsed;
}

void InputTimer::Update()
{
	ellapsed = clock.getElapsedTime().asMilliseconds();
	if(ellapsed > 150) ellapsed = 0;
}
