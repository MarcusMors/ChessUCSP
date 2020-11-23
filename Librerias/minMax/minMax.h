
// int sumUp(int arr[], int length)
// {
// 	int accumulator = 0;
// 	for (int i = 0; i < length; i++)
// 		accumulator += arr[i];

// 	return accumulator;
// }

int max(int arr[], int length)
{
	int max = -10000;
	for (int i = 0; i < length; i++)
	{
		max = (max < arr[i]) ? arr[i] : max;
	}
	return max;
}

int min(int arr[], int length)
{
	int min = 10000;
	for (int i = 0; i < length; i++)
	{
		min = (min > arr[i]) ? arr[i] : min;
	}
	return min;
}
