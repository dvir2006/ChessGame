#pragma once
#include "IFigure.h"

class King : public IFigure
{
public:
	//CTOR
	King(const int team, const int place);
	//DTOR
	~King();

	virtual int checkValidMove(const int index, IFigure* (&board)[BOARD_LENGTH][BOARD_LENGTH], int currTeam)const override;

};

