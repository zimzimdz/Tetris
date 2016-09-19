#include "Board.h"

//-------------------------------------------------------------------------------
Board::Board()
{
	for (int i = 0; i < BOARD_WIDTH; ++i)
	{
		for (int j = 0; j < BOARD_HEIGHT; ++j)
		{
			area[i][j] = FREE;
		}
	}
}

//-------------------------------------------------------------------------------
void Board::Flood(int posX, int j, int px, int py, int kind, int orientation, int value, bool visited[MATRIX_SIZE][MATRIX_SIZE])
{
	if(px < 0 || px >= MATRIX_SIZE || py < 0 || py >= MATRIX_SIZE || visited[px][py] || PIECES[kind][orientation][px][py] == FREE)
	{
		return;
	}
 
  visited[px][py] = true;
	if(posX >= 0) area[j][posX] = value;
    
	Flood(posX, j - 1, px, py - 1, kind, orientation, value, visited);
	Flood(posX + 1, j, px + 1, py, kind, orientation, value, visited);
	Flood(posX, j + 1, px, py + 1, kind, orientation, value, visited);
	Flood(posX - 1, j, px - 1, py, kind, orientation, value, visited);
}
 
//-------------------------------------------------------------------------------
void Board::Flood(int posX, int j, int px, int py, int kind, int orientation, bool& flag, bool visited[MATRIX_SIZE][MATRIX_SIZE])
{
	if (px < 0 || px >= MATRIX_SIZE || py < 0 || py >= MATRIX_SIZE || visited[px][py] || PIECES[kind][orientation][px][py] == FREE)
	{
		return;
	}

  visited[px][py] = true;

  if(posX < 0 || posX >= BOARD_HEIGHT || j < 0 || j >= BOARD_WIDTH || area[j][i] != FREE )
  {
      flag = false;
      return;
  }

  Flood(i, j - 1, px, py - 1, kind, orientation, flag, visited);
  Flood(i + 1, j, px + 1, py, kind, orientation, flag, visited);
  Flood(i, j + 1, px, py + 1, kind, orientation, flag, visited);
  Flood(i - 1, j, px - 1, py, kind, orientation, flag, visited);
}
 
//-------------------------------------------------------------------------------
void Board::FloodFill(int i, int j, int px, int py, int kind, int orientation, int value)
{
	bool visited[MATRIX_SIZE][MATRIX_SIZE];

	for (int l = 0; l < MATRIX_SIZE; ++l)
	{
		for (int m = 0; m < MATRIX_SIZE; ++m)
		{
			visited[l][m] = false;
		}
	}
	Flood(i, j, px, py, kind, orientation, value, visited);
}
 
//-------------------------------------------------------------------------------
void Board::DrawPiece(Piece& piece)
{
    const int posX = piece.GetPosX();
    const int posY = piece.GetPosY();

    const int kind = piece.GetKind();
    const int orientation = piece.GetOrientation();
 
    switch(kind)
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
 
    FloodFill(posX, posY, PIVOT_X, PIVOT_Y, kind, orientation, piece.GetColor());
}
 
//-------------------------------------------------------------------------------
void Board::ClearPiece(const Piece& piece)
{
    const int posX = piece.GetPosX();
    const int posY = piece.GetPosY();
		const int kind = piece.GetKind();
		const int orientation = piece.GetOrientation();
 
		FloodFill(posX, posY, PIVOT_X, PIVOT_Y, kind, orientation, FREE);
}
 
//-------------------------------------------------------------------------------
void Board::NewPiece(const Piece& piece)
{ 
	m_currentPiece.SetColor(piece.GetColor());
	m_currentPiece.SetKind(piece.GetKind());
	m_currentPiece.SetOrientation(piece.GetOrientation());
	m_currentPiece.SetPosX(ORIGIN_X);
	m_currentPiece.SetPosY(ORIGIN_Y);
	DrawPiece(m_currentPiece);
}
 
//-------------------------------------------------------------------------------
bool Board::IsCurrentPieceMovable(int x, int y)
{
	ClearPiece(m_currentPiece);

	bool movable = true;
	bool visited[MATRIX_SIZE][MATRIX_SIZE];
	for (int l = 0; l < MATRIX_SIZE; ++l)
	{
		for (int m = 0; m < MATRIX_SIZE; ++m)
		{
			visited[l][m] = false;
		}
	}
		
	const int kind = m_currentPiece.GetKind();
	const int orientation = m_currentPiece.GetOrientation();

	Flood(x, y, PIVOT_X, PIVOT_Y, kind, orientation, movable, visited);

	DrawPiece(m_currentPiece);

	return movable;
}
 
