#include <iostream>

struct OnceAnnouncement
{
	OnceAnnouncement()
	{
		std::cout << "Welcome, this is a Chess game created as final project by CS students at UCSP\n";
	}
	~OnceAnnouncement()
	{
		std::cout << "The program has ended\n";
	}
};

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
