
enum PiecesInt
{
	int_free = 0,
	int_king = 1,
	int_queen = 2,
	int_rook = 3,
	int_knight = 4,
	int_bishop = 5,
	int_pawn = 6,

	intP1_king = 1,
	intP1_queen = 2,
	intP1_rook = 3,
	intP1_knight = 4,
	intP1_bishop = 5,
	intP1_pawn = 6,

	intP2_king = -1,
	intP2_queen = -2,
	intP2_rook = -3,
	intP2_knight = -4,
	intP2_bishop = -5,
	intP2_pawn = -6
};

enum PiecesChar
{
	char_free = ' ',

	// char_king = 'r',
	// char_queen = 'q',
	// char_rook = 't',
	// char_knight = 'c',
	// char_bishop = 'a',
	// char_pawn = 'p',

	charP1_king = 'r',
	charP1_queen = 'q',
	charP1_rook = 't',
	charP1_knight = 'c',
	charP1_bishop = 'a',
	charP1_pawn = 'p',

	charP2_king = 'R',
	charP2_queen = 'Q',
	charP2_rook = 'T',
	charP2_knight = 'C',
	charP2_bishop = 'A',
	charP2_pawn = 'P'

};

/*
class Pieces
{
public:
	char king;
	char queen;
	char rook;
	char knight;
	char bishop;
	char pawn;
	// int king = 1;
	// int queen = 2;
	// int rook = 3;
	// int knight = 4;
	// int bishop = 5;
	// int pawn = 6;

	int P1_king = 1;
	int P1_queen = 2;
	int P1_rook = 3;
	int P1_knight = 4;
	int P1_bishop = 5;
	int P1_pawn = 6;

	int P2_king = 1;
	int P2_queen = 2;
	int P2_rook = 3;
	int P2_knight = 4;
	int P2_bishop = 5;
	int P2_pawn = 6;
	Pieces()
	{
		king = 'k';
		queen = 'q';
		rook = 'r';
		knight = 'h';
		bishop = 'b';
		pawn = 'p';

		P1_king = 1;
		P1_queen = 2;
		P1_rook = 3;
		P1_knight = 4;
		P1_bishop = 5;
		P1_pawn = 6;
		P2_king = -1;
		P2_queen = -2;
		P2_rook = -3;
		P2_knight = -4;
		P2_bishop = -5;
		P2_pawn = -6;
	}

	static char getKing(Pieces pieces)
	{
		return pieces.king;
	}
};
*/
