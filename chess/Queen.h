#pragma once
#include "IFigure.h"

class Queen : public IFigure
{
public:
	//CTOR
	Queen(const int team, const int place);
	//DTOR
	~Queen();

	virtual bool checkValidMove(const int index)const override;
};

