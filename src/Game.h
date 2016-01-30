#pragma once

#define WIN32_LEAN_AND_MEAN

#include<Windows.h>
#include "GraphicEngine.h"
#include "InputEngine.h"
#include "GameEngine.h"
#include "FPSManager.h"
#include "InputTimer.h"
#include "SoundEngine.h"


class GraphicEngine;

const int STEP_TIME=200;
class Game
{
public:
	Game(void);
	~Game(void);
	

	bool Init();
	void Run();
	void ShutDown();
	HINSTANCE GetAppInstance();

	LRESULT CALLBACK MessageHandler(HWND, UINT, WPARAM, LPARAM);
	
private:
	LPCSTR appName;
	HINSTANCE instance;
	HWND mainWindow;

	GraphicEngine* graphic;
	InputEngine* input;
	GameEngine* gameEngine;
	SoundEngine* soundEngine;
	FPSManager* fps;
	InputTimer* timer;

	int GameOver();
	bool Frame();
	bool InitWindow(int& height, int& width); 
	void ShutDownWindows();
};

static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
static Game* game=0;


