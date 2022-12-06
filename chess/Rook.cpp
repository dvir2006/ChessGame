#include "Rook.h"

//CTOR
Rook::Rook(const int team, const int place) : IFigure(team, place) { }

//DTOR
Rook::~Rook() { }

int Rook::checkValidMove(const int index, IFigure* (&board)[BOARD_LENGTH][BOARD_LENGTH])const
{
	return 0;
}