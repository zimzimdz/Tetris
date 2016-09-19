/* board.h */
#ifndef BOARD_H
#define BOARD_H
 
#include "Piece.h"
 
enum  { FREE, FILLED };
 
const int BOARD_HEIGHT = 20;
const int BOARD_WIDTH = 10;
 
const int ORIGIN_X = 0;
const int ORIGIN_Y = 5;
 
class Board
{
public:
	int area[BOARD_WIDTH][BOARD_HEIGHT];

	Board();

	void SetCurrentPiece(const Piece& piece);
	const Piece& GetCurrentPiece() const;

	void DrawPiece(Piece& piece);
	void ClearPiece(const Piece& piece);

	void NewPiece(const Piece& p);

	bool IsCurrentPieceMovable(int x, int y);
	bool IsCurrentPieceRotable(int orientation);

	void MoveCurrentPieceDown();
	void MoveCurrentPieceLeft();
	void MoveCurrentPieceRight();

	void RotateCurrentPieceLeft();
	void RotateCurrentPieceRight();

	void DeleteLine(int line);
	int DeletePossibleLines();

	void DropCurrentPiece();
	bool IsCurrentPieceFallen();

	void Clear();
	bool IsGameOver() const;

private:
	Piece m_currentPiece;
	Piece m_ghostPiece;

	void Flood(int posX, int posY, int pivotX, int pivotY, int kind, int orientation, int value, bool visited[][MATRIX_SIZE]);
	void Flood(int posX, int posY, int pivotX, int pivotY, int kind, int orientation, bool &flag, bool visited[][MATRIX_SIZE]);
	void FloodFill(int posX, int posY, int pivotX, int pivotY, int kind, int orientation, int value);
};
 
#endif

