#include "IFIgure.h"

//CTOR
IFigure::IFigure(const int team, const std::string place)
{
	this->_stepsTaken = 0;
	this->_team = team;
	this->_place = place;
}

IFigure::~IFigure() {}
