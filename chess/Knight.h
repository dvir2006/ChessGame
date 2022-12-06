#pragma once
#include "IFigure.h"

class Knight : public IFigure
{
public:
	//CTOR
	Knight(const int team, const int place);
	//DTOR
	~Knight();

	virtual bool checkValidMove(const int index)const override;
};

