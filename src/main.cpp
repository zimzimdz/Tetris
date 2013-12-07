
#include<windows.h>
#include "Game.h"


int WINAPI WinMain(HINSTANCE instance, HINSTANCE pInstance, PSTR pScmdline, int iCmdshow) {

	Game* game;
	game = 0;

	game = new Game();
	if(!game) return 0;

	if(game->Init()) game->Run();

	game->ShutDown();
	delete game;
	game=0;
	return 0;

}