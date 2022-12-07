#include "Queen.h"

//CTOR
Queen::Queen(const int team, const int place) : IFigure("Queen", team, place) { }

//DTOR
Queen::~Queen() { }

int Queen::checkValidMove(const int index,  IFigure* (&board)[BOARD_LENGTH][BOARD_LENGTH], int currTeam)const
{
	return 0;
}
