#pragma once
#include "IFigure.h"

class Pawn : public IFigure
{
public:
	//CTOR
	Pawn(const int team, const std::string place);
	//DTOR
	~Pawn();

	bool checkValidMove();
};

