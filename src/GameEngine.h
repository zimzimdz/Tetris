#pragma once

#include "Board.h"
#include <iostream>
#include <random>

class GameEngine
{
public:
	Board* GetBoard() const;
	void Init();
	void NewPiece();
	bool StepForward();
	void MoveLeft();
	void MoveRight();
	void RotateLeft();
	void RotateRight();
	void Drop();
	void Clear();
	int CheckLines();
	bool IsGameOver() const;
	Piece Next();

	inline int GetScore() const {return m_score;}
	inline const Piece& GetNextPiece() const {return m_nextPiece;}

private:
	Board* m_pBoard{nullptr};
	int m_score{0};
	Piece m_nextPiece;

};

