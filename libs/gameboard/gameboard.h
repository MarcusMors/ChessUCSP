#include "libs/pieces/pieces.h"

class Gameboard
{
public:
	int slots[8][8];
	int width;
	int height;
	Gameboard() {}
	Gameboard(int iWidth, int iHeight)
	{
		width = iWidth;
		height = iHeight;
		fill();
	}
	void move(int start[], int end[])
	{
	}

private:
	void fill()
	{
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
				i -= 1;
				piece += 1;
				pieceIndex = 0;
			}
			for (int i = 0; i < width; i++)
			{
				for (int j = 0; i < height; j++)
				{
				}
			}
		}
	}
	int getEntity(int place[2])
	{
		switch (slots[place[0]][place[1]])
		{
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

		default:
			return PiecesInt::int_free;
			break;
		}
	}
};
