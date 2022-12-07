#include "Pawn.h"

//CTOR
Pawn::Pawn(const int team, const int place) : IFigure("Pawn", team, place) { }

//DTOR
Pawn::~Pawn() { }

int Pawn::checkValidMove(const int index,  IFigure* (&board)[BOARD_LENGTH][BOARD_LENGTH], int currTeam)const
{
	return 0;
}
