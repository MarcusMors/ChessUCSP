// #ifndef CHESS_UCSP_PIECES_H
// #define CHESS_UCSP_PIECES_H
// #endif

#pragma once

class Piece
{
public:
	int position[2];
	int movements = 0;
	bool player;
	bool validCheck = false;
	Piece() {}
	Piece(int iPosition[2], bool iPlayer)
	{
		position[0] = iPosition[0];
		position[1] = iPosition[1];
		player = iPlayer;
	}
	void move(int place[2])
	{
		if (validCheck)
		{
			movements++;
			position[0] = place[0];
			position[0] = place[1];
			validCheck = false;
		}
	}

protected:
private:
};

//A derived class inherits all base class methods with the following exceptions −

//	 Constructors, destructors and copy constructors of the base class.
//	 Overloaded operators of the base class.
//	 The friend functions of the base class.

// Public Inheritance − When deriving a class from a public base class, public members of the base class become public members of the derived class and protected members of the base class become protected members of the derived class. A base class's private members are never accessible directly from a derived class, but can be accessed through calls to the public and protected members of the base class.

// Protected Inheritance − When deriving from a protected base class, public and protected members of the base class become protected members of the derived class.

// Private Inheritance − When deriving from a private base class, public and protected members of the base class become private members of the derived class.

//Multiple inheritance
//class derived-class: access baseA, access baseB....

class King : public Piece // Rey
{
public:
	bool checkmate = false;
	King() : Piece() {}
	King(int iPosition[2], bool iPlayer) : Piece(iPosition, iPlayer)
	{
		position[0] = iPosition[0];
		position[1] = iPosition[1];
		bool player = iPlayer;
	}
	bool validKingsideCastling(int bearingsKing[2], int bearingsRook[2])
	{
		bool valid;
		// king movements = 0?
		// tower movements = 0?
		// is in check?
		// are there pieces between?
		// are positions between endangered?
		return valid;
	}
	bool validQueensideCastling()
	{
		bool valid;
		// king movements = 0?
		// tower movements = 0?
		// is in check?
		// are there pieces between?
		// are positions between endangered?
		return valid;
	}
};

class Queen : public Piece
{
public:
	Queen() : Piece() {}
	Queen(int iPosition[2], bool iPlayer) : Piece(iPosition, iPlayer)
	{
		position[0] = iPosition[0];
		position[1] = iPosition[1];
		bool player = iPlayer;
	}
};

class Rook : public Piece
{
public:
	Rook() : Piece() {}
	Rook(int iPosition[2], bool iPlayer) : Piece(iPosition, iPlayer)
	{
		bool player = iPlayer;
	}
	bool validMovement()
	{
		bool valid;
		return valid;
	}
};

class Knight : public Piece
{
public:
	Knight() : Piece() {}
	Knight(int iPosition[2], bool iPlayer) : Piece(iPosition, iPlayer)
	{
		position[0] = iPosition[0];
		position[1] = iPosition[1];
		bool player = iPlayer;
	}
};

class Bishop : public Piece
{
public:
	Bishop() : Piece() {}
	Bishop(int iPosition[2], bool iPlayer) : Piece(iPosition, iPlayer)
	{
		position[0] = iPosition[0];
		position[1] = iPosition[1];
		bool player = iPlayer;
	}
};

class Pawn : public Piece //Peón
{
public:
	Pawn() : Piece() {}
	Pawn(int iPosition[2], bool iPlayer) : Piece(iPosition, iPlayer)
	{
		position[0] = iPosition[0];
		position[1] = iPosition[1];
		bool player = iPlayer;
	}
	// bool validate(int end[2])
	// {
	// 	int direction = position[1] - end[1];
	// 	if (player) // white
	// 	{
	// 	}
	// 	else // black
	// 	{
	// 	}

	// 	if (movements = 0)
	// 	{
	// 	}
	// 	else
	// 	{
	// 	}
	// }
};
