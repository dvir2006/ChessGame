#include "Knight.h"

//CTOR
Knight::Knight(const int team, const int place) : IFigure(team, place) { }

//DTOR
Knight::~Knight() { }

int Knight::checkValidMove(const int index, IFigure* (&board)[BOARD_LENGTH][BOARD_LENGTH])const
{
	return 0;
}
