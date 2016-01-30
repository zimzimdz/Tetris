#include "GameEngine.h"

void GameEngine::Init()
{
	m_pBoard = new Board();
	m_nextPiece = Next();
}

void GameEngine::Clear()
{
	m_pBoard->Clear();
	m_nextPiece = Next();
	m_score = 0;
}

Board* GameEngine::GetBoard() const
{
	return m_pBoard;
}

void GameEngine::NewPiece()
{	
	m_pBoard->NewPiece(m_nextPiece);
	m_nextPiece = Next();
}

Piece GameEngine::Next()
{
	std::random_device rd; // obtain a random number from hardware
    std::mt19937 eng(rd()); // seed the generator
    std::uniform_int_distribution<> distrKind(0, 6); // define the range
	std::uniform_int_distribution<> distrOrientation(0, 3);
	Piece piece = Piece(distrKind(eng), distrOrientation(eng));

	int kind = piece.GetKind();
	switch (kind)
	{
		case I:
			piece.SetColor(CYAN);
			break;
		case J:
			piece.SetColor(BLUE);
			break;
		case L:
			piece.SetColor(ORANGE);
			break;
		case O:
			piece.SetColor(YELLOW);
			break;
		case S:
			piece.SetColor(GREEN);
			break;
		case T:
			piece.SetColor(PURPLE);
			break;
		case Z:
			piece.SetColor(RED);
			break;
		default:
			break;
	}
	return piece;
}

bool GameEngine::StepForward()
{
	if (m_pBoard->IsCurrentPieceMovable(m_pBoard->GetCurrentPiece().GetPosX() + 1, m_pBoard->GetCurrentPiece().GetPosY()))
	{
		m_pBoard->MoveCurrentPieceDown();
	}
	else
	{		
		if (m_pBoard->IsGameOver())
		{
			return false;
		}
		NewPiece();
	}
	return true;
}

int GameEngine::CheckLines()
{
	const int deletedLines = m_pBoard->DeletePossibleLines();
	m_score += deletedLines;
	return deletedLines;
}

void GameEngine::MoveLeft()
{
	m_pBoard->MoveCurrentPieceLeft();
}

void GameEngine::MoveRight()
{
	m_pBoard->MoveCurrentPieceRight();
}

void GameEngine::RotateRight()
{
	m_pBoard->RotateCurrentPieceRight();
}

void GameEngine::RotateLeft()
{
	m_pBoard->RotateCurrentPieceLeft();
}

void GameEngine::Drop()
{
	m_pBoard->DropCurrentPiece();
}

bool GameEngine::IsGameOver() const
{
	return m_pBoard->IsGameOver();
}