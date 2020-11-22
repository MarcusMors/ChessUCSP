#include <iostream>
#include "IA.h"

using namespace std;

bool reachable(int start[2], int end[2], char symbol)
{
	int x = end[0] - start[0];
	int y = abs((end[1] - start[1]));
	return ((x >= 0) && (x >= y)) ? true : false;
}

int intelligence(
	Piece slots[26][26], int width, int height,
	int start[2], int bearings[][2], int length,
	int accumulated, int difficulty, int deep, bool A)
{
	// A = (A == true)? intelligence A : intelligence B;
	if (deep == difficulty || length == 0)
	{
		return accumulated;
	}
	else if (length == 1)
	{
		return accumulated + slots[bearings[0][0]][bearings[0][1]].points;
	}

	int arr[length];
	int auxStart[2];
	int auxEnd[2];
	int auxLength;

	for (int i = 0; i < length; i++)
	{
		auxLength = 0;
		int auxBearings[length][2];

		//auxStart == Bot Piece
		auxStart[0] = slots[i][0];
		auxStart[1] = slots[i][1];

		for (int j = 0; j < length; j++)
		{
			if (j != i)
			{
				// Availables slots and Pieces
				auxEnd[0] = slots[j][0];
				auxEnd[1] = slots[j][1];

				if (reachable(auxStart, auxEnd, ' '))
				{
					auxBearings[auxLength][2] = slots[j][2];
					auxLength++;
				}
			}
		}
		deep++;
		arr[i] = intelligence(
			slots, width, height,
			auxStart, auxBearings, auxLength,
			accumulated, difficulty, deep, (!A))
	}

	if (A)
	{
		A = !A;
		return max(arr, length);
	}
	else
	{
		A = !A;
		return min(arr, length);
	}
}
