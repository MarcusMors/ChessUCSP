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
	int playerBearings[][3], int playerLength,
	int playerPickableBearings[][3], int playerPickableLength,
	int enemyBearings[][2], int enemyLength,
	int enemyPickableBearings[][3], int enemyPickableLength,
	int accumulated, int difficulty, int deep, bool A)
{
	if (A)
	{
		if (deep == difficulty || playerPickableLength == 0)
		{
			return accumulated;
		}
		else if (playerPickableLength == 1)
		{
			return accumulated + slots[playerPickableBearings[0][0]][playerPickableBearings[0][1]].points;
		}

		int branches[playerPickableLength];
		int auxPiece[3];
		int auxEnd[2];
		int auxLength;

		for (int i = 0; i < playerPickableLength; i++)
		{
			auxLength = 0;
			int auxPlayerPickableBearings[playerPickablelength][2];

			//auxStart == Player Piece
			auxPiece[0] = playerPickableBearings[i][0];
			auxPiece[1] = playerPickableBearings[i][1];
			auxPiece[2] = playerPickableBearings[i][2];
			for (int j = 0; j < enemyPickableLength; j++)
			{
				if (j != i)
				{
					switch (char(auxPiece[2]))
					{
					case PiecesChar::charP1_king:
						break;
					case PiecesChar::charP1_queen:
						break;
					case PiecesChar::charP1_knight:
						break;
					case PiecesChar::charP1_rook:
						break;
					case PiecesChar::charP1_bishop:
						break;
					case PiecesChar::charP1_pawn:
						break;
					default:
						break;
					}
					if ()
					{
						// Availables slots and Pieces
						auxEnd[0] = slots[j][0];
						auxEnd[1] = slots[j][1];
					}
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
