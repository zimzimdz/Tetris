/* piece.h */
#ifndef PIECE_H
#define PIECE_H
 
#include "shape.h"
 
enum { CYAN = 1, BLUE, ORANGE, YELLOW, GREEN, PURPLE, RED, GHOST }; // Les couleurs de chaque pièce, GHOST est pour la pièce fantôme
enum { I, J, L, O, S, T, Z};
 
/* Les coordonnées du point de pivot de la pièce */
const int PIVOT_X = 1;
const int PIVOT_Y = 2;
 
class Piece
{
public:
    Piece();
    Piece(int k, int o);
    Piece(const Piece &p);
 
    void setKind(int k);
    void setOrientation(int o);
 
    int getKind();
    int getOrientation();
 
    void setColor(int c);
    int getColor();
 
    void setPosX(int x);
    int getPosX();
 
    void setPosY(int y);
    int getPosY();
private:
    int kind; // Piece kind
    int orientation; // Orientation
    int color; // Color
 
    int posX; // X line
    int posY; // Y column
 
};
 
#endif

