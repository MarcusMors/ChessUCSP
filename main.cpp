#include <iostream>
#include "Librerias/Tablero/Tablero.h"
#include "libs/pieces.h"

using namespace std;

int Game()
{
	// Gameboard gameboard[1];
	King king[1];
	Queen queen[1];
	Rook rook[2];
	Knight knight[2];
	Bishop bishop[2];
	Pawn pawns[8];
}

int main()
{
	char m[8][8] = {{'t', 'c', 'a', 'q', 'r', 'a', 'c', 't'},
					{'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
					{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
					{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
					{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
					{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
					{'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
					{'T', 'C', 'A', 'R', 'Q', 'A', 'C', 'T'}};
	tablero(m);
	while (true)
	{
		cambio(m, ' ', 0, ' ', 0);
	}
}
