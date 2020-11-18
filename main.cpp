#include <iostream>
// #include "Librerias/Tablero/Tablero.h"
#include "Librerias/gameboard/gameboard.h"
// #include "libs/enums/enums.h"

using namespace std;

OnceAnnouncement announcement(5);

int game(int nP1_pieces[6], int nP2_pieces[6], int bearingsP1_pieces[][2], int bearingsP2_pieces[][2], int width = 8, int height = 8)
{
	cout << "Creating the game." << endl;
	int result = 0;
	int movements = 0;
	int difficulty = 2; //movement projection, predicted or calculation in the future
	bool turn = true;
	bool availableMovement = false;

	//construct/ declaring the pieces
	Gameboard gameboard(nP1_pieces, nP2_pieces, bearingsP1_pieces, bearingsP2_pieces, width, height);
	cout << "Game created!" << endl;
	//* GAME

	int start[2];
	int end[2];
	char startLetter;
	char endLetter;
	int startNumber;
	int endNumber;
	char piece;
	char endSlot;

	while (true)
	{
		// show gameboard
		gameboard.show();
		if (turn) //* P1 turn
		{
			// select a piece
			while (true)
			{
				cout << "Input the piece's letter and number:" << endl;
				cin >> startLetter >> start[0];
				start[0]--;
				startLetter = toupper(startLetter);
				start[1] = (int)startLetter - ((int)'A'); // 0 - width
				if ((-1 < start[1]) && (start[1] < width) && (-1 < start[0]) && (start[0] < height))
				{
					piece = gameboard.slots[start[0]][start[1]];
					// piece is a piece and belongs to P1
					if ((piece != PiecesChar::char_free) && ((int)piece < ((int)'Z' + 1)) && ((int)piece > ((int)'A' - 1)))
					{
						availableMovement = gameboard.piecePossibilities(start, piece);
						if (availableMovement)
						{
							break;
						}
						else
						{
							cout << "There aren't available positions to move your piece. Please, choose another" << endl;
						}
					}
					else
					{
						cout << "There is no piece in that position." << endl;
					}
				}
				else
					cout << "Imposible position." << endl;
			}
			while (true)
			{
				cout << "Input the end position letter and number:" << endl;
				cin >> endLetter >> end[0];
				end[0]--;
				endLetter = toupper(endLetter);
				end[1] = (int)endLetter - ((int)'A'); // = 0 to width
				if ((-1 < end[1]) && (end[1] < width) && (-1 < end[0]) && (end[0] < height))
				{
					endSlot = gameboard.slots[end[0]][end[1]];
					if (endSlot == PiecesChar::char_free) // endSlot is empty
						break;
					if (((int)'a' - 1 < endSlot) && (endSlot < (int)'z' + 1)) // eat P2
						//King Exception
						//system Point
						//eat
						break;
					else
						std::cout << "You can't capture your own pieces." << std::endl;
				}
				else
					cout << "Imposible position." << endl;
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
			turn = !turn;
			movements++;
		}
		
	}
	if (true)
	{
		;
		// break;
	}
	if (gameboard.P1_kings_ptr[0].checkmate)
	{
		result = 0;
		// break;
	}
	else if (gameboard.P2_kings_ptr[0].checkmate)
	{
		result = 1;
		// break;
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
		cout << "\nWhat do you want to do now?" << endl;
		cout << "\t[P]lay" << endl;
		cout << "\t[Q]uit" << endl;
		cout << "\t[S]ettings (in progress)" << endl;
		cout << endl;
		cin >> command;
		cleanScreen();
		command = toupper(command);

		switch (command)
		{
		case 'P':
			cout << "\nLet's play!" << endl;
			result = game(nP1_pieces, nP2_pieces, bearingsP1_pieces, bearingsP2_pieces, 8, 8);
			if (result == 0)
			{
				cout << " 🥳 P1 won the game!" << endl;
			}
			else if (result == 1)
			{
				cout << " P2 won the game! 🥳" << endl;
			}
			else
			{
				cout << " Tie 🤯 No one won the game" << endl;
			}
			break;
		case 'Q':
			cout << "\nGood bye 😥" << endl;
			return 0;
			break;
		case 'S':
			cout << "\n<<--<---SETTINGS--->-->>" << endl;
			// show settings:
			cout << "Dimensions\t: " << width << height << endl;

			cout << "\n<---ACTUAL GAMEBOARD--->" << endl;
			//print actual gameboard

			while (true)
			{
				cout << "\nWhat do you want to modify?" << endl;
				cout << "\t[B]ack" << endl;
				cout << "\tP[1] settings" << endl;
				cout << "\tP[2] settings" << endl;
				cout << "\t[C]lear the gameboard" << endl;
				cout << "\t[G]ameboard settings" << endl;
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
					cout << "\nNumber P1's pieces\t: " << sumUp(nP1_pieces, 6) << endl;
					cout << "\tKing(s)\t: " << nP1_pieces[0] << endl;
					cout << "\tQueen(s)\t: " << nP1_pieces[1] << endl;
					cout << "\tRook(s)\t: " << nP1_pieces[2] << endl;
					cout << "\tKnight(s)\t: " << nP1_pieces[3] << endl;
					cout << "\tBishop(s)\t: " << nP1_pieces[4] << endl;
					cout << "\tPawn(s)\t: " << nP1_pieces[5] << endl;

					cout << "\n[B]ack" << endl;
					cout << "[~] Add or remove a piece" << endl;
					cout << "[C]hange a piece position" << endl;
					cout << "[S]how Gameboard" << endl;
					cout << endl;
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
					cout << "\nNumber P2's pieces\t: " << sumUp(nP2_pieces, 6) << endl;
					cout << "\tKing(s)\t: " << nP2_pieces[0] << endl;
					cout << "\tQueen(s)\t: " << nP2_pieces[1] << endl;
					cout << "\tRook(s)\t: " << nP2_pieces[2] << endl;
					cout << "\tKnight(s)\t: " << nP2_pieces[3] << endl;
					cout << "\tBishop(s)\t: " << nP2_pieces[4] << endl;
					cout << "\tPawn(s)\t: " << nP2_pieces[5] << endl;
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
			cout << "\nNot recognizable command" << endl;
			break;
		}
		command = ' ';
	}
}
