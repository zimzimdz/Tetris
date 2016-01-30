#include "GraphicEngine.h"

GraphicEngine::~GraphicEngine()
{
	Shutdown();
}

bool GraphicEngine::Init(int& width, int& height, HWND hwnd, Game* game, GameEngine* gengine)
{	
	m_pEngine = gengine;
	mainWindow = hwnd;
	DWORD Style = WS_CHILD | WS_CLIPSIBLINGS | WS_VISIBLE;
	boardWindow = CreateWindow("STATIC", NULL, Style, 0,0, SPRITE_WIDTH*10, SPRITE_WIDTH*20, mainWindow, NULL, game->GetAppInstance(), NULL);
	menuWindow = CreateWindow("STATIC", NULL, Style, SPRITE_WIDTH*10,0, MENU_WIDTH, SPRITE_WIDTH*20, mainWindow, NULL, game->GetAppInstance(), NULL);
	nextWindow = CreateWindow("STATIC", NULL, Style, 5,40, SPRITE_WIDTH*4, (SPRITE_WIDTH*4), menuWindow, NULL, game->GetAppInstance(), NULL);
	m_pSfml = new SFML();
	return m_pSfml->Init(boardWindow,menuWindow,nextWindow);
}

bool GraphicEngine::Frame()
{
	return Render();
}

void GraphicEngine::Shutdown()
{
	delete(m_pSfml);
	m_pSfml = nullptr;
	m_pEngine = nullptr;
}

bool GraphicEngine::Render()
{
	m_pSfml->Clear();
	m_pSfml->Render(m_pEngine);
	m_pSfml->Display();
	return true;
}
