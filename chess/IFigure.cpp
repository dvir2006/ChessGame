#include "IFIgure.h"

//CTOR
IFigure::IFigure(const int team, const std::string place)
{
	this->_stepsTaken = 0;
	this->_team = team;
	this->_place = place;
}

IFigure::~IFigure() {}

void IFigure::move(const int src, const int dst, std::string& msg)
{
	msg[dst] = msg[src];
	msg[src] = '#';
}