/* piece.cpp */
#include "Piece.h"
 
Piece::Piece(int kind, int orientation)
{
    kind = kind;
    orientation = orientation;
}
 
Piece::Piece(const Piece& piece)
{
	kind = piece.kind;
	orientation = piece.orientation;
	color = piece.color;
	posX = piece.posX;
	posY = piece.posY;
}
 
void Piece::SetKind(int _kind)
{
	kind = _kind;
}
 
void Piece::SetOrientation(int _orientation)
{
	orientation = _orientation;
}
 
int Piece::GetKind() const
{
	return kind;
}
 
int Piece::GetOrientation() const
{
	return orientation;
}
 
void Piece::SetColor(int _color)
{
	color = _color;
}
 
int Piece::GetColor() const
{
    return color;
}
 
void Piece::SetPosX(int x)
{
	posX = x;
}
 
int Piece::GetPosX() const
{
	return posX;
}
 
void Piece::SetPosY(int y)
{
	posY = y;
}
 
int Piece::GetPosY() const
{
	return posY;
}
