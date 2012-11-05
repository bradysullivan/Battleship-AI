/*
	Sample Battleship AI in C++

	GameBoard.cpp
*/

#include "GameBoard.h"

GameBoard::GameBoard(int x, int y)
{
	x_max = x - 1; // Subtract 1 to account for starting indiced at 0. Maps (aka fields) will be made x by y sized. Ie. 0 through x-1.
	y_max = y - 1;

	my_field = new int*[y];
	for(int i = 0; i < x; ++i)
	{
		my_field[i] = new int[x];
	}

	op_field = new int*[y];
	for(int i = 0; i < x; ++i)
	{
		op_field[i] = new int[x];
	}

	return;
}

int GameBoard::setPiece(Ship size, Position pos)
{
	int retval = 0;
	if(pos.x > x_max || pos.y > y_max)
	{
		retval = 1; // Invalid position.
	}
	else
	{
		switch(pos.rotation)
		{
		case 0:
			if(pos.x + (size - 1) > x_max)
			{
				retval = 1; // Invalid position.
			} 
			else 
			{
				for(int i = 0; i < size; ++i)
				{
					if(my_field[pos.y][pos.x + i] != 0)	// Make sure spot isn't already occupied.
						retval = 1;

					// my_field[y][x]
					my_field[pos.y][pos.x + i] = 1; // Signal as occupied position.
				}
			}
			break;

		case 1:
			if(pos.y + (size - 1) > y_max)
			{
				retval = 1; // Invalid position.
			}
			else
			{
				for(int i = 0; i < size; ++i)
				{
					if(my_field[pos.y + i][pos.x] != 0)
						retval = 1;

					my_field[pos.y + i][pos.x] = 1; // Occupied.
				}
			}
			break;

		case 2:
			if(pos.x - (size - 1) < 0)
			{
				retval = 1; // Invalid position.
			}
			else
			{
				for(int i = 0; i < size; ++i)
				{
					if(my_field[pos.y][pos.x - i] != 0)
						retval = 1;

					my_field[pos.y][pos.x - i] = 1; // Occupied. 
				}
			}
			break;

		case 3:
			if(pos.y - (size - 1) < 0)
			{
				retval = 1; // Invalid position.
			}
			else
			{
				for(int i = 0; i < size; ++i)
				{
					if(my_field[pos.y - i][pos.x] != 0)
						retval = 1;

					my_field[pos.y - i][pos.x] = 1;	// Occupied.
				}
			}
			break;

		default:
			retval = 1; // Invalid rotation.
			break;
		}
	}
	if(retval == 0)	// Successful placement of ship.
	{

	}

	return retval;
}