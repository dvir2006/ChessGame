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
	//CTOR
	Board();
	//DTOR
	~Board();

	void parseMsg(const std::string msgToParse, int (& results)[2]);//parses the message the backend recives from the frontend
	void updateBoard(const int src,const int dest);//updates the board and updates the message to send to frontend based on the source and destination
	std::string getMsg()const;//returns the message to the frontend
	void changeTeam();//changes the team that is currently playing
private:
	IFigure*  _board[BOARD_LENGTH][BOARD_LENGTH];
	Player _p1;
	Player _p2;
	std::string _msg;
	int _currTeam;
	bool _won;
	int isCheck();//checks if there is currently check
	bool isCheckmate();//checks if there is currently checkmate
	bool willCheck(const int src, const int dest);//checks if the move will cause check
	int findKing();//changes the team that is currently playing
	int isCastle(const int src, const int dest);//checks if the current move is a castle
	void castle(const int src, const int dest, const int isCas);//does a castle
	int isEnPassant(const int src, const int dest);//checks if the current move is an en passant
	void enPassant(const int src, const int dest);//does an en passant
};

