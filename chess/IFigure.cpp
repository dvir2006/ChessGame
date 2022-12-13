#include "IFIgure.h"

//CTOR
IFigure::IFigure(const std::string type, const int team, const int place)
{
	this->_stepsTaken = 0;
	this->_type = type;
	this->_team = team;
	this->_place = place;
}

IFigure::~IFigure() {}

void IFigure::setPlace(const int newPlace)
{
	this->_place = newPlace;
}

int IFigure::getTeam()
{
	return this->_team;
}

std::string IFigure::getType() const
{
	return this->_type;
}

void IFigure::decStepsTaken()
{
	this->_stepsTaken--;
}

void IFigure::move(const int src, const int dst, IFigure* (&board)[BOARD_LENGTH][BOARD_LENGTH])
{
	int dstLine = dst / BOARD_LENGTH;
	int dstCol = dst % BOARD_LENGTH;
	int srcLine = src / BOARD_LENGTH;
	int srcCol = src % BOARD_LENGTH;

	board[dstLine][dstCol] = board[srcLine][srcCol];
	board[srcLine][srcCol] = NULL;

	this->setPlace(dst);
	this->_stepsTaken++;

}
