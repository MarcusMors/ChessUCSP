#include <iostream>
#include "Librerias/Tablero/Tablero.h"
#include "libs/pieces.h"

using namespace std;

int sumUp(int arr[], int length)
{
	int accumulator = 0;
	for (int i = 0; i < length; i++)
	{
		accumulator += arr[i];
	}

	return accumulator;
}

int game()
{
	Gameboard gameboard;
	for (int i = 0; i < 10; i++)
	{
	}
	// King king[1];
	// Queen queen[1];
	// Rook rook[2];
	// Knight knight[2];
	// Bishop bishop[2];
	// Pawn pawns[8];
}

int main()
{
	char m[8][8] = {{'t', 'c', 'a', 'q', 'r', 'a', 'c', 't'},
					{'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
					{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
					{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
					{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
					{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
					{'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
					{'T', 'C', 'A', 'R', 'Q', 'A', 'C', 'T'}};
	tablero(m);
	while (true)
	{
		cambio(m, ' ', 0, ' ', 0);
	}
	int width = 8;
	int height = 8;

	// The number of pieces
	// kings, queens, rooks, knights, bishops and pawns.
	int nP1_pieces[6] = {1, 1, 2, 2, 2, 8};
	int nP1_pieces[6] = {1, 1, 2, 2, 2, 8};

	char command;
	char settings_command;
	bool settings_break = false;

	while (true)
	{
		printf("\nWhat do you want to do now?\n");
		printf("\t[P]lay\n");
		printf("\t[Q]uit\n");
		printf("\t[S]ettings\n");
		printf("\n");
		cin >> command;
		command = toupper(command);

		switch (command)
		{
		case 'P':
			printf("\nLet's play!\n");
			game();
			break;
		case 'Q':
			printf("\nGood bye 😥\n");
			return 0;
			break;
		case 'S':
			printf("\n<<-<---SETTINGS--->->>\n");
			// show settings:
			printf("Dimensions\t: %i, %i\n", width, height);

			printf("\n<---ACTUAL GAMEBOARD--->\n");
			//print actual gameboard

			while (true)
			{
				printf("\nWhat do you want to modify?\n") int bearingsP1_king[1][2];
				printf("\t[B]ack\n");
				printf("\tP[1] settings\n");
				printf("\tP[2] settings\n");
				printf("\t[C]lear the gameboard\n");
				printf("\t[G]ameboard settings\n");
				// printf("\t[S]how settings\n");
				printf("\t[S]how the Gameboard\n");
				// printf("\t[R]estart settings\n");
				cin >> settings_command;

				settings_command = toUpper(settings_command);

				switch (settings_command)
				{
				case 'B':
					settings_break = true;
					break;
				case '1':
					printf("\nNumber P1's pieces\t: %i\n", sumUp(nP1_pieces, 6));
					printf("\tKing(s)\t: %i\n", nP1_pieces[0]);
					printf("\tQueen(s)\t: %i\n", nP1_pieces[1]);
					printf("\tRook(s)\t: %i\n", nP1_pieces[2]);
					printf("\tKnight(s)\t: %i\n", nP1_pieces[3]);
					printf("\tBishop(s)\t: %i\n", nP1_pieces[4]);
					printf("\tPawn(s)\t: %i\n", nP1_pieces[5]);

					printf("\n[B]ack\n");
					printf("[~] Add or remove a piece\n");
					printf("[C]hange a piece position\n");
					printf("[]\n");
					printf("\n");
					int bearingsP1_queen[1][2];
					int bearingsP1_rook[2][2];
					int bearingsP1_knight[2][2];
					int bearingsP1_bishop[2][2];
					int bearingsP1_pawns[2][2];
					break;
				case '2':
					printf("\nNumber P2's pieces\t: %i\n", sumUp(nP2_pieces, 6));
					printf("\tKing(s)\t: %i\n", nP2_pieces[0]);
					printf("\tQueen(s)\t: %i\n", nP2_pieces[1]);
					printf("\tRook(s)\t: %i\n", nP2_pieces[2]);
					printf("\tKnight(s)\t: %i\n", nP2_pieces[3]);
					printf("\tBishop(s)\t: %i\n", nP2_pieces[4]);
					printf("\tPawn(s)\t: %i\n", nP2_pieces[5]);
					int nP2_king[1][2];
					int nP2_queen[1][2];
					int nP2_rook[2][2];
					int nP2_knight[2][2];
					int nP2_bishop[2][2];
					int nP2_pawns[2][2];
					break;
				case 'C':
					break;
				case 'G':
					break;
				case 'S':
					break;

				default:
					break;
				}
				if (settings_break)
				{
					settings_break = false;
					break;
				}
			}
			settings_command = ' ';
			break;
		default:
			printf("\nNot recognizable command\n");
			break;
		}
		command = ' ';
	}
}
