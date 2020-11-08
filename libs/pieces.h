// /*
enum PiecesInt
{
	free = 0,
	king = 1,
	queen = 2,
	rook = 3,
	knight = 4,
	bishop = 5,
	pawn = 6,

	P1_king = 1,
	P1_queen = 2,
	P1_rook = 3,
	P1_knight = 4,
	P1_bishop = 5,
	P1_pawn = 6,

	P2_king = -1,
	P2_queen = -2,
	P2_rook = -3,
	P2_knight = -4,
	P2_bishop = -5,
	P2_pawn = -6
};
// */
enum PiecesChar
{
	free = ' ',
	king = 'r',
	queen = 'q',
	rook = 't',
	knight = 'c',
	bishop = 'a',
	pawn = 'p',

	P1_king = 'r',
	P1_queen = 'q',
	P1_rook = 't',
	P1_knight = 'c',
	P1_bishop = 'a',
	P1_pawn = 'p',

	P2_king = 'R',
	P2_queen = 'Q',
	P2_rook = 'T',
	P2_knight = 'C',
	P2_bishop = 'A',
	P2_pawn = 'P'

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
	bool player;
	King() {}
	King(int iPosition[], bool iPlayer)
	{
		position[0] = iPosition[0];
		position[1] = iPosition[1];
		bool player = iPlayer;
	}
};

class Queen
{
public:
	int points = 9;
	int position[2];
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
	Gameboard(int iWidth = 8, int iHeight = 8)
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
		case PiecesChar::P1_king:
			return PiecesInt::P1_king;
			break;
		case PiecesChar::P1_queen:
			return PiecesInt::P1_queen;
			break;
		case PiecesChar::P1_rook:
			return PiecesInt::P1_rook;
			break;
		case PiecesChar::P1_bishop:
			return PiecesInt::P1_bishop;
			break;
		case PiecesChar::P1_knight:
			return PiecesInt::P1_knight;
			break;
		case PiecesChar::P1_pawn:
			return PiecesInt::P1_pawn;
			break;
		case PiecesChar::P2_king:
			return PiecesInt::P2_king;
			break;
		case PiecesChar::P2_queen:
			return PiecesInt::P2_queen;
			break;
		case PiecesChar::P2_rook:
			return PiecesInt::P2_rook;
			break;
		case PiecesChar::P2_bishop:
			return PiecesInt::P2_bishop;
			break;
		case PiecesChar::P2_knight:
			return PiecesInt::P2_knight;
			break;
		case PiecesChar::P2_pawn:
			return PiecesInt::P2_pawn;
			break;

		default:
			return PiecesInt::free;
			break;
		}
	}
};
