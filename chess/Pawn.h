#pragma once
#include "IFigure.h"


class Pawn : public IFigure
{
public:
	//CTOR
	Pawn(const int team, const int place);
	//DTOR
	~Pawn();

	//function recives destination index,the chess board and the current team and returns a code according to the move(valid or not)
	virtual int checkValidMove(const int index,  IFigure* (&board)[BOARD_LENGTH][BOARD_LENGTH], int currTeam)const override;
};

