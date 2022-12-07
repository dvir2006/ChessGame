#include "Rook.h"

//CTOR
Rook::Rook(const int team, const int place) : IFigure("Rook", team, place) { }

//DTOR
Rook::~Rook() { }

int Rook::checkValidMove(const int index, IFigure* (&board)[BOARD_LENGTH][BOARD_LENGTH], int currTeam)const
{
	return 0;
}