/* piece.h */
#ifndef PIECE_H
#define PIECE_H
 
#include "Shape.h"
 
enum { CYAN = 1, BLUE, ORANGE, YELLOW, GREEN, PURPLE, RED, GHOST }; // Piece colors
enum { I, J, L, O, S, T, Z};
 
/* Piece pivot coordinates */
const int PIVOT_X = 1;
const int PIVOT_Y = 2;
 
class Piece
{
public:
	Piece() = default;
  Piece(int kind, int orientation);
  Piece(const Piece& p);
 
  void SetKind(int kind);
  void SetOrientation(int orientation);
 
  int GetKind() const;
  int GetOrientation() const;
 
  void SetColor(int color);
  int GetColor() const;
 
  void SetPosX(int x);
  int GetPosX() const;
 
  void SetPosY(int y);
  int GetPosY() const;

private:
  int kind; // Piece kind
  int orientation; // Orientation
  int color; // Color
 
  int posX; // X line
  int posY; // Y column
};
 
#endif

