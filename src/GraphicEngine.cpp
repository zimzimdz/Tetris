#include "GraphicEngine.h"


GraphicEngine::GraphicEngine(void)
{
}


GraphicEngine::~GraphicEngine(void)
{
	Shutdown();
}

bool GraphicEngine::Init(int& width, int& height, HWND hwnd, Game* game, GameEngine* gengine)
{	
	engine = gengine;
	mainWindow = hwnd;
	DWORD Style = WS_CHILD | WS_CLIPSIBLINGS | WS_VISIBLE;
	boardWindow = CreateWindow(L"STATIC", NULL, Style, 0,0, SPRITE_WIDTH*10, SPRITE_WIDTH*20, mainWindow, NULL, game->GetAppInstance(), NULL);
	menuWindow = CreateWindow(L"STATIC", NULL, Style, SPRITE_WIDTH*10,0, MENU_WIDTH, SPRITE_WIDTH*20, mainWindow, NULL, game->GetAppInstance(), NULL);
	nextWindow = CreateWindow(L"STATIC", NULL, Style, 5,40, SPRITE_WIDTH*4, (SPRITE_WIDTH*4), menuWindow, NULL, game->GetAppInstance(), NULL);
	sfml = new SFML();
	return sfml->Init(boardWindow,menuWindow,nextWindow);
}

bool GraphicEngine::Frame()
{
	if(Render()) return true;
	else return false;
}

void GraphicEngine::Shutdown()
{
	delete(sfml);
	sfml = 0;
	engine = 0;
}

bool GraphicEngine::Render()
{
	sfml->Clear();
	sfml->Render(engine);
	sfml->Display();
	return true;
}
