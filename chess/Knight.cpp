#include "Knight.h"

//CTOR
Knight::Knight(const int team, const int place) : IFigure("Knight", team, place) { }

//DTOR
Knight::~Knight() { }

int Knight::checkValidMove(const int index, IFigure* (&board)[BOARD_LENGTH][BOARD_LENGTH], int currTeam)const
{
	return 0;
}
