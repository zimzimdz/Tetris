/* piece.h */
#ifndef PIECE_H
#define PIECE_H
 
#include "Shape.h"
#include <xutility>
 
enum { CYAN = 1, BLUE, ORANGE, YELLOW, GREEN, PURPLE, RED, GHOST }; // Piece colors
enum { I, J, L, O, S, T, Z};
 
/* Piece pivot coordinates */
const int PIVOT_X = 1;
const int PIVOT_Y = 2;
 
class Piece
{
public:
	Piece() = default;
	Piece(int kind, int orientation)
		: m_kind(std::move(kind))
		, m_orientation(std::move(orientation))
	{}
 
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
	int m_kind{ 0 }; // Piece kind
	int m_orientation{ 0 }; // Orientation
	int m_color{ CYAN }; // Color
 
	int m_posX{ PIVOT_X }; // X line
	int m_posY{ PIVOT_Y }; // Y column
};
 
#endif

