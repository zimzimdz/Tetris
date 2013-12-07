#pragma once

#include "Board.h"
#include <iostream>
#include <random>
class GameEngine
{
public:
	GameEngine(void);
	~GameEngine(void);

	Board* GetBoard();
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
	bool IsGameOver();
	Piece Next();
	inline int GetScore(){return score;}
	inline Piece GetNextPiece(){return next;}
private:
	Board* board;
	int score;
	Piece next;

};

