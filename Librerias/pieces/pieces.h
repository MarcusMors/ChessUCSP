#ifndef CHESS_UCSP_PIECES_H
#define CHESS_UCSP_PIECES_H
#endif
#include "../helpers/helpers.h"
#include "../enums/enums.h"

int P1_score = 0;
int P2_score = 0;
class Piece
{
public:
	char symbol;
	bool isFree;
	bool player;
	int points;
	int movements = 0;
	int enemyMenacing = 0;
	int playerMenacing = 0;
	int winPotential = 0;  // Lo que se puede ganar si se mueve a una posición.
	int lostPotential = 0; // Lo que se puede perder si no se defiende una posición

	Piece() {}
	Piece(char, bool, bool, int);
	void moveTo(int[2]);
	void setFree();
	void setPiece(Piece);
	// bool inCheck();
	// void eat(Piece);
	// void capture(Piece);
protected:
private:
};