//-------------------------------------------------------------------------------
bool Board::IsCurrentPieceRotable(int orientation)
{
	ClearPiece(m_currentPiece);
 
  bool rotable = true;
  bool visited[MATRIX_SIZE][MATRIX_SIZE];
 
	for (int i = 0; i < MATRIX_SIZE; ++i)
	{
		for (int j = 0; j < MATRIX_SIZE; ++j)
		{
			visited[i][j] = false;
		}
	}
 
	const int kind = m_currentPiece.GetKind();
 
	Flood(m_currentPiece.GetPosX(), m_currentPiece.GetPosY(), PIVOT_X, PIVOT_Y, kind, orientation, rotable, visited); 
	DrawPiece(m_currentPiece);
  return rotable;
}
 
//-------------------------------------------------------------------------------
void Board::MoveCurrentPieceDown()
{
	const int posX = m_currentPiece.GetPosX();
	const int posY = m_currentPiece.GetPosY();
 
	if (IsCurrentPieceMovable(posX + 1, posY))
  {
		ClearPiece(m_currentPiece);
		m_currentPiece.SetPosX(posX + 1);
		DrawPiece(m_currentPiece);
  }
}
 
//-------------------------------------------------------------------------------
void Board::MoveCurrentPieceLeft()
{
	const int posX = m_currentPiece.GetPosX();
	const int posY = m_currentPiece.GetPosY();
 
	if (IsCurrentPieceMovable(posX, posY - 1))
	{
		ClearPiece(m_currentPiece);
		m_currentPiece.SetPosY(posY - 1);
		DrawPiece(m_currentPiece);
	}
}
 
//-------------------------------------------------------------------------------
void Board::MoveCurrentPieceRight()
{
	const int posX = m_currentPiece.GetPosX();
	const int posY = m_currentPiece.GetPosY();
 
	if (IsCurrentPieceMovable(posX, posY + 1))
	{
		ClearPiece(m_currentPiece);
		m_currentPiece.SetPosY(posY + 1);
		DrawPiece(m_currentPiece);
	}
}
 
//-------------------------------------------------------------------------------
void Board::RotateCurrentPieceLeft()
{
	int orientation = m_currentPiece.GetOrientation();
	orientation = orientation > 0 ? orientation-- : NB_ROTATIONS - 1;
	
	if (IsCurrentPieceRotable(orientation))
	{
		ClearPiece(m_currentPiece);
		m_currentPiece.SetOrientation(orientation);
		DrawPiece(m_currentPiece);
	}
}
 
//-------------------------------------------------------------------------------
void Board::RotateCurrentPieceRight()
{
  int orientation = m_currentPiece.GetOrientation();
	orientation = orientation < NB_ROTATIONS - 1 ? orientation++ : 0;
	
  if(IsCurrentPieceRotable(orientation))
  {
		ClearPiece(m_currentPiece);
		m_currentPiece.SetOrientation(orientation);
		DrawPiece(m_currentPiece);
  }
}
 
//-------------------------------------------------------------------------------
void Board::DeleteLine(int line)
{
	ClearPiece(m_currentPiece);

	for (int j = line; j > 0; --j)
	{
		for (int i = 0; i < BOARD_WIDTH; ++i)
		{
			area[i][j] = area[i][j - 1];
		}
	}
	DrawPiece(m_currentPiece);
}
 
//-------------------------------------------------------------------------------
int Board::DeletePossibleLines()
{
    int nbLinesDeleted = 0;
 
    for(int j = 0; j < BOARD_HEIGHT; ++j)
    {
        int i = 0;
        for(; i < BOARD_WIDTH && area[i][j] != FREE; ++i);
        if(i == BOARD_WIDTH)
        {
            nbLinesDeleted++;
            DeleteLine(j);
        }
    }
 
    return nbLinesDeleted;
}
 
//-------------------------------------------------------------------------------
void Board::DropCurrentPiece()
{
	int x = m_currentPiece.GetPosX();
	const int y = m_currentPiece.GetPosY();

	while (IsCurrentPieceMovable(x++, y))
	{
		MoveCurrentPieceDown();
	}
}
 
//-------------------------------------------------------------------------------
bool Board::IsCurrentPieceFallen()
{
	const int posX = m_currentPiece.GetPosX();
	const int posY = m_currentPiece.GetPosY();
	return !IsCurrentPieceMovable(posX + 1, posX);
}
 
//-------------------------------------------------------------------------------
bool Board::IsGameOver() const
{
  for(int i = 0; i < BOARD_WIDTH; ++i)
  {
		if (area[i][0] != FREE)
		{
			return true;
		}
  }
  return false;
}
 
//-------------------------------------------------------------------------------
void Board::Clear()
{
  for(int i = 0; i < BOARD_WIDTH; ++i)
  {
		for (int j = 0; j < BOARD_HEIGHT; ++j)
		{
			area[i][j] = FREE;
		}
  }
}

//-------------------------------------------------------------------------------
void Board::SetCurrentPiece(const Piece& piece)
{
	m_currentPiece = piece;
}

//-------------------------------------------------------------------------------
const Piece& Board::GetCurrentPiece() const
{
	return m_currentPiece;
}
