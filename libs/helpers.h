#include <iostream>

void cleanScreen(int I = 30)
{
	for (int i = 0; i < I; i++)
		printf("\n");
}

int sumUp(int arr[], int length)
{
	int accumulator = 0;
	for (int i = 0; i < length; i++)
		accumulator += arr[i];

	return accumulator;
}
