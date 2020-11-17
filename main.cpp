#include <iostream>
// #include "Librerias/Tablero/Tablero.h"
#include "librerias/gameboard/gameboard.h"
// #include "libs/enums/enums.h"

using namespace std;

OnceAnnouncement announcement(4);

int game(int nP1_pieces[6], int nP2_pieces[6], int bearingsP1_pieces[][2], int bearingsP2_pieces[][2], int width = 8, int height = 8)
{
	std::cout << "Creating the game." << std::endl;
	int result = 0;
	int movements = 0;
	int difficulty = 2; //movement projection, predicted or calculation in the future
	bool turn = true;

	//construct/ declaring the pieces
	Gameboard gameboard(nP1_pieces, nP2_pieces, bearingsP1_pieces, bearingsP2_pieces, width, height);
	std::cout << "Game created!" << std::endl;
	//* GAME

	int start[2];
	int end[2];
	char startLetter;
	char endLetter;
	int startNumber;
	int endNumber;
	char slot;

	while (true)
	{
		// show gameboard
		gameboard.show();
		if (turn) //* P1 turn
		{
			// select a piece
			while (true)
			{
				std::cout << "Input the piece's letter and number:" << std::endl;
				std::cin >> startLetter >> start[0];
				start[0]--;
				startLetter = toupper(startLetter);
				start[1] = (int)startLetter - ((int)'A'); // 0 - width
				if ((-1 < start[1]) && (start[1] < width) && (-1 < start[0]) && (start[0] < height))
				{
					slot = gameboard.slots[start[0]][start[1]];
					if (slot != PiecesChar::char_free)
					{
						// if (slot == PiecesChar::charP1_pawn)
						// {
						// }
						break;
					}
					else
					{
						std::cout << "There is no piece in that position." << std::endl;
					}
				}
				else
					std::cout << "Imposible position." << std::endl;
			}
			while (true)
			{
				// show gameboard with possibilities.
				std::cout << "Input the end position letter and number:" << std::endl;
				std::cin >> endLetter >> end[0];
				end[0]--;
				endLetter = toupper(endLetter);
				end[1] = (int)endLetter - ((int)'A'); // 0 - width
				if ((-1 < end[1]) && (end[1] < width) && (-1 < end[0]) && (end[0] < height))
				{
					break;
				}
				else
					std::cout << "Imposible position." << std::endl;
			}
			// make the movement in the gameboard
			gameboard.move(start, end);
			gameboard.show();
			turn = !turn;
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
		if (true)
		{
			break;
		}
		if (gameboard.P1_kings_ptr[0].checkmate)
		{
			result = 0;
			break;
		}
		else if (gameboard.P2_kings_ptr[0].checkmate)
		{
			result = 1;
			break;
		}
	}

	return result;
}

int main()
{

	int width = 8;	//ancho
	int height = 8; //altura
	int result;

	// The number of pieces
	// kings, queens, rooks, knights, bishops and pawns.
	// rey, reina, torre, caballos, alfiles y peones
	int nP1_pieces[6] = {1, 1, 2, 2, 2, 8};
	int nP2_pieces[6] = {1, 1, 2, 2, 2, 8};

	int bearingsP1_pieces[16][2] = {
		// bearings = coordenadas
		// coordenadas por default de las piezas P1
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
		// coordenadas por default de las piezas P2
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

	//* INTERFAZ
	while (true)
	{
		std::cout << "\nWhat do you want to do now?" << std::endl;
		std::cout << "\t[P]lay" << std::endl;
		std::cout << "\t[Q]uit" << std::endl;
		std::cout << "\t[S]ettings (in progress)" << std::endl;
		std::cout << std::endl;
		std::cin >> command;
		cleanScreen();
		command = toupper(command);

		switch (command)
		{
		case 'P':
			std::cout << "\nLet's play!" << std::endl;
			result = game(nP1_pieces, nP2_pieces, bearingsP1_pieces, bearingsP2_pieces, 8, 8);
			if (result == 0)
			{
				std::cout << " 🥳 P1 won the game!" << std::endl;
			}
			else if (result == 1)
			{
				std::cout << " P2 won the game! 🥳" << std::endl;
			}
			else
			{
				std::cout << " Tie 🤯 No one won the game" << std::endl;
			}
			break;
		case 'Q':
			std::cout << "\nGood bye 😥" << std::endl;
			return 0;
			break;
		case 'S':
			std::cout << "\n<<--<---SETTINGS--->-->>" << std::endl;
			// show settings:
			std::cout << "Dimensions\t: " << width << height << std::endl;

			std::cout << "\n<---ACTUAL GAMEBOARD--->" << std::endl;
			//print actual gameboard

			while (true)
			{
				std::cout << "\nWhat do you want to modify?" << std::endl;
				std::cout << "\t[B]ack" << std::endl;
				std::cout << "\tP[1] settings" << std::endl;
				std::cout << "\tP[2] settings" << std::endl;
				std::cout << "\t[C]lear the gameboard" << std::endl;
				std::cout << "\t[G]ameboard settings" << std::endl;
				// printf("\t[S]how settings\n");
				printf("\t[S]how Gameboard\n");
				// printf("\t[R]estart settings\n");
				std::cin >> settings_command;
				cleanScreen();

				settings_command = toupper(settings_command);

				switch (settings_command)
				{
				case 'B':
					settings_break = true;
					break;
				case '1':
					std::cout << "\nNumber P1's pieces\t: " << sumUp(nP1_pieces, 6) << std::endl;
					std::cout << "\tKing(s)\t: " << nP1_pieces[0] << std::endl;
					std::cout << "\tQueen(s)\t: " << nP1_pieces[1] << std::endl;
					std::cout << "\tRook(s)\t: " << nP1_pieces[2] << std::endl;
					std::cout << "\tKnight(s)\t: " << nP1_pieces[3] << std::endl;
					std::cout << "\tBishop(s)\t: " << nP1_pieces[4] << std::endl;
					std::cout << "\tPawn(s)\t: " << nP1_pieces[5] << std::endl;

					std::cout << "\n[B]ack" << std::endl;
					std::cout << "[~] Add or remove a piece" << std::endl;
					std::cout << "[C]hange a piece position" << std::endl;
					std::cout << "[S]how Gameboard" << std::endl;
					std::cout << std::endl;
					std::cin >> sub_command;
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
					std::cout << "\nNumber P2's pieces\t: " << sumUp(nP2_pieces, 6) << std::endl;
					std::cout << "\tKing(s)\t: " << nP2_pieces[0] << std::endl;
					std::cout << "\tQueen(s)\t: " << nP2_pieces[1] << std::endl;
					std::cout << "\tRook(s)\t: " << nP2_pieces[2] << std::endl;
					std::cout << "\tKnight(s)\t: " << nP2_pieces[3] << std::endl;
					std::cout << "\tBishop(s)\t: " << nP2_pieces[4] << std::endl;
					std::cout << "\tPawn(s)\t: " << nP2_pieces[5] << std::endl;
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
			std::cout << "\nNot recognizable command" << std::endl;
			break;
		}
		command = ' ';
	}
}
