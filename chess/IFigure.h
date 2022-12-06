#pragma once
#include <string>

class IFigure
{
public:
	//CTOR
	IFigure(const int team, const int place);
	//DTOR
	virtual ~IFigure();

	virtual void move(const int src, const int dst, std::string& msg);
	virtual bool checkValidMove(const int index)const = 0;

protected:
	int _stepsTaken;
	int _team;
	int _place;
};

