#pragma once
#define BOARD_LENGTH 8
#define START_MSG "rnbkqbnrpppppppp################################PPPPPPPPRNBKQBNR1"

#include "IFigure.h"
class IFigure;
#include "Bishop.h"
#include "Rook.h"
#include "Pawn.h"
#include "King.h"
#include "Knight.h"
#include "Queen.h"
#include "Player.h"
#include <string>
#define VALID_MOV 0
#define VALID_MOV_CHECK 1
#define BAD_MOV_SRC_OP 2
#define BAD_MOV_DST_SP 3
#define BAD_MOV_MAKE_CHECK 4
#define BAD_MOV_WRONG_INDEX 5
#define BAD_MOV_WRONG_MOV 6
#define BAD_MOV_SAME_INDEX 7
#define VALID_MOV_CHECKMATE 8



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

