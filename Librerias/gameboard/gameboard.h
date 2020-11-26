// #ifndef CHESS_UCSP_GAMEBOARD_H
// #define CHESS_UCSP_GAMEBOARD_H
// #endif
#pragma once

#include <iostream>
#include "../pieces/pieces.h"
#include "../enums/enums.h"
#include "../helpers/helpers.h"

int P1_score = 0;
int P2_score = 0;

using namespace std;
class Gameboard
{
public:
	// 2D ptrptr?
	char slots[26][26];

	int width;
	int height;
	// Pieces
	King *P1_kings_ptr;
	Queen *P1_queens_ptr;
	Rook *P1_rooks_ptr;
	Knight *P1_knights_ptr;
	Bishop *P1_bishops_ptr;
	Pawn *P1_pawns_ptr;

	King *P2_kings_ptr;
	Queen *P2_queens_ptr;
	Rook *P2_rooks_ptr;
	Knight *P2_knights_ptr;
	Bishop *P2_bishops_ptr;
	Pawn *P2_pawns_ptr;
	int nP1_pieces[6];
	int nP2_pieces[6];

	// Gameboard() {}
	Gameboard(int inP1_pieces[6], int inP2_pieces[6], int bearingsP1_pieces[][2], int bearingsP2_pieces[][2], int iWidth = 8, int iHeight = 8)
	{
		cout << "Inside Gameboard" << endl;
		width = iWidth;
		height = iHeight;

		for (int i = 0; i < 6; i++)
		{
			nP1_pieces[i] = inP1_pieces[i];
		}
		for (int i = 0; i < 6; i++)
		{
			nP2_pieces[i] = inP2_pieces[i];
		}

		P1_kings_ptr = new King[nP1_pieces[0]];
		P1_queens_ptr = new Queen[nP1_pieces[1]];
		P1_rooks_ptr = new Rook[nP1_pieces[2]];
		P1_knights_ptr = new Knight[nP1_pieces[3]];
		P1_bishops_ptr = new Bishop[nP1_pieces[4]];
		P1_pawns_ptr = new Pawn[nP1_pieces[5]];

		P2_kings_ptr = new King[nP2_pieces[0]];
		P2_queens_ptr = new Queen[nP2_pieces[1]];
		P2_rooks_ptr = new Rook[nP2_pieces[2]];
		P2_knights_ptr = new Knight[nP2_pieces[3]];
		P2_bishops_ptr = new Bishop[nP2_pieces[4]];
		P2_pawns_ptr = new Pawn[nP2_pieces[5]];

		int accumulatedP1_pieces[6];
		int accumulatedP2_pieces[6];

		int totalP1_pieces = sumUp(nP1_pieces, 6);
		int totalP2_pieces = sumUp(nP2_pieces, 6);
		int accumulatorP1 = 0;
		int accumulatorP2 = 0;

		for (int i = 0; i < 6; i++)
		{
			accumulatorP1 += nP1_pieces[i];
			accumulatorP2 += nP2_pieces[i];
			accumulatedP1_pieces[i] = accumulatorP1;
			accumulatedP2_pieces[i] = accumulatorP2;
		}
		cout << "Init Gameboard" << endl;
		initGameboard();
		cout << "filling the Gameboard" << endl;
		fillGameboard(accumulatedP1_pieces, totalP1_pieces, bearingsP1_pieces, true);  //P1
		fillGameboard(accumulatedP2_pieces, totalP2_pieces, bearingsP2_pieces, false); //P2
		initShowVars();
	}
	bool validMovement()
	{
		// Your king has been moved earlier in the game.
		// The rook that you would castle with has been moved earlier in the game.
		// There are pieces standing between your king and rook.
		// The king is in check.
		// The king moves through a square that is attacked by a piece of the opponent.
		// The king would be in check after castling.
		bool valid;
		return valid;
	}
	void move(int start[2], int end[2], bool player, bool eat)
	{
		char piece = slots[start[0]][start[1]];
		if (player)
		{
			switch (piece)
			{
			case PiecesChar::charP1_king:
				for (int i = 0; i < nP1_pieces[0]; i++)
					if ((start[0] == P1_kings_ptr[i].position[0]) && (start[1] == P1_kings_ptr[i].position[1]))
					{
						P1_kings_ptr[i].position[0] = end[0];
						P1_kings_ptr[i].position[1] = end[1];
						P1_kings_ptr[i].movements++;
					};
				break;
			case PiecesChar::charP1_queen:
				for (int i = 0; i < nP1_pieces[1]; i++)
					if ((start[0] == P1_queens_ptr[i].position[0]) && (start[1] == P1_queens_ptr[i].position[1]))
					{
						P1_queens_ptr[i].position[0] = end[0];
						P1_queens_ptr[i].position[1] = end[1];
					};
				break;
			case PiecesChar::charP1_rook:
				for (int i = 0; i < nP1_pieces[2]; i++)
					if ((start[0] == P1_rooks_ptr[i].position[0]) && (start[1] == P1_rooks_ptr[i].position[1]))
					{
						P1_rooks_ptr[i].position[0] = end[0];
						P1_rooks_ptr[i].position[1] = end[1];
						P1_rooks_ptr[i].movements++;
					};
				break;
			case PiecesChar::charP1_knight:
				for (int i = 0; i < nP1_pieces[3]; i++)
					if ((start[0] == P1_knights_ptr[i].position[0]) && (start[1] == P1_knights_ptr[i].position[1]))
					{
						P1_knights_ptr[i].position[0] = end[0];
						P1_knights_ptr[i].position[1] = end[1];
					};
				break;
			case PiecesChar::charP1_bishop:
				for (int i = 0; i < nP1_pieces[4]; i++)
					if ((start[0] == P1_bishops_ptr[i].position[0]) && (start[1] == P1_bishops_ptr[i].position[1]))
					{
						P1_bishops_ptr[i].position[0] = end[0];
						P1_bishops_ptr[i].position[1] = end[1];
					};
				break;
			case PiecesChar::charP1_pawn:
				for (int i = 0; i < nP1_pieces[5]; i++)
					if ((start[0] == P1_pawns_ptr[i].position[0]) && (start[1] == P1_pawns_ptr[i].position[1]))
					{
						P1_pawns_ptr[i].position[0] = end[0];
						P1_pawns_ptr[i].position[1] = end[1];
						P1_pawns_ptr[i].movements++;
					};
				break;

			default:
				std::cout << "An error happened while moving" << std::endl;
				break;
			}
		}
		else
		{
			switch (piece)
			{
			case PiecesChar::charP2_king:
				for (int i = 0; i < nP1_pieces[5]; i++)
					if ((start[0] == P2_kings_ptr[i].position[0]) && (start[1] == P2_kings_ptr[i].position[1]))
					{
						P2_kings_ptr[i].position[0] = end[0];
						P2_kings_ptr[i].position[1] = end[1];
						P2_kings_ptr[i].movements++;
					};
				break;
			case PiecesChar::charP2_queen:
				for (int i = 0; i < nP2_pieces[5]; i++)
					if ((start[0] == P2_queens_ptr[i].position[0]) && (start[1] == P2_queens_ptr[i].position[1]))
					{
						P2_queens_ptr[i].position[0] = end[0];
						P2_queens_ptr[i].position[1] = end[1];
					};
				break;
			case PiecesChar::charP2_rook:
				for (int i = 0; i < nP2_pieces[5]; i++)
					if ((start[0] == P2_rooks_ptr[i].position[0]) && (start[1] == P2_rooks_ptr[i].position[1]))
					{
						P2_rooks_ptr[i].position[0] = end[0];
						P2_rooks_ptr[i].position[1] = end[1];
						P2_rooks_ptr[i].movements++;
					};
				break;
			case PiecesChar::charP2_knight:
				for (int i = 0; i < nP2_pieces[5]; i++)
					if ((start[0] == P2_knights_ptr[i].position[0]) && (start[1] == P2_knights_ptr[i].position[1]))
					{
						P2_knights_ptr[i].position[0] = end[0];
						P2_knights_ptr[i].position[1] = end[1];
					};
				break;
			case PiecesChar::charP2_bishop:
				for (int i = 0; i < nP2_pieces[5]; i++)
					if ((start[0] == P2_bishops_ptr[i].position[0]) && (start[1] == P2_bishops_ptr[i].position[1]))
					{
						P2_bishops_ptr[i].position[0] = end[0];
						P2_bishops_ptr[i].position[1] = end[1];
					};
				break;
			case PiecesChar::charP2_pawn:
				for (int i = 0; i < nP2_pieces[5]; i++)
					if ((start[0] == P2_pawns_ptr[i].position[0]) && (start[1] == P2_pawns_ptr[i].position[1]))
					{
						P2_pawns_ptr[i].position[0] = end[0];
						P2_pawns_ptr[i].position[1] = end[1];
						P2_pawns_ptr[i].movements++;
					};
				break;

			default:
				std::cout << "An error happened while moving" << std::endl;
				break;
			}
		}
		// how can we get the object?
		slots[start[0]][start[1]] = PiecesChar::char_free;
		slots[end[0]][end[1]] = piece;
	}
	// bool bishopValid(int start[2], int end[2])
	// {
	// }
	bool piecePossibilities(int place[2], char piece) // ONLY P1 need visual reference
	{
		cout << "pieceposib" << endl;
		int piecePossibilities;
		bool availableMovement = false;
		switch (piece)
		{
		case PiecesChar::charP2_king:
			piecePossibilities = 0;
			availableMovement;
			break;
		case PiecesChar::charP2_queen:
			piecePossibilities = 1;
			if (drawDiagonals(place))
				availableMovement = true;
			if (drawLines(place))
				availableMovement = true;
			break;
		case PiecesChar::charP2_rook:
			piecePossibilities = 2;
			availableMovement = drawLines(place);
			break;
		case PiecesChar::charP2_knight:
			piecePossibilities = 3;
			availableMovement = drawJumps(place);
			break;
		case PiecesChar::charP2_bishop:
			piecePossibilities = 4;
			availableMovement = drawDiagonals(place);
			break;
		case PiecesChar::charP2_pawn:
			availableMovement = drawLines_P(place);
			piecePossibilities = 5;
			break;

		default:
			break;
		}
		if (availableMovement)
		{
			show();
			switch (piecePossibilities)
			{
			case 0:
				break;
			case 1:
				undrawDiagonals(place);
				undrawLines(place);
				break;
			case 2:
				undrawLines(place);
				break;
			case 3:
				undrawJumps(place);
				break;
			case 4:
				undrawDiagonals(place);
				break;
			case 5:
				undrawLines_P(place);
				break;

			default:
				break;
			}
			return true;
		}
		else
			return false;
	}
	void show()
	{
		// Letters, upper gameframe
		cout << equatorBlank << meridianChar;
		for (int i = 0; i < width; i++)
		{
			slotPiece[slotWidth / 2] = ((char)letter + i);
			cout << slotPiece << meridianChar;
		}
		cout << endl;
		// Gameboard
		for (int i = 0; i < height; i++)
		{
			//first frame
			cout << equatorFrame << meridianChar;
			for (int j = 0; j < width; j++)
			{
				cout << equatorSlot << meridianChar;
			}
			cout << equatorFrame << endl;

			for (int j = 0; j < 2; j++)
			{
				// Left frame (equator)
				if (j == 1)
				{
					cout << blankChar << number + i << blankChar << meridianChar;
				}
				else
				{
					cout << equatorBlank << meridianChar;
				}
				// Slot
				for (int o = 0; o < slotWidth + 1; o++)
				{
					if (j == 1)
					{
						slotPiece[slotWidth / 2] = (char)slots[i][o];
						cout << slotPiece << meridianChar;
					}
					else
					{
						cout << slotBlank << meridianChar;
					}
				}
				//Right Frame (equator)
				cout << equatorBlank << endl;
			}
		}
		// Letters, bottom gameframe
		cout << equatorFrame << meridianChar;
		for (int j = 0; j < width; j++)
		{
			cout << equatorSlot << meridianChar;
		}
		cout << equatorFrame << endl;
		cout << equatorBlank << meridianChar;
		for (int i = 0; i < width; i++)
		{
			slotPiece[slotWidth / 2] = ((char)letter + i);
			cout << slotPiece << meridianChar;
		}
		cout << endl;
	}

private:
	int slotWidth = 7;
	int equatorFrameWidth = 3;
	int meridianFrameWidth = 1;
	char blankChar = ' ';
	char equatorChar = '_';
	char meridianChar = '|';
	char letter = 'A';
	int number = 1;
	char *equatorFrame;
	char *equatorSlot;
	char *equatorBlank;
	char *meridianFrame;
	char *meridianBlank;
	char *slotPiece;
	char *slotBlank;

