/*
	Sample Battleship AI in C++

	BattleshipAI.cpp
*/

#include "BattleshipAI.h"


BattleshipAI::BattleshipAI()
{
	game_board = NULL;

	state = Idle;

	nick = "";
	channel = "";
	referee = "";
}

string BattleshipAI::handler(string raw_in)
{
	vector<string> msg = parse(raw_in);
	// Typical in, MSGTYPE:sender:recipient:message
	if(msg[0] != "PRIVMSG" || msg.size() != 4)
	{
		return "";
	}
	string sender = msg[1];
	string recipient = msg[2];
	string input = msg[3];

	string output = "";


	switch(state)
	{
		case Config:
			if(channel == "")
			{
				if(recipient.compare(0,1,"#") == 0)	// Compare the first char of recipient to determine if it's the channel name.
				{
					channel = recipient;
				}
			}
			if(referee == "")
			{
				output = "PRIVMSG:" + recipient + ":!ref\n";
				referee = " ";
			}
			else if (referee == " ")
			{
				if(recipient != channel)
				{
					nick = recipient;
					referee = sender;
				}
			}
			if(channel != "" && referee != "" && nick != "")
			{
				state = Prep;
				output = "PRIVMSG:" + channel + ":Ready to test!\n";
			}
			break;

		case Idle:
			if(input == "[start]")
			{
				state = Config;
				output = "PRIVMSG:" + channel + ":!bs-test\n";
			}
			break;

		case Prep:
			game_board = new GameBoard(10,10);

			output = "PRIVMSG:" + referee + ":Pieces, " + placePieces(10, 10) + "\n";
			break;
	}

	return output;
}

// To do: Fix the return values of either this function or setPiece().
string BatleshipAI::placePieces(int x, int y)
{
	string ret = "";

	Position pos;
	pos.x = 0;
	pos.y = 0;
	pos.rotation = 0;
	ret += game_board->setPiece(Carrier, pos) + ",";

	pos.x = 2;
	pos.y = 9;
	pos.rotation = 1;
	ret += game_board->setPiece(Battleship, pos) + ",";

	pos.x = 9;
	pos.y = 3;
	pos.rotation = 3;
	ret += game_board->setPiece(Submarine, pos) + ",";

	pos.x = 4;
	pos.y = 9;
	pos.rotation = 1;
	ret += game_board->setPiece(Destroyer, pos) + ",";

	pos.x = 6;
	pos.y = 2;
	pos.rotation = 2;
	ret += game_board->setPiece(Cruiser, pos);

	return ret;
}


string BattleshipAI::move()
{

	return "";
}


vector<string> BattleshipAI::parse(string in)
{
	string sec = "";
	vector<string> ret;
	int l = in.length();
	for(int i = 0; i < l; ++i)
	{
		if(in[i] == ':')
		{
			ret.push_back(sec);
			sec = "";
		}
		else
		{
			sec += in[i];
		}
	}
	ret.push_back(sec);
	return ret;
}
