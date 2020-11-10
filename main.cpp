#include <iostream>
#include "Librerias/Tablero/Tablero.h"
#include "libs/pieces.h"
#include "libs/helpers.h"

using namespace std;

int game(int nP1_pieces[6], int nP2_pieces[6], int bearingsP1_pieces[][2], int bearingsP2_pieces[][2], int width = 8, int height = 8)
{
	int result = 0;
	int movements = 0;
	int difficulty = 2; //movement projection, movements predicted /calculated in the future
	bool turn = false;

	int totalP1_pieces = sumUp(nP1_pieces, 6);
	int totalP2_pieces = sumUp(nP2_pieces, 6);
	int accumulatedP1_pieces[6];
	int accumulatedP2_pieces[6];
	int piece = 0;
	int pieceIndex = 0;

	int accumulatorP1 = 0;
	int accumulatorP2 = 0;

	for (int i = 0; i < 6; i++)
	{
		accumulatorP1 += nP1_pieces[i];
		accumulatorP2 += nP2_pieces[i];
		accumulatedP1_pieces[i] = accumulatorP1;
		accumulatedP2_pieces[i] = accumulatorP2;
	}

	//construct/ declaring the pieces
	//kings, queens, rooks, knights, bishops and pawns.
	Gameboard gameboard;

	King P1_kings[nP1_pieces[0]];
	Queen P1_queens[nP1_pieces[1]];
	Rook P1_rooks[nP1_pieces[2]];
	Knight P1_knights[nP1_pieces[3]];
	Bishop P1_bishops[nP1_pieces[4]];
	Pawn P1_pawns[nP1_pieces[5]];

	King P2_kings[nP2_pieces[0]];
	Queen P2_queens[nP2_pieces[1]];
	Rook P2_rooks[nP2_pieces[2]];
	Knight P2_knights[nP2_pieces[3]];
	Bishop P2_bishops[nP2_pieces[4]];
	Pawn P2_pawns[nP2_pieces[5]];

	// initializing the pieces objects
	// P1 bearings of each piece
	for (int i = 0; i < totalP1_pieces; i++)
	{
		if (i < accumulatedP1_pieces[piece])
		{
			switch (piece)
			{
			case 0:
				P1_kings[pieceIndex] = King(bearingsP1_pieces[i], 0);
				break;
			case 1:
				P1_queens[pieceIndex] = Queen(bearingsP1_pieces[i], 0);
				break;
			case 2:
				P1_rooks[pieceIndex] = Rook(bearingsP1_pieces[i], 0);
				break;
			case 3:
				P1_knights[pieceIndex] = Knight(bearingsP1_pieces[i], 0);
				break;
			case 4:
				P1_bishops[pieceIndex] = Bishop(bearingsP1_pieces[i], 0);
				break;
			case 5:
				P1_pawns[pieceIndex] = Pawn(bearingsP1_pieces[i], 0);
				break;

			default:
				printf("\nAn error happened while initializing P1\n");
				printf("iterator\t: %i\n", i);
				printf("accumulated\t: %i\n", accumulatedP1_pieces[piece]);
				printf("piece\t: %i\n", piece);
				printf("pieceIndex\t: %i\n", pieceIndex);
				break;
			}
		}
		else
		{
			i--;
			piece++;
			pieceIndex = 0;
		}
	}
	piece = 0;
	pieceIndex = 0;

	// P2 bearings of each piece
	for (int i = 0; i < totalP2_pieces; i++)
	{
		if (i < accumulatedP2_pieces[piece])
		{
			switch (piece)
			{
			case 0:
				P2_kings[pieceIndex] = King(bearingsP2_pieces[i], 1);
				break;
			case 1:
				P2_queens[pieceIndex] = Queen(bearingsP2_pieces[i], 1);
				break;
			case 2:
				P2_rooks[pieceIndex] = Rook(bearingsP2_pieces[i], 1);
				break;
			case 3:
				P2_knights[pieceIndex] = Knight(bearingsP2_pieces[i], 1);
				break;
			case 4:
				P2_bishops[pieceIndex] = Bishop(bearingsP2_pieces[i], 1);
				break;
			case 5:
				P2_pawns[pieceIndex] = Pawn(bearingsP2_pieces[i], 1);
				break;

			default:
				printf("\nAn error happened while initializing P1\n");
				printf("iterator\t: %i\n", i);
				printf("accumulated\t: %i\n", accumulatedP1_pieces[piece]);
				printf("piece\t: %i\n", piece);
				printf("pieceIndex\t: %i\n", pieceIndex);
				break;
			}
		}
		else
		{
			i--;
			piece++;
			pieceIndex = 0;
		}
	}

	cout << "game created" << endl;
	//* GAME
	while (true)
	{
		if (turn) //* P1 turn
		{
			turn = !turn;
			// show gameboard
			// enter the movement
			// valid movement?
			// make the movement in the gameboard
			movements++;
		}
		else //* P2 turn
		{
			//* strategic points (ruin the castle movement, position, get more options, get good options, exchange strain?, etc? suggest please), piece points,

			// pass the state of the game
			// set an objective: aperture?, start?. middle?, ends?.
			// judge the options: defense, attack, develop (inrook), exchange chain,
			// make a plan
			// make the first movement plan
			// make the movement in the gameboard
			movements++;
		}
		break;
		//code
	}

	return result;
}

