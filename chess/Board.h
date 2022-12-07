#pragma once
#define BOARD_LENGTH 8
#define START_MSG "rnbkqbnrpppppppp################################PPPPPPPPRNBKQBNR1"
#include "IFigure.h"
#include "Bishop.h"
#include "Rook.h"
#include "Pawn.h"
#include "King.h"
#include "Knight.h"
#include "Queen.h"
#include "Player.h"
#include <string>

class IFigure;

class Board
{
public:
	Board();
	~Board();
	void print() const;
	void parseMsg(const std::string msgToParse, int (& results)[2]);
	void updateBoard(const int src,const int dest);
	std::string getMsg()const;
	void changeTeam();
private:
	IFigure*  _board[BOARD_LENGTH][BOARD_LENGTH];
	Player _p1;
	Player _p2;
	std::string _msg;
	int _currTeam;
	bool _won;
};

