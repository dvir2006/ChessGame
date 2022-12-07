#include "Bishop.h"

//CTOR
Bishop::Bishop(const int team, const int place) : IFigure("Bishop", team, place) { }

//DTOR
Bishop::~Bishop() { }

int Bishop::checkValidMove(const int index,  IFigure* (&board)[BOARD_LENGTH][BOARD_LENGTH], int currTeam)const
{
	return 0;
}