int main()
{
	//! still not working
	// char m[8][8] = {{'t', 'c', 'a', 'q', 'r', 'a', 'c', 't'},
	// 				{'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
	// 				{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	// 				{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	// 				{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	// 				{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	// 				{'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
	// 				{'T', 'C', 'A', 'R', 'Q', 'A', 'C', 'T'}};
	// tablero(m);
	// while (true)
	// {
	// 	cambio(m, ' ', 0, ' ', 0);
	// }
	//! still not working

	int width = 8;
	int height = 8;
	int result;

	// The number of pieces
	// kings, queens, rooks, knights, bishops and pawns.
	int nP1_pieces[6] = {1, 1, 2, 2, 2, 8};
	int nP2_pieces[6] = {1, 1, 2, 2, 2, 8};

	int bearingsP1_pieces[16][2] = {
		{0, 4}, // kings
		{0, 3}, // queens
		{0, 0},
		{0, 7}, // rooks
		{0, 1},
		{0, 6}, // knights
		{0, 2},
		{0, 5}, // bishops
		{1, 0},
		{1, 1},
		{1, 2},
		{1, 3},
		{1, 4},
		{1, 5},
		{1, 6},
		{1, 7} //pawns
	};
	int bearingsP2_pieces[16][2] = {
		{7, 4}, // kings
		{7, 3}, // queens
		{7, 0},
		{7, 7}, // rooks
		{7, 1},
		{7, 6}, // knights
		{7, 2},
		{7, 5}, // bishops
		{6, 0},
		{6, 1},
		{6, 2},
		{6, 3},
		{6, 4},
		{6, 5},
		{6, 6},
		{6, 7} //pawns
	};

	char command;
	char settings_command;
	char sub_command;
	bool settings_break = false;
	bool subSettings_break = false;

	while (true)
	{
		printf("\nWhat do you want to do now?\n");
		printf("\t[P]lay\n");
		printf("\t[Q]uit\n");
		printf("\t[S]ettings (in progress)\n");
		printf("\n");
		cin >> command;
		cleanScreen();
		command = toupper(command);

		switch (command)
		{
		case 'P':
			printf("\nLet's play!\n");
			result = game(nP1_pieces, nP2_pieces, bearingsP1_pieces, bearingsP2_pieces);
			if (result == 1)
			{
				cout << " 🥳 P1 won the game!"
			}
			else if (resukt == 0)
			{
				cout << " P2 won the game! 🥳"
			}
			else
			{
				cout << " Tie 🤯 No one won the game"
			}
			break;
		case 'Q':
			printf("\nGood bye 😥\n");
			return 0;
			break;
		case 'S':
			printf("\n<<--<---SETTINGS--->-->>\n");
			// show settings:
			printf("Dimensions\t: %i, %i\n", width, height);

			printf("\n<---ACTUAL GAMEBOARD--->\n");
			//print actual gameboard

			while (true)
			{
				printf("\nWhat do you want to modify?\n");
				printf("\t[B]ack\n");
				printf("\tP[1] settings\n");
				printf("\tP[2] settings\n");
				printf("\t[C]lear the gameboard\n");
				printf("\t[G]ameboard settings\n");
				// printf("\t[S]how settings\n");
				printf("\t[S]how Gameboard\n");
				// printf("\t[R]estart settings\n");
				cin >> settings_command;
				cleanScreen();

				settings_command = toupper(settings_command);

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
					printf("[S]how Gameboard\n");
					printf("\n");
					cin >> sub_command;
					cleanScreen();

					sub_command = toupper(sub_command);

					switch (sub_command)
					{
					case 'B':
						subSettings_break = true;
						int bearingsP1_king[1][2];
						int bearingsP1_queen[1][2];
						int bearingsP1_rook[2][2];
						int bearingsP1_knight[2][2];
						int bearingsP1_bishop[2][2];
						int bearingsP1_pawns[2][2];
						break;
					case '~':
						//print [p]iece
						//another switch? :c
						subSettings_break = true;
						break;
					case 'C':
						subSettings_break = true;
						break;

					default:
						break;
					}
					sub_command = ' ';
					if (subSettings_break)
					{
						subSettings_break = false;
						break;
					}
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
