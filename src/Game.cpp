#include "Game.h"
#include <cstdio>
#include <winuser.h>

Game::Game(void)
{
	input=0;
	graphic=0;
	gameEngine = 0;
	soundEngine = 0;
	fps=0;
}


Game::~Game(void)
{
}

bool Game::Init()
{
	int x=0;
	int y=0;
	if(!InitWindow(y,x)) return false;

	input = new InputEngine();
	if(!input) return false;
	input->Init();

	gameEngine = new GameEngine();
	if(!gameEngine) return false;
	gameEngine->Init();

	graphic = new GraphicEngine();
	if(!graphic) return false;
	if(!graphic->Init(x,y,mainWindow,game,gameEngine)) return false;

	fps = new FPSManager();
	if(!fps) return false;

	timer = new InputTimer();
	if(!timer) return false;

	soundEngine = new SoundEngine();
	if(!soundEngine) return false;
	if(!soundEngine->Init()) return false;

	

	return true;
}

bool Game::InitWindow(int& height, int& width){
	WNDCLASSEX wc;
	DEVMODE dmScreenSettings;
	int posX, posY;

	instance = GetModuleHandle(NULL);
	game = this;
	appName = "Tetris by Zimzim";

	// Setup the windows class with default settings.
	wc.style         = 0;
	wc.lpfnWndProc   = WndProc;
	wc.cbClsExtra    = 0;
	wc.cbWndExtra    = 0;
	wc.hInstance     = instance;
	wc.hIcon		 = LoadIcon(NULL, IDI_WINLOGO);
	wc.hIconSm       = wc.hIcon;
	wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = reinterpret_cast<HBRUSH>(COLOR_BACKGROUND);
	wc.lpszMenuName  = NULL;
	wc.lpszClassName = appName;
	wc.cbSize        = sizeof(WNDCLASSEX);
	
	// Register the window class.
	RegisterClassEx(&wc);

	// Determine the resolution of the clients desktop screen.
	width  = GetSystemMetrics(SM_CXSCREEN);
	height = GetSystemMetrics(SM_CYSCREEN);

	// Setup the screen settings depending on whether it is running in full screen or in windowed mode.
	if(FULL_SCREEN)
	{
		// If full screen set the screen to maximum size of the users desktop and 32bit.
		memset(&dmScreenSettings, 0, sizeof(dmScreenSettings));
		dmScreenSettings.dmSize       = sizeof(dmScreenSettings);
		dmScreenSettings.dmPelsWidth  = (unsigned long)width;
		dmScreenSettings.dmPelsHeight = (unsigned long)height;
		dmScreenSettings.dmBitsPerPel = 32;			
		dmScreenSettings.dmFields     = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;

		// Change the display settings to full screen.
		ChangeDisplaySettings(&dmScreenSettings, CDS_FULLSCREEN);

		// Set the position of the window to the top left corner.
		posX = posY = 0;
	}
	else
	{
		// If windowed then set it to 800x600 resolution.
		width  =  SPRITE_WIDTH*10+MENU_WIDTH;
		height = (SPRITE_WIDTH*20)+28;

		// Place the window in the middle of the screen.
		posX = (GetSystemMetrics(SM_CXSCREEN) - width)  / 2;
		posY = (GetSystemMetrics(SM_CYSCREEN) - height) / 2;
	}

	// Create the window with the screen settings and get the handle to it.
	mainWindow = CreateWindowEx(WS_EX_APPWINDOW, appName, appName, 
						  WS_SYSMENU | WS_VISIBLE,
						    posX, posY, width, height, NULL, NULL, instance, NULL);
	if(!mainWindow) return false;

	// Bring the window up on the screen and set it as main focus.
	ShowWindow(mainWindow, SW_SHOW);
	SetForegroundWindow(mainWindow);
	SetFocus(mainWindow);


	return true;
}

