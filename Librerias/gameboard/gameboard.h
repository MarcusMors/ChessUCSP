#include <iostream>
#include "../pieces/pieces.h"
#include "../enums/enums.h"
#include "../helpers.h"

class Gameboard
{
public:
	// 2D ptrptr?
	int slots[26][26];

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

	// Gameboard() {}
	Gameboard(int nP1_pieces[6], int nP2_pieces[6], int bearingsP1_pieces[][2], int bearingsP2_pieces[][2], int iWidth = 8, int iHeight = 8)
	{
		std::cout << "Inside Gameboard" << std::endl;
		width = iWidth;
		height = iHeight;

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
		std::cout << "Init Gameboard" << std::endl;
		initGameboard();
		std::cout << "filling the Gameboard" << std::endl;
		fillGameboard(accumulatedP1_pieces, totalP1_pieces, bearingsP1_pieces, true);  //P1
		fillGameboard(accumulatedP2_pieces, totalP2_pieces, bearingsP2_pieces, false); //P2
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
	void move(int start[2], int end[2])
	{
		char piece = slots[start[0]][start[1]];
		// how can we get the object?
		slots[start[0]][start[1]] = PiecesChar::char_free;
		slots[end[0]][end[1]] = piece;
	}
	void show()
	{
		int slotWidth = 7;
		int equatorFrameWidth = 3;
		int meridianFrameWidth = 1;
		char blankChar = ' ';
		char equatorChar = '_';
		char meridianChar = '|';
		char letter = 'A';
		int number = 1;

		char equatorFrame[equatorFrameWidth];
		char equatorSlot[slotWidth];
		char equatorBlank[equatorFrameWidth];
		char meridianFrame[meridianFrameWidth];
		char meridianBlank[meridianFrameWidth];
		char slotPiece[slotWidth];
		char slotBlank[slotWidth];

		// Init Arrays
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

		// Show the gameboard
		// Letters, upper gameframe
		std::cout << equatorBlank << meridianChar;
		for (int i = 0; i < width; i++)
		{
			slotPiece[slotWidth / 2] = ((char)letter + i);
			std::cout << slotPiece << meridianChar;
		}
		std::cout << std::endl;
		for (int i = 0; i < height; i++)
		{
			std::cout << equatorFrame << meridianChar;
			for (int j = 0; j < width; j++)
			{
				std::cout << equatorSlot << meridianChar;
			}
			std::cout << equatorFrame << std::endl;
			for (int j = 0; j < 2; j++)
			{
				std::cout << equatorBlank << meridianChar;
				for (int o = 0; o < slotWidth + 1; o++)
				{
					if (j == 1)
					{
						slotPiece[slotWidth / 2] = (char)slots[i][o];
						std::cout << slotPiece << meridianChar;
					}
					else
					{
						std::cout << slotBlank << meridianChar;
					}
				}
				std::cout << equatorBlank << std::endl;
			}
		}
		// Letters, bottom gameframe
		std::cout << equatorFrame << meridianChar;
		for (int j = 0; j < width; j++)
		{
			std::cout << equatorSlot << meridianChar;
		}
		std::cout << equatorFrame << std::endl;
		std::cout << equatorBlank << meridianChar;
		for (int i = 0; i < width; i++)
		{
			slotPiece[slotWidth / 2] = ((char)letter + i);
			std::cout << slotPiece << meridianChar;
		}
		std::cout << std::endl;
	}

private:
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
					std::cout << "\nAn error happened while initializing" << std::endl;
					std::cout << "iterator\t: " << i << std::endl;
					std::cout << "accumulated\t: " << accumulated[piece] << std::endl;
					std::cout << "piece\t: " << piece << std::endl;
					std::cout << "pieceIndex\t: " << pieceIndex << std::endl;
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
