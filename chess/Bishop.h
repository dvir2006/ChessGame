#pragma once
#include "IFigure.h"

class Bishop : public IFigure
{
public:
	//CTOR
	Bishop(const int team, const int place);
	//DTOR
	~Bishop();

	virtual int checkValidMove(const int index, IFigure* (&board)[BOARD_LENGTH][BOARD_LENGTH])const override;
};

