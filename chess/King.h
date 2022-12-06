#pragma once
#include "IFigure.h"

class King : public IFigure
{
public:
	//CTOR
	King(const int team, const int place);
	//DTOR
	~King();

	virtual bool checkValidMove(const int index)const override;

};

