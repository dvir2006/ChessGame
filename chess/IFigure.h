#pragma once
#include <string>

#define BOARD_LENGTH 8

class IFigure
{
public:
	//CTOR
	IFigure(const int team, const int place);
	//DTOR
	virtual ~IFigure();

	void setPlace(const int newPlace);

	virtual void move(const int src, const int dst, std::string& msg, IFigure*(& board)[BOARD_LENGTH][BOARD_LENGTH]);
	virtual int checkValidMove(const int index, const IFigure* [BOARD_LENGTH][BOARD_LENGTH])const = 0;

protected:
	int _stepsTaken;
	int _team;
	int _place;
};

