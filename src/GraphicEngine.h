#pragma once

#include <Windows.h>
#include "Game.h"
#include "GameEngine.h"
#include "SFML.h"

class Game;
class GameEngine;
class SFML;

const int TIME_DROP = 1;
const int MENU_WIDTH = 110;
const int SPRITE_HEIGHT = 24;
const int SPRITE_WIDTH = 24;
const bool FULL_SCREEN = false;

class GraphicEngine
{
public:
	GraphicEngine() = default;
	virtual ~GraphicEngine();

	bool Init(int& width, int& height, HWND hwnd, Game* pGame, GameEngine* pEngine);
	bool Frame();
	void Shutdown();

private:
	HWND mainWindow;
	HWND boardWindow;
	HWND menuWindow;
	HWND nextWindow;

	SFML* m_pSfml;
	GameEngine* m_pEngine;

	bool Render();
};

