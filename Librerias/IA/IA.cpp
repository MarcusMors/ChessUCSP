#include <iostream>

using namespace std;

bool reachable(int start[2], int end[2], char symbol)
{
	int x = end[0] - start[0];
	int y = abs((end[1] - start[1]));
	return ((x >= 0) && (x >= y)) ? true : false;
}

int intelligence(int start[2], int bearingsPoints[][3] = {0}, int length = 0, int accumulated = 0, int difficulty = 3, int deep = 0, bool A = true)
{
	// A = true = IA A
	// A = false = IA B
	if (deep == difficulty)
	{
		return accumulated;
	}
	// if (length == 0)
	// {
	// 	return accumulated;
	// }
	else if (length == 1)
	{
		return accumulated + bearingsPoints[0][2];
	}
	int arr[length];
	int auxStart[2];
	int auxEnd[2];
	int counter;

	for (int i = 0; i < length; i++)
	{
		counter = 0;
		int auxLength = (length);
		int auxBearingsPoints[auxLength][3];

		//auxStart == Bot Piece
		auxStart[0] = bearingsPoints[i][0];
		auxStart[1] = bearingsPoints[i][1];

		for (int j = 0; j < auxLength; j++)
		{
			if (j != i)
			{
				// Availables slots and Pieces
				auxEnd[0] = bearingsPoints[j][0];
				auxEnd[1] = bearingsPoints[j][1];

				if (reachable(auxStart, auxEnd))
				{
					auxBearingsPoints[counter][2] = bearingsPoints[j][2];
					counter++;
				}
			}
		}
		deep++;
		arr[i] = intelligence(auxStart, auxBearingsPoints, counter, accumulated + bearingsPoints[i][2], difficulty, deep, (!A));
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
