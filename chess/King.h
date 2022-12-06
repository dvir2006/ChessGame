#pragma once
#include "IFigure.h"

class King : public IFigure
{
public:
	//CTOR
	King(const int team, const int place);
	//DTOR
	~King();

	virtual int checkValidMove(const int index, const IFigure* [BOARD_LENGTH][BOARD_LENGTH])const override;

};

