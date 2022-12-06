#pragma once
#include <string>

class IFigure
{
public:
	//CTOR
	IFigure(const int team, const std::string place);
	//DTOR
	virtual ~IFigure();

	virtual void move(const int src, const int dst, std::string& msg);
	virtual bool checkValidMove(std::string m)const = 0;

protected:
	int _stepsTaken;
	int _team;
	std::string _place;
};

