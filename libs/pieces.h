
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
// */
enum PiecesChar
{
	char_free = ' ',
	char_king = 'r',
	char_queen = 'q',
	char_rook = 't',
	char_knight = 'c',
	char_bishop = 'a',
	char_pawn = 'p',

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

class King // Rey
{
public:
	int position[2];
	int movements = 0;
	bool player;
	bool checkMate = false;

	King() {}
	King(int iPosition[], bool iPlayer)
	{
		position[0] = iPosition[0];
		position[1] = iPosition[1];
		bool player = iPlayer;
	}
	bool canDoKingsideCastling(int bearingsKing[2], int bearingsRook[2])
	{
		// king movements = 0?
		// tower movements = 0?
		// is in check?
		// are there pieces between?
		// are positions between endangered?
	}
	bool canDoQueensideCastling()
	{
		// king movements = 0?
		// tower movements = 0?
		// is in check?
		// are there pieces between?
		// are positions between endangered?
	}
};

class Queen
{
public:
	int points = 9;
	int position[2];
	int movements = 0;
	bool player;
	Queen() {}
	Queen(int iPosition[], bool iPlayer)
	{
		position[0] = iPosition[0];
		position[1] = iPosition[1];
		bool player = iPlayer;
	}
};

class Rook
{
public:
	int points = 5;
	int position[2];
	int movements = 0;
	bool player;
	Rook() {}
	Rook(int iPosition[], bool iPlayer)
	{
		bool player = iPlayer;
	}
};

class Knight
{
public:
	int points = 3;
	int position[2];
	int movements = 0;
	bool player;
	Knight() {}
	Knight(int iPosition[2], bool iPlayer)
	{
		position[0] = iPosition[0];
		position[1] = iPosition[1];
		bool player = iPlayer;
	}
};

class Bishop
{
public:
	int points = 3;
	int position[2];
	int movements = 0;
	bool player;
	Bishop() {}
	Bishop(int iPosition[2], bool iPlayer)
	{
		position[0] = iPosition[0];
		position[1] = iPosition[1];
		bool player = iPlayer;
	}
};

class Pawn //Peón
{
public:
	int points = 1;
	int position[2];
	int movements = 0;
	bool player;
	Pawn() {}
	Pawn(int iPosition[2], bool iPlayer)
	{
		position[0] = iPosition[0];
		position[1] = iPosition[1];
		bool player = iPlayer;
	}
};

class Gameboard
{
public:
	bool turn;
	int slots[8][8];
	King king[2];
	Queen queen[2];
	Rook rook[4];
	Knight knight[4];
	Bishop bishop[4];
	Pawn pawns[16];
	int width;
	int height;
	Gameboard() {}
	Gameboard(int iWidth, int iHeight)
	{
		width = iWidth;
		height = iHeight;
	}
	void move(int start[], int end[])
	{
	}

private:
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
