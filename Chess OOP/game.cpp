//this project is created by Arham irfan from FAST-NU university
#include<iostream>
#include<string>
#include<iomanip>
#include<math.h>
using namespace std;
class pieces
{
public:
	string name;
	int player;
	int x1, y1, x2, y2;
public:
	pieces()
	{
		name = " ";
		player = 0;
	}
	pieces(string naam, int players)
	{
		name = naam;
		player = players;
	}
	virtual void move(pieces* chess[][8], int x1, int y1, int x2, int y2) {};
	friend void displayboard(pieces* chess[][8]);
};
class pawn :public pieces
{
public:
	pawn()
	{
		name = " ";
		player = 0;
	}
	pawn(string pwn, int n)
	{
		name = pwn;
		player = n;
	}
	void move(pieces* chess[][8], int x1, int y1, int x2, int y2)
	{
		if (x1<8 && x1>-1 && y1<8 && y1>-1 && x2<8 && x2>-1 && y2<8 && y2>-1)
		{
			if (chess[x2][y2]->player != chess[x1][y1]->player)
			{
				if (chess[x1][y1]->player == 1)
				{
					if ((x2 == x1 - 1 && y2 == y1) || ((x2 == x1 - 2 && y2 == y1) && (chess[x1][y1]->player == 1) && x1 == 6))
					{
						delete chess[x2][y2];
						chess[x2][y2] = new pawn(chess[x1][y1]->name, chess[x1][y1]->player);
						chess[x1][y1]->player = 0;
						chess[x1][y1]->name = " ";
					}
					else
						cout << " invalid move" << endl;
				}
				else if (chess[x1][y1]->player == 2)
				{
					if ((x2 == x1 + 1 && y2 == y1) || ((x2 == x1 + 2 && y2 == y1) && (chess[x1][y1]->player == 2) && x1 == 1))
					{
						delete chess[x2][y2];
						chess[x2][y2] = new pawn(chess[x1][y1]->name, chess[x1][y1]->player);
						chess[x1][y1]->player = 0;
						chess[x1][y1]->name = " ";
					}
					else
						cout << " invalid move" << endl;
				}
			}
		}
	}
};
class rook :public pieces
{
public:
	rook()
	{
		name = " ";
		player = 0;
	}
	rook(string rk, int n)
	{
		name = rk;
		player = n;
	}
	void move(pieces* chess[][8], int x1, int y1, int x2, int y2)
	{
		if (x1<8 && x1>-1 && y1<8 && y1>-1 && x2<8 && x2>-1 && y2<8 && y2>-1)
		{
			if (chess[x2][y2]->player != chess[x1][y1]->player)
			{
				if ((x1 == x2 && (y2 > y1 || y2 < y1)) || (y1 == y2 && (x2<x1 || x2>x1)))
				{
					delete chess[x2][y2];
					chess[x2][y2] = new rook(chess[x1][y1]->name, chess[x1][y1]->player);
					chess[x1][y1]->player = 0;
					chess[x1][y1]->name = " ";
				}
			}
		}
	}
};
class bishop :public pieces
{
public:
	bishop()
	{
		name = " ";
		player = 0;
	}
	bishop(string bshp, int n)
	{
		name = bshp;
		player = n;
	}
	void move(pieces* chess[][8], int x1, int y1, int x2, int y2)
	{
		int num1 = abs(x1 - x2), num2 = abs(y1 - y2);
		if (x1<8 && x1>-1 && y1<8 && y1>-1 && x2<8 && x2>-1 && y2<8 && y2>-1)
		{
			if (chess[x2][y2]->player != chess[x1][y1]->player)
			{
				if (num1 == num2)
				{
					delete chess[x2][y2];
					chess[x2][y2] = new bishop(chess[x1][y1]->name, chess[x1][y1]->player);
					chess[x1][y1]->player = 0;
					chess[x1][y1]->name = " ";
				}
			}
		}
	}
};
class knight :public pieces
{
public:
	knight()
	{
		name = " ";
		player = 0;
	}
	knight(string kgt, int n)
	{
		name = kgt;
		player = n;
	}
	void move(pieces* chess[][8], int x1, int y1, int x2, int y2)
	{
		if (x1<8 && x1>-1 && y1<8 && y1>-1 && x2<8 && x2>-1 && y2<8 && y2>-1)
		{
			if (chess[x2][y2]->player != chess[x1][y1]->player)
			{
				if ((x2 == x1 - 2 && y2 == y1 + 1) || (x2 == x1 - 2 && y2 == y1 - 1) || (x2 == x1 + 2 && y2 == y1 + 1) || (x2 == x1 + 2 && y2 == y1 - 1) || (x2 == x1 + 1 && y2 == y1 + 2) || (x2 == x1 + 1 && y2 == y1 - 2) || (x2 == x1 - 1 && y2 == y1 + 2) || (x2 == x1 - 1 && y2 == y1 - 2))
				{
					delete chess[x2][y2];
					chess[x2][y2] = new knight(chess[x1][y1]->name, chess[x1][y1]->player);
					chess[x1][y1]->player = 0;
					chess[x1][y1]->name = " ";
				}
			}
			else
			{
				cout << " invalid move";
			}
		}
	}
};
class queen :public pieces
{
public:
	queen()
	{
		name = " ";
		player = 0;
	}
	queen(string qn, int n)
	{
		name = qn;
		player = n;
	}
	void move(pieces* chess[][8], int x1, int y1, int x2, int y2)
	{
		int num1 = abs(x1 - x2), num2 = abs(y1 - y2);
		if (x1<8 && x1>-1 && y1<8 && y1>-1 && x2<8 && x2>-1 && y2<8 && y2>-1)
		{
			if (chess[x2][y2]->player != chess[x1][y1]->player)
			{
				if ((num1 == num2) || (x1 == x2 && (y2 > y1 || y2 < y1)) || (y1 == y2 && (x2<x1 || x2>x1)))
				{
					delete chess[x2][y2];
					chess[x2][y2] = new queen(chess[x1][y1]->name, chess[x1][y1]->player);
					chess[x1][y1]->player = 0;
					chess[x1][y1]->name = " ";
				}
			}
		}

	}
};
class king :public pieces
{
public:
	king()
	{
	name:" ";
		player = 0;

	}
	king(string kg, int n)
	{
		name = kg;
		player = n;
	}
	void move(pieces* chess[][8], int x1, int y1, int x2, int y2)
	{
		if (x1<8 && x1>-1 && y1<8 && y1>-1 && x2<8 && x2>-1 && y2<8 && y2>-1)
		{
			if (chess[x2][y2]->player != chess[x1][y1]->player)
			{
				if ((x1 == x2 && (y2 == y1 + 1 || y2 == y1 - 1)) || (y1 == y2 && (x2 == x1 + 1 || x2 == x1 - 1)) || (x2 == x1 + 1 && y2 == y1 - 1) || (x2 == x1 + 1 && y2 == y1 + 1) || (x2 == x1 - 1 && y2 == y1 - 1) || (x2 == x1 - 1 && y2 == y1 + 1))
				{
					delete chess[x2][y2];
					chess[x2][y2] = new king(chess[x1][y1]->name, chess[x1][y1]->player);
					chess[x1][y1]->player = 0;
					chess[x1][y1]->name = " ";
				}
			}
		}
	}
};
int main()
{
	int x_cordinate, y_cordinate, x_location, y_location;
	pieces* chess[8][8];
	chess[0][0] = new rook("R1", 2);
	chess[0][1] = new knight("H1", 2);
	chess[0][2] = new bishop("B1", 2);
	chess[0][3] = new queen("Qn", 2);
	chess[0][4] = new king("Kn", 2);
	chess[0][5] = new bishop("B2", 2);
	chess[0][6] = new knight("H2", 2);
	chess[0][7] = new rook("R2", 2);
	chess[1][0] = new pawn("P1", 2);
	chess[1][1] = new pawn("P2", 2);
	chess[1][2] = new pawn("P3", 2);
	chess[1][3] = new pawn("P4", 2);
	chess[1][4] = new pawn("P5", 2);
	chess[1][5] = new pawn("P6", 2);
	chess[1][6] = new pawn("P7", 2);
	chess[1][7] = new pawn("P8", 2);
	chess[7][0] = new rook("r1", 1);
	chess[7][1] = new knight("h1", 1);
	chess[7][2] = new bishop("b1", 1);
	chess[7][3] = new queen("qn", 1);
	chess[7][4] = new king("kn", 1);
	chess[7][5] = new bishop("b2", 1);
	chess[7][6] = new knight("h2", 1);
	chess[7][7] = new rook("r2", 1);
	chess[6][0] = new pawn("p1", 1);
	chess[6][1] = new pawn("p2", 1);
	chess[6][2] = new pawn("p3", 1);
	chess[6][3] = new pawn("p4", 1);
	chess[6][4] = new pawn("p5", 1);
	chess[6][5] = new pawn("p6", 1);
	chess[6][6] = new pawn("p7", 1);
	chess[6][7] = new pawn("p8", 1);
	for (int i = 2; i < 6; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			chess[i][j] = new pieces("  ", 0);
		}
	}
	displayboard(chess);
	string checking;
	bool turn = true;
	while (1)
	{
		if (turn == true)
		{
			cout << "\n Player-1 turn : \n Enter location ROW || COLUMN to select piece : ";
			cin >> x_cordinate >> y_cordinate;
			cout << " Enter x-row || y-column location to move : ";
			cin >> x_location >> y_location;
			if (chess[x_cordinate][y_cordinate]->player == 1)
			{
				checking = chess[x_cordinate][y_cordinate]->name;
				chess[x_cordinate][y_cordinate]->move(chess, x_cordinate, y_cordinate, x_location, y_location);

				if (checking == chess[x_location][y_location]->name)
				{
					if (checking != chess[x_cordinate][y_cordinate]->name)
						turn = false;
				}
			}
			system("cls");
			displayboard(chess);
		}
		else if (turn == false)
		{
			cout << "\n Player-2 turn : \n Enter location ROW || COLUMN to select piece : ";
			cin >> x_cordinate >> y_cordinate;
			cout << " Enter x-row || y-column location to move : ";
			cin >> x_location >> y_location;
			if (chess[x_cordinate][y_cordinate]->player == 2)
			{
				checking = chess[x_cordinate][y_cordinate]->name;
				chess[x_cordinate][y_cordinate]->move(chess, x_cordinate, y_cordinate, x_location, y_location);

				if (checking == chess[x_location][y_location]->name)
				{
					if (checking != chess[x_cordinate][y_cordinate]->name)
					{
						turn = true;
					}
				}
			}
			system("cls");
			displayboard(chess);
		}
	}
}
void displayboard(pieces* chess[][8])
{
	for (int i = 0; i < 2; i++)
	{
		cout << "       " << i;
	}
	for (int i = 2; i <= 7; i++)
	{
		cout << "     " << i;
	}
	cout << endl;
	for (int i = 0; i < 8; i++)
	{
		cout << setw(4);
		cout << i << " ";
		for (int j = 0; j < 8; j++)
		{
			cout << setw(2);
			cout << setw(2) << "|" << setw(4) << chess[i][j]->name;
			if (j == 7)
			{
				cout << " |";
				cout << endl << "      ------------------------------------------------";
			}
		}
		cout << endl;
	}
}
