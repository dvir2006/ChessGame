#include "Pawn.h"

//CTOR
Pawn::Pawn(const int team, const int place) : IFigure(team, place) { }

//DTOR
Pawn::~Pawn() { }

int Pawn::checkValidMove(const int index, const IFigure* [BOARD_LENGTH][BOARD_LENGTH])const
{
	return 0;
}