	void initShowVars()
	{
		equatorFrame = new char[equatorFrameWidth];
		equatorSlot = new char[slotWidth];
		equatorBlank = new char[equatorFrameWidth];
		meridianFrame = new char[meridianFrameWidth];
		meridianBlank = new char[meridianFrameWidth];
		slotPiece = new char[slotWidth];
		slotBlank = new char[slotWidth];

		for (int i = 0; i < equatorFrameWidth; i++)
		{
			equatorFrame[i] = equatorChar;
			equatorBlank[i] = blankChar;
		}
		for (int i = 0; i < meridianFrameWidth; i++)
		{
			meridianFrame[i] = meridianChar;
			meridianBlank[i] = blankChar;
		}
		for (int i = 0; i < slotWidth; i++)
		{
			equatorSlot[i] = equatorChar;
			slotBlank[i] = blankChar;
			slotPiece[i] = blankChar;
		}
	}
	bool drawLines_P(int place[2])
	{
		bool availableMovement = false;
		int p_y = place[0] - 1;
		int cas = 0;
		if (place[0] == 6)
		{
			cas = 2;
		}
		else
		{
			cas = 1;
		}
		for (int i = 0; i < cas; i++)
		{
			if (slots[p_y][place[1]] == PiecesChar::char_free)
			{
				slots[p_y][place[1]] = '*';
				availableMovement = true;
				p_y--;
			}
			else
			{
				break;
			}
		}
		return availableMovement;
	}
	void undrawLines_P(int place[2])
	{
		int p_y = place[0] - 1;
		int cas = 0;
		if (place[0] == 6)
		{
			cas = 2;
		}
		else
		{
			cas = 1;
		}
		for (int j = 0; j < cas; j++)
		{
			if (slots[p_y][place[1]] == '*')
			{
				slots[p_y][place[1]] = PiecesChar::char_free;
				p_y--;
			}
			else
			{
				break;
			}
		}
	}
	void undrawLines(int place[2])
	{
		//(+x) line
		for (int j = place[1] + 1; j < width; j++)
		{
			if (slots[place[0]][j] == '*')
				slots[place[0]][j] = PiecesChar::char_free;
			else
				break;
		}
		//(+y) line
		for (int i = place[0] - 1; - 1 < i; i--)
		{
			if (slots[i][place[1]] == '*')
				slots[i][place[1]] = PiecesChar::char_free;
			else
				break;
		}
		//(-x) line
		for (int j = place[1] - 1; - 1 < j; j--)
		{
			if (slots[place[0]][j] == '*')
				slots[place[0]][j] = PiecesChar::char_free;
			else
				break;
		}
		//(-y) line
		for (int i = place[0] + 1; i < height; i++)
		{
			if (slots[i][place[1]] == '*')
				slots[i][place[1]] = PiecesChar::char_free;
			else
				break;
		}
	}
	bool drawJumps(int place[2]) //Knight Jumps
	{
		bool availableMovement = false;
		if ((place[0] > 1) && (place[1] > 0) && (slots[place[0] - 2][place[1] - 1] == PiecesChar::char_free))
		{
			slots[place[0] - 2][place[1] - 1] = '*';
			availableMovement = true;
		}
		if ((place[0] > 1) && (place[1] < 7) && (slots[place[0] - 2][place[1] + 1] == PiecesChar::char_free))
		{
			slots[place[0] - 2][place[1] + 1] = '*';
			availableMovement = true;
		}
		if ((place[0] > 0) && (place[1] > 1) && (slots[place[0] - 1][place[1] - 2] == PiecesChar::char_free))
		{
			slots[place[0] - 1][place[1] - 2] = '*';
			availableMovement = true;
		}
		if ((place[0] < 7) && (place[1] > 1) && (slots[place[0] + 1][place[1] - 2] == PiecesChar::char_free))
		{
			slots[place[0] + 1][place[1] - 2] = '*';
			availableMovement = true;
		}
		if ((place[0] < 6) && (place[1] > 0) && (slots[place[0] + 2][place[1] - 1] == PiecesChar::char_free))
		{
			slots[place[0] + 2][place[1] - 1] = '*';
			availableMovement = true;
		}
		if ((place[0] < 6) && (place[1] < 7) && (slots[place[0] + 2][place[1] + 1] == PiecesChar::char_free))
		{
			slots[place[0] + 2][place[1] + 1] = '*';
			availableMovement = true;
		}
		if ((place[0] > 0) && (place[1] < 6) && (slots[place[0] - 1][place[1] + 2] == PiecesChar::char_free))
		{
			slots[place[0] - 1][place[1] + 2] = '*';
			availableMovement = true;
		}
		if ((place[0] < 7) && (place[1] < 6) && (slots[place[0] + 1][place[1] + 2] == PiecesChar::char_free))
		{
			slots[place[0] + 1][place[1] + 2] = '*';
			availableMovement = true;
		}
		return availableMovement;
	}
	void undrawJumps(int place[2])
	{
		if ((place[0] > 1) && (place[1] > 0) && (slots[place[0] - 2][place[1] - 1] == '*'))
		{
			slots[place[0] - 2][place[1] - 1] = PiecesChar::char_free;
		}
		if ((place[0] > 1) && (place[1] < 7) && (slots[place[0] - 2][place[1] + 1] == '*'))
		{
			slots[place[0] - 2][place[1] + 1] = PiecesChar::char_free;
		}
		if ((place[0] > 0) && (place[1] > 1) && (slots[place[0] - 1][place[1] - 2] == '*'))
		{
			slots[place[0] - 1][place[1] - 2] = PiecesChar::char_free;
		}
		if ((place[0] < 7) && (place[1] > 1) && (slots[place[0] + 1][place[1] - 2] == '*'))
		{
			slots[place[0] + 1][place[1] - 2] = PiecesChar::char_free;
		}
		if ((place[0] < 6) && (place[1] > 0) && (slots[place[0] + 2][place[1] - 1] == '*'))
		{
			slots[place[0] + 2][place[1] - 1] = PiecesChar::char_free;
		}
		if ((place[0] < 6) && (place[1] < 7) && (slots[place[0] + 2][place[1] + 1] == '*'))
		{
			slots[place[0] + 2][place[1] + 1] = PiecesChar::char_free;
		}
		if ((place[0] > 0) && (place[1] < 6) && (slots[place[0] - 1][place[1] + 2] == '*'))
		{
			slots[place[0] - 1][place[1] + 2] = PiecesChar::char_free;
		}
		if ((place[0] < 7) && (place[1] < 6) && (slots[place[0] + 1][place[1] + 2] == '*'))
		{
			slots[place[0] + 1][place[1] + 2] = PiecesChar::char_free;
		}
	}
	bool drawLines(int place[2])
	{
		bool availableMovement = false;
		//(+x) line
		for (int j = place[1] + 1; j < width; j++)
		{
			if (slots[place[0]][j] == PiecesChar::char_free)
			{
				slots[place[0]][j] = '*';
				availableMovement = true;
			}
			else
				break;
		}
		//(+y) line
		for (int i = place[0] - 1; - 1 < i; i--)
		{
			if (slots[i][place[1]] == PiecesChar::char_free)
			{
				slots[i][place[1]] = '*';
				availableMovement = true;
			}
			else
				break;
		}
		//(-x) line
		for (int j = place[1] - 1; - 1 < j; j--)
		{
			if (slots[place[0]][j] == PiecesChar::char_free)
			{
				slots[place[0]][j] = '*';
				availableMovement = true;
			}
			else
				break;
		}
		//(-y) line
		for (int i = place[0] + 1; i < height; i++)
		{
			if (slots[i][place[1]] == PiecesChar::char_free)
			{
				slots[i][place[1]] = '*';
				availableMovement = true;
			}
			else
				break;
		}
		return availableMovement;
	}
	void undrawDiagonals(int place[2])
	{
		int i, j;
		//(+x;+y) diagonal
		i = place[0] - 1;
		j = place[1] + 1;
		for (; (-1 < i) && (j < width); (i--) && (j++))
		{
			if (slots[i][j] == '*')
			{
				slots[i][j] = PiecesChar::char_free;
			}
			else
				break;
		}
		//(-x;+y) diagonal
		i = place[0] - 1;
		j = place[1] - 1;
		for (; (-1 < i) && (-1 < j); (i--) && (j--))
		{
			if (slots[i][j] == '*')
			{
				slots[i][j] = PiecesChar::char_free;
			}
			else
				break;
		}
		//(-x;-y) diagonal
		i = place[0] + 1;
		j = place[1] - 1;
		for (; (i < height) && (-1 < j); (i++) && (j--))
		{
			if (slots[i][j] == '*')
			{
				slots[i][j] = PiecesChar::char_free;
			}
			else
				break;
		}
		//(+x;-y) diagonal
		i = place[0] + 1;
		j = place[1] + 1;
		for (; (i < height) && (j < width); (i++) && (j++))
		{
			if (slots[i][j] == '*')
			{
				slots[i][j] = PiecesChar::char_free;
			}
			else
				break;
		}
	}