void Game::Run(){
	MSG msg;
	bool done, result, gameOver;

	// Initialize the message structure.
	SecureZeroMemory(&msg, sizeof(MSG));


	// Loop until there is a quit message from the window or the user.
	done = false;
	gameOver = false;
	gameEngine->NewPiece();
	soundEngine->PlayAmbiance();
	while(!done)
	{
		// Handle the windows messages.
		if(PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		// If windows signals to end the application then exit out.
		if(msg.message == WM_QUIT)
		{
			done = true;
		}
		else
		{
			if(!gameOver) {
				int j =  timer->GetEllapsed();
				if(input->IsKeyDown(VK_DOWN) && j == 0) {
					timer->Start();
					if(!gameEngine->StepForward()) gameOver = true;
				}
				if(input->IsKeyDown(VK_LEFT) && j == 0) {
					timer->Start();
					gameEngine->MoveLeft();
				}
				if(input->IsKeyDown(VK_RIGHT) && j == 0) {
					timer->Start();
					gameEngine->MoveRight();
				}
				if(input->IsKeyDown(Q) && j == 0) {
					timer->Start();
					soundEngine->PlayFlip();
					gameEngine->RotateLeft();
				}
				if(input->IsKeyDown(D) && j == 0) {
					timer->Start();
					soundEngine->PlayFlip();
					gameEngine->RotateRight();
				}
				if(input->IsKeyDown(SPACE) && j == 0) {
					timer->Start();
					gameEngine->Drop();
				}
				float currentTime = fps->ffps();
				if(currentTime > STEP_TIME){
					fps->Init();
					if(!gameEngine->StepForward()) gameOver = true;
					else {
						if(gameEngine->CheckLines() > 0) soundEngine->PlayKick();
					}
				}
				result = Frame();
				if(!result) done = true;
			}
			else {
				soundEngine->StopAmbiant();
				if(GameOver()) done = true;
				else {
					gameOver = false;
					soundEngine->PlayAmbiance();
					gameEngine->Init();
					gameEngine->NewPiece();
				}
			}

					
		}

	}
}

int Game::GameOver()
{
    int msgboxID = MessageBox(
        NULL,
        (LPCSTR)"You loose.\nDo you want to try again?",
        (LPCSTR)"GameOver",
        MB_ICONWARNING | MB_OKCANCEL
    );

    switch (msgboxID)
    {
    case IDOK:
        return false;
        break;
    case IDCANCEL:
       return true;
        break;
	}

    return msgboxID;

}
void Game::ShutDown(){

	if(input) delete input;
	if(graphic) delete graphic;
	if(gameEngine) delete gameEngine;
	if(soundEngine) delete soundEngine;

	input = 0;
	graphic = 0;
	gameEngine = 0;
	soundEngine = 0;
	graphic = 0;

	ShutDownWindows();
}

void Game::ShutDownWindows()
{
	// Fix the display settings if leaving full screen mode.
	if(FULL_SCREEN)
	{
		ChangeDisplaySettings(NULL, 0);
	}

	// Remove the window.
	DestroyWindow(mainWindow);
	mainWindow = 0;

	// Remove the application instance.
	UnregisterClass(appName, instance);
	instance = 0;

	// Release the pointer to this class.
	game = 0;
}


bool Game::Frame(){
	bool result;
	// Check if the user pressed escape and wants to exit the application.
	if(input->IsKeyDown(VK_ESCAPE)) return false;
	


	// Do the frame processing for the graphics object.
	result = graphic->Frame();
	if(!result)
	{
		return false;
	}

	return true;
}

HINSTANCE Game::GetAppInstance()
{
	return instance;
}

LRESULT CALLBACK Game::MessageHandler(HWND hwnd, UINT umsg, WPARAM wparam, LPARAM lparam)
{
	switch(umsg)
	{
		// Check if a key has been pressed on the keyboard.
		case WM_KEYDOWN:
		{
			// If a key is pressed send it to the input object so it can record that state.
			input->KeyDown((unsigned int)wparam);
			
			return 0;
		}

		// Check if a key has been released on the keyboard.
		case WM_KEYUP:
		{
			// If a key is released then send it to the input object so it can unset the state for that key.
			input->KeyUp((unsigned int)wparam);
			return 0;
		}

	

		// Any other messages send to the default message handler as our application won't make use of them.
		default:
		{
			return DefWindowProc(hwnd, umsg, wparam, lparam);
		}
	}
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT umessage, WPARAM wparam, LPARAM lparam)
{
	switch(umessage)
	{
		// Check if the window is being destroyed.
		case WM_DESTROY:
		{
			PostQuitMessage(0);
			return 0;
		}

		// Check if the window is being closed.
		case WM_CLOSE:
		{
			PostQuitMessage(0);		
			return 0;
		}

		// All other messages pass to the message handler in the system class.
		default:
		{
			return game->MessageHandler(hwnd, umessage, wparam, lparam);
		}
	}
}


