#include <iostream>
#include "../gameboard/gameboard.h"

using namespace std;

bool reachable(long long start[2], long long end[2])
{
	long long x = end[0] - start[0];
	long long y = abs((end[1] - start[1]));
	return ((x >= 0) && (x >= y)) ? true : false;
}

long long intelligence(long long start[2], long long bearingsPoints[][3] = {0}, long long length = 0, long long accumulated = 0, int difficult = 3, int deep = 0, int AorB = true)
{
	// AorB = true = IA A
	// AorB = false = IA B
	if (deep == difficult)
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
	long long arr[length];
	long long auxStart[2];
	long long auxEnd[2];
	long long counter;

	for (long long i = 0; i < length; i++)
	{
		counter = 0;
		long long auxLength = (length);
		long long auxBearingsPoints[auxLength][3];

		//auxStart == Bot Piece
		auxStart[0] = bearingsPoints[i][0];
		auxStart[1] = bearingsPoints[i][1];

		for (long long j = 0; j < auxLength; j++)
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
		arr[i] = intelligence(auxStart, auxBearingsPoints, counter, accumulated + bearingsPoints[i][2], difficult, deep, (!AorB));
	}

	if (AorB)
	{
		AorB = !AorB;
		return max(arr, length);
	}
	else
	{
		AorB = !AorB;
		return min(arr, length);
	}
}

int main()
{
	long long n;
	cin >> n;
	long long example[1];
	long long bearingsPoints[n][3];
	long long auxBearingsPoints[3];
	long long start[2] = {0, 0};
	long long maxPoints;
	long long count = 0;

	for (long long i = 0; i < n; i++)
	{
		cin >> auxBearingsPoints[0] >> auxBearingsPoints[1] >> auxBearingsPoints[2];
		if (auxBearingsPoints[1] > auxBearingsPoints[0])
		{
			continue;
		}
		bearingsPoints[count][0] = auxBearingsPoints[0];
		bearingsPoints[count][1] = auxBearingsPoints[1];
		bearingsPoints[count][2] = auxBearingsPoints[2];
		count++;
	}

	maxPoints = intelligence(start, bearingsPoints, count, 0);
	std::cout << maxPoints << std::endl;
	return 0;
}
