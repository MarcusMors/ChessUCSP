
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
};

class King // Rey
{
};

class Queen // Reina
{
	int points = 9;
};

class Rook // Torre
{
	int points = 5;
};

class Knight // Caballo
{
	int points = 3;
};

class Bishop // Alfíl
{
	int points = 3;
};

class Pawn //Peón
{
	int points = 1;
};

class Gameboard // Tablero
{
public:
	bool turn;
	int slots[8][8];
	Pieces pieces;
	Gameboard(int iWidth = 8, int iHeight = 8)
	{
		int width = iWidth;
		int height = iHeight;
	}
	void move()
	{
	}

private:
	int getEntity(int place[2])
	{
		if (slots[place[0]][place[1]] == pieces.king)
		{
		}
		else if (slots[place[0]][place[1]] == pieces.king)
		{
		}
	}
};
