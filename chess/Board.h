#pragma once

#include "Consts.h"
#include "IFigure.h"
#include "Bishop.h"
#include "Rook.h"
#include "Pawn.h"
#include "King.h"
#include "Knight.h"
#include "Queen.h"
#include "Player.h"
#include <string>

class Board
{
public:
	Board();
	~Board();
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
	int isCheck();
	bool isCheckmate();
	bool willCheck(const int src, const int dest);
	int findKing();
	int isCastle(const int src, const int dest);
	void castle(const int src, const int dest, const int isCas);
	int isEnPassant(const int src, const int dest);
	void enPassant(const int src, const int dest);
};

