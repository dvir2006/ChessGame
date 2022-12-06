#pragma once
#include "IFigure.h"

class Rook : public IFigure
{
public:
	//CTOR
	Rook(const int team, const int place);
	//DTOR
	~Rook();

	virtual int checkValidMove(const int index, const IFigure* [BOARD_LENGTH][BOARD_LENGTH])const override;
};

