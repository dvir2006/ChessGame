#pragma once
#include <string>
#include "Board.h"

class Board;
#define BOARD_LENGTH 8
class IFigure
{
public:
	//CTOR
	IFigure(const std::string type, const int team, const int place);
	//DTOR
	virtual ~IFigure();

	void setPlace(const int newPlace);

	virtual void move(const int src, const int dst, std::string& msg, IFigure*(& board)[BOARD_LENGTH][BOARD_LENGTH]);
	virtual int checkValidMove(const int index, IFigure* (&board)[BOARD_LENGTH][BOARD_LENGTH], int currTeam)const = 0;

protected:
	std::string _type;
	int _stepsTaken;
	int _team;
	int _place;
};

