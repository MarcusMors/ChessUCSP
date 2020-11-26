// #ifndef CHESS_UCSP_IA_H
// #define CHESS_UCSP_IA_H
// #endif

#pragma once

#include "../minMax/minMax.h"
#include "../gameboard/gameboard.h"

using namespace std;

bool reachable(int piece[2], int end[2], char symbol)
{
	int x = end[0] - piece[0];
	int y = abs((end[1] - piece[1]));
	return ((x >= 0) && (x >= y)) ? true : false;
}

int intelligence(
	Piece slots[26][26], int width, int height,
	int playerBearings[][2], int playerLength,
	int playerPickableBearings[][2], int playerPickableLength,
	int enemyBearings[][2], int enemyLength,
	int enemyPickableBearings[][2], int enemyPickableLength,
	int piece[2], int accumulated, int difficulty, int deep, bool A)
{
	if (A)
	{
		if (deep == difficulty || playerPickableBearings == 0)
		{
			return accumulated;
		}
		else if (playerPickableLength == 1)
		{
			return accumulated + slots[playerPickableBearings[0][0]][playerPickableBearings[0][0]].points;
		}

		int branches[length];
		int auxPiece[2];
		int auxEnd[2];
		int auxLength;

		for (int i = 0; i < playerPickableBearingsLength; i++)
		{
			auxLength = 0;
			int auxPlayerPickableBearings[length][2];

			//auxStart == Player Piece
			auxPiece[0] = playerPickableBearings[i][0];
			auxPiece[1] = playerPickableBearings[i][1];

			for (int j = 0; j < enemyBearingsLength; j++)
			{
				if (j != i)
				{
					// Availables slots and Pieces
					auxEnd[0] = slots[j][0];
					auxEnd[1] = slots[j][1];

					if (reachable(auxPiece, auxEnd, ' '))
					{
						auxPlayerPickableBearings[auxLength][2] = slots[j][2];
						auxLength++;
					}
				}
			}
			deep++;
			branches[i] = intelligence(
				slots, width, height,
				auxPiece, auxPlayerPickableBearings, auxLength,
				accumulated, difficulty, deep, (!A))
		}

		if (A)
		{
			A = !A;
			return max(branches, length);
		}
		else
		{
			A = !A;
			return min(branches, length);
		}
	}
	else
	{
	}
}
