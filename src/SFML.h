#pragma once

#include <SFML/Graphics.hpp>
#include <sstream>
#include <string>
#include <Windows.h>
#include "GameEngine.h"
#include "GraphicEngine.h"
#include "Shape.h"

const std::string IMG_EMPTY = "Image/empty.png";
const std::string IMG_GREEN = "Image/green.png";
const std::string IMG_YELLOW = "Image/yellow.png";
const std::string IMG_PINK = "Image/pink.png";
const std::string IMG_BLUE = "Image/blue.png";
const std::string IMG_ORANGE = "Image/orange.png";
const std::string IMG_CYAN = "Image/cyan.png";
const std::string IMG_RED = "Image/red.png";
const std::string IMG_VIOLET = "Image/violet.png";
const std::string IMG_MENU = "Image/menu.png";
class SFML
{
public:
	bool Init(HWND boardWindow,HWND menuWindow, HWND nextWindow);
	void Clear();
	bool Render(GameEngine* engine);
	void Display();

private:
	sf::RenderWindow boardView;
	sf::RenderWindow menuView;
	sf::RenderWindow nextView;
	sf::Texture menuTexture;
	sf::Texture emptyTexture;
	sf::Texture redTexture;
	sf::Texture blueTexture;
	sf::Texture cyanTexture;
	sf::Texture pinkTexture;
	sf::Texture violetTexture;
	sf::Texture orangeTexture;
	sf::Texture yellowTexture;
	sf::Texture greenTexture;

	sf::Font font;
	sf::Text text;
	sf::Text nextText;
	sf::Text scoreText;
};

