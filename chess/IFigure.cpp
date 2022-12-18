#include "IFIgure.h"

//CTOR
IFigure::IFigure(const std::string type, const int team, const int place)
{
	this->_stepsTaken = 0;
	this->_type = type;
	this->_team = team;
	this->_place = place;
}

//DTOR
IFigure::~IFigure() {}

//sets the place of the figure
void IFigure::setPlace(const int newPlace)
{
	this->_place = newPlace;
}

//returns the team of the figure
int IFigure::getTeam() const
{
	return this->_team;
}

//returns the type of figure of the figure
std::string IFigure::getType() const
{
	return this->_type;
}

//returns the amount of steps the figure has made
int IFigure::getSteps() const
{
	return this->_stepsTaken;
}

//decrease the amount of steps taken by 1
void IFigure::decStepsTaken()
{
	this->_stepsTaken--;
}

//increase the amount of steps taken by 1
void IFigure::incStepsTaken()
{
	this->_stepsTaken++;
}

//moves the figure around the board according to the source and destination
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