	bool drawDiagonals(int place[2])
	{
		bool availableMovement = false;
		int i, j;
		// while ((-1 < i) && (-1 < j))
		// {
		// }
		//(+x;+y) diagonal
		i = place[0] - 1;
		j = place[1] + 1;
		for (; (-1 < i) && (j < width); (i--) && (j++))
		{
			if (slots[i][j] == PiecesChar::char_free)
			{
				slots[i][j] = '*';
				availableMovement = true;
			}
			else
				break;
		}
		// for (int i = place[0] - 1; (-1 < i) && (j < width); i--)
		// {
		// 	j++;
		// 	if (slots[i][j] == PiecesChar::char_free)
		// 		slots[i][j] = '*';
		// 	else
		// 		break;
		// }
		// j = place[1];
		// for(int xy[2] = {place[0] + 1 ,place[1]-1}; ()&&();xy[0]++)

		//(-x;+y) diagonal
		i = place[0] - 1;
		j = place[1] - 1;
		for (; (-1 < i) && (-1 < j); (i--) && (j--))
		{
			if (slots[i][j] == PiecesChar::char_free)
			{
				slots[i][j] = '*';
				availableMovement = true;
			}
			else
				break;
		}
		//(-x;-y) diagonal
		i = place[0] + 1;
		j = place[1] - 1;
		for (; (i < height) && (-1 < j); (i++) && (j--))
		{
			if (slots[i][j] == PiecesChar::char_free)
			{
				slots[i][j] = '*';
				availableMovement = true;
			}
			else
				break;
		}
		//(+x;-y) diagonal
		i = place[0] + 1;
		j = place[1] + 1;
		for (; (i < height) && (j < width); (i++) && (j++))
		{
			if (slots[i][j] == PiecesChar::char_free)
			{
				slots[i][j] = '*';
				availableMovement = true;
			}
			else
				break;
		}
		return availableMovement;
	}

