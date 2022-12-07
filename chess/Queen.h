#pragma once
#include "IFigure.h"

class Queen : public IFigure
{
public:
	//CTOR
	Queen(const int team, const int place);
	//DTOR
	~Queen();

	virtual int checkValidMove(const int index, IFigure* (&board)[BOARD_LENGTH][BOARD_LENGTH], int currTeam)const override;
};

