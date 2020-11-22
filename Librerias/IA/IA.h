#ifndef CHESS_UCSP_IA_H
#define CHESS_UCSP_IA_H
#endif

#include "../minMax/minMax.h"
#include "../gameboard/gameboard.h"

// start[2], slots[26][26], width, height, bearings[][2], length,
// accumulated, difficulty, deep, A
int intelligence(
	Piece[26][26], int, int,
	int[2], int[][2], int,
	int, int, int, bool);
