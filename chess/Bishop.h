#pragma once
#include "IFigure.h"

class Bishop : public IFigure
{
public:
	//CTOR
	Bishop(const int team, const int place);
	//DTOR
	~Bishop();

	virtual bool checkValidMove(const int index)const override;
};

