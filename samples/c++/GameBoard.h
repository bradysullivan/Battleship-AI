/*
	Sample Battleship AI in C++

	GameBoard.h
*/
#ifndef GAMEBOARD
#define GAMEBOARD

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>


using namespace std;

struct Position
{
	int x;
	int y;
	int rotation;
};

class GameBoard
{
private:
	int ** my_field;
	int ** op_field;
	int x_max;
	int y_max;

public:
	GameBoard(int, int);
	//~GameBoard();
	int setPiece(int, Position);

};

#include "GameBoard.cpp"
#endif