	void initGameboard()
	{
		for (int i = 0; i < width; i++)
			for (int j = 0; j < height; j++)
				slots[i][j] = PiecesChar::char_free;
	}

	void fillGameboard(int accumulated[6], int total, int bearings[][2], bool player)
	{

		int piece = 0;
		int pieceIndex = 0;

		char char_king;	 // char de rey
		char char_queen; // char de reina
		char char_rook;	 // char de ...
		char char_knight;
		char char_bishop;
		char char_pawn;

		King *kings_ptrptr;
		Queen *queens_ptrptr;
		Rook *rooks_ptrptr;
		Knight *knights_ptrptr;
		Bishop *bishops_ptrptr;
		Pawn *pawns_ptrptr;

		if (player) // P1
		{
			char_king = PiecesChar::charP1_king;
			char_queen = PiecesChar::charP1_queen;
			char_rook = PiecesChar::charP1_rook;
			char_knight = PiecesChar::charP1_knight;
			char_bishop = PiecesChar::charP1_bishop;
			char_pawn = PiecesChar::charP1_pawn;

			kings_ptrptr = P1_kings_ptr;
			queens_ptrptr = P1_queens_ptr;
			rooks_ptrptr = P1_rooks_ptr;
			knights_ptrptr = P1_knights_ptr;
			bishops_ptrptr = P1_bishops_ptr;
			pawns_ptrptr = P1_pawns_ptr;
		}
		else // P2
		{
			char_king = PiecesChar::charP2_king;
			char_queen = PiecesChar::charP2_queen;
			char_rook = PiecesChar::charP2_rook;
			char_knight = PiecesChar::charP2_knight;
			char_bishop = PiecesChar::charP2_bishop;
			char_pawn = PiecesChar::charP2_pawn;

			kings_ptrptr = P2_kings_ptr;
			queens_ptrptr = P2_queens_ptr;
			rooks_ptrptr = P2_rooks_ptr;
			knights_ptrptr = P2_knights_ptr;
			bishops_ptrptr = P2_bishops_ptr;
			pawns_ptrptr = P2_pawns_ptr;
		}

		//kings, queens, rooks, knights, bishops and pawns.

		for (int i = 0; i < total; i++)
		{
			if (i < accumulated[piece])
			{
				switch (piece)
				{
				case 0: //King
					kings_ptrptr[pieceIndex] = King(bearings[i], player);
					slots[bearings[i][0]][bearings[i][1]] = char_king;
					break;
				case 1: //Queen
					queens_ptrptr[pieceIndex] = Queen(bearings[i], player);
					slots[bearings[i][0]][bearings[i][1]] = char_queen;
					break;
				case 2: //Rook
					rooks_ptrptr[pieceIndex] = Rook(bearings[i], player);
					slots[bearings[i][0]][bearings[i][1]] = char_rook;
					break;
				case 3: //Knight
					knights_ptrptr[pieceIndex] = Knight(bearings[i], player);
					slots[bearings[i][0]][bearings[i][1]] = char_knight;
					break;
				case 4: //Bishop
					bishops_ptrptr[pieceIndex] = Bishop(bearings[i], player);
					slots[bearings[i][0]][bearings[i][1]] = char_bishop;
					break;
				case 5: //Pawn
					pawns_ptrptr[pieceIndex] = Pawn(bearings[i], player);
					slots[bearings[i][0]][bearings[i][1]] = char_pawn;
					break;
				default:
					cout << "\nAn error happened while initializing" << endl;
					cout << "iterator\t: " << i << endl;
					cout << "accumulated\t: " << accumulated[piece] << endl;
					cout << "piece\t: " << piece << endl;
					cout << "pieceIndex\t: " << pieceIndex << endl;
					break;
				}
				pieceIndex++;
			}
			else
			{
				i -= 1;
				piece += 1;
				pieceIndex = 0;
			}
		}
	}

