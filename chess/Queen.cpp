#include "Queen.h"

//CTOR
Queen::Queen(const int team, const int place) : IFigure(team, place) { }

//DTOR
Queen::~Queen() { }

int Queen::checkValidMove(const int index,  IFigure* (&board)[BOARD_LENGTH][BOARD_LENGTH])const
{
	return 0;
}
