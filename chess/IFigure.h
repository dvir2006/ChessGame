#pragma once
#include <string>

class IFigure
{
public:
	//CTOR
	IFigure(const int team, const std::string place);
	//DTOR
	virtual ~IFigure();

	virtual void move(std::string dst) = 0;
	virtual bool checkValidMove()const = 0;

protected:
	int _stepsTaken;
	int _team;
	std::string _place;
};

