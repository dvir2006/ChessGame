#pragma once
#include "IFigure.h"

class Rook : public IFigure
{
public:
	//CTOR
	Rook(const int team, const int place);
	//DTOR
	~Rook();

	virtual bool checkValidMove(const int index)const override;
};

