#include "SFML.h"
#include <iostream>

SFML::SFML(void)
{
	
}


SFML::~SFML(void)
{

}

bool SFML::Init(HWND boardWindow, HWND menuWindow, HWND nextWindow)
{
	boardView.create(boardWindow);
	menuView.create(menuWindow);
	nextView.create(nextWindow);
	
	if (!emptyTexture.loadFromFile(IMG_EMPTY, sf::IntRect(0, 0, 24, 24))) return false;
	if (!orangeTexture.loadFromFile(IMG_ORANGE, sf::IntRect(0, 0, 24, 24))) return false;
	if (!redTexture.loadFromFile(IMG_RED, sf::IntRect(0, 0, 24, 24))) return false;
	if (!greenTexture.loadFromFile(IMG_GREEN, sf::IntRect(0, 0, 24, 24))) return false;
	if (!yellowTexture.loadFromFile(IMG_YELLOW, sf::IntRect(0, 0, 24, 24))) return false;
	if (!pinkTexture.loadFromFile(IMG_PINK, sf::IntRect(0, 0, 24, 24))) return false;
	if (!blueTexture.loadFromFile(IMG_BLUE, sf::IntRect(0, 0, 24, 24))) return false;
	if (!cyanTexture.loadFromFile(IMG_CYAN, sf::IntRect(0, 0, 24, 24))) return false;
	if (!violetTexture.loadFromFile(IMG_VIOLET, sf::IntRect(0, 0, 24, 24))) return false;
	if (!menuTexture.loadFromFile(IMG_MENU, sf::IntRect(0, 0, MENU_WIDTH, SPRITE_WIDTH*20))) return false;
	if (!font.loadFromFile("Font/Pacifico.ttf")) return false;
	nextText.setFont(font);
	nextText.setString("Next");
	nextText.setCharacterSize(20);
	nextText.setColor(sf::Color::White);

	scoreText.setFont(font);
	scoreText.setString("Score");
	scoreText.setCharacterSize(20);
	scoreText.setColor(sf::Color::White);

	return true;

}

void SFML::Clear()
{
	boardView.clear();
	menuView.clear();
	nextView.clear();
}

bool SFML::Render(GameEngine* engine)
{
	std::ostringstream os;
	for(unsigned int i=0; i<BOARD_WIDTH; i++){
		for(unsigned int j=0; j<BOARD_HEIGHT; j++){
			sf::Sprite sprite;
			if(engine->GetBoard()->area[i][j] == FREE)sprite.setTexture(emptyTexture);
			if(engine->GetBoard()->area[i][j] == CYAN)sprite.setTexture(cyanTexture);
			if(engine->GetBoard()->area[i][j] == BLUE)sprite.setTexture(blueTexture);
			if(engine->GetBoard()->area[i][j] == ORANGE)sprite.setTexture(orangeTexture);
			if(engine->GetBoard()->area[i][j] == YELLOW)sprite.setTexture(yellowTexture);
			if(engine->GetBoard()->area[i][j] == PURPLE)sprite.setTexture(violetTexture);
			if(engine->GetBoard()->area[i][j] == GREEN)sprite.setTexture(greenTexture);
			if(engine->GetBoard()->area[i][j] == RED)sprite.setTexture(redTexture);
			
			sprite.setPosition(i*SPRITE_WIDTH,j*SPRITE_HEIGHT);
			boardView.draw(sprite);
		}
	}
	
	sf::Sprite menu;
	menu.setTexture(menuTexture);
	menu.setPosition(0,0);
	menuView.draw(menu);
	nextText.setPosition(30,5);
	menuView.draw(nextText);
	for(unsigned int i=0; i<MATRIX_SIZE; i++){
		for(unsigned int j=0; j<MATRIX_SIZE; j++){
			sf::Sprite sprite;
			if(PIECES[engine->GetNextPiece().getKind()][engine->GetNextPiece().getOrientation()][i][j] != FREE
				&& engine->GetNextPiece().getColor() == CYAN)sprite.setTexture(cyanTexture);
			else if(PIECES[engine->GetNextPiece().getKind()][engine->GetNextPiece().getOrientation()][i][j] != FREE
				&& engine->GetNextPiece().getColor() == BLUE)sprite.setTexture(blueTexture);
			else if(PIECES[engine->GetNextPiece().getKind()][engine->GetNextPiece().getOrientation()][i][j] != FREE
				&& engine->GetNextPiece().getColor() == ORANGE)sprite.setTexture(orangeTexture);
			else if(PIECES[engine->GetNextPiece().getKind()][engine->GetNextPiece().getOrientation()][i][j] != FREE
				&& engine->GetNextPiece().getColor() == YELLOW)sprite.setTexture(yellowTexture);
			else if(PIECES[engine->GetNextPiece().getKind()][engine->GetNextPiece().getOrientation()][i][j] != FREE
				&& engine->GetNextPiece().getColor() == PURPLE)sprite.setTexture(violetTexture);
			else if(PIECES[engine->GetNextPiece().getKind()][engine->GetNextPiece().getOrientation()][i][j] != FREE
				&& engine->GetNextPiece().getColor() == GREEN)sprite.setTexture(greenTexture);
			else if(PIECES[engine->GetNextPiece().getKind()][engine->GetNextPiece().getOrientation()][i][j] != FREE
				&& engine->GetNextPiece().getColor() == RED)sprite.setTexture(redTexture);
			else sprite.setTexture(emptyTexture);
			sprite.setPosition(j*SPRITE_WIDTH,(i*SPRITE_HEIGHT));
			nextView.draw(sprite);
		}
	}

	os<<engine->GetScore();
	scoreText.setString("Score: "+os.str());
	scoreText.setPosition(20,SPRITE_WIDTH*7);
	menuView.draw(scoreText);
	
	return true;
}

void SFML::Display()
{
	boardView.display();
	nextView.display();
	menuView.display();
}