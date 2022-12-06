#pragma once
#include "IFigure.h"

class Knight : public IFigure
{
public:
	//CTOR
	Knight(const int team, const int place);
	//DTOR
	~Knight();

	virtual int checkValidMove(const int index, const IFigure* [BOARD_LENGTH][BOARD_LENGTH])const override;
};

