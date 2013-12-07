#include "GameEngine.h"


GameEngine::GameEngine(void)
{
}


GameEngine::~GameEngine(void)
{
	board = 0;
}

void GameEngine::Init()
{
	board = new Board();
	next = Next();
	score = 0;

}

void GameEngine::Clear()
{
	board->clear();
	next = Next();
	score = 0;
}

Board* GameEngine::GetBoard()
{
	return board;
}

void GameEngine::NewPiece()
{
	
	board->newPiece(next);
	next = Next();
}

Piece GameEngine::Next()
{
	Piece p;
	std::random_device rd; // obtain a random number from hardware
    std::mt19937 eng(rd()); // seed the generator
    std::uniform_int_distribution<> distrKind(0, 6); // define the range
	std::uniform_int_distribution<> distrOrientation(0, 3);
	p = Piece(distrKind(eng),distrOrientation(eng));

	int k = p.getKind(); 
    switch(k)
    {
        case I:
            p.setColor(CYAN);
            break;
        case J:
            p.setColor(BLUE);
            break;
        case L:
            p.setColor(ORANGE);
            break;
        case O:
            p.setColor(YELLOW);
            break;
        case S:
            p.setColor(GREEN);
            break;
        case T:
            p.setColor(PURPLE);
            break;
        case Z:
            p.setColor(RED);
            break;
        default:
            break;
    }
	return p;
}

bool GameEngine::StepForward()
{
	if(board->isCurrentPieceMovable(board->getCurrentPiece().getPosX()+1,board->getCurrentPiece().getPosY())) board->moveCurrentPieceDown();
	else{
		
		if(board->isGameOver()) return false;
		NewPiece();

	}
	return true;
}

int GameEngine::CheckLines()
{
	int i = board->deletePossibleLines();
	score+=i;
	return i;
}

void GameEngine::MoveLeft()
{
	board->moveCurrentPieceLeft();
}

void GameEngine::MoveRight()
{
	board->moveCurrentPieceRight();
}

void GameEngine::RotateRight()
{
	board->rotateCurrentPieceRight();
}

void GameEngine::RotateLeft()
{
	board->rotateCurrentPieceLeft();
}

void GameEngine::Drop()
{
	board->dropCurrentPiece();
}

bool GameEngine::IsGameOver(){
	return board->isGameOver();
}