#include <iostream>

void cleanScreen(int I = 30)
{
	for (int i = 0; i < I; i++)
		std::cout << std::endl;
}

int letterToInt(char letter)
{
	int num;
	return num;
}

int sumUp(int arr[], int length)
{
	int accumulator = 0;
	for (int i = 0; i < length; i++)
		accumulator += arr[i];

	return accumulator;
}

long long max(long long arr[], long long length)
{
	long long max = -10000;
	for (long long i = 0; i < length; i++)
	{
		max = (max < arr[i]) ? arr[i] : max;
	}
	return max;
}

long long min(long long arr[], long long length)
{
	long long min = 10000;
	for (long long i = 0; i < length; i++)
	{
		min = (min > arr[i]) ? arr[i] : min;
	}
	return min;
}

