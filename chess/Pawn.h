#pragma once
#include "IFigure.h"

class Pawn : public IFigure
{
public:
	//CTOR
	Pawn(const int team, const int place);
	//DTOR
	~Pawn();

	virtual bool checkValidMove(const int index)const override;
};

