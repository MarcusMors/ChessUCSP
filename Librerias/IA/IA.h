#include <iostream>

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
	int playerPickableBearings[][2], inr playerPickableBearings,
	int enemyBearings[][2], int enemyLength,
	int enemyPickableBearings[][2], inr enemyPickableBearings,
	int piece[2], int accumulated, int difficulty, int deep, bool A)
{

	// A = (A == true)? intelligence A : intelligence B;

	int *playerBearings_ptr;
	int *playerLength_ptr;
	int *playerPickableBearings_ptr;
	int *playerPickableLength_ptr;
	int *enemyBearings_ptr;
	int *enemyLength_ptr;
	int *enemyPickableBearings_ptr;
	int *enemyPickableLength_ptr;

	if (A)
	{
		playerBearings_ptr = playerBearings;
		playerLength_ptr = playerLength;
		playerPickableBearings_ptr = playerPickableBearings;
		playerPickableLength_ptr = playerPickableLength;
		enemyBearings_ptr = enemyBearings;
		enemyLength_ptr = enemyLength;
		enemyPickableBearings_ptr = enemyPickableBearings;
		enemyPickableLength_ptr = enemyPickableLength;
	}
	else
	{
		playerBearings_ptr = enemyBearings;
		playerLength_ptr = enemyLength;
		playerPickableBearings_ptr = enemyPickableBearings;
		playerPickableLength_ptr = enemyPickableLength;
		enemyBearings_ptr = playerBearings;
		enemyLength_ptr = playerLength;
		enemyPickableBearings_ptr = playerPickableBearings;
		enemyPickableLength_ptr = playerPickableLength;
	}

	if (deep == difficulty || playerPickableBearings_ptr == 0)
	{
		return accumulated;
	}
	else if (playerPickableLength_ptr == 1)
	{
		return accumulated + slots[playerPickableBearings_ptr[0][0]][playerPickableBearings_ptr[0][0]].points;
	}

	int branches[length];
	int auxPiece[2];
	int auxEnd[2];
	int auxLength;

	for (int i = 0; i < playerPickableBearingsLength_ptr; i++)
	{
		auxLength = 0;
		int auxPlayerPickableBearings[length][2];

		//auxStart == Player Piece
		auxPiece[0] = playerPickableBearings_ptr[i][0];
		auxPiece[1] = playerPickableBearings_ptr[i][1];

		for (int j = 0; j < enemyBearingsLength_ptr; j++)
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
