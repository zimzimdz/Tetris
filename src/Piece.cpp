/* piece.cpp */
#include "Piece.h"

void Piece::SetKind(int kind)
{
	m_kind = kind;
}
 
void Piece::SetOrientation(int orientation)
{
	m_orientation = orientation;
}
 
int Piece::GetKind() const
{
	return m_kind;
}
 
int Piece::GetOrientation() const
{
	return m_orientation;
}
 
void Piece::SetColor(int color)
{
	m_color = color;
}
 
int Piece::GetColor() const
{
    return m_color;
}
 
void Piece::SetPosX(int posX)
{
	m_posX = posX;
}
 
int Piece::GetPosX() const
{
	return m_posX;
}
 
void Piece::SetPosY(int posY)
{
	m_posY = posY;
}
 
int Piece::GetPosY() const
{
	return m_posY;
}
