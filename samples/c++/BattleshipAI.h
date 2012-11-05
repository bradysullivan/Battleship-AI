/*
	Sample Battleship AI in C++

	BattleshipAI.h

	To do: Finish GameBoard to-dos. Fix either BattleshipAI.placePieces() or GameBoard.setPiece().
*/
#ifndef BATTLESHIP_AI
#define BATTLESHIP_AI

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

#include "GameBoard.h"

using namespace std;

struct Ship{
	string name;
	int size;
	Position pos;
	bool alive;
};


class BattleshipAI
{
private:
	GameBoard * game_board;

	enum State {
		Config,
		Idle,
		Prep,
		Search,
		Engage
	};

	enum Ship {
		Carrier = 5,
		Battleship = 4,
		Submarine = 3,
		Destroyer = 3,
		Cruiser = 2
	};

	State state;

	string channel;
	string referee;
	string nick;

	vector<Ship> ships;


	string move();
	void placePieces(int, int);

public:
	BattleshipAI();
	//~BattleshipAI();

	string handler(string input);

	static vector<string> parse(string);
};

#include "BattleshipAI.cpp"
#endif