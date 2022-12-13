#pragma once
#include <string>
#include "Consts.h"

class IFigure
{
public:
	//CTOR
	IFigure(const std::string type, const int team, const int place);
	//DTOR
	virtual ~IFigure();

	//setters
	void setPlace(const int newPlace);
	void decStepsTaken();
	
	//getters
	int getTeam();
	std::string getType() const;

	virtual void move(const int src, const int dst, IFigure*(& board)[BOARD_LENGTH][BOARD_LENGTH]);
	virtual int checkValidMove(const int index, IFigure* (&board)[BOARD_LENGTH][BOARD_LENGTH], int currTeam)const = 0;

protected:
	std::string _type;
	int _stepsTaken;
	int _team;
	int _place;
};

