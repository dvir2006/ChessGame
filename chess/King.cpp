#include "King.h"

//CTOR
King::King(const int team, const int place) : IFigure("King", team, place) { }

//DTOR
King::~King() { }

int King::checkValidMove(const int index, IFigure* (&board)[BOARD_LENGTH][BOARD_LENGTH], int currTeam)const
{
	return 0;
}
