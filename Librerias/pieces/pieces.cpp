#include "pieces.h"

Piece::Piece() {}
Piece::Piece(char iSymbol, bool iIsFree, bool iPlayer, int iPoints)
{
	symbol = iSymbol;
	isFree = iIsFree;
	if (isFree = false)
	{
		player = iPlayer; // P1 = TRUE
	}
	points = iPoints;
}
void Piece::moveTo(int place[2])
{
	movements++;
}
void Piece::setFree()
{
	symbol = PiecesChar::char_free;
	isFree = true;
	points = 0;
	movements = 0;
	playerMenacing++;
}
void Piece::setPiece(Piece piece)
{
	symbol = piece.symbol;
	isFree = false;
	player = piece.player;
	points = piece.points;
	movements += piece.movements;
	playerMenacing--;
}
