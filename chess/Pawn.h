#pragma once
#include "IFigure.h"


class Pawn : public IFigure
{
public:
	//CTOR
	Pawn(const int team, const int place);
	//DTOR
	~Pawn();

	virtual int checkValidMove(const int index,  IFigure* (&board)[BOARD_LENGTH][BOARD_LENGTH], int currTeam)const override;
};