	/*
	int getEntity(int place[2])
	{
		switch (slots[place[0]][place[1]])
		{
		case PiecesChar::char_free:
			return PiecesInt::int_free;
			break;
		case PiecesChar::charP1_king:
			return PiecesInt::intP1_king;
			break;
		case PiecesChar::charP1_queen:
			return PiecesInt::intP1_queen;
			break;
		case PiecesChar::charP1_rook:
			return PiecesInt::intP1_rook;
			break;
		case PiecesChar::charP1_bishop:
			return PiecesInt::intP1_bishop;
			break;
		case PiecesChar::charP1_knight:
			return PiecesInt::intP1_knight;
			break;
		case PiecesChar::charP1_pawn:
			return PiecesInt::intP1_pawn;
			break;
		case PiecesChar::charP2_king:
			return PiecesInt::intP2_king;
			break;
		case PiecesChar::charP2_queen:
			return PiecesInt::intP2_queen;
			break;
		case PiecesChar::charP2_rook:
			return PiecesInt::intP2_rook;
			break;
		case PiecesChar::charP2_bishop:
			return PiecesInt::intP2_bishop;
			break;
		case PiecesChar::charP2_knight:
			return PiecesInt::intP2_knight;
			break;
		case PiecesChar::charP2_pawn:
			return PiecesInt::intP2_pawn;
			break;
		}
	}
		*/
};
