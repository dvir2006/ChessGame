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
	void setPlace(const int newPlace);//sets the place of the figure
	void decStepsTaken();//decrease the amount of steps taken by 1
	void incStepsTaken();//increase the amount of steps taken by 1
	
	//getters
	int getTeam() const;//returns the team of the figure
	std::string getType() const;//returns the type of figure of the figure
	int getSteps() const;//returns the amount of steps the figure has made

	//virtual functions
	virtual void move(const int src, const int dst, IFigure*(& board)[BOARD_LENGTH][BOARD_LENGTH]);//moves the figure around the board according to the source and destination
	virtual int checkValidMove(const int index, IFigure* (&board)[BOARD_LENGTH][BOARD_LENGTH], int currTeam)const = 0;//function recives destination index,the chess board and the current team and returns a code according to the move(valid or not)

protected:
	std::string _type;
	int _stepsTaken;
	int _team;
	int _place;
};

